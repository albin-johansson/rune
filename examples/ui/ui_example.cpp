#include <centurion.hpp>

#include "../../src/everything.hpp"

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
    gfx.renderer().set_logical_size(cen::window::default_size());

    // clang-format off
    m_dispatcher.sink<rune::button_pressed_event>().connect<&ui_example::on_button_pressed>(this);
    m_dispatcher.sink<rune::key_bind_triggered_event>().connect<&ui_example::on_key_bind_triggered>(this);
    // clang-format on

    gfx.emplace_cache(0, "resources/fonts/daniel.ttf", 36);

    const auto menu =
        rune::ui::make_menu(m_registry, {.id = 0, .title = "Menu", .is_blocking = true});
    m_registry.set<rune::active_menu>(menu);

    rune::ui::make_label(m_registry,
                         menu,
                         {.position = {4, 4},
                          .text = "Label",
                          .color = cen::colors::crimson,
                          .shadow = true});

    rune::ui::make_button(m_registry,
                          menu,
                          {.position = {10, 4},
                           .text = "Button 1",
                           .id = 1,
                           .fg = cen::colors::aquamarine,
                           .shadow = true});

    rune::ui::make_button(m_registry,
                          menu,
                          {.position = {20, 4},
                           .text = "Button 2",
                           .id = 2,
                           .fg = cen::colors::aquamarine,
                           .shadow = true});

    rune::ui::make_line(m_registry,
                        menu,
                        {.start = {10, 40}, .end = {15, 45}, .color = cen::colors::cyan});

    rune::ui::make_key_bind(m_registry, cen::scancodes::escape, action_id::quit);
    rune::ui::make_key_bind(m_registry, cen::scancodes::f, action_id::foo);
    rune::ui::make_key_bind(m_registry, cen::scancodes::b, action_id::bar);
  }

  void handle_input(const rune::input& input) override
  {
    rune::ui::update(m_registry, m_dispatcher, input);
  }

  void render(rune::graphics& gfx) const override
  {
    auto& renderer = gfx.renderer();
    renderer.clear_with(cen::colors::teal);

    rune::ui::render(m_registry, gfx);
    rune::ui::debug(m_registry, gfx);

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
    switch (static_cast<action_id>(event.id))
    {
      case action_id::quit:
        m_quit = true;
        break;

      case action_id::foo:
        cen::log::info("foo");
        break;

      case action_id::bar:
        cen::log::info("bar");
        break;
    }
  }
};

}  // namespace

RUNE_IMPLEMENT_MAIN_WITH_GAME(ui_example)