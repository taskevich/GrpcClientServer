#include "server.h"

namespace GrpcServer {
	Status V1ServiceImpl::HandleRequest(ServerContext* ctx, const Request* request, Response* reply) {
		reply->set_typeid_(1);
		reply->set_message("OK");
		return Status::OK;
	}

	void GrpcServer::RunServer(int port) {
		std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
		V1ServiceImpl service;

		grpc::EnableDefaultHealthCheckService(true);
		
		ServerBuilder builder;
		builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
		builder.RegisterService(&service);
		std::unique_ptr<Server> server(builder.BuildAndStart());
		std::cout << "Server listening on " << server_address << std::endl;
		server->Wait();
	}
}