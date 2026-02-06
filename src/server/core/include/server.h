#pragma once

#include <grpcpp/grpcpp.h>

#include "v1.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using v1::V1Service;
using v1::Request;
using v1::Response;
using v1::Information;


namespace GrpcServer{
	class V1ServiceImpl final : public V1Service::Service {
	public:
		Status HandleRequest(ServerContext* ctx, const Request* request, Response* reply) override;
	};

	void RunServer(int port);
}