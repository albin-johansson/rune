#ifndef RUNE_CORE_CONCEPTS_HPP
#define RUNE_CORE_CONCEPTS_HPP

#include <type_traits>  // is_arithmetic_v, is_same_v, is_default_constructible_v

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

/// Concept for a type that is either integral or floating-point, but not `bool`.
template <typename T>
concept numeric = std::is_arithmetic_v<T> && !std::is_same_v<T, bool>;

template <typename T>
concept has_value_type = requires
{
  typename T::value_type;
};

template <typename T>
concept default_constructible = std::is_default_constructible_v<T>;

// clang-format on

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_CONCEPTS_HPP