/*
 *   BSD LICENSE
 *   Copyright (c) 2021 Samsung Electronics Corporation
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
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
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

#pragma once

#include "src/array_models/interface/i_mount_sequence.h"

#include "src/mapper/i_map_flush.h"
#include "src/mapper/i_mapper_wbt.h"
#include "src/mapper/address/mapper_address_info.h"
#include "src/mapper/mapper_wbt.h"
#include "src/mapper/reversemap/reverse_map.h"
#include "src/mapper/reversemap/reversemap_manager.h"
#include "src/mapper/stripemap/stripemap_content.h"
#include "src/mapper/stripemap/stripemap_manager.h"
#include "src/mapper/vsamap/vsamap_content.h"
#include "src/mapper/vsamap/vsamap_manager.h"

#include "src/state/interface/i_state_control.h"

#include <string>

namespace pos
{

class Mapper : public IMapFlush, public IMountSequence
{
    friend class MapperTestFixture;

public:
    Mapper(IArrayInfo* iarrayInfo, IStateControl* iState);
    virtual ~Mapper(void);

    virtual int Init(void) override;
    virtual void Dispose(void) override;
    virtual void Shutdown(void) override;
    virtual void Flush(void) override;

    void Close(void);

    virtual IVSAMap* GetIVSAMap(void);
    virtual IStripeMap* GetIStripeMap(void);
    IReverseMap* GetIReverseMap(void);
    virtual IMapFlush* GetIMapFlush(void);
    IMapperWbt* GetIMapperWbt(void);

    int FlushDirtyMpages(int mapId, EventSmartPtr callback, MpageList dirtyPages = DEFAULT_DIRTYPAGE_SET) override;
    int StoreAllMaps(void) override;

private:
    MapContent* _GetMapContent(int mapId);
    void _RegisterToMapperService(void);
    void _UnregisterFromMapperService(void);

    MapperAddressInfo* addrInfo;
    VSAMapManager* vsaMapManager;
    StripeMapManager* stripeMapManager;
    ReverseMapManager* reverseMapManager;
    MapperWbt* mapperWbt;

    IArrayInfo* iArrayinfo;
    IStateControl* iStateControl;

    bool isInitialized;
};

} // namespace pos
