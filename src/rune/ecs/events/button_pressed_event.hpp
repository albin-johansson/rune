#ifndef RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP
#define RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP

#include "../../aliases/integers.hpp"
#include "../null_entity.hpp"
#include "../ui/ui_button.hpp"

namespace rune {

struct button_pressed_event final
{
  ui_button::entity button_entity{null<ui_button>()};  ///< The pressed button entity.
  uint32 id{};  ///< The ID associated with the button.
};

}  // namespace rune

#endif  // RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP
