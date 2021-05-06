#pragma once

#include <cassert>   // assert
#include <json.hpp>  // json
#include <string>    // string
#include <variant>   // variant
#include <vector>    // vector

#include "../aliases/integers.hpp"
#include "tmx_global_id.hpp"

namespace rune {

struct tmx_data final
{
  using gid_data = std::vector<tmx_global_id>;
  using base64_data = std::string;
  using data_type = std::variant<gid_data, base64_data>;

  data_type tile_data;
};

void from_json(const nlohmann::json& json, tmx_data& data);

}  // namespace rune
