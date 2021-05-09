#ifndef RUNE_TMX_TILE_LAYER_HPP
#define RUNE_TMX_TILE_LAYER_HPP

#include <json.hpp>  // json
#include <optional>  // optional

#include "tmx_data.hpp"
#include "tmx_tile_layer_compression.hpp"
#include "tmx_tile_layer_encoding.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_layer final
{
  tmx_tile_layer_compression compression{tmx_tile_layer_compression::none};
  tmx_tile_layer_encoding encoding{tmx_tile_layer_encoding::csv};
  std::optional<tmx_data> data;
  // TODO std::vector<chunk> m_chunks;
};

void from_json(const nlohmann::json& json, tmx_tile_layer& layer);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_HPP
