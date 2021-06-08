/*
 * MIT License
 * Copyright (c) 2021 Albin Johansson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef RUNE_NO_PRAGMA_ONCE
#pragma once
#endif  // RUNE_NO_PRAGMA_ONCE

#include "rune/aliases/czstring.hpp"
#include "rune/aliases/delta_time.hpp"
#include "rune/aliases/font_id.hpp"
#include "rune/aliases/integers.hpp"
#include "rune/aliases/json_type.hpp"
#include "rune/aliases/texture_id.hpp"
#include "rune/aliases/texture_index.hpp"
#include "rune/containers/aabb.hpp"
#include "rune/containers/aabb_node.hpp"
#include "rune/containers/aabb_tree.hpp"
#include "rune/containers/stack_resource.hpp"
#include "rune/containers/static_vector.hpp"
#include "rune/containers/vector_map.hpp"
#include "rune/core/compiler.hpp"
#include "rune/core/concepts.hpp"
#include "rune/core/engine.hpp"
#include "rune/core/from_string.hpp"
#include "rune/core/game.hpp"
#include "rune/core/rune_error.hpp"
#include "rune/core/semi_fixed_game_loop.hpp"
#include "rune/core/to_string.hpp"
#include "rune/doxygen.hpp"
#include "rune/ecs/entity_type.hpp"
#include "rune/ecs/events/button_pressed_event.hpp"
#include "rune/ecs/null_entity.hpp"
#include "rune/ecs/ui/button_system.hpp"
#include "rune/ecs/ui/label_system.hpp"
#include "rune/ecs/ui/line_system.hpp"
#include "rune/ecs/ui/ui_button.hpp"
#include "rune/ecs/ui/ui_checkbox.hpp"
#include "rune/ecs/ui/ui_foreground.hpp"
#include "rune/ecs/ui/ui_grid.hpp"
#include "rune/ecs/ui/ui_key_bind.hpp"
#include "rune/ecs/ui/ui_label.hpp"
#include "rune/ecs/ui/ui_line.hpp"
#include "rune/ecs/ui/ui_menu.hpp"
#include "rune/ecs/ui/ui_position.hpp"
#include "rune/ecs/ui/ui_system.hpp"
#include "rune/io/ini.hpp"
#include "rune/io/ini_value.hpp"
#include "rune/io/json_utils.hpp"
#include "rune/math/almost_equal.hpp"
#include "rune/math/index_to_matrix.hpp"
#include "rune/math/max.hpp"
#include "rune/math/min.hpp"
#include "rune/math/random_utils.hpp"
#include "rune/math/vector2.hpp"
#include "rune/tmx/parse_tileset.hpp"
#include "rune/tmx/parse_tmx.hpp"
#include "rune/tmx/tmx_animation.hpp"
#include "rune/tmx/tmx_color.hpp"
#include "rune/tmx/tmx_data.hpp"
#include "rune/tmx/tmx_global_id.hpp"
#include "rune/tmx/tmx_grid.hpp"
#include "rune/tmx/tmx_halign.hpp"
#include "rune/tmx/tmx_image_layer.hpp"
#include "rune/tmx/tmx_layer.hpp"
#include "rune/tmx/tmx_layer_type.hpp"
#include "rune/tmx/tmx_local_id.hpp"
#include "rune/tmx/tmx_map.hpp"
#include "rune/tmx/tmx_map_orientation.hpp"
#include "rune/tmx/tmx_map_render_order.hpp"
#include "rune/tmx/tmx_object.hpp"
#include "rune/tmx/tmx_object_layer.hpp"
#include "rune/tmx/tmx_parsers.hpp"
#include "rune/tmx/tmx_point.hpp"
#include "rune/tmx/tmx_property.hpp"
#include "rune/tmx/tmx_stagger_axis.hpp"
#include "rune/tmx/tmx_stagger_index.hpp"
#include "rune/tmx/tmx_terrain.hpp"
#include "rune/tmx/tmx_text.hpp"
#include "rune/tmx/tmx_tile.hpp"
#include "rune/tmx/tmx_tile_layer.hpp"
#include "rune/tmx/tmx_tile_layer_compression.hpp"
#include "rune/tmx/tmx_tile_layer_encoding.hpp"
#include "rune/tmx/tmx_tile_offset.hpp"
#include "rune/tmx/tmx_tileset.hpp"
#include "rune/tmx/tmx_valign.hpp"
#include "rune/tmx/tmx_wang_color.hpp"
#include "rune/tmx/tmx_wang_set.hpp"
#include "rune/tmx/tmx_wang_tile.hpp"
