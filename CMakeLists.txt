cmake_minimum_required(VERSION 3.27)
project(ClientServer)

set(CMAKE_CXX_STANDARD 17)
option(BUILD_DOC "Build Documentation" TRUE)
option(BUILD_TEST "Build Test" TRUE)

include(${CMAKE_SOURCE_DIR}/cmake/getGitHash.cmake)

include(${CMAKE_SOURCE_DIR}/cmake/checkBuild.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/generateDoc.cmake)

add_subdirectory(src)
add_subdirectory(test)