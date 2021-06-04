#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP
