cmake_minimum_required(VERSION 3.17)

project(rune-examples CXX)

macro(configure_example target)
  target_include_directories(${target} SYSTEM PUBLIC ${RUNE_INCLUDE_DIR})
  target_link_libraries(${target} PUBLIC ${RUNE_LIBRARY_TARGET})

  if (WIN32)
    copy_directory_post_build(${target} ${RUNE_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  endif ()

  copy_directory_post_build(${target} ${RUNE_RESOURCES_DIR} ${CMAKE_CURRENT_BINARY_DIR}/resources)
endmacro()

add_subdirectory(pong)
