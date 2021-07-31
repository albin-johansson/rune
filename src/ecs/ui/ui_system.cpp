#include "ecs/ui/ui_system.hpp"

#include "ecs/ui/button_system.hpp"
#include "ecs/ui/key_bind_system.hpp"
#include "ecs/ui/label_system.hpp"
#include "ecs/ui/lazy_texture_system.hpp"
#include "ecs/ui/line_system.hpp"
#include "ecs/ui/ui_key_bind.hpp"
#include "ecs/ui/ui_menu.hpp"

namespace rune::ui {

void update(entt::registry& registry, entt::dispatcher& dispatcher, const input& input)
{
  if (const auto button = detail::update_button_hover(registry, input.mouse))
  {
    if (detail::query_button(registry, dispatcher, *button, input.mouse))
    {
      // TODO

      return;
    }
  }

  detail::update_key_binds(registry, dispatcher, input);
}

void render(const entt::registry& registry, graphics& gfx)
{
  detail::update_button_bounds(registry, gfx);
  detail::update_lazy_textures(registry, gfx);

  detail::render_lines(registry, gfx);
  detail::render_buttons(registry, gfx);
  detail::render_labels(registry, gfx);
  detail::render_button_labels(registry, gfx);
}

void debug(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<const active_menu>().menu_entity;
  const auto& menu = registry.get<ui_menu>(menuEntity);

  if (menu.is_blocking)
  {
    auto& renderer = gfx.renderer();
    renderer.set_color(cen::colors::light_gray.with_alpha(50));

    const auto [logicalWidth, logicalHeight] = renderer.logical_size();

    // TODO
  }
}

}  // namespace rune::ui
