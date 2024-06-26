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

// Modules names
static const char* STR_MO_PARACHAINSTAKING = "Parachainstaking";
static const char* STR_MO_VESTING = "Vesting";

// Methods names
static const char* STR_ME_FORCE_NEW_ROUND = "Force new round";
static const char* STR_ME_SET_MAX_SELECTED_CANDIDATES = "Set max selected candidates";
static const char* STR_ME_SET_BLOCKS_PER_ROUND = "Set blocks per round";
static const char* STR_ME_SET_MAX_CANDIDATE_STAKE = "Set max candidate stake";
static const char* STR_ME_FORCE_REMOVE_CANDIDATE = "Force remove candidate";
static const char* STR_ME_JOIN_CANDIDATES = "Join candidates";
static const char* STR_ME_INIT_LEAVE_CANDIDATES = "Init leave candidates";
static const char* STR_ME_EXECUTE_LEAVE_CANDIDATES = "Execute leave candidates";
static const char* STR_ME_CANCEL_LEAVE_CANDIDATES = "Cancel leave candidates";
static const char* STR_ME_CANDIDATE_STAKE_MORE = "Candidate stake more";
static const char* STR_ME_CANDIDATE_STAKE_LESS = "Candidate stake less";
static const char* STR_ME_JOIN_DELEGATORS = "Join delegators";
static const char* STR_ME_DELEGATE_ANOTHER_CANDIDATE = "Delegate another candidate";
static const char* STR_ME_LEAVE_DELEGATORS = "Leave delegators";
static const char* STR_ME_REVOKE_DELEGATION = "Revoke delegation";
static const char* STR_ME_DELEGATOR_STAKE_MORE = "Delegator stake more";
static const char* STR_ME_DELEGATOR_STAKE_LESS = "Delegator stake less";
static const char* STR_ME_UNLOCK_UNSTAKED = "Unlock unstaked";
static const char* STR_ME_VEST = "Vest";
static const char* STR_ME_VEST_OTHER = "Vest other";
static const char* STR_ME_VESTED_TRANSFER = "Vested transfer";
static const char* STR_ME_FORCE_VESTED_TRANSFER = "Force vested transfer";
static const char* STR_ME_MERGE_SCHEDULES = "Merge schedules";

// Items names
static const char* STR_IT_new_ = "New";
static const char* STR_IT_collator = "Collator";
static const char* STR_IT_stake = "Stake";
static const char* STR_IT_more = "More";
static const char* STR_IT_less = "Less";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_candidate = "Candidate";
static const char* STR_IT_target = "Target";
static const char* STR_IT_schedule = "Schedule";
static const char* STR_IT_source = "Source";
static const char* STR_IT_schedule1_index = "Schedule1 index";
static const char* STR_IT_schedule2_index = "Schedule2 index";

#ifdef __cplusplus
}
#endif
