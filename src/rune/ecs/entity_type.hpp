#ifndef RUNE_ECS_ENTITY_TYPE_HPP
#define RUNE_ECS_ENTITY_TYPE_HPP

#include <entt.hpp>   // entity
#include <nenya.hpp>  // strong_type

namespace rune {

/// \addtogroup ecs
/// \{

template <typename T>
using entity_type = nenya::strong_type<entt::entity, T>;

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_ENTITY_TYPE_HPP
