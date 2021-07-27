#ifndef RUNE_ECS_NULL_ENTITY_HPP
#define RUNE_ECS_NULL_ENTITY_HPP

#include <concepts>  // constructible_from
#include <entt.hpp>  // entity, null

namespace rune {

/// \addtogroup ecs
/// \{

// clang-format off

template <typename T>
[[nodiscard]] constexpr auto null()
    noexcept(noexcept(typename T::entity{entt::entity{entt::null}}))
{
  return typename T::entity{entt::entity{entt::null}};
}

// clang-format on

template <std::constructible_from<entt::entity> T>
void nullify(T& entity) noexcept(noexcept(T{entt::entity{entt::null}}))
{
  entity = T{entt::entity{entt::null}};
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_NULL_ENTITY_HPP
