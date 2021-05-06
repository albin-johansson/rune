#pragma once

#include <array>     // array
#include <json.hpp>  // json

#include "tmx_local_id.hpp"
#include "../aliases/integers.hpp"

namespace rune {

struct tmx_wang_tile final
{
  tmx_local_id tile{};
  std::array<uint8, 8> indices{};
};

void from_json(const nlohmann::json& json, tmx_wang_tile& tile);

}  // namespace rune
