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

#include "parser.h"

#include <stdio.h>
#include <zxformat.h>
#include <zxmacros.h>
#include <zxtypes.h>

#include "coin.h"
#include "crypto.h"
#include "parser_common.h"
#include "parser_impl.h"

parser_error_t parser_init_context(parser_context_t *ctx, const uint8_t *buffer, uint16_t bufferSize) {
    if (ctx == NULL || bufferSize == 0 || buffer == NULL) {
        return parser_init_context_empty;
    }

    ctx->offset = 0;
    ctx->buffer = buffer;
    ctx->bufferLen = bufferSize;
    return parser_ok;
}

// For future implementation
parser_error_t parser_parse(parser_context_t *ctx, const uint8_t *data, size_t dataLen, parser_tx_t *tx_obj) {
    UNUSED(ctx);
    UNUSED(data);
    UNUSED(dataLen);
    UNUSED(tx_obj);
    return parser_not_supported_parser;
}

// For future implementation
parser_error_t parser_validate(parser_context_t *ctx) {
    UNUSED(ctx);
    return parser_not_supported_validation;
}
