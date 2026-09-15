/** ******************************************************************************
 *  (c) 2018 - 2024 Zondax AG
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
import { PeaqApp } from '@zondax/ledger-peaq'
import { ETH_PATH, defaultOptions, models } from './common'
import {
  APDU_CODE_OK,
  APDU_CODE_WRONG_LENGTH,
  CLA_ETH,
  INS_SIGN_PERSONAL_MESSAGE,
  P1_ETH_FIRST,
  P1_ETH_MORE,
  eip191FirstChunk,
} from './apdu_helpers'
import { ec } from 'elliptic'

jest.setTimeout(90000)

const sha3 = require('js-sha3')

const SIGN_TEST_DATA = [
  {
    name: 'personal_sign_msg',
    message: Buffer.from('Hello World!', 'utf8'),
  },
  {
    name: 'personal_sign_big_msg',
    message: Buffer.from('Just a big dummy message to be sign. To test if ew are parsing the chunks in the right way. By: Zondax', 'utf8'),
  },
  // Any byte outside printable ASCII switches the review to hex. Rendered as
  // text, the NUL would end the string early and hide the rest of a message
  // that is still signed in full, and a newline would not show at all.
  {
    name: 'personal_sign_msg_nul',
    message: Buffer.from('Hello\x00World! everything after the NUL is signed too', 'utf8'),
  },
  {
    name: 'personal_sign_msg_newline',
    message: Buffer.from('Hello\nWorld!', 'utf8'),
  },
]

describe.each(models)('EIP191', function (m) {
  test.concurrent.each(SIGN_TEST_DATA)('sign transaction:  $name', async function (data) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PeaqApp(sim.getTransport())
      const msgData = data.message

      // Put the app in blindsign mode
      await sim.toggleBlindSigning()

      // eth pubkey used for ETH_PATH: "m/44'/60'/0'/0'/5"
      // to verify signature
      const EXPECTED_PUBLIC_KEY = '024f1dd50f180bfd546339e75410b127331469837fa618d950f7cfb8be351b0020'

      // do not wait here..
      const signatureRequest = app.signPersonalMessage(ETH_PATH, msgData.toString('hex'))
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-eth-${data.name}`, true, 0, 15000, true)

      let resp = await signatureRequest
      console.log(resp)

      const header = Buffer.from('\x19Ethereum Signed Message:\n', 'utf8')
      const msgLengthString = String(msgData.length)
      const msg = Buffer.concat([header, Buffer.from(msgLengthString, 'utf8'), msgData] as unknown as Uint8Array[])
      const msgHash = sha3.keccak256(msg)

      const signature_obj = {
        r: Buffer.from(resp.r, 'hex'),
        s: Buffer.from(resp.s, 'hex'),
      }

      // Verify signature
      const EC = new ec('secp256k1')
      const signatureOK = EC.verify(msgHash, signature_obj, Buffer.from(EXPECTED_PUBLIC_KEY, 'hex'), 'hex')
      expect(signatureOK).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})

// PEAQ-C01: the host declares a 32-bit message length in the first chunk and
// then streams the body. Both places that decremented the outstanding counter
// used to do so without proving the chunk fits what is left, so a chunk longer
// than the declaration wrapped it to near UINT32_MAX and left the command
// waiting on bytes it would never ask for. These drive the raw APDUs directly
// because the JS client derives the length from the payload and so can never
// produce the mismatch.

describe.each(models)('EIP191 chunk length bounds', function (m) {
  test.concurrent('first chunk longer than the declared length is refused', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const transport = sim.getTransport()

      // Declare 4 bytes, then hand over 32. The old arithmetic computed
      // 4 - 32 and wrapped.
      const payload = Buffer.from('Hello World! and then a great deal more', 'utf8').subarray(0, 32)
      await expect(transport.send(CLA_ETH, INS_SIGN_PERSONAL_MESSAGE, P1_ETH_FIRST, 0, eip191FirstChunk(4, payload))).rejects.toMatchObject(
        { statusCode: APDU_CODE_WRONG_LENGTH },
      )

      // Refused before anything is drawn: the device never left its main menu.
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

      // Declare 64 bytes and send 8, leaving 56 outstanding.
      const message = Buffer.from('a'.repeat(64), 'utf8')
      const first = await transport.send(
        CLA_ETH,
        INS_SIGN_PERSONAL_MESSAGE,
        P1_ETH_FIRST,
        0,
        eip191FirstChunk(message.length, message.subarray(0, 8)),
      )
      expect(first.readUInt16BE(first.length - 2)).toEqual(APDU_CODE_OK)

      // Now send 120, well past the 56 that are still outstanding.
      const overlong = Buffer.from('b'.repeat(120), 'utf8')
      await expect(transport.send(CLA_ETH, INS_SIGN_PERSONAL_MESSAGE, P1_ETH_MORE, 0, overlong)).rejects.toMatchObject({
        statusCode: APDU_CODE_WRONG_LENGTH,
      })

      await sim.waitUntilScreenIs(sim.getMainMenuSnapshot())
    } finally {
      await sim.close()
    }
  })

  test.concurrent('declared length of zero is refused', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const transport = sim.getTransport()

      // An empty message used to reach an empty review and only fail with
      // SIGN_VERIFY_ERROR after the user approved it.
      await expect(
        transport.send(CLA_ETH, INS_SIGN_PERSONAL_MESSAGE, P1_ETH_FIRST, 0, eip191FirstChunk(0, Buffer.alloc(0))),
      ).rejects.toMatchObject({ statusCode: APDU_CODE_WRONG_LENGTH })

      await sim.waitUntilScreenIs(sim.getMainMenuSnapshot())
    } finally {
      await sim.close()
    }
  })
})
