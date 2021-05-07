#pragma once

#include <json.hpp>  // json

namespace rune {

struct tmx_tile_offset final
{
  int x{};
  int y{};
};

void from_json(const nlohmann::json& json, tmx_tile_offset& offset);

}  // namespace rune
