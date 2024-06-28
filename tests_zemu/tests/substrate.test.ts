/** ******************************************************************************
 *  (c) 2024 Zondax GmbH
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

import Zemu, { ButtonKind } from '@zondax/zemu'
import { PeaqApp } from '@zondax/ledger-peaq'
import { models, defaultOptions, PATH, EXPECTED_SUBSTRATE_ADDR, EXPECTED_SUBSTRATE_PK, ETH_PATH, EXPECTED_ETH_PK } from './common'

// @ts-expect-error missing typings
import ed25519 from 'ed25519-supercop'
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

import {
  txParachainStaking_delegate_another_candidate,
  txParachainStaking_execute_leave_candidates,
  txParachainStaking_force_new_round,
  txParachainStaking_set_max_selected_candidates,
  txVesting_merge_schedules,
  txVesting_vest_other,
  txVesting_vested_transfer,
} from './zemu_blobs'

jest.setTimeout(180000)

const TXNS = [
  {
    name: 'delegate_another_candidate',
    blob: txParachainStaking_delegate_another_candidate,
  },
  {
    name: 'execute_leave_candidates',
    blob: txParachainStaking_execute_leave_candidates,
  },
  {
    name: 'force_new_round',
    blob: txParachainStaking_force_new_round,
  },
  {
    name: 'set_max_selected_candidates',
    blob: txParachainStaking_set_max_selected_candidates,
  },
  {
    name: 'vested_transfer',
    blob: txVesting_vested_transfer,
  },
  {
    name: 'merge_schedules',
    blob: txVesting_merge_schedules,
  },
  {
    name: 'vest_other',
    blob: txVesting_vest_other,
  },
]

describe.each(models)('Substrate', function (m) {
  test.concurrent('can start and stop container', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.concurrent('get address', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PeaqApp(sim.getTransport())

      const resp = await app.getAddress(ETH_PATH, false, true)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      console.log(resp.address)
      console.log(resp.pubKey)

      expect(resp.address).toEqual(EXPECTED_SUBSTRATE_ADDR)
      expect(resp.pubKey).toEqual(EXPECTED_SUBSTRATE_PK)
    } finally {
      await sim.close()
    }
  })

  test.concurrent('show address', async function () {
    const sim = new Zemu(m.path)
    try {
      await sim.start({
        ...defaultOptions,
        model: m.name,
        approveKeyword: m.name === 'stax' ? 'QR' : '',
        approveAction: ButtonKind.ApproveTapButton,
      })
      const app = new PeaqApp(sim.getTransport())

      const respRequest = app.getAddress(ETH_PATH, true, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address`)

      const resp = await respRequest

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      expect(resp.address).toEqual(EXPECTED_SUBSTRATE_ADDR)
      expect(resp.pubKey).toEqual(EXPECTED_SUBSTRATE_PK)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(TXNS)('sign transaction:  $name', async function (data) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PeaqApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(data.blob, 'hex')

      const responseAddr = await app.getAddress(PATH)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(PATH, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${data.name}`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.subarray(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.concurrent.each(TXNS)('sign transaction expert:  $name', async function (data) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = new PeaqApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(data.blob, 'hex')

      //Change to expert mode so we can skip fields
      await sim.toggleExpertMode()

      const responseAddr = await app.getAddress(PATH)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(PATH, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${data.name}-expert`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.subarray(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})
