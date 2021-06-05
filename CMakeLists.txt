cmake_minimum_required(VERSION 3.17)

project(rune CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(RUNE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(RUNE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/rune)
set(RUNE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(RUNE_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/lib)
set(RUNE_RESOURCES_DIR ${PROJECT_SOURCE_DIR}/resources)

option(RUNE_BUILD_EXAMPLES "Build the example programs" ON)
set(RUNE_BUILD_EXAMPLES ON)

include(Utilities)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_header_only_lib(EnTT ${RUNE_LIBRARY_DIR}/entt ${RUNE_LIBRARY_DIR}/entt/entt.hpp)
add_header_only_lib(Centurion ${RUNE_LIBRARY_DIR}/centurion ${RUNE_LIBRARY_DIR}/centurion/centurion.hpp)
add_header_only_lib(JSON ${RUNE_LIBRARY_DIR}/json ${RUNE_LIBRARY_DIR}/json/json.hpp)
add_header_only_lib(Nenya ${RUNE_LIBRARY_DIR}/nenya ${RUNE_LIBRARY_DIR}/nenya/nenya.hpp)

add_subdirectory(test)

if (RUNE_BUILD_EXAMPLES)
  add_subdirectory(examples/pong)
  add_subdirectory(examples/ui)
endif ()