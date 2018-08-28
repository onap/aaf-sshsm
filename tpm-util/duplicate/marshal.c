/*
 * Copyright 2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */
// Author: Arun Kumar Sekar


#include "marshal.h"

TPM_RC
UINT8_Unmarshal(
    UINT8 *target, BYTE **buffer, INT32     *size
    )
{
    if((*size -= 1) < 0)
        return TPM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT8(*buffer);
    *buffer += 1;
    return TPM_RC_SUCCESS;
}

UINT16
UINT8_Marshal(
    UINT8 *source, BYTE **buffer, INT32     *size
    )
{
    if (buffer != 0)
    {
        if ((size == 0) || ((*size -= 1) >= 0))
        {
            UINT8_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 1;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (1);
}

//   BYTE definition from table 2:3
//   BYTE_Unmarshal changed to #define
//   BYTE_Marshal changed to #define
//   INT8 definition from table 2:3
//   INT8_Unmarshal changed to #define
//     INT8_Marshal not referenced
//   UINT16 definition from table 2:3
TPM_RC
UINT16_Unmarshal(
    UINT16 *target, BYTE **buffer, INT32    *size
    )
{
    if((*size -= 2) < 0)
        return TPM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT16(*buffer);
    *buffer += 2;
    return TPM_RC_SUCCESS;
}

UINT16
UINT16_Marshal(
    UINT16 *source, BYTE **buffer, INT32    *size
    )
{
    if (buffer != 0)
    {
        if ((size == 0) || ((*size -= 2) >= 0))
        {
            UINT16_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 2;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (2);
}

//   INT16 definition from table 2:3
//     INT16_Unmarshal not referenced
//     INT16_Marshal not referenced
//   UINT32 definition from table 2:3
TPM_RC
UINT32_Unmarshal(
    UINT32 *target, BYTE **buffer, INT32    *size
    )
{
    if((*size -= 4) < 0)
        return TPM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT32(*buffer);
    *buffer += 4;
    return TPM_RC_SUCCESS;
}

UINT16
UINT32_Marshal(
    UINT32 *source, BYTE **buffer, INT32    *size
    )
{
    if (buffer != 0)
    {
        if ((size == 0) || ((*size -= 4) >= 0))
        {
            UINT32_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 4;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (4);
}

//   INT32 definition from table 2:3
//   INT32_Unmarshal changed to #define
//     INT32_Marshal not referenced
//   UINT64 definition from table 2:3
TPM_RC
UINT64_Unmarshal(
    UINT64 *target, BYTE **buffer, INT32    *size
    )
{
    if((*size -= 8) < 0)
        return TPM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT64(*buffer);
    *buffer += 8;
    return TPM_RC_SUCCESS;
}

UINT16
UINT64_Marshal(
    UINT64 *source, BYTE **buffer, INT32    *size
    )
{
    if (buffer != 0)
    {
        if ((size == 0) || ((*size -= 8) >= 0))
        {
            UINT64_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 8;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (8);
}

//   INT64 definition from table 2:3
//     INT64_Unmarshal not referenced
//     INT64_Marshal not referenced


// Table 2:4 - Defines for Logic Values (DefinesTable)


// Table 2:5 - Definition of Types for Documentation Clarity (TypesTable)
//   UINT32 definition from table 2:5
//     TPM_ALGORITHM_ID_Unmarshal not referenced
//     TPM_ALGORITHM_ID_Marshal not referenced
//   UINT32 definition from table 2:5
//     TPM_MODIFIER_INDICATOR_Unmarshal not referenced
//     TPM_MODIFIER_INDICATOR_Marshal not referenced
//   UINT32 definition from table 2:5
//     TPM_AUTHORIZATION_SIZE_Unmarshal not referenced
//     TPM_AUTHORIZATION_SIZE_Marshal not referenced
//   UINT32 definition from table 2:5
//     TPM_PARAMETER_SIZE_Unmarshal not referenced
//     TPM_PARAMETER_SIZE_Marshal not referenced
//   UINT16 definition from table 2:5
//     TPM_KEY_SIZE_Unmarshal not referenced
//     TPM_KEY_SIZE_Marshal not referenced
//   UINT16 definition from table 2:5
//   TPM_KEY_BITS_Unmarshal changed to #define
//   TPM_KEY_BITS_Marshal changed to #define


// Table 2:6 - Definition of TPM_SPEC Constants  (ConstantsTable)
//     TPM_SPEC_Unmarshal not referenced
//     TPM_SPEC_Marshal not referenced


// Table 2:7 - Definition of TPM_GENERATED Constants  (ConstantsTable)
//     TPM_GENERATED_Unmarshal not referenced
//   TPM_GENERATED_Marshal changed to #define


// Table 2:9 - Definition of TPM_ALG_ID Constants  (ConstantsTable)
//   TPM_ALG_ID_Unmarshal changed to #define
//   TPM_ALG_ID_Marshal changed to #define


// Table 2:10 - Definition of TPM_ECC_CURVE Constants  (ConstantsTable)
#ifdef    TPM_ALG_ECC
//   TPM_ECC_CURVE_Unmarshal changed to #define
//   TPM_ECC_CURVE_Marshal changed to #define
#endif // TPM_ALG_ECC


// Table 2:13 - Definition of TPM_CC Constants  (ConstantsTable)
//   TPM_CC_Unmarshal changed to #define
//   TPM_CC_Marshal changed to #define


// Table 2:17 - Definition of TPM_RC Constants  (ConstantsTable)
//     TPM_RC_Unmarshal not referenced
//   TPM_RC_Marshal changed to #define


// Table 2:18 - Definition of TPM_CLOCK_ADJUST Constants  (ConstantsTable)
TPM_RC
TPM_CLOCK_ADJUST_Unmarshal(
    TPM_CLOCK_ADJUST *target, BYTE **buffer, INT32  *size
    )
{
    return TPM_RC_SUCCESS;
}

//     TPM_CLOCK_ADJUST_Marshal not referenced


// Table 2:19 - Definition of TPM_EO Constants  (ConstantsTable)
TPM_RC
TPM_EO_Unmarshal(
    TPM_EO *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch(*target) {
        case TPM_EO_EQ :
        case TPM_EO_NEQ :
        case TPM_EO_SIGNED_GT :
        case TPM_EO_UNSIGNED_GT :
        case TPM_EO_SIGNED_LT :
        case TPM_EO_UNSIGNED_LT :
        case TPM_EO_SIGNED_GE :
        case TPM_EO_UNSIGNED_GE :
        case TPM_EO_SIGNED_LE :
        case TPM_EO_UNSIGNED_LE :
        case TPM_EO_BITSET :
        case TPM_EO_BITCLEAR :
            break;
       default :
            return TPM_RC_VALUE;
            break;
    }
    return TPM_RC_SUCCESS;
}

//     TPM_EO_Marshal not referenced


// Table 2:20 - Definition of TPM_ST Constants  (ConstantsTable)
//   TPM_ST_Unmarshal changed to #define
//   TPM_ST_Marshal changed to #define


// Table 2:21 - Definition of TPM_SU Constants  (ConstantsTable)
TPM_RC
TPM_SU_Unmarshal(
    TPM_SU *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch(*target) {
        case TPM_SU_CLEAR :
        case TPM_SU_STATE :
            break;
       default :
            return TPM_RC_VALUE;
            break;
    }
    return TPM_RC_SUCCESS;
}

//     TPM_SU_Marshal not referenced


// Table 2:22 - Definition of TPM_SE Constants  (ConstantsTable)
TPM_RC
TPM_SE_Unmarshal(
    TPM_SE *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT8_Unmarshal((UINT8 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch(*target) {
        case TPM_SE_HMAC :
        case TPM_SE_POLICY :
        case TPM_SE_TRIAL :
            break;
       default :
            return TPM_RC_VALUE;
            break;
    }
    return TPM_RC_SUCCESS;
}

//     TPM_SE_Marshal not referenced


// Table 2:23 - Definition of TPM_CAP Constants (ConstantsTable)
TPM_RC
TPM_CAP_Unmarshal(
    TPM_CAP *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch(*target) {
        case TPM_CAP_ALGS :
        case TPM_CAP_HANDLES :
        case TPM_CAP_COMMANDS :
        case TPM_CAP_PP_COMMANDS :
        case TPM_CAP_AUDIT_COMMANDS :
        case TPM_CAP_PCRS :
        case TPM_CAP_TPM_PROPERTIES :
        case TPM_CAP_PCR_PROPERTIES :
        case TPM_CAP_ECC_CURVES :
        case TPM_CAP_VENDOR_PROPERTY :
            break;
       default :
            return TPM_RC_VALUE;
            break;
    }
    return TPM_RC_SUCCESS;
}

//   TPM_CAP_Marshal changed to #define


// Table 2:24 - Definition of TPM_PT Constants  (ConstantsTable)
//     TPM_PT_Unmarshal not referenced
//   TPM_PT_Marshal changed to #define


// Table 2:25 - Definition of TPM_PT_PCR Constants  (ConstantsTable)
//     TPM_PT_PCR_Unmarshal not referenced
//     TPM_PT_PCR_Marshal not referenced


// Table 2:26 - Definition of TPM_PS Constants  (ConstantsTable)
//     TPM_PS_Unmarshal not referenced
//     TPM_PS_Marshal not referenced


// Table 2:27 - Definition of Types for Handles (TypesTable)
//   UINT32 definition from table 2:27
//   TPM_HANDLE_Unmarshal changed to #define
//   TPM_HANDLE_Marshal changed to #define


// Table 2:28 - Definition of TPM_HT Constants  (ConstantsTable)
//     TPM_HT_Unmarshal not referenced
//     TPM_HT_Marshal not referenced


// Table 2:29 - Definition of TPM_RH Constants  (ConstantsTable)
//     TPM_RH_Unmarshal not referenced
//     TPM_RH_Marshal not referenced


// Table 2:30 - Definition of TPM_HC Constants  (ConstantsTable)
//     TPM_HC_Unmarshal not referenced
//     TPM_HC_Marshal not referenced


// Table 2:31 - Definition of TPMA_ALGORITHM Bits (BitsTable)
//     TPMA_ALGORITHM_Unmarshal not referenced
//   TPMA_ALGORITHM_Marshal changed to #define


// Table 2:32 - Definition of TPMA_OBJECT Bits (BitsTable)
TPM_RC
TPMA_OBJECT_Unmarshal(
    TPMA_OBJECT *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(*((UINT32 *)target) & (UINT32)0xfff8f309)
        return TPM_RC_RESERVED_BITS;
    return TPM_RC_SUCCESS;
}

//   TPMA_OBJECT_Marshal changed to #define


// Table 2:33 - Definition of TPMA_SESSION Bits  (BitsTable)
TPM_RC
TPMA_SESSION_Unmarshal(
    TPMA_SESSION *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT8_Unmarshal((UINT8 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(*((UINT8 *)target) & (UINT8)0x18)
        return TPM_RC_RESERVED_BITS;
    return TPM_RC_SUCCESS;
}

//   TPMA_SESSION_Marshal changed to #define


// Table 2:34 - Definition of TPMA_LOCALITY Bits  (BitsTable)
//   TPMA_LOCALITY_Unmarshal changed to #define
//   TPMA_LOCALITY_Marshal changed to #define


// Table 2:35 - Definition of TPMA_PERMANENT Bits  (BitsTable)
//     TPMA_PERMANENT_Unmarshal not referenced
//     TPMA_PERMANENT_Marshal not referenced


// Table 2:36 - Definition of TPMA_STARTUP_CLEAR Bits  (BitsTable)
//     TPMA_STARTUP_CLEAR_Unmarshal not referenced
//     TPMA_STARTUP_CLEAR_Marshal not referenced


// Table 2:37 - Definition of TPMA_MEMORY Bits  (BitsTable)
//     TPMA_MEMORY_Unmarshal not referenced
//     TPMA_MEMORY_Marshal not referenced


// Table 2:38 - Definition of TPMA_CC Bits  (BitsTable)
//     TPMA_CC_Unmarshal not referenced
//   TPMA_CC_Marshal changed to #define


// Table 2:39 - Definition of TPMI_YES_NO Type (TypeTable)
TPM_RC
TPMI_YES_NO_Unmarshal(
    TPMI_YES_NO *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = BYTE_Unmarshal((BYTE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case NO:
        case YES:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_YES_NO_Marshal changed to #define


// Table 2:40 - Definition of TPMI_DH_OBJECT Type  (TypeTable)
TPM_RC
TPMI_DH_OBJECT_Unmarshal(
    TPMI_DH_OBJECT *target, BYTE **buffer, INT32 *size, BOOL     flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
   if (*target == TPM_RH_NULL) {
        if(flag)
            return TPM_RC_SUCCESS;
        else
            return TPM_RC_VALUE;
    }

    return TPM_RC_SUCCESS;
}

//   TPMI_DH_OBJECT_Marshal changed to #define


// Table 2:41 - Definition of TPMI_DH_PERSISTENT Type  (TypeTable)
TPM_RC
TPMI_DH_PERSISTENT_Unmarshal(
    TPMI_DH_PERSISTENT *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if((*target < PERSISTENT_FIRST) || (*target > PERSISTENT_LAST))
        return TPM_RC_VALUE;
    return TPM_RC_SUCCESS;
}

//     TPMI_DH_PERSISTENT_Marshal not referenced


// Table 2:42 - Definition of TPMI_DH_ENTITY Type  (TypeTable)
TPM_RC
TPMI_DH_ENTITY_Unmarshal(
    TPMI_DH_ENTITY *target, BYTE **buffer, INT32 *size, BOOL     flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;

    return TPM_RC_SUCCESS;
}

//     TPMI_DH_ENTITY_Marshal not referenced


// Table 2:43 - Definition of TPMI_DH_PCR Type  (TypeTable)
TPM_RC
TPMI_DH_PCR_Unmarshal(
    TPMI_DH_PCR *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
   if (*target == TPM_RH_NULL) {
        if(flag)
            return TPM_RC_SUCCESS;
        else
            return TPM_RC_VALUE;
    }

    return TPM_RC_SUCCESS;
}

//     TPMI_DH_PCR_Marshal not referenced


// Table 2:44 - Definition of TPMI_SH_AUTH_SESSION Type  (TypeTable)
TPM_RC
TPMI_SH_AUTH_SESSION_Unmarshal(
    TPMI_SH_AUTH_SESSION *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
   if (*target == TPM_RS_PW) {
        if(flag)
            return TPM_RC_SUCCESS;
        else
            return TPM_RC_VALUE;
    }

    return TPM_RC_SUCCESS;
}

//   TPMI_SH_AUTH_SESSION_Marshal changed to #define


// Table 2:45 - Definition of TPMI_SH_HMAC Type  (TypeTable)
TPM_RC
TPMI_SH_HMAC_Unmarshal(
    TPMI_SH_HMAC *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;

    return TPM_RC_SUCCESS;
}

//     TPMI_SH_HMAC_Marshal not referenced


// Table 2:46 - Definition of TPMI_SH_POLICY Type  (TypeTable)
TPM_RC
TPMI_SH_POLICY_Unmarshal(
    TPMI_SH_POLICY *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);

    return TPM_RC_SUCCESS;
}

//     TPMI_SH_POLICY_Marshal not referenced


// Table 2:47 - Definition of TPMI_DH_CONTEXT Type  (TypeTable)
TPM_RC
TPMI_DH_CONTEXT_Unmarshal(
    TPMI_DH_CONTEXT *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;

    return TPM_RC_SUCCESS;
}

//   TPMI_DH_CONTEXT_Marshal changed to #define


// Table 2:48 - Definition of TPMI_RH_HIERARCHY Type  (TypeTable)
TPM_RC
TPMI_RH_HIERARCHY_Unmarshal(
    TPMI_RH_HIERARCHY *target, BYTE **buffer, INT32 *size, BOOL      flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_OWNER:
        case TPM_RH_PLATFORM:
        case TPM_RH_ENDORSEMENT:
            break;
        case TPM_RH_NULL:
        if (flag)
            break;
        return TPM_RC_VALUE;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_RH_HIERARCHY_Marshal changed to #define


// Table 2:49 - Definition of TPMI_RH_ENABLES Type  (TypeTable)
TPM_RC
TPMI_RH_ENABLES_Unmarshal(
    TPMI_RH_ENABLES *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_OWNER:
        case TPM_RH_PLATFORM:
        case TPM_RH_ENDORSEMENT:
        case TPM_RH_PLATFORM_NV:
            break;
        case TPM_RH_NULL:
        if (flag)
            break;
        return TPM_RC_VALUE;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_ENABLES_Marshal not referenced


// Table 2:50 - Definition of TPMI_RH_HIERARCHY_AUTH Type  (TypeTable)
TPM_RC
TPMI_RH_HIERARCHY_AUTH_Unmarshal(
    TPMI_RH_HIERARCHY_AUTH *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_OWNER:
        case TPM_RH_PLATFORM:
        case TPM_RH_ENDORSEMENT:
        case TPM_RH_LOCKOUT:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_HIERARCHY_AUTH_Marshal not referenced


// Table 2:51 - Definition of TPMI_RH_PLATFORM Type  (TypeTable)
TPM_RC
TPMI_RH_PLATFORM_Unmarshal(
    TPMI_RH_PLATFORM *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_PLATFORM:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_PLATFORM_Marshal not referenced


// Table 2:52 - Definition of TPMI_RH_OWNER Type  (TypeTable)
//     TPMI_RH_OWNER_Unmarshal not referenced
//     TPMI_RH_OWNER_Marshal not referenced


// Table 2:53 - Definition of TPMI_RH_ENDORSEMENT Type  (TypeTable)
TPM_RC
TPMI_RH_ENDORSEMENT_Unmarshal(
    TPMI_RH_ENDORSEMENT *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_ENDORSEMENT:
            break;
        case TPM_RH_NULL:
        if (flag)
            break;
        return TPM_RC_VALUE;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_ENDORSEMENT_Marshal not referenced


// Table 2:54 - Definition of TPMI_RH_PROVISION Type  (TypeTable)
TPM_RC
TPMI_RH_PROVISION_Unmarshal(
    TPMI_RH_PROVISION *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_OWNER:
        case TPM_RH_PLATFORM:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_PROVISION_Marshal not referenced


// Table 2:55 - Definition of TPMI_RH_CLEAR Type  (TypeTable)
TPM_RC
TPMI_RH_CLEAR_Unmarshal(
    TPMI_RH_CLEAR *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_LOCKOUT:
        case TPM_RH_PLATFORM:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_CLEAR_Marshal not referenced


// Table 2:56 - Definition of TPMI_RH_NV_AUTH Type  (TypeTable)
TPM_RC
TPMI_RH_NV_AUTH_Unmarshal(
    TPMI_RH_NV_AUTH *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_PLATFORM:
        case TPM_RH_OWNER:
            break;
        default:
            if((*target < NV_INDEX_FIRST) || (*target > NV_INDEX_LAST))
                return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_NV_AUTH_Marshal not referenced


// Table 2:57 - Definition of TPMI_RH_LOCKOUT Type  (TypeTable)
TPM_RC
TPMI_RH_LOCKOUT_Unmarshal(
    TPMI_RH_LOCKOUT *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_RH_LOCKOUT:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_RH_LOCKOUT_Marshal not referenced


// Table 2:58 - Definition of TPMI_RH_NV_INDEX Type  (TypeTable)
TPM_RC
TPMI_RH_NV_INDEX_Unmarshal(
    TPMI_RH_NV_INDEX *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = TPM_HANDLE_Unmarshal((TPM_HANDLE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if((*target < NV_INDEX_FIRST) || (*target > NV_INDEX_LAST))
        return TPM_RC_VALUE;
    return TPM_RC_SUCCESS;
}

//   TPMI_RH_NV_INDEX_Marshal changed to #define


// Table 2:59 - Definition of TPMI_ALG_HASH Type  (TypeTable)
TPM_RC
TPMI_ALG_HASH_Unmarshal(
    TPMI_ALG_HASH *target, BYTE **buffer, INT32 *size, BOOL      flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_SHA1
        case TPM_ALG_SHA1:
#endif // TPM_ALG_SHA1
#ifdef    TPM_ALG_SHA256
        case TPM_ALG_SHA256:
#endif // TPM_ALG_SHA256
#ifdef    TPM_ALG_SHA384
        case TPM_ALG_SHA384:
#endif // TPM_ALG_SHA384
#ifdef    TPM_ALG_SHA512
        case TPM_ALG_SHA512:
#endif // TPM_ALG_SHA512
#ifdef    TPM_ALG_SM3_256
        case TPM_ALG_SM3_256:
#endif // TPM_ALG_SM3_256
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_HASH;
        default:
            return TPM_RC_HASH;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_HASH_Marshal changed to #define


// Table 2:60 - Definition of TPMI_ALG_ASYM Type (TypeTable)
//     TPMI_ALG_ASYM_Unmarshal not referenced
//     TPMI_ALG_ASYM_Marshal not referenced


// Table 2:61 - Definition of TPMI_ALG_SYM Type (TypeTable)
TPM_RC
TPMI_ALG_SYM_Unmarshal(
    TPMI_ALG_SYM *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_AES
        case TPM_ALG_AES:
#endif // TPM_ALG_AES
#ifdef    TPM_ALG_SM4
        case TPM_ALG_SM4:
#endif // TPM_ALG_SM4
#ifdef    TPM_ALG_CAMELLIA
        case TPM_ALG_CAMELLIA:
#endif // TPM_ALG_CAMELLIA
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
#endif // TPM_ALG_XOR
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_SYMMETRIC;
        default:
            return TPM_RC_SYMMETRIC;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_ALG_SYM_Marshal not referenced


// Table 2:62 - Definition of TPMI_ALG_SYM_OBJECT Type (TypeTable)
TPM_RC
TPMI_ALG_SYM_OBJECT_Unmarshal(
    TPMI_ALG_SYM_OBJECT *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_AES
        case TPM_ALG_AES:
#endif // TPM_ALG_AES
#ifdef    TPM_ALG_SM4
        case TPM_ALG_SM4:
#endif // TPM_ALG_SM4
#ifdef    TPM_ALG_CAMELLIA
        case TPM_ALG_CAMELLIA:
#endif // TPM_ALG_CAMELLIA
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_SYMMETRIC;
        default:
            return TPM_RC_SYMMETRIC;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_SYM_OBJECT_Marshal changed to #define


// Table 2:63 - Definition of TPMI_ALG_SYM_MODE Type (TypeTable)
TPM_RC
TPMI_ALG_SYM_MODE_Unmarshal(
    TPMI_ALG_SYM_MODE *target, BYTE **buffer, INT32 *size, BOOL      flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_CTR
        case TPM_ALG_CTR:
#endif // TPM_ALG_CTR
#ifdef    TPM_ALG_OFB
        case TPM_ALG_OFB:
#endif // TPM_ALG_OFB
#ifdef    TPM_ALG_CBC
        case TPM_ALG_CBC:
#endif // TPM_ALG_CBC
#ifdef    TPM_ALG_CFB
        case TPM_ALG_CFB:
#endif // TPM_ALG_CFB
#ifdef    TPM_ALG_ECB
        case TPM_ALG_ECB:
#endif // TPM_ALG_ECB
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_MODE;
        default:
            return TPM_RC_MODE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_SYM_MODE_Marshal changed to #define


// Table 2:64 - Definition of TPMI_ALG_KDF Type (TypeTable)
TPM_RC
TPMI_ALG_KDF_Unmarshal(
    TPMI_ALG_KDF *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_MGF1
        case TPM_ALG_MGF1:
#endif // TPM_ALG_MGF1
#ifdef    TPM_ALG_KDF1_SP800_56A
        case TPM_ALG_KDF1_SP800_56A:
#endif // TPM_ALG_KDF1_SP800_56A
#ifdef    TPM_ALG_KDF2
        case TPM_ALG_KDF2:
#endif // TPM_ALG_KDF2
#ifdef    TPM_ALG_KDF1_SP800_108
        case TPM_ALG_KDF1_SP800_108:
#endif // TPM_ALG_KDF1_SP800_108
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_KDF;
        default:
            return TPM_RC_KDF;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_KDF_Marshal changed to #define


// Table 2:65 - Definition of TPMI_ALG_SIG_SCHEME Type (TypeTable)
TPM_RC
TPMI_ALG_SIG_SCHEME_Unmarshal(
    TPMI_ALG_SIG_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
#endif // TPM_ALG_HMAC
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_SCHEME;
        default:
            return TPM_RC_SCHEME;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_SIG_SCHEME_Marshal changed to #define


// Table 2:66 - Definition of TPMI_ECC_KEY_EXCHANGE Type (TypeTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMI_ECC_KEY_EXCHANGE_Unmarshal(
    TPMI_ECC_KEY_EXCHANGE *target, BYTE **buffer, INT32 *size, BOOL      flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_ECDH
        case TPM_ALG_ECDH:
#endif // TPM_ALG_ECDH
#ifdef    TPM_ALG_ECMQV
        case TPM_ALG_ECMQV:
#endif // TPM_ALG_ECMQV
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
#endif // TPM_ALG_SM2
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_SCHEME;
        default:
            return TPM_RC_SCHEME;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_ECC_KEY_EXCHANGE_Marshal not referenced
#endif // TPM_ALG_ECC


// Table 2:67 - Definition of TPMI_ST_COMMAND_TAG Type (TypeTable)
TPM_RC
TPMI_ST_COMMAND_TAG_Unmarshal(
    TPMI_ST_COMMAND_TAG *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = TPM_ST_Unmarshal((TPM_ST *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_ST_NO_SESSIONS:
        case TPM_ST_SESSIONS:
            break;
        default:
            return TPM_RC_BAD_TAG;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_ST_COMMAND_TAG_Marshal not referenced
TPM_RC
TPMS_EMPTY_Unmarshal(
    TPMS_EMPTY *target, BYTE **buffer, INT32    *size
    )
{
    // to prevent the compiler from complaining
    UNREFERENCED(target);
    UNREFERENCED(buffer);
    UNREFERENCED(size);
    return TPM_RC_SUCCESS;
}

UINT16
TPMS_EMPTY_Marshal(
    TPMS_EMPTY *source, BYTE **buffer, INT32    *size
    )
{
    // to prevent the compiler from complaining
    UNREFERENCED(source);
    UNREFERENCED(buffer);
    UNREFERENCED(size);
    return 0;
}


// Table 2:69 - Definition of TPMS_ALGORITHM_DESCRIPTION Structure  (StructureTable)
//     TPMS_ALGORITHM_DESCRIPTION_Unmarshal not referenced
//     TPMS_ALGORITHM_DESCRIPTION_Marshal not referenced


// Table 2:70 - Definition of TPMU_HA Union  (UnionTable)
TPM_RC
TPMU_HA_Unmarshal(
    TPMU_HA *target, BYTE **buffer, INT32 *size, UINT32      selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_SHA1
        case TPM_ALG_SHA1:
            return BYTE_Array_Unmarshal((BYTE *)(target->sha1), buffer, size, (INT32)SHA1_DIGEST_SIZE);
#endif // TPM_ALG_SHA1
#ifdef    TPM_ALG_SHA256
        case TPM_ALG_SHA256:
            return BYTE_Array_Unmarshal((BYTE *)(target->sha256), buffer, size, (INT32)SHA256_DIGEST_SIZE);
#endif // TPM_ALG_SHA256
#ifdef    TPM_ALG_SHA384
        case TPM_ALG_SHA384:
            return BYTE_Array_Unmarshal((BYTE *)(target->sha384), buffer, size, (INT32)SHA384_DIGEST_SIZE);
#endif // TPM_ALG_SHA384
#ifdef    TPM_ALG_SHA512
        case TPM_ALG_SHA512:
            return BYTE_Array_Unmarshal((BYTE *)(target->sha512), buffer, size, (INT32)SHA512_DIGEST_SIZE);
#endif // TPM_ALG_SHA512
#ifdef    TPM_ALG_SM3_256
        case TPM_ALG_SM3_256:
            return BYTE_Array_Unmarshal((BYTE *)(target->sm3_256), buffer, size, (INT32)SM3_256_DIGEST_SIZE);
#endif // TPM_ALG_SM3_256
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_HA_Marshal(
    TPMU_HA *source, BYTE **buffer, INT32 *size, UINT32      selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_SHA1
        case TPM_ALG_SHA1:
            return BYTE_Array_Marshal((BYTE *)(source->sha1), buffer, size, (INT32)SHA1_DIGEST_SIZE);
#endif // TPM_ALG_SHA1
#ifdef    TPM_ALG_SHA256
        case TPM_ALG_SHA256:
            return BYTE_Array_Marshal((BYTE *)(source->sha256), buffer, size, (INT32)SHA256_DIGEST_SIZE);
#endif // TPM_ALG_SHA256
#ifdef    TPM_ALG_SHA384
        case TPM_ALG_SHA384:
            return BYTE_Array_Marshal((BYTE *)(source->sha384), buffer, size, (INT32)SHA384_DIGEST_SIZE);
#endif // TPM_ALG_SHA384
#ifdef    TPM_ALG_SHA512
        case TPM_ALG_SHA512:
            return BYTE_Array_Marshal((BYTE *)(source->sha512), buffer, size, (INT32)SHA512_DIGEST_SIZE);
#endif // TPM_ALG_SHA512
#ifdef    TPM_ALG_SM3_256
        case TPM_ALG_SM3_256:
            return BYTE_Array_Marshal((BYTE *)(source->sm3_256), buffer, size, (INT32)SM3_256_DIGEST_SIZE);
#endif // TPM_ALG_SM3_256
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:71 - Definition of TPMT_HA Structure  (StructureTable)
TPM_RC
TPMT_HA_Unmarshal(
    TPMT_HA *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->hashAlg), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_HA_Unmarshal((TPMU_HA *)&(target->digest), buffer, size, (UINT32)target->hashAlg);
    return result;
}

UINT16
TPMT_HA_Marshal(
    TPMT_HA *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->hashAlg), buffer, size));
    result = (UINT16)(result + TPMU_HA_Marshal((TPMU_HA *)&(source->digest), buffer, size, (UINT32)source->hashAlg));
    return result;
}


// Table 2:72 - Definition of TPM2B_DIGEST Structure (StructureTable)
TPM_RC
TPM2B_DIGEST_Unmarshal(
    TPM2B_DIGEST *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(TPMU_HA))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_DIGEST_Marshal(
    TPM2B_DIGEST *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:73 - Definition of TPM2B_DATA Structure (StructureTable)
TPM_RC
TPM2B_DATA_Unmarshal(
    TPM2B_DATA *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(TPMT_HA))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_DATA_Marshal(
    TPM2B_DATA *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:74 - Definition of Types for TPM2B_NONCE (TypesTable)
//   TPM2B_DIGEST definition from table 2:74
//   TPM2B_NONCE_Unmarshal changed to #define
//   TPM2B_NONCE_Marshal changed to #define


// Table 2:75 - Definition of Types for TPM2B_AUTH (TypesTable)
//   TPM2B_DIGEST definition from table 2:75
//   TPM2B_AUTH_Unmarshal changed to #define
//   TPM2B_AUTH_Marshal changed to #define


// Table 2:76 - Definition of Types for TPM2B_OPERAND (TypesTable)
//   TPM2B_DIGEST definition from table 2:76
//   TPM2B_OPERAND_Unmarshal changed to #define
//     TPM2B_OPERAND_Marshal not referenced


// Table 2:77 - Definition of TPM2B_EVENT Structure (StructureTable)
TPM_RC
TPM2B_EVENT_Unmarshal(
    TPM2B_EVENT *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > 1024)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

//     TPM2B_EVENT_Marshal not referenced


// Table 2:78 - Definition of TPM2B_MAX_BUFFER Structure (StructureTable)
TPM_RC
TPM2B_MAX_BUFFER_Unmarshal(
    TPM2B_MAX_BUFFER *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_DIGEST_BUFFER)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_MAX_BUFFER_Marshal(
    TPM2B_MAX_BUFFER *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:79 - Definition of TPM2B_MAX_NV_BUFFER Structure (StructureTable)
TPM_RC
TPM2B_MAX_NV_BUFFER_Unmarshal(
    TPM2B_MAX_NV_BUFFER *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_NV_BUFFER_SIZE)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_MAX_NV_BUFFER_Marshal(
    TPM2B_MAX_NV_BUFFER *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:80 - Definition of TPM2B_TIMEOUT Structure  (StructureTable)
TPM_RC
TPM2B_TIMEOUT_Unmarshal(
    TPM2B_TIMEOUT *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(UINT64))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_TIMEOUT_Marshal(
    TPM2B_TIMEOUT *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:81 - Definition of TPM2B_IV Structure  (StructureTable)
TPM_RC
TPM2B_IV_Unmarshal(
    TPM2B_IV *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_SYM_BLOCK_SIZE)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_IV_Marshal(
    TPM2B_IV *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:82 - Definition of TPMU_NAME Union  (UnionTable)


// Table 2:83 - Definition of TPM2B_NAME Structure (StructureTable)
TPM_RC
TPM2B_NAME_Unmarshal(
    TPM2B_NAME *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(TPMU_NAME))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.name), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_NAME_Marshal(
    TPM2B_NAME *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.name), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:84 - Definition of TPMS_PCR_SELECT Structure (StructureTable)
//     TPMS_PCR_SELECT_Unmarshal not referenced
//     TPMS_PCR_SELECT_Marshal not referenced


// Table 2:85 - Definition of TPMS_PCR_SELECTION Structure (StructureTable)
TPM_RC
TPMS_PCR_SELECTION_Unmarshal(
    TPMS_PCR_SELECTION *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->hash), buffer, size, 0);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = UINT8_Unmarshal((UINT8 *)&(target->sizeofSelect), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( (target->sizeofSelect < PCR_SELECT_MIN))
        return TPM_RC_VALUE;
    if((target->sizeofSelect) > PCR_SELECT_MAX)
        return TPM_RC_VALUE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->pcrSelect), buffer, size, (INT32)(target->sizeofSelect));
    return result;
}

UINT16
TPMS_PCR_SELECTION_Marshal(
    TPMS_PCR_SELECTION *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->hash), buffer, size));
    result = (UINT16)(result + UINT8_Marshal((UINT8 *)&(source->sizeofSelect), buffer, size));
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->pcrSelect), buffer, size, (INT32)(source->sizeofSelect)));
    return result;
}


// Table 2:88 - Definition of TPMT_TK_CREATION Structure (StructureTable)
TPM_RC
TPMT_TK_CREATION_Unmarshal(
    TPMT_TK_CREATION *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = TPM_ST_Unmarshal((TPM_ST *)&(target->tag), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( ((target->tag) != TPM_ST_CREATION))
        return TPM_RC_TAG;
    result = TPMI_RH_HIERARCHY_Unmarshal((TPMI_RH_HIERARCHY *)&(target->hierarchy), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->digest), buffer, size);
    return result;
}

UINT16
TPMT_TK_CREATION_Marshal(
    TPMT_TK_CREATION *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_ST_Marshal((TPM_ST *)&(source->tag), buffer, size));
    result = (UINT16)(result + TPMI_RH_HIERARCHY_Marshal((TPMI_RH_HIERARCHY *)&(source->hierarchy), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->digest), buffer, size));
    return result;
}


// Table 2:89 - Definition of TPMT_TK_VERIFIED Structure (StructureTable)
TPM_RC
TPMT_TK_VERIFIED_Unmarshal(
    TPMT_TK_VERIFIED *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = TPM_ST_Unmarshal((TPM_ST *)&(target->tag), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( ((target->tag) != TPM_ST_VERIFIED))
        return TPM_RC_TAG;
    result = TPMI_RH_HIERARCHY_Unmarshal((TPMI_RH_HIERARCHY *)&(target->hierarchy), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->digest), buffer, size);
    return result;
}

UINT16
TPMT_TK_VERIFIED_Marshal(
    TPMT_TK_VERIFIED *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_ST_Marshal((TPM_ST *)&(source->tag), buffer, size));
    result = (UINT16)(result + TPMI_RH_HIERARCHY_Marshal((TPMI_RH_HIERARCHY *)&(source->hierarchy), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->digest), buffer, size));
    return result;
}


// Table 2:90 - Definition of TPMT_TK_AUTH Structure (StructureTable)
TPM_RC
TPMT_TK_AUTH_Unmarshal(
    TPMT_TK_AUTH *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = TPM_ST_Unmarshal((TPM_ST *)&(target->tag), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( ((target->tag) != TPM_ST_AUTH_SIGNED)
     && ((target->tag) != TPM_ST_AUTH_SECRET))
        return TPM_RC_TAG;
    result = TPMI_RH_HIERARCHY_Unmarshal((TPMI_RH_HIERARCHY *)&(target->hierarchy), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->digest), buffer, size);
    return result;
}

UINT16
TPMT_TK_AUTH_Marshal(
    TPMT_TK_AUTH *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_ST_Marshal((TPM_ST *)&(source->tag), buffer, size));
    result = (UINT16)(result + TPMI_RH_HIERARCHY_Marshal((TPMI_RH_HIERARCHY *)&(source->hierarchy), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->digest), buffer, size));
    return result;
}


// Table 2:91 - Definition of TPMT_TK_HASHCHECK Structure (StructureTable)
TPM_RC
TPMT_TK_HASHCHECK_Unmarshal(
    TPMT_TK_HASHCHECK *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM_ST_Unmarshal((TPM_ST *)&(target->tag), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( ((target->tag) != TPM_ST_HASHCHECK))
        return TPM_RC_TAG;
    result = TPMI_RH_HIERARCHY_Unmarshal((TPMI_RH_HIERARCHY *)&(target->hierarchy), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->digest), buffer, size);
    return result;
}

UINT16
TPMT_TK_HASHCHECK_Marshal(
    TPMT_TK_HASHCHECK *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_ST_Marshal((TPM_ST *)&(source->tag), buffer, size));
    result = (UINT16)(result + TPMI_RH_HIERARCHY_Marshal((TPMI_RH_HIERARCHY *)&(source->hierarchy), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->digest), buffer, size));
    return result;
}


// Table 2:92 - Definition of TPMS_ALG_PROPERTY Structure  (StructureTable)
//     TPMS_ALG_PROPERTY_Unmarshal not referenced
UINT16
TPMS_ALG_PROPERTY_Marshal(
    TPMS_ALG_PROPERTY *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_ALG_ID_Marshal((TPM_ALG_ID *)&(source->alg), buffer, size));
    result = (UINT16)(result + TPMA_ALGORITHM_Marshal((TPMA_ALGORITHM *)&(source->algProperties), buffer, size));
    return result;
}


// Table 2:93 - Definition of TPMS_TAGGED_PROPERTY Structure  (StructureTable)
//     TPMS_TAGGED_PROPERTY_Unmarshal not referenced
UINT16
TPMS_TAGGED_PROPERTY_Marshal(
    TPMS_TAGGED_PROPERTY *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_PT_Marshal((TPM_PT *)&(source->property), buffer, size));
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->value), buffer, size));
    return result;
}


// Table 2:94 - Definition of TPMS_TAGGED_PCR_SELECT Structure  (StructureTable)
//     TPMS_TAGGED_PCR_SELECT_Unmarshal not referenced
UINT16
TPMS_TAGGED_PCR_SELECT_Marshal(
    TPMS_TAGGED_PCR_SELECT *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_PT_Marshal((TPM_PT *)&(source->tag), buffer, size));
    result = (UINT16)(result + UINT8_Marshal((UINT8 *)&(source->sizeofSelect), buffer, size));
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->pcrSelect), buffer, size, (INT32)(source->sizeofSelect)));
    return result;
}


// Table 2:95 - Definition of TPML_CC Structure (StructureTable)
TPM_RC
TPML_CC_Unmarshal(
    TPML_CC *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)&(target->count), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if((target->count) > MAX_CAP_CC)
        return TPM_RC_SIZE;
    result = TPM_CC_Array_Unmarshal((TPM_CC *)(target->commandCodes), buffer, size, (INT32)(target->count));
    return result;
}

UINT16
TPML_CC_Marshal(
    TPML_CC *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPM_CC_Array_Marshal((TPM_CC *)(source->commandCodes), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:96 - Definition of TPML_CCA Structure  (StructureTable)
//     TPML_CCA_Unmarshal not referenced
UINT16
TPML_CCA_Marshal(
    TPML_CCA *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPMA_CC_Array_Marshal((TPMA_CC *)(source->commandAttributes), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:97 - Definition of TPML_ALG Structure (StructureTable)
TPM_RC
TPML_ALG_Unmarshal(
    TPML_ALG *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)&(target->count), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if((target->count) > MAX_ALG_LIST_SIZE)
        return TPM_RC_SIZE;
    result = TPM_ALG_ID_Array_Unmarshal((TPM_ALG_ID *)(target->algorithms), buffer, size, (INT32)(target->count));
    return result;
}

UINT16
TPML_ALG_Marshal(
    TPML_ALG *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPM_ALG_ID_Array_Marshal((TPM_ALG_ID *)(source->algorithms), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:98 - Definition of TPML_HANDLE Structure  (StructureTable)
//     TPML_HANDLE_Unmarshal not referenced
UINT16
TPML_HANDLE_Marshal(
    TPML_HANDLE *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPM_HANDLE_Array_Marshal((TPM_HANDLE *)(source->handle), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:99 - Definition of TPML_DIGEST Structure (StructureTable)
TPM_RC
TPML_DIGEST_Unmarshal(
    TPML_DIGEST *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)&(target->count), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( (target->count < 2))
        return TPM_RC_SIZE;
    if((target->count) > 8)
        return TPM_RC_SIZE;
    result = TPM2B_DIGEST_Array_Unmarshal((TPM2B_DIGEST *)(target->digests), buffer, size, (INT32)(target->count));
    return result;
}

UINT16
TPML_DIGEST_Marshal(
    TPML_DIGEST *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Array_Marshal((TPM2B_DIGEST *)(source->digests), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:100 - Definition of TPML_DIGEST_VALUES Structure (StructureTable)
TPM_RC
TPML_DIGEST_VALUES_Unmarshal(
    TPML_DIGEST_VALUES *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)&(target->count), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if((target->count) > HASH_COUNT)
        return TPM_RC_SIZE;
    result = TPMT_HA_Array_Unmarshal((TPMT_HA *)(target->digests), buffer, size, 0, (INT32)(target->count));
    return result;
}

UINT16
TPML_DIGEST_VALUES_Marshal(
    TPML_DIGEST_VALUES *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPMT_HA_Array_Marshal((TPMT_HA *)(source->digests), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:101 - Definition of TPM2B_DIGEST_VALUES Structure (StructureTable)
//     TPM2B_DIGEST_VALUES_Unmarshal not referenced
//     TPM2B_DIGEST_VALUES_Marshal not referenced


// Table 2:102 - Definition of TPML_PCR_SELECTION Structure (StructureTable)
TPM_RC
TPML_PCR_SELECTION_Unmarshal(
    TPML_PCR_SELECTION *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)&(target->count), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if((target->count) > HASH_COUNT)
        return TPM_RC_SIZE;
    result = TPMS_PCR_SELECTION_Array_Unmarshal((TPMS_PCR_SELECTION *)(target->pcrSelections), buffer, size, (INT32)(target->count));
    return result;
}

UINT16
TPML_PCR_SELECTION_Marshal(
    TPML_PCR_SELECTION *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPMS_PCR_SELECTION_Array_Marshal((TPMS_PCR_SELECTION *)(source->pcrSelections), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:103 - Definition of TPML_ALG_PROPERTY Structure  (StructureTable)
//     TPML_ALG_PROPERTY_Unmarshal not referenced
UINT16
TPML_ALG_PROPERTY_Marshal(
    TPML_ALG_PROPERTY *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPMS_ALG_PROPERTY_Array_Marshal((TPMS_ALG_PROPERTY *)(source->algProperties), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:104 - Definition of TPML_TAGGED_TPM_PROPERTY Structure  (StructureTable)
//     TPML_TAGGED_TPM_PROPERTY_Unmarshal not referenced
UINT16
TPML_TAGGED_TPM_PROPERTY_Marshal(
    TPML_TAGGED_TPM_PROPERTY *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPMS_TAGGED_PROPERTY_Array_Marshal((TPMS_TAGGED_PROPERTY *)(source->tpmProperty), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:105 - Definition of TPML_TAGGED_PCR_PROPERTY Structure  (StructureTable)
//     TPML_TAGGED_PCR_PROPERTY_Unmarshal not referenced
UINT16
TPML_TAGGED_PCR_PROPERTY_Marshal(
    TPML_TAGGED_PCR_PROPERTY *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPMS_TAGGED_PCR_SELECT_Array_Marshal((TPMS_TAGGED_PCR_SELECT *)(source->pcrProperty), buffer, size, (INT32)(source->count)));
    return result;
}


// Table 2:106 - Definition of TPML_ECC_CURVE Structure  (StructureTable)
#ifdef    TPM_ALG_ECC
//     TPML_ECC_CURVE_Unmarshal not referenced
UINT16
TPML_ECC_CURVE_Marshal(
    TPML_ECC_CURVE *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
    result = (UINT16)(result + TPM_ECC_CURVE_Array_Marshal((TPM_ECC_CURVE *)(source->eccCurves), buffer, size, (INT32)(source->count)));
    return result;
}

#endif // TPM_ALG_ECC

#ifdef ME11_SIM
UINT16
INTEL_PROP_VALUE_Marshal(INTEL_PROP_VALUE *source, BYTE **buffer, INT32 *size)
{
	UINT16    result = 0;
	result = (UINT16)(result + UINT32_Marshal((UINT32 *)source, buffer, size));
	return result;
}

UINT16
INTEL_PROPERTY_Marshal(INTEL_PROPERTY *source, BYTE **buffer, INT32 *size)
{
	UINT16    result = 0;
	result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->count), buffer, size));
	result = (UINT16)(result + INTEL_PROP_VALUE_Marshal(&(source->property), buffer, size));

	return result;
}
#endif

// Table 2:107 - Definition of TPMU_CAPABILITIES Union  (UnionTable)
//     TPMU_CAPABILITIES_Unmarshal not referenced
UINT16
TPMU_CAPABILITIES_Marshal(
    TPMU_CAPABILITIES *source, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
        case TPM_CAP_ALGS:
            return TPML_ALG_PROPERTY_Marshal((TPML_ALG_PROPERTY *)&(source->algorithms), buffer, size);
        case TPM_CAP_HANDLES:
            return TPML_HANDLE_Marshal((TPML_HANDLE *)&(source->handles), buffer, size);
        case TPM_CAP_COMMANDS:
            return TPML_CCA_Marshal((TPML_CCA *)&(source->command), buffer, size);
        case TPM_CAP_PP_COMMANDS:
            return TPML_CC_Marshal((TPML_CC *)&(source->ppCommands), buffer, size);
        case TPM_CAP_AUDIT_COMMANDS:
            return TPML_CC_Marshal((TPML_CC *)&(source->auditCommands), buffer, size);
        case TPM_CAP_PCRS:
            return TPML_PCR_SELECTION_Marshal((TPML_PCR_SELECTION *)&(source->assignedPCR), buffer, size);
        case TPM_CAP_TPM_PROPERTIES:
            return TPML_TAGGED_TPM_PROPERTY_Marshal((TPML_TAGGED_TPM_PROPERTY *)&(source->tpmProperties), buffer, size);
        case TPM_CAP_PCR_PROPERTIES:
            return TPML_TAGGED_PCR_PROPERTY_Marshal((TPML_TAGGED_PCR_PROPERTY *)&(source->pcrProperties), buffer, size);
#ifdef    TPM_ALG_ECC
        case TPM_CAP_ECC_CURVES:
            return TPML_ECC_CURVE_Marshal((TPML_ECC_CURVE *)&(source->eccCurves), buffer, size);
#endif // TPM_ALG_ECC
#ifdef    ME11_SIM
		case TPM_CAP_VENDOR_PROPERTY:
			return INTEL_PROPERTY_Marshal((INTEL_PROPERTY *)&(source->intelProperty), buffer, size);
#endif
	}
    return 0;
}


// Table 2:108 - Definition of TPMS_CAPABILITY_DATA Structure  (StructureTable)
//     TPMS_CAPABILITY_DATA_Unmarshal not referenced
UINT16
TPMS_CAPABILITY_DATA_Marshal(
    TPMS_CAPABILITY_DATA *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_CAP_Marshal((TPM_CAP *)&(source->capability), buffer, size));
    result = (UINT16)(result + TPMU_CAPABILITIES_Marshal((TPMU_CAPABILITIES *)&(source->data), buffer, size, (UINT32)source->capability));
    return result;
}


// Table 2:109 - Definition of TPMS_CLOCK_INFO Structure (StructureTable)
//     TPMS_CLOCK_INFO_Unmarshal not referenced
UINT16
TPMS_CLOCK_INFO_Marshal(
    TPMS_CLOCK_INFO *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT64_Marshal((UINT64 *)&(source->clock), buffer, size));
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->resetCount), buffer, size));
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->restartCount), buffer, size));
    result = (UINT16)(result + TPMI_YES_NO_Marshal((TPMI_YES_NO *)&(source->safe), buffer, size));
    return result;
}


// Table 2:110 - Definition of TPMS_TIME_INFO Structure (StructureTable)
//     TPMS_TIME_INFO_Unmarshal not referenced
UINT16
TPMS_TIME_INFO_Marshal(
    TPMS_TIME_INFO *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT64_Marshal((UINT64 *)&(source->time), buffer, size));
    result = (UINT16)(result + TPMS_CLOCK_INFO_Marshal((TPMS_CLOCK_INFO *)&(source->clockInfo), buffer, size));
    return result;
}


// Table 2:111 - Definition of TPMS_TIME_ATTEST_INFO Structure  (StructureTable)
//     TPMS_TIME_ATTEST_INFO_Unmarshal not referenced
UINT16
TPMS_TIME_ATTEST_INFO_Marshal(
    TPMS_TIME_ATTEST_INFO *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMS_TIME_INFO_Marshal((TPMS_TIME_INFO *)&(source->time), buffer, size));
    result = (UINT16)(result + UINT64_Marshal((UINT64 *)&(source->firmwareVersion), buffer, size));
    return result;
}


// Table 2:112 - Definition of TPMS_CERTIFY_INFO Structure  (StructureTable)
//     TPMS_CERTIFY_INFO_Unmarshal not referenced
UINT16
TPMS_CERTIFY_INFO_Marshal(
    TPMS_CERTIFY_INFO *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->name), buffer, size));
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->qualifiedName), buffer, size));
    return result;
}


// Table 2:113 - Definition of TPMS_QUOTE_INFO Structure  (StructureTable)
//     TPMS_QUOTE_INFO_Unmarshal not referenced
UINT16
TPMS_QUOTE_INFO_Marshal(
    TPMS_QUOTE_INFO *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPML_PCR_SELECTION_Marshal((TPML_PCR_SELECTION *)&(source->pcrSelect), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->pcrDigest), buffer, size));
    return result;
}


// Table 2:114 - Definition of TPMS_COMMAND_AUDIT_INFO Structure  (StructureTable)
//     TPMS_COMMAND_AUDIT_INFO_Unmarshal not referenced
UINT16
TPMS_COMMAND_AUDIT_INFO_Marshal(
    TPMS_COMMAND_AUDIT_INFO *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT64_Marshal((UINT64 *)&(source->auditCounter), buffer, size));
    result = (UINT16)(result + TPM_ALG_ID_Marshal((TPM_ALG_ID *)&(source->digestAlg), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->auditDigest), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->commandDigest), buffer, size));
    return result;
}


