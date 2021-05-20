#include "core/game.hpp"

#include <iostream>

#include "core/engine.hpp"

class Game final
{
 public:
  using graphics_type = rune::graphics;

//  void init(graphics_type& gfx)
//  {
//    std::cout << "Game::init\n";
//  }
//
//  void on_start()
//  {
//    std::cout << "Game::on_start\n";
//  }
//
//  void on_exit()
//  {
//    std::cout << "Game::on_exit\n";
//  }

  void handle_input(const rune::input& input)
  {
    if (input.keyboard.just_released(cen::scancodes::escape))
    {
      m_quit = true;
    }
  }

  void tick(rune::delta_time dt)
  {}

  void render(rune::graphics& graphics) const
  {
    auto& renderer = graphics.renderer();

    renderer.set_color(cen::colors::red);
    renderer.fill_rect(cen::rect(25, 25, 150, 100));
  }

  [[nodiscard]] auto should_quit() const -> bool
  {
    return m_quit;
  }

 private:
  bool m_quit{};
};

using RuneEngine = rune::engine<Game>;
