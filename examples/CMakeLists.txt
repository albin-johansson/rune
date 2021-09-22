cmake_minimum_required(VERSION 3.17)

project(rune-examples CXX)

macro(configure_example target)
  target_include_directories(${target}
      SYSTEM PUBLIC ${RUNE_INCLUDE_DIR}
      SYSTEM PUBLIC ${SDL2_INCLUDE_DIR}
      SYSTEM PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
      SYSTEM PUBLIC ${SDL2_MIXER_INCLUDE_DIRS}
      SYSTEM PUBLIC ${SDL2_TTF_INCLUDE_DIRS}
      SYSTEM PUBLIC ${RUNE_LIBRARY_DIR}/centurion
      SYSTEM PUBLIC ${RUNE_LIBRARY_DIR}/entt
      SYSTEM PUBLIC ${RUNE_LIBRARY_DIR}/json
      SYSTEM PUBLIC ${RUNE_LIBRARY_DIR}/nenya
      )

  target_link_libraries(${target}
      PUBLIC ${SDL2_IMAGE_LIBRARIES}
      PUBLIC ${SDL2_MIXER_LIBRARIES}
      PUBLIC ${SDL2_TTF_LIBRARIES}
      PUBLIC ${SDL2_LIBRARY})

  if (WIN32)
    copy_directory_post_build(${target} ${RUNE_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  endif ()

  copy_directory_post_build(${target} ${RUNE_RESOURCES_DIR} ${CMAKE_CURRENT_BINARY_DIR}/resources)
endmacro()

add_subdirectory(pong)
add_subdirectory(ui)