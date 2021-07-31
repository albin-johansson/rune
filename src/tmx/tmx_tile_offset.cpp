#include "tmx/tmx_tile_offset.hpp"

namespace rune {

void from_json(const json_type& json, tmx_tile_offset& offset)
{
  json.at("x").get_to(offset.x);
  json.at("y").get_to(offset.y);
}

}  // namespace rune