// Table 2:115 - Definition of TPMS_SESSION_AUDIT_INFO Structure  (StructureTable)
//     TPMS_SESSION_AUDIT_INFO_Unmarshal not referenced
UINT16
TPMS_SESSION_AUDIT_INFO_Marshal(
    TPMS_SESSION_AUDIT_INFO *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_YES_NO_Marshal((TPMI_YES_NO *)&(source->exclusiveSession), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->sessionDigest), buffer, size));
    return result;
}


// Table 2:116 - Definition of TPMS_CREATION_INFO Structure  (StructureTable)
//     TPMS_CREATION_INFO_Unmarshal not referenced
UINT16
TPMS_CREATION_INFO_Marshal(
    TPMS_CREATION_INFO *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->objectName), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->creationHash), buffer, size));
    return result;
}


// Table 2:117 - Definition of TPMS_NV_CERTIFY_INFO Structure  (StructureTable)
//     TPMS_NV_CERTIFY_INFO_Unmarshal not referenced
UINT16
TPMS_NV_CERTIFY_INFO_Marshal(
    TPMS_NV_CERTIFY_INFO *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->indexName), buffer, size));
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->offset), buffer, size));
    result = (UINT16)(result + TPM2B_MAX_NV_BUFFER_Marshal((TPM2B_MAX_NV_BUFFER *)&(source->nvContents), buffer, size));
    return result;
}


