#ifndef RUNE_TMX_POINT_HPP
#define RUNE_TMX_POINT_HPP

#include <json.hpp>  // json

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_point final
{
  float x{};
  float y{};
};

void from_json(const nlohmann::json& json, tmx_point& point);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_POINT_HPP
