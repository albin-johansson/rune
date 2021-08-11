#include "core/game.hpp"

#include <iostream>

#include "core/engine.hpp"

class Game final : public rune::game_base
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

  void handle_input(const rune::input& input) override
  {
    if (input.keyboard.just_released(cen::scancodes::escape))
    {
      m_quit = true;
    }
  }

  void tick(rune::delta_time dt) override
  {}

  void render(rune::graphics& graphics) const override
  {
    auto& renderer = graphics.get_renderer();
    renderer.clear_with(cen::colors::black);

    renderer.set_color(cen::colors::red);
    renderer.fill_rect(cen::rect(25, 25, 150, 100));

    renderer.present();
  }

  [[nodiscard]] auto should_quit() const -> bool override
  {
    return m_quit;
  }

 private:
  bool m_quit{};
};

using RuneEngine = rune::engine<Game>;
