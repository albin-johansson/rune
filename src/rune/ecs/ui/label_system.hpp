#ifndef RUNE_ECS_UI_LABEL_SYSTEM_HPP
#define RUNE_ECS_UI_LABEL_SYSTEM_HPP

#include <entt.hpp>  // registry

#include "../../core/graphics.hpp"
#include "ui_foreground.hpp"
#include "ui_grid.hpp"
#include "ui_label.hpp"
#include "ui_position.hpp"

namespace rune {

inline void render_labels(const entt::registry& registry, graphics& gfx)
{
  auto& renderer = gfx.renderer();
  for (auto&& [entity, label, position, fg] :
       registry.view<const ui_label, const ui_position, const ui_foreground>().each())
  {
    renderer.set_color(fg.color);

    if (!label.texture)
    {
      const auto& font = gfx.get_font(label.font);
      label.texture = renderer.render_blended_utf8(label.text, font);
    }

    renderer.render(*label.texture, from_grid(position));
  }
}

}  // namespace rune

#endif  // RUNE_ECS_UI_LABEL_SYSTEM_HPP
