# Peaq 1.17.x

## System

| Name                    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                         |
| ----------------------- | ------ | --------- | ---------------- | ------- | --------------------------------- |
| Remark                  |        |           |                  |         | `Bytes`remark<br/>                |
| Set heap pages          |        |           |                  |         | `u64`pages<br/>                   |
| Set code                |        |           |                  |         | `Bytes`code<br/>                  |
| Set code without checks |        |           |                  |         | `Vecu8`code<br/>                  |
| Set storage             |        |           |                  |         | `VecKeyValue`items<br/>           |
| Kill storage            |        |           |                  |         | `VecKey`keys<br/>                 |
| Kill prefix             |        |           |                  |         | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        |           |                  |         | `Bytes`remark<br/>                |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Balances

| Name                   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| ---------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Transfer allow death   |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance deprecated |        |           |                  |         | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`old_reserved<br/> |
| Force transfer         |        |           |                  |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive    |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all           |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve        |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |
| Upgrade accounts       |        |           |                  |         | `VecAccountId`who<br/>                                                                     |
| Transfer               |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Force set balance      |        |           |                  |         | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                                  |

## Sudo

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| --------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Sudo                  |        |           |                  |         | `Call`call<br/>                             |
| Sudo unchecked weight |        |           |                  |         | `Call`call<br/>`Weight`weight<br/>          |
| Set key               |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>              |
| Sudo as               |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Call`call<br/> |

## Contracts

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                       |
| -------------------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Call old weight                  |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`data<br/>            |
| Instantiate with code old weight |        |           |                  |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`code<br/>`Bytes`data<br/>`Bytes`salt<br/>         |
| Instantiate old weight           |        |           |                  |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/> |
| Upload code                      |        |           |                  |         | `Bytes`code<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Determinism`determinism<br/>                                                                 |
| Remove code                      |        |           |                  |         | `CodeHash`code_hash<br/>                                                                                                                                        |
| Set code                         |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CodeHash`code_hash<br/>                                                                                                           |
| Call                             |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`data<br/>                |
| Instantiate with code            |        |           |                  |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Bytes`code<br/>`Bytes`data<br/>`Bytes`salt<br/>             |
| Instantiate                      |        |           |                  |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/>     |

## Utility

| Name          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                       |
| ------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------- |
| Batch         |        |           |                  |         | `VecCall`calls<br/>                             |
| As derivative |        |           |                  |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     |        |           |                  |         | `VecCall`calls<br/>                             |
| Dispatch as   |        |           |                  |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   |        |           |                  |         | `VecCall`calls<br/>                             |
| With weight   |        |           |                  |         | `Call`call<br/>`Weight`weight<br/>              |

## Treasury

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                       |
| ---------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------- |
| Propose spend    |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Reject proposal  |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |
| Approve proposal |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |
| Spend            |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Remove approval  |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |

## Council

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |

## Ethereum

| Name     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                     |
| -------- | ------ | --------- | ---------------- | ------- | ----------------------------- |
| Transact |        |           |                  |         | `Transaction`transaction<br/> |

## EVM

| Name     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                            |
| -------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Withdraw |        |           |                  |         | `H160`address<br/>`Balance`amount<br/>                                                                                                                                                                               |
| Call     |        |           |                  |         | `H160`source<br/>`H160`target<br/>`Vecu8`input<br/>`U256`value<br/>`u64`gas_limit<br/>`U256`max_fee_per_gas<br/>`OptionU256`max_priority_fee_per_gas<br/>`OptionU256`nonce<br/>`VecTupleH160VecH256`access_list<br/> |
| Create   |        |           |                  |         | `H160`source<br/>`Vecu8`init<br/>`U256`value<br/>`u64`gas_limit<br/>`U256`max_fee_per_gas<br/>`OptionU256`max_priority_fee_per_gas<br/>`OptionU256`nonce<br/>`VecTupleH160VecH256`access_list<br/>                   |
| Create2  |        |           |                  |         | `H160`source<br/>`Vecu8`init<br/>`H256`salt<br/>`U256`value<br/>`u64`gas_limit<br/>`U256`max_fee_per_gas<br/>`OptionU256`max_priority_fee_per_gas<br/>`OptionU256`nonce<br/>`VecTupleH160VecH256`access_list<br/>    |

