//**********************************************************************;
// Copyright (c) 2015, Intel Corporation
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//**********************************************************************;

//
// The context for TCTI implementations is on opaque
// structure. There shall never be a definition of its content.
// Implementation provide the size information to
// applications via the initialize call.
// This makes use of a compiler trick that allows type
// checking of the pointer even though the type isn't
// defined.
//
// The first field of a Context must be the common part
// (see below).
#ifndef TSS2_TCTI_UTIL_H
#define TSS2_TCTI_UTIL_H

#if defined linux || defined unix
#include <sys/socket.h>
#define SOCKET int
#endif

#include <tcti/common.h>

#define TCTI_MAGIC   0x7e18e9defa8bc9e2
#define TCTI_VERSION 0x1

#define TCTI_LOG_CALLBACK(ctx) ((TSS2_TCTI_CONTEXT_INTEL*)ctx)->logCallback
#define TCTI_LOG_DATA(ctx)     ((TSS2_TCTI_CONTEXT_INTEL*)ctx)->logData
#define TCTI_LOG_BUFFER_CALLBACK(ctx) ((TSS2_TCTI_CONTEXT_INTEL*)ctx)->logBufferCallback

typedef TSS2_RC (*TCTI_TRANSMIT_PTR)( TSS2_TCTI_CONTEXT *tctiContext, size_t size, uint8_t *command);
typedef TSS2_RC (*TCTI_RECEIVE_PTR) (TSS2_TCTI_CONTEXT *tctiContext, size_t *size, uint8_t *response, int32_t timeout);

enum tctiStates { TCTI_STAGE_INITIALIZE, TCTI_STAGE_SEND_COMMAND, TCTI_STAGE_RECEIVE_RESPONSE };

/* current Intel version */
typedef struct {
    uint64_t magic;
    uint32_t version;
    TCTI_TRANSMIT_PTR transmit;
    TCTI_RECEIVE_PTR receive;
    TSS2_RC (*finalize) (TSS2_TCTI_CONTEXT *tctiContext);
    TSS2_RC (*cancel) (TSS2_TCTI_CONTEXT *tctiContext);
    TSS2_RC (*getPollHandles) (TSS2_TCTI_CONTEXT *tctiContext,
              TSS2_TCTI_POLL_HANDLE *handles, size_t *num_handles);
    TSS2_RC (*setLocality) (TSS2_TCTI_CONTEXT *tctiContext, uint8_t locality);
    struct {
        UINT32 debugMsgEnabled: 1;
        UINT32 locality: 8;
        UINT32 commandSent: 1;
        UINT32 rmDebugPrefix: 1;  // Used to add a prefix to RM debug messages.  This is ONLY used
                                  // for TPM commands and responses as a way to differentiate
                                  // RM generated TPM commands from application generated ones.

        // Following two fields used to save partial response status in case receive buffer's too small.
        UINT32 tagReceived: 1;
        UINT32 responseSizeReceived: 1;
        UINT32 protocolResponseSizeReceived: 1;
    } status;

    // Following two fields used to save partial response in case receive buffer's too small.
    TPM_ST tag;
    TPM_RC responseSize;

    TSS2_TCTI_CONTEXT *currentTctiContext;

    // Sockets if socket interface is being used.
    SOCKET otherSock;
    SOCKET tpmSock;
    SOCKET currentConnectSock;

    // File descriptor for device file if real TPM is being used.
    int devFile;
    UINT8 previousStage;            // Used to check for sequencing errors.
    unsigned char responseBuffer[4096];
    TCTI_LOG_CALLBACK logCallback;
    TCTI_LOG_BUFFER_CALLBACK logBufferCallback;
    void *logData;
} TSS2_TCTI_CONTEXT_INTEL;

#define TCTI_CONTEXT ( (TSS2_TCTI_CONTEXT_COMMON_CURRENT *)(SYS_CONTEXT->tctiContext) )
#define TCTI_CONTEXT_INTEL ( (TSS2_TCTI_CONTEXT_INTEL *)tctiContext )

#endif
