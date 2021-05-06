#pragma once

#include <json.hpp>  // json
#include <string>    // string
#include <vector>    // vector

#include "tmx_local_id.hpp"
#include "tmx_property.hpp"

namespace rune {

struct tmx_terrain final
{
  tmx_local_id tile{};
  std::string name;
  std::vector<tmx_property> properties;
};

void from_json(const nlohmann::json& json, tmx_terrain& terrain);

}  // namespace rune