## DynamicFee

| Name                      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments         |
| ------------------------- | ------ | --------- | ---------------- | ------- | ----------------- |
| Note min gas price target |        |           |                  |         | `U256`target<br/> |

## BaseFee

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------ |
| Set base fee per gas |        |           |                  |         | `U256`fee<br/>           |
| Set elasticity       |        |           |                  |         | `Permill`elasticity<br/> |

## InflationManager

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---------------- | ------ | --------- | ---------------- | ------- | -------------------- |
| Transfer all pot |        |           |                  |         | `AccountId`dest<br/> |

## Session

| Name       | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                        |
| ---------- | ------ | --------- | ---------------- | ------- | -------------------------------- |
| Set keys   |        |           |                  |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys |        |           |                  |         |                                  |

## ParachainStaking

| Name                        | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                     |
| --------------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------- |
| Force new round             |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                               |
| Set max selected candidates |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                               |
| Set blocks per round        |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`new\_<br/>                                       |
| Set max candidate stake     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`new\_<br/>                                           |
| Force remove candidate      |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`collator<br/>                     |
| Join candidates             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`stake<br/>                                           |
| Init leave candidates       |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                               |
| Execute leave candidates    |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`collator<br/>                     |
| Cancel leave candidates     |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                               |
| Candidate stake more        |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`more<br/>                                            |
| Candidate stake less        |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`less<br/>                                            |
| Join delegators             |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`collator<br/>`Balance`amount<br/> |
| Delegate another candidate  |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`collator<br/>`Balance`amount<br/> |
| Leave delegators            |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                               |
| Revoke delegation           |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`collator<br/>                     |
| Delegator stake more        |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`candidate<br/>`Balance`more<br/>  |
| Delegator stake less        |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`candidate<br/>`Balance`less<br/>  |
| Unlock unstaked             |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`target<br/>                       |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                    |
| ------------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------- |
| Set validation data      |        |           |                  |         | `ParachainInherentData`data<br/>             |
| Sudo send upward message |        |           |                  |         | `UpwardMessage`message<br/>                  |
| Authorize upgrade        |        |           |                  |         | `Hash`code_hash<br/>`bool`check_version<br/> |
| Enact authorized upgrade |        |           |                  |         | `Vecu8`code<br/>                             |

## BlockReward

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                           |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------- |
| Set configuration |        |           |                  |         | `RewardDistributionConfig`reward_distro_params<br/> |

## StakingCoefficientRewardCalculator

| Name            | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| --------------- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set coefficient |        |           |                  |         | `u8`coefficient<br/> |

## XcmpQueue

| Name                              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| --------------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Service overweight                |        |           |                  |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |
| Suspend xcm execution             |        |           |                  |         |                                                      |
| Resume xcm execution              |        |           |                  |         |                                                      |
| Update suspend threshold          |        |           |                  |         | `u32`new\_<br/>                                      |
| Update drop threshold             |        |           |                  |         | `u32`new\_<br/>                                      |
| Update resume threshold           |        |           |                  |         | `u32`new\_<br/>                                      |
| Update threshold weight           |        |           |                  |         | `Weight`new\_<br/>                                   |
| Update weight restrict decay      |        |           |                  |         | `Weight`new\_<br/>                                   |
| Update xcmp max individual weight |        |           |                  |         | `Weight`new\_<br/>                                   |

## PolkadotXcm

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |                  |         | `BoxVersionedXcmTasSysConfigRuntimeCall`message<br/>`Weight`max_weight<br/>                                                                                               |
| Force xcm version                |        |           |                  |         | `BoxMultiLocation`location<br/>`XcmVersion`xcm_version<br/>                                                                                                               |
| Force default xcm version        |        |           |                  |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |                  |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |                  |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Force suspension                 |        |           |                  |         | `bool`suspended<br/>                                                                                                                                                      |

## DmpQueue

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| ------------------ | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Service overweight |        |           |                  |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |

## XTokens

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                 |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Transfer                     |        |           |                  |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                   |
| Transfer multiasset          |        |           |                  |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                                 |
| Transfer with fee            |        |           |                  |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`Balance`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>  |
| Transfer multiasset with fee |        |           |                  |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiAsset`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/> |
| Transfer multicurrencies     |        |           |                  |         | `VecTupleCurrencyIdBalance`currencies<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>       |
| Transfer multiassets         |        |           |                  |         | `BoxVersionedMultiAssets`assets<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>             |

