#include <cassert>  // assert
#include <memory>   // make_unique
#include <string>   // string

#include "aliases/integers.hpp"
#include "aliases/json_type.hpp"
#include "core/from_string.hpp"
#include "io/json_utils.hpp"
#include "tmx/tmx_animation.hpp"
#include "tmx/tmx_color.hpp"
#include "tmx/tmx_data.hpp"
#include "tmx/tmx_grid.hpp"
#include "tmx/tmx_image_layer.hpp"
#include "tmx/tmx_layer.hpp"
#include "tmx/tmx_local_id.hpp"
#include "tmx/tmx_object.hpp"
#include "tmx/tmx_object_layer.hpp"
#include "tmx/tmx_point.hpp"
#include "tmx/tmx_terrain.hpp"
#include "tmx/tmx_text.hpp"
#include "tmx/tmx_tile.hpp"
#include "tmx/tmx_tile_layer.hpp"
#include "tmx/tmx_tile_offset.hpp"
#include "tmx/tmx_tileset.hpp"
#include "tmx/tmx_wang_color.hpp"
#include "tmx/tmx_wang_set.hpp"
#include "tmx/tmx_wang_tile.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

/// \name JSON conversions
/// \{

void from_json(const json_type& json, tmx_point& point)
{
  json.at("x").get_to(point.x);
  json.at("y").get_to(point.y);
}

void from_json(const json_type& json, tmx_color& color)
{
  color = tmx::make_color(json.get<std::string>());
}

void from_json(const json_type& json, tmx_grid& grid)
{
  json.at("width").get_to(grid.cell_width);
  json.at("height").get_to(grid.cell_height);
  json.at("orientation").get_to(grid.orientation);
}

void from_json(const json_type& json, tmx_tile_offset& offset)
{
  json.at("x").get_to(offset.x);
  json.at("y").get_to(offset.y);
}

void from_json(const json_type& json, tmx_wang_color& color)
{
  json.at("name").get_to(color.name);
  json.at("color").get_to(color.color);
  json.at("probability").get_to(color.probability);
  io::emplace_to(json, "tile", color.tile);

  io::try_get_to(json, "properties", color.properties);
}

void from_json(const json_type& json, tmx_wang_tile& tile)
{
  io::emplace_to(json, "tileid", tile.tile);
  json.at("wangid").get_to(tile.indices);
}

void from_json(const json_type& json, tmx_wang_set& set)
{
  io::emplace_to(json, "tile", set.tile);
  json.at("name").get_to(set.name);

  // TODO check if colors or wangtiles are required
  io::try_get_to(json, "colors", set.colors);
  io::try_get_to(json, "wangtiles", set.wang_tiles);
  io::try_get_to(json, "properties", set.properties);
}

void from_json(const json_type& json, tmx_property& property)
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

void from_json(const json_type& json, tmx_terrain& terrain)
{
  terrain.tile = tmx_local_id{json.at("tile").get<tmx_local_id::value_type>()};
  json.at("name").get_to(terrain.name);
  io::try_get_to(json, "properties", terrain.properties);
}

void from_json(const json_type& json, tmx_text& text)
{
  json.at("text").get_to(text.text);

  io::try_get_to(json, "fontfamily", text.family);
  io::try_get_to(json, "halign", text.horizontal_alignment);
  io::try_get_to(json, "valign", text.vertical_alignment);
  io::try_get_to(json, "pixelsize", text.pixel_size);
  io::try_get_to(json, "bold", text.bold);
  io::try_get_to(json, "italic", text.italic);
  io::try_get_to(json, "kerning", text.kerning);
  io::try_get_to(json, "strikeout", text.strikeout);
  io::try_get_to(json, "underline", text.underline);
  io::try_get_to(json, "wrap", text.wrap);

  if (const auto it = json.find("color"); it != json.end())
  {
    text.color = tmx::make_color(it->get<std::string>());
  }
}

void from_json(const json_type& json, tmx_frame& frame)
{
  using ms_t = std::chrono::milliseconds;

  io::emplace_to(json, "tileid", frame.tile);
  frame.duration = ms_t{json.at("duration").get<ms_t::rep>()};
}

void from_json(const json_type& json, tmx_animation& animation)
{
  io::get_to(json, animation.frames);
}

