#ifndef RUNE_ECS_UI_BUTTON_SYSTEM_HPP
#define RUNE_ECS_UI_BUTTON_SYSTEM_HPP

#include <centurion.hpp>  // mouse
#include <entt.hpp>       // registry, dispatcher
#include <string>         // string
#include <utility>        // move

#include "../../aliases/integers.hpp"
#include "../../aliases/maybe.hpp"
#include "../../core/graphics.hpp"
#include "../events/button_pressed_event.hpp"
#include "ui_button.hpp"
#include "ui_checkbox.hpp"
#include "ui_foreground.hpp"
#include "ui_grid.hpp"
#include "ui_label.hpp"
#include "ui_position.hpp"

namespace rune {

struct ui_button_cfg final
{
  ui_position position;
  std::string text;
  uint32 id{};
  cen::color fg{cen::colors::white};
};

inline auto make_button(entt::registry& registry, ui_button_cfg cfg) -> ui_button::entity
{
  const auto entity = ui_button::entity{registry.create()};

  registry.emplace<ui_position>(entity, cfg.position);

  auto& button = registry.emplace<ui_button>(entity);
  button.id = cfg.id;

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.text);

  auto& foreground = registry.emplace<ui_foreground>(entity);
  foreground.color = cfg.fg;

  return entity;
}

[[nodiscard]] inline auto query_button(entt::registry& registry,
                                       entt::dispatcher& dispatcher,
                                       const ui_button::entity entity,
                                       const cen::mouse& mouse) -> bool
{
  auto& button = registry.get<ui_button>(entity);
  if (button.is_enabled && button.is_hovered)
  {
    // TODO enable_cursor

    if (mouse.was_left_button_released())
    {
      dispatcher.trigger<button_pressed_event>(entity, button.id);
      button.is_hovered = false;

      if (auto* checkbox = registry.try_get<ui_checkbox>(entity))
      {
        checkbox->is_checked = !checkbox->is_checked;
      }

      // TODO reset cursor

      return true;
    }
  }

  return false;
}

inline auto update_button_hover(entt::registry& registry, const cen::mouse& mouse)
    -> maybe<ui_button::entity>
{
  const auto mousePos = cen::cast<cen::fpoint>(mouse.position());
  for (auto&& [entity, button, position] :
       registry.view<ui_button, const ui_position>().each())
  {
    if (button.is_visible && button.size)
    {
      const auto bounds = cen::frect{from_grid(position), *button.size};
      button.is_hovered = bounds.contains(mousePos);
      if (button.is_hovered)
      {
        return ui_button::entity{entity};
      }
    }
  }

  return std::nullopt;
}

inline void render_buttons(const entt::registry& registry, graphics& gfx)
{
  auto& renderer = gfx.renderer();
  for (auto&& [entity, button, label, position] :
       registry.view<const ui_button, const ui_label, const ui_position>().each())
  {
    if (!button.size)
    {
      const auto& font = gfx.get_font(label.font);
      button.size = cen::cast<cen::farea>(font.string_size(label.text).value());
    }

    renderer.set_color(cen::colors::white);
    renderer.draw_rect(cen::frect{from_grid(position), button.size.value()});
  }
}

}  // namespace rune

#endif  // RUNE_ECS_UI_BUTTON_SYSTEM_HPP
