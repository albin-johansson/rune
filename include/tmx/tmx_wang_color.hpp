#ifndef RUNE_TMX_WANG_COLOR_HPP
#define RUNE_TMX_WANG_COLOR_HPP

#include <string>  // string

#include "../aliases/json_type.hpp"
#include "rune_api.hpp"
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

RUNE_API void from_json(const json_type& json, tmx_wang_color& color);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_COLOR_HPP