// Table 2:118 - Definition of TPMI_ST_ATTEST Type  (TypeTable)
//     TPMI_ST_ATTEST_Unmarshal not referenced
//   TPMI_ST_ATTEST_Marshal changed to #define


// Table 2:119 - Definition of TPMU_ATTEST Union  (UnionTable)
//     TPMU_ATTEST_Unmarshal not referenced
UINT16
TPMU_ATTEST_Marshal(
    TPMU_ATTEST *source, BYTE **buffer, INT32 *size, UINT32      selector
    )
{
    switch(selector) {
        case TPM_ST_ATTEST_CERTIFY:
            return TPMS_CERTIFY_INFO_Marshal((TPMS_CERTIFY_INFO *)&(source->certify), buffer, size);
        case TPM_ST_ATTEST_CREATION:
            return TPMS_CREATION_INFO_Marshal((TPMS_CREATION_INFO *)&(source->creation), buffer, size);
        case TPM_ST_ATTEST_QUOTE:
            return TPMS_QUOTE_INFO_Marshal((TPMS_QUOTE_INFO *)&(source->quote), buffer, size);
        case TPM_ST_ATTEST_COMMAND_AUDIT:
            return TPMS_COMMAND_AUDIT_INFO_Marshal((TPMS_COMMAND_AUDIT_INFO *)&(source->commandAudit), buffer, size);
        case TPM_ST_ATTEST_SESSION_AUDIT:
            return TPMS_SESSION_AUDIT_INFO_Marshal((TPMS_SESSION_AUDIT_INFO *)&(source->sessionAudit), buffer, size);
        case TPM_ST_ATTEST_TIME:
            return TPMS_TIME_ATTEST_INFO_Marshal((TPMS_TIME_ATTEST_INFO *)&(source->time), buffer, size);
        case TPM_ST_ATTEST_NV:
            return TPMS_NV_CERTIFY_INFO_Marshal((TPMS_NV_CERTIFY_INFO *)&(source->nv), buffer, size);
    }
    return 0;
}


