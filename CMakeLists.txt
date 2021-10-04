cmake_minimum_required(VERSION 3.17)

project(rune
    VERSION 0.1.0
    HOMEPAGE_URL "https://github.com/albin-johansson/rune"
    LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(RUNE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(RUNE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(RUNE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(RUNE_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/lib)
set(RUNE_RESOURCES_DIR ${PROJECT_SOURCE_DIR}/resources)

set(RUNE_LIBRARY_TARGET rune)

option(RUNE_BUILD_EXAMPLES "Build the example programs" ON)

include(Utilities)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library(${RUNE_LIBRARY_TARGET} INTERFACE)

target_sources(${RUNE_LIBRARY_TARGET} PUBLIC INTERFACE
    include/common/font_id.hpp
    include/common/integers.hpp
    include/common/json_type.hpp
    include/common/maybe.hpp
    include/common/str.hpp
    include/common/texture_id.hpp
    include/common/texture_index.hpp
    include/containers/aabb.hpp
    include/containers/aabb_node.hpp
    include/containers/aabb_tree.hpp
    include/containers/stack_resource.hpp
    include/containers/static_vector.hpp
    include/containers/vector_map.hpp
    include/core/compiler.hpp
    include/core/configuration.hpp
    include/core/engine.hpp
    include/core/from_string.hpp
    include/core/graphics.hpp
    include/core/input.hpp
    include/core/iterable.hpp
    include/core/rune_error.hpp
    include/ecs/ecs_utils.hpp
    include/ecs/entity_type.hpp
    include/ecs/null_entity.hpp
    include/ecs/events/button_pressed_event.hpp
    include/ecs/events/key_bind_triggered_event.hpp
    include/io/csv.hpp
    include/math/almost_equal.hpp
    include/math/index_to_matrix.hpp
    include/math/max.hpp
    include/math/min.hpp
    include/math/random_utils.hpp
    include/math/vector2.hpp
    include/everything.hpp
    )

target_include_directories(${RUNE_LIBRARY_TARGET}
    PUBLIC INTERFACE
    ${PROJECT_SOURCE_DIR}/include

    SYSTEM PUBLIC INTERFACE
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${RUNE_LIBRARY_DIR}/centurion
    ${RUNE_LIBRARY_DIR}/entt
    ${RUNE_LIBRARY_DIR}/json
    ${RUNE_LIBRARY_DIR}/nenya
    ${RUNE_LIBRARY_DIR}/init
    )

target_link_libraries(${RUNE_LIBRARY_TARGET}
    PUBLIC INTERFACE
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    )

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${RUNE_LIBRARY_TARGET} PUBLIC INTERFACE
      /EHsc
      /MP
      /W3
      /Zc:__cplusplus  # Force MSVC to use __cplusplus macro with correct value
      /Zc:preprocessor # Enable conforming preprocessor
      /wd5105          # "macro expansion producing 'defined' has undefined behavior"
      )

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_options(${RUNE_LIBRARY_TARGET} PUBLIC INTERFACE
      /EHsc
      )

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${RUNE_LIBRARY_TARGET} PUBLIC INTERFACE
      -Wall
      -Wextra
      -Wpedantic
      -Wconversion
      )
endif ()

add_subdirectory(test)

if (RUNE_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif ()