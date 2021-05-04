cmake_minimum_required(VERSION 3.17)

project(rune-test-unit-tests CXX)

set(SOURCE_FILES
    serialization_utils.hpp
    test_main.cpp
    vector2_test.cpp
    rune/almost_equal_test.cpp
    rune/to_string_test.cpp
    )

add_executable(UnitTests ${SOURCE_FILES})
set_compiler_options(UnitTests)

set(TEST_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/../lib)

target_include_directories(UnitTests
    PUBLIC .
    PUBLIC ${RUNE_SOURCE_DIR}
    SYSTEM PUBLIC ${TEST_LIBRARY_DIR}/cereal
    SYSTEM PUBLIC ${gtest_SOURCE_DIR}/include
    SYSTEM PUBLIC ${gtest_SOURCE_DIR}
    SYSTEM PUBLIC ${gmock_SOURCE_DIR}/include
    SYSTEM PUBLIC ${gmock_SOURCE_DIR})

target_link_libraries(UnitTests
    PUBLIC gtest)

add_test(NAME UnitTests COMMAND UnitTests)