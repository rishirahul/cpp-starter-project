if (BUILD_TEST)
    message("TEST SWITCHED ON")
    project(${CMAKE_PROJECT_NAME}_tests)

    # Clone Google Test
    set(GOOGLETEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest)
    if (NOT EXISTS ${GOOGLETEST_DIR})
        find_package(Git REQUIRED)
        execute_process(
                COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
        )
    endif ()

    add_subdirectory(lib/googletest)
    add_subdirectory(unit_tests)
else (BUILD_TEST)
    message("TEST SWITCHED OFF")
endif (BUILD_TEST)