#include <iostream>

#include "core/include/server.h"

int main() {
    GrpcServer::RunServer(5001);
    return 0;
}