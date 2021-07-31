#include "ecs/ui/label_system.hpp"

#include <cassert>  // assert
#include <utility>  // move

#include "ecs/ui/ui_button.hpp"
#include "ecs/ui/ui_foreground.hpp"
#include "ecs/ui/ui_grid.hpp"

namespace rune::ui {

void add_label(entt::registry& registry,
               const ui_menu::entity menu,
               const entt::entity entity,
               ui_label_cfg cfg)
{
  registry.emplace<in_menu>(entity, menu);

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.text);
  label.font = cfg.font;

  registry.emplace<ui_position>(entity, cfg.position);
  registry.emplace<ui_foreground>(entity, cfg.color);

  if (cfg.shadow)
  {
    registry.emplace<ui_label_shadow>(entity);
  }
}

auto make_label(entt::registry& registry, const ui_menu::entity menu, ui_label_cfg cfg)
    -> ui_label::entity
{
  const auto entity = ui_label::entity{registry.create()};

  add_label(registry, menu, entity, std::move(cfg));

  return entity;
}

namespace detail {

auto render_text(graphics& gfx, const ui_label& label, const cen::color& color)
    -> cen::texture
{
  auto& renderer = gfx.renderer();
  renderer.set_color(color);

  const auto& font = gfx.get_font(label.font);
  return renderer.render_blended_utf8(label.text, font);
}

void render_label(graphics& gfx,
                  const ui_label& label,
                  const cen::fpoint& position,
                  const cen::color& fg)
{
  auto& renderer = gfx.renderer();

  if (!label.texture)
  {
    label.texture = render_text(gfx, label, fg);
  }

  assert(label.texture);
  renderer.render(*label.texture, position);
}

void render_shadow(graphics& gfx,
                   const ui_label& label,
                   const ui_label_shadow& shadow,
                   const cen::fpoint& position)
{
  if (!shadow.texture)
  {
    shadow.texture = render_text(gfx, label, cen::colors::black);
  }

  assert(shadow.texture);
  const cen::fpoint offset{static_cast<float>(shadow.offset),
                           static_cast<float>(shadow.offset)};
  gfx.renderer().render(*shadow.texture, position + offset);
}

void render_labels(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  const auto filter = entt::exclude<ui_button>;
  for (auto&& [entity, label, position, fg, inMenu] :
       registry.view<ui_label, ui_position, ui_foreground, in_menu>(filter).each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      if (const auto* shadow = registry.try_get<ui_label_shadow>(entity))
      {
        render_shadow(gfx, label, *shadow, from_grid(position));
      }

      render_label(gfx, label, from_grid(position), fg.color);
    }
  }
}

void render_button_labels(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  for (auto&& [entity, button, label, position, fg, inMenu] :
       registry.view<ui_button, ui_label, ui_position, ui_foreground, in_menu>().each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      const auto textPos = from_grid(position) + button.text_offset.value();

      if (const auto* shadow = registry.try_get<ui_label_shadow>(entity))
      {
        render_shadow(gfx, label, *shadow, textPos);
      }

      render_label(gfx, label, textPos, fg.color);
    }
  }
}

}  // namespace detail
}  // namespace rune::ui
