#ifndef RUNE_TMX_GRID_HPP
#define RUNE_TMX_GRID_HPP

#include <json.hpp>  // json, NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_grid_orientation
{
  orthogonal,
  isometric
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_grid_orientation,
                             {{tmx_grid_orientation::orthogonal, "orthogonal"},
                              {tmx_grid_orientation::isometric, "isometric"}})

struct tmx_grid final
{
  int cell_width{};
  int cell_height{};
  tmx_grid_orientation orientation{tmx_grid_orientation::orthogonal};
};

void from_json(const nlohmann::json& json, tmx_grid& grid);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_GRID_HPP
