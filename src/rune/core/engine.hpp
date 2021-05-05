#pragma once

#include <centurion.hpp>  // window
#include <concepts>       // derived_from

#include "game.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "semi_fixed_game_loop.hpp"

namespace rune {

// clang-format off

// clang-format on

template <game_type Game, std::derived_from<graphics> Graphics = graphics>
class engine
{
 public:
  using game_type = Game;
  using graphics_type = Graphics;
  using loop_type = semi_fixed_game_loop<game_type, graphics_type>;

  engine()
    : m_loop{this}
    , m_window{"Rune window"}
    , m_graphics{m_window}
  {}

  void update_logic(const delta_time dt)
  {
    m_game.tick(dt);
  }

  auto update_input() -> bool
  {
    m_input.mouse.update(m_graphics.renderer().output_size());
    m_input.keyboard.update();

    cen::event::update();

    m_game.handle_input(m_input);

    return !m_game.should_quit() && !cen::event::in_queue(cen::event_type::quit);
  }

  auto run() -> int
  {
    m_window.show();

    m_loop.fetch_current_time();

    if constexpr (has_on_start<Game>)
    {
      m_game.on_start();
    }

    auto& renderer = m_graphics.renderer();
    while (m_loop.is_running())
    {
      m_loop.tick();

      renderer.clear_with(cen::colors::black);
      m_game.render(m_graphics);
      renderer.present();
    }

    if constexpr (has_on_exit<Game>)
    {
      m_game.on_exit();
    }

    m_window.hide();

    return 0;
  }

 private:
  loop_type m_loop;

  cen::window m_window;
  graphics_type m_graphics;
  input m_input;

  game_type m_game;
};

}  // namespace rune
