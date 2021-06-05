#ifndef RUNE_ECS_UI_UI_LINE_HPP
#define RUNE_ECS_UI_UI_LINE_HPP

#include <centurion.hpp>  // fpoint

#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_line_tag;
}  // namespace tags

struct ui_line final
{
  using entity = entity_type<tags::ui_line_tag>;

  cen::fpoint start;
  cen::fpoint end;
};

void serialize(auto& archive, ui_line& line)
{
  archive(line.start, line.end);
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LINE_HPP
