add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(CppSocketLib)

add_executable(client dummy.cpp)
target_link_libraries(client clientLib socketLib)

add_executable(server dummy.cpp)
target_link_libraries(server  serverLib socketLib)
