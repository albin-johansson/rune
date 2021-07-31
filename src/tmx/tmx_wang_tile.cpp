#include "tmx/tmx_wang_tile.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_wang_tile& tile)
{
  io::emplace_to(json, "tileid", tile.tile);
  json.at("wangid").get_to(tile.indices);
}

}  // namespace rune
