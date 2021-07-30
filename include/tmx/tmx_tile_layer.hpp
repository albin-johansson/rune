#ifndef RUNE_TMX_TILE_LAYER_HPP
#define RUNE_TMX_TILE_LAYER_HPP

#include "../aliases/json_type.hpp"
#include "../aliases/maybe.hpp"
#include "rune_api.hpp"
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
  maybe<tmx_data> data;
  // TODO std::vector<chunk> m_chunks;
};

RUNE_API void from_json(const json_type& json, tmx_tile_layer& layer);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_HPP
