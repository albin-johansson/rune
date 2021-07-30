#include "tmx/tmx_layer.hpp"

#include <gtest/gtest.h>

TEST(TmxLayer, Defaults)
{
  const rune::tmx_layer layer;

  ASSERT_TRUE(layer.name.empty());
  ASSERT_TRUE(layer.properties.empty());
  ASSERT_TRUE(layer.visible);

  ASSERT_EQ(0, layer.id);
  ASSERT_EQ(0, layer.width);
  ASSERT_EQ(0, layer.height);
  ASSERT_EQ(0, layer.start_x);
  ASSERT_EQ(0, layer.start_y);
  ASSERT_EQ(0, layer.offset_x);
  ASSERT_EQ(0, layer.offset_y);
  ASSERT_FLOAT_EQ(1.0f, layer.opacity);
  ASSERT_FLOAT_EQ(1.0f, layer.parallax_x);
  ASSERT_FLOAT_EQ(1.0f, layer.parallax_y);

  ASSERT_EQ(rune::tmx_layer_type::tile_layer, layer.type);
  ASSERT_TRUE(std::holds_alternative<std::monostate>(layer.data));
}

TEST(TmxLayer, ParseTileLayer)
{
  const auto json = R"(
    {
      "id": 42,
      "name": "foo",
      "type": "tilelayer",
      "opacity": 0.7,
      "visible": true,
      "tintcolor": "#F1CE12",
      "parallaxx": 0.74,
      "parallaxy": 0.38,
      "width": 4,
      "height": 3,
      "data": [1, 1, 1, 1,
               1, 1, 1, 1,
               1, 1, 1, 1],
      "properties": [
        {
          "name": "hello",
          "type": "int",
          "value": 79
        },
        {
          "name": "world",
          "type": "bool",
          "value": false
        }
      ]
    }
  )"_json;

  const auto layer = json.get<rune::tmx_layer>();
  ASSERT_EQ(4, layer.width);
  ASSERT_EQ(3, layer.height);
  ASSERT_EQ(42, layer.id);
  ASSERT_EQ("foo", layer.name);
  ASSERT_EQ(rune::tmx_layer_type::tile_layer, layer.type);
  ASSERT_FLOAT_EQ(0.7f, layer.opacity);
  ASSERT_TRUE(layer.visible);

  const rune::tmx_color tint{0xF1, 0xCE, 0x12};
  ASSERT_EQ(tint, layer.tint);

  ASSERT_FLOAT_EQ(0.74f, layer.parallax_x);
  ASSERT_FLOAT_EQ(0.38f, layer.parallax_y);

  ASSERT_TRUE(rune::tmx::is_tile_layer(layer));
  ASSERT_FALSE(rune::tmx::is_object_layer(layer));
  ASSERT_FALSE(rune::tmx::is_image_layer(layer));
  ASSERT_FALSE(rune::tmx::is_group(layer));

  const auto& tileLayer = rune::tmx::get_tile_layer(layer);
  ASSERT_EQ(rune::tmx_tile_layer_encoding::csv, tileLayer.encoding);
  ASSERT_EQ(rune::tmx_tile_layer_compression::none, tileLayer.compression);

  ASSERT_TRUE(tileLayer.data);
  const auto& tiles = std::get<rune::tmx_data::gid_data>(tileLayer.data->tile_data);
  ASSERT_EQ(12, tiles.size());

  ASSERT_EQ(2, layer.properties.size());

  auto& first = layer.properties.at(0);
  ASSERT_EQ("hello", first.name);
  ASSERT_EQ(rune::tmx_property_type::integer, first.type);
  ASSERT_TRUE(rune::tmx::is_int(first));
  ASSERT_TRUE(rune::tmx::get_if_int(first));
  ASSERT_EQ(79, rune::tmx::get_int(first));

  auto& second = layer.properties.at(1);
  ASSERT_EQ("world", second.name);
  ASSERT_EQ(rune::tmx_property_type::boolean, second.type);
  ASSERT_TRUE(rune::tmx::is_bool(second));
  ASSERT_TRUE(rune::tmx::get_if_bool(second));
  ASSERT_FALSE(rune::tmx::get_bool(second));
}

