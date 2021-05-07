#ifndef RUNE_TMX_WANG_TILE_HPP
#define RUNE_TMX_WANG_TILE_HPP

#include <array>     // array
#include <json.hpp>  // json

#include "../aliases/integers.hpp"
#include "tmx_local_id.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_tile final
{
  tmx_local_id tile{};
  std::array<uint8, 8> indices{};
};

void from_json(const nlohmann::json& json, tmx_wang_tile& tile);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_TILE_HPP
