#ifndef RUNE_ECS_UI_UI_LABEL_HPP
#define RUNE_ECS_UI_UI_LABEL_HPP

#include <centurion.hpp>  // texture
#include <string>         // string

#include "../../aliases/font_id.hpp"
#include "../../aliases/maybe.hpp"
#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_label_tag;
}  // namespace tags

struct ui_label final
{
  using entity = entity_type<tags::ui_label_tag>;

  std::string text;
  font_id font{};
  mutable maybe<cen::texture> texture;
};

void serialize(auto& archive, ui_label& label)
{
  archive(label.text, label.font);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LABEL_HPP
