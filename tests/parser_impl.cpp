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

// #{TODO} --> Apply tests that check this app's encoding/libraries

#include "parser_impl.h"

#include <hexutils.h>

#include <iostream>
#include <vector>

#include "crypto_helper.h"
#include "gmock/gmock.h"
#include "parser.h"
#include "parser_txdef.h"

using namespace std;

TEST(SCALE, ReadBytes) {
    parser_context_t ctx;
    parser_tx_t tx_obj;
    parser_error_t err;
    uint8_t buffer[100];
    auto bufferLen = parseHexString(buffer, sizeof(buffer),
                                    "45"
                                    "123456"
                                    "12345678901234567890");

    parser_parse(&ctx, buffer, bufferLen, &tx_obj);

    // uint8_t bytesArray[100] = {0};
    // err = _readBytes(&ctx, bytesArray, 1);
    // EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    // EXPECT_EQ(bytesArray[0], 0x45);

    // uint8_t testArray[3] = {0x12, 0x34, 0x56};
    // err = _readBytes(&ctx, bytesArray+1, 3);
    // EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    // for (uint8_t i = 0; i < 3; i++) {
    //     EXPECT_EQ(testArray[i], bytesArray[i+1]);
    // }

    // uint8_t testArray2[10] = {0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x34, 0x56, 0x78, 0x90};
    // err = _readBytes(&ctx, bytesArray+4, 10);
    // EXPECT_EQ(err, parser_ok) << parser_getErrorDescription(err);
    // for (uint8_t i = 0; i < 10; i++) {
    //     EXPECT_EQ(testArray2[i], bytesArray[i+4]);
    // }
}

TEST(CONVERT, EVM2SS58) {
    uint8_t evm[20] = {0x95, 0xe5, 0xe3, 0xc1, 0xbd, 0xd9, 0x2c, 0xd4, 0xa0, 0xc1,
                       0x4c, 0x62, 0x48, 0x0d, 0xb5, 0x86, 0x79, 0x46, 0x28, 0x1d};
    char ss58_address[60];
    const char *expected_address = "5DtxSQCujadnQKSZFGEtVvSed2BCsNEU3NQf5Bz5WE2eV1fs";
    uint16_t ss58_len = 60;
    convertEvmToSS58(evm, 20, (uint8_t *)ss58_address, &ss58_len);

    // Ensure null-terminated string
    ss58_address[sizeof(ss58_address) - 1] = '\0';

    // Check if the result matches the expected address
    ASSERT_STREQ(ss58_address, expected_address);
}
