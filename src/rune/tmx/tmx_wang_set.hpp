#ifndef RUNE_TMX_WANG_SET_HPP
#define RUNE_TMX_WANG_SET_HPP

#include <json.hpp>  // json
#include <string>    // string
#include <vector>    // vector

#include "tmx_local_id.hpp"
#include "tmx_property.hpp"
#include "tmx_wang_color.hpp"
#include "tmx_wang_tile.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_set final
{
  tmx_local_id tile{};
  std::string name;
  std::vector<tmx_wang_tile> wang_tiles;
  std::vector<tmx_wang_color> colors;
  std::vector<tmx_property> properties;
};

void from_json(const nlohmann::json& json, tmx_wang_set& set);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_SET_HPP
