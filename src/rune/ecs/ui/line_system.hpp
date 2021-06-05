#ifndef RUNE_ECS_UI_LINE_SYSTEM_HPP
#define RUNE_ECS_UI_LINE_SYSTEM_HPP

#include <centurion.hpp>  // color
#include <entt.hpp>       // registry

#include "../../core/graphics.hpp"
#include "ui_grid.hpp"
#include "ui_line.hpp"
#include "ui_position.hpp"

namespace rune {

struct ui_line_cfg final
{
  ui_position start;
  ui_position end;
  cen::color color{cen::colors::white};
};

inline auto make_line(entt::registry& registry, ui_line_cfg cfg) -> ui_line::entity
{
  const auto entity = ui_line::entity{registry.create()};

  auto& line = registry.emplace<ui_line>(entity);
  line.start = cfg.start;
  line.end = cfg.end;

  // TODO color

  return entity;
}

void render_lines(const entt::registry& registry, graphics& gfx)
{
  auto& renderer = gfx.renderer();
  for (auto&& [entity, line] : registry.view<const ui_line>().each())
  {
    // TODO color
    renderer.set_color(cen::colors::white);
    renderer.draw_line(from_grid(line.start), from_grid(line.end));
  }
}

}  // namespace rune

#endif  // RUNE_ECS_UI_LINE_SYSTEM_HPP
