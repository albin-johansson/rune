#pragma once

#include "../aliases/integers.hpp"
#include "tmx_global_id.hpp"
#include "tmx_local_id.hpp"

namespace rune {
namespace tmx_literals {

[[nodiscard]] constexpr auto operator""_local(const ulonglong value) noexcept
    -> tmx_local_id
{
  return tmx_local_id{static_cast<tmx_local_id::value_type>(value)};
}

[[nodiscard]] constexpr auto operator""_global(const ulonglong value) noexcept
    -> tmx_global_id
{
  return tmx_global_id{static_cast<tmx_global_id::value_type>(value)};
}

}  // namespace tmx_literals

}  // namespace rune
