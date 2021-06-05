#ifndef RUNE_CORE_ENGINE_HPP
#define RUNE_CORE_ENGINE_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // window, renderer, ...
#include <concepts>       // derived_from, constructible_from
#include <optional>       // optional

#include "game.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "semi_fixed_game_loop.hpp"

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

template <typename T>
concept is_configuration_type = requires
{
  typename T::graphics_type;
  typename T::delta_type;
  { T::renderer_flags } -> std::convertible_to<uint32>;
  { T::window_size } -> std::convertible_to<cen::iarea>;
};

// clang-format on

/**
 * \struct configuration
 *
 * \brief Provides configuration options for different engine aspects.
 *
 * \note Members are initialized to their default values, meaning that you do not have to
 * assign each member if you create custom configurations.
 *
 * \see `engine`
 */
struct configuration
{
  using graphics_type = graphics;
  using delta_type = float;

  uint32 renderer_flags = cen::renderer::default_flags();
  cen::iarea window_size = cen::window::default_size();
};

static_assert(is_configuration_type<configuration>);

// clang-format off

/**
 * \class engine
 *
 * \brief Represents the core engine in the framework.
 *
 * \details One instance of this should be created in your `main` function, and then
 * call `engine::run()` to launch your game. The game class must either be
 * default-constructible, or provide at least one constructor that accepts
 * `graphics_type&`.
 * \code{cpp}
 * #include <centurion.hpp>
 * #include <rune.hpp>
 *
 * class AwesomeGame
 * {
 *  public:
 *   explicit AwesomeGame(rune::graphics& graphics)
 *   {
 *     // ...
 *   }
 *
 *   void handle_input(const rune::input& input)
 *   {
 *     // ...
 *   }
 *
 *   void tick(rune::delta_time dt)
 *   {
 *     // ...
 *   }
 *
 *   void render(rune::graphics& graphics) const
 *   {
 *     // ...
 *   }
 *
 *   [[nodiscard]] bool should_quit() const
 *   {
 *     // ...
 *   }
 * };
 *
 * int main(int, char**)
 * {
 *   cen::library centurion;  // Remember to initialize Centurion!
 *   rune::engine<AwesomeGame> engine;
 *   return engine.run();
 * }
 * \endcode
 *
 * \tparam Game the type of the game class.
 *
 * \see `is_game_type`
 * \see `graphics`
 */
template <typename Game, std::derived_from<graphics> Graphics = graphics>
    requires is_game_type<Game, Graphics>
class engine
{
  // clang-format on

  // To be able to access update_logic and update_input
  friend class semi_fixed_game_loop<Game, Graphics>;

 public:
  using game_type = Game;          ///< Game class type.
  using graphics_type = Graphics;  ///< Graphics context type.
  using loop_type = semi_fixed_game_loop<Game, graphics_type>;  ///< Game loop type.

  static_assert(std::constructible_from<game_type, graphics_type&> ||
                    std::default_initializable<game_type>,
                "Game class must either be default constructible or provide a "
                "constructor that accepts \"graphics_type&\"");

  /**
   * \brief Creates an engine instance.
   *
   * \param cfg optional custom configuration of the engine.
   */
  explicit engine(const configuration& cfg = default_cfg())
      : m_loop{this}
      , m_window{"Rune", cfg.window_size}
      , m_graphics{m_window, cfg.renderer_flags}
  {
    if constexpr (std::constructible_from<game_type, graphics_type&>)
    {
      m_game.emplace(m_graphics);
    }
    else
    {
      m_game.emplace();
    }

    if constexpr (has_init<game_type, graphics_type>)
    {
      m_game->init(m_graphics);
    }
  }

  /**
   * \brief Starts the game loop and runs the game.
   *
   * \return 0 on success.
   */
  auto run() -> int
  {
    assert(m_game);

    m_window.show();
    m_loop.fetch_current_time();

    if constexpr (has_on_start<game_type>)
    {
      m_game->on_start();
    }

    auto& renderer = m_graphics.renderer();
    while (m_loop.is_running())
    {
      m_loop.tick();
      m_game->render(m_graphics);
    }

    if constexpr (has_on_exit<game_type>)
    {
      m_game->on_exit();
    }
    m_window.hide();

    return 0;
  }

  /**
   * \brief Returns the associated game window.
   *
   * \return the associated window.
   */
  [[nodiscard]] auto get_window() noexcept -> cen::window&
  {
    return m_window;
  }

  /// \copydoc get_window()
  [[nodiscard]] auto get_window() const noexcept -> const cen::window&
  {
    return m_window;
  }

  /**
   * \brief Returns the associated game instance.
   *
   * \return the game instance.
   */
  [[nodiscard]] auto get_game() -> game_type&
  {
    assert(m_game);
    return *m_game;
  }

  /// \copydoc get_game()
  [[nodiscard]] auto get_game() const -> const game_type&
  {
    assert(m_game);
    return *m_game;
  }

  /**
   * \brief Returns the associated graphics context.
   *
   * \return the graphics context.
   */
  [[nodiscard]] auto get_graphics() noexcept -> graphics_type&
  {
    return m_graphics;
  }

  /// \copydoc get_graphics()
  [[nodiscard]] auto get_graphics() const noexcept -> const graphics_type&
  {
    return m_graphics;
  }

  /**
   * \brief Returns the current input state.
   *
   * \return the input state.
   */
  [[nodiscard]] auto get_input() noexcept -> input&
  {
    return m_input;
  }

  /// \copydoc get_input()
  [[nodiscard]] auto get_input() const noexcept -> const input&
  {
    return m_input;
  }

  /**
   * \brief Returns the default configuration used by the engine, if no custom
   * configuration is requested.
   *
   * \return the default engine configuration.
   */
  [[nodiscard]] constexpr static auto default_cfg() -> configuration
  {
    return configuration{};
  }

 private:
  loop_type m_loop;                 ///< The game loop.
  cen::window m_window;             ///< The associated window.
  graphics_type m_graphics;         ///< The graphics context.
  input m_input;                    ///< The input state wrapper.
  std::optional<game_type> m_game;  ///< The game instance, optional delays construction.

  void update_logic(const delta_time dt)
  {
    m_game->tick(dt);
  }

  auto update_input() -> bool
  {
    m_input.mouse.update(m_graphics.renderer().output_size());
    m_input.keyboard.update();

    cen::event::update();

    m_game->handle_input(m_input);

    return !m_game->should_quit() && !cen::event::in_queue(cen::event_type::quit);
  }
};

#define RUNE_IMPLEMENT_MAIN_WITH_GAME(Game) \
  int main(int, char**)                     \
  {                                         \
    cen::library centurion;                 \
    rune::engine<Game> engine;              \
    return engine.run();                    \
  }

#define RUNE_IMPLEMENT_MAIN_WITH_GAME_AND_GRAPHICS(Game, Graphics) \
  int main(int, char**)                                            \
  {                                                                \
    cen::library centurion;                                        \
    rune::engine<Game, Graphics> engine;                           \
    return engine.run();                                           \
  }

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_ENGINE_HPP
