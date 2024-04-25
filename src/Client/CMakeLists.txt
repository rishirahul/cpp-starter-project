project(Client VERSION 1.0.1)
include(${CMAKE_SOURCE_DIR}/cmake/generateVersionHeader.cmake)
include_directories(${CMAKE_SOURCE_DIR}/src/CppSocketLib)
generateVerHeader(${CMAKE_CURRENT_BINARY_DIR})
add_library (clientLib
        Client.cpp
        )
