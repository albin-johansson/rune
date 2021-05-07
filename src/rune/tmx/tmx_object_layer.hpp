#ifndef RUNE_TMX_OBJECT_LAYER_HPP
#define RUNE_TMX_OBJECT_LAYER_HPP

#include <cassert>   // assert
#include <json.hpp>  // json, NLOHMANN_JSON_SERIALIZE_ENUM
#include <vector>    // vector

#include "tmx_object.hpp"

namespace rune {

enum class tmx_object_layer_draw_order
{
  top_down,
  index
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_object_layer_draw_order,
                             {{tmx_object_layer_draw_order::top_down, "topdown"},
                              {tmx_object_layer_draw_order::index, "index"}})

struct tmx_object_layer final  // Note, referred to as "object group" by tiled
{
  tmx_object_layer_draw_order draw_order{tmx_object_layer_draw_order::top_down};
  std::vector<tmx_object> objects;
};

void from_json(const nlohmann::json& json, tmx_object_layer& layer);

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_LAYER_HPP
