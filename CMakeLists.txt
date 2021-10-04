cmake_minimum_required(VERSION 3.17)

project(rune
    VERSION 0.1.0
    HOMEPAGE_URL "https://github.com/albin-johansson/rune"
    LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

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
    src/common/cstr.hpp
    src/common/integers.hpp
    src/common/maybe.hpp
    src/containers/aabb.hpp
    src/containers/aabb_node.hpp
    src/containers/aabb_tree.hpp
    src/containers/stack_resource.hpp
    src/containers/static_vector.hpp
    src/containers/vector_map.hpp
    src/core/compiler.hpp
    src/core/configuration.hpp
    src/core/engine.hpp
    src/core/from_string.hpp
    src/core/rune_error.hpp
    src/io/csv.hpp
    src/math/almost_equal.hpp
    src/math/index_to_matrix.hpp
    src/math/max.hpp
    src/math/min.hpp
    src/math/random_utils.hpp
    src/math/vector2.hpp
    src/rune.hpp
    )

target_include_directories(${RUNE_LIBRARY_TARGET}
    PUBLIC INTERFACE
    ${PROJECT_SOURCE_DIR}/src

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