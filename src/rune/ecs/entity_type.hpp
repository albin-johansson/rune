#ifndef RUNE_ECS_ENTITY_TYPE_HPP
#define RUNE_ECS_ENTITY_TYPE_HPP

#include <entt.hpp>   // entity
#include <nenya.hpp>  // strong_type

namespace rune {

template <typename T>
using entity_type = nenya::strong_type<entt::entity, T>;

}  // namespace rune

#endif  // RUNE_ECS_ENTITY_TYPE_HPP
