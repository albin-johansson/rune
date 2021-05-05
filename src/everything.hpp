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

#include "rune/aabb_tree.hpp"
#include "rune/almost_equal.hpp"
#include "rune/compiler.hpp"
#include "rune/concepts.hpp"
#include "rune/engine.hpp"
#include "rune/game.hpp"
#include "rune/ini.hpp"
#include "rune/integers.hpp"
#include "rune/json_utils.hpp"
#include "rune/semi_fixed_game_loop.hpp"
#include "rune/stack_resource.hpp"
#include "rune/static_vector.hpp"
#include "rune/tiled.hpp"
#include "rune/tmx/tmx_color.hpp"
#include "rune/tmx/tmx_text.hpp"
#include "rune/to_string.hpp"
#include "rune/vector2.hpp"
