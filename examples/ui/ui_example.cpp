#include <centurion.hpp>
#include <rune.hpp>

namespace {

enum class action_id
{
  quit,
  foo,
  bar
};

class ui_example final : public rune::game_base
{
 public:
  explicit ui_example(rune::graphics& gfx)
  {
    // clang-format off
    m_dispatcher.sink<rune::button_pressed_event>().connect<&ui_example::on_button_pressed>(this);
    m_dispatcher.sink<rune::key_bind_triggered_event>().connect<&ui_example::on_key_bind_triggered>(this);
    // clang-format on

    gfx.emplace_cache(0, "resources/fonts/daniel.ttf", 36);

    rune::make_button(m_registry,
                      {.position = {10, 10}, .text = "foo", .fg = cen::colors::red});

    rune::make_button(m_registry, {.position = {16, 10}, .text = "bar"});

    rune::make_line(m_registry, {.start = {14, 35}, .end = {16, 60}});

    rune::make_key_bind(m_registry, cen::scancodes::escape, action_id::quit);
  }

  void handle_input(const rune::input& input) override
  {
    rune::ui::update(m_registry, m_dispatcher, input);
  }

  void render(rune::graphics& gfx) const override
  {
    auto& renderer = gfx.renderer();
    renderer.clear_with(cen::colors::black);

    rune::ui::render(m_registry, gfx);
    //    rune::debug_ui(m_registry, gfx);

    renderer.present();
  }

  [[nodiscard]] auto should_quit() const -> bool override
  {
    return m_quit;
  }

 private:
  entt::registry m_registry;
  entt::dispatcher m_dispatcher;
  bool m_quit{};

  void on_button_pressed(const rune::button_pressed_event& event)
  {
    cen::log::info("on_button_pressed");
  }

  void on_key_bind_triggered(const rune::key_bind_triggered_event& event)
  {
    cen::log::info("on_key_bind_triggered");
    switch (static_cast<action_id>(event.id))
    {
      case action_id::quit:
        m_quit = true;
        break;
    }
  }
};

}  // namespace

RUNE_IMPLEMENT_MAIN_WITH_GAME(ui_example)