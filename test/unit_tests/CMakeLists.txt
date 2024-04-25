include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(gtest_check
        gtest_check.cpp
)

target_link_libraries(gtest_check gtest gtest_main)