#ifndef RUNE_TMX_LAYER_HPP
#define RUNE_TMX_LAYER_HPP

#include <cassert>   // assert
#include <json.hpp>  // json
#include <memory>    // unique_ptr
#include <string>    // string
#include <variant>   // variant, monostate
#include <vector>    // vector

#include "../aliases/integers.hpp"
#include "../io/json_utils.hpp"
#include "tmx_image_layer.hpp"
#include "tmx_layer_type.hpp"
#include "tmx_object.hpp"
#include "tmx_object_layer.hpp"
#include "tmx_property.hpp"
#include "tmx_tile_layer.hpp"

namespace rune {

struct tmx_layer;

struct tmx_group final
{
  std::vector<std::unique_ptr<tmx_layer>> layers;
};

struct tmx_layer final
{
  using data_type = std::variant<std::monostate,
                                 tmx_tile_layer,
                                 tmx_image_layer,
                                 tmx_object_layer,
                                 tmx_group>;

  tmx_layer_type type{tmx_layer_type::tile_layer};
  int id{};

  data_type data;

  std::vector<tmx_property> properties;

  int width{};
  int height{};
  int start_x{};
  int start_y{};
  float offset_x{};
  float offset_y{};
  float opacity{1};

  std::string name;
  bool visible{true};
};

void from_json(const nlohmann::json& json, tmx_group& group);
void from_json(const nlohmann::json& json, tmx_layer& layer);

namespace tmx {

[[nodiscard]] inline auto as_tile_layer(const tmx_layer& layer) -> const tmx_tile_layer&
{
  return std::get<tmx_tile_layer>(layer.data);
}

[[nodiscard]] inline auto as_image_layer(const tmx_layer& layer) -> const tmx_image_layer&
{
  return std::get<tmx_image_layer>(layer.data);
}

[[nodiscard]] inline auto as_object_layer(const tmx_layer& layer)
    -> const tmx_object_layer&
{
  return std::get<tmx_object_layer>(layer.data);
}

[[nodiscard]] inline auto as_group(const tmx_layer& layer) -> const tmx_group&
{
  return std::get<tmx_group>(layer.data);
}

[[nodiscard]] inline auto is_tile_layer(const tmx_layer& layer) noexcept -> bool
{
  return std::holds_alternative<tmx_tile_layer>(layer.data);
}

[[nodiscard]] inline auto is_object_layer(const tmx_layer& layer) noexcept -> bool
{
  return std::holds_alternative<tmx_object_layer>(layer.data);
}

[[nodiscard]] inline auto is_image_layer(const tmx_layer& layer) noexcept -> bool
{
  return std::holds_alternative<tmx_image_layer>(layer.data);
}

[[nodiscard]] inline auto is_group(const tmx_layer& layer) noexcept -> bool
{
  return std::holds_alternative<tmx_group>(layer.data);
}

}  // namespace tmx
}  // namespace rune

#endif  // RUNE_TMX_LAYER_HPP
