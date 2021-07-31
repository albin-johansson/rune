#include "tmx/tmx_terrain.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_terrain& terrain)
{
  terrain.tile = tmx_local_id{json.at("tile").get<tmx_local_id::value_type>()};
  json.at("name").get_to(terrain.name);
  io::try_get_to(json, "properties", terrain.properties);
}

}  // namespace rune
