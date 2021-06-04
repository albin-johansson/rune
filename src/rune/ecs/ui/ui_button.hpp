#ifndef RUNE_ECS_UI_UI_BUTTON_HPP
#define RUNE_ECS_UI_UI_BUTTON_HPP

#include "../../aliases/integers.hpp"
#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_button_tag;
}  // namespace tags

struct ui_button final
{
  using entity = entity_type<tags::ui_button_tag>;

  uint32 id{};
  bool is_enabled{true};
  bool is_visible{true};
  bool is_hovered{false};
};

void serialize(auto& archive, ui_button& b)
{
  archive(b.id, b.is_enabled, b.is_visible, b.is_hovered);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BUTTON_HPP
