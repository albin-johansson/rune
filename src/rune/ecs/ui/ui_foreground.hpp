#ifndef RUNE_ECS_UI_UI_FOREGROUND_HPP
#define RUNE_ECS_UI_UI_FOREGROUND_HPP

#include <centurion.hpp>  // color

#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_foreground_tag;
}  // namespace tags

struct ui_foreground final
{
  using entity = entity_type<tags::ui_foreground_tag>;

  cen::color color;
};

void serialize(auto& archive, ui_foreground& fg)
{
  archive(fg.color);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_FOREGROUND_HPP
