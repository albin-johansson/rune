#include "io/tmx/tmx_object.hpp"

#include <gtest/gtest.h>

TEST(TmxObject, Defaults)
{
  const rune::tmx_object object;
  ASSERT_EQ(0, object.id);
  ASSERT_FLOAT_EQ(0, object.x);
  ASSERT_FLOAT_EQ(0, object.y);
  ASSERT_FLOAT_EQ(0, object.width);
  ASSERT_FLOAT_EQ(0, object.height);
  ASSERT_FLOAT_EQ(0, object.rotation);
  ASSERT_TRUE(object.name.empty());
  ASSERT_TRUE(object.type.empty());
  ASSERT_TRUE(object.properties.empty());
  ASSERT_TRUE(std::holds_alternative<std::monostate>(object.data));
  ASSERT_FALSE(object.is_ellipse);
  ASSERT_FALSE(object.is_point);
  ASSERT_TRUE(object.visible);
}
