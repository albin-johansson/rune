#include "tmx/tmx_wang_tile.hpp"

#include <gtest/gtest.h>

#include "tmx/tmx_parsers.hpp"

TEST(TmxWangTile, Defaults)
{
  const rune::tmx_wang_tile tile;
  ASSERT_EQ(rune::tmx_local_id{}, tile.tile);
  ASSERT_EQ(0, tile.indices[0]);
  ASSERT_EQ(0, tile.indices[1]);
  ASSERT_EQ(0, tile.indices[2]);
  ASSERT_EQ(0, tile.indices[3]);
  ASSERT_EQ(0, tile.indices[4]);
  ASSERT_EQ(0, tile.indices[5]);
  ASSERT_EQ(0, tile.indices[6]);
  ASSERT_EQ(0, tile.indices[7]);
}

TEST(TmxWangTile, Parse)
{
  const auto json = R"({ "tileid": 42, "wangid": [2, 0, 1, 0, 1, 0, 2, 0] })"_json;
  const auto tile = json.get<rune::tmx_wang_tile>();

  ASSERT_EQ(rune::tmx_local_id{42}, tile.tile);
  ASSERT_EQ(2, tile.indices[0]);
  ASSERT_EQ(0, tile.indices[1]);
  ASSERT_EQ(1, tile.indices[2]);
  ASSERT_EQ(0, tile.indices[3]);
  ASSERT_EQ(1, tile.indices[4]);
  ASSERT_EQ(0, tile.indices[5]);
  ASSERT_EQ(2, tile.indices[6]);
  ASSERT_EQ(0, tile.indices[7]);
}
