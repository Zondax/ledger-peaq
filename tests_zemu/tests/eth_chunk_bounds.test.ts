/** ******************************************************************************
 *  (c) 2018 - 2026 Zondax AG
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
 ******************************************************************************* */

import Zemu from '@zondax/zemu'
import { defaultOptions, models } from './common'
import {
  APDU_CODE_DATA_INVALID,
  APDU_CODE_OK,
  APDU_CODE_TX_NOT_INITIALIZED,
  APDU_CODE_WRONG_LENGTH,
  CLA_ETH,
  INS_SIGN_ETH,
  INS_SIGN_PERSONAL_MESSAGE,
  P1_ETH_FIRST,
  P1_ETH_MORE,
  eip191FirstChunk,
  ethFirstChunk,
} from './apdu_helpers'

jest.setTimeout(90000)

// The PEAQ-C01 pattern on INS_SIGN_ETH: the outstanding length comes from the
// RLP header of the first chunk. A chunk longer than what is outstanding used to
// be truncated while the completion check wrapped, so the stream only finished
// after an extra empty chunk, and the header itself was read past the bytes that
// arrived. These drive raw APDUs because hw-app-eth always chunks exactly.

function statusOf(response: Buffer): number {
  return response.readUInt16BE(response.length - 2)
}

describe.each(models)('ETH chunk length bounds', function (m) {
  test.concurrent('first chunk longer than the RLP length is refused', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const transport = sim.getTransport()

      // 0xc5 declares a 6-byte transaction (marker + 5); send 10.
      const rlp = Buffer.from('c5' + '01'.repeat(9), 'hex')
      await expect(transport.send(CLA_ETH, INS_SIGN_ETH, P1_ETH_FIRST, 0, ethFirstChunk(rlp))).rejects.toMatchObject({
        statusCode: APDU_CODE_WRONG_LENGTH,
      })

      await sim.waitUntilScreenIs(sim.getMainMenuSnapshot())
    } finally {
      await sim.close()
    }
  })

  test.concurrent('continuation chunk longer than the remainder is refused', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const transport = sim.getTransport()

      // 0xf8 0x40 declares 2 + 64 bytes; send the header and 8 payload bytes,
      // leaving 56 outstanding.
      const rlp = Buffer.from('f840' + '01'.repeat(8), 'hex')
      const first = await transport.send(CLA_ETH, INS_SIGN_ETH, P1_ETH_FIRST, 0, ethFirstChunk(rlp))
      expect(statusOf(first)).toEqual(APDU_CODE_OK)

      await expect(transport.send(CLA_ETH, INS_SIGN_ETH, P1_ETH_MORE, 0, Buffer.alloc(120, 0x02))).rejects.toMatchObject({
        statusCode: APDU_CODE_WRONG_LENGTH,
      })

      await sim.waitUntilScreenIs(sim.getMainMenuSnapshot())
    } finally {
      await sim.close()
    }
  })

  test.concurrent('RLP header that runs past the chunk is refused', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const transport = sim.getTransport()

      // A type byte with no list marker after it.
      await expect(transport.send(CLA_ETH, INS_SIGN_ETH, P1_ETH_FIRST, 0, ethFirstChunk(Buffer.from('02', 'hex')))).rejects.toMatchObject({
        statusCode: APDU_CODE_DATA_INVALID,
      })

      // 0xf9 announces two length bytes; only one arrives.
      await expect(transport.send(CLA_ETH, INS_SIGN_ETH, P1_ETH_FIRST, 0, ethFirstChunk(Buffer.from('f901', 'hex')))).rejects.toMatchObject(
        { statusCode: APDU_CODE_DATA_INVALID },
      )

      await sim.waitUntilScreenIs(sim.getMainMenuSnapshot())
    } finally {
      await sim.close()
    }
  })

  // Both signing commands share one chunking session. An empty INS 0x08
  // continuation used to complete a partial INS 0x04 stream and send it to
  // review as a personal message.
  test.concurrent('continuation under the other signing INS is refused', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const transport = sim.getTransport()

      const ethFirst = await transport.send(
        CLA_ETH,
        INS_SIGN_ETH,
        P1_ETH_FIRST,
        0,
        ethFirstChunk(Buffer.from('f840' + '01'.repeat(8), 'hex')),
      )
      expect(statusOf(ethFirst)).toEqual(APDU_CODE_OK)
      await expect(transport.send(CLA_ETH, INS_SIGN_PERSONAL_MESSAGE, P1_ETH_MORE, 0, Buffer.alloc(0))).rejects.toMatchObject({
        statusCode: APDU_CODE_TX_NOT_INITIALIZED,
      })

      const message = Buffer.from('a'.repeat(64), 'utf8')
      const msgFirst = await transport.send(
        CLA_ETH,
        INS_SIGN_PERSONAL_MESSAGE,
        P1_ETH_FIRST,
        0,
        eip191FirstChunk(message.length, message.subarray(0, 8)),
      )
      expect(statusOf(msgFirst)).toEqual(APDU_CODE_OK)
      await expect(transport.send(CLA_ETH, INS_SIGN_ETH, P1_ETH_MORE, 0, message.subarray(8, 16))).rejects.toMatchObject({
        statusCode: APDU_CODE_TX_NOT_INITIALIZED,
      })

      await sim.waitUntilScreenIs(sim.getMainMenuSnapshot())
    } finally {
      await sim.close()
    }
  })
})
