#ifndef RUNE_TMX_IMAGE_LAYER_HPP
#define RUNE_TMX_IMAGE_LAYER_HPP

#include <json.hpp>  // json
#include <optional>  // optional
#include <string>    // string

#include "tmx_color.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_image_layer final
{
  std::string image;
  std::optional<tmx_color> transparent;
};

void from_json(const nlohmann::json& json, tmx_image_layer& layer);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_IMAGE_LAYER_HPP
