set(GIT_HASH "unknown")
# find Git and if available set GIT_HASH variable
find_package(Git QUIET)

set(FILE_EXISTS FALSE)
if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
    set(FILE_EXISTS TRUE)
else ()
    message(STATUS "This is not a github repository")
endif ()


if(GIT_FOUND AND FILE_EXISTS)
    execute_process(
        COMMAND git log -1 --pretty=format:%h
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
endif()

message(STATUS "Git hash is ${GIT_HASH}")
