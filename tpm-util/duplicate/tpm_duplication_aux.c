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


#include "tpm_duplication_aux.h"
#include "marshal.h"

#define AES_SIZE 16;

void print2b(char* msg, TPM2B * toprint){
	print_buff(msg, toprint->size, toprint->buffer);
}

void TPMT_PUBLIC_TO_TPM2B(TPMT_PUBLIC *source, TPM2B_PUBLIC *target)
{
	BYTE buff[1024],
		*runner = buff+2;
	int size = 1024;

	UINT16 sizeField = TPMT_PUBLIC_Marshal(source, &runner, &size);
	runner = buff;
	UINT16_Marshal(&sizeField, &runner, &size);


	runner = buff;
	size = sizeof(TPM2B_PUBLIC);
	TPM2B_PUBLIC_Unmarshal(target, &runner, &size, 1);
}

void TPMT_SENSITIVE_TO_TPM2B(TPMT_SENSITIVE *source, TPM2B_SENSITIVE *target)
{
	BYTE buff[1024]={0},
		*runner = buff+2;
	INT32 size = 1024;

	UINT16 sizeField = TPMT_SENSITIVE_Marshal(source, &runner, &size);
	runner = buff;
	UINT16_Marshal(&sizeField, &runner, &size);


	runner = buff;
	size = sizeof(TPM2B_SENSITIVE);
	TPM2B_SENSITIVE_Unmarshal(target, &runner, &size);


}

void TPM2B_SENSITIVE_TO_TPMT(TPM2B_SENSITIVE *source, TPMT_SENSITIVE *target)
{
	BYTE buffer[1024], *runner = buffer;
	int size = 1024;
	TPMT_SENSITIVE_Marshal(&(source->t.sensitiveArea), &runner, &size);

	runner = buffer;
	size = sizeof(*target);

	TPMT_SENSITIVE_Unmarshal(target, &runner, &size);

}
void TPM2B_PUBLIC_TO_TPMT(TPM2B_PUBLIC *source, TPMT_PUBLIC *target)
{
	BYTE buffer[1024], *runner = buffer;
	int size = 1024;
	TPMT_PUBLIC_Marshal(&(source->t.publicArea), &runner, &size);

	runner = buffer;
	size = sizeof(*target);

	TPMT_PUBLIC_Unmarshal(target, &runner, &size, 1);
}


TPM2B_NAME * GetName(TPMI_ALG_HASH hashAlg, TPM2B_PUBLIC *obj, TPM2B_NAME *outName)
{
	int size_in =1024;
	BYTE buff[1024] = {0};
	BYTE* runner = buff;

	UINT16 toHashSize = TPM2B_PUBLIC_Marshal(obj, &runner, &size_in) ;

	runner = outName->b.buffer;
	size_in = 2;
	outName->b.size =  TPM_ALG_ID_Marshal(&hashAlg, &runner , &size_in) + 32;

	SHA256(buff+2, toHashSize-2, runner);

	return outName;
}


void CreateDuplicationBlob2B(
		//IN
		TPM2B_PUBLIC_KEY_RSA *protector,
		TPM2B_PUBLIC * public2B,
		TPM2B_SENSITIVE *sens2B,
		TPM2B_ENCRYPTED_SECRET *plainSymSeed, TPMI_YES_NO generateInSymSeed,
		TPM2B_DATA *encryptionKey, TPMI_YES_NO generateEncryptionKey,

		//OUT
		TPM2B_PRIVATE *outDuplicate,
		TPM2B_ENCRYPTED_SECRET *encSymSeed)
{
	TPMT_PUBLIC publicPortion;
	TPMT_SENSITIVE sens;

	TPM2B_PUBLIC_TO_TPMT(public2B, &publicPortion);
	TPM2B_SENSITIVE_TO_TPMT(sens2B, &sens);

	CreateDuplicationBlob(protector, &publicPortion, &sens, plainSymSeed, generateInSymSeed, encryptionKey, generateEncryptionKey, outDuplicate, encSymSeed);

}

