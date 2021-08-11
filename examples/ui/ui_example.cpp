#include "../../include/everything.hpp"

namespace {

using rune::uint32;

struct action_id final
{
  enum value : uint32
  {
    quit = 1
  };
};

struct button_id final
{
  enum value : uint32
  {
    goto_home = 1,
    goto_settings = 2,
    quit = 3
  };
};

class ui_example final : public rune::game_base
{
 public:
  explicit ui_example(graphics_type& gfx)
      : m_home{make_home_menu()}
      , m_settings{make_settings_menu()}
  {
    gfx.emplace_cache(0, "resources/fonts/daniel.ttf", 36);
    gfx.emplace_cache(1, "resources/fonts/type_writer.ttf", 36);
    gfx.renderer().set_logical_size(cen::window::default_size());

    init_dispatcher();

    rune::ui::make_key_bind(m_registry,
                            {.id = action_id::quit,
                             .key = cen::scancodes::e,
                             .modifiers = cen::key_mod::left_ctrl});
  }

  void handle_input(const rune::input& input) override
  {
    rune::ui::update(m_registry, m_dispatcher, input);
  }

  void render(graphics_type& gfx) const override
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
  entt::dispatcher m_dispatcher;
  entt::registry m_registry;
  rune::ui_menu::entity m_home;
  rune::ui_menu::entity m_settings;
  bool m_quit{};

  void init_dispatcher()
  {
    // clang-format off
    m_dispatcher.sink<rune::button_pressed_event>().connect<&ui_example::on_button_pressed>(this);
    m_dispatcher.sink<rune::key_bind_triggered_event>().connect<&ui_example::on_key_bind_triggered>(this);
    // clang-format on
  }

  [[nodiscard]] auto make_home_menu() -> rune::ui_menu::entity
  {
    const auto home =
        rune::ui::make_menu(m_registry, {.id = 0, .title = "Home", .is_blocking = true});

    m_registry.set<rune::active_menu>(home);

    rune::ui::make_label(m_registry,
                         home,
                         {.position = {4, 4},
                          .text = "Label",
                          .font = 1,
                          .color = cen::colors::crimson,
                          .shadow = true});

    rune::ui::make_button(
        m_registry,
        home,
        {.position = {10, 4}, .text = "Settings", .id = button_id::goto_settings});

    rune::ui::make_button(m_registry,
                          home,
                          {.position = {20, 4},
                           .text = "Quit",
                           .id = button_id::quit,
                           .fg = cen::colors::aquamarine,
                           .shadow = true});

    rune::ui::make_line(m_registry,
                        home,
                        {.start = {10, 40}, .end = {15, 45}, .color = cen::colors::cyan});

    return home;
  }

  [[nodiscard]] auto make_settings_menu() -> rune::ui_menu::entity
  {
    const auto settings =
        rune::ui::make_menu(m_registry,
                            {.id = 2, .title = "Settings", .is_blocking = true});
    rune::ui::make_button(
        m_registry,
        settings,
        {.position = {10, 4}, .text = "Return", .id = button_id::goto_home});

    return settings;
  }

  void on_button_pressed(const rune::button_pressed_event& event)
  {
    if (event.id == button_id::goto_home)
    {
      m_registry.set<rune::active_menu>(m_home);
    }
    else if (event.id == button_id::goto_settings)
    {
      m_registry.set<rune::active_menu>(m_settings);
    }
    else if (event.id == button_id::quit)
    {
      m_quit = true;
    }
  }

  void on_key_bind_triggered(const rune::key_bind_triggered_event& event)
  {
    switch (event.id)
    {
      case action_id::quit:
        m_quit = true;
        break;
    }
  }
};

}  // namespace

RUNE_IMPLEMENT_MAIN_WITH_GAME(ui_example)