#ifndef RUNE_TMX_PROPERTY_HPP
#define RUNE_TMX_PROPERTY_HPP

#include <cassert>      // assert
#include <concepts>     // same_as
#include <json.hpp>     // json
#include <nenya.hpp>    // strong_type
#include <ranges>       // any_of, find_if
#include <string>       // string
#include <string_view>  // string_view
#include <variant>      // variant, get, get_if, holds_alternative
#include <vector>       // vector

#include "../core/rune_error.hpp"
#include "tmx_color.hpp"
#include "tmx_property_type.hpp"

namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_file_tag;
struct tmx_object_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_file = nenya::strong_type<std::string, tags::tmx_file_tag>;
using tmx_object_id = nenya::strong_type<int, tags::tmx_object_id_tag>;

/**
 * \brief Represents a property, with an associated name and value.
 */
struct tmx_property final
{
  using data_type =
      std::variant<std::string, tmx_file, tmx_object_id, tmx_color, int, float, bool>;

  std::string name;
  tmx_property_type type{tmx_property_type::string};
  data_type value;
};

using tmx_properties = std::vector<tmx_property>;

void from_json(const nlohmann::json& json, tmx_property& property);

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

// clang-format off

template <typename T>
concept property_value_type = std::same_as<T, int> ||
                              std::same_as<T, float> ||
                              std::same_as<T, bool> ||
                              std::same_as<T, std::string> ||
                              std::same_as<T, tmx_color> ||
                              std::same_as<T, tmx_file> ||
                              std::same_as<T, tmx_object_id>;

// clang-format on

/// \name Property functions
/// \{

[[nodiscard]] inline auto try_get(const tmx_properties& properties,
                                  const std::string_view name)
    -> tmx_properties::const_iterator
{
  return std::ranges::find_if(properties, [name](const tmx_property& property) noexcept {
    return property.name == name;
  });
}

[[nodiscard]] inline auto try_get_string(const tmx_property& property) noexcept
    -> const std::string*
{
  return std::get_if<std::string>(&property.value);
}

[[nodiscard]] inline auto try_get_string(const tmx_properties& properties,
                                         const std::string_view name)
    -> const std::string*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<std::string>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto try_get_int(const tmx_property& property) noexcept -> const int*
{
  return std::get_if<int>(&property.value);
}

[[nodiscard]] inline auto try_get_int(const tmx_properties& properties,
                                      const std::string_view name) -> const int*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<int>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto try_get_float(const tmx_property& property) noexcept -> const
    float*
{
  return std::get_if<float>(&property.value);
}

[[nodiscard]] inline auto try_get_float(const tmx_properties& properties,
                                        const std::string_view name) -> const float*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<float>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto try_get_bool(const tmx_property& property) noexcept -> const
    bool*
{
  return std::get_if<bool>(&property.value);
}

[[nodiscard]] inline auto try_get_bool(const tmx_properties& properties,
                                       const std::string_view name) -> const bool*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<bool>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto try_get_color(const tmx_property& property) noexcept
    -> const tmx_color*
{
  return std::get_if<tmx_color>(&property.value);
}

[[nodiscard]] inline auto try_get_color(const tmx_properties& properties,
                                        const std::string_view name) -> const tmx_color*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<tmx_color>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto try_get_file(const tmx_property& property) noexcept
    -> const tmx_file*
{
  return std::get_if<tmx_file>(&property.value);
}

[[nodiscard]] inline auto try_get_file(const tmx_properties& properties,
                                       const std::string_view name) -> const tmx_file*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<tmx_file>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto try_get_object(const tmx_property& property) noexcept
    -> const tmx_object_id*
{
  return std::get_if<tmx_object_id>(&property.value);
}

[[nodiscard]] inline auto try_get_object(const tmx_properties& properties,
                                         const std::string_view name)
    -> const tmx_object_id*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<tmx_object_id>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

template <property_value_type T>
[[nodiscard]] auto is(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<T>(property.value);
}

template <property_value_type T>
[[nodiscard]] auto is(const tmx_properties& properties, const std::string_view name)
    -> bool
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return is<T>(*it);
  }
  else
  {
    return false;
  }
}

[[nodiscard]] inline auto is_string(const tmx_property& property) noexcept -> bool
{
  return is<std::string>(property);
}

[[nodiscard]] inline auto is_string(const tmx_properties& properties,
                                    const std::string_view name) -> bool
{
  return is<std::string>(properties, name);
}

[[nodiscard]] inline auto is_int(const tmx_property& property) noexcept -> bool
{
  return is<int>(property);
}

[[nodiscard]] inline auto is_int(const tmx_properties& properties,
                                 const std::string_view name) -> bool
{
  return is<int>(properties, name);
}

