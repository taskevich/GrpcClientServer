find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/impl CORE_IMPL_SOURCES)

add_library(Core STATIC ${CORE_IMPL_SOURCES})

target_include_directories(Core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/proto
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/impl
)

target_link_libraries(Core
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)