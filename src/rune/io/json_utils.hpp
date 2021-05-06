#pragma once

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

}  // namespace rune
