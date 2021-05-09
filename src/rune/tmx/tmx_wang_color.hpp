#ifndef RUNE_TMX_WANG_COLOR_HPP
#define RUNE_TMX_WANG_COLOR_HPP

#include <json.hpp>  // json
#include <string>    // string

#include "tmx_color.hpp"
#include "tmx_local_id.hpp"
#include "tmx_property.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_color final
{
  tmx_local_id tile{};
  tmx_color color;
  std::string name;
  float probability{};
  tmx_properties properties;
};

void from_json(const nlohmann::json& json, tmx_wang_color& color);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_COLOR_HPP
