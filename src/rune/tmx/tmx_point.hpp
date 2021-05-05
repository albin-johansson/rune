#pragma once

#include <json.hpp>  // json

namespace rune {

struct tmx_point final
{
  float x{};
  float y{};
};

inline void from_json(const nlohmann::json& json, tmx_point& point)
{
  json.at("x").get_to(point.x);
  json.at("y").get_to(point.y);
}

}  // namespace rune
