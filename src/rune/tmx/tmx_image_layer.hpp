#pragma once

#include <json.hpp>  // json
#include <optional>  // optional
#include <string>    // string

#include "tmx_color.hpp"

namespace rune {

struct tmx_image_layer final
{
  std::string image;
  std::optional<tmx_color> transparent;
};

void from_json(const nlohmann::json& json, tmx_image_layer& layer);

}  // namespace rune
