#include "tmx/tmx_map.hpp"

#include <gtest/gtest.h>

#include "tmx/parse_tmx.hpp"

TEST(TmxMap, Defaults)
{
  const rune::tmx_map map;
  ASSERT_EQ(0, map.width);
  ASSERT_EQ(0, map.height);
  ASSERT_EQ(0, map.tile_width);
  ASSERT_EQ(0, map.tile_height);
  ASSERT_EQ(1, map.next_layer_id);
  ASSERT_EQ(1, map.next_object_id);
  ASSERT_EQ(-1, map.compression_level);
  ASSERT_EQ(0, map.hex_side_length);
  ASSERT_EQ(rune::tmx_map_orientation::orthogonal, map.orientation);
  ASSERT_EQ(rune::tmx_map_render_order::right_down, map.render_order);
  ASSERT_FALSE(map.background);
  ASSERT_FALSE(map.stagger_axis);
  ASSERT_FALSE(map.stagger_index);
  ASSERT_TRUE(map.layers.empty());
  ASSERT_TRUE(map.tilesets.empty());
  ASSERT_TRUE(map.properties.empty());
  ASSERT_TRUE(map.tiled_version.empty());
  ASSERT_TRUE(map.json_version.empty());
  ASSERT_FALSE(map.infinite);
}

TEST(TmxMap, Parse)
{
  const auto map = rune::parse_tmx("resources/map_embedded.json");

  ASSERT_EQ(27, map.width);
  ASSERT_EQ(30, map.height);
  ASSERT_EQ(32, map.tile_width);
  ASSERT_EQ(32, map.tile_height);
  ASSERT_EQ(6, map.next_layer_id);
  ASSERT_EQ(2, map.next_object_id);
  ASSERT_EQ(rune::tmx_map_orientation::orthogonal, map.orientation);
  ASSERT_EQ(rune::tmx_map_render_order::right_down, map.render_order);
  ASSERT_EQ(-1, map.compression_level);
  ASSERT_EQ("1.6.0", map.tiled_version);
  ASSERT_EQ("1.6", map.json_version);
  ASSERT_FALSE(map.infinite);

  {  // Layers
    ASSERT_EQ(3, map.layers.size());

    {  // Group
      const auto& groupLayer = map.layers.at(0);
      ASSERT_TRUE(rune::tmx::is_group(groupLayer));

      ASSERT_EQ(5, groupLayer.id);
      ASSERT_EQ(rune::tmx_layer_type::group, groupLayer.type);
      ASSERT_FLOAT_EQ(1.0f, groupLayer.opacity);
      ASSERT_TRUE(groupLayer.visible);

      const auto& group = rune::tmx::get_group(groupLayer);
      ASSERT_EQ(2, group.layers.size());

      const auto& foo = group.layers.at(0);
      ASSERT_EQ("Foo", foo->name);
      ASSERT_EQ(1, foo->id);
      ASSERT_EQ(27, foo->width);
      ASSERT_EQ(30, foo->height);
      ASSERT_FLOAT_EQ(1.0f, foo->opacity);
      ASSERT_TRUE(foo->visible);

      const auto& bar = group.layers.at(1);
      ASSERT_EQ("Bar", bar->name);
      ASSERT_EQ(2, bar->id);
      ASSERT_EQ(27, bar->width);
      ASSERT_EQ(30, bar->height);
      ASSERT_FLOAT_EQ(1.0f, bar->opacity);
      ASSERT_TRUE(bar->visible);
    }

    {  // Object layer
      const auto& objectLayer = map.layers.at(1);
      ASSERT_TRUE(rune::tmx::is_object_layer(objectLayer));

      ASSERT_EQ(3, objectLayer.id);
      ASSERT_EQ(rune::tmx_layer_type::object_layer, objectLayer.type);
      ASSERT_EQ("Objects", objectLayer.name);
      ASSERT_FLOAT_EQ(1.0f, objectLayer.opacity);
      ASSERT_TRUE(objectLayer.visible);

      const auto& data = rune::tmx::get_object_layer(objectLayer);
      ASSERT_EQ(rune::tmx_object_layer_draw_order::top_down, data.draw_order);
      ASSERT_EQ(1, data.objects.size());

      const auto& object = data.objects.at(0);
      ASSERT_EQ(1, object.id);
      ASSERT_EQ("Rect", object.name);
      ASSERT_EQ("cool_rectangle", object.type);
      ASSERT_FLOAT_EQ(0.0f, object.rotation);
      ASSERT_FLOAT_EQ(137.0f, object.x);
      ASSERT_FLOAT_EQ(541.0f, object.y);
      ASSERT_FLOAT_EQ(73.0f, object.width);
      ASSERT_FLOAT_EQ(62.0f, object.height);
      ASSERT_TRUE(object.visible);
    }

    {  // Image layer
      const auto& imageLayer = map.layers.at(2);
      ASSERT_TRUE(rune::tmx::is_image_layer(imageLayer));

      ASSERT_EQ(4, imageLayer.id);
      ASSERT_EQ("Panda", imageLayer.name);
      ASSERT_FLOAT_EQ(1.0f, imageLayer.opacity);
      ASSERT_FLOAT_EQ(663.5f, imageLayer.offset_x);
      ASSERT_FLOAT_EQ(810.5f, imageLayer.offset_y);
      ASSERT_TRUE(imageLayer.visible);

      const auto& data = rune::tmx::get_image_layer(imageLayer);
      ASSERT_EQ("images/panda.png", data.image);
      ASSERT_FALSE(data.transparent);
    }
  }
}