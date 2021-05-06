#pragma once

#include <json.hpp>  // json
#include <optional>  // optional
#include <string>    // string
#include <vector>    // vector

#include "tmx_color.hpp"
#include "tmx_global_id.hpp"
#include "tmx_property.hpp"
#include "tmx_terrain.hpp"
#include "tmx_tile.hpp"

namespace rune {

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

  std::optional<tmx_color> background;
  std::optional<tmx_color> transparent;

  std::string name;
  std::string image;
  std::string external_source;
  std::string tiled_version;

  std::vector<tmx_tile> tiles;
  std::vector<tmx_terrain> terrains;
  std::vector<tmx_property> properties;

  // TODO std::vector<wang_set> wang_sets;
  // TODO std::optional<grid> grid;
  // TODO std::optional<tile_offset> tile_offset;
};

}  // namespace rune