void CreateSwDataObject2B(
		BYTE* auth, UINT16 authSize,
		RSA * rsaKey,
		BYTE * policyDigest, UINT16 policyDigestSize,
		TPM2B_PUBLIC * outPublic2B, 
        TPM2B_SENSITIVE *outSens2B)
{

	TPMT_PUBLIC publicPortion;
	TPMT_SENSITIVE sens;

	CreateSwDataObject(auth, authSize, rsaKey, NULL, 0, policyDigest, policyDigestSize, &publicPortion, &sens);


	TPMT_PUBLIC_TO_TPM2B(&publicPortion, outPublic2B);
	TPMT_SENSITIVE_TO_TPM2B(&sens, outSens2B);
}

void CreateDuplicationBlob(
		//IN
		TPM2B_PUBLIC_KEY_RSA *protector,
		TPMT_PUBLIC * publicPortion,
		TPMT_SENSITIVE *sens,
		TPM2B_ENCRYPTED_SECRET *plainSymSeed, TPMI_YES_NO generateInSymSeed,
		TPM2B_DATA *encryptionKey, TPMI_YES_NO generateEncryptionKey,

		//OUT
		TPM2B_PRIVATE *outDuplicate,
		TPM2B_ENCRYPTED_SECRET *encSymSeed)
{
	memset((void*)outDuplicate, 0, sizeof(TPM2B_PRIVATE));
	memset((void*)encSymSeed, 0, sizeof(TPM2B_ENCRYPTED_SECRET));
	TPM2B_SYM_KEY outerWrapper;
	TPM2B NULL_2B = {0};
	TPM2B_NAME swkName = {{0}};


	TPM2B_PUBLIC public2B = {{0}};
	TPM2B_SENSITIVE sens2B = {{0}};
	INT32 size_in = 0;

	TPM2B_MAX_BUFFER encSensitive = {{0}};

	if(generateInSymSeed)
	{
		RAND_bytes(plainSymSeed->b.buffer, 16);
		plainSymSeed->b.size = 16;
	}
	if(generateEncryptionKey)
	{
		RAND_bytes(encryptionKey->b.buffer, 16);
		encryptionKey->b.size = 16;
	}

	// Preparing marshaled publicPortion:
	TPMT_PUBLIC_TO_TPM2B(publicPortion, &public2B);

	// calculating name:
	GetName(TPM_ALG_SHA256, &(public2B), &swkName);

	// preparing marshaled sensitive:
	TPMT_SENSITIVE_TO_TPM2B(sens, &sens2B);

	//preparing encSensitive
	{
		UINT16 tempUint16;
		TPM2B_SYM_KEY IV = {0};
		IV.b.size = 16;
		TPM2B_MAX_BUFFER innerData = {0};
		BYTE innerIntegrity[34] = {0}, toHash[1024] = {0};
		size_in = 1024;
		BYTE* runner = toHash;


		UINT16_Marshal(&(sens2B.b.size), &runner, &size_in);
		TPMT_SENSITIVE_Marshal(sens, &runner, &size_in);

		memcpy(runner, swkName.b.buffer, swkName.b.size );
		runner += swkName.b.size;


		SHA256(toHash, runner - toHash, innerIntegrity+2);
		runner = innerIntegrity;
		tempUint16 = 32;
		UINT16_Marshal(&tempUint16, &runner, &size_in);

		memcpy(innerData.b.buffer, innerIntegrity, 34);
		runner = innerData.b.buffer + 34;
		size_in = 1024;

		UINT16_Marshal(&(sens2B.b.size), &runner, &size_in);
		TPMT_SENSITIVE_Marshal(sens, &runner, &size_in);

		innerData.b.size = sens2B.b.size + 36;

		AES_128_CFB_enc_dec(&(innerData.b), &(encSensitive.b), &(encryptionKey->b), &(IV.b), NULL, 1);
	}


	// outer integrity
	{
		TPM2B_SYM_KEY IV = {{0}};
		TPM2B_DIGEST hmacKey = {{0}};
		TPM2B_DIGEST outerHmac = {{0}};
		TPM2B_MAX_BUFFER dupSensitive = {{0}};
		TPM2B_MAX_BUFFER dataToHmac = {{0}};
		BYTE * runner = NULL;

		IV.b.size = 16;

		KDFa(TPM_ALG_SHA256, &(plainSymSeed->b), "STORAGE", &(swkName.b), &NULL_2B, 128 , (TPM2B_MAX_BUFFER*) &outerWrapper);

		AES_128_CFB_enc_dec(&(encSensitive.b), &(dupSensitive.b), &(outerWrapper.b), &(IV.b), NULL, 1);

		KDFa(TPM_ALG_SHA256,  &(plainSymSeed->b), "INTEGRITY", &NULL_2B, &NULL_2B, 32*8,(TPM2B_MAX_BUFFER*) &(hmacKey.b));

		memcpy(dataToHmac.b.buffer, dupSensitive.b.buffer, dupSensitive.b.size);
		memcpy(dataToHmac.b.buffer + dupSensitive.b.size, swkName.b.buffer, swkName.b.size);
		dataToHmac.b.size = dupSensitive.b.size + swkName.b.size;


		HMAC(EVP_sha256(), hmacKey.b.buffer, hmacKey.b.size, dataToHmac.b.buffer, dataToHmac.b.size,
				outerHmac.b.buffer, (UINT32*) &size_in);

		outerHmac.b.size = size_in;

		runner = outDuplicate->b.buffer;
		size_in = sizeof(*outDuplicate) - 2;
		outDuplicate->b.size = TPM2B_DIGEST_Marshal(&outerHmac, &runner, &size_in);

		memcpy(runner, dupSensitive.b.buffer, dupSensitive.b.size);
		outDuplicate->b.size += dupSensitive.b.size;

	}

	// Encrypting seed with RSA pub:
	TPM2B_DATA encodingParams = {{0}};
	encodingParams.b.size = 10;
	memcpy(encodingParams.b.buffer, "DUPLICATE", 10);

	RSA_OAEP_Enc((TPM2B_PUBLIC_KEY_RSA*)plainSymSeed, (TPM2B_PUBLIC_KEY_RSA*)encSymSeed, protector, &encodingParams);

}

