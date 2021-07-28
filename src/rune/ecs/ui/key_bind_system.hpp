#ifndef RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
#define RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

#include "../../core/concepts.hpp"
#include "../../core/input.hpp"
#include "../events/key_bind_triggered_event.hpp"
#include "ui_key_bind.hpp"

namespace rune::ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new key bind entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_key_bind`
 *
 * \param registry the registry to which a key bind entity will be added.
 * \param key the key that will trigger the bind.
 * \param id the identifier that will be associated with the bind.
 *
 * \return the created key bind entity.
 *
 * \since 0.1.0
 */
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

/// \copydoc make_key_bind()
template <cc::enum_type T>
auto make_key_bind(entt::registry& registry, const cen::scan_code key, const T id)
    -> ui_key_bind::entity
{
  return make_key_bind(registry, key, cen::to_underlying(id));
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

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

}  // namespace detail

/// \endcond

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
