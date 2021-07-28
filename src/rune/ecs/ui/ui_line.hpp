#ifndef RUNE_ECS_UI_UI_LINE_HPP
#define RUNE_ECS_UI_UI_LINE_HPP

#include "../entity_type.hpp"
#include "ui_position.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_line_tag;
}  // namespace tags

struct ui_line final
{
  using entity = entity_type<tags::ui_line_tag>;

  ui_position start;  ///< The start point.
  ui_position end;    ///< The end point.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_line& line)
{
  archive(line.start, line.end);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LINE_HPP
