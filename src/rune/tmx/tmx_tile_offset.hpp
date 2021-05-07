#ifndef RUNE_TMX_TILE_OFFSET_HPP
#define RUNE_TMX_TILE_OFFSET_HPP

#include <json.hpp>  // json

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_offset final
{
  int x{};
  int y{};
};

void from_json(const nlohmann::json& json, tmx_tile_offset& offset);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_OFFSET_HPP
