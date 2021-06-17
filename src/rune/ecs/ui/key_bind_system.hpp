#ifndef RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
#define RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

#include "../../core/concepts.hpp"
#include "../../core/input.hpp"
#include "../events/key_bind_triggered_event.hpp"
#include "ui_key_bind.hpp"

namespace rune {

inline auto make_key_bind(entt::registry& registry,
                          const cen::scan_code key,
                          const uint32 id) -> ui_key_bind::entity
{
  const auto entity = ui_key_bind::entity{registry.create()};

  auto& bind = registry.emplace<ui_key_bind>(entity);
  bind.key = key;
  bind.id = id;

  return entity;
}

template <cc::enum_type T>
auto make_key_bind(entt::registry& registry, const cen::scan_code key, const T id)
    -> ui_key_bind::entity
{
  return make_key_bind(registry, key, cen::to_underlying(id));
}

inline void update_key_binds(entt::registry& registry,
                             entt::dispatcher& dispatcher,
                             const input& input)
{
  for (auto&& [entity, bind] : registry.view<const ui_key_bind>().each())
  {
    if (input.keyboard.just_released(bind.key))
    {
      dispatcher.trigger<key_bind_triggered_event>(ui_key_bind::entity{entity}, bind.id);
      return;
    }
  }
}

}  // namespace rune

#endif  // RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
