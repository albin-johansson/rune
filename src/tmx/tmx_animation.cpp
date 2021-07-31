#include "tmx/tmx_animation.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_frame& frame)
{
  using ms_t = std::chrono::milliseconds;

  io::emplace_to(json, "tileid", frame.tile);
  frame.duration = ms_t{json.at("duration").get<ms_t::rep>()};
}

void from_json(const json_type& json, tmx_animation& animation)
{
  io::get_to(json, animation.frames);
}

}  // namespace rune
