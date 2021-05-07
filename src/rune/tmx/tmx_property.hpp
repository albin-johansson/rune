#ifndef RUNE_TMX_PROPERTY_HPP
#define RUNE_TMX_PROPERTY_HPP

#include <cassert>    // assert
#include <json.hpp>   // json
#include <nenya.hpp>  // strong_type
#include <string>     // string
#include <variant>    // variant, get, get_if, holds_alternative
#include <vector>     // vector

#include "tmx_color.hpp"

namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_file_tag;
struct tmx_object_tag;
}  // namespace tags
/// \endcond

using tmx_file = nenya::strong_type<std::string, tags::tmx_file_tag>;
using tmx_object_id = nenya::strong_type<int, tags::tmx_object_tag>;

enum class tmx_property_type
{
  string,    ///< For string values, such as `"foo"`.
  integer,   ///< For integer values, e.g. `27`.
  floating,  ///< For floating-point values, e.g. `182.4`.
  boolean,   ///< For the boolean values `true`/`false`.
  color,     ///< For ARGB/RGB colors, i.e. `"#AARRGGBB"` and `"#RRGGBB"`.
  file,      ///< For file paths, e.g. `"some/path/abc.png"`.
  object     ///< For referencing other objects, really just an integer ID.
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_property_type,
                             {{tmx_property_type::string, "string"},
                              {tmx_property_type::integer, "int"},
                              {tmx_property_type::floating, "float"},
                              {tmx_property_type::boolean, "bool"},
                              {tmx_property_type::color, "color"},
                              {tmx_property_type::object, "object"},
                              {tmx_property_type::file, "file"}})

struct tmx_property final
{
  using data_type =
      std::variant<std::string, tmx_file, tmx_object_id, tmx_color, int, float, bool>;

  std::string name;
  tmx_property_type type{tmx_property_type::string};
  data_type value;
};

void from_json(const nlohmann::json& json, tmx_property& property);

namespace tmx {

[[nodiscard]] inline auto is_string(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<std::string>(property.value);
}

[[nodiscard]] inline auto is_integer(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<int>(property.value);
}

[[nodiscard]] inline auto is_float(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<float>(property.value);
}

[[nodiscard]] inline auto is_boolean(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<bool>(property.value);
}

[[nodiscard]] inline auto is_color(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<tmx_color>(property.value);
}

[[nodiscard]] inline auto is_file(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<tmx_file>(property.value);
}

[[nodiscard]] inline auto is_object(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<tmx_object_id>(property.value);
}

template <typename T>
[[nodiscard]] auto value_cast(const tmx_property& property) -> const T&
{
  return std::get<T>(property.value);
}

[[nodiscard]] inline auto as_string(const tmx_property& property) -> const std::string&
{
  return value_cast<std::string>(property);
}

[[nodiscard]] inline auto as_integer(const tmx_property& property) -> int
{
  return value_cast<int>(property);
}

[[nodiscard]] inline auto as_float(const tmx_property& property) -> float
{
  return value_cast<float>(property);
}

[[nodiscard]] inline auto as_boolean(const tmx_property& property) -> bool
{
  return value_cast<bool>(property);
}

[[nodiscard]] inline auto as_color(const tmx_property& property) -> const tmx_color&
{
  return value_cast<tmx_color>(property);
}

[[nodiscard]] inline auto as_file(const tmx_property& property) -> const tmx_file&
{
  return value_cast<tmx_file>(property);
}

[[nodiscard]] inline auto as_object(const tmx_property& property) -> const tmx_object_id&
{
  return value_cast<tmx_object_id>(property);
}

[[nodiscard]] inline auto try_as_string(const tmx_property& property) noexcept
    -> const std::string*
{
  return std::get_if<std::string>(&property.value);
}

[[nodiscard]] inline auto try_as_integer(const tmx_property& property) noexcept -> const
    int*
{
  return std::get_if<int>(&property.value);
}

[[nodiscard]] inline auto try_as_float(const tmx_property& property) noexcept -> const
    float*
{
  return std::get_if<float>(&property.value);
}

[[nodiscard]] inline auto try_as_boolean(const tmx_property& property) noexcept -> const
    bool*
{
  return std::get_if<bool>(&property.value);
}

[[nodiscard]] inline auto try_as_color(const tmx_property& property) noexcept
    -> const tmx_color*
{
  return std::get_if<tmx_color>(&property.value);
}

[[nodiscard]] inline auto try_as_file(const tmx_property& property) noexcept
    -> const tmx_file*
{
  return std::get_if<tmx_file>(&property.value);
}

[[nodiscard]] inline auto try_as_object(const tmx_property& property) noexcept
    -> const tmx_object_id*
{
  return std::get_if<tmx_object_id>(&property.value);
}

}  // namespace tmx
}  // namespace rune

#endif  // RUNE_TMX_PROPERTY_HPP
