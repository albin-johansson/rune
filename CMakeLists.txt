cmake_minimum_required(VERSION 3.17)

project(rune
    LANGUAGES CXX
    VERSION 0.1.0
    HOMEPAGE_URL "https://github.com/albin-johansson/rune")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(RUNE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/rune)
set(RUNE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(RUNE_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/lib)

include(Utilities)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_subdirectory(test)