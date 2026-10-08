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

// Raw APDU helpers for tests that must send what the JS client never would
// (mismatched lengths, truncated headers, interleaved commands). Zemu's transport
// raises on any status word other than 0x9000, so refusals are asserted on the
// rejection's statusCode.

import { ETH_PATH } from './common'

export const CLA_ETH = 0xe0
export const INS_SIGN_ETH = 0x04
export const INS_SIGN_PERSONAL_MESSAGE = 0x08
export const P1_ETH_FIRST = 0x00
export const P1_ETH_MORE = 0x80

export const APDU_CODE_OK = 0x9000
export const APDU_CODE_WRONG_LENGTH = 0x6700
export const APDU_CODE_DATA_INVALID = 0x6984
export const APDU_CODE_TX_NOT_INITIALIZED = 0x6987

// hw-app-eth serializes the path as a leading count followed by big-endian u32s.
export function serializeEthPath(path: string = ETH_PATH): Buffer {
  const components = path
    .split('/')
    .slice(1)
    .map(component => {
      const hardened = component.endsWith("'")
      const index = parseInt(hardened ? component.slice(0, -1) : component, 10)
      return hardened ? (index | 0x80000000) >>> 0 : index >>> 0
    })

  const out = Buffer.alloc(1 + components.length * 4)
  out.writeUInt8(components.length, 0)
  components.forEach((value, i) => out.writeUInt32BE(value, 1 + i * 4))
  return out
}

// EIP-191 first chunk: [path][declared length as u32 BE][payload]
export function eip191FirstChunk(declaredLength: number, payload: Buffer): Buffer {
  const declared = Buffer.alloc(4)
  declared.writeUInt32BE(declaredLength >>> 0, 0)
  return Buffer.concat([serializeEthPath(), declared, payload] as unknown as Uint8Array[])
}

// ETH first chunk: [path][start of the RLP-encoded transaction]
export function ethFirstChunk(rlp: Buffer): Buffer {
  return Buffer.concat([serializeEthPath(), rlp] as unknown as Uint8Array[])
}
