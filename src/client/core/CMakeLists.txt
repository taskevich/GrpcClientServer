find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

aux_source_directory(impl CORE_IMPL_SOURCES)

add_library(CoreClient STATIC
    ${CORE_IMPL_SOURCES}
    proto/v1.pb.cc
    proto/v1.grpc.pb.cc
)

target_include_directories(CoreClient
    PUBLIC
        include
        proto
)

target_link_libraries(CoreClient
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)
