#include "client.h"

namespace GrpcClient {
	V1ServiceImpl::V1ServiceImpl(std::shared_ptr<Channel> channel)
		: stub_(V1Service::NewStub(channel)) { }

	Response V1ServiceImpl::ServerRequest(const ServerReqeust& req) {
		ClientContext ctx;
		Request request;
		Response response;

		request.set_uuid(req.UUID);
		request.set_deviceuuid(req.deviceUUID);
		request.set_statusid(req.statusId);

		if (req.information.size() > 0) {
			auto& informationMap = *request.mutable_information();
			for (const ServerInformation& item : req.information) {
				Information* grpcInfo = &informationMap[std::to_string(item.typeId)];
				grpcInfo->set_typeid_(item.typeId);
				grpcInfo->set_message(item.message);
			}
		}

		Status status = this->stub_->HandleRequest(&ctx, request, &response);
		
		if (status.ok()) {
			std::cout << "Server successfully replied!" << std::endl;
		} else {
			std::cout << "Server replied with errors: " << status.error_message() << std::endl;
		}

		return response;
	}

	void RunClient(int port) {
		std::string server_address = absl::StrFormat("localhost:%d", port);
		V1ServiceImpl service(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
		while (true) {
			ServerReqeust req;

			req.UUID = "1234";
			req.deviceUUID = "5678";
			req.statusId = 1;

			ServerInformation si;
			si.typeId = 1;
			si.message = "OK";

			req.information = {si};

			service.ServerRequest(req);
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}