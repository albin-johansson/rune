#ifndef RUNE_TMX_DATA_HPP
#define RUNE_TMX_DATA_HPP

#include <cassert>  // assert
#include <string>   // string
#include <variant>  // variant
#include <vector>   // vector

#include "../aliases/integers.hpp"
#include "../aliases/json_type.hpp"
#include "rune_api.hpp"
#include "tmx_global_id.hpp"

namespace rune {

struct tmx_data final
{
  using gid_data = std::vector<tmx_global_id>;
  using base64_data = std::string;
  using data_type = std::variant<gid_data, base64_data>;

  data_type tile_data;
};

RUNE_API void from_json(const json_type& json, tmx_data& data);

}  // namespace rune

#endif  // RUNE_TMX_DATA_HPP
