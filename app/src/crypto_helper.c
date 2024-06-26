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

#include "crypto_helper.h"

#include "base58.h"
#include "coin_evm.h"

#define EVM_STR_LEN 4

#if defined(TARGET_NANOS) || defined(TARGET_NANOX) || defined(TARGET_NANOS2) || defined(TARGET_STAX)
#include "cx.h"
cx_err_t ss58hash(const unsigned char *in, unsigned int inLen, unsigned char *out, unsigned int outLen) {
    cx_blake2b_t ctx;
    CHECK_CXERROR(cx_blake2b_init_no_throw(&ctx, 512));
    CHECK_CXERROR(cx_hash_no_throw(&ctx.header, 0, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN, NULL, 0));
    CHECK_CXERROR(cx_hash_no_throw(&ctx.header, CX_LAST, in, inLen, out, outLen));

    return CX_OK;
}

cx_err_t encoding_hash(const unsigned char *in, unsigned int inLen, unsigned char *out, unsigned int outLen) {
    cx_blake2b_t ctx;
    CHECK_CXERROR(cx_blake2b_init_no_throw(&ctx, 256));
    CHECK_CXERROR(cx_hash_no_throw(&ctx.header, CX_LAST, in, inLen, out, outLen));
    return CX_OK;
}
#else

#include <hexutils.h>

#include "blake2.h"

int ss58hash(const unsigned char *in, unsigned int inLen, unsigned char *out, unsigned int outLen) {
    blake2b_state s;
    blake2b_init(&s, 64);
    blake2b_update(&s, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN);
    blake2b_update(&s, in, inLen);
    blake2b_final(&s, out, outLen);
    return 0;
}

int encoding_hash(const unsigned char *in, unsigned int inLen, unsigned char *out, unsigned int outLen) {
    blake2b_state s;
    blake2b_init(&s, 32);
    blake2b_update(&s, in, inLen);
    blake2b_final(&s, out, outLen);
    return 0;
}
#endif

uint8_t crypto_SS58CalculatePrefix(uint16_t addressType, uint8_t *prefixBytes) {
    if (addressType > 16383) {
        return 0;
    }

    if (addressType > 63) {
        prefixBytes[0] = 0x40 | ((addressType >> 2) & 0x3F);
        prefixBytes[1] = ((addressType & 0x3) << 6) + ((addressType >> 8) & 0x3F);
        return 2;
    }

    prefixBytes[0] = addressType & 0x3F;  // address type
    return 1;
}

uint16_t crypto_SS58EncodePubkey(uint8_t *buffer, uint16_t buffer_len, uint16_t addressType, const uint8_t *pubkey) {
    // based on https://docs.substrate.io/v3/advanced/ss58/
    if (buffer == NULL || buffer_len < SS58_ADDRESS_MAX_LEN) {
        return 0;
    }
    if (pubkey == NULL) {
        return 0;
    }
    MEMZERO(buffer, buffer_len);

    uint8_t hash[64] = {0};
    uint8_t unencoded[36] = {0};

    const uint8_t prefixSize = crypto_SS58CalculatePrefix(addressType, unencoded);
    if (prefixSize == 0) {
        return 0;
    }

    memcpy(unencoded + prefixSize, pubkey, 32);  // account id
    if (ss58hash((uint8_t *)unencoded, 32 + prefixSize, hash, 64) != CX_OK) {
        MEMZERO(unencoded, sizeof(unencoded));
        return 0;
    }
    unencoded[32 + prefixSize] = hash[0];
    unencoded[33 + prefixSize] = hash[1];

    size_t outLen = buffer_len;
    if (encode_base58(unencoded, 34 + prefixSize, buffer, &outLen) != 0) {
        MEMZERO(unencoded, sizeof(unencoded));
        return 0;
    }

    return outLen;
}

zxerr_t convertEvmToSS58(uint8_t *evm_addr, uint16_t evm_addr_len, uint8_t *ss58_addr, uint16_t *ss58_addr_len) {
    if (evm_addr == NULL || evm_addr_len != ETH_ADDR_LEN || ss58_addr == NULL || *ss58_addr_len < SS58_ADDRESS_MAX_LEN) {
        return zxerr_invalid_crypto_settings;
    }

    // Append emv: prefix
    const char *evm_str = "evm:";

    uint8_t msg[EVM_STR_LEN + ETH_ADDR_LEN];
    memcpy(msg, evm_str, EVM_STR_LEN);
    memcpy(msg + EVM_STR_LEN, evm_addr, ETH_ADDR_LEN);

    // hash previous prefixed address and concatenate with ss58 prefix
    uint8_t prefix_message[1 + 32] = {0};
    prefix_message[0] = 0x2A;
    encoding_hash(msg, EVM_STR_LEN + ETH_ADDR_LEN, prefix_message + 1, 32);

    // SS58 hash previous
    uint8_t hash[64] = {0};
    ss58hash(prefix_message, 1 + 32, hash, 64);

    // Get msg to encode -> 42 | hash(evm|evm_addr) | 2 bytes of ss58hash(42 | hash(evm|evm_addr))
    uint8_t to_encode[33 + 2];
    memcpy(to_encode, prefix_message, 33);
    memcpy(to_encode + 33, hash, 2);

    size_t out_len = *ss58_addr_len;
    if (encode_base58(to_encode, 35, ss58_addr, &out_len) != 0) {
        return zxerr_encoding_failed;
    }

    *ss58_addr_len = out_len;

    return zxerr_ok;
}
