#ifndef RUNE_ECS_UI_UI_SYSTEM_HPP
#define RUNE_ECS_UI_UI_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

#include "../../core/graphics.hpp"
#include "../../core/input.hpp"
#include "../events/button_pressed_event.hpp"
#include "../events/key_bind_triggered_event.hpp"
#include "button_system.hpp"
#include "key_bind_system.hpp"
#include "label_system.hpp"
#include "line_system.hpp"
#include "ui_key_bind.hpp"
#include "ui_menu.hpp"

namespace rune::ui {

/// \addtogroup ecs
/// \{

/**
 * \brief Updates the state of the UI.
 *
 * \details This is the only UI-function you need to call in your `handle_input()`
 * function if you are using the UI framework.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param dispatcher the event dispatcher that will be used.
 * \param input the current input state.
 */
inline void update(entt::registry& registry,
                   entt::dispatcher& dispatcher,
                   const input& input)
{
  if (const auto button = update_button_hover(registry, input.mouse))
  {
    if (query_button(registry, dispatcher, *button, input.mouse))
    {
      // TODO

      return;
    }
  }

  update_key_binds(registry, dispatcher, input);
}

inline void render(const entt::registry& registry, graphics& gfx)
{
  update_button_bounds(registry, gfx);
  render_lines(registry, gfx);
  render_buttons(registry, gfx);
  render_labels(registry, gfx);
  render_button_labels(registry, gfx);
}

inline void debug(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<const active_menu>().menu_entity;
  const auto& menu = registry.get<ui_menu>(menuEntity);

  if (menu.is_blocking)
  {
    auto& renderer = gfx.renderer();
    renderer.set_color(cen::colors::light_gray.with_alpha(50));

    const auto [logicalWidth, logicalHeight] = renderer.logical_size();

    for (int row = 0; row < static_cast<int>(menu_row_size); ++row)
    {
      const auto y = static_cast<float>(row) * menu_row_size;
      renderer.draw_line(cen::point(0.0f, y),
                         cen::point(static_cast<float>(logicalWidth), y));
    }

    for (int col = 0; col < static_cast<int>(menu_column_size); ++col)
    {
      const auto x = static_cast<float>(col) * menu_column_size;
      renderer.draw_line(cen::point(x, 0.0f),
                         cen::point(x, static_cast<float>(logicalHeight)));
    }

    renderer.draw_line(cen::point(0, logicalHeight - 1),
                       cen::point(logicalWidth, logicalHeight - 1));

    renderer.draw_line(cen::point(logicalWidth - 1, 0),
                       cen::point(logicalWidth - 1, logicalHeight));
  }
}

/// \} End of group ecs

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_UI_SYSTEM_HPP
