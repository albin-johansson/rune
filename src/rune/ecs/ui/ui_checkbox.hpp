#ifndef RUNE_ECS_UI_CHECKBOX_HPP
#define RUNE_ECS_UI_CHECKBOX_HPP

#include "../entity_type.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_checkbox_tag;
}  // namespace tags

struct ui_checkbox final
{
  using entity = entity_type<tags::ui_checkbox_tag>;

  bool is_checked{};
};

void serialize(auto& archive, ui_checkbox& cb)
{
  archive(cb.is_checked);
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_CHECKBOX_HPP
