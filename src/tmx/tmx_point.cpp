#include "tmx/tmx_point.hpp"

namespace rune {

void from_json(const json_type& json, tmx_point& point)
{
  json.at("x").get_to(point.x);
  json.at("y").get_to(point.y);
}

}  // namespace rune
