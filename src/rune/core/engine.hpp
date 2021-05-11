#ifndef RUNE_CORE_ENGINE_HPP
#define RUNE_CORE_ENGINE_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // window
#include <concepts>       // derived_from
#include <optional>       // optional

#include "game.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "semi_fixed_game_loop.hpp"

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

// clang-format on

template <typename Game, std::derived_from<graphics> Graphics = graphics>
requires game_type<Game, Graphics> class engine
{
 public:
  using game_type = Game;
  using graphics_type = Graphics;
  using loop_type = semi_fixed_game_loop<game_type, graphics_type>;

  static_assert(std::constructible_from<game_type, graphics_type&> ||
                    std::default_initializable<game_type>,
                "Game class must either be default constructible or provide a "
                "constructor that accepts \"graphics_type&\"");

  engine() : m_loop{this}, m_window{"Rune window"}, m_graphics{m_window}
  {
    if constexpr (std::constructible_from<game_type, graphics_type&>)
    {
      m_game.emplace(m_graphics);

      if constexpr (has_init<game_type, graphics_type>)
      {
        CENTURION_LOG_WARN(
            "rune::engine > game_type::init(graphics_type&) is not called when "
            "game_type has a constructor that accepts \"graphics_type&\"");
      }
    }
    else if constexpr (std::default_initializable<game_type>)
    {
      m_game.emplace();
      if constexpr (has_init<game_type, graphics_type>)
      {
        m_game->init(m_graphics);
      }
    }
  }

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

  auto run() -> int
  {
    m_window.show();

    m_loop.fetch_current_time();

    if constexpr (has_on_start<Game>)
    {
      m_game->on_start();
    }

    auto& renderer = m_graphics.renderer();
    while (m_loop.is_running())
    {
      m_loop.tick();

      renderer.clear_with(cen::colors::black);
      m_game->render(m_graphics);
      renderer.present();
    }

    if constexpr (has_on_exit<Game>)
    {
      m_game->on_exit();
    }

    m_window.hide();

    return 0;
  }

  [[nodiscard]] auto get_window() noexcept -> cen::window&
  {
    return m_window;
  }

  [[nodiscard]] auto get_window() const noexcept -> const cen::window&
  {
    return m_window;
  }

  [[nodiscard]] auto get_game() -> game_type&
  {
    assert(m_game);
    return *m_game;
  }

  [[nodiscard]] auto get_game() const -> const game_type&
  {
    assert(m_game);
    return *m_game;
  }

  [[nodiscard]] auto get_graphics() noexcept -> graphics_type&
  {
    return m_graphics;
  }

  [[nodiscard]] auto get_graphics() const noexcept -> const graphics_type&
  {
    return m_graphics;
  }

  [[nodiscard]] auto get_input() noexcept -> input&
  {
    return m_input;
  }

  [[nodiscard]] auto get_input() const noexcept -> const input&
  {
    return m_input;
  }

 private:
  loop_type m_loop;

  cen::window m_window;
  graphics_type m_graphics;
  input m_input;

  std::optional<game_type> m_game;  // Optional to delay initialization
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_ENGINE_HPP
