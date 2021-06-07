#ifndef RUNE_ECS_UI_UI_MENU_HPP
#define RUNE_ECS_UI_UI_MENU_HPP

#include "../../aliases/integers.hpp"
#include "../entity_type.hpp"
#include "../null_entity.hpp"

namespace rune {

namespace tags {
struct ui_menu_tag;
}  // namespace tags

struct ui_menu final
{
  using entity = entity_type<tags::ui_menu_tag>;

  uint32 id{};
  bool is_blocking{};
};

void serialize(auto& archive, ui_menu& menu)
{
  archive(menu.id, menu.is_blocking);
}

struct active_menu final
{
  ui_menu::entity menu_entity{null<ui_menu>()};
};

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_MENU_HPP
