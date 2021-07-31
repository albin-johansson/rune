#include "ecs/ui/button_system.hpp"

#include <cassert>  // assert
#include <utility>  // move

#include "ecs/null_entity.hpp"
#include "ecs/ui/label_system.hpp"
#include "ecs/ui/ui_checkbox.hpp"
#include "ecs/ui/ui_foreground.hpp"
#include "ecs/ui/ui_grid.hpp"
#include "ecs/ui/ui_label.hpp"

namespace rune::ui {

void add_button(entt::registry& registry,
                const ui_menu::entity menu,
                const entt::entity entity,
                ui_button_cfg cfg)
{
  auto& button = registry.emplace<ui_button>(entity);
  button.id = cfg.id;

  add_label(registry,
            menu,
            entity,
            {.position = cfg.position,
             .text = std::move(cfg.text),
             .font = cfg.font,
             .color = cfg.fg,
             .shadow = cfg.shadow});
}

auto make_button(entt::registry& registry, const ui_menu::entity menu, ui_button_cfg cfg)
    -> ui_button::entity
{
  const auto entity = ui_button::entity{registry.create()};

  add_button(registry, menu, entity, std::move(cfg));

  return entity;
}

namespace detail {

auto query_button(entt::registry& registry,
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

auto update_button_hover(entt::registry& registry, const cen::mouse& mouse)
    -> maybe<ui_button::entity>
{
  const auto menuEntity = registry.ctx<const active_menu>().menu_entity;
  const auto mousePos = cen::cast<cen::fpoint>(mouse.position());

  for (auto&& [entity, button, position, inMenu] :
       registry.view<ui_button, const ui_position, const in_menu>().each())
  {
    if (inMenu.menu_entity == menuEntity && button.is_visible && button.size)
    {
      const auto bounds = cen::frect{from_grid(position), *button.size};
      button.is_hovered = bounds.contains(mousePos);
      if (button.is_hovered)
      {
        return ui_button::entity{entity};
      }
    }
  }

  return nothing;
}

void update_button_bounds(const entt::registry& registry, graphics& gfx)
{
  auto& renderer = gfx.renderer();
  for (auto&& [entity, button, label] : registry.view<ui_button, ui_label>().each())
  {
    if (!button.size)
    {
      const auto& font = gfx.get_font(label.font);
      auto size = cen::cast<cen::farea>(font.string_size(label.text).value());

      const auto widthPadding = size.width * 0.5f;
      const auto heightPadding = size.height * 0.5f;

      size.width += widthPadding;
      size.height += heightPadding;

      button.size = size;
      button.text_offset = cen::fpoint{widthPadding / 2.0f, heightPadding / 2.0f};
    }
  }
}

void render_buttons(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  const auto view = registry.view<ui_button, ui_position, in_menu>();
  for (auto&& [entity, button, position, inMenu] : view.each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      assert(button.size);
      const auto rect = cen::frect{from_grid(position), *button.size};

      renderer.set_color(cen::colors::white);
      renderer.draw_rect(rect);

      if (button.is_hovered)
      {
        renderer.set_color(cen::colors::lime);
        renderer.draw_rect(rect);
      }
    }
  }
}

}  // namespace detail
}  // namespace rune::ui