// Table 2:120 - Definition of TPMS_ATTEST Structure  (StructureTable)
//     TPMS_ATTEST_Unmarshal not referenced
UINT16
TPMS_ATTEST_Marshal(
    TPMS_ATTEST *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_GENERATED_Marshal((TPM_GENERATED *)&(source->magic), buffer, size));
    result = (UINT16)(result + TPMI_ST_ATTEST_Marshal((TPMI_ST_ATTEST *)&(source->type), buffer, size));
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->qualifiedSigner), buffer, size));
    result = (UINT16)(result + TPM2B_DATA_Marshal((TPM2B_DATA *)&(source->extraData), buffer, size));
    result = (UINT16)(result + TPMS_CLOCK_INFO_Marshal((TPMS_CLOCK_INFO *)&(source->clockInfo), buffer, size));
    result = (UINT16)(result + UINT64_Marshal((UINT64 *)&(source->firmwareVersion), buffer, size));
    result = (UINT16)(result + TPMU_ATTEST_Marshal((TPMU_ATTEST *)&(source->attested), buffer, size, (UINT32)source->type));
    return result;
}


// Table 2:121 - Definition of TPM2B_ATTEST Structure  (StructureTable)
//     TPM2B_ATTEST_Unmarshal not referenced
UINT16
TPM2B_ATTEST_Marshal(
    TPM2B_ATTEST *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.attestationData), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:122 - Definition of TPMS_AUTH_COMMAND Structure  (StructureTable)
//     TPMS_AUTH_COMMAND_Unmarshal not referenced
//     TPMS_AUTH_COMMAND_Marshal not referenced


// Table 2:123 - Definition of TPMS_AUTH_RESPONSE Structure  (StructureTable)
//     TPMS_AUTH_RESPONSE_Unmarshal not referenced
//     TPMS_AUTH_RESPONSE_Marshal not referenced


