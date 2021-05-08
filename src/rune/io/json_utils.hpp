#ifndef RUNE_IO_JSON_UTILS_HPP
#define RUNE_IO_JSON_UTILS_HPP

#include <cassert>      // assert
#include <filesystem>   // path
#include <fstream>      // ifstream
#include <json.hpp>     // json
#include <optional>     // optional
#include <string_view>  // string_view
#include <variant>      // variant

#include "../core/concepts.hpp"

namespace rune {

/// \addtogroup io
/// \{

/// \name JSON
/// \{

// clang-format off

template <typename T>
concept json_type = requires (const nlohmann::json& json)
{
  { json.get<T>() };
};

// clang-format on

/**
 * \brief Parses the JSON file at the specified path, and returns the contents.
 *
 * \pre `file` must refer to a JSON file.
 *
 * \param file the file path of the JSON file.
 *
 * \return the parsed JSON data.
 */
[[nodiscard]] inline auto read_json(const std::filesystem::path& file) -> nlohmann::json
{
  assert(file.extension() == ".json");
  std::ifstream stream{file};

  nlohmann::json json;
  stream >> json;

  return json;
}

/**
 * \brief Writes the data associated with the specified key to the specified value, as
 * long as the key exists in the JSON object.
 *
 * \details This function requires that values of type `T` can be obtained from JSON
 * objects, i.e. the type needs to provide an overload of the `from_json()` function.
 *
 * \note This function has no effect if there is no element associated with the specified
 * key.
 *
 * \tparam T the deduced the type of the value that might be assigned.
 *
 * \param json the JSON object.
 * \param key the element to look for.
 * \param[out] value a reference to the value that will be assigned with the data
 * associated with `key`, if it exists.
 */
template <json_type T>
void get_if_exists(const nlohmann::json& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

/// \copydoc get_if_exists()
template <json_type T>
void get_if_exists(const nlohmann::json& json,
                   const std::string_view key,
                   std::optional<T>& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

template <has_value_type T>
void emplace(const nlohmann::json& json, const std::string_view key, T& value)
{
  static_assert(json_type<typename T::value_type>);

  const auto it = json.find(key);
  assert(it != json.end());

  value = T{it->get<typename T::value_type>()};
}

template <has_value_type T>
void emplace(const nlohmann::json& json,
             const std::string_view key,
             std::optional<T>& value)
{
  static_assert(json_type<typename T::value_type>);

  const auto it = json.find(key);
  assert(it != json.end());

  value = T{it->get<typename T::value_type>()};
}

template <has_value_type T>
void emplace_if_exists(const nlohmann::json& json, const std::string_view key, T& value)
{
  static_assert(json_type<typename T::value_type>);

  if (const auto it = json.find(key); it != json.end())
  {
    value = T{it->get<typename T::value_type>()};
  }
}

template <has_value_type T>
void emplace_if_exists(const nlohmann::json& json,
                       const std::string_view key,
                       std::optional<T>& value)
{
  static_assert(json_type<typename T::value_type>);

  if (const auto it = json.find(key); it != json.end())
  {
    value.emplace(it->get<typename T::value_type>());
  }
}

/**
 * \brief Writes the data associated with the specified key to the specified variant, as
 * long as the key exists in the JSON object.
 *
 * \details This function requires that values of type `T` can be obtained from JSON
 * objects, i.e. the type needs to provide an overload of the `from_json()` function.
 *
 * \note This function has no effect if there is no element associated with the specified
 * key.
 *
 * \tparam T the type of the data that will be extracted from the JSON object.
 * \tparam Types the types used by the variant.
 *
 * \param json the JSON object.
 * \param key the element to look for.
 * \param[out] variant the variant that the data will be written to.
 */
template <json_type T, typename... Types>
void emplace_if_exists(const nlohmann::json& json,
                       const std::string_view key,
                       std::variant<Types...>& variant)
{
  if (const auto it = json.find(key); it != json.end())
  {
    variant.template emplace<T>(it->get<T>());
  }
}

/**
 * \brief Fills a container with values from a JSON array.
 *
 * \details This function requires that values of type `Container::value_type` can be
 * obtained from JSON objects, i.e. the type needs to provide an overload of the
 * `from_json()` function.
 *
 * \pre `array` must represent a JSON array.
 *
 * \tparam Container the container type, e.g. `std::vector` or `std::array`.
 *
 * \param array the JSON array that provides the source data.
 * \param[out] container the container that will be filled.
 */
template <has_value_type Container>
void fill(const nlohmann::json& array, Container& container)
{
  static_assert(json_type<typename Container::value_type>);
  assert(array.is_array());

  container.reserve(array.size());
  for (const auto& [key, value] : array.items())
  {
    container.push_back(value.template get<typename Container::value_type>());
  }
}

/**
 * \brief Fills a container with values from a JSON array.
 *
 * \details This function requires that values of type `Container::value_type` can be
 * obtained from JSON objects, i.e. the type needs to provide an overload of the
 * `from_json()` function.
 *
 * \pre `json` must contain the specified key.
 * \pre The JSON element associated with the specified key must be an array.
 *
 * \tparam Container the container type, e.g. `std::vector` or `std::array`.
 *
 * \param json the JSON object that contains an array associated with the specified key.
 * \param key the key of the JSON array element.
 * \param[out] container the container that will be filled.
 */
template <has_value_type Container>
void fill(const nlohmann::json& json, const std::string_view key, Container& container)
{
  static_assert(json_type<typename Container::value_type>);

  const auto it = json.find(key);
  assert(it != json.end());
  assert(it->is_array());

  container.reserve(it->size());
  for (const auto& [key, value] : it->items())
  {
    container.push_back(value.template get<typename Container::value_type>());
  }
}

/**
 * \brief Fills a container with values from a JSON array, if it exists.
 *
 * \details This function requires that values of type `Container::value_type` can be
 * obtained from JSON objects, i.e. the type needs to provide an overload of the
 * `from_json()` function.
 *
 * \note This function has no effect if there is no element associated with the specified
 * key.
 *
 * \pre The JSON element associated with the specified key must be an array.
 *
 * \tparam Container the container type, e.g. `std::vector` or `std::array`.
 *
 * \param json the JSON object that contains an array associated with the specified key.
 * \param key the key of the JSON array element.
 * \param[out] container the container that will be filled.
 */
template <has_value_type Container>
void fill_if_exists(const nlohmann::json& json,
                    const std::string_view key,
                    Container& container)
{
  static_assert(json_type<typename Container::value_type>);

  if (const auto it = json.find(key); it != json.end())
  {
    assert(it->is_array());
    container.reserve(it->size());
    for (const auto& [key, value] : it->items())
    {
      container.push_back(value.template get<typename Container::value_type>());
    }
  }
}

/// \} End of JSON

/// \} End of group io

}  // namespace rune

#endif  // RUNE_IO_JSON_UTILS_HPP
