#pragma once

#include <type_traits>  // is_arithmetic_v, is_same_v

namespace rune {

/// \addtogroup core
/// \{

/// Concept for a type that is either integral or floating-point, but not `bool`.
template <typename T>
concept numeric = std::is_arithmetic_v<T> && !std::is_same_v<T, bool>;

/// \} End of group core

}  // namespace rune
