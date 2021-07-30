#ifndef RUNE_TMX_TILE_OFFSET_HPP
#define RUNE_TMX_TILE_OFFSET_HPP

#include "../aliases/json_type.hpp"
#include "rune_api.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_offset final
{
  int x{};
  int y{};
};

RUNE_API void from_json(const json_type& json, tmx_tile_offset& offset);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_OFFSET_HPP
