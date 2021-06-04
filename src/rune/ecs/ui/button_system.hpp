#ifndef RUNE_ECS_UI_BUTTON_SYSTEM_HPP
#define RUNE_ECS_UI_BUTTON_SYSTEM_HPP

#include <centurion.hpp>  // mouse
#include <entt.hpp>       // registry, dispatcher

#include "../../aliases/maybe.hpp"
#include "ui_bounds.hpp"
#include "ui_button.hpp"
#include "ui_checkbox.hpp"

namespace rune {

inline auto make_button(entt::registry& registry) -> ui_button::entity
{
  const auto entity = ui_button::entity{registry.create()};

  auto& button = registry.emplace<ui_button>(entity);
  auto& bounds = registry.emplace<ui_bounds>(entity);
  // TODO ui_label

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
      dispatcher.trigger<button_pressed_event>(entity, b.id);
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

auto update_button_hover(entt::registry& registry, const cen::mouse& mouse)
    -> maybe<ui_button::entity>
{
  for (auto&& [entity, button] : registry.view<ui_button>().each())
  {
    if (button.is_visible)
    {
      //      const auto& drawable = registry.get<comp::button_drawable>(entity);
      //      button.hover = drawable.bounds.contains(mousePos);
      //      if (button.hover)
      //      {
      //        return comp::button::entity{entity};
      //      }
    }
  }

  return std::nullopt;
}

}  // namespace rune

#endif  // RUNE_ECS_UI_BUTTON_SYSTEM_HPP
