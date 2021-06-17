#ifndef RUNE_CORE_TO_STRING_HPP
#define RUNE_CORE_TO_STRING_HPP

#include <array>         // array
#include <charconv>      // to_chars
#include <concepts>      // floating_point
#include <optional>      // optional
#include <string>        // string, to_string
#include <system_error>  // errc

#include "../aliases/integers.hpp"
#include "compiler.hpp"
#include "concepts.hpp"

namespace rune {

/// \addtogroup core
/// \{

/**
 * \brief Returns a string representation of an arithmetic value.
 *
 * \note The default buffer size is guaranteed to work for 64-bit integers and floats.
 *
 * \remark This function just calls `std::to_string()` on GCC, or if the compiler is
 * Clang and the supplied number is floating-point.
 *
 * \tparam BufferSize the size of the stack buffer used, must be big enough to store the
 * characters of the string representation of the value.
 *
 * \tparam T the type of the value that will be converted.
 *
 * \param number the number that will be converted.
 *
 * \return a string representation of the supplied value; `nothing` if something goes
 * wrong.
 */
template <cc::numeric T, usize BufferSize = 24>
[[nodiscard]] auto to_string(const T number) -> std::optional<std::string>
{
  if constexpr (on_gcc() || (on_clang() && std::floating_point<T>))
  {
    return std::to_string(number);
  }
  else
  {
    std::array<char, BufferSize> buffer{};
    const auto [ptr, error] =
        std::to_chars(buffer.data(), buffer.data() + buffer.size(), number);
    if (error == std::errc{})
    {
      return std::string{buffer.data(), ptr};
    }
    else
    {
      return nothing;
    }
  }
}

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_TO_STRING_HPP
