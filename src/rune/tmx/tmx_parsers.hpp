#pragma once

#include <cassert>   // assert
#include <json.hpp>  // json
#include <memory>    // make_unique
#include <string>    // string

#include "../io/json_utils.hpp"
#include "tmx_animation.hpp"
#include "tmx_color.hpp"
#include "tmx_data.hpp"
#include "tmx_image_layer.hpp"
#include "tmx_layer.hpp"
#include "tmx_local_id.hpp"
#include "tmx_object.hpp"
#include "tmx_object_layer.hpp"
#include "tmx_point.hpp"
#include "tmx_terrain.hpp"
#include "tmx_text.hpp"
#include "tmx_tile.hpp"
#include "tmx_tile_layer.hpp"
#include "tmx_tileset.hpp"

namespace rune {

inline void from_json(const nlohmann::json& json, tmx_point& point)
{
  json.at("x").get_to(point.x);
  json.at("y").get_to(point.y);
}

inline void from_json(const nlohmann::json& json, tmx_color& color)
{
  color = tmx::make_color(json.get<std::string>());
}

inline void from_json(const nlohmann::json& json, tmx_property& property)
{
  json.at("name").get_to(property.name);
  json.at("type").get_to(property.type);

  switch (property.type)
  {
    default:
      assert(false && "from_json() for tmx_property has missing branch!");

    case tmx_property_type::string:
      property.value.emplace<std::string>(json.at("value").get<std::string>());
      break;

    case tmx_property_type::integer:
      property.value.emplace<int>(json.at("value").get<int>());
      break;

    case tmx_property_type::floating:
      property.value.emplace<float>(json.at("value").get<float>());
      break;

    case tmx_property_type::boolean:
      property.value.emplace<bool>(json.at("value").get<bool>());
      break;

    case tmx_property_type::color:
      property.value.emplace<tmx_color>(json.at("value").get<tmx_color>());
      break;

    case tmx_property_type::file:
      property.value.emplace<tmx_file>(json.at("value").get<std::string>());
      break;

    case tmx_property_type::object:
      property.value.emplace<tmx_object_id>(json.at("value").get<int>());
      break;
  }
}

inline void from_json(const nlohmann::json& json, tmx_terrain& terrain)
{
  terrain.tile = tmx_local_id{json.at("tile").get<tmx_local_id::value_type>()};
  json.at("name").get_to(terrain.name);
  fill_if_exists(json, "properties", terrain.properties);
}

inline void from_json(const nlohmann::json& json, tmx_text& text)
{
  json.at("text").get_to(text.text);

  get_if_exists(json, "fontfamily", text.family);
  get_if_exists(json, "halign", text.horizontal_alignment);
  get_if_exists(json, "valign", text.vertical_alignment);
  get_if_exists(json, "pixelsize", text.pixel_size);
  get_if_exists(json, "bold", text.bold);
  get_if_exists(json, "italic", text.italic);
  get_if_exists(json, "kerning", text.kerning);
  get_if_exists(json, "strikeout", text.strikeout);
  get_if_exists(json, "underline", text.underline);
  get_if_exists(json, "wrap", text.wrap);

  if (const auto it = json.find("color"); it != json.end())
  {
    text.color = tmx::make_color(it->get<std::string>());
  }
}

inline void from_json(const nlohmann::json& json, tmx_frame& frame)
{
  frame.tile = tmx_local_id{json.at("tileid").get<tmx_local_id::value_type>()};
  json.at("duration").get_to(frame.duration);
}

inline void from_json(const nlohmann::json& json, tmx_animation& animation)
{
  fill(json, animation.frames);
}

inline void from_json(const nlohmann::json& json, tmx_data& data)
{
  assert(json.is_array() || json.is_string());

  if (json.is_array())
  {
    auto& gidData = data.tile_data.emplace<tmx_data::gid_data>();
    for (const auto& [key, value] : json.items())
    {
      gidData.emplace_back(value.get<uint>());
    }
  }
  else if (json.is_string())
  {
    data.tile_data.emplace<tmx_data::base64_data>(json.get<tmx_data::base64_data>());
  }
}

inline void from_json(const nlohmann::json& json, tmx_polygon& polygon)
{
  fill(json, polygon.points);
}

inline void from_json(const nlohmann::json& json, tmx_polyline& line)
{
  fill(json, line.points);
}

inline void from_json(const nlohmann::json& json, tmx_template_object& object)
{
  json.at("template").get_to(object.template_file);
  object.object = std::make_unique<tmx_object>(json.at("object").get<tmx_object>());

  // TODO
  //  if (const auto it = json.find("tileset"); it != json.end())
  //  {
  //    object.tileset = std::make_unique<tmx_tileset>(it->get<tmx_tileset>());
  //  }
}

inline void from_json(const nlohmann::json& json, tmx_object& object)
{
  json.at("id").get_to(object.id);
  json.at("x").get_to(object.x);
  json.at("y").get_to(object.y);
  json.at("width").get_to(object.width);
  json.at("height").get_to(object.height);
  json.at("rotation").get_to(object.rotation);
  json.at("name").get_to(object.name);
  json.at("type").get_to(object.type);
  json.at("visible").get_to(object.visible);

  get_if_exists(json, "ellipse", object.is_ellipse);
  get_if_exists(json, "point", object.is_point);

  fill_if_exists(json, "properties", object.properties);

  if (const auto it = json.find("gid"); it != json.end())
  {
    object.data.emplace<tmx_global_id>(it->get<uint>());
  }

  if (const auto it = json.find("text"); it != json.end())
  {
    object.data.emplace<tmx_text>(it->get<tmx_text>());
  }

  if (const auto it = json.find("polygon"); it != json.end())
  {
    object.data.emplace<tmx_polygon>(it->get<tmx_polygon>());
  }

  if (const auto it = json.find("polyline"); it != json.end())
  {
    object.data.emplace<tmx_polyline>(it->get<tmx_polyline>());
  }

  if (const auto it = json.find("template"); it != json.end())
  {
    object.data.emplace<tmx_template_object>(it->get<tmx_template_object>());
  }
}

inline void from_json(const nlohmann::json& json, tmx_tile_layer& layer)
{
  get_if_exists(json, "compression", layer.compression);
  get_if_exists(json, "encoding", layer.encoding);
  get_if_exists(json, "data", layer.data);

  // TODO
  //  if (json.contains("chunks")) {
  //    m_chunks = detail::fill<std::vector<chunk>>(json, "chunks");
  //  }
}

inline void from_json(const nlohmann::json& json, tmx_image_layer& layer)
{
  json.at("image").get_to(layer.image);
  get_if_exists(json, "transparentcolor", layer.transparent);
}

inline void from_json(const nlohmann::json& json, tmx_object_layer& layer)
{
  fill(json, "objects", layer.objects);
}

inline void from_json(const nlohmann::json& json, tmx_layer& layer)
{
  json.at("type").get_to(layer.type);

  get_if_exists(json, "name", layer.name);
  get_if_exists(json, "opacity", layer.opacity);
  get_if_exists(json, "visible", layer.visible);
  get_if_exists(json, "id", layer.id);
  get_if_exists(json, "width", layer.width);
  get_if_exists(json, "height", layer.height);
  get_if_exists(json, "startx", layer.start_x);
  get_if_exists(json, "starty", layer.start_y);
  get_if_exists(json, "offsetx", layer.offset_x);
  get_if_exists(json, "offsety", layer.offset_y);

  fill_if_exists(json, "properties", layer.properties);

  switch (layer.type)
  {
    default:
      assert(false && "from_json() for tmx_layer is missing branch!");

    case tmx_layer_type::tile_layer:
      layer.data = json.get<tmx_tile_layer>();
      break;

    case tmx_layer_type::object_layer:
      layer.data = json.get<tmx_object_layer>();
      break;

    case tmx_layer_type::image_layer:
      layer.data = json.get<tmx_image_layer>();
      break;

    case tmx_layer_type::group:
      layer.data = json.get<tmx_group>();
      break;
  }
}

inline void from_json(const nlohmann::json& json, tmx_group& group)
{
  const auto& layers = json.at("layers");
  group.layers.reserve(layers.size());
  for (const auto& [key, value] : layers.items())
  {
    group.layers.push_back(std::make_unique<tmx_layer>(value.get<tmx_layer>()));
  }
}

inline void from_json(const nlohmann::json& json, tmx_tile& tile)
{
  get_if_exists(json, "animation", tile.animation);
  get_if_exists(json, "type", tile.type);
  get_if_exists(json, "image", tile.image);
  get_if_exists(json, "imagewidth", tile.image_width);
  get_if_exists(json, "imageheight", tile.image_height);
  get_if_exists(json, "probability", tile.probability);

  fill_if_exists(json, "properties", tile.properties);

  if (const auto it = json.find("terrain"); it != json.end())
  {
    auto& terrain = tile.terrain.emplace();
    for (const auto& [key, value] : it->items())
    {
      terrain.at(std::stoi(key)) = value.get<int>();  // TODO don't use stoi
    }
  }

  if (const auto it = json.find("objectgroup"); it != json.end())
  {
    tile.object_group = it->get<tmx_layer>();
  }
}

}  // namespace rune
