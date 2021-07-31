#include "tmx/tmx_tile.hpp"

#include "aliases/integers.hpp"
#include "core/from_string.hpp"
#include "io/json_utils.hpp"

namespace rune {

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

}  // namespace rune
