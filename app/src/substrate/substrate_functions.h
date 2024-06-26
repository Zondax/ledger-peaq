/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "parser_common.h"

// Common read functions

parser_error_t _readbool(parser_context_t *c, pd_bool_t *v);
parser_error_t _readu8(parser_context_t *c, pd_u8_t *v);
parser_error_t _readu16(parser_context_t *c, pd_u16_t *v);
parser_error_t _readu32(parser_context_t *c, pd_u32_t *v);
parser_error_t _readu64(parser_context_t *c, pd_u64_t *v);
parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v);
parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v);
parser_error_t _readCompactu64(parser_context_t *c, pd_Compactu64_t *v);
parser_error_t _readCallImpl(parser_context_t *c, pd_Call_t *v, pd_MethodNested_t *m);

parser_error_t _readBalance(parser_context_t *c, pd_Balance_t *v);
parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v);
parser_error_t _readBalanceOf(parser_context_t *c, pd_BalanceOf_t *v);
parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v);
parser_error_t _readCompactAccountIndex(parser_context_t *c, pd_CompactAccountIndex_t *v);
parser_error_t _readAccountIdLookupOfT(parser_context_t *c, pd_AccountIdLookupOfT_t *v);
parser_error_t _readCall(parser_context_t *c, pd_Call_t *v);
parser_error_t _readLookupasStaticLookupSource(parser_context_t *c, pd_LookupasStaticLookupSource_t *v);
parser_error_t _readVestingInfo(parser_context_t *c, pd_VestingInfo_t *v);
parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v);

// Common toString functions

parser_error_t _toStringu8(const pd_u8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu16(const pd_u16_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu32(const pd_u32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu64(const pd_u64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringbool(const pd_bool_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBlockNumber(const pd_BlockNumber_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringCompactu32(const pd_Compactu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringCompactu64(const pd_Compactu64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringBalance(const pd_Balance_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringAccountId(const pd_AccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringBalanceOf(const pd_BalanceOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringBytes(const pd_Bytes_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringCompactAccountIndex(const pd_CompactAccountIndex_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAccountIdLookupOfT(const pd_AccountIdLookupOfT_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCall(const pd_Call_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringLookupasStaticLookupSource(const pd_LookupasStaticLookupSource_t *v, char *outValue,
                                                   uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVestingInfo(const pd_VestingInfo_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringHash(const pd_Hash_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
