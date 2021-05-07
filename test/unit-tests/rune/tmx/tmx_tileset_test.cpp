#include "tmx/tmx_tileset.hpp"

#include <gtest/gtest.h>

#include "tmx/parse_tileset.hpp"
#include "tmx/tmx.hpp"
#include "tmx/tmx_parsers.hpp"

using namespace rune::tmx_literals;

TEST(TmxTileset, Defaults)
{
  const rune::tmx_tileset tileset;
  ASSERT_EQ(1_global, tileset.first_id);
  ASSERT_EQ(0, tileset.tile_width);
  ASSERT_EQ(0, tileset.tile_height);
  ASSERT_EQ(0, tileset.tile_count);
  ASSERT_EQ(0, tileset.column_count);
  ASSERT_EQ(0, tileset.image_width);
  ASSERT_EQ(0, tileset.image_height);
  ASSERT_EQ(0, tileset.margin);
  ASSERT_EQ(0, tileset.spacing);
  ASSERT_EQ(0, tileset.json_version);

  ASSERT_FALSE(tileset.background);
  ASSERT_FALSE(tileset.transparent);

  ASSERT_TRUE(tileset.name.empty());
  ASSERT_TRUE(tileset.image.empty());
  ASSERT_TRUE(tileset.external_source.empty());
  ASSERT_TRUE(tileset.tiled_version.empty());

  ASSERT_TRUE(tileset.tiles.empty());
  ASSERT_TRUE(tileset.properties.empty());
}

TEST(TmxTileset, ParseEmbedded)
{
  const auto tileset = rune::tmx::parse_tileset("resources/embedded_tileset.json");
  ASSERT_EQ(7_global, tileset.first_id);
  ASSERT_EQ(48, tileset.column_count);
  ASSERT_EQ(1270, tileset.image_width);
  ASSERT_EQ(960, tileset.image_height);
  ASSERT_EQ(77, tileset.margin);
  ASSERT_EQ(82, tileset.spacing);
  ASSERT_EQ(63, tileset.tile_count);
  ASSERT_EQ(55, tileset.tile_width);
  ASSERT_EQ(27, tileset.tile_height);
  ASSERT_FLOAT_EQ(1.2f, tileset.json_version);

  ASSERT_EQ("sam/is/the/hero.png", tileset.image);
  ASSERT_EQ("Took", tileset.name);
  ASSERT_EQ("1.3.4", tileset.tiled_version);

  const rune::tmx_color background{0x34, 0x56, 0x78, 0x12};
  const rune::tmx_color transparent{0xCC, 0xDD, 0xEE};
  ASSERT_EQ(background, tileset.background);
  ASSERT_EQ(transparent, tileset.transparent);
  ASSERT_TRUE(tileset.external_source.empty());

  {  // Terrains
    ASSERT_EQ(3, tileset.terrains.size());

    const auto& a = tileset.terrains.at(0);
    ASSERT_EQ(4_local, a.tile);
    ASSERT_EQ("ground", a.name);

    ASSERT_EQ(1, a.properties.size());
    const auto& property = a.properties.at(0);
    ASSERT_EQ("foo", property.name);
    ASSERT_EQ(rune::tmx_property_type::boolean, property.type);
    ASSERT_TRUE(rune::tmx::as_boolean(property));

    const auto& b = tileset.terrains.at(1);
    ASSERT_EQ(12_local, b.tile);
    ASSERT_EQ("chasm", b.name);

    const auto& c = tileset.terrains.at(2);
    ASSERT_EQ(36_local, c.tile);
    ASSERT_EQ("cliff", c.name);
  }

  {  // Tile offset
    ASSERT_TRUE(tileset.tile_offset);
    const auto& offset = tileset.tile_offset.value();

    ASSERT_FLOAT_EQ(1574.0f, offset.x);
    ASSERT_FLOAT_EQ(753.0f, offset.y);
  }

  {  // Grid
    ASSERT_TRUE(tileset.grid);
    const auto& grid = tileset.grid.value();

    ASSERT_EQ(rune::tmx_orientation::isometric, grid.orientation);
    ASSERT_EQ(48, grid.cell_width);
    ASSERT_EQ(64, grid.cell_height);
  }
}

TEST(TmxTileset, ParseExternal)
{
  const auto tileset = rune::tmx::parse_tileset("resources/external_tileset.json");

  ASSERT_EQ(32, tileset.column_count);
  ASSERT_EQ(1024, tileset.image_width);
  ASSERT_EQ(768, tileset.image_height);
  ASSERT_EQ(18, tileset.margin);
  ASSERT_EQ(7, tileset.spacing);
  ASSERT_EQ(1024, tileset.tile_count);
  ASSERT_EQ(64, tileset.tile_width);
  ASSERT_EQ(32, tileset.tile_height);

  ASSERT_FLOAT_EQ(1.2f, tileset.json_version);

  ASSERT_EQ("Aragorn", tileset.name);
  ASSERT_EQ("../terrain.png", tileset.image);
  ASSERT_EQ("1.3.4", tileset.tiled_version);
  ASSERT_EQ("external_tileset_data.json", tileset.external_source);
}
