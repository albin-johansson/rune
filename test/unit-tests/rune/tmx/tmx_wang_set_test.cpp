#include "tmx/tmx_wang_set.hpp"

#include <gtest/gtest.h>

#include "tmx/parse_tmx.hpp"

using namespace rune::tmx_literals;

TEST(TmxWangSet, Defaults)
{
  const rune::tmx_wang_set set;
  ASSERT_EQ(0_local, set.tile);
  ASSERT_TRUE(set.name.empty());
  ASSERT_TRUE(set.colors.empty());
  ASSERT_TRUE(set.wang_tiles.empty());
  ASSERT_TRUE(set.properties.empty());
}

TEST(TmxWangSet, Parse)
{
  const auto json = R"(
    {
      "name": "Galadriel",
      "tile": 27,
      "wangtiles": [
        {
          "tileid": 42,
          "wangid": [1, 2, 3, 4, 5, 6, 7, 8]
        }
      ],
      "colors": [
        {
          "color": "#AABBCC",
          "name": "Balrog",
          "probability": 0.45,
          "tile": 123
        }
      ],
      "properties": []
    }
  )"_json;

  const auto set = json.get<rune::tmx_wang_set>();
  ASSERT_EQ("Galadriel", set.name);
  ASSERT_EQ(27_local, set.tile);
  ASSERT_EQ(1, set.wang_tiles.size());
  ASSERT_EQ(1, set.colors.size());
  ASSERT_TRUE(set.properties.empty());

  const auto& tile = set.wang_tiles.at(0);
  ASSERT_EQ(42_local, tile.tile);
  ASSERT_EQ(1, tile.indices[0]);
  ASSERT_EQ(2, tile.indices[1]);
  ASSERT_EQ(3, tile.indices[2]);
  ASSERT_EQ(4, tile.indices[3]);
  ASSERT_EQ(5, tile.indices[4]);
  ASSERT_EQ(6, tile.indices[5]);
  ASSERT_EQ(7, tile.indices[6]);
  ASSERT_EQ(8, tile.indices[7]);

  const auto& color = set.colors.at(0);
  const rune::tmx_color expected{0xAA, 0xBB, 0xCC};
  ASSERT_EQ(expected, color.color);
  ASSERT_EQ("Balrog", color.name);
  ASSERT_FLOAT_EQ(0.45f, color.probability);
  ASSERT_EQ(123_local, color.tile);
}