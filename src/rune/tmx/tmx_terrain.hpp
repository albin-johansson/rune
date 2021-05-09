#ifndef RUNE_TMX_TERRAIN_HPP
#define RUNE_TMX_TERRAIN_HPP

#include <json.hpp>  // json
#include <string>    // string

#include "tmx_local_id.hpp"
#include "tmx_property.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_terrain final
{
  tmx_local_id tile{};
  std::string name;
  tmx_properties properties;
};

void from_json(const nlohmann::json& json, tmx_terrain& terrain);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TERRAIN_HPP