// Table 2:124 - Definition of TPMI_AES_KEY_BITS Type (TypeTable)
#ifdef    TPM_ALG_AES
TPM_RC
TPMI_AES_KEY_BITS_Unmarshal(
    TPMI_AES_KEY_BITS *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM_KEY_BITS_Unmarshal((TPM_KEY_BITS *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case 128:
        case 256:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_AES_KEY_BITS_Marshal changed to #define
#endif // TPM_ALG_AES


// Table 2:124 - Definition of TPMI_SM4_KEY_BITS Type (TypeTable)
#ifdef    TPM_ALG_SM4
TPM_RC
TPMI_SM4_KEY_BITS_Unmarshal(
    TPMI_SM4_KEY_BITS *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM_KEY_BITS_Unmarshal((TPM_KEY_BITS *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case 128:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_SM4_KEY_BITS_Marshal changed to #define
#endif // TPM_ALG_SM4


// Table 2:124 - Definition of TPMI_CAMELLIA_KEY_BITS Type (TypeTable)
#ifdef    TPM_ALG_CAMELLIA
TPM_RC
TPMI_CAMELLIA_KEY_BITS_Unmarshal(
    TPMI_CAMELLIA_KEY_BITS *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPM_KEY_BITS_Unmarshal((TPM_KEY_BITS *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case 128:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_CAMELLIA_KEY_BITS_Marshal changed to #define
#endif // TPM_ALG_CAMELLIA


// Table 2:125 - Definition of TPMU_SYM_KEY_BITS Union (UnionTable)
TPM_RC
TPMU_SYM_KEY_BITS_Unmarshal(
    TPMU_SYM_KEY_BITS *target, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_AES
        case TPM_ALG_AES:
            return TPMI_AES_KEY_BITS_Unmarshal((TPMI_AES_KEY_BITS *)&(target->aes), buffer, size);
#endif // TPM_ALG_AES
#ifdef    TPM_ALG_SM4
        case TPM_ALG_SM4:
            return TPMI_SM4_KEY_BITS_Unmarshal((TPMI_SM4_KEY_BITS *)&(target->sm4), buffer, size);
#endif // TPM_ALG_SM4
#ifdef    TPM_ALG_CAMELLIA
        case TPM_ALG_CAMELLIA:
            return TPMI_CAMELLIA_KEY_BITS_Unmarshal((TPMI_CAMELLIA_KEY_BITS *)&(target->camellia), buffer, size);
#endif // TPM_ALG_CAMELLIA
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
            return TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->exclusiveOr
					), buffer, size, 0);
#endif // TPM_ALG_XOR
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_SYM_KEY_BITS_Marshal(
    TPMU_SYM_KEY_BITS *source, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_AES
        case TPM_ALG_AES:
            return TPMI_AES_KEY_BITS_Marshal((TPMI_AES_KEY_BITS *)&(source->aes), buffer, size);
#endif // TPM_ALG_AES
#ifdef    TPM_ALG_SM4
        case TPM_ALG_SM4:
            return TPMI_SM4_KEY_BITS_Marshal((TPMI_SM4_KEY_BITS *)&(source->sm4), buffer, size);
#endif // TPM_ALG_SM4
#ifdef    TPM_ALG_CAMELLIA
        case TPM_ALG_CAMELLIA:
            return TPMI_CAMELLIA_KEY_BITS_Marshal((TPMI_CAMELLIA_KEY_BITS *)&(source->camellia), buffer, size);
#endif // TPM_ALG_CAMELLIA
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
            return TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->exclusiveOr
					), buffer, size);
#endif // TPM_ALG_XOR
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:126 - Definition of TPMU_SYM_MODE Union (UnionTable)
TPM_RC
TPMU_SYM_MODE_Unmarshal(
    TPMU_SYM_MODE *target, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_AES
        case TPM_ALG_AES:
            return TPMI_ALG_SYM_MODE_Unmarshal((TPMI_ALG_SYM_MODE *)&(target->aes), buffer, size, 1);
#endif // TPM_ALG_AES
#ifdef    TPM_ALG_SM4
        case TPM_ALG_SM4:
            return TPMI_ALG_SYM_MODE_Unmarshal((TPMI_ALG_SYM_MODE *)&(target->sm4), buffer, size, 1);
#endif // TPM_ALG_SM4
#ifdef    TPM_ALG_CAMELLIA
        case TPM_ALG_CAMELLIA:
            return TPMI_ALG_SYM_MODE_Unmarshal((TPMI_ALG_SYM_MODE *)&(target->camellia), buffer, size, 1);
#endif // TPM_ALG_CAMELLIA
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
            return TPM_RC_SUCCESS;
#endif // TPM_ALG_XOR
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_SYM_MODE_Marshal(
    TPMU_SYM_MODE *source, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_AES
        case TPM_ALG_AES:
            return TPMI_ALG_SYM_MODE_Marshal((TPMI_ALG_SYM_MODE *)&(source->aes), buffer, size);
#endif // TPM_ALG_AES
#ifdef    TPM_ALG_SM4
        case TPM_ALG_SM4:
            return TPMI_ALG_SYM_MODE_Marshal((TPMI_ALG_SYM_MODE *)&(source->sm4), buffer, size);
#endif // TPM_ALG_SM4
#ifdef    TPM_ALG_CAMELLIA
        case TPM_ALG_CAMELLIA:
            return TPMI_ALG_SYM_MODE_Marshal((TPMI_ALG_SYM_MODE *)&(source->camellia), buffer, size);
#endif // TPM_ALG_CAMELLIA
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
            return 0;
#endif // TPM_ALG_XOR
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:128 - Definition of TPMT_SYM_DEF Structure (StructureTable)
TPM_RC
TPMT_SYM_DEF_Unmarshal(
    TPMT_SYM_DEF *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_SYM_Unmarshal((TPMI_ALG_SYM *)&(target->algorithm), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SYM_KEY_BITS_Unmarshal((TPMU_SYM_KEY_BITS *)&(target->keyBits), buffer, size, (UINT32)target->algorithm);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SYM_MODE_Unmarshal((TPMU_SYM_MODE *)&(target->mode), buffer, size, (UINT32)target->algorithm);
    return result;
}

//     TPMT_SYM_DEF_Marshal not referenced


// Table 2:129 - Definition of TPMT_SYM_DEF_OBJECT Structure (StructureTable)
TPM_RC
TPMT_SYM_DEF_OBJECT_Unmarshal(
    TPMT_SYM_DEF_OBJECT *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_SYM_OBJECT_Unmarshal((TPMI_ALG_SYM_OBJECT *)&(target->algorithm), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SYM_KEY_BITS_Unmarshal((TPMU_SYM_KEY_BITS *)&(target->keyBits), buffer, size, (UINT32)target->algorithm);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SYM_MODE_Unmarshal((TPMU_SYM_MODE *)&(target->mode), buffer, size, (UINT32)target->algorithm);
    return result;
}

UINT16
TPMT_SYM_DEF_OBJECT_Marshal(
    TPMT_SYM_DEF_OBJECT *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_SYM_OBJECT_Marshal((TPMI_ALG_SYM_OBJECT *)&(source->algorithm), buffer, size));
    result = (UINT16)(result + TPMU_SYM_KEY_BITS_Marshal((TPMU_SYM_KEY_BITS *)&(source->keyBits), buffer, size, (UINT32)source->algorithm));
    result = (UINT16)(result + TPMU_SYM_MODE_Marshal((TPMU_SYM_MODE *)&(source->mode), buffer, size, (UINT32)source->algorithm));
    return result;
}


// Table 2:130 - Definition of TPM2B_SYM_KEY Structure (StructureTable)
TPM_RC
TPM2B_SYM_KEY_Unmarshal(
    TPM2B_SYM_KEY *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_SYM_KEY_BYTES)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_SYM_KEY_Marshal(
    TPM2B_SYM_KEY *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:131 - Definition of TPMS_SYMCIPHER_PARMS Structure (StructureTable)
//   TPMS_SYMCIPHER_PARMS_Unmarshal changed to #define
//   TPMS_SYMCIPHER_PARMS_Marshal changed to #define


// Table 2:132 - Definition of TPM2B_SENSITIVE_DATA Structure (StructureTable)
TPM_RC
TPM2B_SENSITIVE_DATA_Unmarshal(
    TPM2B_SENSITIVE_DATA *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_SYM_DATA)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_SENSITIVE_DATA_Marshal(
    TPM2B_SENSITIVE_DATA *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:133 - Definition of TPMS_SENSITIVE_CREATE Structure  (StructureTable)
TPM_RC
TPMS_SENSITIVE_CREATE_Unmarshal(
    TPMS_SENSITIVE_CREATE *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM2B_AUTH_Unmarshal((TPM2B_AUTH *)&(target->userAuth), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_SENSITIVE_DATA_Unmarshal((TPM2B_SENSITIVE_DATA *)&(target->data), buffer, size);
    return result;
}

//     TPMS_SENSITIVE_CREATE_Marshal not referenced


// Table 2:134 - Definition of TPM2B_SENSITIVE_CREATE Structure  (StructureTable)
TPM_RC
TPM2B_SENSITIVE_CREATE_Unmarshal(
    TPM2B_SENSITIVE_CREATE *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    INT32    startSize;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size is zero, then the required structure is missing
    if(target->t.size == 0)
        return TPM_RC_SIZE;
    startSize = *size;
    result = TPMS_SENSITIVE_CREATE_Unmarshal((TPMS_SENSITIVE_CREATE *)&(target->t.sensitive), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(target->t.size != (startSize - *size)) return TPM_RC_SIZE;
    return TPM_RC_SUCCESS;
}

//     TPM2B_SENSITIVE_CREATE_Marshal not referenced


// Table 2:135 - Definition of TPMS_SCHEME_HASH Structure (StructureTable)
//   TPMS_SCHEME_HASH_Unmarshal changed to #define
//   TPMS_SCHEME_HASH_Marshal changed to #define


// Table 2:136 - Definition of TPMS_SCHEME_ECDAA Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMS_SCHEME_ECDAA_Unmarshal(
    TPMS_SCHEME_ECDAA *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->hashAlg), buffer, size, 0);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = UINT16_Unmarshal((UINT16 *)&(target->count), buffer, size);
    return result;
}

UINT16
TPMS_SCHEME_ECDAA_Marshal(
    TPMS_SCHEME_ECDAA *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->hashAlg), buffer, size));
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->count), buffer, size));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:137 - Definition of TPMI_ALG_KEYEDHASH_SCHEME Type (TypeTable)
TPM_RC
TPMI_ALG_KEYEDHASH_SCHEME_Unmarshal(
    TPMI_ALG_KEYEDHASH_SCHEME *target, BYTE **buffer, INT32 *size, BOOL      flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
#endif // TPM_ALG_HMAC
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
#endif // TPM_ALG_XOR
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_VALUE;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_KEYEDHASH_SCHEME_Marshal changed to #define


// Table 2:138 - Definition of Types for HMAC_SIG_SCHEME (TypesTable)
//   TPMS_SCHEME_HASH definition from table 2:138
//   TPMS_SCHEME_HMAC_Unmarshal changed to #define
//   TPMS_SCHEME_HMAC_Marshal changed to #define


// Table 2:139 - Definition of TPMS_SCHEME_XOR Structure (StructureTable)
TPM_RC
TPMS_SCHEME_XOR_Unmarshal(
    TPMS_SCHEME_XOR *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->hashAlg), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_ALG_KDF_Unmarshal((TPMI_ALG_KDF *)&(target->kdf), buffer, size, 1);
    return result;
}

UINT16
TPMS_SCHEME_XOR_Marshal(
    TPMS_SCHEME_XOR *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->hashAlg), buffer, size));
    result = (UINT16)(result + TPMI_ALG_KDF_Marshal((TPMI_ALG_KDF *)&(source->kdf), buffer, size));
    return result;
}


// Table 2:140 - Definition of TPMU_SCHEME_KEYEDHASH Union  (UnionTable)
TPM_RC
TPMU_SCHEME_KEYEDHASH_Unmarshal(
    TPMU_SCHEME_KEYEDHASH *target, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
            return TPMS_SCHEME_HMAC_Unmarshal((TPMS_SCHEME_HMAC *)&(target->hmac), buffer, size);
#endif // TPM_ALG_HMAC
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
            return TPMS_SCHEME_XOR_Unmarshal((TPMS_SCHEME_XOR *)&(target->exclusiveOr
					), buffer, size, 1);
#endif // TPM_ALG_XOR
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_SCHEME_KEYEDHASH_Marshal(
    TPMU_SCHEME_KEYEDHASH *source, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
            return TPMS_SCHEME_HMAC_Marshal((TPMS_SCHEME_HMAC *)&(source->hmac), buffer, size);
#endif // TPM_ALG_HMAC
#ifdef    TPM_ALG_XOR
        case TPM_ALG_XOR:
            return TPMS_SCHEME_XOR_Marshal((TPMS_SCHEME_XOR *)&(source->exclusiveOr
					), buffer, size);
#endif // TPM_ALG_XOR
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:141 - Definition of TPMT_KEYEDHASH_SCHEME Structure (StructureTable)
TPM_RC
TPMT_KEYEDHASH_SCHEME_Unmarshal(
    TPMT_KEYEDHASH_SCHEME *target, BYTE **buffer, INT32 *size, BOOL      flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_KEYEDHASH_SCHEME_Unmarshal((TPMI_ALG_KEYEDHASH_SCHEME *)&(target->scheme), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SCHEME_KEYEDHASH_Unmarshal((TPMU_SCHEME_KEYEDHASH *)&(target->details), buffer, size, (UINT32)target->scheme);
    return result;
}

UINT16
TPMT_KEYEDHASH_SCHEME_Marshal(
    TPMT_KEYEDHASH_SCHEME *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_KEYEDHASH_SCHEME_Marshal((TPMI_ALG_KEYEDHASH_SCHEME *)&(source->scheme), buffer, size));
    result = (UINT16)(result + TPMU_SCHEME_KEYEDHASH_Marshal((TPMU_SCHEME_KEYEDHASH *)&(source->details), buffer, size, (UINT32)source->scheme));
    return result;
}


// Table 2:142 - Definition of Types for RSA Signature Schemes  (TypesTable)
#ifdef    TPM_ALG_RSA
//   TPMS_SCHEME_HASH definition from table 2:142
#ifdef    TPM_ALG_RSA
//   TPMS_SIG_SCHEME_RSASSA_Unmarshal changed to #define
//   TPMS_SIG_SCHEME_RSASSA_Marshal changed to #define
#endif // TPM_ALG_RSA
//   TPMS_SCHEME_HASH definition from table 2:142
#ifdef    TPM_ALG_RSA
//   TPMS_SIG_SCHEME_RSAPSS_Unmarshal changed to #define
//   TPMS_SIG_SCHEME_RSAPSS_Marshal changed to #define
#endif // TPM_ALG_RSA
#endif // TPM_ALG_RSA


// Table 2:143 - Definition of Types for ECC Signature Schemes  (TypesTable)
#ifdef    TPM_ALG_ECC
//   TPMS_SCHEME_HASH definition from table 2:143
#ifdef    TPM_ALG_ECC
//   TPMS_SIG_SCHEME_ECDSA_Unmarshal changed to #define
//   TPMS_SIG_SCHEME_ECDSA_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SCHEME_HASH definition from table 2:143
#ifdef    TPM_ALG_ECC
//   TPMS_SIG_SCHEME_SM2_Unmarshal changed to #define
//   TPMS_SIG_SCHEME_SM2_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SCHEME_HASH definition from table 2:143
#ifdef    TPM_ALG_ECC
//   TPMS_SIG_SCHEME_ECSCHNORR_Unmarshal changed to #define
//   TPMS_SIG_SCHEME_ECSCHNORR_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SCHEME_ECDAA definition from table 2:143
#ifdef    TPM_ALG_ECC
//   TPMS_SIG_SCHEME_ECDAA_Unmarshal changed to #define
//   TPMS_SIG_SCHEME_ECDAA_Marshal changed to #define
#endif // TPM_ALG_ECC
#endif // TPM_ALG_ECC


// Table 2:144 - Definition of TPMU_SIG_SCHEME Union  (UnionTable)
TPM_RC
TPMU_SIG_SCHEME_Unmarshal(
    TPMU_SIG_SCHEME *target, BYTE **buffer, INT32 *size, UINT32      selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
            return TPMS_SIG_SCHEME_RSASSA_Unmarshal((TPMS_SIG_SCHEME_RSASSA *)&(target->rsassa), buffer, size);
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
            return TPMS_SIG_SCHEME_RSAPSS_Unmarshal((TPMS_SIG_SCHEME_RSAPSS *)&(target->rsapss), buffer, size);
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
            return TPMS_SIG_SCHEME_ECDSA_Unmarshal((TPMS_SIG_SCHEME_ECDSA *)&(target->ecdsa), buffer, size);
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
            return TPMS_SIG_SCHEME_SM2_Unmarshal((TPMS_SIG_SCHEME_SM2 *)&(target->sm2), buffer, size);
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
            return TPMS_SIG_SCHEME_ECSCHNORR_Unmarshal((TPMS_SIG_SCHEME_ECSCHNORR *)&(target->ecschnorr), buffer, size);
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
            return TPMS_SIG_SCHEME_ECDAA_Unmarshal((TPMS_SIG_SCHEME_ECDAA *)&(target->ecdaa), buffer, size);
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
            return TPMS_SCHEME_HMAC_Unmarshal((TPMS_SCHEME_HMAC *)&(target->hmac), buffer, size);
#endif // TPM_ALG_HMAC
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

//     TPMU_SIG_SCHEME_Marshal not referenced


// Table 2:145 - Definition of TPMT_SIG_SCHEME Structure (StructureTable)
TPM_RC
TPMT_SIG_SCHEME_Unmarshal(
    TPMT_SIG_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_SIG_SCHEME_Unmarshal((TPMI_ALG_SIG_SCHEME *)&(target->scheme), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SIG_SCHEME_Unmarshal((TPMU_SIG_SCHEME *)&(target->details), buffer, size, (UINT32)target->scheme);
    return result;
}

//     TPMT_SIG_SCHEME_Marshal not referenced


// Table 2:146 - Definition of Types for Encryption Schemes (TypesTable)
#ifdef    TPM_ALG_RSA
//   TPMS_SCHEME_HASH definition from table 2:146
#ifdef    TPM_ALG_RSA
//   TPMS_ENC_SCHEME_OAEP_Unmarshal changed to #define
//   TPMS_ENC_SCHEME_OAEP_Marshal changed to #define
#endif // TPM_ALG_RSA
//   TPMS_EMPTY definition from table 2:146
#ifdef    TPM_ALG_RSA
//   TPMS_ENC_SCHEME_RSAES_Unmarshal changed to #define
//   TPMS_ENC_SCHEME_RSAES_Marshal changed to #define
#endif // TPM_ALG_RSA
#endif // TPM_ALG_RSA


// Table 2:147 - Definition of Types for ECC Key Exchange (TypesTable)
#ifdef    TPM_ALG_ECC
//   TPMS_SCHEME_HASH definition from table 2:147
#ifdef    TPM_ALG_ECC
//   TPMS_KEY_SCHEME_ECDH_Unmarshal changed to #define
//   TPMS_KEY_SCHEME_ECDH_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SCHEME_HASH definition from table 2:147
#ifdef    TPM_ALG_ECC
//   TPMS_KEY_SCHEME_ECMQV_Unmarshal changed to #define
//   TPMS_KEY_SCHEME_ECMQV_Marshal changed to #define
#endif // TPM_ALG_ECC
#endif // TPM_ALG_ECC


// Table 2:148 - Definition of Types for KDF Schemes (TypesTable)
//   TPMS_SCHEME_HASH definition from table 2:148
//   TPMS_SCHEME_MGF1_Unmarshal changed to #define
//   TPMS_SCHEME_MGF1_Marshal changed to #define
//   TPMS_SCHEME_HASH definition from table 2:148
//   TPMS_SCHEME_KDF1_SP800_56A_Unmarshal changed to #define
//   TPMS_SCHEME_KDF1_SP800_56A_Marshal changed to #define
//   TPMS_SCHEME_HASH definition from table 2:148
//   TPMS_SCHEME_KDF2_Unmarshal changed to #define
//   TPMS_SCHEME_KDF2_Marshal changed to #define
//   TPMS_SCHEME_HASH definition from table 2:148
//   TPMS_SCHEME_KDF1_SP800_108_Unmarshal changed to #define
//   TPMS_SCHEME_KDF1_SP800_108_Marshal changed to #define


// Table 2:149 - Definition of TPMU_KDF_SCHEME Union  (UnionTable)
TPM_RC
TPMU_KDF_SCHEME_Unmarshal(
    TPMU_KDF_SCHEME *target, BYTE **buffer, INT32 *size, UINT32      selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_MGF1
        case TPM_ALG_MGF1:
            return TPMS_SCHEME_MGF1_Unmarshal((TPMS_SCHEME_MGF1 *)&(target->mgf1), buffer, size);
#endif // TPM_ALG_MGF1
#ifdef    TPM_ALG_KDF1_SP800_56A
        case TPM_ALG_KDF1_SP800_56A:
            return TPMS_SCHEME_KDF1_SP800_56A_Unmarshal((TPMS_SCHEME_KDF1_SP800_56A *)&(target->kdf1_sp800_56a), buffer, size);
#endif // TPM_ALG_KDF1_SP800_56A
#ifdef    TPM_ALG_KDF2
        case TPM_ALG_KDF2:
            return TPMS_SCHEME_KDF2_Unmarshal((TPMS_SCHEME_KDF2 *)&(target->kdf2), buffer, size);
#endif // TPM_ALG_KDF2
#ifdef    TPM_ALG_KDF1_SP800_108
        case TPM_ALG_KDF1_SP800_108:
            return TPMS_SCHEME_KDF1_SP800_108_Unmarshal((TPMS_SCHEME_KDF1_SP800_108 *)&(target->kdf1_sp800_108), buffer, size);
#endif // TPM_ALG_KDF1_SP800_108
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_KDF_SCHEME_Marshal(
    TPMU_KDF_SCHEME *source, BYTE **buffer, INT32 *size, UINT32      selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_MGF1
        case TPM_ALG_MGF1:
            return TPMS_SCHEME_MGF1_Marshal((TPMS_SCHEME_MGF1 *)&(source->mgf1), buffer, size);
#endif // TPM_ALG_MGF1
#ifdef    TPM_ALG_KDF1_SP800_56A
        case TPM_ALG_KDF1_SP800_56A:
            return TPMS_SCHEME_KDF1_SP800_56A_Marshal((TPMS_SCHEME_KDF1_SP800_56A *)&(source->kdf1_sp800_56a), buffer, size);
#endif // TPM_ALG_KDF1_SP800_56A
#ifdef    TPM_ALG_KDF2
        case TPM_ALG_KDF2:
            return TPMS_SCHEME_KDF2_Marshal((TPMS_SCHEME_KDF2 *)&(source->kdf2), buffer, size);
#endif // TPM_ALG_KDF2
#ifdef    TPM_ALG_KDF1_SP800_108
        case TPM_ALG_KDF1_SP800_108:
            return TPMS_SCHEME_KDF1_SP800_108_Marshal((TPMS_SCHEME_KDF1_SP800_108 *)&(source->kdf1_sp800_108), buffer, size);
#endif // TPM_ALG_KDF1_SP800_108
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:150 - Definition of TPMT_KDF_SCHEME Structure (StructureTable)
TPM_RC
TPMT_KDF_SCHEME_Unmarshal(
    TPMT_KDF_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_KDF_Unmarshal((TPMI_ALG_KDF *)&(target->scheme), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_KDF_SCHEME_Unmarshal((TPMU_KDF_SCHEME *)&(target->details), buffer, size, (UINT32)target->scheme);
    return result;
}

UINT16
TPMT_KDF_SCHEME_Marshal(
    TPMT_KDF_SCHEME *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_KDF_Marshal((TPMI_ALG_KDF *)&(source->scheme), buffer, size));
    result = (UINT16)(result + TPMU_KDF_SCHEME_Marshal((TPMU_KDF_SCHEME *)&(source->details), buffer, size, (UINT32)source->scheme));
    return result;
}


// Table 2:151 - Definition of TPMI_ALG_ASYM_SCHEME Type  (TypeTable)
//     TPMI_ALG_ASYM_SCHEME_Unmarshal not referenced
//     TPMI_ALG_ASYM_SCHEME_Marshal not referenced


// Table 2:152 - Definition of TPMU_ASYM_SCHEME Union (UnionTable)
TPM_RC
TPMU_ASYM_SCHEME_Unmarshal(
    TPMU_ASYM_SCHEME *target, BYTE **buffer, INT32 *size, UINT32     selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_ECDH
        case TPM_ALG_ECDH:
            return TPMS_KEY_SCHEME_ECDH_Unmarshal((TPMS_KEY_SCHEME_ECDH *)&(target->ecdh), buffer, size);
#endif // TPM_ALG_ECDH
#ifdef    TPM_ALG_ECMQV
        case TPM_ALG_ECMQV:
            return TPMS_KEY_SCHEME_ECMQV_Unmarshal((TPMS_KEY_SCHEME_ECMQV *)&(target->ecmqv), buffer, size);
#endif // TPM_ALG_ECMQV
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
            return TPMS_SIG_SCHEME_RSASSA_Unmarshal((TPMS_SIG_SCHEME_RSASSA *)&(target->rsassa), buffer, size);
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
            return TPMS_SIG_SCHEME_RSAPSS_Unmarshal((TPMS_SIG_SCHEME_RSAPSS *)&(target->rsapss), buffer, size);
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
            return TPMS_SIG_SCHEME_ECDSA_Unmarshal((TPMS_SIG_SCHEME_ECDSA *)&(target->ecdsa), buffer, size);
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
            return TPMS_SIG_SCHEME_SM2_Unmarshal((TPMS_SIG_SCHEME_SM2 *)&(target->sm2), buffer, size);
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
            return TPMS_SIG_SCHEME_ECSCHNORR_Unmarshal((TPMS_SIG_SCHEME_ECSCHNORR *)&(target->ecschnorr), buffer, size);
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
            return TPMS_SIG_SCHEME_ECDAA_Unmarshal((TPMS_SIG_SCHEME_ECDAA *)&(target->ecdaa), buffer, size);
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_OAEP
        case TPM_ALG_OAEP:
            return TPMS_ENC_SCHEME_OAEP_Unmarshal((TPMS_ENC_SCHEME_OAEP *)&(target->oaep), buffer, size);
#endif // TPM_ALG_OAEP
#ifdef    TPM_ALG_RSAES
        case TPM_ALG_RSAES:
            return TPMS_ENC_SCHEME_RSAES_Unmarshal((TPMS_ENC_SCHEME_RSAES *)&(target->rsaes), buffer, size);
#endif // TPM_ALG_RSAES
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_ASYM_SCHEME_Marshal(
    TPMU_ASYM_SCHEME *source, BYTE **buffer, INT32 *size, UINT32     selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_ECDH
        case TPM_ALG_ECDH:
            return TPMS_KEY_SCHEME_ECDH_Marshal((TPMS_KEY_SCHEME_ECDH *)&(source->ecdh), buffer, size);
#endif // TPM_ALG_ECDH
#ifdef    TPM_ALG_ECMQV
        case TPM_ALG_ECMQV:
            return TPMS_KEY_SCHEME_ECMQV_Marshal((TPMS_KEY_SCHEME_ECMQV *)&(source->ecmqv), buffer, size);
#endif // TPM_ALG_ECMQV
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
            return TPMS_SIG_SCHEME_RSASSA_Marshal((TPMS_SIG_SCHEME_RSASSA *)&(source->rsassa), buffer, size);
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
            return TPMS_SIG_SCHEME_RSAPSS_Marshal((TPMS_SIG_SCHEME_RSAPSS *)&(source->rsapss), buffer, size);
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
            return TPMS_SIG_SCHEME_ECDSA_Marshal((TPMS_SIG_SCHEME_ECDSA *)&(source->ecdsa), buffer, size);
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
            return TPMS_SIG_SCHEME_SM2_Marshal((TPMS_SIG_SCHEME_SM2 *)&(source->sm2), buffer, size);
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
            return TPMS_SIG_SCHEME_ECSCHNORR_Marshal((TPMS_SIG_SCHEME_ECSCHNORR *)&(source->ecschnorr), buffer, size);
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
            return TPMS_SIG_SCHEME_ECDAA_Marshal((TPMS_SIG_SCHEME_ECDAA *)&(source->ecdaa), buffer, size);
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_OAEP
        case TPM_ALG_OAEP:
            return TPMS_ENC_SCHEME_OAEP_Marshal((TPMS_ENC_SCHEME_OAEP *)&(source->oaep), buffer, size);
#endif // TPM_ALG_OAEP
#ifdef    TPM_ALG_RSAES
        case TPM_ALG_RSAES:
            return TPMS_ENC_SCHEME_RSAES_Marshal((TPMS_ENC_SCHEME_RSAES *)&(source->rsaes), buffer, size);
#endif // TPM_ALG_RSAES
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:153 - Definition of TPMT_ASYM_SCHEME Structure  (StructureTable)
//     TPMT_ASYM_SCHEME_Unmarshal not referenced
//     TPMT_ASYM_SCHEME_Marshal not referenced


// Table 2:154 - Definition of TPMI_ALG_RSA_SCHEME Type (TypeTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMI_ALG_RSA_SCHEME_Unmarshal(
    TPMI_ALG_RSA_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_OAEP
        case TPM_ALG_OAEP:
#endif // TPM_ALG_OAEP
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_RSAES
        case TPM_ALG_RSAES:
#endif // TPM_ALG_RSAES
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_VALUE;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_RSA_SCHEME_Marshal changed to #define
#endif // TPM_ALG_RSA


// Table 2:155 - Definition of TPMT_RSA_SCHEME Structure (StructureTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMT_RSA_SCHEME_Unmarshal(
    TPMT_RSA_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_RSA_SCHEME_Unmarshal((TPMI_ALG_RSA_SCHEME *)&(target->scheme), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_ASYM_SCHEME_Unmarshal((TPMU_ASYM_SCHEME *)&(target->details), buffer, size, (UINT32)target->scheme);
    return result;
}

UINT16
TPMT_RSA_SCHEME_Marshal(
    TPMT_RSA_SCHEME *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_RSA_SCHEME_Marshal((TPMI_ALG_RSA_SCHEME *)&(source->scheme), buffer, size));
    result = (UINT16)(result + TPMU_ASYM_SCHEME_Marshal((TPMU_ASYM_SCHEME *)&(source->details), buffer, size, (UINT32)source->scheme));
    return result;
}

#endif // TPM_ALG_RSA


// Table 2:156 - Definition of TPMI_ALG_RSA_DECRYPT Type (TypeTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMI_ALG_RSA_DECRYPT_Unmarshal(
    TPMI_ALG_RSA_DECRYPT *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_OAEP
        case TPM_ALG_OAEP:
#endif // TPM_ALG_OAEP
#ifdef    TPM_ALG_RSAES
        case TPM_ALG_RSAES:
#endif // TPM_ALG_RSAES
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_VALUE;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//     TPMI_ALG_RSA_DECRYPT_Marshal not referenced
#endif // TPM_ALG_RSA


// Table 2:157 - Definition of TPMT_RSA_DECRYPT Structure (StructureTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMT_RSA_DECRYPT_Unmarshal(
    TPMT_RSA_DECRYPT *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_RSA_DECRYPT_Unmarshal((TPMI_ALG_RSA_DECRYPT *)&(target->scheme), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_ASYM_SCHEME_Unmarshal((TPMU_ASYM_SCHEME *)&(target->details), buffer, size, (UINT32)target->scheme);
    return result;
}

//     TPMT_RSA_DECRYPT_Marshal not referenced
#endif // TPM_ALG_RSA


// Table 2:158 - Definition of TPM2B_PUBLIC_KEY_RSA Structure (StructureTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPM2B_PUBLIC_KEY_RSA_Unmarshal(
    TPM2B_PUBLIC_KEY_RSA *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_RSA_KEY_BYTES)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_PUBLIC_KEY_RSA_Marshal(
    TPM2B_PUBLIC_KEY_RSA *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}

#endif // TPM_ALG_RSA


// Table 2:159 - Definition of TPMI_RSA_KEY_BITS Type (TypeTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMI_RSA_KEY_BITS_Unmarshal(
    TPMI_RSA_KEY_BITS *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPM_KEY_BITS_Unmarshal((TPM_KEY_BITS *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case 1024:
        case 2048:
            break;
        default:
            return TPM_RC_VALUE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_RSA_KEY_BITS_Marshal changed to #define
#endif // TPM_ALG_RSA


// Table 2:160 - Definition of TPM2B_PRIVATE_KEY_RSA Structure (StructureTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPM2B_PRIVATE_KEY_RSA_Unmarshal(
    TPM2B_PRIVATE_KEY_RSA *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_RSA_KEY_BYTES/2)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_PRIVATE_KEY_RSA_Marshal(
    TPM2B_PRIVATE_KEY_RSA *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}

#endif // TPM_ALG_RSA


// Table 2:161 - Definition of TPM2B_ECC_PARAMETER Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPM2B_ECC_PARAMETER_Unmarshal(
    TPM2B_ECC_PARAMETER *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > MAX_ECC_KEY_BYTES)
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_ECC_PARAMETER_Marshal(
    TPM2B_ECC_PARAMETER *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:162 - Definition of TPMS_ECC_POINT Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMS_ECC_POINT_Unmarshal(
    TPMS_ECC_POINT *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPM2B_ECC_PARAMETER_Unmarshal((TPM2B_ECC_PARAMETER *)&(target->x), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_ECC_PARAMETER_Unmarshal((TPM2B_ECC_PARAMETER *)&(target->y), buffer, size);
    return result;
}

UINT16
TPMS_ECC_POINT_Marshal(
    TPMS_ECC_POINT *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->x), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->y), buffer, size));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:163 - Definition of TPM2B_ECC_POINT Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPM2B_ECC_POINT_Unmarshal(
    TPM2B_ECC_POINT *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    INT32    startSize;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size is zero, then the required structure is missing
    if(target->t.size == 0)
        return TPM_RC_SIZE;
    startSize = *size;
    result = TPMS_ECC_POINT_Unmarshal((TPMS_ECC_POINT *)&(target->t.point), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(target->t.size != (startSize - *size)) return TPM_RC_SIZE;
    return TPM_RC_SUCCESS;
}

UINT16
TPM2B_ECC_POINT_Marshal(
    TPM2B_ECC_POINT *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    BYTE      *sizeField = *buffer;
    // Advance buffer pointer by cononical size of a UINT16
    *buffer += 2;
    // Marshal the structure
    result = (UINT16)(result + TPMS_ECC_POINT_Marshal((TPMS_ECC_POINT *)&(source->t.point), buffer, size));
    // Marshal the size
    result = (UINT16)(result + UINT16_Marshal(&result, &sizeField, size));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:164 - Definition of TPMI_ALG_ECC_SCHEME Type (TypeTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMI_ALG_ECC_SCHEME_Unmarshal(
    TPMI_ALG_ECC_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_ECDH
        case TPM_ALG_ECDH:
#endif // TPM_ALG_ECDH
#ifdef    TPM_ALG_ECMQV
        case TPM_ALG_ECMQV:
#endif // TPM_ALG_ECMQV
            break;
        case TPM_ALG_NULL:
        if (flag)
            break;
        return TPM_RC_SCHEME;
        default:
            return TPM_RC_SCHEME;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_ECC_SCHEME_Marshal changed to #define
#endif // TPM_ALG_ECC


// Table 2:165 - Definition of TPMI_ECC_CURVE Type (TypeTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMI_ECC_CURVE_Unmarshal(
    TPMI_ECC_CURVE *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPM_ECC_CURVE_Unmarshal((TPM_ECC_CURVE *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
        case TPM_ECC_BN_P256:
        case TPM_ECC_NIST_P256:
#if defined ME11_SIM
#elif defined INTEL_SMX
		case TPM_ECC_SM2_P256:
#else
        case TPM_ECC_NIST_P384:
#endif
            break;
        default:
            return TPM_RC_CURVE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ECC_CURVE_Marshal changed to #define
#endif // TPM_ALG_ECC


// Table 2:166 - Definition of TPMT_ECC_SCHEME Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMT_ECC_SCHEME_Unmarshal(
    TPMT_ECC_SCHEME *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_ECC_SCHEME_Unmarshal((TPMI_ALG_ECC_SCHEME *)&(target->scheme), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_ASYM_SCHEME_Unmarshal((TPMU_ASYM_SCHEME *)&(target->details), buffer, size, (UINT32)target->scheme);
    return result;
}

UINT16
TPMT_ECC_SCHEME_Marshal(
    TPMT_ECC_SCHEME *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_ECC_SCHEME_Marshal((TPMI_ALG_ECC_SCHEME *)&(source->scheme), buffer, size));
    result = (UINT16)(result + TPMU_ASYM_SCHEME_Marshal((TPMU_ASYM_SCHEME *)&(source->details), buffer, size, (UINT32)source->scheme));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:167 - Definition of TPMS_ALGORITHM_DETAIL_ECC Structure  (StructureTable)
#ifdef    TPM_ALG_ECC
//     TPMS_ALGORITHM_DETAIL_ECC_Unmarshal not referenced
UINT16
TPMS_ALGORITHM_DETAIL_ECC_Marshal(
    TPMS_ALGORITHM_DETAIL_ECC *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPM_ECC_CURVE_Marshal((TPM_ECC_CURVE *)&(source->curveID), buffer, size));
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->keySize), buffer, size));
    result = (UINT16)(result + TPMT_KDF_SCHEME_Marshal((TPMT_KDF_SCHEME *)&(source->kdf), buffer, size));
    result = (UINT16)(result + TPMT_ECC_SCHEME_Marshal((TPMT_ECC_SCHEME *)&(source->sign), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->p), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->a), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->b), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->gX), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->gY), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->n), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->h), buffer, size));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:168 - Definition of TPMS_SIGNATURE_RSA Structure (StructureTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMS_SIGNATURE_RSA_Unmarshal(
    TPMS_SIGNATURE_RSA *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->hash), buffer, size, 0);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_PUBLIC_KEY_RSA_Unmarshal((TPM2B_PUBLIC_KEY_RSA *)&(target->sig), buffer, size);
    return result;
}

UINT16
TPMS_SIGNATURE_RSA_Marshal(
    TPMS_SIGNATURE_RSA *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->hash), buffer, size));
    result = (UINT16)(result + TPM2B_PUBLIC_KEY_RSA_Marshal((TPM2B_PUBLIC_KEY_RSA *)&(source->sig), buffer, size));
    return result;
}

