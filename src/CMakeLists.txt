cmake_minimum_required(VERSION 3.17)

project(rune-src CXX)

set(SOURCE_FILES
    ${RUNE_INCLUDE_DIR}/rune_api.hpp

    ${RUNE_INCLUDE_DIR}/aliases/delta_time.hpp
    ${RUNE_INCLUDE_DIR}/aliases/font_id.hpp
    ${RUNE_INCLUDE_DIR}/aliases/integers.hpp
    ${RUNE_INCLUDE_DIR}/aliases/json_type.hpp
    ${RUNE_INCLUDE_DIR}/aliases/maybe.hpp
    ${RUNE_INCLUDE_DIR}/aliases/str.hpp
    ${RUNE_INCLUDE_DIR}/aliases/texture_id.hpp
    ${RUNE_INCLUDE_DIR}/aliases/texture_index.hpp

    ${RUNE_INCLUDE_DIR}/containers/aabb.hpp
    ${RUNE_INCLUDE_DIR}/containers/aabb_node.hpp
    ${RUNE_INCLUDE_DIR}/containers/aabb_tree.hpp
    ${RUNE_INCLUDE_DIR}/containers/stack_resource.hpp
    ${RUNE_INCLUDE_DIR}/containers/static_vector.hpp
    ${RUNE_INCLUDE_DIR}/containers/vector_map.hpp

    ${RUNE_INCLUDE_DIR}/core/compiler.hpp
    ${RUNE_INCLUDE_DIR}/core/engine.hpp
    ${RUNE_INCLUDE_DIR}/core/from_string.hpp
    ${RUNE_INCLUDE_DIR}/core/game.hpp
    ${RUNE_INCLUDE_DIR}/core/graphics.hpp
    ${RUNE_INCLUDE_DIR}/core/input.hpp
    ${RUNE_INCLUDE_DIR}/core/rune_error.hpp
    ${RUNE_INCLUDE_DIR}/core/semi_fixed_game_loop.hpp

    ${RUNE_INCLUDE_DIR}/ecs/entity_type.hpp
    ${RUNE_INCLUDE_DIR}/ecs/null_entity.hpp

    ${RUNE_INCLUDE_DIR}/ecs/events/button_pressed_event.hpp
    ${RUNE_INCLUDE_DIR}/ecs/events/key_bind_triggered_event.hpp

    ${RUNE_INCLUDE_DIR}/ecs/ui/button_system.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/key_bind_system.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/label_system.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/lazy_texture_system.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/line_system.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/menu_system.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_background.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_button.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_checkbox.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_foreground.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_grid.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_key_bind.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_label.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_lazy_texture.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_line.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_menu.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_position.hpp
    ${RUNE_INCLUDE_DIR}/ecs/ui/ui_system.hpp

    ${RUNE_INCLUDE_DIR}/io/ini.hpp
    ${RUNE_INCLUDE_DIR}/io/ini_section.hpp
    ${RUNE_INCLUDE_DIR}/io/ini_value.hpp
    ${RUNE_INCLUDE_DIR}/io/json_utils.hpp

    ${RUNE_INCLUDE_DIR}/math/almost_equal.hpp
    ${RUNE_INCLUDE_DIR}/math/index_to_matrix.hpp
    ${RUNE_INCLUDE_DIR}/math/max.hpp
    ${RUNE_INCLUDE_DIR}/math/min.hpp
    ${RUNE_INCLUDE_DIR}/math/random_utils.hpp
    ${RUNE_INCLUDE_DIR}/math/vector2.hpp

    ${RUNE_INCLUDE_DIR}/tmx/parse_tileset.hpp
    ${RUNE_INCLUDE_DIR}/tmx/parse_tmx.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_animation.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_color.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_data.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_global_id.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_grid.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_halign.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_image_layer.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_layer.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_layer_type.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_local_id.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_map.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_map_orientation.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_map_render_order.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_object.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_object_layer.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_point.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_property.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_property_type.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_stagger_axis.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_stagger_index.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_terrain.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_text.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_tile.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_tile_layer.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_tile_layer_compression.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_tile_layer_encoding.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_tile_offset.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_tileset.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_valign.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_wang_color.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_wang_set.hpp
    ${RUNE_INCLUDE_DIR}/tmx/tmx_wang_tile.hpp

    ecs/ui/button_system.cpp
    ecs/ui/key_bind_system.cpp
    ecs/ui/label_system.cpp
    ecs/ui/lazy_texture_system.cpp
    ecs/ui/line_system.cpp
    ecs/ui/menu_system.cpp
    ecs/ui/ui_system.cpp

    io/json_utils.cpp

    math/random_utils.cpp

    tmx/parse_tmx.cpp
    tmx/parse_tileset.cpp
    tmx/tmx_parsers.cpp)

add_library(${RUNE_LIBRARY_TARGET} SHARED ${SOURCE_FILES})

if (WIN32)
  target_compile_definitions(${RUNE_LIBRARY_TARGET}
      PRIVATE RUNE_EXPORT
      PRIVATE ENTT_API_EXPORT)
endif ()

set_compiler_options(${RUNE_LIBRARY_TARGET})

target_include_directories(${RUNE_LIBRARY_TARGET}
    PUBLIC ${RUNE_INCLUDE_DIR}
    PUBLIC ${RUNE_SOURCE_DIR}
    SYSTEM PUBLIC ${SDL2_INCLUDE_DIR}
    SYSTEM PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS}
    SYSTEM PUBLIC ${SDL2_MIXER_INCLUDE_DIRS}
    SYSTEM PUBLIC ${SDL2_TTF_INCLUDE_DIRS})

target_link_libraries(${RUNE_LIBRARY_TARGET}
    PUBLIC ${SDL2_IMAGE_LIBRARIES}
    PUBLIC ${SDL2_MIXER_LIBRARIES}
    PUBLIC ${SDL2_TTF_LIBRARIES}
    PUBLIC ${SDL2_LIBRARY}
    PUBLIC Centurion
    PUBLIC Nenya
    PUBLIC EnTT
    PUBLIC JSON)