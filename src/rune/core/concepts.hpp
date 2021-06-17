#ifndef RUNE_CORE_CONCEPTS_HPP
#define RUNE_CORE_CONCEPTS_HPP

#include <concepts>     // convertible_to, same_as
#include <type_traits>  // is_arithmetic_v, is_default_constructible_v, is_enum_v

namespace rune::cc {

/// \addtogroup core
/// \{

// clang-format off

/// Concept for a type that is either integral or floating-point, but not `bool`.
template <typename T>
concept numeric = std::is_arithmetic_v<T> && !std::same_as<T, bool>;

template <typename T>
concept enum_type = std::is_enum_v<T>;

template <typename T>
concept default_constructible = std::is_default_constructible_v<T>;

template <typename T>
concept has_value_type = requires
{
  typename T::value_type;
};

template <typename T>
concept has_less_than = requires (T value)
{
  { value < value } -> std::convertible_to<bool>;
};

// clang-format on

/// \} End of group core

}  // namespace rune::cc

#endif  // RUNE_CORE_CONCEPTS_HPP