void rsaKeyTobn( const RSA* rsaKey,
                const BIGNUM** n,
                const BIGNUM** e,
                const BIGNUM** d,
                const BIGNUM** p,
                const BIGNUM** q
                )
{
#if OPENSSL_VERSION_NUMBER < 0x10100000
    if (n != NULL) 
    {
        *n = rsaKey->n;
        *e = rsaKey->e;
        *d = rsaKey->d;
    }
    if (p != NULL) 
    {
        *p = rsaKey->p;
        *q = rsaKey->q;
    }

#else
    if (n != NULL) 
    {
        RSA_get0_key(rsaKey, n, e, d);
    }
    if (p != NULL) 
    {
        RSA_get0_factors(rsaKey, p, q);
    }
#endif
}

int rsabnTobin( const BIGNUM** n,
                const BIGNUM** e,
                const BIGNUM** p,
                uint8_t** n_bytes, int* n_size,
                uint8_t** e_bytes, int* e_size,
                uint8_t** p_bytes, int* p_size
                )
{
    int rc=-1;
    
    if(n_size != NULL)
    {
        *n_size = BN_num_bytes(*n);
    }

    if( (n_bytes != NULL) && (*n_size > 0) )
    {
        *n_bytes = (uint8_t*) malloc(*n_size);
        BN_bn2bin(*n, *n_bytes); 
        rc = 0;
    }

    if(e_size != NULL)
    {
        *e_size = BN_num_bytes(*e);
    }

    if( (e_bytes != NULL) && (*e_size > 0) )
    {
        *e_bytes = (uint8_t*) malloc(*e_size);
        BN_bn2bin(*e, *e_bytes); 
        rc = 0;
    }

    if(p_size != NULL)
    {
        *p_size = BN_num_bytes(*p);
    }

    if( (p_bytes != NULL) && (*p_size > 0) )
    {
        *p_bytes = (uint8_t*) malloc(*p_size);
        BN_bn2bin(*p, *p_bytes); 
        rc = 0;
    }

end:
    return rc;
}


