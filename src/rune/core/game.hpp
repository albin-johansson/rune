#ifndef RUNE_CORE_GAME_HPP
#define RUNE_CORE_GAME_HPP

#include <concepts>  // convertible_to

#include "../aliases/delta_time.hpp"
#include "graphics.hpp"
#include "input.hpp"

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

/**
 * \brief Ensures that a type satisfies the requirements of a game class.
 *
 * \details `handle_input()` is where the game should respond to user input. Note, `
 * handle_input()` is called before `tick()`.
 *
 * \details `tick()` should update the state of the game by one "tick".
 *
 * \details `render()` should render the current game state.
 *
 * \details `should_quit()` should indicate if the game should shut down.
 *
 * \note There are a few optional "event" functions that you can define. These are
 * `void init(graphics_type&)`, `void on_start()` and `void on_exit()`.
 *
 * \tparam Game the game type.
 * \tparam Graphics the graphics context type.
 */
template <typename Game, typename Graphics>
concept is_game_type = requires (Game game, Graphics& gfx, const input& input, delta_time dt)
{
  { game.handle_input(input) };
  { game.tick(dt) };
  { game.render(gfx) };
  { game.should_quit() } -> std::convertible_to<bool>;
};

template <typename Game, typename Graphics>
concept has_init = requires (Game game, Graphics& gfx)
{
  { game.init(gfx) };
};

template <typename Game>
concept has_on_start = requires (Game game)
{
  { game.on_start() };
};

template <typename Game>
concept has_on_exit = requires (Game game)
{
  { game.on_exit() };
};

// clang-format on

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GAME_HPP