#ifndef RUNE_ECS_UI_BUTTON_SYSTEM_HPP
#define RUNE_ECS_UI_BUTTON_SYSTEM_HPP

#include <centurion.hpp>  // mouse
#include <entt.hpp>       // registry, dispatcher
#include <string>         // string
#include <utility>        // move

#include "../../aliases/integers.hpp"
#include "../../aliases/maybe.hpp"
#include "../../core/graphics.hpp"
#include "ui_bounds.hpp"
#include "ui_button.hpp"
#include "ui_checkbox.hpp"
#include "ui_label.hpp"
#include "ui_position.hpp"

namespace rune {

struct ui_button_cfg final
{
  float row{};
  float column{};
  std::string text;
  uint32 id{};
  cen::color fg{cen::colors::white};
};

inline auto make_button(entt::registry& registry, ui_button_cfg cfg) -> ui_button::entity
{
  const auto entity = ui_button::entity{registry.create()};

  auto& button = registry.emplace<ui_button>(entity);
  button.id = cfg.id;

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.text);
  // TODO label color

  auto& position = registry.emplace<ui_position>(entity);
  position.row = cfg.row;
  position.col = cfg.column;

  auto& bounds = registry.emplace<ui_bounds>(entity);

  // TODO set bounds position

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
  for (auto&& [entity, button, bounds] :
       registry.view<ui_button, const ui_bounds>().each())
  {
    if (button.is_visible)
    {
      button.is_hovered = bounds.bounds.contains(mousePos);
      if (button.is_hovered)
      {
        return ui_button::entity{entity};
      }
    }
  }

  return std::nullopt;
}

}  // namespace rune

#endif  // RUNE_ECS_UI_BUTTON_SYSTEM_HPP
