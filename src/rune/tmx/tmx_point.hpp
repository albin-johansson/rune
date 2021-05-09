#ifndef RUNE_TMX_POINT_HPP
#define RUNE_TMX_POINT_HPP

#include "../aliases/json_type.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_point final
{
  float x{};
  float y{};
};

void from_json(const json_type& json, tmx_point& point);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_POINT_HPP
