#include "ecs/ui/line_system.hpp"

#include "ecs/ui/ui_foreground.hpp"
#include "ecs/ui/ui_grid.hpp"

namespace rune::ui {

auto make_line(entt::registry& registry,
               const ui_menu::entity menu,
               const ui_line_cfg cfg) -> ui_line::entity
{
  const auto entity = ui_line::entity{registry.create()};

  registry.emplace<ui_line>(entity, cfg.start, cfg.end);
  registry.emplace<ui_foreground>(entity, cfg.color);
  registry.emplace<in_menu>(entity, menu);

  return entity;
}

namespace detail {

void render_lines(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;

  auto& renderer = gfx.renderer();
  for (auto&& [entity, line, fg, inMenu] :
       registry.view<ui_line, ui_foreground, in_menu>().each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      renderer.set_color(fg.color);
      renderer.draw_line(from_grid(line.start), from_grid(line.end));
    }
  }
}

}  // namespace detail
}  // namespace rune::ui
