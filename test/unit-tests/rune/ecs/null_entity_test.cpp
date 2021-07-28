#include "ecs/null_entity.hpp"

#include <gtest/gtest.h>

#include "ecs/entity_type.hpp"

namespace {

inline constexpr auto null_entity = entt::entity{entt::null};

struct my_component final
{
  using entity = rune::entity_type<struct my_component_tag>;
};

}  // namespace

TEST(NullEntity, NullEntity)
{
  ASSERT_EQ(null_entity, rune::null<my_component>());
}

TEST(NullEntity, Nullify)
{
  my_component::entity entity{static_cast<entt::entity>(42)};
  ASSERT_NE(null_entity, entity);

  rune::nullify(entity);
  ASSERT_EQ(null_entity, entity);
}
