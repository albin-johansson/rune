#pragma once

#include <json.hpp>  // json

namespace rune {

struct tmx_point final
{
  float x{};
  float y{};
};

void from_json(const nlohmann::json& json, tmx_point& point);

}  // namespace rune
