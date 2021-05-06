#pragma once

#include <json.hpp>  // json
#include <string>    // string

#include "tmx_color.hpp"
#include "tmx_local_id.hpp"

namespace rune {

struct tmx_wang_color final
{
  tmx_local_id tile{};
  tmx_color color;
  std::string name;
  float probability{};
};

void from_json(const nlohmann::json& json, tmx_wang_color& color);

}  // namespace rune
