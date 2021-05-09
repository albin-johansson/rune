#ifndef RUNE_TMX_TILESET_HPP
#define RUNE_TMX_TILESET_HPP

#include <json.hpp>  // json
#include <optional>  // optional
#include <string>    // string
#include <vector>    // vector

#include "tmx_color.hpp"
#include "tmx_global_id.hpp"
#include "tmx_grid.hpp"
#include "tmx_property.hpp"
#include "tmx_terrain.hpp"
#include "tmx_tile.hpp"
#include "tmx_tile_offset.hpp"
#include "tmx_wang_set.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tileset final
{
  tmx_global_id first_id{1};
  int tile_width{};
  int tile_height{};
  int tile_count{};
  int column_count{};
  int image_width{};
  int image_height{};
  int margin{};
  int spacing{};
  float json_version{};

  std::string name;
  std::string image;
  std::string external_source;
  std::string tiled_version;

  std::optional<tmx_color> background;
  std::optional<tmx_color> transparent;
  std::optional<tmx_tile_offset> tile_offset;
  std::optional<tmx_grid> grid;

  std::vector<tmx_tile> tiles;
  std::vector<tmx_terrain> terrains;
  std::vector<tmx_wang_set> wang_sets;
  tmx_properties properties;
};

using tmx_tilesets = std::vector<tmx_tileset>;

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILESET_HPP
