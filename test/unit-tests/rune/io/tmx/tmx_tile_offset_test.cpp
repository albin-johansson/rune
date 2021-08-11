#include "io/tmx/tmx_tile_offset.hpp"

#include <gtest/gtest.h>

TEST(TmxTileOffset, Defaults)
{
  const rune::tmx_tile_offset offset;
  ASSERT_EQ(0.0f, offset.x);
  ASSERT_EQ(0.0f, offset.y);
}

TEST(TmxTileOffset, Parse)
{
  const auto json = R"({ "x": 123, "y": 84 })"_json;
  const auto offset = json.get<rune::tmx_tile_offset>();

  ASSERT_EQ(123, offset.x);
  ASSERT_EQ(84, offset.y);
}
