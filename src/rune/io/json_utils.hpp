#pragma once

#include <cassert>      // assert
#include <json.hpp>     // json
#include <optional>     // optional
#include <string_view>  // string_view

namespace rune {

template <typename T>
void get_if_exists(const nlohmann::json& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

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

template <typename Container>
void fill(const nlohmann::json& json, Container& container)
{
  assert(json.is_array());

  container.reserve(json.size());
  for (const auto& [key, value] : json.items())
  {
    using value_type = typename Container::value_type;
    container.push_back(value.get<value_type>());
  }
}

template <typename Container>
void fill(const nlohmann::json& json, const std::string_view key, Container& container)
{
  const auto it = json.find(key);
  assert(it != json.end());
  assert(it->is_array());

  container.reserve(it->size());
  for (const auto& [key, value] : it->items())
  {
    using value_type = typename Container::value_type;
    container.push_back(value.get<value_type>());
  }
}

template <typename Container>
void fill_if_exists(const nlohmann::json& json,
                    const std::string_view key,
                    Container& container)
{
  if (const auto it = json.find(key); it != json.end())
  {
    container.reserve(it->size());
    for (const auto& [key, value] : it->items())
    {
      using value_type = typename Container::value_type;
      container.push_back(value.get<value_type>());
    }
  }
}

}  // namespace rune
