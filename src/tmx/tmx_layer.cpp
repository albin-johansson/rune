#include "tmx/tmx_layer.hpp"

#include <memory>  // make_unique

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_group& group)
{
  const auto& layers = json.at("layers");
  group.layers.reserve(layers.size());
  for (const auto& [key, value] : layers.items())
  {
    group.layers.push_back(std::make_unique<tmx_layer>(value.get<tmx_layer>()));
  }
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

}  // namespace rune
