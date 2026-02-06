#include <iostream>

#include "core/include/client.h"

int main() {
    GrpcClient::RunClient(5001);
    return 0;
}