#include "tmx/tmx_object_layer.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_object_layer& layer)
{
  io::get_to(json, "objects", layer.objects);
}

}  // namespace rune
