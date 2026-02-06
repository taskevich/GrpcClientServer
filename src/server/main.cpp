#include <iostream>

#include "core/include/server.h"

int main() {
    while (true) {
        GrpcServer::RunServer(5001);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}