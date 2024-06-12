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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

__Z_INLINE parser_error_t _readMethod_parachainstaking_force_new_round_V1(
    parser_context_t* c, pd_parachainstaking_force_new_round_V1_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_set_max_selected_candidates_V1(
    parser_context_t* c, pd_parachainstaking_set_max_selected_candidates_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_set_blocks_per_round_V1(
    parser_context_t* c, pd_parachainstaking_set_blocks_per_round_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_set_max_candidate_stake_V1(
    parser_context_t* c, pd_parachainstaking_set_max_candidate_stake_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_force_remove_candidate_V1(
    parser_context_t* c, pd_parachainstaking_force_remove_candidate_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->collator))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_join_candidates_V1(
    parser_context_t* c, pd_parachainstaking_join_candidates_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->stake))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_init_leave_candidates_V1(
    parser_context_t* c, pd_parachainstaking_init_leave_candidates_V1_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_execute_leave_candidates_V1(
    parser_context_t* c, pd_parachainstaking_execute_leave_candidates_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->collator))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_cancel_leave_candidates_V1(
    parser_context_t* c, pd_parachainstaking_cancel_leave_candidates_V1_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_candidate_stake_more_V1(
    parser_context_t* c, pd_parachainstaking_candidate_stake_more_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->more))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_candidate_stake_less_V1(
    parser_context_t* c, pd_parachainstaking_candidate_stake_less_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->less))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_join_delegators_V1(
    parser_context_t* c, pd_parachainstaking_join_delegators_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->collator))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_delegate_another_candidate_V1(
    parser_context_t* c, pd_parachainstaking_delegate_another_candidate_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->collator))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_leave_delegators_V1(
    parser_context_t* c, pd_parachainstaking_leave_delegators_V1_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_revoke_delegation_V1(
    parser_context_t* c, pd_parachainstaking_revoke_delegation_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->collator))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_delegator_stake_more_V1(
    parser_context_t* c, pd_parachainstaking_delegator_stake_more_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->candidate))
    CHECK_ERROR(_readBalance(c, &m->more))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_delegator_stake_less_V1(
    parser_context_t* c, pd_parachainstaking_delegator_stake_less_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->candidate))
    CHECK_ERROR(_readBalance(c, &m->less))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parachainstaking_unlock_unstaked_V1(
    parser_context_t* c, pd_parachainstaking_unlock_unstaked_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V1(
    parser_context_t* c, pd_vesting_vest_other_V1_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V1(
    parser_context_t* c, pd_vesting_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V1(
    parser_context_t* c, pd_vesting_force_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V1(
    parser_context_t* c, pd_vesting_merge_schedules_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_parachainstaking_force_new_round_V1(c, &method->basic.parachainstaking_force_new_round_V1))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_parachainstaking_set_max_selected_candidates_V1(c, &method->basic.parachainstaking_set_max_selected_candidates_V1))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_parachainstaking_set_blocks_per_round_V1(c, &method->basic.parachainstaking_set_blocks_per_round_V1))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_parachainstaking_set_max_candidate_stake_V1(c, &method->basic.parachainstaking_set_max_candidate_stake_V1))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_parachainstaking_force_remove_candidate_V1(c, &method->basic.parachainstaking_force_remove_candidate_V1))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_parachainstaking_join_candidates_V1(c, &method->basic.parachainstaking_join_candidates_V1))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_parachainstaking_init_leave_candidates_V1(c, &method->basic.parachainstaking_init_leave_candidates_V1))
        break;
    case 5896: /* module 23 call 8 */
        CHECK_ERROR(_readMethod_parachainstaking_execute_leave_candidates_V1(c, &method->basic.parachainstaking_execute_leave_candidates_V1))
        break;
    case 5897: /* module 23 call 9 */
        CHECK_ERROR(_readMethod_parachainstaking_cancel_leave_candidates_V1(c, &method->basic.parachainstaking_cancel_leave_candidates_V1))
        break;
    case 5898: /* module 23 call 10 */
        CHECK_ERROR(_readMethod_parachainstaking_candidate_stake_more_V1(c, &method->basic.parachainstaking_candidate_stake_more_V1))
        break;
    case 5899: /* module 23 call 11 */
        CHECK_ERROR(_readMethod_parachainstaking_candidate_stake_less_V1(c, &method->basic.parachainstaking_candidate_stake_less_V1))
        break;
    case 5900: /* module 23 call 12 */
        CHECK_ERROR(_readMethod_parachainstaking_join_delegators_V1(c, &method->basic.parachainstaking_join_delegators_V1))
        break;
    case 5901: /* module 23 call 13 */
        CHECK_ERROR(_readMethod_parachainstaking_delegate_another_candidate_V1(c, &method->basic.parachainstaking_delegate_another_candidate_V1))
        break;
    case 5902: /* module 23 call 14 */
        CHECK_ERROR(_readMethod_parachainstaking_leave_delegators_V1(c, &method->basic.parachainstaking_leave_delegators_V1))
        break;
    case 5903: /* module 23 call 15 */
        CHECK_ERROR(_readMethod_parachainstaking_revoke_delegation_V1(c, &method->basic.parachainstaking_revoke_delegation_V1))
        break;
    case 5904: /* module 23 call 16 */
        CHECK_ERROR(_readMethod_parachainstaking_delegator_stake_more_V1(c, &method->basic.parachainstaking_delegator_stake_more_V1))
        break;
    case 5905: /* module 23 call 17 */
        CHECK_ERROR(_readMethod_parachainstaking_delegator_stake_less_V1(c, &method->basic.parachainstaking_delegator_stake_less_V1))
        break;
    case 5906: /* module 23 call 18 */
        CHECK_ERROR(_readMethod_parachainstaking_unlock_unstaked_V1(c, &method->basic.parachainstaking_unlock_unstaked_V1))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V1(c, &method->basic.vesting_vest_other_V1))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V1(c, &method->basic.vesting_vested_transfer_V1))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V1(c, &method->basic.vesting_force_vested_transfer_V1))
        break;
    case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V1(c, &method->basic.vesting_merge_schedules_V1))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 23:
        return STR_MO_PARACHAINSTAKING;
    case 50:
        return STR_MO_VESTING;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    default:
        return _getMethod_Name_V1_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V1_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 5888: /* module 23 call 0 */
        return STR_ME_FORCE_NEW_ROUND;
    case 5890: /* module 23 call 2 */
        return STR_ME_SET_MAX_SELECTED_CANDIDATES;
    case 5891: /* module 23 call 3 */
        return STR_ME_SET_BLOCKS_PER_ROUND;
    case 5892: /* module 23 call 4 */
        return STR_ME_SET_MAX_CANDIDATE_STAKE;
    case 5893: /* module 23 call 5 */
        return STR_ME_FORCE_REMOVE_CANDIDATE;
    case 5894: /* module 23 call 6 */
        return STR_ME_JOIN_CANDIDATES;
    case 5895: /* module 23 call 7 */
        return STR_ME_INIT_LEAVE_CANDIDATES;
    case 5896: /* module 23 call 8 */
        return STR_ME_EXECUTE_LEAVE_CANDIDATES;
    case 5897: /* module 23 call 9 */
        return STR_ME_CANCEL_LEAVE_CANDIDATES;
    case 5898: /* module 23 call 10 */
        return STR_ME_CANDIDATE_STAKE_MORE;
    case 5899: /* module 23 call 11 */
        return STR_ME_CANDIDATE_STAKE_LESS;
    case 5900: /* module 23 call 12 */
        return STR_ME_JOIN_DELEGATORS;
    case 5901: /* module 23 call 13 */
        return STR_ME_DELEGATE_ANOTHER_CANDIDATE;
    case 5902: /* module 23 call 14 */
        return STR_ME_LEAVE_DELEGATORS;
    case 5903: /* module 23 call 15 */
        return STR_ME_REVOKE_DELEGATION;
    case 5904: /* module 23 call 16 */
        return STR_ME_DELEGATOR_STAKE_MORE;
    case 5905: /* module 23 call 17 */
        return STR_ME_DELEGATOR_STAKE_LESS;
    case 5906: /* module 23 call 18 */
        return STR_ME_UNLOCK_UNSTAKED;
    case 12800: /* module 50 call 0 */
        return STR_ME_VEST;
    case 12801: /* module 50 call 1 */
        return STR_ME_VEST_OTHER;
    case 12802: /* module 50 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 12803: /* module 50 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 12804: /* module 50 call 4 */
        return STR_ME_MERGE_SCHEDULES;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 5888: /* module 23 call 0 */
        return 0;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 1;
    case 5892: /* module 23 call 4 */
        return 1;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 1;
    case 5895: /* module 23 call 7 */
        return 0;
    case 5896: /* module 23 call 8 */
        return 1;
    case 5897: /* module 23 call 9 */
        return 0;
    case 5898: /* module 23 call 10 */
        return 1;
    case 5899: /* module 23 call 11 */
        return 1;
    case 5900: /* module 23 call 12 */
        return 2;
    case 5901: /* module 23 call 13 */
        return 2;
    case 5902: /* module 23 call 14 */
        return 0;
    case 5903: /* module 23 call 15 */
        return 1;
    case 5904: /* module 23 call 16 */
        return 2;
    case 5905: /* module 23 call 17 */
        return 2;
    case 5906: /* module 23 call 18 */
        return 1;
    case 12800: /* module 50 call 0 */
        return 0;
    case 12801: /* module 50 call 1 */
        return 1;
    case 12802: /* module 50 call 2 */
        return 2;
    case 12803: /* module 50 call 3 */
        return 3;
    case 12804: /* module 50 call 4 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collator;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stake;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collator;
        default:
            return NULL;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_more;
        default:
            return NULL;
        }
    case 5899: /* module 23 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_less;
        default:
            return NULL;
        }
    case 5900: /* module 23 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collator;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collator;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5903: /* module 23 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collator;
        default:
            return NULL;
        }
    case 5904: /* module 23 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate;
        case 1:
            return STR_IT_more;
        default:
            return NULL;
        }
    case 5905: /* module 23 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate;
        case 1:
            return STR_IT_less;
        default:
            return NULL;
        }
    case 5906: /* module 23 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* parachainstaking_set_max_selected_candidates_V1 - new_ */;
            return _toStringu32(
                &m->basic.parachainstaking_set_max_selected_candidates_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0: /* parachainstaking_set_blocks_per_round_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.parachainstaking_set_blocks_per_round_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* parachainstaking_set_max_candidate_stake_V1 - new_ */;
            return _toStringBalance(
                &m->basic.parachainstaking_set_max_candidate_stake_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* parachainstaking_force_remove_candidate_V1 - collator */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_force_remove_candidate_V1.collator,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* parachainstaking_join_candidates_V1 - stake */;
            return _toStringBalance(
                &m->basic.parachainstaking_join_candidates_V1.stake,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0: /* parachainstaking_execute_leave_candidates_V1 - collator */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_execute_leave_candidates_V1.collator,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0: /* parachainstaking_candidate_stake_more_V1 - more */;
            return _toStringBalance(
                &m->basic.parachainstaking_candidate_stake_more_V1.more,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5899: /* module 23 call 11 */
        switch (itemIdx) {
        case 0: /* parachainstaking_candidate_stake_less_V1 - less */;
            return _toStringBalance(
                &m->basic.parachainstaking_candidate_stake_less_V1.less,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5900: /* module 23 call 12 */
        switch (itemIdx) {
        case 0: /* parachainstaking_join_delegators_V1 - collator */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_join_delegators_V1.collator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* parachainstaking_join_delegators_V1 - amount */;
            return _toStringBalance(
                &m->basic.parachainstaking_join_delegators_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0: /* parachainstaking_delegate_another_candidate_V1 - collator */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_delegate_another_candidate_V1.collator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* parachainstaking_delegate_another_candidate_V1 - amount */;
            return _toStringBalance(
                &m->basic.parachainstaking_delegate_another_candidate_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5903: /* module 23 call 15 */
        switch (itemIdx) {
        case 0: /* parachainstaking_revoke_delegation_V1 - collator */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_revoke_delegation_V1.collator,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5904: /* module 23 call 16 */
        switch (itemIdx) {
        case 0: /* parachainstaking_delegator_stake_more_V1 - candidate */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_delegator_stake_more_V1.candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* parachainstaking_delegator_stake_more_V1 - more */;
            return _toStringBalance(
                &m->basic.parachainstaking_delegator_stake_more_V1.more,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5905: /* module 23 call 17 */
        switch (itemIdx) {
        case 0: /* parachainstaking_delegator_stake_less_V1 - candidate */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_delegator_stake_less_V1.candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* parachainstaking_delegator_stake_less_V1 - less */;
            return _toStringBalance(
                &m->basic.parachainstaking_delegator_stake_less_V1.less,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5906: /* module 23 call 18 */
        switch (itemIdx) {
        case 0: /* parachainstaking_unlock_unstaked_V1 - target */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.parachainstaking_unlock_unstaked_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V1 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vest_other_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V1 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V1 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V1 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_force_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V1 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V1.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V1 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V1.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 5888: // ParachainStaking:Force new round
    case 5890: // ParachainStaking:Set max selected candidates
    case 5891: // ParachainStaking:Set blocks per round
    case 5892: // ParachainStaking:Set max candidate stake
    case 5893: // ParachainStaking:Force remove candidate
    case 5894: // ParachainStaking:Join candidates
    case 5895: // ParachainStaking:Init leave candidates
    case 5896: // ParachainStaking:Execute leave candidates
    case 5897: // ParachainStaking:Cancel leave candidates
    case 5898: // ParachainStaking:Candidate stake more
    case 5899: // ParachainStaking:Candidate stake less
    case 5900: // ParachainStaking:Join delegators
    case 5901: // ParachainStaking:Delegate another candidate
    case 5902: // ParachainStaking:Leave delegators
    case 5903: // ParachainStaking:Revoke delegation
    case 5904: // ParachainStaking:Delegator stake more
    case 5905: // ParachainStaking:Delegator stake less
    case 5906: // ParachainStaking:Unlock unstaked
    case 12800: // Vesting:Vest
    case 12801: // Vesting:Vest other
    case 12802: // Vesting:Vested transfer
    case 12803: // Vesting:Force vested transfer
    case 12804: // Vesting:Merge schedules
        return false;
    default:
        return true;
    }
}
