#ifndef RUNE_CORE_GAME_HPP
#define RUNE_CORE_GAME_HPP

#include <concepts>  // convertible_to

#include "../aliases/delta_time.hpp"
#include "graphics.hpp"
#include "input.hpp"

namespace rune {

/// \addtogroup core
/// \{

///**
// * \class game_base
// *
// * \brief The base class for all game class implementations.
// *
// * \details This class should be the base class for the core game class in your game.
// The
// * game loop will call the mandatory functions `handle_input()`, `tick()` and `render()`
// * during each frame, in that order.
// *
// * \details Your derived game classes must either be default-constructible or provide a
// * constructor that accepts `graphics_type&`. The `init()` function is called upon
// * initialization regardless.
// *
// * \tparam Graphics the type of the graphics context.
// *
// * \see `engine`
// * \see `graphics`
// */
// template <std::derived_from<graphics> Graphics = graphics>
// class game_base
//{
// public:
//  using graphics_type = Graphics;
//
//  virtual ~game_base() noexcept = default;
//
//  /**
//   * \brief Called when the game is initialized.
//   *
//   * \details This function is mainly intended to be overridden by game classes that do
//   * not provide a constructor that accepts `graphics_type&`. However, this function is
//   * still called even if the game class provides such a constructor.
//   *
//   * \param graphics the graphics context that will be used.
//   */
//  virtual void init(graphics_type& graphics)
//  {}
//
//  /**
//   * \brief Handles player mouse and keyboard input.
//   *
//   * \note This function is called before `tick()`.
//   *
//   * \param input the current mouse and keyboard state.
//   */
//  virtual void handle_input(const input& input) = 0;
//
//  /**
//   * \brief Updates the state of the game by one "tick".
//   *
//   * \param dt the current delta time.
//   */
//  virtual void tick(delta_time dt) = 0;
//
//  /**
//   * \brief Renders the game.
//   *
//   * \param graphics the graphics context that will be used.
//   */
//  virtual void render(graphics_type& graphics) const = 0;
//
//  /**
//   * \brief Indicates whether or not the game should quit.
//   *
//   * \return `true` if the game should quit; `false` otherwise.
//   */
//  [[nodiscard]] virtual auto should_quit() const -> bool = 0;
//
//  /**
//   * \brief Called just before the first iteration of the game loop.
//   *
//   * \details This function can be useful to perform some additional setup just before
//   the
//   * game starts running.
//   */
//  virtual void on_start()
//  {}
//
//  /**
//   * \brief Called when the game is about to terminate, just after the last iteration of
//   * the game loop.
//   *
//   * \details This function can be useful performing miscellaneous cleanup when the game
//   * is about to shut down.
//   *
//   * \note The game window is still visible when this function is called.
//   */
//  virtual void on_exit()
//  {}
//};

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