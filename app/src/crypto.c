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
#include "coin_evm.h"
#include "crypto_evm.h"
#include "crypto_helper.h"
#include "cx.h"
#include "ristretto.h"
#include "zxmacros.h"

uint32_t hdPath[HDPATH_LEN_DEFAULT];

zxerr_t crypto_sign_ed25519(uint8_t *signature, uint16_t signatureMaxlen, const uint8_t *message, uint16_t messageLen) {
    if (signature == NULL || message == NULL || signatureMaxlen < SIG_PLUS_TYPE_LEN || messageLen == 0) {
        return zxerr_buffer_too_small;
    }
    cx_ecfp_private_key_t cx_privateKey;
    uint8_t privateKeyData[SK_LEN_25519] = {0};

    const uint8_t *toSign = message;
    uint8_t messageDigest[BLAKE2B_DIGEST_SIZE] = {0};

    zxerr_t error = zxerr_unknown;

    if (messageLen > MAX_SIGN_SIZE) {
        // Hash it
        cx_blake2b_t ctx;
        CATCH_CXERROR(cx_blake2b_init_no_throw(&ctx, 256));
        CATCH_CXERROR(cx_hash_no_throw(&ctx.header, CX_LAST, message, messageLen, messageDigest, BLAKE2B_DIGEST_SIZE));
        toSign = messageDigest;
        messageLen = BLAKE2B_DIGEST_SIZE;
    }

    // Generate keys
    CATCH_CXERROR(os_derive_bip32_with_seed_no_throw(HDW_NORMAL, CX_CURVE_Ed25519, hdPath, HDPATH_LEN_DEFAULT,
                                                     privateKeyData, NULL, NULL, 0));

    CATCH_CXERROR(cx_ecfp_init_private_key_no_throw(CX_CURVE_Ed25519, privateKeyData, SCALAR_LEN_ED25519, &cx_privateKey));

    // Sign
    *signature = PREFIX_SIGNATURE_TYPE_ED25519;
    CATCH_CXERROR(cx_eddsa_sign_no_throw(&cx_privateKey, CX_SHA512, toSign, messageLen, signature + 1, signatureMaxlen - 1));
    error = zxerr_ok;

catch_cx_error:
    MEMZERO(&cx_privateKey, sizeof(cx_privateKey));
    MEMZERO(privateKeyData, SK_LEN_25519);

    if (error != zxerr_ok) {
        MEMZERO(signature, signatureMaxlen);
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
