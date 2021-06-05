#ifndef RUNE_ECS_UI_UI_POSITION_HPP
#define RUNE_ECS_UI_UI_POSITION_HPP

#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_position_tag;
}  // namespace tags

struct ui_position final
{
  using entity = entity_type<tags::ui_position_tag>;

  float row{};
  float col{};
};

void serialize(auto& archive, ui_position& position)
{
  archive(position.row, position.col);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_POSITION_HPP
