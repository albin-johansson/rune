#ifndef RUNE_TMX_OBJECT_HPP
#define RUNE_TMX_OBJECT_HPP

#include <memory>    // unique_ptr
#include <optional>  // optional
#include <string>    // string
#include <variant>   // variant, monostate
#include <vector>    // vector

#include "../aliases/integers.hpp"
#include "../aliases/json_type.hpp"
#include "../io/json_utils.hpp"
#include "tmx_global_id.hpp"
#include "tmx_point.hpp"
#include "tmx_property.hpp"
#include "tmx_text.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

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
  std::optional<std::string> tileset_source;
  std::optional<tmx_global_id> tileset_first_id;
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
  tmx_properties properties;
  data_type data;
  bool is_ellipse{};
  bool is_point{};
  bool visible{true};
};

void from_json(const json_type& json, tmx_polygon& polygon);
void from_json(const json_type& json, tmx_polyline& line);
void from_json(const json_type& json, tmx_template_object& object);
void from_json(const json_type& json, tmx_object& object);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_HPP
