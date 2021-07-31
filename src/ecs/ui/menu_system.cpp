#include "ecs/ui/menu_system.hpp"

#include <utility>  // move

#include "ecs/ui/ui_label.hpp"

namespace rune::ui {

auto make_menu(entt::registry& registry, ui_menu_cfg cfg) -> ui_menu::entity
{
  const auto entity = ui_menu::entity{registry.create()};

  auto& menu = registry.emplace<ui_menu>(entity);
  menu.id = cfg.id;
  menu.is_blocking = cfg.is_blocking;

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.title);
  label.font = cfg.font;

  return entity;
}

}  // namespace rune::ui
