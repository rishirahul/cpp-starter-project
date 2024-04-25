project(Client VERSION 1.0.2)
include(${CMAKE_SOURCE_DIR}/cmake/generateVersionHeader.cmake)
include_directories(${CMAKE_SOURCE_DIR}/src/CppSocketLib)
generateVerHeader(${CMAKE_CURRENT_BINARY_DIR})
add_library (serverLib
        Server.cpp
        )
