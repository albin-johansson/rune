#ifndef RUNE_TMX_OBJECT_HPP
#define RUNE_TMX_OBJECT_HPP

#include <memory>    // unique_ptr
#include <optional>  // optional
#include <string>    // string
#include <variant>   // variant, monostate
#include <vector>    // vector

#include "../aliases/integers.hpp"
#include "../io/json_utils.hpp"
#include "tmx_global_id.hpp"
#include "tmx_point.hpp"
#include "tmx_property.hpp"
#include "tmx_text.hpp"

namespace rune {

struct tmx_object;

struct tmx_polygon final
{
  std::vector<tmx_point> points;
};

struct tmx_polyline final
{
  std::vector<tmx_point> points;
};

struct tmx_template_object final
{
  std::string template_file;
  std::unique_ptr<tmx_object> object;
  // TODO std::shared_ptr<tmx_tileset> tileset;  // optional
};

struct tmx_object final
{
  using data_type = std::variant<std::monostate,
                                 tmx_polygon,
                                 tmx_polyline,
                                 tmx_text,
                                 tmx_template_object,
                                 tmx_global_id>;

  int id{};
  float x{};
  float y{};
  float width{};
  float height{};
  float rotation{};
  std::string name;
  std::string type;
  std::vector<tmx_property> properties;
  data_type data;
  bool is_ellipse{};
  bool is_point{};
  bool visible{true};
};

void from_json(const nlohmann::json& json, tmx_polygon& polygon);
void from_json(const nlohmann::json& json, tmx_polyline& line);
void from_json(const nlohmann::json& json, tmx_template_object& object);
void from_json(const nlohmann::json& json, tmx_object& object);

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_HPP