[[nodiscard]] inline auto is_float(const tmx_property& property) noexcept -> bool
{
  return is<float>(property);
}

[[nodiscard]] inline auto is_float(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return is<float>(properties, name);
}

[[nodiscard]] inline auto is_bool(const tmx_property& property) noexcept -> bool
{
  return is<bool>(property);
}

[[nodiscard]] inline auto is_bool(const tmx_properties& properties,
                                  const std::string_view name) -> bool
{
  return is<bool>(properties, name);
}

[[nodiscard]] inline auto is_color(const tmx_property& property) noexcept -> bool
{
  return is<tmx_color>(property);
}

[[nodiscard]] inline auto is_color(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return is<tmx_color>(properties, name);
}

[[nodiscard]] inline auto is_file(const tmx_property& property) noexcept -> bool
{
  return is<tmx_file>(property);
}

[[nodiscard]] inline auto is_file(const tmx_properties& properties,
                                  const std::string_view name) -> bool
{
  return is<tmx_file>(properties, name);
}

[[nodiscard]] inline auto is_object(const tmx_property& property) noexcept -> bool
{
  return is<tmx_object_id>(property);
}

[[nodiscard]] inline auto is_object(const tmx_properties& properties,
                                    const std::string_view name) -> bool
{
  return is<tmx_object_id>(properties, name);
}

template <property_value_type T>
[[nodiscard]] auto get(const tmx_property& property) -> const T&
{
  return std::get<T>(property.value);
}

template <property_value_type T>
[[nodiscard]] auto get(const tmx_properties& properties, const std::string_view name)
    -> const T&
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return get<T>(*it);
  }
  else
  {
    throw rune_error{"Could not find property with the specified name!"};
  }
}

[[nodiscard]] inline auto get_string(const tmx_property& property) -> const std::string&
{
  return get<std::string>(property);
}

[[nodiscard]] inline auto get_string(const tmx_properties& properties,
                                     const std::string_view name) -> const std::string&
{
  return get<std::string>(properties, name);
}

[[nodiscard]] inline auto get_int(const tmx_property& property) -> int
{
  return get<int>(property);
}

[[nodiscard]] inline auto get_int(const tmx_properties& properties,
                                  const std::string_view name) -> int
{
  return get<int>(properties, name);
}

[[nodiscard]] inline auto get_float(const tmx_property& property) -> float
{
  return get<float>(property);
}

[[nodiscard]] inline auto get_float(const tmx_properties& properties,
                                    const std::string_view name) -> float
{
  return get<float>(properties, name);
}

[[nodiscard]] inline auto get_bool(const tmx_property& property) -> bool
{
  return get<bool>(property);
}

[[nodiscard]] inline auto get_bool(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return get<bool>(properties, name);
}

[[nodiscard]] inline auto get_color(const tmx_property& property) -> const tmx_color&
{
  return get<tmx_color>(property);
}

[[nodiscard]] inline auto get_color(const tmx_properties& properties,
                                    const std::string_view name) -> const tmx_color&
{
  return get<tmx_color>(properties, name);
}

[[nodiscard]] inline auto get_file(const tmx_property& property) -> const tmx_file&
{
  return get<tmx_file>(property);
}

[[nodiscard]] inline auto get_file(const tmx_properties& properties,
                                   const std::string_view name) -> const tmx_file&
{
  return get<tmx_file>(properties, name);
}

[[nodiscard]] inline auto get_object(const tmx_property& property) -> tmx_object_id
{
  return get<tmx_object_id>(property);
}

[[nodiscard]] inline auto get_object(const tmx_properties& properties,
                                     const std::string_view name) -> tmx_object_id
{
  return get<tmx_object_id>(properties, name);
}

/**
 * \brief Indicates whether or not a property with the specified name exists in a vector
 * of properties.
 *
 * \param properties the vector of properties that will be searched.
 * \param name the name of the property to look for.
 *
 * \return `true` if the properties contains a property with the specified name; `false`
 * otherwise.
 */
[[nodiscard]] inline auto contains(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return std::ranges::any_of(properties, [name](const tmx_property& property) noexcept {
    return property.name == name;
  });
}

/**
 * \brief Attempts to find and return a property with the specified name.
 *
 * \param properties the properties that will be searched.
 * \param name the name of the desired property.
 *
 * \return the property with the specified name.
 *
 * \throws rune_error if there is no property with the specified name.
 */
[[nodiscard]] inline auto at(const tmx_properties& properties,
                             const std::string_view name) -> const tmx_property&
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return *it;
  }
  else
  {
    throw rune_error{"Could not find property with specified name!"};
  }
}

/// \} End of property functions

/// \} End of group tmx

}  // namespace tmx

}  // namespace rune

#endif  // RUNE_TMX_PROPERTY_HPP