void CreateSwDataObject(
		BYTE* auth, UINT16 authSize,
		RSA * rsaKey,
		BYTE * dataToSeal, UINT16 dataSize,
		BYTE * policyDigest, UINT16 policyDigestSize,
		TPMT_PUBLIC * outPublic, 
        TPMT_SENSITIVE *outSens)
{
	TPM2B_MAX_BUFFER hash_buffer;
	BYTE seed[32] = {0};

    if(rsaKey != NULL)
    {
    /* Asymmetric key (RSA) creation */

        const BIGNUM    *n;
        const BIGNUM    *e;
        const BIGNUM    *d;
        const BIGNUM    *p;
        const BIGNUM    *q;

        uint8_t* n_bytes; int n_size;
        uint8_t* e_bytes; int e_size;
        uint8_t* p_bytes; int p_size;

        rsaKeyTobn(rsaKey, &n, &e, &d, &p, &q);

        rsabnTobin( &n, &e, &p,
                &n_bytes, &n_size,
                &e_bytes, &e_size,
                &p_bytes, &p_size
                );

        /* Fill TPM Sensitive data */
        outSens->sensitiveType = TPM_ALG_RSA;

        outSens->authValue.b.size = authSize;
        memcpy(outSens->authValue.b.buffer, auth, authSize);

        outSens->seedValue.b.size = 32;
        memcpy(outSens->seedValue.b.buffer, seed, 32);

        outSens->sensitive.bits.b.size = p_size;
        memcpy(outSens->sensitive.bits.b.buffer, p_bytes, p_size);

        /* Fill TPM Public portion */
        outPublic->type = TPM_ALG_RSA;
        outPublic->nameAlg = TPM_ALG_SHA256;
        outPublic->objectAttributes.val = 0;
        //outPublic->objectAttributes.val |= TPMA_OBJECT_RESTRICTED;
        outPublic->objectAttributes.val |= TPMA_OBJECT_USERWITHAUTH;
        outPublic->objectAttributes.val |= TPMA_OBJECT_SIGN;
        outPublic->authPolicy.t.size = 0;

        /* Table 182 - Definition of TPMU_PUBLIC_PARMS Union <IN/OUT, S> */
        outPublic->parameters.rsaDetail.symmetric.algorithm = TPM_ALG_NULL;
        outPublic->parameters.rsaDetail.scheme.scheme = TPM_ALG_NULL;
        //outPublic->parameters.rsaDetail.scheme.details.rsassa.hashAlg = TPM_ALG_SHA256;
        
        outPublic->parameters.rsaDetail.keyBits = BYTES_TO_BITS(n_size);;
        printf("outPublic->parameters.rsaDetail.keyBits: %d \n", outPublic->parameters.rsaDetail.keyBits);

        unsigned long tmp_val = 0;  // Need to use this temp variable?
        memcpy(&tmp_val, e_bytes, e_size);
        outPublic->parameters.rsaDetail.exponent = tmp_val;
        printf("outPublic->parameters.rsaDetail.exponent: 0x%x \n", outPublic->parameters.rsaDetail.exponent);

        outPublic->unique.rsa.t.size = n_size;
        memcpy(outPublic->unique.rsa.t.buffer, n_bytes, n_size);
        printf("outPublic->unique.rsa.t.size: %d \n", outPublic->unique.rsa.t.size);

        if(( policyDigestSize > 0) && (policyDigest != NULL) )
        {
            memcpy(outPublic->authPolicy.b.buffer, policyDigest, policyDigestSize);
            outPublic->authPolicy.b.size = policyDigestSize;
        }
    }
    
    else if( (dataToSeal != NULL) && (dataSize > 0) )
    {
    /* Symmetric Key Creation */

        outSens->authValue.b.size = authSize;
        memcpy(outSens->authValue.b.buffer, auth, authSize);

        outSens->seedValue.b.size = 32;
        memcpy(outSens->seedValue.b.buffer, seed, 32);

        outSens->sensitive.bits.b.size = dataSize;
        memcpy(outSens->sensitive.bits.b.buffer, dataToSeal, dataSize);

        outSens->sensitiveType = TPM_ALG_KEYEDHASH;

        outPublic->objectAttributes.val = 0;
        outPublic->objectAttributes.adminWithPolicy = 1;
        outPublic->nameAlg = TPM_ALG_SHA256;
        memcpy(outPublic->unique.keyedHash.b.buffer, dataToSeal, dataSize);
        outPublic->unique.keyedHash.b.size = dataSize;

        if(( policyDigestSize > 0) && (policyDigest != NULL) )
        {
            memcpy(outPublic->authPolicy.b.buffer, policyDigest, policyDigestSize);
            outPublic->authPolicy.b.size = policyDigestSize;
        }

        outPublic->type = TPM_ALG_KEYEDHASH;
        outPublic->nameAlg = TPM_ALG_SHA256;

        outPublic->parameters.keyedHashDetail.scheme.scheme = TPM_ALG_NULL;
        outPublic->parameters.keyedHashDetail.scheme.details.hmac.hashAlg = TPM_ALG_NULL;

        memcpy(hash_buffer.b.buffer, seed, 32);
        memcpy(hash_buffer.b.buffer+32, dataToSeal, dataSize);
        SHA256(hash_buffer.b.buffer, 32+dataSize, outPublic->unique.keyedHash.b.buffer);
        outPublic->unique.keyedHash.b.size = 32;
    }

}


