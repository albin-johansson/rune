#pragma once

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

inline void from_json(const nlohmann::json& json, tmx_frame& frame)
{
  frame.tile = tmx_local_id{json.at("tileid").get<tmx_local_id::value_type>()};
  json.at("duration").get_to(frame.duration);
}

inline void from_json(const nlohmann::json& json, tmx_animation& animation)
{
  animation.frames.reserve(json.size());
  for (const auto& [key, value] : json.items())
  {
    animation.frames.push_back(value.get<tmx_frame>());
  }
}

}  // namespace rune