void from_json(const json_type& json, tmx_data& data)
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

void from_json(const json_type& json, tmx_polygon& polygon)
{
  io::get_to(json, polygon.points);
}

void from_json(const json_type& json, tmx_polyline& line)
{
  io::get_to(json, line.points);
}

void from_json(const json_type& json, tmx_template_object& object)
{
  json.at("template").get_to(object.template_file);
  object.object = std::make_unique<tmx_object>(json.at("object").get<tmx_object>());

  if (const auto it = json.find("tileset"); it != json.end())
  {
    io::emplace_to(json, "firstgid", object.tileset_first_id);
    object.tileset_source = json.at("source").get<std::string>();
  }
}

void from_json(const json_type& json, tmx_object& object)
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

  io::try_get_to(json, "ellipse", object.is_ellipse);
  io::try_get_to(json, "point", object.is_point);

  io::try_get_to(json, "properties", object.properties);

  if (const auto it = json.find("gid"); it != json.end())
  {
    object.data.emplace<tmx_global_id>(it->get<tmx_global_id::value_type>());
  }

  io::try_emplace_to<tmx_text>(json, "text", object.data);
  io::try_emplace_to<tmx_polygon>(json, "polygon", object.data);
  io::try_emplace_to<tmx_polyline>(json, "polyline", object.data);
  io::try_emplace_to<tmx_template_object>(json, "template", object.data);
}

void from_json(const json_type& json, tmx_tile_layer& layer)
{
  io::try_get_to(json, "compression", layer.compression);
  io::try_get_to(json, "encoding", layer.encoding);
  io::try_get_to(json, "data", layer.data);

  // TODO
  //  if (json.contains("chunks")) {
  //    m_chunks = detail::fill<std::vector<chunk>>(json, "chunks");
  //  }
}

void from_json(const json_type& json, tmx_image_layer& layer)
{
  json.at("image").get_to(layer.image);
  io::try_get_to(json, "transparentcolor", layer.transparent);
}

void from_json(const json_type& json, tmx_object_layer& layer)
{
  io::get_to(json, "objects", layer.objects);
}

void from_json(const json_type& json, tmx_layer& layer)
{
  json.at("type").get_to(layer.type);

  io::try_get_to(json, "name", layer.name);
  io::try_get_to(json, "opacity", layer.opacity);
  io::try_get_to(json, "visible", layer.visible);
  io::try_get_to(json, "id", layer.id);
  io::try_get_to(json, "width", layer.width);
  io::try_get_to(json, "height", layer.height);
  io::try_get_to(json, "startx", layer.start_x);
  io::try_get_to(json, "starty", layer.start_y);
  io::try_get_to(json, "parallaxx", layer.parallax_x);
  io::try_get_to(json, "parallaxy", layer.parallax_y);
  io::try_get_to(json, "offsetx", layer.offset_x);
  io::try_get_to(json, "offsety", layer.offset_y);
  io::try_get_to(json, "tintcolor", layer.tint);

  io::try_get_to(json, "properties", layer.properties);

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

void from_json(const json_type& json, tmx_group& group)
{
  const auto& layers = json.at("layers");
  group.layers.reserve(layers.size());
  for (const auto& [key, value] : layers.items())
  {
    group.layers.push_back(std::make_unique<tmx_layer>(value.get<tmx_layer>()));
  }
}

void from_json(const json_type& json, tmx_tile& tile)
{
  io::emplace_to(json, "id", tile.id);

  io::try_get_to(json, "animation", tile.animation);
  io::try_get_to(json, "type", tile.type);
  io::try_get_to(json, "image", tile.image);
  io::try_get_to(json, "imagewidth", tile.image_width);
  io::try_get_to(json, "imageheight", tile.image_height);
  io::try_get_to(json, "probability", tile.probability);
  io::try_get_to(json, "objectgroup", tile.object_layer);
  io::try_get_to(json, "properties", tile.properties);

  if (const auto it = json.find("terrain"); it != json.end())
  {
    auto& terrain = tile.terrain.emplace();
    for (const auto& [key, value] : it->items())
    {
      const auto index = from_string<usize>(key).value();
      terrain.at(index) = value.get<int>();
    }
  }
}

/// \} End of JSON conversions

/// \} End of group tmx

}  // namespace rune
