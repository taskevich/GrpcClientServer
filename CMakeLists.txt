cmake_minimum_required(VERSION 4.1)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(GrpcClientServer)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
