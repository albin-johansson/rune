#ifndef RUNE_TMX_MAP_HPP
#define RUNE_TMX_MAP_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM
#include <optional>  // optional
#include <string>    // string
#include <vector>    // vector

#include "tmx_color.hpp"
#include "tmx_layer.hpp"
#include "tmx_property.hpp"
#include "tmx_tileset.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_map_orientation
{
  orthogonal,
  isometric,
  staggered,
  hexagonal
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_map_orientation,
                             {{tmx_map_orientation::orthogonal, "orthogonal"},
                              {tmx_map_orientation::isometric, "isometric"},
                              {tmx_map_orientation::staggered, "staggered"},
                              {tmx_map_orientation::hexagonal, "hexagonal"}})

enum class tmx_map_render_order
{
  right_down,
  right_up,
  left_down,
  left_up
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_map_render_order,
                             {{tmx_map_render_order::right_down, "right-down"},
                              {tmx_map_render_order::right_up, "right-up"},
                              {tmx_map_render_order::left_down, "left-down"},
                              {tmx_map_render_order::left_up, "left-up"}})

enum class tmx_stagger_axis
{
  x,
  y
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_stagger_axis,
                             {{tmx_stagger_axis::x, "x"}, {tmx_stagger_axis::y, "y"}})

enum class tmx_stagger_index
{
  odd,
  even
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_stagger_index,
                             {{tmx_stagger_index::odd, "odd"},
                              {tmx_stagger_index::even, "even"}})

struct tmx_map final
{
  int width{};   ///< Number of columns.
  int height{};  ///< Number of rows.

  int next_layer_id{1};
  int next_object_id{1};

  int tile_height{};
  int tile_width{};

  int compression_level{-1};
  int hex_side_length{};

  tmx_map_orientation orientation{tmx_map_orientation::orthogonal};
  tmx_map_render_order render_order{tmx_map_render_order::right_down};

  std::optional<tmx_color> background;
  std::optional<tmx_stagger_axis> stagger_axis;
  std::optional<tmx_stagger_index> stagger_index;

  std::vector<tmx_layer> layers;
  std::vector<tmx_tileset> tilesets;
  std::vector<tmx_property> properties;

  std::string tiled_version;
  std::string json_version;
  bool infinite{};
};

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_HPP
