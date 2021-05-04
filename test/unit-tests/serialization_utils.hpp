#pragma once

#include <cereal/archives/binary.hpp>
#include <cereal/cereal.hpp>
#include <fstream>      // ifstream, ofstream
#include <ios>          // ios
#include <type_traits>  // is_default_constructible_v

// clang-format off

template <typename T> requires std::is_default_constructible_v<T>
[[nodiscard]] auto serialize_read(const char* file) -> T
{
  std::ifstream stream{file, std::ios::binary};
  cereal::BinaryInputArchive archive{stream};

  T obj;
  archive(obj);

  return obj;
}

// clang-format on

template <typename T>
void serialize_write(const char* file, T&& obj)
{
  std::ofstream stream{file, std::ios::binary};
  cereal::BinaryOutputArchive archive{stream};

  archive(obj);
}

// clang-format on
