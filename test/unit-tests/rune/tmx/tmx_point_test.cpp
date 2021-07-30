#include "tmx/tmx_point.hpp"

#include <gtest/gtest.h>

TEST(TmxPoint, Defaults)
{
  const rune::tmx_point point;
  ASSERT_FLOAT_EQ(0, point.x);
  ASSERT_FLOAT_EQ(0, point.y);
}

TEST(TmxPoint, Parse)
{
  const auto json = R"({ "x": 12.3, "y": 94.6 })"_json;
  const auto point = json.get<rune::tmx_point>();
  ASSERT_FLOAT_EQ(12.3f, point.x);
  ASSERT_FLOAT_EQ(94.6f, point.y);
}