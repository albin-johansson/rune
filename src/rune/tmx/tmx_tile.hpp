#ifndef RUNE_TMX_TILE_HPP
#define RUNE_TMX_TILE_HPP

#include <array>   // array
#include <string>  // string

#include "../aliases/json_type.hpp"
#include "../aliases/maybe.hpp"
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
  maybe<tmx_animation> animation;
  maybe<std::array<int, 4>> terrain;
  maybe<std::string> type;
  maybe<std::string> image;
  maybe<int> image_width;
  maybe<int> image_height;
  maybe<float> probability;
  maybe<tmx_layer> object_layer;
  tmx_properties properties;
};

void from_json(const json_type& json, tmx_tile& tile);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_HPP
