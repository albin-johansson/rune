#ifndef RUNE_TMX_WANG_TILE_HPP
#define RUNE_TMX_WANG_TILE_HPP

#include <array>  // array

#include "../aliases/integers.hpp"
#include "../aliases/json_type.hpp"
#include "tmx_local_id.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_tile final
{
  tmx_local_id tile{};
  std::array<uint8, 8> indices{};
};

void from_json(const json_type& json, tmx_wang_tile& tile);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_TILE_HPP