TSS2_RC swKeyDuplicate(
      /* IN */
      RSA* rsaKey, TPM2B_PUBLIC* parentKeyPublicPortion, UINT8* policyDigest, int digestSize,
      /* OUT */ 
      TPM2B_DATA* encryptionKey, TPM2B_PUBLIC *swKeyPublic, TPM2B_PRIVATE *swKeyPrivate,  TPM2B_ENCRYPTED_SECRET *encSymSeed)
{
    TPM_RC rval = TPM_RC_SUCCESS;
    UINT8 auth[0];
    TPM2B_SENSITIVE swKeySens;
    TPM2B_ENCRYPTED_SECRET plainSymSeed = {{0}};
    TPM2B_PUBLIC_KEY_RSA protectorRsaPub = {{0}};

    INIT_SIMPLE_TPM2B_SIZE(swKeySens);
    INIT_SIMPLE_TPM2B_SIZE(*swKeyPublic);

    // Fill the protector data
    memcpy(protectorRsaPub.b.buffer, parentKeyPublicPortion->t.publicArea.unique.rsa.t.buffer, parentKeyPublicPortion->t.publicArea.unique.rsa.t.size);
    protectorRsaPub.b.size = parentKeyPublicPortion->t.publicArea.unique.rsa.t.size;

    // Fill Symmetric seed
    plainSymSeed.b.size =  encryptionKey->b.size = 16;
    encSymSeed->b.size = 16;

    // Create SW Data Object Public and Sensitive portions
    CreateSwDataObject2B(auth, 0, rsaKey, policyDigest, digestSize, swKeyPublic, &swKeySens);

    // Create Duplication blob needed for Import
    CreateDuplicationBlob2B( &protectorRsaPub, swKeyPublic, &swKeySens, &plainSymSeed, 0, encryptionKey, 1, swKeyPrivate, encSymSeed);

	return rval;
}


