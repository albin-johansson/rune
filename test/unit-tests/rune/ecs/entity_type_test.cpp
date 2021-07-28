#include "ecs/entity_type.hpp"

#include <gtest/gtest.h>

#include <concepts>  // same_as

using foo = rune::entity_type<struct foo_tag>;

static_assert(std::same_as<entt::entity, foo::value_type>);
