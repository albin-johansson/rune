#ifndef RUNE_TMX_ANIMATION_HPP
#define RUNE_TMX_ANIMATION_HPP

#include <json.hpp>  // json
#include <vector>    // vector

#include "tmx_local_id.hpp"

namespace rune {

struct tmx_frame final
{
  tmx_local_id tile{};
  int duration{};  // Milliseconds, TODO chrono?
};

struct tmx_animation final
{
  std::vector<tmx_frame> frames;
};

void from_json(const nlohmann::json& json, tmx_frame& frame);
void from_json(const nlohmann::json& json, tmx_animation& animation);

}  // namespace rune

#endif  // RUNE_TMX_ANIMATION_HPP
