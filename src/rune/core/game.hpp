#pragma once

#include <concepts>  // convertible_to

#include "../aliases/delta_time.hpp"
#include "graphics.hpp"
#include "input.hpp"

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

template <typename T>
concept game_type = requires (T game, const input& input, graphics& graphics, delta_time dt)
{
  { game.handle_input(input) };
  { game.tick(dt) };
  { game.render(graphics) };
  { game.should_quit() } -> std::convertible_to<bool>;
};

template <typename T>
concept has_on_start = requires (T game)
{
  { game.on_start() };
};

template <typename T>
concept has_on_exit = requires (T game)
{
  { game.on_exit() };
};

// clang-format on

/// \} End of group core

}  // namespace rune
