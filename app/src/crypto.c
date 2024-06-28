/*******************************************************************************
 *   (c) 2018 - 2024 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include "crypto.h"

#include "base58.h"
#include "coin.h"
#include "crypto_evm.h"
#include "crypto_helper.h"
#include "cx.h"
#include "ristretto.h"
#include "zxmacros.h"

typedef struct {
    uint8_t sign_type;
    uint8_t r[32];
    uint8_t s[32];
    uint8_t v;

    // DER signature max size should be 73
    // https://bitcoin.stackexchange.com/questions/77191/what-is-the-maximum-size-of-a-der-encoded-ecdsa-signature#77192
    uint8_t der_signature[73];

} __attribute__((packed)) signature_substrate_t;

zxerr_t crypto_sign(uint8_t *output, uint16_t outputLen, const uint8_t *message, uint16_t messageLen, uint16_t *sigSize) {
    if (output == NULL || message == NULL || sigSize == NULL || outputLen < sizeof(signature_substrate_t)) {
        return zxerr_invalid_crypto_settings;
    }

    zxerr_t error = zxerr_unknown;
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SECP256K1_SK_LEN] = {0};
    size_t signatureLength = sizeof_field(signature_substrate_t, der_signature);
    uint32_t tmpInfo = 0;
    *sigSize = 0;

    const uint8_t *toSign = message;
    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE] = {0};

    // Hash Message if bigger
    if (messageLen > MAX_SIGN_SIZE) {
        // Hash it
        cx_blake2b_t ctx;
        CATCH_CXERROR(cx_blake2b_init_no_throw(&ctx, 256));
        CATCH_CXERROR(cx_hash_no_throw(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE));
        toSign = messageDigest;
        messageLen = BLAKE2B_DIGEST_SIZE;
    }

    signature_substrate_t *const signature = (signature_substrate_t *)output;
    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL, CX_CURVE_256K1, hdPathEth, HDPATH_LEN_DEFAULT,
                                                     privateKeyData, NULL, NULL, 0));
    CATCH_CXERROR(cx_ecfp_init_private_key_no_throw(CX_CURVE_256K1, privateKeyData, SK_SECP256K1_SIZE, &cx_privateKey));

    // Sign
    CATCH_CXERROR(cx_ecdsa_sign_no_throw(&cx_privateKey, CX_RND_RFC6979 | CX_LAST, CX_SHA256, toSign, messageLen,
                                         signature->der_signature, &signatureLength, &tmpInfo));

    signature->sign_type = PREFIX_SIGNATURE_TYPE_EDCSA;

    const err_convert_e err_c =
        convertDERtoRSV(signature->der_signature, tmpInfo, signature->r, signature->s, &signature->v);
    if (err_c != no_error) {
        error = zxerr_unknown;
    } else {
        *sigSize = sizeof_field(signature_substrate_t, sign_type) + sizeof_field(signature_substrate_t, r) +
                   sizeof_field(signature_substrate_t, s) + sizeof_field(signature_substrate_t, v);
        error = zxerr_ok;
    }

catch_cx_error:
    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
    MEMZERO(privateKeyData, sizeof(privateKeyData));
    if (error != zxerr_ok) {
        MEMZERO(signature, outputLen);
    }
    return error;
}

zxerr_t crypto_fillAddress(uint8_t *buffer, uint16_t bufferLen, uint16_t *addrResponseLen) {
    if (buffer == NULL || bufferLen < (SECP256K1_PK_LEN + SS58_ADDRESS_MAX_LEN) || addrResponseLen == NULL) {
        return zxerr_no_data;
    }
    MEMZERO(buffer, bufferLen);

    uint8_t pubkey[SECP256K1_PK_LEN] = {0};
    CHECK_ZXERR(crypto_extractUncompressedPublicKey(pubkey, SECP256K1_PK_LEN, &peaq_chain_code))

    memcpy(buffer, pubkey, SECP256K1_PK_LEN);

    uint8_t hash[KECCAK_256_SIZE] = {0};
    CHECK_ZXERR(keccak_digest(&pubkey[1], SECP256K1_PK_LEN - 1, hash, KECCAK_256_SIZE))

    // encode last 20 bytes of the hash(the eth address) to base58
    uint16_t ss58_len = SS58_ADDRESS_MAX_LEN;
    zxerr_t err = convertEvmToSS58(hash + 12, ETH_ADDR_LEN, buffer + SECP256K1_PK_LEN, &ss58_len);

    if (err != zxerr_ok) {
        MEMZERO(buffer, bufferLen);
        MEMZERO(hash, KECCAK_256_SIZE);
        MEMZERO(pubkey, SECP256K1_PK_LEN);
        return zxerr_unknown;
    }

    *addrResponseLen = SECP256K1_PK_LEN + ss58_len;
    return zxerr_ok;
}
