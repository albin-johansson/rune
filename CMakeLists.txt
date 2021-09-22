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

add_subdirectory(test)

if (RUNE_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif ()