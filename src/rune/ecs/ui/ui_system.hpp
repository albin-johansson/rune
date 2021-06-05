#ifndef RUNE_ECS_UI_UI_SYSTEM_HPP
#define RUNE_ECS_UI_UI_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

#include "../../core/graphics.hpp"
#include "label_system.hpp"
#include "line_system.hpp"

namespace rune {

inline void update_ui(entt::registry& registry, entt::dispatcher& dispatcher)
{
  // TODO check for button hover
  // TODO key binds
}

inline void render_ui(const entt::registry& registry, graphics& gfx)
{
  render_lines(registry, gfx);
  render_labels(registry, gfx);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_SYSTEM_HPP
