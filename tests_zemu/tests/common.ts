import { IDeviceModel, DEFAULT_START_OPTIONS } from '@zondax/zemu'

import { resolve } from 'path'

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = resolve('../app/output/app_s.elf')
const APP_PATH_X = resolve('../app/output/app_x.elf')
const APP_PATH_SP = resolve('../app/output/app_s2.elf')
const APP_PATH_ST = resolve('../app/output/app_stax.elf')

export const models: IDeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
  { name: 'stax', prefix: 'ST', path: APP_PATH_ST },
]

export const ETH_PATH = "m/44'/60'/0'/0/0"

export const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}
export const EXPECTED_ETH_PK =
  '041853d93524119eeb31ab0b06f1dcb068f84943bb230dfa10b1292f47af6435757e8c55a1637d935c4930062ce3ef860941484ce67525ca1adf099badc83d2442'
export const EXPECTED_ETH_ADDRESS = '0x95e5e3c1bdd92cd4a0c14c62480db5867946281d'

export const EXPECTED_SUBSTRATE_ADDR = '5DtxSQCujadnQKSZFGEtVvSed2BCsNEU3NQf5Bz5WE2eV1fs'
export const EXPECTED_SUBSTRATE_PK = '021853d93524119eeb31ab0b06f1dcb068f84943bb230dfa10b1292f47af643575'
