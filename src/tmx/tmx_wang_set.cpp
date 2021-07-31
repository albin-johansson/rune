#include "tmx/tmx_wang_set.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_wang_set& set)
{
  io::emplace_to(json, "tile", set.tile);
  json.at("name").get_to(set.name);

  // TODO check if colors or wangtiles are required
  io::try_get_to(json, "colors", set.colors);
  io::try_get_to(json, "wangtiles", set.wang_tiles);
  io::try_get_to(json, "properties", set.properties);
}

}  // namespace rune
