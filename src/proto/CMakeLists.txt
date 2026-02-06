find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(PROTO_FILES v1.proto)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_FILES})

add_library(myproto STATIC
        ${PROTO_SRCS}
        ${PROTO_HDRS}
        ${GRPC_SRCS}
        ${GRPC_HDRS}
)

target_link_libraries(myproto
        PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

target_include_directories(myproto
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
)