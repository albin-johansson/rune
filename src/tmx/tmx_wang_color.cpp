#include "tmx/tmx_wang_color.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_wang_color& color)
{
  json.at("name").get_to(color.name);
  json.at("color").get_to(color.color);
  json.at("probability").get_to(color.probability);
  io::emplace_to(json, "tile", color.tile);

  io::try_get_to(json, "properties", color.properties);
}

}  // namespace rune
