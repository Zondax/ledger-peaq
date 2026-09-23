/*******************************************************************************
 *   (c) 2018 - 2026 Zondax AG
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

#include "evm_utils.h"

#include <cstdint>
#include <vector>

#include "gmock/gmock.h"

// get_tx_rlp_len reads the optional type byte, the RLP list marker and any
// length bytes the marker announces. The first ETH chunk hands it only the bytes
// that arrived, while the global tx buffer behind them still holds whatever an
// earlier command left there, so every header byte must be bounded by len.

namespace {

struct RlpHeader {
    rlp_error_t err;
    uint64_t read;
    uint64_t to_read;
};

RlpHeader header(const std::vector<uint8_t> &buffer, uint32_t len) {
    RlpHeader out = {rlp_ok, 0, 0};
    out.err = get_tx_rlp_len(buffer.data(), len, &out.read, &out.to_read);
    return out;
}

}  // namespace

TEST(GetTxRlpLen, ShortList) {
    const auto h = header({0xc5}, 1);
    EXPECT_EQ(h.err, rlp_ok);
    EXPECT_EQ(h.read, 1u);
    EXPECT_EQ(h.to_read, 5u);
}

TEST(GetTxRlpLen, TypedLongList) {
    const auto h = header({0x02, 0xf8, 0x40}, 3);
    EXPECT_EQ(h.err, rlp_ok);
    EXPECT_EQ(h.read, 3u);
    EXPECT_EQ(h.to_read, 0x40u);
}

TEST(GetTxRlpLen, LengthBytesEndingAtLen) {
    const auto h = header({0xf9, 0x01, 0x00}, 3);
    EXPECT_EQ(h.err, rlp_ok);
    EXPECT_EQ(h.read, 3u);
    EXPECT_EQ(h.to_read, 0x100u);
}

TEST(GetTxRlpLen, EmptyIsNoData) {
    EXPECT_EQ(header({0xc5}, 0).err, rlp_no_data);
}

TEST(GetTxRlpLen, TypeByteWithoutMarkerIsNoData) {
    // The byte after len would otherwise be taken as the marker.
    EXPECT_EQ(header({0x02, 0xc5}, 1).err, rlp_no_data);
}

TEST(GetTxRlpLen, LengthBytesPastLenAreNoData) {
    // 0xf9 announces two length bytes; only one is inside len.
    EXPECT_EQ(header({0xf9, 0x01, 0xff}, 2).err, rlp_no_data);
    EXPECT_EQ(header({0x02, 0xfa, 0x01, 0x02, 0x03}, 4).err, rlp_no_data);
    // The marker alone, with none of its length bytes.
    EXPECT_EQ(header({0xf8, 0x40}, 1).err, rlp_no_data);
}
