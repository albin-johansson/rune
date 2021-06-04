#include <centurion.hpp>
#include <rune.hpp>

#define RUNE_IMPLEMENT_MAIN_WITH_GAME(Game) \
  int main(int, char**)                     \
  {                                         \
    cen::library centurion;                 \
    rune::engine<Game> engine;              \
    return engine.run();                    \
  }

namespace {

class ui_example final
{
 public:
  ui_example()
  {

  }

  void handle_input(const rune::input& input)
  {}

  void tick(rune::delta_time dt)
  {}

  void render(rune::graphics& gfx) const
  {}

  [[nodiscard]] auto should_quit() const -> bool
  {
    return false;
  }

 private:
  entt::registry m_registry;
};

}  // namespace

RUNE_IMPLEMENT_MAIN_WITH_GAME(ui_example)