#endif // TPM_ALG_RSA


// Table 2:169 - Definition of Types for Signature  (TypesTable)
#ifdef    TPM_ALG_RSA
//   TPMS_SIGNATURE_RSA definition from table 2:169
#ifdef    TPM_ALG_RSA
//   TPMS_SIGNATURE_RSASSA_Unmarshal changed to #define
//   TPMS_SIGNATURE_RSASSA_Marshal changed to #define
#endif // TPM_ALG_RSA
//   TPMS_SIGNATURE_RSA definition from table 2:169
#ifdef    TPM_ALG_RSA
//   TPMS_SIGNATURE_RSAPSS_Unmarshal changed to #define
//   TPMS_SIGNATURE_RSAPSS_Marshal changed to #define
#endif // TPM_ALG_RSA
#endif // TPM_ALG_RSA


// Table 2:170 - Definition of TPMS_SIGNATURE_ECC Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMS_SIGNATURE_ECC_Unmarshal(
    TPMS_SIGNATURE_ECC *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->hash), buffer, size, 0);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_ECC_PARAMETER_Unmarshal((TPM2B_ECC_PARAMETER *)&(target->signatureR), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_ECC_PARAMETER_Unmarshal((TPM2B_ECC_PARAMETER *)&(target->signatureS), buffer, size);
    return result;
}

UINT16
TPMS_SIGNATURE_ECC_Marshal(
    TPMS_SIGNATURE_ECC *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->hash), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->signatureR), buffer, size));
    result = (UINT16)(result + TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->signatureS), buffer, size));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:171 - Definition of Types for TPMS_SIGNATUE_ECC (TypesTable)
#ifdef    TPM_ALG_ECC
//   TPMS_SIGNATURE_ECC definition from table 2:171
#ifdef    TPM_ALG_ECC
//   TPMS_SIGNATURE_ECDSA_Unmarshal changed to #define
//   TPMS_SIGNATURE_ECDSA_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SIGNATURE_ECC definition from table 2:171
#ifdef    TPM_ALG_ECC
//   TPMS_SIGNATURE_SM2_Unmarshal changed to #define
//   TPMS_SIGNATURE_SM2_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SIGNATURE_ECC definition from table 2:171
#ifdef    TPM_ALG_ECC
//   TPMS_SIGNATURE_ECSCHNORR_Unmarshal changed to #define
//   TPMS_SIGNATURE_ECSCHNORR_Marshal changed to #define
#endif // TPM_ALG_ECC
//   TPMS_SIGNATURE_ECC definition from table 2:171
#ifdef    TPM_ALG_ECC
//   TPMS_SIGNATURE_ECDAA_Unmarshal changed to #define
//   TPMS_SIGNATURE_ECDAA_Marshal changed to #define
#endif // TPM_ALG_ECC
#endif // TPM_ALG_ECC


// Table 2:172 - Definition of TPMU_SIGNATURE Union  (UnionTable)
TPM_RC
TPMU_SIGNATURE_Unmarshal(
    TPMU_SIGNATURE *target, BYTE **buffer, INT32 *size, UINT32   selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
            return TPMS_SIGNATURE_RSASSA_Unmarshal((TPMS_SIGNATURE_RSASSA *)&(target->rsassa), buffer, size);
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
            return TPMS_SIGNATURE_RSAPSS_Unmarshal((TPMS_SIGNATURE_RSAPSS *)&(target->rsapss), buffer, size);
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
            return TPMS_SIGNATURE_ECDSA_Unmarshal((TPMS_SIGNATURE_ECDSA *)&(target->ecdsa), buffer, size);
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
            return TPMS_SIGNATURE_SM2_Unmarshal((TPMS_SIGNATURE_SM2 *)&(target->sm2), buffer, size);
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
            return TPMS_SIGNATURE_ECSCHNORR_Unmarshal((TPMS_SIGNATURE_ECSCHNORR *)&(target->ecschnorr), buffer, size);
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
            return TPMS_SIGNATURE_ECDAA_Unmarshal((TPMS_SIGNATURE_ECDAA *)&(target->ecdaa), buffer, size);
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
            return TPMT_HA_Unmarshal((TPMT_HA *)&(target->hmac), buffer, size, 0);
#endif // TPM_ALG_HMAC
        case TPM_ALG_NULL:
            return TPM_RC_SUCCESS;
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_SIGNATURE_Marshal(
    TPMU_SIGNATURE *source, BYTE **buffer, INT32 *size, UINT32   selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_RSASSA
        case TPM_ALG_RSASSA:
            return TPMS_SIGNATURE_RSASSA_Marshal((TPMS_SIGNATURE_RSASSA *)&(source->rsassa), buffer, size);
#endif // TPM_ALG_RSASSA
#ifdef    TPM_ALG_RSAPSS
        case TPM_ALG_RSAPSS:
            return TPMS_SIGNATURE_RSAPSS_Marshal((TPMS_SIGNATURE_RSAPSS *)&(source->rsapss), buffer, size);
#endif // TPM_ALG_RSAPSS
#ifdef    TPM_ALG_ECDSA
        case TPM_ALG_ECDSA:
            return TPMS_SIGNATURE_ECDSA_Marshal((TPMS_SIGNATURE_ECDSA *)&(source->ecdsa), buffer, size);
#endif // TPM_ALG_ECDSA
#ifdef    TPM_ALG_SM2
        case TPM_ALG_SM2:
            return TPMS_SIGNATURE_SM2_Marshal((TPMS_SIGNATURE_SM2 *)&(source->sm2), buffer, size);
#endif // TPM_ALG_SM2
#ifdef    TPM_ALG_ECSCHNORR
        case TPM_ALG_ECSCHNORR:
            return TPMS_SIGNATURE_ECSCHNORR_Marshal((TPMS_SIGNATURE_ECSCHNORR *)&(source->ecschnorr), buffer, size);
#endif // TPM_ALG_ECSCHNORR
#ifdef    TPM_ALG_ECDAA
        case TPM_ALG_ECDAA:
            return TPMS_SIGNATURE_ECDAA_Marshal((TPMS_SIGNATURE_ECDAA *)&(source->ecdaa), buffer, size);
#endif // TPM_ALG_ECDAA
#ifdef    TPM_ALG_HMAC
        case TPM_ALG_HMAC:
            return TPMT_HA_Marshal((TPMT_HA *)&(source->hmac), buffer, size);
#endif // TPM_ALG_HMAC
        case TPM_ALG_NULL:
            return 0;
    }
    return 0;
}


