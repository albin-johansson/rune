#ifndef RUNE_IO_JSON_UTILS_HPP
#define RUNE_IO_JSON_UTILS_HPP

#include <cassert>      // assert
#include <filesystem>   // path
#include <fstream>      // ifstream
#include <json.hpp>     // json
#include <optional>     // optional
#include <ranges>       // range
#include <string_view>  // string_view

namespace rune {

/// \addtogroup io
/// \{

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
template <typename T>
void get_if_exists(const nlohmann::json& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

/// \copydoc get_if_exists()
template <typename T>
void get_if_exists(const nlohmann::json& json,
                   const std::string_view key,
                   std::optional<T>& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
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
template <typename Container>
void fill(const nlohmann::json& array, Container& container)
{
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
template <typename Container>
void fill(const nlohmann::json& json, const std::string_view key, Container& container)
{
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
template <typename Container>
void fill_if_exists(const nlohmann::json& json,
                    const std::string_view key,
                    Container& container)
{
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

/// \} End of group io

}  // namespace rune

#endif  // RUNE_IO_JSON_UTILS_HPP
