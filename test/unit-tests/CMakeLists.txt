cmake_minimum_required(VERSION 3.17)

project(rune-test-unit-tests CXX)

set(TEST_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/../lib)

set(SOURCE_FILES
    serialization_utils.hpp
    test_main.cpp

    rune/containers/aabb_test.cpp
    rune/containers/aabb_tree_test.cpp
    rune/containers/stack_resource_test.cpp
    rune/containers/static_vector_test.cpp
    rune/containers/vector_map_test.cpp

    rune/core/compiler_test.cpp
    rune/core/configuration_test.cpp
    rune/core/from_string_test.cpp

    rune/io/csv_test.cpp

    rune/math/almost_equal_test.cpp
    rune/math/index_to_matrix_test.cpp
    rune/math/min_test.cpp
    rune/math/max_test.cpp
    rune/math/random_utils_test.cpp
    rune/math/vector2_test.cpp
    )

add_executable(UnitTests ${SOURCE_FILES})
add_dependencies(UnitTests ${RUNE_LIBRARY_TARGET})

target_precompile_headers(UnitTests PRIVATE
    <array>
    <algorithm>
    <vector>
    <string>
    <concepts>
    <unordered_map>
    <functional>
    <utility>
    <type_traits>

    <centurion.hpp>
    <entt.hpp>
    )

if (MSVC)
  target_compile_options(UnitTests PRIVATE
      /wd4834  # "discarding return value of function with 'nodiscard' attribute"
      )
endif ()

target_compile_definitions(UnitTests
    PRIVATE
    ENTT_STANDARD_CPP
    RUNE_DEBUG_CONTAINERS
    )

target_include_directories(UnitTests
    PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${RUNE_SOURCE_DIR}

    SYSTEM PRIVATE
    ${TEST_LIBRARY_DIR}/cereal
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}
    )

target_link_libraries(UnitTests PRIVATE
    ${RUNE_LIBRARY_TARGET}
    gtest
    )

add_test(NAME UnitTests COMMAND UnitTests)

if (WIN32)
  copy_directory_post_build(UnitTests ${RUNE_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
endif ()

copy_directory_post_build(UnitTests ${RUNE_RESOURCES_DIR} ${CMAKE_CURRENT_BINARY_DIR}/resources)