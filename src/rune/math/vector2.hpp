#pragma once

#include <cmath>     // lerp, sqrt
#include <concepts>  // floating_point
#include <ostream>   // ostream
#include <string>    // string

#include "../core/to_string.hpp"
#include "almost_equal.hpp"

namespace rune {

template <std::floating_point T>
class basic_vector2 final
{
 public:
  using value_type = T;
  using vector_type = basic_vector2;

  value_type x{};  ///< The x-coordinate.
  value_type y{};  ///< The y-coordinate.

  /// \name Construction
  /// \{

  /// Creates a zero vector.
  constexpr basic_vector2() noexcept = default;

  /**
   * \brief Creates a vector with the specified components.
   *
   * \param x the x-coordinate of the vector.
   * \param y the y-coordinate of the vector.
   */
  constexpr basic_vector2(const value_type x, const value_type y) noexcept : x{x}, y{y}
  {}

  /// \} End of construction

  /// \name Mutators
  /// \{

  /// Turns the vector into the zero vector.
  constexpr void reset() noexcept
  {
    x = 0;
    y = 0;
  }

  /**
   * \brief Negates the coordinates of the vector.
   *
   * \details Negating a vector with components (20, 30) results in (-20, -30).
   */
  constexpr void negate() noexcept
  {
    x = -x;
    y = -y;
  }

  /**
   * \brief Normalizes the vector, i.e. the vector will be made a unit vector.
   *
   * \note If the vector is the zero vector, then this function has no effect.
   */
  constexpr void normalize()
  {
    const auto currentMagnitude = magnitude();
    if (currentMagnitude != 0) [[likely]]
    {
      x /= currentMagnitude;
      y /= currentMagnitude;
    }
  }

  /**
   * \brief Scales the coordinates of the vector by the specified factor.
   *
   * \param factor the scale factor, may be negative.
   */
  constexpr void scale(const value_type factor) noexcept
  {
    x *= factor;
    y *= factor;
  }

  /**
   * \brief Linearly interpolates the vector with the supplied target vector.
   *
   * \param target the target vector of the interpolation.
   * \param alpha the interpolation alpha, in the interval [0, 1].
   */
  constexpr void lerp(const vector_type target, const value_type alpha) noexcept
  {
    x = std::lerp(x, target.x, alpha);
    y = std::lerp(y, target.y, alpha);
  }

  /**
   * \brief Makes the vector "look" at the supplied point.
   *
   * \note A negative length value will turn the vector into the zero vector.
   *
   * \param target the point that the vector will look at.
   * \param length the length of the vector after the operation.
   *
   * \since 0.1.0
   */
  constexpr void look_at(const vector_type target, const value_type length)
  {
    if (length >= 0) [[likely]]
    {
      x = target.x - x;
      y = target.y - y;
      normalize();
      scale(length);
    }
    else
    {
      reset();
    }
  }

  /**
   * \brief Makes the vector "look" at the supplied point.
   *
   * \note The vector will maintain its current magnitude.
   *
   * \param target the point that the vector will look at.
   */
  constexpr void look_at(const vector_type target)
  {
    look_at(target, magnitude());
  }

  /// \} End of mutators

  /// \name Queries
  /// \{

  /// Returns the magnitude, i.e. length, of the vector.
  [[nodiscard]] auto magnitude() const -> value_type
  {
    return std::sqrt((x * x) + (y * y));
  }

  /// Returns the squared magnitude of the vector.
  [[nodiscard]] constexpr auto magnitude2() const noexcept -> value_type
  {
    return (x * x) + (y * y);
  }

  /// Indicates whether or not the vector is a unit vector.
  [[nodiscard]] auto is_unit() const -> bool
  {
    return almost_equal(magnitude(), value_type{1});
  }

  /// Indicates whether or not the vector is the zero vector.
  [[nodiscard]] auto is_zero() const -> bool
  {
    return almost_equal(x, value_type{0}) && almost_equal(y, value_type{0});
  }

  /// \} End of queries

  /// \name Serialization
  /// \{

  /// Serializes the vector.
  void serialize(auto& archive)
  {
    archive(x, y);
  }

  /// \} End of serialization

  /// \name Comparisons
  /// \{

  /// Indicates whether or not two vectors are exactly equal.
  [[nodiscard]] constexpr bool operator==(const vector_type&) const noexcept = default;

  /// \} End of comparisons
};

/// A two-dimensional vector using `float` precision.
using float2 = basic_vector2<float>;

/// A two-dimensional vector using `double` precision.
using double2 = basic_vector2<double>;

/// Indicates whether or not two vectors are almost equal.
template <std::floating_point T>
[[nodiscard]] auto almost_equal(const basic_vector2<T>& a,
                                const basic_vector2<T>& b,
                                const T epsilon = default_epsilon) -> bool
{
  return almost_equal(a.x, b.x, epsilon) && almost_equal(a.y, b.y, epsilon);
}

/// \name Vector operators
/// \{

template <std::floating_point T>
constexpr void operator+=(basic_vector2<T>& a, const basic_vector2<T>& b) noexcept
{
  a.x += b.x;
  a.y += b.y;
}

template <std::floating_point T>
constexpr void operator-=(basic_vector2<T>& a, const basic_vector2<T>& b) noexcept
{
  a.x -= b.x;
  a.y -= b.y;
}

template <std::floating_point T>
constexpr void operator*=(basic_vector2<T>& vector, const T factor) noexcept
{
  vector.scale(factor);
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator+(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x + rhs.x, lhs.y + rhs.y};
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator-(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x - rhs.x, lhs.y - rhs.y};
}

/// \} End of vector operators

template <std::floating_point T>
[[nodiscard]] auto to_string(const basic_vector2<T> vec) -> std::string
{
  return "vector2{x: " + to_string(vec.x).value() + ", y: " + to_string(vec.y).value() +
         "}";
}

template <std::floating_point T>
auto operator<<(std::ostream& stream, const basic_vector2<T> vec) -> std::ostream&
{
  return stream << to_string(vec);
}

}  // namespace rune
