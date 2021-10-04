cmake_minimum_required(VERSION 3.17)

project(rune-test CXX)

enable_testing()

include(GTest)

add_subdirectory(unit-tests)