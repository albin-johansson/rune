#include "tmx/tmx_tile_layer.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_tile_layer& layer)
{
  io::try_get_to(json, "compression", layer.compression);
  io::try_get_to(json, "encoding", layer.encoding);
  io::try_get_to(json, "data", layer.data);

  // TODO
  //  if (json.contains("chunks")) {
  //    m_chunks = detail::fill<std::vector<chunk>>(json, "chunks");
  //  }
}

}  // namespace rune
