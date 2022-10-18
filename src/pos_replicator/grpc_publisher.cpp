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

#include "grpc_publisher.h"

#include <memory>
#include <string>
#include <thread>

#include "src/include/grpc_server_socket_address.h"
#include "src/include/pos_event_id.h"
#include "src/logger/logger.h"
#include "src/master_context/config_manager.h"

namespace pos
{
GrpcPublisher::GrpcPublisher(std::shared_ptr<grpc::Channel> channel_, ConfigManager* configManager)
{
    std::string serverAddress;
    int ret = configManager->GetValue("replicator", "ha_publisher_address",
        static_cast<void*>(&serverAddress), CONFIG_TYPE_STRING);
    if (ret != 0)
    {
        POS_TRACE_INFO(static_cast<int>(EID(HA_DEBUG_MSG)),
            "Cannot read address of grpc publisher from pos config file, Address will be default vaule set defined in the \"grpc_server_socket_address.h\"");
        serverAddress = GRPC_HA_PUB_SERVER_SOCKET_ADDRESS;
    }
    new std::thread(&GrpcPublisher::_ConnectGrpcServer, this, serverAddress);
}

GrpcPublisher::~GrpcPublisher(void)
{
    POS_TRACE_INFO(EID(HA_DEBUG_MSG), "Replicator publisher has been destructed");
}

void
GrpcPublisher::_ConnectGrpcServer(std::string targetAddress)
{
    if (channel == nullptr)
    {
        channel = grpc::CreateChannel(targetAddress, grpc::InsecureChannelCredentials());
        if (_WaitUntilReady() != true)
        {
            POS_TRACE_ERROR(EID(HA_COMPLETION_FAIL), "Failed to initialize replicator publisher");
        }
    }

    stub = ::replicator_rpc::ReplicatorIo::NewStub(channel);
    POS_TRACE_INFO(EID(HA_DEBUG_MSG), "Replicator publisher has been initialized with the channel newly established on {}", targetAddress);
}

bool
GrpcPublisher::_WaitUntilReady()
{
    // TODO (cheolho.kang): check functionality. Should wait until grpc channel is ready
    /*
    auto state = channel->GetState(true);
    while (state != GRPC_CHANNEL_READY)
    {
        if (!channel->WaitForStateChange(state, gpr_inf_future(GPR_CLOCK_REALTIME)))
        {
            POS_TRACE_ERROR(EID(HA_COMPLETION_FAIL), "Failed to wait for state change due to grpc error");
            return false;
        }
        state = channel->GetState(true);
    }
    */
    return true;
}

int
GrpcPublisher::PushHostWrite(uint64_t rba, uint64_t size, string volumeName,
    string arrayName, void* buf, uint64_t& lsn)
{
    ::grpc::ClientContext cliContext;
    replicator_rpc::PushHostWriteRequest* request = new replicator_rpc::PushHostWriteRequest;
    replicator_rpc::PushHostWriteResponse response;
    request->set_array_name(arrayName);
    request->set_volume_name(volumeName);
    request->set_rba(rba);
    request->set_num_blocks(size);

    /*
    [To do buffer process]    
    for (int iter = 0; iter < size; iter++)
    {
        replicator_rpc::Chunk* dataChunk = request->add_data();
        request->CopyFrom(buf);
    }
    */

    grpc::Status status = stub->PushHostWrite(&cliContext, *request, &response);

    if (status.ok() == false)
    {
        POS_TRACE_ERROR(EID(HA_INVALID_RETURN_LSN), "Failed to send PushHostWrite response to invalid lsn");
        return EID(HA_INVALID_RETURN_LSN);
    }
    lsn = response.lsn();

    return EID(SUCCESS);
}

int
GrpcPublisher::CompleteUserWrite(uint64_t lsn, string volumeName, string arrayName)
{
    ::grpc::ClientContext cliContext;
    replicator_rpc::CompleteWriteRequest* request = new replicator_rpc::CompleteWriteRequest;
    replicator_rpc::CompleteWriteResponse response;

    request->set_lsn(lsn);
    request->set_array_name(arrayName);
    request->set_volume_name(volumeName);

    grpc::Status status = stub->CompleteWrite(&cliContext, *request, &response);

    if (status.ok() == false)
    {
        return EID(HA_COMPLETION_FAIL);
    }

    return EID(SUCCESS);
}

int
GrpcPublisher::CompleteWrite(uint64_t lsn, string volumeName, string arrayName)
{
    ::grpc::ClientContext cliContext;
    replicator_rpc::CompleteWriteRequest* request = new replicator_rpc::CompleteWriteRequest;
    replicator_rpc::CompleteWriteResponse response;

    request->set_lsn(lsn);
    request->set_array_name(arrayName);
    request->set_volume_name(volumeName);

    grpc::Status status = stub->CompleteWrite(&cliContext, *request, &response);

    if (status.ok() == false)
    {
        return EID(HA_COMPLETION_FAIL);
    }

    return EID(SUCCESS);
}

int
GrpcPublisher::CompleteRead(uint64_t lsn, uint64_t size, string volumeName, string arrayName, void* buf)
{
    ::grpc::ClientContext cliContext;
    replicator_rpc::CompleteReadRequest* request = new replicator_rpc::CompleteReadRequest;
    replicator_rpc::CompleteReadResponse response;

    request->set_lsn(lsn);
    request->set_array_name(arrayName);
    request->set_volume_name(volumeName);
    // to do set buffer

    grpc::Status status;
    if (_WaitUntilReady() == true)
    {
        status = stub->CompleteRead(&cliContext, *request, &response);
        POS_TRACE_INFO(EID(HA_DEBUG_MSG), "Complete to send CompleteRead response to replicator");
    }

    if (status.ok() == false)
    {
        POS_TRACE_ERROR(EID(HA_COMPLETION_FAIL), "Failed to send CompleteRead response to replicator due to grpc error, status: {}", status.error_code());
        return EID(HA_COMPLETION_FAIL);
    }

    return EID(SUCCESS);
}
} // namespace pos
