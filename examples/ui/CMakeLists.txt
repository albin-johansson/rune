cmake_minimum_required(VERSION 3.17)

project(rune-examples-ui CXX)

add_executable(UIExample ui_example.cpp)
set_compiler_options(UIExample)

target_include_directories(UIExample
    SYSTEM PUBLIC ${RUNE_INCLUDE_DIR}
    SYSTEM PUBLIC ${SDL2_INCLUDE_DIR}
    SYSTEM PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
    SYSTEM PUBLIC ${SDL2_MIXER_INCLUDE_DIRS}
    SYSTEM PUBLIC ${SDL2_TTF_INCLUDE_DIRS})

target_link_libraries(UIExample
    PUBLIC ${SDL2_IMAGE_LIBRARIES}
    PUBLIC ${SDL2_MIXER_LIBRARIES}
    PUBLIC ${SDL2_TTF_LIBRARIES}
    PUBLIC ${SDL2_LIBRARY}
    PUBLIC Centurion
    PUBLIC EnTT
    PUBLIC JSON
    PUBLIC Nenya)

if (WIN32)
  copy_directory_post_build(UIExample ${RUNE_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
endif ()
