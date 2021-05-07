#pragma once

#include <json.hpp>  // json, NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

enum class tmx_orientation
{
  orthogonal,
  isometric
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_orientation,
                             {{tmx_orientation::orthogonal, "orthogonal"},
                              {tmx_orientation::isometric, "isometric"}})

struct tmx_grid final
{
  int cell_width{};
  int cell_height{};
  tmx_orientation orientation{tmx_orientation::orthogonal};
};

void from_json(const nlohmann::json& json, tmx_grid& grid);

}  // namespace rune
