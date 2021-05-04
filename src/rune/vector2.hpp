#pragma once

#include <cmath>  // sqrt

namespace rune {

template <typename T>
class basic_vector2;

using float2 = basic_vector2<float>;
using double2 = basic_vector2<double>;

template <typename T>
class basic_vector2 final
{
 public:
  using value_type = T;
  using vector_type = basic_vector2;

  value_type x{};  ///< The x-coordinate.
  value_type y{};  ///< The y-coordinate.

  constexpr basic_vector2() noexcept = default;

  constexpr basic_vector2(const value_type x, const value_type y) noexcept : x{x}, y{y}
  {}

  constexpr void normalize() noexcept
  {
    const auto currentMagnitude = magnitude();
    if (currentMagnitude != 0)
    {
      x /= currentMagnitude;
      y /= currentMagnitude;
    }
  }

  constexpr void reset() noexcept
  {
    x = 0;
    y = 0;
  }

  constexpr void scale(const value_type factor) noexcept
  {
    x *= factor;
    y *= factor;
  }

  constexpr void negate() noexcept
  {
    x = -x;
    y = -y;
  }

  constexpr void lerp(const vector_type& target, const value_type alpha) noexcept
  {
    const auto invAlpha = value_type{1} - alpha;
    x = (x * invAlpha) + (target.x * alpha);
    y = (y * invAlpha) + (target.y * alpha);
  }

  constexpr void point_at(const vector_type& target) noexcept
  {}

  constexpr void point_at(const vector_type& target, const value_type length) noexcept
  {}

  [[nodiscard]] auto magnitude() const -> value_type
  {
    return std::sqrt((x * x) + (y * y));
  }

  [[nodiscard]] auto magnitude2() const noexcept -> value_type
  {
    return (x * x) + (y * y);
  }

  [[nodiscard]] auto is_unit() const noexcept -> bool
  {
    return false;
  }
};

template <typename T>
[[nodiscard]] constexpr auto operator+(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T>
[[nodiscard]] constexpr auto operator-(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x - rhs.x, lhs.y - rhs.y};
}

}  // namespace rune
