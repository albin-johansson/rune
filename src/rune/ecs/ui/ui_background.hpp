#ifndef RUNE_ECS_UI_UI_BACKGROUND_HPP
#define RUNE_ECS_UI_UI_BACKGROUND_HPP

#include <centurion.hpp>  // color

#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_background_tag;
}  // namespace tags

struct ui_background final
{
  using entity = entity_type<tags::ui_background_tag>;

  cen::color color;
};

void serialize(auto& archive, ui_background& bg)
{
  archive(bg.color);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BACKGROUND_HPP
