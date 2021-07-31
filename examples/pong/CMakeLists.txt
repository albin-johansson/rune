cmake_minimum_required(VERSION 3.17)

project(rune-examples-pong CXX)

add_executable(Pong pong.cpp)
set_compiler_options(Pong)

configure_example(Pong)
