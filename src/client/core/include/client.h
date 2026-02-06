#pragma once

#include <grpcpp/grpcpp.h>

#include "v1.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using v1::Request;
using v1::Response;
using v1::Information;
using v1::V1Service;

namespace GrpcClient {
	struct ServerInformation {
		int typeId;
		std::string message;
	};

	struct ServerReqeust {
		int statusId;
		std::string UUID;
		std::string deviceUUID;
		std::vector<ServerInformation> information;
	};

	class V1ServiceImpl {
	public:
		V1ServiceImpl(std::shared_ptr<Channel> channel);

		Response ServerRequest(const ServerReqeust& req);
	private:
		std::shared_ptr<V1Service::Stub> stub_;
	};

	void RunClient(int port);
}