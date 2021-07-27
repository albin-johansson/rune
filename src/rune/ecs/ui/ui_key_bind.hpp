#ifndef RUNE_ECS_UI_UI_KEY_BIND_HPP
#define RUNE_ECS_UI_UI_KEY_BIND_HPP

#include <centurion.hpp>  // scan_code

#include "../../aliases/integers.hpp"
#include "../entity_type.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_keybind_tag;
}  // namespace tags

struct ui_key_bind final
{
  using entity = entity_type<tags::ui_keybind_tag>;

  cen::scan_code key;
  uint32 id{};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_key_bind& bind)
{
  archive(bind.key, bind.id);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_KEY_BIND_HPP
