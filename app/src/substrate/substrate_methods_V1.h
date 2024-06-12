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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_PARACHAINSTAKING_V1 23
#define PD_CALL_VESTING_V1 50

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_PARACHAINSTAKING_FORCE_NEW_ROUND_V1 0
typedef struct {
} pd_parachainstaking_force_new_round_V1_t;

#define PD_CALL_PARACHAINSTAKING_SET_MAX_SELECTED_CANDIDATES_V1 2
typedef struct {
    pd_u32_t new_;
} pd_parachainstaking_set_max_selected_candidates_V1_t;

#define PD_CALL_PARACHAINSTAKING_SET_BLOCKS_PER_ROUND_V1 3
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainstaking_set_blocks_per_round_V1_t;

#define PD_CALL_PARACHAINSTAKING_SET_MAX_CANDIDATE_STAKE_V1 4
typedef struct {
    pd_Balance_t new_;
} pd_parachainstaking_set_max_candidate_stake_V1_t;

#define PD_CALL_PARACHAINSTAKING_FORCE_REMOVE_CANDIDATE_V1 5
typedef struct {
    pd_LookupasStaticLookupSource_t collator;
} pd_parachainstaking_force_remove_candidate_V1_t;

#define PD_CALL_PARACHAINSTAKING_JOIN_CANDIDATES_V1 6
typedef struct {
    pd_Balance_t stake;
} pd_parachainstaking_join_candidates_V1_t;

#define PD_CALL_PARACHAINSTAKING_INIT_LEAVE_CANDIDATES_V1 7
typedef struct {
} pd_parachainstaking_init_leave_candidates_V1_t;

#define PD_CALL_PARACHAINSTAKING_EXECUTE_LEAVE_CANDIDATES_V1 8
typedef struct {
    pd_LookupasStaticLookupSource_t collator;
} pd_parachainstaking_execute_leave_candidates_V1_t;

#define PD_CALL_PARACHAINSTAKING_CANCEL_LEAVE_CANDIDATES_V1 9
typedef struct {
} pd_parachainstaking_cancel_leave_candidates_V1_t;

#define PD_CALL_PARACHAINSTAKING_CANDIDATE_STAKE_MORE_V1 10
typedef struct {
    pd_Balance_t more;
} pd_parachainstaking_candidate_stake_more_V1_t;

#define PD_CALL_PARACHAINSTAKING_CANDIDATE_STAKE_LESS_V1 11
typedef struct {
    pd_Balance_t less;
} pd_parachainstaking_candidate_stake_less_V1_t;

#define PD_CALL_PARACHAINSTAKING_JOIN_DELEGATORS_V1 12
typedef struct {
    pd_LookupasStaticLookupSource_t collator;
    pd_Balance_t amount;
} pd_parachainstaking_join_delegators_V1_t;

#define PD_CALL_PARACHAINSTAKING_DELEGATE_ANOTHER_CANDIDATE_V1 13
typedef struct {
    pd_LookupasStaticLookupSource_t collator;
    pd_Balance_t amount;
} pd_parachainstaking_delegate_another_candidate_V1_t;

#define PD_CALL_PARACHAINSTAKING_LEAVE_DELEGATORS_V1 14
typedef struct {
} pd_parachainstaking_leave_delegators_V1_t;

#define PD_CALL_PARACHAINSTAKING_REVOKE_DELEGATION_V1 15
typedef struct {
    pd_LookupasStaticLookupSource_t collator;
} pd_parachainstaking_revoke_delegation_V1_t;

#define PD_CALL_PARACHAINSTAKING_DELEGATOR_STAKE_MORE_V1 16
typedef struct {
    pd_LookupasStaticLookupSource_t candidate;
    pd_Balance_t more;
} pd_parachainstaking_delegator_stake_more_V1_t;

#define PD_CALL_PARACHAINSTAKING_DELEGATOR_STAKE_LESS_V1 17
typedef struct {
    pd_LookupasStaticLookupSource_t candidate;
    pd_Balance_t less;
} pd_parachainstaking_delegator_stake_less_V1_t;

#define PD_CALL_PARACHAINSTAKING_UNLOCK_UNSTAKED_V1 18
typedef struct {
    pd_LookupasStaticLookupSource_t target;
} pd_parachainstaking_unlock_unstaked_V1_t;

#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

#define PD_CALL_VESTING_VEST_OTHER_V1 1
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_vesting_vest_other_V1_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V1 2
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_V1_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V1 3
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_V1_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V1 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V1_t;

#endif

typedef union {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_parachainstaking_force_new_round_V1_t parachainstaking_force_new_round_V1;
    pd_parachainstaking_set_max_selected_candidates_V1_t parachainstaking_set_max_selected_candidates_V1;
    pd_parachainstaking_set_blocks_per_round_V1_t parachainstaking_set_blocks_per_round_V1;
    pd_parachainstaking_set_max_candidate_stake_V1_t parachainstaking_set_max_candidate_stake_V1;
    pd_parachainstaking_force_remove_candidate_V1_t parachainstaking_force_remove_candidate_V1;
    pd_parachainstaking_join_candidates_V1_t parachainstaking_join_candidates_V1;
    pd_parachainstaking_init_leave_candidates_V1_t parachainstaking_init_leave_candidates_V1;
    pd_parachainstaking_execute_leave_candidates_V1_t parachainstaking_execute_leave_candidates_V1;
    pd_parachainstaking_cancel_leave_candidates_V1_t parachainstaking_cancel_leave_candidates_V1;
    pd_parachainstaking_candidate_stake_more_V1_t parachainstaking_candidate_stake_more_V1;
    pd_parachainstaking_candidate_stake_less_V1_t parachainstaking_candidate_stake_less_V1;
    pd_parachainstaking_join_delegators_V1_t parachainstaking_join_delegators_V1;
    pd_parachainstaking_delegate_another_candidate_V1_t parachainstaking_delegate_another_candidate_V1;
    pd_parachainstaking_leave_delegators_V1_t parachainstaking_leave_delegators_V1;
    pd_parachainstaking_revoke_delegation_V1_t parachainstaking_revoke_delegation_V1;
    pd_parachainstaking_delegator_stake_more_V1_t parachainstaking_delegator_stake_more_V1;
    pd_parachainstaking_delegator_stake_less_V1_t parachainstaking_delegator_stake_less_V1;
    pd_parachainstaking_unlock_unstaked_V1_t parachainstaking_unlock_unstaked_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_vesting_vest_other_V1_t vesting_vest_other_V1;
    pd_vesting_vested_transfer_V1_t vesting_vested_transfer_V1;
    pd_vesting_force_vested_transfer_V1_t vesting_force_vested_transfer_V1;
    pd_vesting_merge_schedules_V1_t vesting_merge_schedules_V1;
#endif
} pd_MethodBasic_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#endif

typedef union {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
