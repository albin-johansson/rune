#ifndef RUNE_ECS_UI_UI_BOUNDS_HPP
#define RUNE_ECS_UI_UI_BOUNDS_HPP

#include <centurion.hpp>  // frect

#include "../entity_type.hpp"

namespace rune {

namespace tags {
struct ui_bounds_tag;
}  // namespace tags

struct ui_bounds final
{
  using entity = entity_type<tags::ui_bounds_tag>;

  cen::frect bounds;
};

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BOUNDS_HPP
