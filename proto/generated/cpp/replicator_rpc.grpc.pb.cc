// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: replicator_rpc.proto

#include "replicator_rpc.pb.h"
#include "replicator_rpc.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace replicator_rpc {

static const char* ReplicatorIoService_method_names[] = {
  "/replicator_rpc.ReplicatorIoService/CompleteRead",
  "/replicator_rpc.ReplicatorIoService/CompleteWrite",
  "/replicator_rpc.ReplicatorIoService/PushHostWrite",
  "/replicator_rpc.ReplicatorIoService/PushDirtyLog",
  "/replicator_rpc.ReplicatorIoService/TransferDirtyLog",
  "/replicator_rpc.ReplicatorIoService/TransferHostWrite",
};

std::unique_ptr< ReplicatorIoService::Stub> ReplicatorIoService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ReplicatorIoService::Stub> stub(new ReplicatorIoService::Stub(channel, options));
  return stub;
}

ReplicatorIoService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_CompleteRead_(ReplicatorIoService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CompleteWrite_(ReplicatorIoService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_PushHostWrite_(ReplicatorIoService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_PushDirtyLog_(ReplicatorIoService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_TransferDirtyLog_(ReplicatorIoService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_TransferHostWrite_(ReplicatorIoService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ReplicatorIoService::Stub::CompleteRead(::grpc::ClientContext* context, const ::replicator_rpc::CompleteReadRequest& request, ::replicator_rpc::CompleteReadResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::replicator_rpc::CompleteReadRequest, ::replicator_rpc::CompleteReadResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CompleteRead_, context, request, response);
}

void ReplicatorIoService::Stub::experimental_async::CompleteRead(::grpc::ClientContext* context, const ::replicator_rpc::CompleteReadRequest* request, ::replicator_rpc::CompleteReadResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::replicator_rpc::CompleteReadRequest, ::replicator_rpc::CompleteReadResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompleteRead_, context, request, response, std::move(f));
}

void ReplicatorIoService::Stub::experimental_async::CompleteRead(::grpc::ClientContext* context, const ::replicator_rpc::CompleteReadRequest* request, ::replicator_rpc::CompleteReadResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompleteRead_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::CompleteReadResponse>* ReplicatorIoService::Stub::PrepareAsyncCompleteReadRaw(::grpc::ClientContext* context, const ::replicator_rpc::CompleteReadRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::replicator_rpc::CompleteReadResponse, ::replicator_rpc::CompleteReadRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CompleteRead_, context, request);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::CompleteReadResponse>* ReplicatorIoService::Stub::AsyncCompleteReadRaw(::grpc::ClientContext* context, const ::replicator_rpc::CompleteReadRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCompleteReadRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ReplicatorIoService::Stub::CompleteWrite(::grpc::ClientContext* context, const ::replicator_rpc::CompleteWriteRequest& request, ::replicator_rpc::CompleteWriteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::replicator_rpc::CompleteWriteRequest, ::replicator_rpc::CompleteWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CompleteWrite_, context, request, response);
}

void ReplicatorIoService::Stub::experimental_async::CompleteWrite(::grpc::ClientContext* context, const ::replicator_rpc::CompleteWriteRequest* request, ::replicator_rpc::CompleteWriteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::replicator_rpc::CompleteWriteRequest, ::replicator_rpc::CompleteWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompleteWrite_, context, request, response, std::move(f));
}

void ReplicatorIoService::Stub::experimental_async::CompleteWrite(::grpc::ClientContext* context, const ::replicator_rpc::CompleteWriteRequest* request, ::replicator_rpc::CompleteWriteResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompleteWrite_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::CompleteWriteResponse>* ReplicatorIoService::Stub::PrepareAsyncCompleteWriteRaw(::grpc::ClientContext* context, const ::replicator_rpc::CompleteWriteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::replicator_rpc::CompleteWriteResponse, ::replicator_rpc::CompleteWriteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CompleteWrite_, context, request);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::CompleteWriteResponse>* ReplicatorIoService::Stub::AsyncCompleteWriteRaw(::grpc::ClientContext* context, const ::replicator_rpc::CompleteWriteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCompleteWriteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ReplicatorIoService::Stub::PushHostWrite(::grpc::ClientContext* context, const ::replicator_rpc::PushHostWriteRequest& request, ::replicator_rpc::PushHostWriteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::replicator_rpc::PushHostWriteRequest, ::replicator_rpc::PushHostWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_PushHostWrite_, context, request, response);
}

void ReplicatorIoService::Stub::experimental_async::PushHostWrite(::grpc::ClientContext* context, const ::replicator_rpc::PushHostWriteRequest* request, ::replicator_rpc::PushHostWriteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::replicator_rpc::PushHostWriteRequest, ::replicator_rpc::PushHostWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PushHostWrite_, context, request, response, std::move(f));
}

void ReplicatorIoService::Stub::experimental_async::PushHostWrite(::grpc::ClientContext* context, const ::replicator_rpc::PushHostWriteRequest* request, ::replicator_rpc::PushHostWriteResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PushHostWrite_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::PushHostWriteResponse>* ReplicatorIoService::Stub::PrepareAsyncPushHostWriteRaw(::grpc::ClientContext* context, const ::replicator_rpc::PushHostWriteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::replicator_rpc::PushHostWriteResponse, ::replicator_rpc::PushHostWriteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_PushHostWrite_, context, request);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::PushHostWriteResponse>* ReplicatorIoService::Stub::AsyncPushHostWriteRaw(::grpc::ClientContext* context, const ::replicator_rpc::PushHostWriteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPushHostWriteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ReplicatorIoService::Stub::PushDirtyLog(::grpc::ClientContext* context, const ::replicator_rpc::PushDirtyLogRequest& request, ::replicator_rpc::PushDirtyLogResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::replicator_rpc::PushDirtyLogRequest, ::replicator_rpc::PushDirtyLogResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_PushDirtyLog_, context, request, response);
}

void ReplicatorIoService::Stub::experimental_async::PushDirtyLog(::grpc::ClientContext* context, const ::replicator_rpc::PushDirtyLogRequest* request, ::replicator_rpc::PushDirtyLogResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::replicator_rpc::PushDirtyLogRequest, ::replicator_rpc::PushDirtyLogResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PushDirtyLog_, context, request, response, std::move(f));
}

void ReplicatorIoService::Stub::experimental_async::PushDirtyLog(::grpc::ClientContext* context, const ::replicator_rpc::PushDirtyLogRequest* request, ::replicator_rpc::PushDirtyLogResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PushDirtyLog_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::PushDirtyLogResponse>* ReplicatorIoService::Stub::PrepareAsyncPushDirtyLogRaw(::grpc::ClientContext* context, const ::replicator_rpc::PushDirtyLogRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::replicator_rpc::PushDirtyLogResponse, ::replicator_rpc::PushDirtyLogRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_PushDirtyLog_, context, request);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::PushDirtyLogResponse>* ReplicatorIoService::Stub::AsyncPushDirtyLogRaw(::grpc::ClientContext* context, const ::replicator_rpc::PushDirtyLogRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPushDirtyLogRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ReplicatorIoService::Stub::TransferDirtyLog(::grpc::ClientContext* context, const ::replicator_rpc::TransferDirtyLogRequest& request, ::replicator_rpc::TransferDirtyLogResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::replicator_rpc::TransferDirtyLogRequest, ::replicator_rpc::TransferDirtyLogResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_TransferDirtyLog_, context, request, response);
}

void ReplicatorIoService::Stub::experimental_async::TransferDirtyLog(::grpc::ClientContext* context, const ::replicator_rpc::TransferDirtyLogRequest* request, ::replicator_rpc::TransferDirtyLogResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::replicator_rpc::TransferDirtyLogRequest, ::replicator_rpc::TransferDirtyLogResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_TransferDirtyLog_, context, request, response, std::move(f));
}

void ReplicatorIoService::Stub::experimental_async::TransferDirtyLog(::grpc::ClientContext* context, const ::replicator_rpc::TransferDirtyLogRequest* request, ::replicator_rpc::TransferDirtyLogResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_TransferDirtyLog_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::TransferDirtyLogResponse>* ReplicatorIoService::Stub::PrepareAsyncTransferDirtyLogRaw(::grpc::ClientContext* context, const ::replicator_rpc::TransferDirtyLogRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::replicator_rpc::TransferDirtyLogResponse, ::replicator_rpc::TransferDirtyLogRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_TransferDirtyLog_, context, request);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::TransferDirtyLogResponse>* ReplicatorIoService::Stub::AsyncTransferDirtyLogRaw(::grpc::ClientContext* context, const ::replicator_rpc::TransferDirtyLogRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncTransferDirtyLogRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status ReplicatorIoService::Stub::TransferHostWrite(::grpc::ClientContext* context, const ::replicator_rpc::TransferHostWriteRequest& request, ::replicator_rpc::TransferHostWriteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::replicator_rpc::TransferHostWriteRequest, ::replicator_rpc::TransferHostWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_TransferHostWrite_, context, request, response);
}

void ReplicatorIoService::Stub::experimental_async::TransferHostWrite(::grpc::ClientContext* context, const ::replicator_rpc::TransferHostWriteRequest* request, ::replicator_rpc::TransferHostWriteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::replicator_rpc::TransferHostWriteRequest, ::replicator_rpc::TransferHostWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_TransferHostWrite_, context, request, response, std::move(f));
}

void ReplicatorIoService::Stub::experimental_async::TransferHostWrite(::grpc::ClientContext* context, const ::replicator_rpc::TransferHostWriteRequest* request, ::replicator_rpc::TransferHostWriteResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_TransferHostWrite_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::TransferHostWriteResponse>* ReplicatorIoService::Stub::PrepareAsyncTransferHostWriteRaw(::grpc::ClientContext* context, const ::replicator_rpc::TransferHostWriteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::replicator_rpc::TransferHostWriteResponse, ::replicator_rpc::TransferHostWriteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_TransferHostWrite_, context, request);
}

::grpc::ClientAsyncResponseReader< ::replicator_rpc::TransferHostWriteResponse>* ReplicatorIoService::Stub::AsyncTransferHostWriteRaw(::grpc::ClientContext* context, const ::replicator_rpc::TransferHostWriteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncTransferHostWriteRaw(context, request, cq);
  result->StartCall();
  return result;
}

ReplicatorIoService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ReplicatorIoService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ReplicatorIoService::Service, ::replicator_rpc::CompleteReadRequest, ::replicator_rpc::CompleteReadResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ReplicatorIoService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::replicator_rpc::CompleteReadRequest* req,
             ::replicator_rpc::CompleteReadResponse* resp) {
               return service->CompleteRead(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ReplicatorIoService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ReplicatorIoService::Service, ::replicator_rpc::CompleteWriteRequest, ::replicator_rpc::CompleteWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ReplicatorIoService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::replicator_rpc::CompleteWriteRequest* req,
             ::replicator_rpc::CompleteWriteResponse* resp) {
               return service->CompleteWrite(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ReplicatorIoService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ReplicatorIoService::Service, ::replicator_rpc::PushHostWriteRequest, ::replicator_rpc::PushHostWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ReplicatorIoService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::replicator_rpc::PushHostWriteRequest* req,
             ::replicator_rpc::PushHostWriteResponse* resp) {
               return service->PushHostWrite(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ReplicatorIoService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ReplicatorIoService::Service, ::replicator_rpc::PushDirtyLogRequest, ::replicator_rpc::PushDirtyLogResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ReplicatorIoService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::replicator_rpc::PushDirtyLogRequest* req,
             ::replicator_rpc::PushDirtyLogResponse* resp) {
               return service->PushDirtyLog(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ReplicatorIoService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ReplicatorIoService::Service, ::replicator_rpc::TransferDirtyLogRequest, ::replicator_rpc::TransferDirtyLogResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ReplicatorIoService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::replicator_rpc::TransferDirtyLogRequest* req,
             ::replicator_rpc::TransferDirtyLogResponse* resp) {
               return service->TransferDirtyLog(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ReplicatorIoService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ReplicatorIoService::Service, ::replicator_rpc::TransferHostWriteRequest, ::replicator_rpc::TransferHostWriteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ReplicatorIoService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::replicator_rpc::TransferHostWriteRequest* req,
             ::replicator_rpc::TransferHostWriteResponse* resp) {
               return service->TransferHostWrite(ctx, req, resp);
             }, this)));
}

ReplicatorIoService::Service::~Service() {
}

::grpc::Status ReplicatorIoService::Service::CompleteRead(::grpc::ServerContext* context, const ::replicator_rpc::CompleteReadRequest* request, ::replicator_rpc::CompleteReadResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ReplicatorIoService::Service::CompleteWrite(::grpc::ServerContext* context, const ::replicator_rpc::CompleteWriteRequest* request, ::replicator_rpc::CompleteWriteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ReplicatorIoService::Service::PushHostWrite(::grpc::ServerContext* context, const ::replicator_rpc::PushHostWriteRequest* request, ::replicator_rpc::PushHostWriteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ReplicatorIoService::Service::PushDirtyLog(::grpc::ServerContext* context, const ::replicator_rpc::PushDirtyLogRequest* request, ::replicator_rpc::PushDirtyLogResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ReplicatorIoService::Service::TransferDirtyLog(::grpc::ServerContext* context, const ::replicator_rpc::TransferDirtyLogRequest* request, ::replicator_rpc::TransferDirtyLogResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ReplicatorIoService::Service::TransferHostWrite(::grpc::ServerContext* context, const ::replicator_rpc::TransferHostWriteRequest* request, ::replicator_rpc::TransferHostWriteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace replicator_rpc

