#ifndef RUNE_TMX_TILE_HPP
#define RUNE_TMX_TILE_HPP

#include <array>     // array
#include <optional>  // optional
#include <string>    // string, stoi

#include "../aliases/json_type.hpp"
#include "tmx_animation.hpp"
#include "tmx_layer.hpp"
#include "tmx_local_id.hpp"
#include "tmx_property.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile final
{
  tmx_local_id id{};
  std::optional<tmx_animation> animation;
  std::optional<std::array<int, 4>> terrain;
  std::optional<std::string> type;
  std::optional<std::string> image;
  std::optional<int> image_width;
  std::optional<int> image_height;
  std::optional<float> probability;
  std::optional<tmx_layer> object_layer;
  tmx_properties properties;
};

void from_json(const json_type& json, tmx_tile& tile);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_HPP