TEST(TmxLayer, ParseImageLayer)
{
  const auto json = R"(
    {
      "id": 27,
      "name": "Sauron",
      "image": "mordor.png",
      "type": "imagelayer",
      "opacity": 1,
      "visible": true,
      "startx": 82,
      "starty": 37,
      "transparentcolor": "#214365"
    }
  )"_json;

  const auto layer = json.get<rune::tmx_layer>();
  ASSERT_EQ(rune::tmx_layer_type::image_layer, layer.type);
  ASSERT_EQ("Sauron", layer.name);
  ASSERT_EQ(27, layer.id);
  ASSERT_EQ(82, layer.start_x);
  ASSERT_EQ(37, layer.start_y);
  ASSERT_FLOAT_EQ(1, layer.opacity);
  ASSERT_TRUE(layer.visible);

  ASSERT_TRUE(rune::tmx::is_image_layer(layer));
  ASSERT_FALSE(rune::tmx::is_tile_layer(layer));
  ASSERT_FALSE(rune::tmx::is_object_layer(layer));
  ASSERT_FALSE(rune::tmx::is_group(layer));

  const auto& imageLayer = rune::tmx::get_image_layer(layer);
  const rune::tmx_color color{0x21, 0x43, 0x65, 0xFF};
  ASSERT_EQ(color, imageLayer.transparent);
  ASSERT_EQ("mordor.png", imageLayer.image);
}

TEST(TmxLayer, ParseObjectLayer)
{
  const auto json = R"(
    {
      "id": 3,
      "name": "Legolas",
      "type": "objectgroup",
      "draworder": "topdown",
      "opacity": 0.4,
      "visible": true,
      "offsetx": 65,
      "offsety": 173,
      "objects": [
        {
          "id": 36,
          "name": "Elrond",
          "type": "elf",
          "x": 234,
          "y": 584,
          "width": 118,
          "height": 77,
          "rotation": 3,
          "visible": true
        }
      ]
    }
  )"_json;

  const auto layer = json.get<rune::tmx_layer>();
  ASSERT_EQ(rune::tmx_layer_type::object_layer, layer.type);

  ASSERT_EQ("Legolas", layer.name);
  ASSERT_EQ(3, layer.id);
  ASSERT_FLOAT_EQ(0.4f, layer.opacity);
  ASSERT_FLOAT_EQ(65, layer.offset_x);
  ASSERT_FLOAT_EQ(173, layer.offset_y);
  ASSERT_TRUE(layer.visible);

  ASSERT_TRUE(rune::tmx::is_object_layer(layer));
  ASSERT_FALSE(rune::tmx::is_image_layer(layer));
  ASSERT_FALSE(rune::tmx::is_tile_layer(layer));
  ASSERT_FALSE(rune::tmx::is_group(layer));

  const auto& objectLayer = rune::tmx::get_object_layer(layer);
  ASSERT_EQ(rune::tmx_object_layer_draw_order::top_down, objectLayer.draw_order);
  ASSERT_EQ(1, objectLayer.objects.size());

  auto& object = objectLayer.objects.at(0);
  ASSERT_EQ(36, object.id);
  ASSERT_EQ("Elrond", object.name);
  ASSERT_EQ("elf", object.type);
  ASSERT_FLOAT_EQ(234, object.x);
  ASSERT_FLOAT_EQ(584, object.y);
  ASSERT_FLOAT_EQ(118, object.width);
  ASSERT_FLOAT_EQ(77, object.height);
  ASSERT_FLOAT_EQ(3, object.rotation);
  ASSERT_TRUE(object.visible);
}

TEST(TmxLayer, ParseGroup)
{
  const auto json = R"(
    {
      "id": 7,
      "type": "group",
      "name": "Gimli",
      "opacity": 0.9,
      "visible": false,
      "layers": [
        {
          "id": 123,
          "type": "tilelayer",
          "name": "Thorin",
          "opacity": 0.25,
          "visible": true,
          "width": 2,
          "height": 2,
          "data": [1, 2, 3, 4]
        }
      ]
    }
  )"_json;

  const auto layer = json.get<rune::tmx_layer>();
  ASSERT_EQ(rune::tmx_layer_type::group, layer.type);
  ASSERT_EQ(7, layer.id);
  ASSERT_EQ("Gimli", layer.name);
  ASSERT_FLOAT_EQ(0.9f, layer.opacity);
  ASSERT_FALSE(layer.visible);

  ASSERT_TRUE(rune::tmx::is_group(layer));
  ASSERT_FALSE(rune::tmx::is_object_layer(layer));
  ASSERT_FALSE(rune::tmx::is_image_layer(layer));
  ASSERT_FALSE(rune::tmx::is_tile_layer(layer));

  const auto& group = rune::tmx::get_group(layer);
  ASSERT_EQ(1, group.layers.size());

  const auto& groupLayer = group.layers.at(0);
  ASSERT_TRUE(rune::tmx::is_tile_layer(*groupLayer));
  ASSERT_EQ(rune::tmx_layer_type::tile_layer, groupLayer->type);
  ASSERT_EQ(123, groupLayer->id);
  ASSERT_EQ("Thorin", groupLayer->name);
  ASSERT_FLOAT_EQ(0.25f, groupLayer->opacity);
  ASSERT_TRUE(groupLayer->visible);
  ASSERT_EQ(2, groupLayer->width);
  ASSERT_EQ(2, groupLayer->height);
}
