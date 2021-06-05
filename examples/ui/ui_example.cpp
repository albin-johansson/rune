#include <centurion.hpp>
#include <rune.hpp>

namespace {

class ui_example final : public rune::game_base
{
 public:
  explicit ui_example(rune::graphics& gfx)
  {
    gfx.emplace_cache(0, "resources/fonts/daniel.ttf", 36);

    rune::make_button(m_registry,
                      {.position = {10, 10}, .text = "foo", .fg = cen::colors::red});

    rune::make_line(m_registry, {.start = {14, 10}, .end = {16, 20}});
  }

  void tick(const rune::delta_time dt) override
  {
    rune::update_ui(m_registry, m_dispatcher);
  }

  void render(rune::graphics& gfx) const override
  {
    auto& renderer = gfx.renderer();
    renderer.clear_with(cen::colors::black);

    rune::render_ui(m_registry, gfx);

    renderer.present();
  }

 private:
  entt::registry m_registry;
  entt::dispatcher m_dispatcher;
};

}  // namespace

RUNE_IMPLEMENT_MAIN_WITH_GAME(ui_example)