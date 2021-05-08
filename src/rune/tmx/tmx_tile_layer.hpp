#ifndef RUNE_TMX_TILE_LAYER_HPP
#define RUNE_TMX_TILE_LAYER_HPP

#include <json.hpp>  // json, NLOHMANN_JSON_SERIALIZE_ENUM
#include <optional>  // optional

#include "tmx_data.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_tile_layer_compression
{
  none,
  gzip,
  zlib
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_tile_layer_compression,
                             {{tmx_tile_layer_compression::none, ""},
                              {tmx_tile_layer_compression::gzip, "gzip"},
                              {tmx_tile_layer_compression::zlib, "zlib"}})

enum class tmx_tile_layer_encoding
{
  csv,
  base64
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_tile_layer_encoding,
                             {{tmx_tile_layer_encoding::csv, "csv"},
                              {tmx_tile_layer_encoding::base64, "base64"}})

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
