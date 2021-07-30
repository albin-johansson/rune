#ifndef RUNE_TMX_IMAGE_LAYER_HPP
#define RUNE_TMX_IMAGE_LAYER_HPP

#include <string>  // string

#include "../aliases/json_type.hpp"
#include "../aliases/maybe.hpp"
#include "rune_api.hpp"
#include "tmx_color.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_image_layer final
{
  std::string image;
  maybe<tmx_color> transparent;
};

RUNE_API void from_json(const json_type& json, tmx_image_layer& layer);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_IMAGE_LAYER_HPP
