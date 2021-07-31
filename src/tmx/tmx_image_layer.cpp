#include "tmx/tmx_image_layer.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_image_layer& layer)
{
  json.at("image").get_to(layer.image);
  io::try_get_to(json, "transparentcolor", layer.transparent);
}

}  // namespace rune
