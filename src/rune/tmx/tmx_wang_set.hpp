#pragma once

#include <json.hpp>  // json
#include <string>    // string
#include <vector>    // vector

#include "tmx_local_id.hpp"
#include "tmx_property.hpp"
#include "tmx_wang_color.hpp"
#include "tmx_wang_tile.hpp"

namespace rune {

struct tmx_wang_set final
{
  tmx_local_id tile{};
  std::string name;
  std::vector<tmx_wang_tile> wang_tiles;
  std::vector<tmx_wang_color> colors;
  std::vector<tmx_property> properties;
};

void from_json(const nlohmann::json& json, tmx_wang_set& set);

}  // namespace rune
