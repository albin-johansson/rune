#include "tmx/tmx_color.hpp"

namespace rune {

void from_json(const json_type& json, tmx_color& color)
{
  color = tmx::make_color(json.get<std::string>());
}

}  // namespace rune
