add_subdirectory(core)

add_executable(server main.cpp)

target_link_libraries(server
    PRIVATE
        Core
)

target_link_libraries(Core
    PUBLIC
        myproto
)
