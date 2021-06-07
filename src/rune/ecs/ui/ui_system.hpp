#ifndef RUNE_ECS_UI_UI_SYSTEM_HPP
#define RUNE_ECS_UI_UI_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

#include "../../core/graphics.hpp"
#include "../../core/input.hpp"
#include "button_system.hpp"
#include "label_system.hpp"
#include "line_system.hpp"
#include "ui_menu.hpp"

namespace rune {

inline void update_ui(entt::registry& registry,
                      entt::dispatcher& dispatcher,
                      const input& input)
{
  // TODO check for button hover

  if (const auto button = update_button_hover(registry, input.mouse))
  {
    if (query_button(registry, dispatcher, *button, input.mouse))
    {
    }
  }
  // TODO key binds
}

inline void render_ui(const entt::registry& registry, graphics& gfx)
{
  render_lines(registry, gfx);
  render_buttons(registry, gfx);
  render_labels(registry, gfx);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_SYSTEM_HPP
