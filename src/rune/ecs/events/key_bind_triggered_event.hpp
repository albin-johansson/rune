#ifndef RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP
#define RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP

#include "../../aliases/integers.hpp"
#include "../null_entity.hpp"
#include "../ui/ui_key_bind.hpp"

namespace rune {

struct key_bind_triggered_event final
{
  ui_key_bind::entity entity{null<ui_key_bind>()};
  uint32 id{};
};

}  // namespace rune

#endif  // RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP
