#include "core/game.hpp"

#include <iostream>

#include "core/engine.hpp"

class Game final
{
 public:
  void on_start()
  {
    std::cout << "Game::on_start\n";
  }

  void on_exit()
  {
    std::cout << "Game::on_exit\n";
  }

  void handle_input(const rune::input& input)
  {
    if (input.keyboard.just_released(cen::scancodes::escape))
    {
      m_quit = true;
    }
  }

  void tick(rune::delta_time dt)
  {}

  void render(rune::graphics& graphics)
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

static_assert(rune::game_type<Game>);

class CustomGraphics : public rune::graphics
{
 public:
  template <typename T>
  explicit CustomGraphics(const cen::basic_window<T>& window) : rune::graphics{window}
  {}
};

using RuneEngine = rune::engine<Game, CustomGraphics>;
