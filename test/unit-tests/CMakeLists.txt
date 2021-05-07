cmake_minimum_required(VERSION 3.17)

project(rune-test-unit-tests CXX)

set(SOURCE_FILES
    serialization_utils.hpp
    test_main.cpp

    rune/core/game_test.cpp
    rune/core/to_string_test.cpp

    rune/math/almost_equal_test.cpp
    rune/math/vector2_test.cpp

    rune/tmx/tmx_animation_test.cpp
    rune/tmx/tmx_color_test.cpp
    rune/tmx/tmx_grid_test.cpp
    rune/tmx/tmx_layer_test.cpp
    rune/tmx/tmx_object_test.cpp
    rune/tmx/tmx_point_test.cpp
    rune/tmx/tmx_property_test.cpp
    rune/tmx/tmx_text_test.cpp
    rune/tmx/tmx_tile_offset_test.cpp
    rune/tmx/tmx_tileset_test.cpp
    rune/tmx/tmx_wang_color_test.cpp
    rune/tmx/tmx_wang_set_test.cpp
    rune/tmx/tmx_wang_tile_test.cpp
    )

add_executable(UnitTests ${SOURCE_FILES})
set_compiler_options(UnitTests)

add_header_only_lib(EnTT ${RUNE_LIBRARY_DIR}/entt ${RUNE_LIBRARY_DIR}/entt/entt.hpp)
add_header_only_lib(Centurion ${RUNE_LIBRARY_DIR}/centurion ${RUNE_LIBRARY_DIR}/centurion/centurion.hpp)
add_header_only_lib(JSON ${RUNE_LIBRARY_DIR}/json ${RUNE_LIBRARY_DIR}/json/json.hpp)
add_header_only_lib(Nenya ${RUNE_LIBRARY_DIR}/nenya ${RUNE_LIBRARY_DIR}/nenya/nenya.hpp)

set(TEST_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/../lib)

target_include_directories(UnitTests
    PUBLIC .
    PUBLIC ${RUNE_SOURCE_DIR}
    SYSTEM PUBLIC ${SDL2_INCLUDE_DIR}
    SYSTEM PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
    SYSTEM PUBLIC ${SDL2_MIXER_INCLUDE_DIRS}
    SYSTEM PUBLIC ${SDL2_TTF_INCLUDE_DIRS}
    SYSTEM PUBLIC ${TEST_LIBRARY_DIR}/cereal
    SYSTEM PUBLIC ${gtest_SOURCE_DIR}/include
    SYSTEM PUBLIC ${gtest_SOURCE_DIR}
    SYSTEM PUBLIC ${gmock_SOURCE_DIR}/include
    SYSTEM PUBLIC ${gmock_SOURCE_DIR})

target_link_libraries(UnitTests
    PUBLIC ${SDL2_IMAGE_LIBRARIES}
    PUBLIC ${SDL2_MIXER_LIBRARIES}
    PUBLIC ${SDL2_TTF_LIBRARIES}
    PUBLIC ${SDL2_LIBRARY}
    PUBLIC Centurion
    PUBLIC EnTT
    PUBLIC JSON
    PUBLIC Nenya
    PUBLIC gtest)

add_test(NAME UnitTests COMMAND UnitTests)

if (WIN32)
  copy_directory_post_build(UnitTests ${RUNE_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
endif ()

copy_directory_post_build(UnitTests ${RUNE_RESOURCES_DIR} ${CMAKE_CURRENT_BINARY_DIR}/resources)