## ZenlinkProtocol

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Set fee receiver             |        |           |                  |         | `OptionLookupasStaticLookupSource`send_to<br/>                                                                                                                                                                                                                         |
| Set fee point                |        |           |                  |         | `u8`fee_point<br/>                                                                                                                                                                                                                                                     |
| Transfer                     |        |           |                  |         | `AssetId`asset_id<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu128`amount<br/>                                                                                                                                                                               |
| Create pair                  |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>                                                                                                                                                                                                                             |
| Add liquidity                |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`amount_0_desired<br/>`Compactu128`amount_1_desired<br/>`Compactu128`amount_0_min<br/>`Compactu128`amount_1_min<br/>`Compactu32`deadline<br/>                                                                    |
| Remove liquidity             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`liquidity<br/>`Compactu128`amount_0_min<br/>`Compactu128`amount_1_min<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu32`deadline<br/>                                                                   |
| Swap exact assets for assets |        |           |                  |         | `Compactu128`amount_in<br/>`Compactu128`amount_out_min<br/>`VecAssetId`path<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu32`deadline<br/>                                                                                                                    |
| Swap assets for exact assets |        |           |                  |         | `Compactu128`amount_out<br/>`Compactu128`amount_in_max<br/>`VecAssetId`path<br/>`LookupasStaticLookupSource`recipient<br/>`Compactu32`deadline<br/>                                                                                                                    |
| Bootstrap create             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`target_supply_0<br/>`Compactu128`target_supply_1<br/>`Compactu128`capacity_supply_0<br/>`Compactu128`capacity_supply_1<br/>`Compactu32`end<br/>`VecAssetId`rewards<br/>`VecTupleAssetIdAssetBalance`limits<br/> |
| Bootstrap contribute         |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`amount_0_contribute<br/>`Compactu128`amount_1_contribute<br/>`Compactu32`deadline<br/>                                                                                                                          |
| Bootstrap claim              |        |           |                  |         | `LookupasStaticLookupSource`recipient<br/>`AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu32`deadline<br/>                                                                                                                                                          |
| Bootstrap end                |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>                                                                                                                                                                                                                             |
| Bootstrap update             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`Compactu128`target_supply_0<br/>`Compactu128`target_supply_1<br/>`Compactu128`capacity_supply_0<br/>`Compactu128`capacity_supply_1<br/>`Compactu32`end<br/>`VecAssetId`rewards<br/>`VecTupleAssetIdAssetBalance`limits<br/> |
| Bootstrap refund             |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>                                                                                                                                                                                                                             |
| Bootstrap charge reward      |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`VecTupleAssetIdAssetBalance`charge_rewards<br/>                                                                                                                                                                             |
| Bootstrap withdraw reward    |        |           |                  |         | `AssetId`asset_0<br/>`AssetId`asset_1<br/>`LookupasStaticLookupSource`recipient<br/>                                                                                                                                                                                   |

## Assets

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                                        |
| --------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`admin<br/>`Balance`min_balance<br/>                                                                                                                                                 |
| Force create          |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`bool`is_sufficient<br/>`CompactBalance`min_balance<br/>                                                                                                                  |
| Start destroy         |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Destroy accounts      |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Destroy approvals     |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Finish destroy        |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Mint                  |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`beneficiary<br/>`CompactBalance`amount<br/>                                                                                                                                         |
| Burn                  |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>`CompactBalance`amount<br/>                                                                                                                                                 |
| Transfer              |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Transfer keep alive   |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Force transfer        |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                                                                                                 |
| Freeze                |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Thaw                  |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Freeze asset          |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Thaw asset            |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Transfer ownership    |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                                          |
| Set team              |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                                                           |
| Set metadata          |        |           |                  |         | `AssetIdParameter`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>                                                                                                                                                     |
| Clear metadata        |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Force set metadata    |        |           |                  |         | `AssetIdParameter`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>`bool`is_frozen<br/>                                                                                                                                 |
| Force clear metadata  |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Force asset status    |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`CompactBalance`min_balance<br/>`bool`is_sufficient<br/>`bool`is_frozen<br/> |
| Approve transfer      |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`delegate<br/>`CompactBalance`amount<br/>                                                                                                                                            |
| Cancel approval       |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                                                       |
| Force cancel approval |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                         |
| Transfer approved     |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`destination<br/>`CompactBalance`amount<br/>                                                                                                           |
| Touch                 |        |           |                  |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Refund                |        |           |                  |         | `AssetIdParameter`id<br/>`bool`allow_burn<br/>                                                                                                                                                                                   |
| Set min balance       |        |           |                  |         | `AssetIdParameter`id<br/>`Balance`min_balance<br/>                                                                                                                                                                               |
| Touch other           |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Refund other          |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Block                 |        |           |                  |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |

## XcAssetConfig

| Name                           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                        |
| ------------------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------- |
| Register asset location        |        |           |                  |         | `BoxVersionedMultiLocation`asset_location<br/>`AssetId`asset_id<br/>             |
| Set asset units per second     |        |           |                  |         | `BoxVersionedMultiLocation`asset_location<br/>`Compactu128`units_per_second<br/> |
| Change existing asset location |        |           |                  |         | `BoxVersionedMultiLocation`new_asset_location<br/>`AssetId`asset_id<br/>         |
| Remove payment asset           |        |           |                  |         | `BoxVersionedMultiLocation`asset_location<br/>                                   |
| Remove asset                   |        |           |                  |         | `AssetId`asset_id<br/>                                                           |

## AddressUnification

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                       |
| --------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------- |
| Claim account         |        |           |                  |         | `EvmAddress`evm_address<br/>`Eip712Signature`eth_signature<br/> |
| Claim default account |        |           |                  |         |                                                                 |

## Vesting

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                |
| --------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------------- |
| Vest                  |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                          |
| Vest other            |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |

## PeaqDid

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                   |
| ---------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------- |
| Add attribute    |        |           |                  |         | `AccountId`did_account<br/>`BoundedVecu8`name<br/>`BoundedVecu8`value<br/>`OptionBlockNumber`valid_for<br/> |
| Update attribute |        |           |                  |         | `AccountId`did_account<br/>`BoundedVecu8`name<br/>`BoundedVecu8`value<br/>`OptionBlockNumber`valid_for<br/> |
| Read attribute   |        |           |                  |         | `AccountId`did_account<br/>`BoundedVecu8`name<br/>                                                          |
| Remove attribute |        |           |                  |         | `AccountId`did_account<br/>`BoundedVecu8`name<br/>                                                          |

## Transaction

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                               |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| Service requested |        |           |                  |         | `AccountId`provider<br/>`Balance`token_deposited<br/>                                                                                   |
| Service delivered |        |           |                  |         | `AccountId`consumer<br/>`DeliveredInfoBalanceOfTHashBlockNumber`refund_info<br/>`DeliveredInfoBalanceOfTHashBlockNumber`spent_info<br/> |

## Multisig

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                               |
| -------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        |           |                  |         | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## PeaqRbac

| Name                        | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                           |
| --------------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------- |
| Fetch role                  |        |           |                  |         | `AccountId`owner<br/>`EntityId`entity<br/>          |
| Fetch roles                 |        |           |                  |         | `AccountId`owner<br/>                               |
| Add role                    |        |           |                  |         | `EntityId`role_id<br/>`BoundedVecu8`name<br/>       |
| Update role                 |        |           |                  |         | `EntityId`role_id<br/>`BoundedVecu8`name<br/>       |
| Disable role                |        |           |                  |         | `EntityId`role_id<br/>                              |
| Fetch user roles            |        |           |                  |         | `AccountId`owner<br/>`EntityId`user_id<br/>         |
| Assign role to user         |        |           |                  |         | `EntityId`role_id<br/>`EntityId`user_id<br/>        |
| Unassign role to user       |        |           |                  |         | `EntityId`role_id<br/>`EntityId`user_id<br/>        |
| Fetch permission            |        |           |                  |         | `AccountId`owner<br/>`EntityId`permission_id<br/>   |
| Fetch permissions           |        |           |                  |         | `AccountId`owner<br/>                               |
| Add permission              |        |           |                  |         | `EntityId`permission_id<br/>`BoundedVecu8`name<br/> |
| Update permission           |        |           |                  |         | `EntityId`permission_id<br/>`BoundedVecu8`name<br/> |
| Disable permission          |        |           |                  |         | `EntityId`permission_id<br/>                        |
| Fetch role permissions      |        |           |                  |         | `AccountId`owner<br/>`EntityId`role_id<br/>         |
| Assign permission to role   |        |           |                  |         | `EntityId`permission_id<br/>`EntityId`role_id<br/>  |
| Unassign permission to role |        |           |                  |         | `EntityId`permission_id<br/>`EntityId`role_id<br/>  |
| Fetch group                 |        |           |                  |         | `AccountId`owner<br/>`EntityId`group_id<br/>        |
| Fetch groups                |        |           |                  |         | `AccountId`owner<br/>                               |
| Add group                   |        |           |                  |         | `EntityId`group_id<br/>`BoundedVecu8`name<br/>      |
| Update group                |        |           |                  |         | `EntityId`group_id<br/>`BoundedVecu8`name<br/>      |
| Disable group               |        |           |                  |         | `EntityId`group_id<br/>                             |
| Assign role to group        |        |           |                  |         | `EntityId`role_id<br/>`EntityId`group_id<br/>       |
| Unassign role to group      |        |           |                  |         | `EntityId`role_id<br/>`EntityId`group_id<br/>       |
| Fetch group roles           |        |           |                  |         | `AccountId`owner<br/>`EntityId`group_id<br/>        |
| Assign user to group        |        |           |                  |         | `EntityId`user_id<br/>`EntityId`group_id<br/>       |
| Unassign user to group      |        |           |                  |         | `EntityId`user_id<br/>`EntityId`group_id<br/>       |
| Fetch user groups           |        |           |                  |         | `AccountId`owner<br/>`EntityId`user_id<br/>         |
| Fetch user permissions      |        |           |                  |         | `AccountId`owner<br/>`EntityId`user_id<br/>         |
| Fetch group permissions     |        |           |                  |         | `AccountId`owner<br/>`EntityId`group_id<br/>        |
| Delete role                 |        |           |                  |         | `EntityId`role_id<br/>                              |
| Delete permission           |        |           |                  |         | `EntityId`permission_id<br/>                        |
| Delete group                |        |           |                  |         | `EntityId`group_id<br/>                             |

## PeaqStorage

| Name        | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                           |
| ----------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------- |
| Add item    |        |           |                  |         | `BoundedVecu8`item_type<br/>`BoundedVecu8`item<br/> |
| Update item |        |           |                  |         | `BoundedVecu8`item_type<br/>`BoundedVecu8`item<br/> |
| Get item    |        |           |                  |         | `BoundedVecu8`item_type<br/>                        |
| Remove item |        |           |                  |         | `BoundedVecu8`item_type<br/>                        |

## PeaqMor

| Name                    | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| ----------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Get registration reward |        |           |                  |         | `AccountId`machine<br/>                     |
| Get online rewards      |        |           |                  |         | `AccountId`machine<br/>                     |
| Pay machine usage       |        |           |                  |         | `AccountId`machine<br/>`Balance`amount<br/> |
| Set configuration       |        |           |                  |         | `MorConfigBalanceOfT`config<br/>            |
| Fetch pot balance       |        |           |                  |         |                                             |
