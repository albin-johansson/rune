cmake_minimum_required(VERSION 3.17)

project(rune-examples-pong CXX)

add_executable(Pong pong.cpp)

configure_example(Pong)

copy_file_post_build(Pong ${CMAKE_CURRENT_SOURCE_DIR}/pong.ini ${CMAKE_CURRENT_BINARY_DIR}/pong.ini)