// Table 2:173 - Definition of TPMT_SIGNATURE Structure (StructureTable)
TPM_RC
TPMT_SIGNATURE_Unmarshal(
    TPMT_SIGNATURE *target, BYTE **buffer, INT32 *size, BOOL     flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_SIG_SCHEME_Unmarshal((TPMI_ALG_SIG_SCHEME *)&(target->sigAlg), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SIGNATURE_Unmarshal((TPMU_SIGNATURE *)&(target->signature), buffer, size, (UINT32)target->sigAlg);
    return result;
}

UINT16
TPMT_SIGNATURE_Marshal(
    TPMT_SIGNATURE *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_SIG_SCHEME_Marshal((TPMI_ALG_SIG_SCHEME *)&(source->sigAlg), buffer, size));
    result = (UINT16)(result + TPMU_SIGNATURE_Marshal((TPMU_SIGNATURE *)&(source->signature), buffer, size, (UINT32)source->sigAlg));
    return result;
}


// Table 2:174 - Definition of TPMU_ENCRYPTED_SECRET Union  (UnionTable)
//     TPMU_ENCRYPTED_SECRET_Unmarshal not referenced
//     TPMU_ENCRYPTED_SECRET_Marshal not referenced


// Table 2:175 - Definition of TPM2B_ENCRYPTED_SECRET Structure (StructureTable)
TPM_RC
TPM2B_ENCRYPTED_SECRET_Unmarshal(
    TPM2B_ENCRYPTED_SECRET *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(TPMU_ENCRYPTED_SECRET))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.secret), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_ENCRYPTED_SECRET_Marshal(
    TPM2B_ENCRYPTED_SECRET *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.secret), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:176 - Definition of TPMI_ALG_PUBLIC Type (TypeTable)
TPM_RC
TPMI_ALG_PUBLIC_Unmarshal(
    TPMI_ALG_PUBLIC *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = TPM_ALG_ID_Unmarshal((TPM_ALG_ID *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    switch (*target) {
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
#endif // TPM_ALG_SYMCIPHER
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
#endif // TPM_ALG_ECC
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
#endif // TPM_ALG_KEYEDHASH
            break;
        default:
            return TPM_RC_TYPE;
    }
    return TPM_RC_SUCCESS;
}

//   TPMI_ALG_PUBLIC_Marshal changed to #define


// Table 2:177 - Definition of TPMU_PUBLIC_ID Union  (UnionTable)
TPM_RC
TPMU_PUBLIC_ID_Unmarshal(
    TPMU_PUBLIC_ID *target, BYTE **buffer, INT32 *size, UINT32   selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
            return TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->keyedHash), buffer, size);
#endif // TPM_ALG_KEYEDHASH
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
            return TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->sym), buffer, size);
#endif // TPM_ALG_SYMCIPHER
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
            return TPM2B_PUBLIC_KEY_RSA_Unmarshal((TPM2B_PUBLIC_KEY_RSA *)&(target->rsa), buffer, size);
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
            return TPMS_ECC_POINT_Unmarshal((TPMS_ECC_POINT *)&(target->ecc), buffer, size);
#endif // TPM_ALG_ECC
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_PUBLIC_ID_Marshal(
    TPMU_PUBLIC_ID *source, BYTE **buffer, INT32 *size, UINT32   selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
            return TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->keyedHash), buffer, size);
#endif // TPM_ALG_KEYEDHASH
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
            return TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->sym), buffer, size);
#endif // TPM_ALG_SYMCIPHER
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
            return TPM2B_PUBLIC_KEY_RSA_Marshal((TPM2B_PUBLIC_KEY_RSA *)&(source->rsa), buffer, size);
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
            return TPMS_ECC_POINT_Marshal((TPMS_ECC_POINT *)&(source->ecc), buffer, size);
#endif // TPM_ALG_ECC
    }
    return 0;
}


// Table 2:178 - Definition of TPMS_KEYEDHASH_PARMS Structure (StructureTable)
//   TPMS_KEYEDHASH_PARMS_Unmarshal changed to #define
//   TPMS_KEYEDHASH_PARMS_Marshal changed to #define


// Table 2:179 - Definition of TPMS_ASYM_PARMS Structure  (StructureTable)
//     TPMS_ASYM_PARMS_Unmarshal not referenced
//     TPMS_ASYM_PARMS_Marshal not referenced


// Table 2:180 - Definition of TPMS_RSA_PARMS Structure (StructureTable)
#ifdef    TPM_ALG_RSA
TPM_RC
TPMS_RSA_PARMS_Unmarshal(
    TPMS_RSA_PARMS *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMT_SYM_DEF_OBJECT_Unmarshal((TPMT_SYM_DEF_OBJECT *)&(target->symmetric), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMT_RSA_SCHEME_Unmarshal((TPMT_RSA_SCHEME *)&(target->scheme), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_RSA_KEY_BITS_Unmarshal((TPMI_RSA_KEY_BITS *)&(target->keyBits), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = UINT32_Unmarshal((UINT32 *)&(target->exponent), buffer, size);
    return result;
}

UINT16
TPMS_RSA_PARMS_Marshal(
    TPMS_RSA_PARMS *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMT_SYM_DEF_OBJECT_Marshal((TPMT_SYM_DEF_OBJECT *)&(source->symmetric), buffer, size));
    result = (UINT16)(result + TPMT_RSA_SCHEME_Marshal((TPMT_RSA_SCHEME *)&(source->scheme), buffer, size));
    result = (UINT16)(result + TPMI_RSA_KEY_BITS_Marshal((TPMI_RSA_KEY_BITS *)&(source->keyBits), buffer, size));
    result = (UINT16)(result + UINT32_Marshal((UINT32 *)&(source->exponent), buffer, size));
    return result;
}

#endif // TPM_ALG_RSA


// Table 2:181 - Definition of TPMS_ECC_PARMS Structure (StructureTable)
#ifdef    TPM_ALG_ECC
TPM_RC
TPMS_ECC_PARMS_Unmarshal(
    TPMS_ECC_PARMS *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMT_SYM_DEF_OBJECT_Unmarshal((TPMT_SYM_DEF_OBJECT *)&(target->symmetric), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMT_ECC_SCHEME_Unmarshal((TPMT_ECC_SCHEME *)&(target->scheme), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_ECC_CURVE_Unmarshal((TPMI_ECC_CURVE *)&(target->curveID), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMT_KDF_SCHEME_Unmarshal((TPMT_KDF_SCHEME *)&(target->kdf), buffer, size, 1);
    return result;
}

UINT16
TPMS_ECC_PARMS_Marshal(
    TPMS_ECC_PARMS *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMT_SYM_DEF_OBJECT_Marshal((TPMT_SYM_DEF_OBJECT *)&(source->symmetric), buffer, size));
    result = (UINT16)(result + TPMT_ECC_SCHEME_Marshal((TPMT_ECC_SCHEME *)&(source->scheme), buffer, size));
    result = (UINT16)(result + TPMI_ECC_CURVE_Marshal((TPMI_ECC_CURVE *)&(source->curveID), buffer, size));
    result = (UINT16)(result + TPMT_KDF_SCHEME_Marshal((TPMT_KDF_SCHEME *)&(source->kdf), buffer, size));
    return result;
}

#endif // TPM_ALG_ECC


// Table 2:182 - Definition of TPMU_PUBLIC_PARMS Union  (UnionTable)
TPM_RC
TPMU_PUBLIC_PARMS_Unmarshal(
    TPMU_PUBLIC_PARMS *target, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
            return TPMS_KEYEDHASH_PARMS_Unmarshal((TPMS_KEYEDHASH_PARMS *)&(target->keyedHashDetail), buffer, size);
#endif // TPM_ALG_KEYEDHASH
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
            return TPMS_SYMCIPHER_PARMS_Unmarshal((TPMS_SYMCIPHER_PARMS *)&(target->symDetail), buffer, size);
#endif // TPM_ALG_SYMCIPHER
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
            return TPMS_RSA_PARMS_Unmarshal((TPMS_RSA_PARMS *)&(target->rsaDetail), buffer, size);
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
            return TPMS_ECC_PARMS_Unmarshal((TPMS_ECC_PARMS *)&(target->eccDetail), buffer, size);
#endif // TPM_ALG_ECC
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_PUBLIC_PARMS_Marshal(
    TPMU_PUBLIC_PARMS *source, BYTE **buffer, INT32 *size, UINT32    selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
            return TPMS_KEYEDHASH_PARMS_Marshal((TPMS_KEYEDHASH_PARMS *)&(source->keyedHashDetail), buffer, size);
#endif // TPM_ALG_KEYEDHASH
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
            return TPMS_SYMCIPHER_PARMS_Marshal((TPMS_SYMCIPHER_PARMS *)&(source->symDetail), buffer, size);
#endif // TPM_ALG_SYMCIPHER
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
            return TPMS_RSA_PARMS_Marshal((TPMS_RSA_PARMS *)&(source->rsaDetail), buffer, size);
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
            return TPMS_ECC_PARMS_Marshal((TPMS_ECC_PARMS *)&(source->eccDetail), buffer, size);
#endif // TPM_ALG_ECC
    }
    return 0;
}


// Table 2:183 - Definition of TPMT_PUBLIC_PARMS Structure (StructureTable)
TPM_RC
TPMT_PUBLIC_PARMS_Unmarshal(
    TPMT_PUBLIC_PARMS *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = TPMI_ALG_PUBLIC_Unmarshal((TPMI_ALG_PUBLIC *)&(target->type), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_PUBLIC_PARMS_Unmarshal((TPMU_PUBLIC_PARMS *)&(target->parameters), buffer, size, (UINT32)target->type);
    return result;
}

//     TPMT_PUBLIC_PARMS_Marshal not referenced


// Table 2:184 - Definition of TPMT_PUBLIC Structure (StructureTable)
TPM_RC
TPMT_PUBLIC_Unmarshal(
    TPMT_PUBLIC *target, BYTE **buffer, INT32 *size, BOOL    flag
    )
{
    TPM_RC    result;
    result = TPMI_ALG_PUBLIC_Unmarshal((TPMI_ALG_PUBLIC *)&(target->type), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->nameAlg), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMA_OBJECT_Unmarshal((TPMA_OBJECT *)&(target->objectAttributes), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->authPolicy), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_PUBLIC_PARMS_Unmarshal((TPMU_PUBLIC_PARMS *)&(target->parameters), buffer, size, (UINT32)target->type);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_PUBLIC_ID_Unmarshal((TPMU_PUBLIC_ID *)&(target->unique), buffer, size, (UINT32)target->type);
    return result;
}

UINT16
TPMT_PUBLIC_Marshal(
    TPMT_PUBLIC *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_PUBLIC_Marshal((TPMI_ALG_PUBLIC *)&(source->type), buffer, size));
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->nameAlg), buffer, size));
    result = (UINT16)(result + TPMA_OBJECT_Marshal((TPMA_OBJECT *)&(source->objectAttributes), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->authPolicy), buffer, size));
    result = (UINT16)(result + TPMU_PUBLIC_PARMS_Marshal((TPMU_PUBLIC_PARMS *)&(source->parameters), buffer, size, (UINT32)source->type));
    result = (UINT16)(result + TPMU_PUBLIC_ID_Marshal((TPMU_PUBLIC_ID *)&(source->unique), buffer, size, (UINT32)source->type));
    return result;
}


// Table 2:185 - Definition of TPM2B_PUBLIC Structure (StructureTable)
TPM_RC
TPM2B_PUBLIC_Unmarshal(
    TPM2B_PUBLIC *target, BYTE **buffer, INT32 *size, BOOL   flag
    )
{
    TPM_RC    result;
    INT32    startSize;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size is zero, then the required structure is missing
    if(target->t.size == 0)
        return TPM_RC_SIZE;
    startSize = *size;
    result = TPMT_PUBLIC_Unmarshal((TPMT_PUBLIC *)&(target->t.publicArea), buffer, size, flag);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(target->t.size != (startSize - *size)) return TPM_RC_SIZE;
    return TPM_RC_SUCCESS;
}

UINT16
TPM2B_PUBLIC_Marshal(
    TPM2B_PUBLIC *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    BYTE      *sizeField = *buffer;
    // Advance buffer pointer by cononical size of a UINT16
    *buffer += 2;
    // Marshal the structure
    result = (UINT16)(result + TPMT_PUBLIC_Marshal((TPMT_PUBLIC *)&(source->t.publicArea), buffer, size));
    // Marshal the size
    result = (UINT16)(result + UINT16_Marshal(&result, &sizeField, size));
    return result;
}


// Table 2:186 - Definition of TPM2B_PRIVATE_VENDOR_SPECIFIC Structure (StructureTable)
//     TPM2B_PRIVATE_VENDOR_SPECIFIC_Unmarshal not referenced
//     TPM2B_PRIVATE_VENDOR_SPECIFIC_Marshal not referenced


// Table 2:187 - Definition of TPMU_SENSITIVE_COMPOSITE Union  (UnionTable)
TPM_RC
TPMU_SENSITIVE_COMPOSITE_Unmarshal(
    TPMU_SENSITIVE_COMPOSITE *target, BYTE **buffer, INT32 *size, UINT32     selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
            return TPM2B_PRIVATE_KEY_RSA_Unmarshal((TPM2B_PRIVATE_KEY_RSA *)&(target->rsa), buffer, size);
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
            return TPM2B_ECC_PARAMETER_Unmarshal((TPM2B_ECC_PARAMETER *)&(target->ecc), buffer, size);
#endif // TPM_ALG_ECC
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
            return TPM2B_SENSITIVE_DATA_Unmarshal((TPM2B_SENSITIVE_DATA *)&(target->bits), buffer, size);
#endif // TPM_ALG_KEYEDHASH
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
            return TPM2B_SYM_KEY_Unmarshal((TPM2B_SYM_KEY *)&(target->sym), buffer, size);
#endif // TPM_ALG_SYMCIPHER
    }
    return TPM_RC_SELECTOR;
}

UINT16
TPMU_SENSITIVE_COMPOSITE_Marshal(
    TPMU_SENSITIVE_COMPOSITE *source, BYTE **buffer, INT32 *size, UINT32     selector
    )
{
    switch(selector) {
#ifdef    TPM_ALG_RSA
        case TPM_ALG_RSA:
            return TPM2B_PRIVATE_KEY_RSA_Marshal((TPM2B_PRIVATE_KEY_RSA *)&(source->rsa), buffer, size);
#endif // TPM_ALG_RSA
#ifdef    TPM_ALG_ECC
        case TPM_ALG_ECC:
            return TPM2B_ECC_PARAMETER_Marshal((TPM2B_ECC_PARAMETER *)&(source->ecc), buffer, size);
#endif // TPM_ALG_ECC
#ifdef    TPM_ALG_KEYEDHASH
        case TPM_ALG_KEYEDHASH:
            return TPM2B_SENSITIVE_DATA_Marshal((TPM2B_SENSITIVE_DATA *)&(source->bits), buffer, size);
#endif // TPM_ALG_KEYEDHASH
#ifdef    TPM_ALG_SYMCIPHER
        case TPM_ALG_SYMCIPHER:
            return TPM2B_SYM_KEY_Marshal((TPM2B_SYM_KEY *)&(source->sym), buffer, size);
#endif // TPM_ALG_SYMCIPHER
    }
    return 0;
}


