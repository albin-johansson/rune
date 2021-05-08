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

#pragma once

#include "rune/aliases/czstring.hpp"
#include "rune/core/aabb_tree.hpp"
#include "rune/core/compiler.hpp"
#include "rune/core/concepts.hpp"
#include "rune/core/engine.hpp"
#include "rune/core/game.hpp"
#include "rune/core/rune_error.hpp"
#include "rune/core/semi_fixed_game_loop.hpp"
#include "rune/core/to_string.hpp"
#include "rune/doxygen.hpp"
#include "rune/generic/stack_resource.hpp"
#include "rune/generic/static_vector.hpp"
#include "rune/io/ini.hpp"
#include "rune/io/json_utils.hpp"
#include "rune/math/almost_equal.hpp"
#include "rune/math/vector2.hpp"
#include "rune/tmx/parse_tileset.hpp"
#include "rune/tmx/tmx.hpp"
#include "rune/tmx/tmx_animation.hpp"
#include "rune/tmx/tmx_color.hpp"
#include "rune/tmx/tmx_data.hpp"
#include "rune/tmx/tmx_global_id.hpp"
#include "rune/tmx/tmx_grid.hpp"
#include "rune/tmx/tmx_image_layer.hpp"
#include "rune/tmx/tmx_layer.hpp"
#include "rune/tmx/tmx_layer_type.hpp"
#include "rune/tmx/tmx_local_id.hpp"
#include "rune/tmx/tmx_map.hpp"
#include "rune/tmx/tmx_object.hpp"
#include "rune/tmx/tmx_object_layer.hpp"
#include "rune/tmx/tmx_parsers.hpp"
#include "rune/tmx/tmx_point.hpp"
#include "rune/tmx/tmx_property.hpp"
#include "rune/tmx/tmx_terrain.hpp"
#include "rune/tmx/tmx_text.hpp"
#include "rune/tmx/tmx_tile.hpp"
#include "rune/tmx/tmx_tile_layer.hpp"
#include "rune/tmx/tmx_tile_offset.hpp"
#include "rune/tmx/tmx_tileset.hpp"
#include "rune/tmx/tmx_wang_color.hpp"
#include "rune/tmx/tmx_wang_set.hpp"
#include "rune/tmx/tmx_wang_tile.hpp"
