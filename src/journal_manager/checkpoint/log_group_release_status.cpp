/*
 *   BSD LICENSE
 *   Copyright (c) 2022 Samsung Electronics Corporation
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Samsung Electronics Corporation nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "src/journal_manager/checkpoint/log_group_release_status.h"
#include "src/include/pos_event_id.h"
#include "src/logger/logger.h"
#include <cassert>

namespace pos
{
LogGroupReleaseStatus::LogGroupReleaseStatus(int groupId)
: id(groupId),
  sequenceNumber(UINT32_MAX),
  prevSequenceNumber(UINT32_MAX),
  status(ReleaseStatus::INIT)
{
}

void
LogGroupReleaseStatus::SetWaiting(uint32_t seqNum)
{
    assert(status == ReleaseStatus::INIT);

    ReleaseStatus from = status;

    prevSequenceNumber = sequenceNumber;
    sequenceNumber = seqNum;
    status = ReleaseStatus::WAITING;

    _PrintStatusChangedLog(from);
}

void
LogGroupReleaseStatus::SetReleasing(void)
{
    assert(status == ReleaseStatus::WAITING);

    ReleaseStatus from = status;
    status = ReleaseStatus::RELEASING;

    _PrintStatusChangedLog(from);
}

void
LogGroupReleaseStatus::Reset(void)
{
    ReleaseStatus from = status;
    status = ReleaseStatus::INIT;

    _PrintStatusChangedLog(from);
}

void
LogGroupReleaseStatus::_PrintStatusChangedLog(ReleaseStatus from)
{
    POS_TRACE_DEBUG(EID(JOURNAL_LOG_GROUP_STATUS_CHANGED),
        "logGroupId:{}, from:{}, to:{}", id, from, status);
}

uint32_t
LogGroupReleaseStatus::GetSeqNum(void)
{
    return sequenceNumber;
}

uint32_t
LogGroupReleaseStatus::GetPrevSeqNum(void)
{
    return prevSequenceNumber;
}

int
LogGroupReleaseStatus::GetId(void)
{
    return id;
}

bool
LogGroupReleaseStatus::IsFull(void)
{
    return (status != ReleaseStatus::INIT);
}

bool
LogGroupReleaseStatus::IsReleasing(void)
{
    return (status == ReleaseStatus::RELEASING);
}

} // namespace pos