// Table 2:188 - Definition of TPMT_SENSITIVE Structure (StructureTable)
TPM_RC
TPMT_SENSITIVE_Unmarshal(
    TPMT_SENSITIVE *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMI_ALG_PUBLIC_Unmarshal((TPMI_ALG_PUBLIC *)&(target->sensitiveType), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_AUTH_Unmarshal((TPM2B_AUTH *)&(target->authValue), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->seedValue), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMU_SENSITIVE_COMPOSITE_Unmarshal((TPMU_SENSITIVE_COMPOSITE *)&(target->sensitive), buffer, size, (UINT32)target->sensitiveType);
    return result;
}

UINT16
TPMT_SENSITIVE_Marshal(
    TPMT_SENSITIVE *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_ALG_PUBLIC_Marshal((TPMI_ALG_PUBLIC *)&(source->sensitiveType), buffer, size));
    result = (UINT16)(result + TPM2B_AUTH_Marshal((TPM2B_AUTH *)&(source->authValue), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->seedValue), buffer, size));
    result = (UINT16)(result + TPMU_SENSITIVE_COMPOSITE_Marshal((TPMU_SENSITIVE_COMPOSITE *)&(source->sensitive), buffer, size, (UINT32)source->sensitiveType));
    return result;
}


// Table 2:189 - Definition of TPM2B_SENSITIVE Structure  (StructureTable)
TPM_RC
TPM2B_SENSITIVE_Unmarshal(
    TPM2B_SENSITIVE *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    INT32    startSize;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    startSize = *size;
    result = TPMT_SENSITIVE_Unmarshal((TPMT_SENSITIVE *)&(target->t.sensitiveArea), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(target->t.size != (startSize - *size)) return TPM_RC_SIZE;
    return TPM_RC_SUCCESS;
}

//     TPM2B_SENSITIVE_Marshal not referenced


// Table 2:190 - Definition of _PRIVATE Structure  (StructureTable)
//     _PRIVATE_Unmarshal not referenced
//     _PRIVATE_Marshal not referenced


// Table 2:191 - Definition of TPM2B_PRIVATE Structure  (StructureTable)
TPM_RC
TPM2B_PRIVATE_Unmarshal(
    TPM2B_PRIVATE *target, BYTE **buffer, INT32     *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(_PRIVATE))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_PRIVATE_Marshal(
    TPM2B_PRIVATE *source, BYTE **buffer, INT32     *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:192 - Definition of _ID_OBJECT Structure  (StructureTable)
//     _ID_OBJECT_Unmarshal not referenced
//     _ID_OBJECT_Marshal not referenced


// Table 2:193 - Definition of TPM2B_ID_OBJECT Structure  (StructureTable)
TPM_RC
TPM2B_ID_OBJECT_Unmarshal(
    TPM2B_ID_OBJECT *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(_ID_OBJECT))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.credential), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_ID_OBJECT_Marshal(
    TPM2B_ID_OBJECT *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.credential), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:194 - Definition of TPM_NV_INDEX Bits  (BitsTable)
//     TPM_NV_INDEX_Unmarshal not referenced
//     TPM_NV_INDEX_Marshal not referenced


// Table 2:195 - Definition of TPMA_NV Bits (BitsTable)
TPM_RC
TPMA_NV_Unmarshal(
    TPMA_NV *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    result = UINT32_Unmarshal((UINT32 *)target, buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(*((UINT32 *)target) & (UINT32)0x01f00380)
        return TPM_RC_RESERVED_BITS;
    return TPM_RC_SUCCESS;
}

//   TPMA_NV_Marshal changed to #define


// Table 2:196 - Definition of TPMS_NV_PUBLIC Structure (StructureTable)
TPM_RC
TPMS_NV_PUBLIC_Unmarshal(
    TPMS_NV_PUBLIC *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = TPMI_RH_NV_INDEX_Unmarshal((TPMI_RH_NV_INDEX *)&(target->nvIndex), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_ALG_HASH_Unmarshal((TPMI_ALG_HASH *)&(target->nameAlg), buffer, size, 0);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMA_NV_Unmarshal((TPMA_NV *)&(target->attributes), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_DIGEST_Unmarshal((TPM2B_DIGEST *)&(target->authPolicy), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = UINT16_Unmarshal((UINT16 *)&(target->dataSize), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if( (target->dataSize> MAX_NV_INDEX_SIZE))
        return TPM_RC_SIZE;
    return TPM_RC_SUCCESS;
}

UINT16
TPMS_NV_PUBLIC_Marshal(
    TPMS_NV_PUBLIC *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPMI_RH_NV_INDEX_Marshal((TPMI_RH_NV_INDEX *)&(source->nvIndex), buffer, size));
    result = (UINT16)(result + TPMI_ALG_HASH_Marshal((TPMI_ALG_HASH *)&(source->nameAlg), buffer, size));
    result = (UINT16)(result + TPMA_NV_Marshal((TPMA_NV *)&(source->attributes), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->authPolicy), buffer, size));
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->dataSize), buffer, size));
    return result;
}


// Table 2:197 - Definition of TPM2B_NV_PUBLIC Structure (StructureTable)
TPM_RC
TPM2B_NV_PUBLIC_Unmarshal(
    TPM2B_NV_PUBLIC *target, BYTE **buffer, INT32   *size
    )
{
    TPM_RC    result;
    INT32    startSize;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size is zero, then the required structure is missing
    if(target->t.size == 0)
        return TPM_RC_SIZE;
    startSize = *size;
    result = TPMS_NV_PUBLIC_Unmarshal((TPMS_NV_PUBLIC *)&(target->t.nvPublic), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    if(target->t.size != (startSize - *size)) return TPM_RC_SIZE;
    return TPM_RC_SUCCESS;
}

UINT16
TPM2B_NV_PUBLIC_Marshal(
    TPM2B_NV_PUBLIC *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    BYTE      *sizeField = *buffer;
    // Advance buffer pointer by cononical size of a UINT16
    *buffer += 2;
    // Marshal the structure
    result = (UINT16)(result + TPMS_NV_PUBLIC_Marshal((TPMS_NV_PUBLIC *)&(source->t.nvPublic), buffer, size));
    // Marshal the size
    result = (UINT16)(result + UINT16_Marshal(&result, &sizeField, size));
    return result;
}


// Table 2:198 - Definition of TPM2B_CONTEXT_SENSITIVE Structure  (StructureTable)
//     TPM2B_CONTEXT_SENSITIVE_Unmarshal not referenced
//     TPM2B_CONTEXT_SENSITIVE_Marshal not referenced


// Table 2:199 - Definition of TPMS_CONTEXT_DATA Structure  (StructureTable)
//     TPMS_CONTEXT_DATA_Unmarshal not referenced
//     TPMS_CONTEXT_DATA_Marshal not referenced


// Table 2:200 - Definition of TPM2B_CONTEXT_DATA Structure  (StructureTable)
TPM_RC
TPM2B_CONTEXT_DATA_Unmarshal(
    TPM2B_CONTEXT_DATA *target, BYTE **buffer, INT32    *size
    )
{
    TPM_RC    result;
    result = UINT16_Unmarshal((UINT16 *)&(target->t.size), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(target->t.size == 0)
        return TPM_RC_SUCCESS;
    if((target->t.size) > sizeof(TPMS_CONTEXT_DATA))
        return TPM_RC_SIZE;
    result = BYTE_Array_Unmarshal((BYTE *)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    return result;
}

UINT16
TPM2B_CONTEXT_DATA_Marshal(
    TPM2B_CONTEXT_DATA *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT16_Marshal((UINT16 *)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result + BYTE_Array_Marshal((BYTE *)(source->t.buffer), buffer, size, (INT32)(source->t.size)));
    return result;
}


// Table 2:201 - Definition of TPMS_CONTEXT Structure (StructureTable)
TPM_RC
TPMS_CONTEXT_Unmarshal(
    TPMS_CONTEXT *target, BYTE **buffer, INT32  *size
    )
{
    TPM_RC    result;
    result = UINT64_Unmarshal((UINT64 *)&(target->sequence), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_DH_CONTEXT_Unmarshal((TPMI_DH_CONTEXT *)&(target->savedHandle), buffer, size);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPMI_RH_HIERARCHY_Unmarshal((TPMI_RH_HIERARCHY *)&(target->hierarchy), buffer, size, 1);
    if(result != TPM_RC_SUCCESS)
        return result;
    result = TPM2B_CONTEXT_DATA_Unmarshal((TPM2B_CONTEXT_DATA *)&(target->contextBlob), buffer, size);
    return result;
}

UINT16
TPMS_CONTEXT_Marshal(
    TPMS_CONTEXT *source, BYTE **buffer, INT32  *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + UINT64_Marshal((UINT64 *)&(source->sequence), buffer, size));
    result = (UINT16)(result + TPMI_DH_CONTEXT_Marshal((TPMI_DH_CONTEXT *)&(source->savedHandle), buffer, size));
    result = (UINT16)(result + TPMI_RH_HIERARCHY_Marshal((TPMI_RH_HIERARCHY *)&(source->hierarchy), buffer, size));
    result = (UINT16)(result + TPM2B_CONTEXT_DATA_Marshal((TPM2B_CONTEXT_DATA *)&(source->contextBlob), buffer, size));
    return result;
}


// Table 2:203 - Definition of TPMS_CREATION_DATA Structure  (StructureTable)
//     TPMS_CREATION_DATA_Unmarshal not referenced
UINT16
TPMS_CREATION_DATA_Marshal(
    TPMS_CREATION_DATA *source, BYTE **buffer, INT32    *size
    )
{
    UINT16    result = 0;
    result = (UINT16)(result + TPML_PCR_SELECTION_Marshal((TPML_PCR_SELECTION *)&(source->pcrSelect), buffer, size));
    result = (UINT16)(result + TPM2B_DIGEST_Marshal((TPM2B_DIGEST *)&(source->pcrDigest), buffer, size));
    result = (UINT16)(result + TPMA_LOCALITY_Marshal((TPMA_LOCALITY *)&(source->locality), buffer, size));
    result = (UINT16)(result + TPM_ALG_ID_Marshal((TPM_ALG_ID *)&(source->parentNameAlg), buffer, size));
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->parentName), buffer, size));
    result = (UINT16)(result + TPM2B_NAME_Marshal((TPM2B_NAME *)&(source->parentQualifiedName), buffer, size));
    result = (UINT16)(result + TPM2B_DATA_Marshal((TPM2B_DATA *)&(source->outsideInfo), buffer, size));
    return result;
}


// Table 2:204 - Definition of TPM2B_CREATION_DATA Structure  (StructureTable)
//     TPM2B_CREATION_DATA_Unmarshal not referenced
UINT16
TPM2B_CREATION_DATA_Marshal(
    TPM2B_CREATION_DATA *source, BYTE **buffer, INT32   *size
    )
{
    UINT16    result = 0;
    BYTE      *sizeField = *buffer;
    // Advance buffer pointer by cononical size of a UINT16
    *buffer += 2;
    // Marshal the structure
    result = (UINT16)(result + TPMS_CREATION_DATA_Marshal((TPMS_CREATION_DATA *)&(source->t.creationData), buffer, size));
    // Marshal the size
    result = (UINT16)(result + UINT16_Marshal(&result, &sizeField, size));
    return result;
}

// Array Marshal/Unmarshal for TPMS_TAGGED_PROPERTY
//     TPMS_TAGGED_PROPERTY_Array_Unmarshal not referenced
UINT16
TPMS_TAGGED_PROPERTY_Array_Marshal(
    TPMS_TAGGED_PROPERTY *source, BYTE **buffer, INT32 *size, INT32      count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPMS_TAGGED_PROPERTY_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPMS_ALG_PROPERTY
//     TPMS_ALG_PROPERTY_Array_Unmarshal not referenced
UINT16
TPMS_ALG_PROPERTY_Array_Marshal(
    TPMS_ALG_PROPERTY *source, BYTE **buffer, INT32 *size, INT32     count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPMS_ALG_PROPERTY_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPMS_PCR_SELECTION
TPM_RC
TPMS_PCR_SELECTION_Array_Unmarshal(
    TPMS_PCR_SELECTION *target, BYTE **buffer, INT32 *size, INT32    count
    )
{
    TPM_RC    result;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = TPMS_PCR_SELECTION_Unmarshal(&target[i], buffer, size);
        if(result != TPM_RC_SUCCESS)
            return result;
    }
    return TPM_RC_SUCCESS;
}

UINT16
TPMS_PCR_SELECTION_Array_Marshal(
    TPMS_PCR_SELECTION *source, BYTE **buffer, INT32 *size, INT32    count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPMS_PCR_SELECTION_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPMT_HA
TPM_RC
TPMT_HA_Array_Unmarshal(
    TPMT_HA *target, BYTE **buffer, INT32 *size, BOOL flag, INT32    count
    )
{
    TPM_RC    result;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = TPMT_HA_Unmarshal(&target[i], buffer, size, flag);
        if(result != TPM_RC_SUCCESS)
            return result;
    }
    return TPM_RC_SUCCESS;
}

UINT16
TPMT_HA_Array_Marshal(
    TPMT_HA *source, BYTE **buffer, INT32 *size, INT32   count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPMT_HA_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for BYTE
TPM_RC
BYTE_Array_Unmarshal(
    BYTE *target, BYTE **buffer, INT32 *size, INT32      count
    )
{
    TPM_RC    result;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = BYTE_Unmarshal(&target[i], buffer, size);
        if(result != TPM_RC_SUCCESS)
            return result;
    }
    return TPM_RC_SUCCESS;
}

UINT16
BYTE_Array_Marshal(
    BYTE *source, BYTE **buffer, INT32 *size, INT32      count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + BYTE_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPM_HANDLE
//     TPM_HANDLE_Array_Unmarshal not referenced
UINT16
TPM_HANDLE_Array_Marshal(
    TPM_HANDLE *source, BYTE **buffer, INT32 *size, INT32    count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPM_HANDLE_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPMA_CC
//     TPMA_CC_Array_Unmarshal not referenced
UINT16
TPMA_CC_Array_Marshal(
    TPMA_CC *source, BYTE **buffer, INT32 *size, INT32   count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPMA_CC_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPMS_TAGGED_PCR_SELECT
//     TPMS_TAGGED_PCR_SELECT_Array_Unmarshal not referenced
UINT16
TPMS_TAGGED_PCR_SELECT_Array_Marshal(
    TPMS_TAGGED_PCR_SELECT *source, BYTE **buffer, INT32 *size, INT32    count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPMS_TAGGED_PCR_SELECT_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPM_ECC_CURVE
#ifdef    TPM_ALG_ECC
//     TPM_ECC_CURVE_Array_Unmarshal not referenced
UINT16
TPM_ECC_CURVE_Array_Marshal(
    TPM_ECC_CURVE *source, BYTE **buffer, INT32 *size, INT32     count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPM_ECC_CURVE_Marshal(&source[i], buffer, size));
    }
    return result;
}

#endif // TPM_ALG_ECC
// Array Marshal/Unmarshal for TPM2B_DIGEST
TPM_RC
TPM2B_DIGEST_Array_Unmarshal(
    TPM2B_DIGEST *target, BYTE **buffer, INT32 *size, INT32      count
    )
{
    TPM_RC    result;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = TPM2B_DIGEST_Unmarshal(&target[i], buffer, size);
        if(result != TPM_RC_SUCCESS)
            return result;
    }
    return TPM_RC_SUCCESS;
}

UINT16
TPM2B_DIGEST_Array_Marshal(
    TPM2B_DIGEST *source, BYTE **buffer, INT32 *size, INT32      count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPM2B_DIGEST_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPM_CC
TPM_RC
TPM_CC_Array_Unmarshal(
    TPM_CC *target, BYTE **buffer, INT32 *size, INT32    count
    )
{
    TPM_RC    result;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = TPM_CC_Unmarshal(&target[i], buffer, size);
        if(result != TPM_RC_SUCCESS)
            return result;
    }
    return TPM_RC_SUCCESS;
}

UINT16
TPM_CC_Array_Marshal(
    TPM_CC *source, BYTE **buffer, INT32 *size, INT32    count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPM_CC_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for TPM_ALG_ID
TPM_RC
TPM_ALG_ID_Array_Unmarshal(
    TPM_ALG_ID *target, BYTE **buffer, INT32 *size, INT32    count
    )
{
    TPM_RC    result;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = TPM_ALG_ID_Unmarshal(&target[i], buffer, size);
        if(result != TPM_RC_SUCCESS)
            return result;
    }
    return TPM_RC_SUCCESS;
}

UINT16
TPM_ALG_ID_Array_Marshal(
    TPM_ALG_ID *source, BYTE **buffer, INT32 *size, INT32    count
    )
{
    UINT16    result = 0;
    INT32 i;
    for(i = 0; i < count; i++) {
        result = (UINT16)(result + TPM_ALG_ID_Marshal(&source[i], buffer, size));
    }
    return result;
}
