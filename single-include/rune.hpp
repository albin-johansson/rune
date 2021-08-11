/*
 * MIT License
 * Copyright (c) 2021 Albin Johansson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef RUNE_EVERYTHING_HPP
#define RUNE_EVERYTHING_HPP

// clang-format off
// #include "rune_api.hpp"
#ifndef RUNE_API_HPP
#define RUNE_API_HPP

#include <centurion.hpp>

#if CENTURION_VERSION_NUMBER != CENTURION_MAKE_VERSION_NUMBER(6, 2, 0)
#error "Incompatible Centurion version!"
#endif  // CENTURION_VERSION_NUMBER != CENTURION_MAKE_VERSION_NUMBER(6, 2, 0)

#ifdef _WIN32
#ifdef RUNE_EXPORT
#define RUNE_API __declspec(dllexport)
#else
#define RUNE_API __declspec(dllimport)
#endif  // RUNE_EXPORT
#endif  // _WIN32

#define RUNE_FUNCTION [[nodiscard]] RUNE_API

#endif  // RUNE_API_HPP

// clang-format on

// #include "aliases/delta_time.hpp"
#ifndef RUNE_ALIASES_DELTA_TIME_HPP
#define RUNE_ALIASES_DELTA_TIME_HPP

namespace rune {

/// \cond FALSE
namespace tags {
struct delta_time_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \def RUNE_DELTA_TIME_UNDERLYING_TYPE
 *
 * \brief The underlying type of the `delta_time` strong type.
 *
 * \note The underlying should be a floating-point type, i.e. `float`, `double` or
 * possibly `long double`.
 */
#ifndef RUNE_DELTA_TIME_UNDERLYING_TYPE
#define RUNE_DELTA_TIME_UNDERLYING_TYPE float
#endif  // RUNE_DELTA_TIME_UNDERLYING_TYPE

/**
 * \brief The type used for delta time values, e.g. in the `tick()` function of game class
 * implementations.
 *
 * \see `RUNE_DELTA_TIME_UNDERLYING_TYPE`
 */
using delta_time = RUNE_DELTA_TIME_UNDERLYING_TYPE;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_DELTA_TIME_HPP

// #include "aliases/font_id.hpp"
#ifndef RUNE_ALIASES_FONT_ID_HPP
#define RUNE_ALIASES_FONT_ID_HPP

// #include "integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP


namespace rune {

using font_id = usize;

}  // namespace rune

#endif  // RUNE_ALIASES_FONT_ID_HPP

// #include "aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "aliases/json_type.hpp"
#ifndef RUNE_ALIASES_JSON_TYPE_HPP
#define RUNE_ALIASES_JSON_TYPE_HPP

#include <json.hpp>  // json

namespace rune {

using json_type = nlohmann::json;

}  // namespace rune

#endif  // RUNE_ALIASES_JSON_TYPE_HPP

// #include "aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune

// #include "aliases/texture_id.hpp"
#ifndef RUNE_ALIASES_TEXTURE_ID_HPP
#define RUNE_ALIASES_TEXTURE_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct texture_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \def RUNE_TEXTURE_ID_UNDERLYING_TYPE
 *
 * \brief The underlying type of the `texture_id` strong type.
 *
 * \details By default, the underlying type is `usize`.
 *
 * \note The value of this macro must be of a hashable type.
 */
#ifndef RUNE_TEXTURE_ID_UNDERLYING_TYPE
#define RUNE_TEXTURE_ID_UNDERLYING_TYPE usize
#endif  // RUNE_TEXTURE_ID_UNDERLYING_TYPE

/**
 * \typedef texture_id
 *
 * \brief Used as unique identifiers for textures.
 *
 * \details This is used in order to avoid loading the same texture more than once.
 *
 * \see `RUNE_TEXTURE_ID_UNDERLYING_TYPE`
 */
using texture_id =
    nenya::strong_type<RUNE_TEXTURE_ID_UNDERLYING_TYPE, tags::texture_id_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_ID_HPP

// #include "aliases/texture_index.hpp"
#ifndef RUNE_ALIASES_TEXTURE_INDEX_HPP
#define RUNE_ALIASES_TEXTURE_INDEX_HPP

#include <nenya.hpp>  // strong_type

// #include "integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct texture_index_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \typedef texture_index
 *
 * \brief Strong type for texture indices, used by the `graphics` class.
 */
using texture_index = nenya::strong_type<usize, tags::texture_index_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_INDEX_HPP

// #include "containers/aabb.hpp"
#ifndef RUNE_CONTAINERS_AABB_HPP
#define RUNE_CONTAINERS_AABB_HPP

#include <cassert>   // assert
#include <concepts>  // floating_point

// #include "../math/max.hpp"
#ifndef RUNE_MATH_MAX_HPP
#define RUNE_MATH_MAX_HPP

#include <concepts>

namespace rune {

/**
 * \brief Returns the largest of two values.
 *
 * \note This function exists because `std::max()` isn't marked as `noexcept`.
 *
 * \note This function uses `operator<`, and not `operator>`.
 *
 * \ingroup math
 *
 * \tparam T the type of the values.
 *
 * \param a the first value.
 * \param b the second value.
 *
 * \return the largest of the two values.
 */
template <typename T>
[[nodiscard]] constexpr auto max(const T& a, const T& b) noexcept(noexcept(a < b)) -> T
{
  return (a < b) ? b : a;
}

}  // namespace rune

#endif  // RUNE_MATH_MAX_HPP

// #include "../math/min.hpp"
#ifndef RUNE_MATH_MIN_HPP
#define RUNE_MATH_MIN_HPP

namespace rune {

/**
 * \brief Returns the smallest of two values.
 *
 * \note This function exists because `std::min()` isn't marked as `noexcept`.
 *
 * \ingroup math
 *
 * \tparam T the type of the values.
 *
 * \param a the first value.
 * \param b the second value.
 *
 * \return the smallest of the two values.
 */
template <typename T>
[[nodiscard]] constexpr auto min(const T& a, const T& b) noexcept(noexcept(a < b)) -> T
{
  return (a < b) ? a : b;
}

}  // namespace rune

#endif  // RUNE_MATH_MIN_HPP

// #include "../math/vector2.hpp"
#ifndef RUNE_MATH_VECTOR2_HPP
#define RUNE_MATH_VECTOR2_HPP

#include <cmath>     // lerp, sqrt
#include <concepts>  // floating_point
#include <ostream>   // ostream
#include <string>    // string, to_string

// #include "almost_equal.hpp"
#ifndef RUNE_MATH_ALMOST_EQUAL_HPP
#define RUNE_MATH_ALMOST_EQUAL_HPP

#include <cmath>     // abs
#include <concepts>  // floating_point

namespace rune {

/// \addtogroup math
/// \{

// clang-format off

/// The default epsilon value used for floating point comparisons.
inline constexpr float default_epsilon = 0.00001f;

/**
 * \brief Indicates whether or not two floating-point values are almost equal.
 *
 * \details The two values are considered equal if the absolute value of their difference
 * is in the range [0, `epsilon`).
 *
 * \param a the first value.
 * \param b the second value.
 * \param epsilon the epsilon value.
 *
 * \return `true` if the values are almost equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] auto almost_equal(const T a,
                                const T b,
                                const T epsilon = default_epsilon) noexcept(noexcept(std::abs(a)))
    -> bool
{
  return std::abs(a - b) < epsilon;
}

// clang-format on

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_ALMOST_EQUAL_HPP


namespace rune {

/// \addtogroup math
/// \{

/**
 * \class basic_vector2
 *
 * \brief A two-dimensional vector with floating point coordinates.
 *
 * \tparam T the representation type, must a floating-point type.
 *
 * \see `float2`
 * \see `double2`
 * \see `almost_equal(const basic_vector2<T>&, const basic_vector2<T>&, T)`
 * \see `distance(const basic_vector2<T>&, const basic_vector2<T>&)`
 * \see `angle(const basic_vector2<T>&, const basic_vector2<T>&)`
 * \see `cross(const basic_vector2<T>&, const basic_vector2<T>&)`
 * \see `dot(const basic_vector2<T>&, const basic_vector2<T>&)`
 */
template <std::floating_point T>
class basic_vector2 final
{
 public:
  using value_type = T;               ///< The type of the coordinates.
  using vector_type = basic_vector2;  ///< The type of the vector itself.

  value_type x{};  ///< The x-coordinate.
  value_type y{};  ///< The y-coordinate.

  /// \name Construction
  /// \{

  /**
   * \brief Creates a zero vector.
   */
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

  /**
   * \brief Turns the vector into a zero vector.
   */
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

  /**
   * \brief Sets the magnitude of the vector.
   *
   * \note If the supplied magnitude is negative, the vector becomes the zero vector.
   *
   * \param length the new magnitude of the vector.
   */
  void set_magnitude(const T length)
  {
    if (length > 0) [[likely]]
    {
      const auto previous = magnitude();
      if (previous != 0 && previous != length)
      {
        scale(length / previous);
      }
    }
    else
    {
      reset();
    }
  }

  /// \} End of mutators

  /// \name Queries
  /// \{

  /// Returns the magnitude, i.e. length, of the vector.

  /**
   * \brief Returns the magnitude (length) of the vector.
   *
   * \return the magnitude of the vector.
   */
  [[nodiscard]] auto magnitude() const -> value_type
  {
    return std::sqrt((x * x) + (y * y));
  }

  /**
   * \brief Returns the squared magnitude of this vector.
   *
   * \details This function can be useful when comparing vectors. It avoids a relatively
   * expensive square root computation.
   *
   * \return the squared magnitude of this vector.
   */
  [[nodiscard]] constexpr auto magnitude2() const noexcept -> value_type
  {
    return (x * x) + (y * y);
  }

  /**
   * \brief Indicates whether or not the vector is a unit vector.
   *
   * \details A unit vector is a vector with length `1`.
   *
   * \return `true` if the vector is a unit vector; `false` otherwise.
   */
  [[nodiscard]] auto is_unit() const -> bool
  {
    return almost_equal(magnitude(), value_type{1});
  }

  /**
   * \brief Indicates whether or not the vector is a zero vector.
   *
   * \details A vector is a zero vector if both of its coordinates are zero.
   *
   * \return `true` if the vector is a zero vector; `false` otherwise.
   */
  [[nodiscard]] auto is_zero() const -> bool
  {
    return almost_equal(x, value_type{0}) && almost_equal(y, value_type{0});
  }

  /// \} End of queries

  /// \name Serialization
  /// \{

  /**
   * \brief Serializes the vector.
   *
   * \param archive the serialization archive that will be used.
   */
  void serialize(auto& archive)
  {
    archive(x, y);
  }

  /// \} End of serialization

  /// \name Comparisons
  /// \{

  /**
   * \brief Indicates whether or not two vectors are *exactly* equal.
   *
   * \return `true` if the vectors are exactly equal; `false` otherwise.
   *
   * \see `almost_equal(const basic_vector2<T>&, const basic_vector2<T>&, T)`
   */
  [[nodiscard]] constexpr bool operator==(const vector_type&) const noexcept = default;

  /// \} End of comparisons
};

/// A two-dimensional vector using `float` precision.
using float2 = basic_vector2<float>;

/// A two-dimensional vector using `double` precision.
using double2 = basic_vector2<double>;

/// \name Vector operators
/// \{

template <std::floating_point T>
constexpr void operator+=(basic_vector2<T>& a, const basic_vector2<T>& b) noexcept
{
  a.x += b.x;
  a.y += b.y;
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator+(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x + rhs.x, lhs.y + rhs.y};
}

template <std::floating_point T>
constexpr void operator-=(basic_vector2<T>& a, const basic_vector2<T>& b) noexcept
{
  a.x -= b.x;
  a.y -= b.y;
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator-(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x - rhs.x, lhs.y - rhs.y};
}

/**
 * \brief Returns the dot product of two vectors.
 *
 * \note The dot product is commutative, which means that the order of
 * the operands doesn't matter.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the dot product of the two vectors.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto operator*(const basic_vector2<T>& a,
                                       const basic_vector2<T>& b) noexcept -> T
{
  return (a.x * b.x) + (a.y * b.y);
}

template <std::floating_point T, typename U>
constexpr void operator*=(basic_vector2<T>& vector, const U factor) noexcept
{
  vector.scale(factor);
}

template <std::floating_point T, typename U>
[[nodiscard]] constexpr auto operator*(const basic_vector2<T>& vector,
                                       const U factor) noexcept -> basic_vector2<T>
{
  return basic_vector2{vector.x * factor, vector.y * factor};
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator*(const T factor,
                                       const basic_vector2<T>& vector) noexcept
    -> basic_vector2<T>
{
  return vector * factor;
}

/// \} End of vector operators

/// \name Vector functions
/// \{

/**
 * \brief Indicates whether or not two vectors are *almost* equal.
 *
 * \param a the first vector.
 * \param b the second vector.
 * \param epsilon the epsilon value that will be used.
 *
 * \return `true` if the vectors are almost equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] auto almost_equal(const basic_vector2<T>& a,
                                const basic_vector2<T>& b,
                                const T epsilon = default_epsilon) -> bool
{
  return almost_equal(a.x, b.x, epsilon) && almost_equal(a.y, b.y, epsilon);
}

/**
 * \brief Returns the distance between two vectors.
 *
 * \details The vectors are treated as points in the plane by this function.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the distance between the two points.
 */
template <std::floating_point T>
[[nodiscard]] auto distance(const basic_vector2<T>& a, const basic_vector2<T>& b) -> T
{
  const auto dx = b.x - a.x;
  const auto dy = b.y - a.y;
  return std::sqrt(dx * dx + dy * dy);
}

/**
 * \brief Returns the cross product between two vectors.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the cross product of the vectors.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto cross(const basic_vector2<T>& a,
                                   const basic_vector2<T>& b) noexcept -> T
{
  return a.x * b.y - a.y * b.x;
}

/// \copydoc operator*(const basic_vector2<T>&, const basic_vector2<T>&)
template <std::floating_point T>
[[nodiscard]] constexpr auto dot(const basic_vector2<T>& a,
                                 const basic_vector2<T>& b) noexcept -> T
{
  return a * b;
}

/**
 * \brief Returns the angle between two vectors.
 *
 * \note This function returns zero if any of the supplied vectors are zero vectors.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the angle between the two vectors.
 */
template <std::floating_point T>
[[nodiscard]] auto angle(const basic_vector2<T>& a, const basic_vector2<T>& b) -> T
{
  if (a.is_zero() || b.is_zero() || a == b)
  {
    return 0;
  }

  const auto mag1 = a.magnitude();
  const auto mag2 = b.magnitude();

  const auto cos = (a * b) / mag1 / mag2;
  const auto sin = cross(a, b) / mag1 / mag2;

  if (const auto angle = std::acos(cos); sin < 0)
  {
    return -angle;
  }
  else
  {
    return angle;
  }
}

/// \} End of vector functions

template <std::floating_point T>
[[nodiscard]] auto to_string(const basic_vector2<T> vec) -> std::string
{
  return "vector2{x: " + std::to_string(vec.x) + ", y: " + std::to_string(vec.y) + "}";
}

template <std::floating_point T>
auto operator<<(std::ostream& stream, const basic_vector2<T> vec) -> std::ostream&
{
  return stream << to_string(vec);
}

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_VECTOR2_HPP


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \struct basic_aabb
 *
 * \brief Represents an axis-aligned bounding box (AABB).
 *
 * \details An AABB is really just a fancy rectangle, used to provide a rough
 * approximation of the shape of game objects in order to speed up collision detection in
 * combination with AABB trees.
 *
 * \see `aabb_tree`
 * \see `make_aabb()`
 */
template <std::floating_point T>
struct basic_aabb final
{
  using precision_type = T;  ///< The type used as coordinates in the vectors, etc.
  using vector_type = basic_vector2<precision_type>;  ///< The associated vector type.

  vector_type min;  ///< The lower bound point, i.e. the upper left corner of the AABB.
  vector_type max;  ///< The upper bound point, i.e. the lower right corner of the AABB.
  precision_type area{};  ///< The area heuristic of the AABB.

  /**
   * \brief Indicates whether or not the AABB contains another AABB.
   *
   * \details The supplied AABB is still considered to be contained within the
   * invoked AABB if the borders of the "inner" AABB are overlapping the borders
   * of the "outer" AABB.
   *
   * \param other the AABB that will be checked.
   *
   * \return `true` if the AABB contains the supplied AABB; `false` otherwise.
   */
  [[nodiscard]] constexpr auto contains(const basic_aabb& other) const noexcept -> bool
  {
    return (other.min.x >= min.x) && (other.min.y >= min.y) && (other.max.x <= max.x) &&
           (other.max.y <= max.y);
  }

  /**
   * \brief Returns the size (width and height) of the AABB, represented as a vector.
   *
   * \return the size of the AABB.
   */
  [[nodiscard]] constexpr auto size() const noexcept -> vector_type
  {
    return max - min;
  }
};

/**
 * \brief Serializes an AABB.
 *
 * \param archive the serialization archive that will be used.
 *
 * \param aabb the AABB that will be serialized.
 */
template <std::floating_point T>
void serialize(auto& archive, basic_aabb<T>& aabb)
{
  archive(aabb.min, aabb.max, aabb.area);
}

/// \name AABB operators
/// \{

/**
 * \brief Indicates whether or not two AABBs are equal.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 *
 * \return `true` if the AABBs are *exactly* equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto operator==(const basic_aabb<T>& a,
                                        const basic_aabb<T>& b) noexcept -> bool
{
  return a.min == b.min && a.max == b.max;
}

/**
 * \brief Indicates whether or not two AABBs aren't equal.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 *
 * \return `true` if the AABBs aren't equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto operator!=(const basic_aabb<T>& a,
                                        const basic_aabb<T>& b) noexcept -> bool
{
  return !(a == b);
}

/// \} End of AABB operators

/// \name AABB functions
/// \{

/**
 * \brief Computes the area heuristic of an AABB.
 *
 * \param aabb the AABB for which the area heuristic will be calculated.
 *
 * \return the area heuristic of the AABB.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto compute_area(const basic_aabb<T>& aabb) noexcept -> T
{
  T sum{0};

  for (auto a = 0; a < 2; ++a)
  {
    T product{1};

    for (auto b = 0; b < 2; ++b)
    {
      if (a == b)
      {
        continue;
      }

      if (b == 0)
      {
        product *= (aabb.max.x - aabb.min.x);
      }
      else if (b == 1)
      {
        product *= (aabb.max.y - aabb.min.y);
      }
    }

    sum += product;
  }

  return T{2} * sum;
}

/**
 * \brief Creates an AABB.
 *
 * \pre `lower` must have coordinates smaller than those of `upper`.
 *
 * \details Use of this function is the recommended way to create AABBs, since this
 * function will compute the area heuristic for you.
 *
 * \param lower the lower bound point, i.e. the upper left corner of the AABB.
 * \param upper the upper bound point, i.e. the lower right corner of the AABB.
 *
 * \return the created AABB.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto make_aabb(const basic_vector2<T>& lower,
                                       const basic_vector2<T>& upper) noexcept
    -> basic_aabb<T>
{
  assert(lower.x < upper.x);
  assert(lower.y < upper.y);

  basic_aabb<T> aabb;

  aabb.min = lower;
  aabb.max = upper;
  aabb.area = compute_area(aabb);

  return aabb;
}

/**
 * \brief Returns the union of two AABBs.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 *
 * \return an AABB that corresponds to the union of the two AABBs.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto merge(const basic_aabb<T>& a,
                                   const basic_aabb<T>& b) noexcept -> basic_aabb<T>
{
  basic_vector2<T> lower;
  basic_vector2<T> upper;

  lower.x = min(a.min.x, b.min.x);
  lower.y = min(a.min.y, b.min.y);

  upper.x = max(a.max.x, b.max.x);
  upper.y = max(a.max.y, b.max.y);

  return make_aabb(lower, upper);
}

/**
 * \brief Indicates whether or not two AABBs are overlapping each other.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 * \param touchIsOverlap `true` if two "touching" AABBs should be considered to overlap;
 * `false` otherwise.
 *
 * \return `true` if the AABBs overlap; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto overlaps(const basic_aabb<T>& a,
                                      const basic_aabb<T>& b,
                                      const bool touchIsOverlap) noexcept -> bool
{
  if (touchIsOverlap)
  {
    return !(b.max.x < a.min.x || b.min.x > a.max.x || b.max.y < a.min.y ||
             b.min.y > a.max.y);
  }
  else
  {
    return !(b.max.x <= a.min.x || b.min.x >= a.max.x || b.max.y <= a.min.y ||
             b.min.y >= a.max.y);
  }
}

/**
 * \brief Fattens an AABB by the specified factor.
 *
 * \details The supplied AABB will be enlarged by having *each* coordinate (i.e. X- and
 * Y-coordinates of both lower and upper bounds) widened by the specified percentage, e.g.
 * an AABB with width 100 that is fattened with `percentage` specified as `0.05`, will end
 * up with having width 110.
 *
 * \param aabb the AABB that will be fattened.
 * \param percentage the percentage of the current size that each coordinate will be
 * enlarged by.
 */
template <std::floating_point T>
void fatten(basic_aabb<T>& aabb, const T percentage) noexcept
{
  const auto size = aabb.size();
  const auto dx = percentage * size.x;
  const auto dy = percentage * size.y;

  aabb.min.x -= dx;
  aabb.min.y -= dy;

  aabb.max.x += dx;
  aabb.max.y += dy;

  aabb.area = compute_area(aabb);
}

/// \} End of AABB functions

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_HPP

// #include "containers/aabb_node.hpp"
#ifndef RUNE_CONTAINERS_AABB_NODE_HPP
#define RUNE_CONTAINERS_AABB_NODE_HPP

#include <concepts>  // floating_point

// #include "../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "aabb.hpp"
#ifndef RUNE_CONTAINERS_AABB_HPP
#define RUNE_CONTAINERS_AABB_HPP

#include <cassert>   // assert
#include <concepts>  // floating_point

// #include "../math/max.hpp"

// #include "../math/min.hpp"

// #include "../math/vector2.hpp"


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \struct basic_aabb
 *
 * \brief Represents an axis-aligned bounding box (AABB).
 *
 * \details An AABB is really just a fancy rectangle, used to provide a rough
 * approximation of the shape of game objects in order to speed up collision detection in
 * combination with AABB trees.
 *
 * \see `aabb_tree`
 * \see `make_aabb()`
 */
template <std::floating_point T>
struct basic_aabb final
{
  using precision_type = T;  ///< The type used as coordinates in the vectors, etc.
  using vector_type = basic_vector2<precision_type>;  ///< The associated vector type.

  vector_type min;  ///< The lower bound point, i.e. the upper left corner of the AABB.
  vector_type max;  ///< The upper bound point, i.e. the lower right corner of the AABB.
  precision_type area{};  ///< The area heuristic of the AABB.

  /**
   * \brief Indicates whether or not the AABB contains another AABB.
   *
   * \details The supplied AABB is still considered to be contained within the
   * invoked AABB if the borders of the "inner" AABB are overlapping the borders
   * of the "outer" AABB.
   *
   * \param other the AABB that will be checked.
   *
   * \return `true` if the AABB contains the supplied AABB; `false` otherwise.
   */
  [[nodiscard]] constexpr auto contains(const basic_aabb& other) const noexcept -> bool
  {
    return (other.min.x >= min.x) && (other.min.y >= min.y) && (other.max.x <= max.x) &&
           (other.max.y <= max.y);
  }

  /**
   * \brief Returns the size (width and height) of the AABB, represented as a vector.
   *
   * \return the size of the AABB.
   */
  [[nodiscard]] constexpr auto size() const noexcept -> vector_type
  {
    return max - min;
  }
};

/**
 * \brief Serializes an AABB.
 *
 * \param archive the serialization archive that will be used.
 *
 * \param aabb the AABB that will be serialized.
 */
template <std::floating_point T>
void serialize(auto& archive, basic_aabb<T>& aabb)
{
  archive(aabb.min, aabb.max, aabb.area);
}

/// \name AABB operators
/// \{

/**
 * \brief Indicates whether or not two AABBs are equal.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 *
 * \return `true` if the AABBs are *exactly* equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto operator==(const basic_aabb<T>& a,
                                        const basic_aabb<T>& b) noexcept -> bool
{
  return a.min == b.min && a.max == b.max;
}

/**
 * \brief Indicates whether or not two AABBs aren't equal.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 *
 * \return `true` if the AABBs aren't equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto operator!=(const basic_aabb<T>& a,
                                        const basic_aabb<T>& b) noexcept -> bool
{
  return !(a == b);
}

/// \} End of AABB operators

/// \name AABB functions
/// \{

/**
 * \brief Computes the area heuristic of an AABB.
 *
 * \param aabb the AABB for which the area heuristic will be calculated.
 *
 * \return the area heuristic of the AABB.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto compute_area(const basic_aabb<T>& aabb) noexcept -> T
{
  T sum{0};

  for (auto a = 0; a < 2; ++a)
  {
    T product{1};

    for (auto b = 0; b < 2; ++b)
    {
      if (a == b)
      {
        continue;
      }

      if (b == 0)
      {
        product *= (aabb.max.x - aabb.min.x);
      }
      else if (b == 1)
      {
        product *= (aabb.max.y - aabb.min.y);
      }
    }

    sum += product;
  }

  return T{2} * sum;
}

/**
 * \brief Creates an AABB.
 *
 * \pre `lower` must have coordinates smaller than those of `upper`.
 *
 * \details Use of this function is the recommended way to create AABBs, since this
 * function will compute the area heuristic for you.
 *
 * \param lower the lower bound point, i.e. the upper left corner of the AABB.
 * \param upper the upper bound point, i.e. the lower right corner of the AABB.
 *
 * \return the created AABB.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto make_aabb(const basic_vector2<T>& lower,
                                       const basic_vector2<T>& upper) noexcept
    -> basic_aabb<T>
{
  assert(lower.x < upper.x);
  assert(lower.y < upper.y);

  basic_aabb<T> aabb;

  aabb.min = lower;
  aabb.max = upper;
  aabb.area = compute_area(aabb);

  return aabb;
}

/**
 * \brief Returns the union of two AABBs.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 *
 * \return an AABB that corresponds to the union of the two AABBs.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto merge(const basic_aabb<T>& a,
                                   const basic_aabb<T>& b) noexcept -> basic_aabb<T>
{
  basic_vector2<T> lower;
  basic_vector2<T> upper;

  lower.x = min(a.min.x, b.min.x);
  lower.y = min(a.min.y, b.min.y);

  upper.x = max(a.max.x, b.max.x);
  upper.y = max(a.max.y, b.max.y);

  return make_aabb(lower, upper);
}

/**
 * \brief Indicates whether or not two AABBs are overlapping each other.
 *
 * \param a the first AABB.
 * \param b the second AABB.
 * \param touchIsOverlap `true` if two "touching" AABBs should be considered to overlap;
 * `false` otherwise.
 *
 * \return `true` if the AABBs overlap; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto overlaps(const basic_aabb<T>& a,
                                      const basic_aabb<T>& b,
                                      const bool touchIsOverlap) noexcept -> bool
{
  if (touchIsOverlap)
  {
    return !(b.max.x < a.min.x || b.min.x > a.max.x || b.max.y < a.min.y ||
             b.min.y > a.max.y);
  }
  else
  {
    return !(b.max.x <= a.min.x || b.min.x >= a.max.x || b.max.y <= a.min.y ||
             b.min.y >= a.max.y);
  }
}

/**
 * \brief Fattens an AABB by the specified factor.
 *
 * \details The supplied AABB will be enlarged by having *each* coordinate (i.e. X- and
 * Y-coordinates of both lower and upper bounds) widened by the specified percentage, e.g.
 * an AABB with width 100 that is fattened with `percentage` specified as `0.05`, will end
 * up with having width 110.
 *
 * \param aabb the AABB that will be fattened.
 * \param percentage the percentage of the current size that each coordinate will be
 * enlarged by.
 */
template <std::floating_point T>
void fatten(basic_aabb<T>& aabb, const T percentage) noexcept
{
  const auto size = aabb.size();
  const auto dx = percentage * size.x;
  const auto dy = percentage * size.y;

  aabb.min.x -= dx;
  aabb.min.y -= dy;

  aabb.max.x += dx;
  aabb.max.y += dy;

  aabb.area = compute_area(aabb);
}

/// \} End of AABB functions

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_HPP


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \class aabb_node
 *
 * \brief Represents a node in an AABB tree.
 *
 * \tparam Key the type of the associated key.
 *
 * \see `aabb_tree`
 * \see `is_leaf()`
 */
template <typename Key, std::floating_point Precision>
class aabb_node final
{
 public:
  using key_type = Key;                               ///< The type of the associated key.
  using precision_type = Precision;                   ///< The vector coordinate type.
  using vector_type = basic_vector2<precision_type>;  ///< The associated vector type.
  using aabb_type = basic_aabb<precision_type>;       ///< The associated AABB type.
  using index_type = usize;                           ///< The type used for node indices

  maybe<key_type> id;        ///< The user-provided ID associated with the AABB.
  aabb_type box;             ///< The associated AABB.
  maybe<index_type> parent;  ///< Index of parent node.
  maybe<index_type> left;    ///< Index of left child.
  maybe<index_type> right;   ///< Index of right child.
  maybe<index_type> next;    ///< Index of next adjacent node.
  int height{-1};            ///< Amount of levels below the node (0 for leaves).
};

/**
 * \brief Serializes an AABB node.
 *
 * \param archive the serialization archive that will be used.
 * \param node the AABB node that will be serialized.
 */
template <typename Key, std::floating_point Precision>
void serialize(auto& archive, aabb_node<Key, Precision>& node)
{
  archive(node.id, node.box, node.parent, node.left, node.right, node.next, node.height);
}

/**
 * \brief Indicates whether or not an AABB node is a leaf in an AABB tree.
 *
 * \param node the node that will be checked.
 *
 * \return `true` if the node is a leaf; `false` otherwise.
 */
template <typename Key, std::floating_point Precision>
[[nodiscard]] constexpr auto is_leaf(const aabb_node<Key, Precision>& node) noexcept
    -> bool
{
  return !node.left;
}

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_NODE_HPP

// #include "containers/aabb_tree.hpp"
#ifndef RUNE_CONTAINERS_AABB_TREE_HPP
#define RUNE_CONTAINERS_AABB_TREE_HPP

#include <array>          // array
#include <cassert>        // assert
#include <cmath>          // abs
#include <concepts>       // floating_point, invocable, same_as
#include <cstddef>        // byte
#include <deque>          // deque
#include <iterator>       // output_iterator
#include <limits>         // numeric_limits
#include <ostream>        // ostream
#include <stack>          // stack
#include <string>         // string
#include <type_traits>    // invoke_result_t
#include <unordered_map>  // unordered_map
#include <vector>         // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/maybe.hpp"

// #include "../math/max.hpp"

// #include "../math/min.hpp"

// #include "../math/vector2.hpp"

// #include "aabb.hpp"

// #include "aabb_node.hpp"
#ifndef RUNE_CONTAINERS_AABB_NODE_HPP
#define RUNE_CONTAINERS_AABB_NODE_HPP

#include <concepts>  // floating_point

// #include "../aliases/integers.hpp"

// #include "../aliases/maybe.hpp"

// #include "aabb.hpp"


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \class aabb_node
 *
 * \brief Represents a node in an AABB tree.
 *
 * \tparam Key the type of the associated key.
 *
 * \see `aabb_tree`
 * \see `is_leaf()`
 */
template <typename Key, std::floating_point Precision>
class aabb_node final
{
 public:
  using key_type = Key;                               ///< The type of the associated key.
  using precision_type = Precision;                   ///< The vector coordinate type.
  using vector_type = basic_vector2<precision_type>;  ///< The associated vector type.
  using aabb_type = basic_aabb<precision_type>;       ///< The associated AABB type.
  using index_type = usize;                           ///< The type used for node indices

  maybe<key_type> id;        ///< The user-provided ID associated with the AABB.
  aabb_type box;             ///< The associated AABB.
  maybe<index_type> parent;  ///< Index of parent node.
  maybe<index_type> left;    ///< Index of left child.
  maybe<index_type> right;   ///< Index of right child.
  maybe<index_type> next;    ///< Index of next adjacent node.
  int height{-1};            ///< Amount of levels below the node (0 for leaves).
};

/**
 * \brief Serializes an AABB node.
 *
 * \param archive the serialization archive that will be used.
 * \param node the AABB node that will be serialized.
 */
template <typename Key, std::floating_point Precision>
void serialize(auto& archive, aabb_node<Key, Precision>& node)
{
  archive(node.id, node.box, node.parent, node.left, node.right, node.next, node.height);
}

/**
 * \brief Indicates whether or not an AABB node is a leaf in an AABB tree.
 *
 * \param node the node that will be checked.
 *
 * \return `true` if the node is a leaf; `false` otherwise.
 */
template <typename Key, std::floating_point Precision>
[[nodiscard]] constexpr auto is_leaf(const aabb_node<Key, Precision>& node) noexcept
    -> bool
{
  return !node.left;
}

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_NODE_HPP

// #include "stack_resource.hpp"
#ifndef RUNE_CONTAINERS_STACK_RESOURCE_HPP
#define RUNE_CONTAINERS_STACK_RESOURCE_HPP

#include <array>            // array
#include <cstddef>          // byte
#include <memory_resource>  // memory_resource, monotonic_buffer_resource

// #include "../aliases/integers.hpp"


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \brief Represents a buffer of stack memory, for avoiding dynamic memory allocations.
 *
 * \details The following is an example of you can use this class.
 * \code{cpp}
 *   rune::stack_resource<128> resource;
 *   std::pmr::vector<int> vector{resource.get()};
 * \endcode
 *
 * \tparam size the size of the stack buffer.
 */
template <usize Size>
class stack_resource final
{
 public:
  /// \brief Returns the associated memory resource
  [[nodiscard]] auto get() noexcept -> std::pmr::memory_resource*
  {
    return &m_resource;
  }

  /// \copydoc get()
  [[nodiscard]] auto get() const noexcept -> const std::pmr::memory_resource*
  {
    return &m_resource;
  }

 private:
  std::array<std::byte, Size> m_buffer;
  std::pmr::monotonic_buffer_resource m_resource{m_buffer.data(), m_buffer.size()};
};

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_STACK_RESOURCE_HPP


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \def RUNE_AABB_TREE_DEFAULT_CAPACITY
 *
 * \brief The default capacity of entries in AABB trees.
 *
 * \note This macro should be expand to an integer value.
 *
 * \see `aabb_tree`
 */
#ifndef RUNE_AABB_TREE_DEFAULT_CAPACITY
#define RUNE_AABB_TREE_DEFAULT_CAPACITY 64
#endif  // RUNE_AABB_TREE_DEFAULT_CAPACITY

/**
 * \def RUNE_AABB_TREE_QUERY_BUFFER_SIZE
 *
 * \brief The default stack buffer size when looking for collision candidates (with
 * `aabb_tree::query()`), in bytes.
 *
 * \note This macro should be expand to an integer value.
 *
 * \see `aabb_tree`
 */
#ifndef RUNE_AABB_TREE_QUERY_BUFFER_SIZE
#define RUNE_AABB_TREE_QUERY_BUFFER_SIZE 256
#endif  // RUNE_AABB_TREE_QUERY_BUFFER_SIZE

// clang-format off
inline constexpr usize aabb_tree_default_capacity = RUNE_AABB_TREE_DEFAULT_CAPACITY;
inline constexpr usize aabb_tree_query_buffer_size = RUNE_AABB_TREE_QUERY_BUFFER_SIZE;
// clang-format on

/**
 * \class aabb_tree
 *
 * \brief An implementation of an AABB tree, intended to be used for efficient collision
 * detection.
 *
 * \details The usage of this class is relatively straight forward, register IDs with
 * AABBs and update their positions (or even size) throughout the duration of your game.
 * The following code illustrates the use of some of the core functions.
 * \code{cpp}
 * rune::aabb_tree<int> tree;  // AABB tree using integer keys
 *
 * // Add some AABB entries
 * tree.insert(42, {10, 10}, {20, 20});
 * tree.insert(123, {150, 125}, {192, 234});
 * tree.insert(27, {59, 95}, {73, 106});
 *
 * // Update the position of an existing AABB
 * tree.set_position(42, {27, 43});
 *
 * // Query the tree for collision candidates for a certain AABB
 * tree.query(42, [](int id) {
 *   // Invoked for each collision candidate (return true to stop query)
 * });
 *
 * // Remove an AABB
 * tree.erase(27);
 *
 * \endcode
 *
 * \tparam Key the type of the keys associated with tree entries.
 * \tparam Precision the floating-point type used, e.g. by stored vectors.
 *
 * \see `RUNE_AABB_TREE_DEFAULT_CAPACITY`
 * \see `RUNE_AABB_TREE_QUERY_BUFFER_SIZE`
 */
template <typename Key, std::floating_point Precision = float>
class aabb_tree final
{
 public:
  using key_type = Key;
  using precision_type = Precision;
  using vector_type = basic_vector2<precision_type>;
  using aabb_type = basic_aabb<precision_type>;
  using node_type = aabb_node<key_type, precision_type>;
  using index_type = usize;
  using size_type = usize;

  // TODO reserve()?

  /// \name Construction
  /// \{

  explicit aabb_tree(const size_type capacity = aabb_tree_default_capacity)
      : m_nodeCapacity{capacity}
  {
    assert(!m_root);
    assert(m_nodeCount == 0);
    assert(m_nodeCapacity == capacity);

    resize_to_match_node_capacity(0);
    assert(m_nextFreeIndex == 0);
  }

  /// \} End of construction

  /// \name Insertion/Deletion
  /// \{

  void insert(const key_type& key, const vector_type& lower, const vector_type& upper)
  {
    assert(!m_indices.contains(key));

    const auto index = allocate_node();

    {
      auto& node = m_nodes.at(index);
      node.id = key;
      node.box = {lower, upper};
      node.height = 0;

      if (m_thickness)
      {
        fatten(node.box, *m_thickness);
      }
    }

    insert_leaf(index);
    m_indices.emplace(key, index);

#ifdef RUNE_DEBUG_CONTAINERS
    validate();
#endif  // RUNE_DEBUG_CONTAINERS
  }

  void erase(const key_type& key)
  {
    if (const auto it = m_indices.find(key); it != m_indices.end())
    {
      const auto index = it->second;
      assert(index < m_nodeCapacity);
      assert(is_leaf(m_nodes.at(index)));

      m_indices.erase(it);

      remove_leaf(index);
      free_node(index);

#ifdef RUNE_DEBUG_CONTAINERS
      validate();
#endif  // RUNE_DEBUG_CONTAINERS
    }
  }

  void clear()
  {
    auto it = m_indices.begin();

    while (it != m_indices.end())
    {
      const auto nodeIndex = it->second;
      assert(nodeIndex < m_nodeCapacity);
      assert(is_leaf(m_nodes.at(nodeIndex)));

      remove_leaf(nodeIndex);
      free_node(nodeIndex);

      ++it;
    }

    m_indices.clear();

#ifdef RUNE_DEBUG_CONTAINERS
    validate();
#endif  // RUNE_DEBUG_CONTAINERS
  }

  /// \} End of insertion/deletion

  /// \name Tree structure
  /// \{

  void rebuild()
  {
    if (empty())
    {
      return;
    }

    std::vector<index_type> indices(m_nodeCount);
    int count{0};

    for (size_type index = 0; index < m_nodeCapacity; ++index)
    {
      auto& node = m_nodes.at(index);

      if (node.height < 0)
      {
        continue;
      }

      if (is_leaf(node))
      {
        node.parent = nothing;
        indices.at(static_cast<size_type>(count)) = index;
        ++count;
      }
      else
      {
        free_node(index);
      }
    }

    while (count > 1)
    {
      auto minCost = std::numeric_limits<precision_type>::max();
      int iMin{-1};
      int jMin{-1};

      for (auto i = 0; i < count; ++i)
      {
        const auto fstAabb = m_nodes.at(indices.at(static_cast<size_type>(i))).box;

        for (auto j = (i + 1); j < count; ++j)
        {
          const auto sndAabb = m_nodes.at(indices.at(static_cast<size_type>(j))).box;
          const auto cost = merge(fstAabb, sndAabb).area;

          if (cost < minCost)
          {
            iMin = i;
            jMin = j;
            minCost = cost;
          }
        }
      }

      const auto index1 = indices.at(iMin);
      const auto index2 = indices.at(jMin);

      const auto parentIndex = allocate_node();

      {
        auto& parentNode = m_nodes.at(parentIndex);
        auto& index1Node = m_nodes.at(index1);
        auto& index2Node = m_nodes.at(index2);

        parentNode.left = index1;
        parentNode.right = index2;
        parentNode.height = 1 + max(index1Node.height, index2Node.height);
        parentNode.box = merge(index1Node.box, index2Node.box);
        parentNode.parent = nothing;

        index1Node.parent = parentIndex;
        index2Node.parent = parentIndex;
      }

      indices.at(jMin) = indices.at(count - 1);
      indices.at(iMin) = parentIndex;

      --count;
    }

    m_root = indices.at(0);

#ifdef RUNE_DEBUG_CONTAINERS
    validate();
#endif  // RUNE_DEBUG_CONTAINERS
  }

  void print(std::ostream& stream) const
  {
    stream << "aabb_tree\n";
    print(stream, "", m_root, false);
  }

  [[nodiscard]] auto maximum_balance() const -> size_type
  {
    size_type maxBalance{};

    for (size_type index = 0; index < m_nodeCapacity; ++index)
    {
      const auto& node = m_nodes.at(index);
      if (node.height > 2)
      {
        assert(!is_leaf(node));
        assert(node.left);
        assert(node.right);

        const auto leftHeight = m_nodes.at(*node.left).height;
        const auto rightHeight = m_nodes.at(*node.right).height;

        const auto balance = std::abs(leftHeight - rightHeight);
        maxBalance = max(maxBalance, static_cast<size_type>(balance));
      }
    }

    return maxBalance;
  }

  [[nodiscard]] auto surface_area_ratio() const -> precision_type
  {
    if (!m_root)
    {
      return 0;
    }

    const auto rootArea = compute_area(m_nodes.at(*m_root).box);

    precision_type totalArea{};
    for (size_type index = 0; index < m_nodeCapacity; ++index)
    {
      const auto& node = m_nodes.at(index);
      if (node.height >= 0)
      {
        totalArea += compute_area(node.box);
      }
    }

    return totalArea / rootArea;
  }

  [[nodiscard]] auto height() const -> int
  {
    return m_root ? m_nodes.at(*m_root).height : 0;
  }

  [[nodiscard]] auto node_count() const noexcept -> size_type
  {
    return m_nodeCount;
  }

  /// \} End of tree structure

  /// \name AABB mutators
  /// \{

  auto update(const key_type& key, aabb_type box, const bool forceReinsert = false)
      -> bool
  {
    if (const auto it = m_indices.find(key); it != m_indices.end())
    {
      const auto nodeIndex = it->second;
      assert(nodeIndex < m_nodeCapacity);
      assert(is_leaf(m_nodes.at(nodeIndex)));

      // No need to update if the particle is still within its fattened AABB.
      if (!forceReinsert && m_nodes.at(nodeIndex).box.contains(box))
      {
        return false;
      }

      remove_leaf(nodeIndex);

      if (m_thickness)
      {
        fatten(box, *m_thickness);
      }

      {
        auto& node = m_nodes.at(nodeIndex);
        node.box = box;
        node.box.area = compute_area(node.box);
      }

      insert_leaf(nodeIndex);

#ifdef RUNE_DEBUG_CONTAINERS
      validate();
#endif  // RUNE_DEBUG_CONTAINERS
      return true;
    }
    else
    {
      return false;
    }
  }

  auto update(const key_type& key,
              const vector_type& lower,
              const vector_type& upper,
              const bool forceReinsert = false) -> bool
  {
    return update(key, aabb_type{lower, upper}, forceReinsert);
  }

  auto set_position(const key_type& key,
                    const vector_type& position,
                    const bool forceReinsert = false) -> bool
  {
    if (const auto it = m_indices.find(key); it != m_indices.end())
    {
      const auto& box = m_nodes.at(it->second).box;
      return update(key, {position, position + box.size()}, forceReinsert);
    }
    else
    {
      return false;
    }
  }

  /// \} End of AABB mutators

  /// \name AABB queries
  /// \{

  [[nodiscard]] auto at(const key_type& key) const -> const aabb_type&
  {
    const auto index = m_indices.at(key);
    return m_nodes.at(index).box;
  }

  [[nodiscard]] auto find(const key_type& key) const -> const aabb_type*
  {
    if (const auto it = m_indices.find(key); it != m_indices.end())
    {
      const auto index = it->second;
      return &m_nodes.at(index).box;
    }
    else
    {
      return nullptr;
    }
  }

  [[nodiscard]] auto size() const noexcept -> size_type
  {
    return m_indices.size();
  }

  [[nodiscard]] auto empty() const noexcept -> bool
  {
    return m_indices.empty();
  }

  /// \} End of AABB queries

  /// \name Thickness factor
  /// \{

  void disable_thickness_factor()
  {
    m_thickness.reset();
  }

  void set_thickness_factor(const precision_type factor)
  {
    m_thickness = factor;
  }

  [[nodiscard]] auto thickness_factor() const noexcept -> maybe<precision_type>
  {
    return m_thickness;
  }

  /// \} End of thickness factor

  /// \name Collision queries
  /// \{

  template <size_type BufferSize = aabb_tree_query_buffer_size,
            std::invocable<key_type> T>
  void query(const key_type& key, T&& callable) const
  {
    if (const auto it = m_indices.find(key); it != m_indices.end())
    {
      const auto index = it->second;
      const auto& sourceNode = m_nodes.at(index);

      stack_resource<BufferSize * sizeof(maybe<index_type>)> resource;
      pmr_stack<maybe<index_type>> stack{resource.get()};

      stack.push(m_root);

      bool quit{};
      while (!stack.empty() && !quit)
      {
        const auto nodeIndex = stack.top();
        stack.pop();

        if (!nodeIndex)
        {
          continue;
        }

        const auto& node = m_nodes.at(*nodeIndex);

        // Test for overlap between the AABBs
        if (overlaps(sourceNode.box, node.box, m_touchIsOverlap))
        {
          if (is_leaf(node) && node.id && node.id != key)
          {
            // The boolean return type is optional
            if constexpr (std::same_as<bool, std::invoke_result_t<T, key_type>>)
            {
              quit = callable(*node.id);
            }
            else
            {
              callable(*node.id);
            }
          }
          else
          {
            stack.push(node.left);
            stack.push(node.right);
          }
        }
      }
    }
  }

  template <size_type BufferSize = aabb_tree_query_buffer_size,
            std::output_iterator<key_type> T>
  void query(const key_type& key, T iterator) const
  {
    query<BufferSize>(key, [&](const key_type& key) {
      *iterator = key;
      ++iterator;
    });
  }

  /// \} End of collision queries

  /// \name Serialization
  /// \{

  void serialize(auto& archive)
  {
    archive(m_nodes,
            m_indices,
            m_root,
            m_nextFreeIndex,
            m_nodeCount,
            m_nodeCapacity,
            m_thickness,
            m_touchIsOverlap);
  }

  /// \} End of serialization

 private:
  inline static constexpr auto def_thickness_factor = static_cast<precision_type>(0.05);

  std::vector<node_type> m_nodes;                      ///< The collection of nodes
  std::unordered_map<key_type, index_type> m_indices;  ///< User IDs -> Node indices
  maybe<index_type> m_root;                            ///< Root node index
  maybe<index_type> m_nextFreeIndex{0};                ///< Index of next free node
  size_type m_nodeCount{0};                            ///< Number of nodes in the tree
  size_type m_nodeCapacity{};                          ///< Current node capacity
  maybe<precision_type> m_thickness{def_thickness_factor};  ///< Thickness factor
  bool m_touchIsOverlap{true};  ///< Overlap detection strategy

  /// \name Allocation
  /// \{

  /**
   * \brief Resizes the node vector.
   *
   * \param beginInitIndex the index at which the function will start to initialize the
   * `next` and `height` members of the new nodes.
   */
  void resize_to_match_node_capacity(const index_type beginInitIndex)
  {
    m_nodes.resize(m_nodeCapacity);

    const auto end = m_nodeCapacity - 1;
    for (auto index = beginInitIndex; index < end; ++index)
    {
      auto& node = m_nodes.at(index);
      node.next = index + 1;
      node.height = -1;
    }

    auto& node = m_nodes.at(end);
    node.next = nothing;
    node.height = -1;
  }

  /// \brief Doubles the size of the node pool.
  void grow_pool()
  {
    assert(m_nodeCount == m_nodeCapacity);  // Don't grow the pool unnecessarily

    // Expand the pool of nodes, only initializing new nodes.
    m_nodeCapacity *= 2;
    resize_to_match_node_capacity(m_nodeCount);

    // Update the index of the next free node.
    m_nextFreeIndex = static_cast<index_type>(m_nodeCount);
  }

  /**
   * \brief Returns the index to a new node.
   *
   * \details This function will grow the node pool if there are no available nodes.
   * Otherwise, this function will just increment the next free node index and return the
   * index of the previous next free node.
   *
   * \return the index of the allocated node.
   */
  [[nodiscard]] auto allocate_node() -> index_type
  {
    if (!m_nextFreeIndex)
    {
      grow_pool();
    }

    const auto index = m_nextFreeIndex.value();
    auto& node = m_nodes.at(index);

    m_nextFreeIndex = node.next;

    node.parent = nothing;
    node.left = nothing;
    node.right = nothing;
    node.height = 0;

    ++m_nodeCount;

    return index;
  }

  void free_node(const index_type index)
  {
    assert(index < m_nodeCapacity);
    assert(0 < m_nodeCount);

    {
      auto& node = m_nodes.at(index);
      node.next = m_nextFreeIndex;
      node.height = -1;
    }

    m_nextFreeIndex = index;

    --m_nodeCount;
  }

  /// \} End of allocation

  /// \name Tree structure
  /// \{

  void print(std::ostream& stream,
             const std::string& prefix,
             const maybe<index_type> index,
             const bool isLeft) const
  {
    if (index)
    {
      stream << prefix << (isLeft ? "├── " : "└── ");

      const auto& node = m_nodes.at(*index);
      if (is_leaf(node))
      {
        stream << node.id.value() << '\n';
      }
      else
      {
        stream << "X\n";
      }

      print(stream, prefix + (isLeft ? "│   " : "    "), node.left, true);
      print(stream, prefix + (isLeft ? "│   " : "    "), node.right, false);
    }
  }

  [[nodiscard]] static auto left_cost(const aabb_type& leafAabb,
                                      const node_type& leftNode,
                                      const precision_type minimumCost) -> precision_type
  {
    if (is_leaf(leftNode))
    {
      return merge(leafAabb, leftNode.box).area + minimumCost;
    }
    else
    {
      const auto oldArea = leftNode.box.area;
      const auto newArea = merge(leafAabb, leftNode.box).area;
      return (newArea - oldArea) + minimumCost;
    }
  }

  [[nodiscard]] static auto right_cost(const aabb_type& leafAabb,
                                       const node_type& rightNode,
                                       const precision_type minimumCost) -> precision_type
  {
    if (is_leaf(rightNode))
    {
      return merge(leafAabb, rightNode.box).area + minimumCost;
    }
    else
    {
      const auto oldArea = rightNode.box.area;
      const auto newArea = merge(leafAabb, rightNode.box).area;
      return (newArea - oldArea) + minimumCost;
    }
  }

  [[nodiscard]] auto find_best_sibling(const aabb_type& leafAabb) const -> index_type
  {
    auto index = m_root.value();

    while (!is_leaf(m_nodes.at(index)))
    {
      const auto& node = m_nodes.at(index);
      const auto left = node.left.value();
      const auto right = node.right.value();

      const auto surfaceArea = node.box.area;
      const auto combinedSurfaceArea = merge(node.box, leafAabb).area;

      // Cost of creating a new parent for this node and the new leaf.
      const auto cost = precision_type{2.0} * combinedSurfaceArea;

      // Minimum cost of pushing the leaf further down the tree.
      const auto minimumCost = precision_type{2.0} * (combinedSurfaceArea - surfaceArea);

      const auto costLeft = left_cost(leafAabb, m_nodes.at(left), minimumCost);
      const auto costRight = right_cost(leafAabb, m_nodes.at(right), minimumCost);

      // Descend according to the minimum cost.
      if ((cost < costLeft) && (cost < costRight))
      {
        break;
      }

      if (costLeft < costRight)
      {
        index = left;
      }
      else
      {
        index = right;
      }
    }

    return index;
  }

  void rotate_right(const index_type nodeIndex,
                    const index_type leftIndex,
                    const index_type rightIndex)
  {
    auto& node = m_nodes.at(nodeIndex);
    auto& rightNode = m_nodes.at(rightIndex);

    const auto rightLeft = rightNode.left.value();
    assert(rightLeft < m_nodeCapacity);

    const auto rightRight = rightNode.right.value();
    assert(rightRight < m_nodeCapacity);

    // Swap node and its right-hand child.
    rightNode.left = nodeIndex;
    rightNode.parent = node.parent;
    node.parent = rightIndex;

    // The node's old parent should now point to its right-hand child.
    if (rightNode.parent)
    {
      auto& rightParent = m_nodes.at(*rightNode.parent);
      if (rightParent.left == nodeIndex)
      {
        rightParent.left = rightIndex;
      }
      else
      {
        assert(rightParent.right == nodeIndex);
        rightParent.right = rightIndex;
      }
    }
    else
    {
      m_root = rightIndex;
    }

    auto& leftNode = m_nodes.at(leftIndex);
    auto& rightRightNode = m_nodes.at(rightRight);
    auto& rightLeftNode = m_nodes.at(rightLeft);

    // Rotate.
    if (rightLeftNode.height > rightRightNode.height)
    {
      rightNode.right = rightLeft;
      node.right = rightRight;

      rightRightNode.parent = nodeIndex;

      node.box = merge(leftNode.box, rightRightNode.box);
      rightNode.box = merge(node.box, rightLeftNode.box);

      node.height = 1 + max(leftNode.height, rightRightNode.height);
      rightNode.height = 1 + max(node.height, rightLeftNode.height);
    }
    else
    {
      rightNode.right = rightRight;
      node.right = rightLeft;

      rightLeftNode.parent = nodeIndex;

      node.box = merge(leftNode.box, rightLeftNode.box);
      rightNode.box = merge(node.box, rightRightNode.box);

      node.height = 1 + max(leftNode.height, rightLeftNode.height);
      rightNode.height = 1 + max(node.height, rightRightNode.height);
    }
  }

  void rotate_left(const index_type nodeIndex,
                   const index_type leftIndex,
                   const index_type rightIndex)
  {
    auto& node = m_nodes.at(nodeIndex);
    auto& leftNode = m_nodes.at(leftIndex);

    const auto leftLeft = leftNode.left.value();
    assert(leftLeft < m_nodeCapacity);

    const auto leftRight = leftNode.right.value();
    assert(leftRight < m_nodeCapacity);

    // Swap node and its left-hand child.
    leftNode.left = nodeIndex;
    leftNode.parent = node.parent;
    node.parent = leftIndex;

    // The node's old parent should now point to its left-hand child.
    if (leftNode.parent)
    {
      auto& leftParent = m_nodes.at(*leftNode.parent);
      if (leftParent.left == nodeIndex)
      {
        leftParent.left = leftIndex;
      }
      else
      {
        assert(leftParent.right == nodeIndex);
        leftParent.right = leftIndex;
      }
    }
    else
    {
      m_root = leftIndex;
    }

    auto& rightNode = m_nodes.at(rightIndex);
    auto& leftLeftNode = m_nodes.at(leftLeft);
    auto& leftRightNode = m_nodes.at(leftRight);

    // Rotate.
    if (leftLeftNode.height > leftRightNode.height)
    {
      leftNode.right = leftLeft;
      node.left = leftRight;

      leftRightNode.parent = nodeIndex;

      node.box = merge(rightNode.box, leftRightNode.box);
      leftNode.box = merge(node.box, leftLeftNode.box);

      node.height = 1 + max(rightNode.height, leftRightNode.height);
      leftNode.height = 1 + max(node.height, leftLeftNode.height);
    }
    else
    {
      leftNode.right = leftRight;
      node.left = leftLeft;

      leftLeftNode.parent = nodeIndex;

      node.box = merge(rightNode.box, leftLeftNode.box);
      leftNode.box = merge(node.box, leftRightNode.box);

      node.height = 1 + max(rightNode.height, leftLeftNode.height);
      leftNode.height = 1 + max(node.height, leftRightNode.height);
    }
  }

  [[nodiscard]] auto balance(const index_type index) -> index_type
  {
    if (is_leaf(m_nodes.at(index)) || (m_nodes.at(index).height < 2))
    {
      return index;
    }

    const auto leftIndex = m_nodes.at(index).left.value();
    assert(leftIndex < m_nodeCapacity);

    const auto rightIndex = m_nodes.at(index).right.value();
    assert(rightIndex < m_nodeCapacity);

    const auto currentBalance =
        m_nodes.at(rightIndex).height - m_nodes.at(leftIndex).height;

    // Rotate right branch up.
    if (currentBalance > 1)
    {
      rotate_right(index, leftIndex, rightIndex);
      return rightIndex;
    }

    // Rotate left branch up.
    if (currentBalance < -1)
    {
      rotate_left(index, leftIndex, rightIndex);
      return leftIndex;
    }

    return index;
  }

  void fix_tree_upwards(maybe<index_type> index)
  {
    while (index)
    {
      index = balance(*index);

      auto& node = m_nodes.at(*index);

      const auto& leftNode = m_nodes.at(node.left.value());
      const auto& rightNode = m_nodes.at(node.right.value());

      node.box = merge(leftNode.box, rightNode.box);
      node.height = 1 + max(leftNode.height, rightNode.height);

      index = node.parent;
    }
  }

  /// \} End of tree structure

  /// \name Leaves
  /// \{

  void insert_leaf(const index_type leafIndex)
  {
    if (!m_root)
    {
      m_root = leafIndex;
      m_nodes.at(leafIndex).parent = nothing;
      return;
    }

    // Find the best sibling for the node.
    const auto leafAabb = m_nodes.at(leafIndex).box;  // copy current AABB
    const auto siblingIndex = find_best_sibling(leafAabb);

    // Create a new parent.
    const auto oldParentIndex = m_nodes.at(siblingIndex).parent;
    const auto newParentIndex = allocate_node();

    {
      auto& newParent = m_nodes.at(newParentIndex);
      newParent.parent = oldParentIndex;
      newParent.box = merge(leafAabb, m_nodes.at(siblingIndex).box);
      newParent.height = m_nodes.at(siblingIndex).height + 1;
      newParent.left = siblingIndex;
      newParent.right = leafIndex;
    }

    if (oldParentIndex)
    {
      // The sibling was not the root.
      auto& oldParent = m_nodes.at(*oldParentIndex);
      if (oldParent.left == siblingIndex)
      {
        oldParent.left = newParentIndex;
      }
      else
      {
        oldParent.right = newParentIndex;
      }
    }
    else
    {
      // The sibling was the root.
      m_root = newParentIndex;
    }

    m_nodes.at(siblingIndex).parent = newParentIndex;
    m_nodes.at(leafIndex).parent = newParentIndex;

    // Walk back up the tree fixing heights and AABBs.
    fix_tree_upwards(m_nodes.at(leafIndex).parent);
  }

  void remove_leaf(const index_type leafIndex)
  {
    if (leafIndex == m_root)
    {
      m_root = nothing;
      return;
    }

    const auto parentIndex = m_nodes.at(leafIndex).parent;
    const auto grandParentIndex = m_nodes.at(parentIndex.value()).parent;

    const auto siblingIndex = (m_nodes.at(parentIndex.value()).left == leafIndex)
                                  ? m_nodes.at(parentIndex.value()).right
                                  : m_nodes.at(parentIndex.value()).left;

    // Destroy the parent and connect the sibling to the grandparent.
    if (grandParentIndex)
    {
      if (m_nodes.at(*grandParentIndex).left == parentIndex)
      {
        m_nodes.at(*grandParentIndex).left = siblingIndex;
      }
      else
      {
        m_nodes.at(*grandParentIndex).right = siblingIndex;
      }

      m_nodes.at(siblingIndex.value()).parent = grandParentIndex;
      free_node(parentIndex.value());

      // Adjust ancestor bounds.
      fix_tree_upwards(grandParentIndex);
    }
    else
    {
      m_root = siblingIndex;
      m_nodes.at(siblingIndex.value()).parent = nothing;
      free_node(parentIndex.value());
    }
  }

  /// \} End of leaves

  /// \name Collision queries
  /// \{

  template <typename T>
  using pmr_stack = std::stack<T, std::pmr::deque<T>>;

  /// \} End of collision queries

  /// \name Validation
  /// \{

  [[nodiscard]] auto compute_height(const maybe<index_type> nodeIndex) const -> size_type
  {
    if (!nodeIndex)
    {
      return 0;
    }

    assert(nodeIndex < m_nodeCapacity);

    const auto& node = m_nodes.at(*nodeIndex);
    if (is_leaf(node))
    {
      return 0;
    }
    else
    {
      const auto left = compute_height(node.left);
      const auto right = compute_height(node.right);
      return 1 + max(left, right);
    }
  }

  [[nodiscard]] auto compute_height() const -> size_type
  {
    return compute_height(m_root);
  }

  void validate_structure(const maybe<index_type> nodeIndex) const
  {
    if (nodeIndex == nothing)
    {
      return;
    }

    const auto& node = m_nodes.at(*nodeIndex);

    if (nodeIndex == m_root)
    {
      assert(!node.parent);
    }

    const auto left = node.left;
    const auto right = node.right;

    if (is_leaf(node))
    {
      assert(!left);
      assert(!right);
      assert(node.height == 0);
    }
    else
    {
      assert(left < m_nodeCapacity);
      assert(right < m_nodeCapacity);
      assert(left);
      assert(right);

      assert(m_nodes.at(*left).parent == nodeIndex);
      assert(m_nodes.at(*right).parent == nodeIndex);

      validate_structure(left);
      validate_structure(right);
    }
  }

  void validate_metrics(const maybe<index_type> nodeIndex) const
  {
    if (!nodeIndex)
    {
      return;
    }

    const auto& node = m_nodes.at(*nodeIndex);
    const auto left = node.left;
    const auto right = node.right;

    if (is_leaf(node))
    {
      assert(!left);
      assert(!right);
      assert(node.height == 0);
      return;
    }
    else
    {
      assert(left < m_nodeCapacity);
      assert(right < m_nodeCapacity);
      assert(left);
      assert(right);

      const auto leftHeight = m_nodes.at(*left).height;
      const auto rightHeight = m_nodes.at(*right).height;
      const auto height = 1 + max(leftHeight, rightHeight);
      assert(node.height == height);

      const auto box = merge(m_nodes.at(*left).box, m_nodes.at(*right).box);

      assert(box.min.x == node.box.min.x);
      assert(box.min.y == node.box.min.y);
      assert(box.max.x == node.box.max.x);
      assert(box.max.y == node.box.max.y);

      validate_metrics(left);
      validate_metrics(right);
    }
  }

  void validate()
  {
    validate_structure(m_root);
    validate_metrics(m_root);

    auto freeCount = 0;
    auto freeIndex = m_nextFreeIndex;

    while (freeIndex)
    {
      assert(freeIndex < m_nodeCapacity);
      freeIndex = m_nodes.at(*freeIndex).next;
      ++freeCount;
    }

    assert(height() == compute_height());
    assert((m_nodeCount + freeCount) == m_nodeCapacity);
  }

  /// \} End of validation
};

template <typename Key, std::floating_point Precision>
auto operator<<(std::ostream& stream, const aabb_tree<Key, Precision>& tree)
    -> std::ostream&
{
  tree.print(stream);
  return stream;
}

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_TREE_HPP

// #include "containers/stack_resource.hpp"
#ifndef RUNE_CONTAINERS_STACK_RESOURCE_HPP
#define RUNE_CONTAINERS_STACK_RESOURCE_HPP

#include <array>            // array
#include <cstddef>          // byte
#include <memory_resource>  // memory_resource, monotonic_buffer_resource

// #include "../aliases/integers.hpp"


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \brief Represents a buffer of stack memory, for avoiding dynamic memory allocations.
 *
 * \details The following is an example of you can use this class.
 * \code{cpp}
 *   rune::stack_resource<128> resource;
 *   std::pmr::vector<int> vector{resource.get()};
 * \endcode
 *
 * \tparam size the size of the stack buffer.
 */
template <usize Size>
class stack_resource final
{
 public:
  /// \brief Returns the associated memory resource
  [[nodiscard]] auto get() noexcept -> std::pmr::memory_resource*
  {
    return &m_resource;
  }

  /// \copydoc get()
  [[nodiscard]] auto get() const noexcept -> const std::pmr::memory_resource*
  {
    return &m_resource;
  }

 private:
  std::array<std::byte, Size> m_buffer;
  std::pmr::monotonic_buffer_resource m_resource{m_buffer.data(), m_buffer.size()};
};

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_STACK_RESOURCE_HPP

// #include "containers/static_vector.hpp"
#ifndef RUNE_CONTAINERS_STATIC_VECTOR_HPP
#define RUNE_CONTAINERS_STATIC_VECTOR_HPP

#include <array>             // array
#include <cassert>           // assert
#include <concepts>          // default_initializable
#include <initializer_list>  // initializer_list
#include <utility>           // forward, move

// #include "../aliases/integers.hpp"

// #include "../core/rune_error.hpp"
#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

// #include "../aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune


namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const str what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> str override
  {
    return m_what;
  }

 private:
  str m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP


namespace rune {

/// \addtogroup containers
/// \{

/**
 * \class static_vector
 *
 * \brief A sequence container with an API similar to that of `std::vector`, but the
 * elements are stored in a `std::array`, i.e. as a part of the object.
 *
 * \note This class performs no dynamic memory allocations by itself.
 *
 * \tparam T the element type.
 * \tparam Capacity the maximum capacity of the vector.
 */
template <std::default_initializable T, usize Capacity>
class static_vector final
{
 public:
  using size_type = usize;
  using value_type = T;
  using iterator = value_type*;
  using const_iterator = const value_type*;

  constexpr static_vector() = default;

  /**
   * \brief Creates a vector with the specified elements.
   *
   * \pre The size of the supplied list must not exceed the capacity of the vector.
   *
   * \details A terse way to use this constructor is using CTAD.
   * \code{cpp}
   *   static_vector vector = {1, 2, 3}; // decltype(vector) == static_vector<int, 3>
   * \endcode
   *
   * \param list the list of elements.
   */
  constexpr static_vector(std::initializer_list<value_type> list)
  {
    const auto size = list.size();
    assert(size <= Capacity);

    for (size_type index = 0u; auto value : list)
    {
      m_data.at(index) = std::move(value);
      ++index;
    }

    m_size = size;
  }

  /// Clears the vector.
  constexpr void clear() noexcept
  {
    m_size = 0;
  }

  /**
   * \brief Adds an element to the end of the vector.
   *
   * \param value the element that will be added.
   *
   * \throws rune_error if the vector is already full.
   */
  constexpr void push_back(const value_type& value)
  {
    const auto index = m_size;
    if (index < Capacity)
    {
      m_data.at(index) = value;
      ++m_size;
    }
    else
    {
      throw rune_error{"static_vector::push_back(): vector already full"};
    }
  }

  /// \copydoc push_back()
  constexpr void push_back(value_type&& value)
  {
    const auto index = m_size;
    if (index < Capacity)
    {
      m_data.at(index) = std::move(value);
      ++m_size;
    }
    else
    {
      throw rune_error{"static_vector::push_back(): vector already full"};
    }
  }

  /**
   * \brief Adds an element to the end of the vector, creating it from the supplied
   * arguments.
   *
   * \tparam Args the types of the arguments that will be forwarded.
   *
   * \param args the arguments that will be forwarded to an appropriate value constructor.
   *
   * \return a reference to the created element.
   *
   * \throws rune_error if the vector is already full.
   */
  template <typename... Args>
  constexpr auto emplace_back(Args&&... args) -> T&
  {
    const auto index = m_size;
    if (index < Capacity)
    {
      m_data.at(index) = value_type{std::forward<Args>(args)...};
      ++m_size;
      return m_data.at(index);
    }
    else
    {
      throw rune_error{"static_vector::emplace_back(): vector already full"};
    }
  }

  /**
   * \brief Removes the last element of the vector.
   *
   * \note No element is destroyed by this function, i.e. no destructor is called, the
   * size is simply decremented.
   *
   * \pre The vector must not be empty.
   */
  constexpr void pop_back() noexcept
  {
    assert(!empty() && "static_vector mustn't be empty when pop_back() is called");
    --m_size;
  }

  /**
   * \brief Serializes the vector.
   *
   * \param archive the archive that will be used to serialize the vector.
   */
  constexpr void serialize(auto& archive)
  {
    archive(m_data, m_size);
  }

  /**
   * \brief Returns the element at the specified index.
   *
   * \param index the index of the desired element.
   *
   * \return the element at the specified index.
   *
   * \throws rune_error if the index is out of bounds.
   */
  [[nodiscard]] constexpr auto at(const size_type index) -> value_type&
  {
    if (index < m_size)
    {
      return m_data.at(index);
    }
    else
    {
      throw rune_error{"static_vector::at(): invalid index"};
    }
  }

  /// \copydoc at()
  [[nodiscard]] constexpr auto at(const size_type index) const -> const value_type&
  {
    if (index < m_size)
    {
      return m_data.at(index);
    }
    else
    {
      throw rune_error{"static_vector::at(): invalid index"};
    }
  }

  /**
   * \brief Returns the element at the specified index.
   *
   * \warning This function performs no bounds checking.
   *
   * \pre `index` must not be out of bounds.
   *
   * \param index the index of the desired element.
   *
   * \return the element at the specified index.
   */
  [[nodiscard]] constexpr auto operator[](const size_type index) -> value_type&
  {
    assert(index < m_size);
    return m_data[index];
  }

  /// \copydoc operator[]()
  [[nodiscard]] constexpr auto operator[](const size_type index) const
      -> const value_type&
  {
    assert(index < m_size);
    return m_data[index];
  }

  /// \brief Returns the amount of elements.
  [[nodiscard]] constexpr auto size() const noexcept -> size_type
  {
    return m_size;
  }

  /// \brief Returns the maximum amount of elements.
  [[nodiscard]] constexpr auto capacity() const noexcept -> size_type
  {
    return Capacity;
  }

  /**
   * \brief Indicates whether or not the vector is empty.
   *
   * \return `true` if the vector is empty; `false` otherwise.
   */
  [[nodiscard]] constexpr auto empty() const noexcept -> bool
  {
    return m_size == 0;
  }

  /// \brief Returns an iterator to the beginning of the vector.
  [[nodiscard]] constexpr auto begin() noexcept -> iterator
  {
    return m_data.data();
  }

  /// \copydoc begin()
  [[nodiscard]] constexpr auto begin() const noexcept -> const_iterator
  {
    return m_data.data();
  }

  /// \brief Returns an iterator to the end of the vector.
  [[nodiscard]] constexpr auto end() noexcept -> iterator
  {
    return begin() + m_size;
  }

  /// \copydoc end()
  [[nodiscard]] constexpr auto end() const noexcept -> const_iterator
  {
    return begin() + m_size;
  }

 private:
  std::array<T, Capacity> m_data{};
  size_type m_size{};
};

template <typename T, typename... Rest>
static_vector(T, Rest...) -> static_vector<T, 1u + sizeof...(Rest)>;

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_STATIC_VECTOR_HPP

// #include "containers/vector_map.hpp"
#ifndef RUNE_CONTAINERS_VECTOR_MAP_HPP
#define RUNE_CONTAINERS_VECTOR_MAP_HPP

#include <algorithm>  // find_if
#include <cassert>    // assert
#include <concepts>   // convertible_to
#include <iterator>   // distance, iter_swap
#include <utility>    // pair, move, forward
#include <vector>     // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/maybe.hpp"

// #include "../core/rune_error.hpp"


namespace rune {

/// \addtogroup containers
/// \{

// clang-format off

template <typename T, typename U>
concept transparent_to = requires (T key, U actual)
{
  { key == actual } -> std::convertible_to<bool>;
  { actual == key } -> std::convertible_to<bool>;
};

// clang-format on

/**
 * \class vector_map
 *
 * \brief A cache-friendly associative container for small sets of key/value pairs.
 *
 * \details This container is useful when the number of pairs is small (approximately
 * 0-100 elements), due to the fact that the internal representation is a `std::vector`
 * of key/value pairs. This results in very fast iteration and lookup (as long as the
 * total amount of entries is relatively small) due to the contiguous layout of the
 * elements.
 *
 * \tparam K the key type.
 * \tparam V the value type.
 */
template <typename K, typename V>
class vector_map final
{
 public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<key_type, mapped_type>;
  using size_type = usize;
  using iterator = typename std::vector<value_type>::iterator;
  using const_iterator = typename std::vector<value_type>::const_iterator;

  vector_map() noexcept = default;

  /**
   * \brief Creates a map with the specified storage capacity.
   *
   * \param capacity the amount of entries the map can store without needing needing to
   * allocate additional memory.
   */
  explicit vector_map(const size_type capacity)
  {
    reserve(capacity);
  }

  /// \brief Clears the map of all entries.
  void clear() noexcept
  {
    m_data.clear();
  }

  /**
   * \brief Ensures that the map can store the specified amount of entries without
   * reallocation.
   *
   * \note This function has no effect if the specified capacity isn't greater than the
   * current capacity.
   *
   * \param capacity the new capacity of the map.
   */
  void reserve(const size_type capacity)
  {
    m_data.reserve(capacity);
  }

  /**
   * \brief Adds a key/value pair to the map.
   *
   * \pre `key` must not be associated with an existing entry.
   *
   * \tparam Args the types of the arguments that will be forwarded.
   *
   * \param key the key that will be associated with the value.
   * \param args the arguments that will be forwarded to a `mapped_type` constructor.
   *
   * \return a reference to the added key/value pair.
   */
  template <typename... Args>
  auto emplace(key_type key, Args&&... args) -> value_type&
  {
    assert(!contains(key));
    return m_data.emplace_back(std::move(key), mapped_type{std::forward<Args>(args)...});
  }

  /**
   * \brief Adds a key/value pair to the map.
   *
   * \pre `key` must not be associated with an existing entry.
   *
   * \param key the key that will be associated with the value.
   * \param value the value that will be moved into the map.
   *
   * \return a reference to the added key/value pair.
   */
  auto emplace(key_type key, mapped_type value) -> value_type&
  {
    assert(!contains(key));
    return m_data.emplace_back(std::move(key), std::move(value));
  }

  /**
   * \brief Adds or replaces a key/value pair in the map.
   *
   * \tparam Args the types of the arguments that will be forwarded.
   *
   * \param key the key that will be associated with the value.
   * \param args the arguments that will be forwarded to a `mapped_type` constructor.
   *
   * \return a reference to the added key/value pair.
   */
  template <typename... Args>
  auto emplace_or_replace(key_type key, Args&&... args) -> value_type&
  {
    if (const auto it = find(key); it != end())
    {
      it->second = mapped_type{std::forward<Args>(args)...};
      return *it;
    }
    else
    {
      return emplace(std::move(key), std::forward<Args>(args)...);
    }
  }

  /**
   * \brief Adds or replaces a key/value pair in the map.
   *
   * \param key the key that will be associated with the value.
   * \param value the value that will be moved into the map.
   *
   * \return a reference to the added key/value pair.
   */
  auto emplace_or_replace(key_type key, mapped_type value) -> value_type&
  {
    if (const auto it = find(key); it != end())
    {
      it->second = std::move(value);
      return *it;
    }
    else
    {
      return emplace(std::move(key), std::move(value));
    }
  }

  /**
   * \brief Removes an entry from the map.
   *
   * \note This function has no effect if there is no entry associated with the specified
   * key.
   *
   * \param key the key associated with the entry that will be removed.
   */
  template <transparent_to<key_type> T>
  void erase(const T& key)
  {
    std::erase_if(m_data, [&](const value_type& pair) { return pair.first == key; });
  }

  /**
   * \brief Moves the the specified key/value pair forwards in the underlying array by one
   * step.
   *
   * \param key the key/value pair that will be moved in the underlying vector.
   */
  template <transparent_to<key_type> T>
  void move_forward(const T& key)
  {
    move_element<true>(key);
  }

  /**
   * \brief Moves the the specified key/value pair backwards in the underlying array by
   * one step.
   *
   * \param key the key/value pair that will be moved in the underlying vector.
   */
  template <transparent_to<key_type> T>
  void move_backward(const T& key)
  {
    move_element<false>(key);
  }

  /**
   * \brief Returns an iterator to the element associated with the specified key.
   *
   * \tparam T the type of the key, must be comparable with the real key type.
   *
   * \param key the key to of the value to look for.
   *
   * \return an iterator to the found element; `end()` is returned if the element wasn't
   * found.
   */
  template <transparent_to<key_type> T>
  [[nodiscard]] auto find(const T& key) -> iterator
  {
    return std::ranges::find_if(m_data, [&](const value_type& pair) {
      return pair.first == key;
    });
  }

  /// \copydoc find()
  template <transparent_to<key_type> T>
  [[nodiscard]] auto find(const T& key) const -> const_iterator
  {
    return std::ranges::find_if(m_data, [&](const value_type& pair) {
      return pair.first == key;
    });
  }

  /**
   * \brief Returns the key/value pair at the specified index.
   *
   * \param index the index of the desired key/value pair.
   *
   * \throws std::out_of_range if the index is out out of bounds.
   *
   * \return a key/value pair.
   */
  [[nodiscard]] auto at_index(const size_type index) -> value_type&
  {
    return m_data.at(index);
  }

  /// \copydoc at_index()
  [[nodiscard]] auto at_index(const size_type index) const -> const value_type&
  {
    return m_data.at(index);
  }

  /**
   * \brief Returns the value associated with the specified key.
   *
   * \tparam T the type of the key, must be comparable with the real key type.
   *
   * \param key the key associated with the desired value.
   *
   * \return the value associated with the specified key.
   *
   * \throws rune_error if the key is not associated with a value.
   *
   * \since 0.1.0
   */
  template <transparent_to<key_type> T>
  [[nodiscard]] auto at(const T& key) -> mapped_type&
  {
    if (auto it = find(key); it != end())
    {
      return it->second;
    }
    else
    {
      throw rune_error{"vector_map::at(): invalid key"};
    }
  }

  /// \copydoc at()
  template <transparent_to<key_type> T>
  [[nodiscard]] auto at(const T& key) const -> const mapped_type&
  {
    if (const auto it = find(key); it != end())
    {
      return it->second;
    }
    else
    {
      throw rune_error{"vector_map::at(): invalid key"};
    }
  }

  /// \copydoc at()
  template <transparent_to<key_type> T>
  [[nodiscard]] auto operator[](const T& key) -> mapped_type&
  {
    return at(key);
  }

  /// \copydoc at()
  template <transparent_to<key_type> T>
  [[nodiscard]] auto operator[](const T& key) const -> const mapped_type&
  {
    return at(key);
  }

  /**
   * \brief Returns the index of the entry associated with the specified key.
   *
   * \param key the key of the entry to look for.
   *
   * \return the index of the specified entry in the underlying vector; `nothing` if
   * the key is unused.
   */
  template <transparent_to<key_type> T>
  [[nodiscard]] auto index_of(const T& key) const -> maybe<size_type>
  {
    if (const auto it = find(key); it != end())
    {
      return std::distance(begin(), it);
    }
    else
    {
      return nothing;
    }
  }

  /**
   * \brief Indicates whether or not the map contains the specified key.
   *
   * \param key the key to look for.
   *
   * \return `true` if the map contains the supplied key; `false` otherwise.
   */
  template <transparent_to<key_type> T>
  [[nodiscard]] auto contains(const T& key) const -> bool
  {
    return find(key) != end();
  }

  /**
   * \brief Indicates whether or not the map is empty.
   *
   * \return `true` if the map is empty; `false` otherwise.
   */
  [[nodiscard]] auto empty() const noexcept -> bool
  {
    return m_data.empty();
  }

  /// \brief Returns the amount of key/value pairs that are stored in the map.
  [[nodiscard]] auto size() const noexcept -> size_type
  {
    return m_data.size();
  }

  /// \brief Returns the amount of entries the map can store without re-allocation.
  [[nodiscard]] auto capacity() const noexcept -> size_type
  {
    return m_data.capacity();
  }

  /// \brief Returns an iterator to the beginning of the map.
  [[nodiscard]] auto begin() noexcept -> iterator
  {
    return m_data.begin();
  }

  /// \copydoc begin()
  [[nodiscard]] auto begin() const noexcept -> const_iterator
  {
    return m_data.begin();
  }

  /// \brief Returns an iterator to the end of the map.
  [[nodiscard]] auto end() noexcept -> iterator
  {
    return m_data.end();
  }

  /// \copydoc end()
  [[nodiscard]] auto end() const noexcept -> const_iterator
  {
    return m_data.end();
  }

 private:
  std::vector<value_type> m_data;

  template <bool MoveForward, transparent_to<key_type> T>
  void move_element(const T& key)
  {
    if (const auto it = find(key); it != end())
    {
      const auto index = std::distance(begin(), it);
      if constexpr (MoveForward)
      {
        if (index != size() - 1)
        {
          std::iter_swap(it, it + 1);
        }
      }
      else
      {
        if (index != 0)
        {
          std::iter_swap(it, it - 1);
        }
      }
    }
  }
};

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_VECTOR_MAP_HPP

// #include "core/compiler.hpp"
#ifndef RUNE_CORE_COMPILER_HPP
#define RUNE_CORE_COMPILER_HPP

namespace rune {

/// \addtogroup core
/// \{

/// \name Compiler checks
/// \{

/// Indicates whether or not the current compiler is MSVC
[[nodiscard]] consteval auto on_msvc() noexcept -> bool
{
#ifdef _MSC_VER
  return true;
#else
  return false;
#endif  // _MSC_VER
}

/// Indicates whether or not the current compiler is GCC
[[nodiscard]] consteval auto on_gcc() noexcept -> bool
{
#ifdef __GNUC__
  return true;
#else
  return false;
#endif  // __GNUC__
}

/// Indicates whether or not the current compiler is Clang
[[nodiscard]] consteval auto on_clang() noexcept -> bool
{
#ifdef __clang__
  return true;
#else
  return false;
#endif  // __clang__
}

/// \} End of compiler checks

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_COMPILER_HPP

// #include "core/engine.hpp"
#ifndef RUNE_CORE_ENGINE_HPP
#define RUNE_CORE_ENGINE_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // window, renderer, ...
#include <concepts>       // derived_from, constructible_from

// #include "../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "game.hpp"
#ifndef RUNE_CORE_GAME_HPP
#define RUNE_CORE_GAME_HPP

#include <concepts>  // derived_from

// #include "aliases/delta_time.hpp"

// #include "core/graphics.hpp"
#ifndef RUNE_CORE_GRAPHICS_HPP
#define RUNE_CORE_GRAPHICS_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // window, renderer, texture, font_cache, pixel_format
#include <string>         // string
#include <unordered_map>  // unordered_map
#include <utility>        // forward
#include <vector>         // vector

// #include "../aliases/font_id.hpp"
#ifndef RUNE_ALIASES_FONT_ID_HPP
#define RUNE_ALIASES_FONT_ID_HPP

// #include "integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP


namespace rune {

using font_id = usize;

}  // namespace rune

#endif  // RUNE_ALIASES_FONT_ID_HPP

// #include "../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../aliases/texture_id.hpp"
#ifndef RUNE_ALIASES_TEXTURE_ID_HPP
#define RUNE_ALIASES_TEXTURE_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct texture_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \def RUNE_TEXTURE_ID_UNDERLYING_TYPE
 *
 * \brief The underlying type of the `texture_id` strong type.
 *
 * \details By default, the underlying type is `usize`.
 *
 * \note The value of this macro must be of a hashable type.
 */
#ifndef RUNE_TEXTURE_ID_UNDERLYING_TYPE
#define RUNE_TEXTURE_ID_UNDERLYING_TYPE usize
#endif  // RUNE_TEXTURE_ID_UNDERLYING_TYPE

/**
 * \typedef texture_id
 *
 * \brief Used as unique identifiers for textures.
 *
 * \details This is used in order to avoid loading the same texture more than once.
 *
 * \see `RUNE_TEXTURE_ID_UNDERLYING_TYPE`
 */
using texture_id =
    nenya::strong_type<RUNE_TEXTURE_ID_UNDERLYING_TYPE, tags::texture_id_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_ID_HPP

// #include "../aliases/texture_index.hpp"
#ifndef RUNE_ALIASES_TEXTURE_INDEX_HPP
#define RUNE_ALIASES_TEXTURE_INDEX_HPP

#include <nenya.hpp>  // strong_type

// #include "integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct texture_index_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \typedef texture_index
 *
 * \brief Strong type for texture indices, used by the `graphics` class.
 */
using texture_index = nenya::strong_type<usize, tags::texture_index_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_INDEX_HPP

// #include "compiler.hpp"
#ifndef RUNE_CORE_COMPILER_HPP
#define RUNE_CORE_COMPILER_HPP

namespace rune {

/// \addtogroup core
/// \{

/// \name Compiler checks
/// \{

/// Indicates whether or not the current compiler is MSVC
[[nodiscard]] consteval auto on_msvc() noexcept -> bool
{
#ifdef _MSC_VER
  return true;
#else
  return false;
#endif  // _MSC_VER
}

/// Indicates whether or not the current compiler is GCC
[[nodiscard]] consteval auto on_gcc() noexcept -> bool
{
#ifdef __GNUC__
  return true;
#else
  return false;
#endif  // __GNUC__
}

/// Indicates whether or not the current compiler is Clang
[[nodiscard]] consteval auto on_clang() noexcept -> bool
{
#ifdef __clang__
  return true;
#else
  return false;
#endif  // __clang__
}

/// \} End of compiler checks

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_COMPILER_HPP


namespace rune {

/// \addtogroup core
/// \{

/**
 * \class graphics
 *
 * \brief Provides the main graphics API.
 *
 * \details This class provides a renderer, efficient texture handling, font caches for
 * efficient text rendering, pixel format information, etc.
 *
 * \details For reduced memory consumption and redundancy in loaded textures, this class
 * manages a collection of textures that are given unique indices when loaded. These
 * indices literally correspond to indices in an array of textures managed by this class,
 * which results in very fast constant complexity lookup of textures.
 *
 * \details It is safe to derive your own custom graphics context classes from this class.
 * However, you then need to supply your custom graphics type as a template parameter to
 * your engine instance.
 *
 * \since 0.1.0
 */
class graphics
{
 public:
  using size_type = usize;

  /**
   * \brief Creates a graphics context.
   *
   * \tparam T the ownership semantics of the window.
   * \param window the associated game window.
   * \param flags the renderer flags supplied to the `cen::renderer` constructor.
   */
  template <typename T>
  graphics(const cen::basic_window<T>& window, const uint32 flags)
      : m_renderer{window, flags}
      , m_format{window.get_pixel_format()}
  {}

  virtual ~graphics() noexcept = default;

  /// \name Texture handling
  /// \{

  /**
   * \brief Reserves enough memory to store the specified amount of textures.
   *
   * \param capacity the new capacity of textures.
   */
  void reserve(const size_type capacity)
  {
    m_textures.reserve(capacity);
  }

  /**
   * \brief Loads a texture and returns the associated index.
   *
   * \details If a texture with the specified ID has already been loaded, then this
   * function does nothing, and just returns the existing texture index.
   *
   * \param id the unique ID of the texture.
   * \param path the file path of the texture.
   *
   * \return the index of the loaded texture.
   */
  auto load(const texture_id id, const std::string& path) -> texture_index
  {
    if (const auto it = m_indices.find(id); it != m_indices.end())
    {
      return it->second;
    }
    else
    {
      const auto index = m_textures.size();

      m_textures.emplace_back(m_renderer, path);
      m_indices.try_emplace(id, index);

      return texture_index{index};
    }
  }

  /**
   * \brief Returns the texture associated with the specified index.
   *
   * \details This function performs a very fast index lookup for finding the associated
   * texture. This function is not bounds checked in optimized builds, but an assertion
   * will abort the execution of the program in debug builds if an invalid index is used.
   *
   * \pre `index` must be associated with an existing texture.
   *
   * \param index the index of the desired texture.
   *
   * \return the texture associated with the index.
   */
  [[nodiscard]] auto at(const texture_index index) const noexcept(on_msvc())
      -> const cen::texture&
  {
    assert(index < m_textures.size());  // texture_index is unsigned
    return m_textures[index];
  }

  /// \copydoc at()
  [[nodiscard]] auto operator[](const texture_index index) const noexcept(on_msvc())
      -> const cen::texture&
  {
    return at(index);
  }

  /**
   * \brief Indicates whether or not a texture index is associated with a texture.
   *
   * \param index the texture index that will be checked.
   *
   * \return `true` if the texture index is associated with a texture; `false` otherwise.
   */
  [[nodiscard]] auto contains(const texture_index index) const noexcept -> bool
  {
    return index < m_textures.size();
  }

  /**
   * \brief Returns the texture index associated with the specified ID.
   *
   * \param id the ID associated with the texture.
   *
   * \return the index of the specified texture.
   *
   * \throws std::out_of_range if the supplied ID isn't associated with an index.
   */
  [[nodiscard]] auto to_index(const texture_id id) const -> texture_index
  {
    return m_indices.at(id);
  }

  /// \} End of texture handling

  /// \name Font cache handling
  /// \{

  /**
   * \brief Adds a font cache to the graphics context.
   *
   * \tparam Args the types of the font cache constructor arguments.
   *
   * \note Any previous font cache associated with the supplied ID is overwritten.
   *
   * \param id the unique ID that will be associated with the font cache.
   * \param args the arguments that will be forwarded to an appropriate font cache
   * constructor.
   */
  template <typename... Args>
  void emplace_cache(const font_id id, Args&&... args)
  {
    m_caches.insert_or_assign(id, cen::font_cache{std::forward<Args>(args)...});
  }

  /**
   * \brief Returns the font cache associated with the specified ID.
   *
   * \param id the ID associated with the desired font cache.
   *
   * \return the found font cache.
   *
   * \throws std::out_of_range if there is no font cache associated with the ID.
   */
  [[nodiscard]] auto get_cache(const font_id id) -> cen::font_cache&
  {
    return m_caches.at(id);
  }

  /// \copydoc get_cache()
  [[nodiscard]] auto get_cache(const font_id id) const -> const cen::font_cache&
  {
    return m_caches.at(id);
  }

  [[nodiscard]] auto get_font(const font_id id) -> cen::font&
  {
    return get_cache(id).get_font();
  }

  [[nodiscard]] auto get_font(const font_id id) const -> const cen::font&
  {
    return get_cache(id).get_font();
  }

  /**
   * \brief Indicates whether or not the graphics context has a font cache associated with
   * the specified ID.
   *
   * \param id the ID that will be checked.
   *
   * \return `true` if there is a font cache associated with the ID; `false` otherwise.
   */
  [[nodiscard]] auto contains_cache(const font_id id) const -> bool
  {
    return m_caches.contains(id);
  }

  /// \} End of font cache handling

  /**
   * \brief Returns the renderer associated with the graphics context.
   *
   * \return the associated renderer.
   */
  [[nodiscard]] auto renderer() noexcept -> cen::renderer&
  {
    return m_renderer;
  }

  /// \copydoc renderer()
  [[nodiscard]] auto renderer() const noexcept -> const cen::renderer&
  {
    return m_renderer;
  }

  /**
   * \brief Returns the pixel format used by the associated window.
   *
   * \return the associated pixel format.
   */
  [[nodiscard]] auto format() const noexcept -> cen::pixel_format
  {
    return m_format;
  }

 private:
  cen::renderer m_renderer;
  cen::pixel_format m_format;
  std::vector<cen::texture> m_textures;
  std::unordered_map<texture_id, texture_index> m_indices;
  std::unordered_map<size_type, cen::font_cache> m_caches;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GRAPHICS_HPP

// #include "core/input.hpp"
#ifndef RUNE_CORE_INPUT_HPP
#define RUNE_CORE_INPUT_HPP

#include <centurion.hpp>  // keyboard, mouse

namespace rune {

/// \addtogroup core
/// \{

struct input final
{
  cen::keyboard keyboard;
  cen::mouse mouse;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_INPUT_HPP


namespace rune {

/// \addtogroup core
/// \{

/**
 * \class game_base
 *
 * \brief The base class for all game class implementations.
 *
 * \details You should derive your game class from this class, which you then supply to
 * your engine instance.
 *
 * \details The following example illustrates a skeleton for a game using the Rune
 * framework. Note, no virtual functions are pure, i.e. you only have to override the
 * functions that you need in your own game class.
 *
 * \note Whilst this class is stateless and default-constructible, the `engine` class
 * expects game classes to be either default-constructible or constructible from a
 * reference to a graphics context.
 *
 * \code{cpp}
 * #include <rune.hpp>
 *
 * class AwesomeGame final : public rune::game_base
 * {
 *  public:
 *   explicit AwesomeGame(graphics_type& graphics)
 *   {
 *     // ...
 *   }
 *
 *   void handle_input(const rune::input& input) override
 *   {
 *     // ...
 *   }
 *
 *   void tick(rune::delta_time dt) override
 *   {
 *     // ...
 *   }
 *
 *   void render(graphics_type& graphics) const override
 *   {
 *     // ...
 *   }
 *
 *   [[nodiscard]] bool should_quit() const override
 *   {
 *     // ...
 *   }
 * };
 *
 * RUNE_IMPLEMENT_MAIN_WITH_GAME(AwesomeGame)
 * \endcode
 *
 * \see `game_base`
 * \see `engine`
 * \see `graphics`
 * \see `input`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_GAME`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_ENGINE`
 *
 * \since 0.1.0
 */
template <std::derived_from<graphics> Graphics>
class basic_game
{
 public:
  using graphics_type = Graphics;

  virtual ~basic_game() noexcept = default;

  /**
   * \brief Initializes the game state.
   *
   * \details This function is called just after the game class is constructed. A use case
   * for this function could be if you do not want to provide a constructor in your game
   * class that accepts a graphics context by reference.
   *
   * \param gfx the associated graphics context.
   *
   * \since 0.1.0
   */
  virtual void init(graphics_type& gfx)
  {}

  /**
   * \brief Invoked just before the game starts running.
   *
   * \details This function is guaranteed to only be called once just before the game loop
   * starts running.
   *
   * \since 0.1.0
   */
  virtual void on_start()
  {}

  /**
   * \brief Invoked just before the game stops running.
   *
   * \details This function is guaranteed to only be called once just after the game loop
   * has finished running, i.e. just before the game shuts down.
   *
   * \since 0.1.0
   */
  virtual void on_exit()
  {}

  /**
   * \brief Handles the current input state.
   *
   * \details This function is called each frame and is meant to handle user input.
   *
   * \details This function is called each frame _before_ both `tick()` and `render()`.
   *
   * \param input the current input state.
   *
   * \since 0.1.0
   */
  virtual void handle_input(const input& input)
  {}

  /**
   * \brief Updates the state of the game by one frame according to the delta.
   *
   * \details This function updates the core logic of the game.
   *
   * \details This function is called each frame _after_ `handle_input()` and _before_
   * `render()`.
   *
   * \param dt the current delta time, in seconds.
   *
   * \since 0.1.0
   */
  virtual void tick(delta_time dt)
  {}

  /**
   * \brief Renders the current game state.
   *
   * \details This function is called each frame _after_ both `handle_input()` and
   * `tick()`.
   *
   * \details If you've specified a custom graphics context type (that must derive from
   * `graphics`), then you can safely downcast the supplied graphics context using
   * `dynamic_cast` (or even `static_cast`, the engine is guaranteed to use your graphics
   * context type if specified).
   *
   * \note Remember to clear the rendering target and present your draw commands at the
   * beginning and end of your rendering function, respectively.
   *
   * \param gfx the graphics context used for rendering.
   *
   * \since 0.1.0
   */
  virtual void render(graphics_type& gfx) const
  {}

  /**
   * \brief Indicates whether or not the game should stop running.
   *
   * \details By default, this function returns `true`.
   *
   * \return `true` if the game should stop running; `false` otherwise.
   *
   * \since 0.1.0
   */
  [[nodiscard]] virtual auto should_quit() const -> bool
  {
    return false;
  }
};

using game_base = basic_game<graphics>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GAME_HPP
// #include "graphics.hpp"
#ifndef RUNE_CORE_GRAPHICS_HPP
#define RUNE_CORE_GRAPHICS_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // window, renderer, texture, font_cache, pixel_format
#include <string>         // string
#include <unordered_map>  // unordered_map
#include <utility>        // forward
#include <vector>         // vector

// #include "../aliases/font_id.hpp"

// #include "../aliases/integers.hpp"

// #include "../aliases/texture_id.hpp"

// #include "../aliases/texture_index.hpp"

// #include "compiler.hpp"


namespace rune {

/// \addtogroup core
/// \{

/**
 * \class graphics
 *
 * \brief Provides the main graphics API.
 *
 * \details This class provides a renderer, efficient texture handling, font caches for
 * efficient text rendering, pixel format information, etc.
 *
 * \details For reduced memory consumption and redundancy in loaded textures, this class
 * manages a collection of textures that are given unique indices when loaded. These
 * indices literally correspond to indices in an array of textures managed by this class,
 * which results in very fast constant complexity lookup of textures.
 *
 * \details It is safe to derive your own custom graphics context classes from this class.
 * However, you then need to supply your custom graphics type as a template parameter to
 * your engine instance.
 *
 * \since 0.1.0
 */
class graphics
{
 public:
  using size_type = usize;

  /**
   * \brief Creates a graphics context.
   *
   * \tparam T the ownership semantics of the window.
   * \param window the associated game window.
   * \param flags the renderer flags supplied to the `cen::renderer` constructor.
   */
  template <typename T>
  graphics(const cen::basic_window<T>& window, const uint32 flags)
      : m_renderer{window, flags}
      , m_format{window.get_pixel_format()}
  {}

  virtual ~graphics() noexcept = default;

  /// \name Texture handling
  /// \{

  /**
   * \brief Reserves enough memory to store the specified amount of textures.
   *
   * \param capacity the new capacity of textures.
   */
  void reserve(const size_type capacity)
  {
    m_textures.reserve(capacity);
  }

  /**
   * \brief Loads a texture and returns the associated index.
   *
   * \details If a texture with the specified ID has already been loaded, then this
   * function does nothing, and just returns the existing texture index.
   *
   * \param id the unique ID of the texture.
   * \param path the file path of the texture.
   *
   * \return the index of the loaded texture.
   */
  auto load(const texture_id id, const std::string& path) -> texture_index
  {
    if (const auto it = m_indices.find(id); it != m_indices.end())
    {
      return it->second;
    }
    else
    {
      const auto index = m_textures.size();

      m_textures.emplace_back(m_renderer, path);
      m_indices.try_emplace(id, index);

      return texture_index{index};
    }
  }

  /**
   * \brief Returns the texture associated with the specified index.
   *
   * \details This function performs a very fast index lookup for finding the associated
   * texture. This function is not bounds checked in optimized builds, but an assertion
   * will abort the execution of the program in debug builds if an invalid index is used.
   *
   * \pre `index` must be associated with an existing texture.
   *
   * \param index the index of the desired texture.
   *
   * \return the texture associated with the index.
   */
  [[nodiscard]] auto at(const texture_index index) const noexcept(on_msvc())
      -> const cen::texture&
  {
    assert(index < m_textures.size());  // texture_index is unsigned
    return m_textures[index];
  }

  /// \copydoc at()
  [[nodiscard]] auto operator[](const texture_index index) const noexcept(on_msvc())
      -> const cen::texture&
  {
    return at(index);
  }

  /**
   * \brief Indicates whether or not a texture index is associated with a texture.
   *
   * \param index the texture index that will be checked.
   *
   * \return `true` if the texture index is associated with a texture; `false` otherwise.
   */
  [[nodiscard]] auto contains(const texture_index index) const noexcept -> bool
  {
    return index < m_textures.size();
  }

  /**
   * \brief Returns the texture index associated with the specified ID.
   *
   * \param id the ID associated with the texture.
   *
   * \return the index of the specified texture.
   *
   * \throws std::out_of_range if the supplied ID isn't associated with an index.
   */
  [[nodiscard]] auto to_index(const texture_id id) const -> texture_index
  {
    return m_indices.at(id);
  }

  /// \} End of texture handling

  /// \name Font cache handling
  /// \{

  /**
   * \brief Adds a font cache to the graphics context.
   *
   * \tparam Args the types of the font cache constructor arguments.
   *
   * \note Any previous font cache associated with the supplied ID is overwritten.
   *
   * \param id the unique ID that will be associated with the font cache.
   * \param args the arguments that will be forwarded to an appropriate font cache
   * constructor.
   */
  template <typename... Args>
  void emplace_cache(const font_id id, Args&&... args)
  {
    m_caches.insert_or_assign(id, cen::font_cache{std::forward<Args>(args)...});
  }

  /**
   * \brief Returns the font cache associated with the specified ID.
   *
   * \param id the ID associated with the desired font cache.
   *
   * \return the found font cache.
   *
   * \throws std::out_of_range if there is no font cache associated with the ID.
   */
  [[nodiscard]] auto get_cache(const font_id id) -> cen::font_cache&
  {
    return m_caches.at(id);
  }

  /// \copydoc get_cache()
  [[nodiscard]] auto get_cache(const font_id id) const -> const cen::font_cache&
  {
    return m_caches.at(id);
  }

  [[nodiscard]] auto get_font(const font_id id) -> cen::font&
  {
    return get_cache(id).get_font();
  }

  [[nodiscard]] auto get_font(const font_id id) const -> const cen::font&
  {
    return get_cache(id).get_font();
  }

  /**
   * \brief Indicates whether or not the graphics context has a font cache associated with
   * the specified ID.
   *
   * \param id the ID that will be checked.
   *
   * \return `true` if there is a font cache associated with the ID; `false` otherwise.
   */
  [[nodiscard]] auto contains_cache(const font_id id) const -> bool
  {
    return m_caches.contains(id);
  }

  /// \} End of font cache handling

  /**
   * \brief Returns the renderer associated with the graphics context.
   *
   * \return the associated renderer.
   */
  [[nodiscard]] auto renderer() noexcept -> cen::renderer&
  {
    return m_renderer;
  }

  /// \copydoc renderer()
  [[nodiscard]] auto renderer() const noexcept -> const cen::renderer&
  {
    return m_renderer;
  }

  /**
   * \brief Returns the pixel format used by the associated window.
   *
   * \return the associated pixel format.
   */
  [[nodiscard]] auto format() const noexcept -> cen::pixel_format
  {
    return m_format;
  }

 private:
  cen::renderer m_renderer;
  cen::pixel_format m_format;
  std::vector<cen::texture> m_textures;
  std::unordered_map<texture_id, texture_index> m_indices;
  std::unordered_map<size_type, cen::font_cache> m_caches;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GRAPHICS_HPP

// #include "input.hpp"
#ifndef RUNE_CORE_INPUT_HPP
#define RUNE_CORE_INPUT_HPP

#include <centurion.hpp>  // keyboard, mouse

namespace rune {

/// \addtogroup core
/// \{

struct input final
{
  cen::keyboard keyboard;
  cen::mouse mouse;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_INPUT_HPP

// #include "semi_fixed_game_loop.hpp"
#ifndef RUNE_CORE_SEMI_FIXED_GAME_LOOP_HPP
#define RUNE_CORE_SEMI_FIXED_GAME_LOOP_HPP

#include <centurion.hpp>  // ...
#include <concepts>       // floating_point, derived_from

// #include "../aliases/delta_time.hpp"
#ifndef RUNE_ALIASES_DELTA_TIME_HPP
#define RUNE_ALIASES_DELTA_TIME_HPP

namespace rune {

/// \cond FALSE
namespace tags {
struct delta_time_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \def RUNE_DELTA_TIME_UNDERLYING_TYPE
 *
 * \brief The underlying type of the `delta_time` strong type.
 *
 * \note The underlying should be a floating-point type, i.e. `float`, `double` or
 * possibly `long double`.
 */
#ifndef RUNE_DELTA_TIME_UNDERLYING_TYPE
#define RUNE_DELTA_TIME_UNDERLYING_TYPE float
#endif  // RUNE_DELTA_TIME_UNDERLYING_TYPE

/**
 * \brief The type used for delta time values, e.g. in the `tick()` function of game class
 * implementations.
 *
 * \see `RUNE_DELTA_TIME_UNDERLYING_TYPE`
 */
using delta_time = RUNE_DELTA_TIME_UNDERLYING_TYPE;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_DELTA_TIME_HPP

// #include "../math/min.hpp"
#ifndef RUNE_MATH_MIN_HPP
#define RUNE_MATH_MIN_HPP

namespace rune {

/**
 * \brief Returns the smallest of two values.
 *
 * \note This function exists because `std::min()` isn't marked as `noexcept`.
 *
 * \ingroup math
 *
 * \tparam T the type of the values.
 *
 * \param a the first value.
 * \param b the second value.
 *
 * \return the smallest of the two values.
 */
template <typename T>
[[nodiscard]] constexpr auto min(const T& a, const T& b) noexcept(noexcept(a < b)) -> T
{
  return (a < b) ? a : b;
}

}  // namespace rune

#endif  // RUNE_MATH_MIN_HPP

// #include "game.hpp"

// #include "rune_error.hpp"
#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

// #include "../aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune


namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const str what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> str override
  {
    return m_what;
  }

 private:
  str m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP


namespace rune {

/// \addtogroup core
/// \{

/// \name Configuration macros
/// \{

/**
 * \def RUNE_MAX_TICK_RATE
 *
 * \brief The maximum tick rate of the game loop, i.e. the maximum amount of ticks per
 * second.
 *
 * \details The game loop will try to run at the refresh rate of the primary screen, as
 * long as the the refresh rate isn't greater than the value of this macro. By default,
 * this macro expands to `120.0`.
 *
 * \note The value of this macro should be a `double`.
 */
#ifndef RUNE_MAX_TICK_RATE
#define RUNE_MAX_TICK_RATE 120.0
#endif  // RUNE_MAX_TICK_RATE

/**
 * \def RUNE_ENGINE_MAX_FRAMES_PER_TICK
 *
 * \brief The maximum amount of frames that the game loop can run per tick.
 *
 * \details The purpose of this limit is to avoid the "spiral-of-death". By default, this
 * macro expands to `5`.
 *
 * \note The value of this macro should be an `int`.
 */
#ifndef RUNE_ENGINE_MAX_FRAMES_PER_TICK
#define RUNE_ENGINE_MAX_FRAMES_PER_TICK 5
#endif  // RUNE_ENGINE_MAX_FRAMES_PER_TICK

/// \} End of configuration macros

/// \copybrief RUNE_MAX_TICK_RATE
/// \see `RUNE_MAX_TICK_RATE`
inline constexpr double max_tick_rate = RUNE_MAX_TICK_RATE;

/// \copybrief RUNE_ENGINE_MAX_FRAMES_PER_TICK
/// \see `RUNE_ENGINE_MAX_FRAMES_PER_TICK`
inline constexpr int engine_max_frames_per_tick = RUNE_ENGINE_MAX_FRAMES_PER_TICK;

/**
 * \brief Returns the tick rate used by the game loop.
 *
 * \details The tick rate is determined by comparing the refresh rate of the primary
 * screen and the maximum tick rate, and selecting the minimum value.
 *
 * \return the tick rate used by the game loop.
 *
 * \see `max_tick_rate`
 * \see `RUNE_MAX_TICK_RATE`
 */
[[nodiscard]] inline auto tick_rate() -> double
{
  return min(max_tick_rate, static_cast<double>(cen::screen::refresh_rate().value()));
}

template <typename Game, typename Graphics>
class engine;

/**
 * \class semi_fixed_game_loop
 *
 * \brief Represents a "semi-fixed" game loop, that strives to use a fixed delta, but it
 * can be adjusted dynamically for a few frames at a time.
 *
 * \details The game loop will use a tick rate that depends on the refresh rate of the
 * current monitor, but the tick rate is limited to be at most `max_tick_rate`, see
 * `tick_rate()` for more information.
 *
 * \tparam Game the game type.
 * \tparam Graphics the graphics context type.
 *
 * \see `tick_rate()`
 * \see `max_tick_rate`
 * \see `engine_max_frames_per_tick`
 *
 * \since 0.1.0
 */
template <typename Game, typename Graphics>
class semi_fixed_game_loop
{
 public:
  using game_type = Game;
  using graphics_type = Graphics;
  using engine_type = engine<game_type, graphics_type>;
  using seconds_type = cen::seconds<double>;

  explicit semi_fixed_game_loop(engine_type* engine)
      : m_engine{engine}
      , m_rate{tick_rate()}
      , m_delta{1.0 / m_rate}
      , m_current{cen::counter::now_in_seconds<double>()}
  {
    if (!m_engine)
    {
      throw rune_error{"Cannot create semi_fixed_game_loop from null engine!"};
    }
  }

  void fetch_current_time() noexcept
  {
    m_current = cen::counter::now_in_seconds<double>();
  }

  void tick()
  {
    const auto newTime = cen::counter::now_in_seconds<double>();
    auto frameTime = newTime - m_current;

    m_current = newTime;
    auto nSteps = 0;

    while (frameTime > seconds_type::zero())
    {
      if (nSteps > engine_max_frames_per_tick)
      {
        break;  // avoids spiral-of-death by limiting maximum amount of steps
      }

      m_running = m_engine->update_input();
      if (!m_running)
      {
        break;
      }

      const auto dt = rune::min(frameTime, m_delta);
      m_engine->update_logic(static_cast<delta_time>(dt.count()));

      frameTime -= dt;

      ++nSteps;
    }
  }

  [[nodiscard]] auto is_running() const noexcept -> bool
  {
    return m_running;
  }

 private:
  engine_type* m_engine{};
  double m_rate;
  seconds_type m_delta;
  seconds_type m_current;
  bool m_running{true};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_SEMI_FIXED_GAME_LOOP_HPP


namespace rune {

/// \addtogroup core
/// \{

// clang-format off

template <typename T>
concept is_configuration_type = requires
{
  { T::renderer_flags } -> std::convertible_to<uint32>;
  { T::window_size } -> std::convertible_to<cen::iarea>;
};

// clang-format on

/**
 * \struct configuration
 *
 * \brief Provides configuration options for different engine aspects.
 *
 * \note Members are initialized to their default values, meaning that you do not have to
 * assign each member if you create custom configurations.
 *
 * \see `engine`
 */
struct configuration
{
  uint32 renderer_flags = cen::renderer::default_flags();
  cen::iarea window_size = cen::window::default_size();
};

static_assert(is_configuration_type<configuration>);

/**
 * \class engine
 *
 * \brief Represents the core engine in the framework.
 *
 * \details The easiest way to set up your game is to use either of
 * `RUNE_IMPLEMENT_MAIN_WITH_GAME` or `RUNE_IMPLEMENT_MAIN_WITH_ENGINE` to automatically
 * generate a correct definition of the `main` function.
 *
 * \details Alternatively, you could manually initialize an `engine` instance with your
 * game and graphics types and call the `engine::run()` function to start your game.
 * However, remember to initialize Centurion _before_ creating your engine instance!
 *
 * \details It is perfectly valid to derive from this class, which enables easy access to
 * the game window, graphics context, input state, etc.
 *
 * \details The game class must either be default-constructible or provide a constructor
 * that accepts `graphics_type&`.
 *
 * \tparam Game the type of the game class.
 * \tparam Graphics the type of the graphics context.
 *
 * \see `game_base`
 * \see `graphics`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_ENGINE`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_GAME`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_GAME_AND_GRAPHICS`
 *
 * \since 0.1.0
 */
template <typename Game, typename Graphics = graphics>
class engine
{
  // To be able to access update_logic and update_input
  friend class semi_fixed_game_loop<Game, Graphics>;

 public:
  using game_type = Game;          ///< Game class type.
  using graphics_type = Graphics;  ///< Graphics context type.
  using loop_type = semi_fixed_game_loop<game_type, graphics_type>;  ///< Game loop type.

  static_assert(std::constructible_from<game_type, graphics_type&> ||
                    std::default_initializable<game_type>,
                "Game class must either be default constructible or provide a "
                "constructor that accepts \"graphics_type&\"");

  /**
   * \brief Creates an engine instance.
   *
   * \param cfg optional custom configuration of the engine.
   */
  explicit engine(const configuration& cfg = default_cfg())
      : m_loop{this}
      , m_window{"Rune", cfg.window_size}
      , m_graphics{m_window, cfg.renderer_flags}
  {
    if constexpr (std::constructible_from<game_type, graphics_type&>)
    {
      m_game.emplace(m_graphics);
    }
    else
    {
      m_game.emplace();
    }

    m_game->init(m_graphics);
  }

  /**
   * \brief Starts the game loop and runs the game.
   *
   * \return always `0`.
   */
  auto run() -> int
  {
    assert(m_game);

    m_window.show();
    m_loop.fetch_current_time();

    m_game->on_start();

    auto& renderer = m_graphics.renderer();
    while (m_loop.is_running())
    {
      m_loop.tick();
      m_game->render(m_graphics);
    }

    m_game->on_exit();
    m_window.hide();

    return 0;
  }

  /**
   * \brief Returns the associated game window.
   *
   * \return the associated window.
   */
  [[nodiscard]] auto get_window() noexcept -> cen::window&
  {
    return m_window;
  }

  /// \copydoc get_window()
  [[nodiscard]] auto get_window() const noexcept -> const cen::window&
  {
    return m_window;
  }

  /**
   * \brief Returns the associated game instance.
   *
   * \return the game instance.
   */
  [[nodiscard]] auto get_game() -> game_type&
  {
    assert(m_game);
    return *m_game;
  }

  /// \copydoc get_game()
  [[nodiscard]] auto get_game() const -> const game_type&
  {
    assert(m_game);
    return *m_game;
  }

  /**
   * \brief Returns the associated graphics context.
   *
   * \return the graphics context.
   */
  [[nodiscard]] auto get_graphics() noexcept -> graphics_type&
  {
    return m_graphics;
  }

  /// \copydoc get_graphics()
  [[nodiscard]] auto get_graphics() const noexcept -> const graphics_type&
  {
    return m_graphics;
  }

  /**
   * \brief Returns the current input state.
   *
   * \return the input state.
   */
  [[nodiscard]] auto get_input() noexcept -> input&
  {
    return m_input;
  }

  /// \copydoc get_input()
  [[nodiscard]] auto get_input() const noexcept -> const input&
  {
    return m_input;
  }

  /**
   * \brief Returns the default configuration used by the engine, if no custom
   * configuration is requested.
   *
   * \return the default engine configuration.
   */
  [[nodiscard]] constexpr static auto default_cfg() -> configuration
  {
    return configuration{};
  }

 private:
  loop_type m_loop;          ///< The game loop.
  cen::window m_window;      ///< The associated window.
  graphics_type m_graphics;  ///< The graphics context.
  input m_input;             ///< The input state wrapper.
  maybe<game_type> m_game;   ///< The game instance, optional to delay construction.

  void update_logic(const delta_time dt)
  {
    m_game->tick(dt);
  }

  auto update_input() -> bool
  {
    const auto& renderer = m_graphics.renderer();
    m_input.mouse.set_logical_size(renderer.logical_size());
    m_input.mouse.update(renderer.output_size());
    m_input.keyboard.update();

    cen::event::update();

    m_game->handle_input(m_input);

    return !m_game->should_quit() && !cen::event::in_queue(cen::event_type::quit);
  }
};

#define RUNE_IMPLEMENT_MAIN_WITH_ENGINE(Engine) \
  int main(int, char**)                         \
  {                                             \
    cen::library centurion;                     \
    Engine engine;                              \
    return engine.run();                        \
  }

#define RUNE_IMPLEMENT_MAIN_WITH_GAME(Game)    \
  int main(int, char**)                        \
  {                                            \
    cen::library centurion;                    \
    rune::engine<Game, rune::graphics> engine; \
    return engine.run();                       \
  }

#define RUNE_IMPLEMENT_MAIN_WITH_GAME_AND_GRAPHICS(Game, Graphics) \
  int main(int, char**)                                            \
  {                                                                \
    cen::library centurion;                                        \
    rune::engine<Game, Graphics> engine;                           \
    return engine.run();                                           \
  }

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_ENGINE_HPP

// #include "core/from_string.hpp"
#ifndef RUNE_CORE_FROM_STRING_HPP
#define RUNE_CORE_FROM_STRING_HPP

#include <charconv>      // from_chars
#include <string_view>   // string_view
#include <system_error>  // errc

// #include "../aliases/maybe.hpp"


namespace rune {

/// \addtogroup core
/// \{

template <typename T>
[[nodiscard]] auto from_string(const std::string_view str, const int base = 10)
    -> maybe<T>
{
  T value{};

  const auto [ptr, error] =
      std::from_chars(str.data(), str.data() + str.size(), value, base);
  if (error != std::errc::invalid_argument && error != std::errc::result_out_of_range)
  {
    return value;
  }
  else
  {
    return nothing;
  }
}

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_FROM_STRING_HPP

// #include "core/game.hpp"
#ifndef RUNE_CORE_GAME_HPP
#define RUNE_CORE_GAME_HPP

#include <concepts>  // derived_from

// #include "aliases/delta_time.hpp"

// #include "core/graphics.hpp"

// #include "core/input.hpp"


namespace rune {

/// \addtogroup core
/// \{

/**
 * \class game_base
 *
 * \brief The base class for all game class implementations.
 *
 * \details You should derive your game class from this class, which you then supply to
 * your engine instance.
 *
 * \details The following example illustrates a skeleton for a game using the Rune
 * framework. Note, no virtual functions are pure, i.e. you only have to override the
 * functions that you need in your own game class.
 *
 * \note Whilst this class is stateless and default-constructible, the `engine` class
 * expects game classes to be either default-constructible or constructible from a
 * reference to a graphics context.
 *
 * \code{cpp}
 * #include <rune.hpp>
 *
 * class AwesomeGame final : public rune::game_base
 * {
 *  public:
 *   explicit AwesomeGame(graphics_type& graphics)
 *   {
 *     // ...
 *   }
 *
 *   void handle_input(const rune::input& input) override
 *   {
 *     // ...
 *   }
 *
 *   void tick(rune::delta_time dt) override
 *   {
 *     // ...
 *   }
 *
 *   void render(graphics_type& graphics) const override
 *   {
 *     // ...
 *   }
 *
 *   [[nodiscard]] bool should_quit() const override
 *   {
 *     // ...
 *   }
 * };
 *
 * RUNE_IMPLEMENT_MAIN_WITH_GAME(AwesomeGame)
 * \endcode
 *
 * \see `game_base`
 * \see `engine`
 * \see `graphics`
 * \see `input`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_GAME`
 * \see `RUNE_IMPLEMENT_MAIN_WITH_ENGINE`
 *
 * \since 0.1.0
 */
template <std::derived_from<graphics> Graphics>
class basic_game
{
 public:
  using graphics_type = Graphics;

  virtual ~basic_game() noexcept = default;

  /**
   * \brief Initializes the game state.
   *
   * \details This function is called just after the game class is constructed. A use case
   * for this function could be if you do not want to provide a constructor in your game
   * class that accepts a graphics context by reference.
   *
   * \param gfx the associated graphics context.
   *
   * \since 0.1.0
   */
  virtual void init(graphics_type& gfx)
  {}

  /**
   * \brief Invoked just before the game starts running.
   *
   * \details This function is guaranteed to only be called once just before the game loop
   * starts running.
   *
   * \since 0.1.0
   */
  virtual void on_start()
  {}

  /**
   * \brief Invoked just before the game stops running.
   *
   * \details This function is guaranteed to only be called once just after the game loop
   * has finished running, i.e. just before the game shuts down.
   *
   * \since 0.1.0
   */
  virtual void on_exit()
  {}

  /**
   * \brief Handles the current input state.
   *
   * \details This function is called each frame and is meant to handle user input.
   *
   * \details This function is called each frame _before_ both `tick()` and `render()`.
   *
   * \param input the current input state.
   *
   * \since 0.1.0
   */
  virtual void handle_input(const input& input)
  {}

  /**
   * \brief Updates the state of the game by one frame according to the delta.
   *
   * \details This function updates the core logic of the game.
   *
   * \details This function is called each frame _after_ `handle_input()` and _before_
   * `render()`.
   *
   * \param dt the current delta time, in seconds.
   *
   * \since 0.1.0
   */
  virtual void tick(delta_time dt)
  {}

  /**
   * \brief Renders the current game state.
   *
   * \details This function is called each frame _after_ both `handle_input()` and
   * `tick()`.
   *
   * \details If you've specified a custom graphics context type (that must derive from
   * `graphics`), then you can safely downcast the supplied graphics context using
   * `dynamic_cast` (or even `static_cast`, the engine is guaranteed to use your graphics
   * context type if specified).
   *
   * \note Remember to clear the rendering target and present your draw commands at the
   * beginning and end of your rendering function, respectively.
   *
   * \param gfx the graphics context used for rendering.
   *
   * \since 0.1.0
   */
  virtual void render(graphics_type& gfx) const
  {}

  /**
   * \brief Indicates whether or not the game should stop running.
   *
   * \details By default, this function returns `true`.
   *
   * \return `true` if the game should stop running; `false` otherwise.
   *
   * \since 0.1.0
   */
  [[nodiscard]] virtual auto should_quit() const -> bool
  {
    return false;
  }
};

using game_base = basic_game<graphics>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GAME_HPP
// #include "core/iterable.hpp"
#ifndef RUNE_CORE_ITERABLE_HPP
#define RUNE_CORE_ITERABLE_HPP

#include <algorithm>  // for_each

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

template <typename T, typename Elem>
concept iterable = requires (T obj)
{
  { std::ranges::for_each(obj, [](const Elem& elem) {}) };
};

// clang-format on

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_ITERABLE_HPP

// #include "core/rune_error.hpp"
#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

// #include "../aliases/str.hpp"


namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const str what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> str override
  {
    return m_what;
  }

 private:
  str m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP

// #include "core/semi_fixed_game_loop.hpp"
#ifndef RUNE_CORE_SEMI_FIXED_GAME_LOOP_HPP
#define RUNE_CORE_SEMI_FIXED_GAME_LOOP_HPP

#include <centurion.hpp>  // ...
#include <concepts>       // floating_point, derived_from

// #include "../aliases/delta_time.hpp"

// #include "../math/min.hpp"

// #include "game.hpp"

// #include "rune_error.hpp"


namespace rune {

/// \addtogroup core
/// \{

/// \name Configuration macros
/// \{

/**
 * \def RUNE_MAX_TICK_RATE
 *
 * \brief The maximum tick rate of the game loop, i.e. the maximum amount of ticks per
 * second.
 *
 * \details The game loop will try to run at the refresh rate of the primary screen, as
 * long as the the refresh rate isn't greater than the value of this macro. By default,
 * this macro expands to `120.0`.
 *
 * \note The value of this macro should be a `double`.
 */
#ifndef RUNE_MAX_TICK_RATE
#define RUNE_MAX_TICK_RATE 120.0
#endif  // RUNE_MAX_TICK_RATE

/**
 * \def RUNE_ENGINE_MAX_FRAMES_PER_TICK
 *
 * \brief The maximum amount of frames that the game loop can run per tick.
 *
 * \details The purpose of this limit is to avoid the "spiral-of-death". By default, this
 * macro expands to `5`.
 *
 * \note The value of this macro should be an `int`.
 */
#ifndef RUNE_ENGINE_MAX_FRAMES_PER_TICK
#define RUNE_ENGINE_MAX_FRAMES_PER_TICK 5
#endif  // RUNE_ENGINE_MAX_FRAMES_PER_TICK

/// \} End of configuration macros

/// \copybrief RUNE_MAX_TICK_RATE
/// \see `RUNE_MAX_TICK_RATE`
inline constexpr double max_tick_rate = RUNE_MAX_TICK_RATE;

/// \copybrief RUNE_ENGINE_MAX_FRAMES_PER_TICK
/// \see `RUNE_ENGINE_MAX_FRAMES_PER_TICK`
inline constexpr int engine_max_frames_per_tick = RUNE_ENGINE_MAX_FRAMES_PER_TICK;

/**
 * \brief Returns the tick rate used by the game loop.
 *
 * \details The tick rate is determined by comparing the refresh rate of the primary
 * screen and the maximum tick rate, and selecting the minimum value.
 *
 * \return the tick rate used by the game loop.
 *
 * \see `max_tick_rate`
 * \see `RUNE_MAX_TICK_RATE`
 */
[[nodiscard]] inline auto tick_rate() -> double
{
  return min(max_tick_rate, static_cast<double>(cen::screen::refresh_rate().value()));
}

template <typename Game, typename Graphics>
class engine;

/**
 * \class semi_fixed_game_loop
 *
 * \brief Represents a "semi-fixed" game loop, that strives to use a fixed delta, but it
 * can be adjusted dynamically for a few frames at a time.
 *
 * \details The game loop will use a tick rate that depends on the refresh rate of the
 * current monitor, but the tick rate is limited to be at most `max_tick_rate`, see
 * `tick_rate()` for more information.
 *
 * \tparam Game the game type.
 * \tparam Graphics the graphics context type.
 *
 * \see `tick_rate()`
 * \see `max_tick_rate`
 * \see `engine_max_frames_per_tick`
 *
 * \since 0.1.0
 */
template <typename Game, typename Graphics>
class semi_fixed_game_loop
{
 public:
  using game_type = Game;
  using graphics_type = Graphics;
  using engine_type = engine<game_type, graphics_type>;
  using seconds_type = cen::seconds<double>;

  explicit semi_fixed_game_loop(engine_type* engine)
      : m_engine{engine}
      , m_rate{tick_rate()}
      , m_delta{1.0 / m_rate}
      , m_current{cen::counter::now_in_seconds<double>()}
  {
    if (!m_engine)
    {
      throw rune_error{"Cannot create semi_fixed_game_loop from null engine!"};
    }
  }

  void fetch_current_time() noexcept
  {
    m_current = cen::counter::now_in_seconds<double>();
  }

  void tick()
  {
    const auto newTime = cen::counter::now_in_seconds<double>();
    auto frameTime = newTime - m_current;

    m_current = newTime;
    auto nSteps = 0;

    while (frameTime > seconds_type::zero())
    {
      if (nSteps > engine_max_frames_per_tick)
      {
        break;  // avoids spiral-of-death by limiting maximum amount of steps
      }

      m_running = m_engine->update_input();
      if (!m_running)
      {
        break;
      }

      const auto dt = rune::min(frameTime, m_delta);
      m_engine->update_logic(static_cast<delta_time>(dt.count()));

      frameTime -= dt;

      ++nSteps;
    }
  }

  [[nodiscard]] auto is_running() const noexcept -> bool
  {
    return m_running;
  }

 private:
  engine_type* m_engine{};
  double m_rate;
  seconds_type m_delta;
  seconds_type m_current;
  bool m_running{true};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_SEMI_FIXED_GAME_LOOP_HPP

// #include "ecs/ecs_utils.hpp"
#ifndef RUNE_ECS_ECS_UTILS_HPP
#define RUNE_ECS_ECS_UTILS_HPP

#include <entt.hpp>  // registry, entity

// #include "../core/iterable.hpp"
#ifndef RUNE_CORE_ITERABLE_HPP
#define RUNE_CORE_ITERABLE_HPP

#include <algorithm>  // for_each

namespace rune {

/// \addtogroup core
/// \{

// clang-format off

template <typename T, typename Elem>
concept iterable = requires (T obj)
{
  { std::ranges::for_each(obj, [](const Elem& elem) {}) };
};

// clang-format on

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_ITERABLE_HPP


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \brief Destroys all entities in a container and subsequently clears the container.
 *
 * \tparam T the type of the container.
 *
 * \param registry the registry that the entities belongs to.
 * \param container the container that will be cleared.
 *
 * \since 0.1.0
 */
template <iterable<entt::entity> T>
void destroy_and_clear(entt::registry& registry, T& container)
{
  for (const auto entity : container)
  {
    registry.destroy(entity);
  }

  container.clear();
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_ECS_UTILS_HPP

// #include "ecs/entity_type.hpp"
#ifndef RUNE_ECS_ENTITY_TYPE_HPP
#define RUNE_ECS_ENTITY_TYPE_HPP

#include <entt.hpp>   // entity
#include <nenya.hpp>  // strong_type

namespace rune {

/**
 * \typedef entity_type
 *
 * \brief Alias for creating strong types with `entt::entity` as the underlying type.
 *
 * \ingroup ecs
 *
 * \tparam T the unique tag type for the strong type alias.
 *
 * \see `null()`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
using entity_type = nenya::strong_type<entt::entity, T>;

}  // namespace rune

#endif  // RUNE_ECS_ENTITY_TYPE_HPP

// #include "ecs/events/button_pressed_event.hpp"
#ifndef RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP
#define RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP

// #include "../../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../null_entity.hpp"
#ifndef RUNE_ECS_NULL_ENTITY_HPP
#define RUNE_ECS_NULL_ENTITY_HPP

#include <concepts>  // constructible_from
#include <entt.hpp>  // entity, null

namespace rune {

/// \addtogroup ecs
/// \{

// clang-format off

/**
 * \brief Returns a null entity identifier for a component with an `entity` member type.
 *
 * \tparam T the component with a public `entity` member type (based on `entity_type`).
 *
 * \return a null entity identifier.
 *
 * \see `entity_type`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
[[nodiscard]] constexpr auto null()
    noexcept(noexcept(typename T::entity{entt::entity{entt::null}}))
{
  return typename T::entity{entt::entity{entt::null}};
}

// clang-format on

/**
 * \brief Assigns a null entity identifier to an strong type entity value.
 *
 * \tparam T the strong entity type.
 *
 * \param entity the entity that will be nullified.
 *
 * \see `entity_type`
 * \see `null()`
 *
 * \since 0.1.0
 */
template <std::constructible_from<entt::entity> T>
void nullify(T& entity) noexcept(noexcept(T{entt::entity{entt::null}}))
{
  entity = T{entt::entity{entt::null}};
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_NULL_ENTITY_HPP

// #include "../ui/ui_button.hpp"
#ifndef RUNE_ECS_UI_UI_BUTTON_HPP
#define RUNE_ECS_UI_UI_BUTTON_HPP

#include <centurion.hpp>  // farea, fpoint

// #include "../../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "../entity_type.hpp"
#ifndef RUNE_ECS_ENTITY_TYPE_HPP
#define RUNE_ECS_ENTITY_TYPE_HPP

#include <entt.hpp>   // entity
#include <nenya.hpp>  // strong_type

namespace rune {

/**
 * \typedef entity_type
 *
 * \brief Alias for creating strong types with `entt::entity` as the underlying type.
 *
 * \ingroup ecs
 *
 * \tparam T the unique tag type for the strong type alias.
 *
 * \see `null()`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
using entity_type = nenya::strong_type<entt::entity, T>;

}  // namespace rune

#endif  // RUNE_ECS_ENTITY_TYPE_HPP


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_button_tag;
}  // namespace tags

/**
 * \struct ui_button
 *
 * \brief A component that represents a UI button, i.e. a control that can be pressed.
 *
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 * \see `serialize(auto&, ui_button&)`
 *
 * \since 0.1.0
 */
struct ui_button final
{
  using entity = entity_type<tags::ui_button_tag>;

  uint32 id{};                             ///< User-defined identifier.
  mutable maybe<cen::fpoint> text_offset;  ///< Lazily initialized offset for the label.
  mutable maybe<cen::farea> size;          ///< Lazily initialized button size.
  bool is_enabled{true};   ///< Is the button enabled, i.e. can it be pressed?
  bool is_visible{true};   ///< Is the button visible?
  bool is_hovered{false};  ///< Is the button currently hovered?
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_button& b)
{
  archive(b.id, b.text_offset, b.size, b.is_enabled, b.is_visible, b.is_hovered);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BUTTON_HPP


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct button_pressed_event
 *
 * \brief An event that is emitted whenever a button is pressed.
 *
 * \since 0.1.0
 */
struct button_pressed_event final
{
  ui_button::entity button_entity{null<ui_button>()};  ///< The pressed button entity.
  uint32 id{};                                         ///< The button ID.
};

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP

// #include "ecs/events/key_bind_triggered_event.hpp"
#ifndef RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP
#define RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP

// #include "../../aliases/integers.hpp"

// #include "../null_entity.hpp"

// #include "../ui/ui_key_bind.hpp"
#ifndef RUNE_ECS_UI_UI_KEY_BIND_HPP
#define RUNE_ECS_UI_UI_KEY_BIND_HPP

#include <centurion.hpp>  // scan_code

// #include "../../aliases/integers.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_keybind_tag;
}  // namespace tags

/**
 * \struct ui_key_bind
 *
 * \brief A component that represents a key bind, that emits an event when triggered.
 *
 * \see `ui::make_key_bind()`
 * \see `serialize(auto&, ui_key_bind&)`
 *
 * \since 0.1.0
 */
struct ui_key_bind final
{
  using entity = entity_type<tags::ui_keybind_tag>;

  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The associated key modifiers.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_key_bind& bind)
{
  archive(bind.id, bind.key, bind.modifiers);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_KEY_BIND_HPP


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct key_bind_triggered_event
 *
 * \brief An event that is emitted whenever a key bind is triggered.
 *
 * \since 0.1.0
 */
struct key_bind_triggered_event final
{
  ui_key_bind::entity entity{null<ui_key_bind>()};  ///< The key bind entity.
  uint32 id{};                                      ///< The key bind ID.
};

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP

// #include "ecs/null_entity.hpp"
#ifndef RUNE_ECS_NULL_ENTITY_HPP
#define RUNE_ECS_NULL_ENTITY_HPP

#include <concepts>  // constructible_from
#include <entt.hpp>  // entity, null

namespace rune {

/// \addtogroup ecs
/// \{

// clang-format off

/**
 * \brief Returns a null entity identifier for a component with an `entity` member type.
 *
 * \tparam T the component with a public `entity` member type (based on `entity_type`).
 *
 * \return a null entity identifier.
 *
 * \see `entity_type`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
[[nodiscard]] constexpr auto null()
    noexcept(noexcept(typename T::entity{entt::entity{entt::null}}))
{
  return typename T::entity{entt::entity{entt::null}};
}

// clang-format on

/**
 * \brief Assigns a null entity identifier to an strong type entity value.
 *
 * \tparam T the strong entity type.
 *
 * \param entity the entity that will be nullified.
 *
 * \see `entity_type`
 * \see `null()`
 *
 * \since 0.1.0
 */
template <std::constructible_from<entt::entity> T>
void nullify(T& entity) noexcept(noexcept(T{entt::entity{entt::null}}))
{
  entity = T{entt::entity{entt::null}};
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_NULL_ENTITY_HPP

// #include "ecs/ui/button_system.hpp"
#ifndef RUNE_ECS_UI_BUTTON_SYSTEM_HPP
#define RUNE_ECS_UI_BUTTON_SYSTEM_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // mouse, color
#include <entt.hpp>       // registry, dispatcher
#include <string>         // string
#include <utility>        // move

// #include "../../aliases/font_id.hpp"
#ifndef RUNE_ALIASES_FONT_ID_HPP
#define RUNE_ALIASES_FONT_ID_HPP

// #include "integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP


namespace rune {

using font_id = usize;

}  // namespace rune

#endif  // RUNE_ALIASES_FONT_ID_HPP

// #include "../../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "../../core/graphics.hpp"
#ifndef RUNE_CORE_GRAPHICS_HPP
#define RUNE_CORE_GRAPHICS_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // window, renderer, texture, font_cache, pixel_format
#include <string>         // string
#include <unordered_map>  // unordered_map
#include <utility>        // forward
#include <vector>         // vector

// #include "../aliases/font_id.hpp"
#ifndef RUNE_ALIASES_FONT_ID_HPP
#define RUNE_ALIASES_FONT_ID_HPP

// #include "integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP


namespace rune {

using font_id = usize;

}  // namespace rune

#endif  // RUNE_ALIASES_FONT_ID_HPP

// #include "../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../aliases/texture_id.hpp"
#ifndef RUNE_ALIASES_TEXTURE_ID_HPP
#define RUNE_ALIASES_TEXTURE_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct texture_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \def RUNE_TEXTURE_ID_UNDERLYING_TYPE
 *
 * \brief The underlying type of the `texture_id` strong type.
 *
 * \details By default, the underlying type is `usize`.
 *
 * \note The value of this macro must be of a hashable type.
 */
#ifndef RUNE_TEXTURE_ID_UNDERLYING_TYPE
#define RUNE_TEXTURE_ID_UNDERLYING_TYPE usize
#endif  // RUNE_TEXTURE_ID_UNDERLYING_TYPE

/**
 * \typedef texture_id
 *
 * \brief Used as unique identifiers for textures.
 *
 * \details This is used in order to avoid loading the same texture more than once.
 *
 * \see `RUNE_TEXTURE_ID_UNDERLYING_TYPE`
 */
using texture_id =
    nenya::strong_type<RUNE_TEXTURE_ID_UNDERLYING_TYPE, tags::texture_id_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_ID_HPP

// #include "../aliases/texture_index.hpp"
#ifndef RUNE_ALIASES_TEXTURE_INDEX_HPP
#define RUNE_ALIASES_TEXTURE_INDEX_HPP

#include <nenya.hpp>  // strong_type

// #include "integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct texture_index_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \typedef texture_index
 *
 * \brief Strong type for texture indices, used by the `graphics` class.
 */
using texture_index = nenya::strong_type<usize, tags::texture_index_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_INDEX_HPP

// #include "compiler.hpp"
#ifndef RUNE_CORE_COMPILER_HPP
#define RUNE_CORE_COMPILER_HPP

namespace rune {

/// \addtogroup core
/// \{

/// \name Compiler checks
/// \{

/// Indicates whether or not the current compiler is MSVC
[[nodiscard]] consteval auto on_msvc() noexcept -> bool
{
#ifdef _MSC_VER
  return true;
#else
  return false;
#endif  // _MSC_VER
}

/// Indicates whether or not the current compiler is GCC
[[nodiscard]] consteval auto on_gcc() noexcept -> bool
{
#ifdef __GNUC__
  return true;
#else
  return false;
#endif  // __GNUC__
}

/// Indicates whether or not the current compiler is Clang
[[nodiscard]] consteval auto on_clang() noexcept -> bool
{
#ifdef __clang__
  return true;
#else
  return false;
#endif  // __clang__
}

/// \} End of compiler checks

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_COMPILER_HPP


namespace rune {

/// \addtogroup core
/// \{

/**
 * \class graphics
 *
 * \brief Provides the main graphics API.
 *
 * \details This class provides a renderer, efficient texture handling, font caches for
 * efficient text rendering, pixel format information, etc.
 *
 * \details For reduced memory consumption and redundancy in loaded textures, this class
 * manages a collection of textures that are given unique indices when loaded. These
 * indices literally correspond to indices in an array of textures managed by this class,
 * which results in very fast constant complexity lookup of textures.
 *
 * \details It is safe to derive your own custom graphics context classes from this class.
 * However, you then need to supply your custom graphics type as a template parameter to
 * your engine instance.
 *
 * \since 0.1.0
 */
class graphics
{
 public:
  using size_type = usize;

  /**
   * \brief Creates a graphics context.
   *
   * \tparam T the ownership semantics of the window.
   * \param window the associated game window.
   * \param flags the renderer flags supplied to the `cen::renderer` constructor.
   */
  template <typename T>
  graphics(const cen::basic_window<T>& window, const uint32 flags)
      : m_renderer{window, flags}
      , m_format{window.get_pixel_format()}
  {}

  virtual ~graphics() noexcept = default;

  /// \name Texture handling
  /// \{

  /**
   * \brief Reserves enough memory to store the specified amount of textures.
   *
   * \param capacity the new capacity of textures.
   */
  void reserve(const size_type capacity)
  {
    m_textures.reserve(capacity);
  }

  /**
   * \brief Loads a texture and returns the associated index.
   *
   * \details If a texture with the specified ID has already been loaded, then this
   * function does nothing, and just returns the existing texture index.
   *
   * \param id the unique ID of the texture.
   * \param path the file path of the texture.
   *
   * \return the index of the loaded texture.
   */
  auto load(const texture_id id, const std::string& path) -> texture_index
  {
    if (const auto it = m_indices.find(id); it != m_indices.end())
    {
      return it->second;
    }
    else
    {
      const auto index = m_textures.size();

      m_textures.emplace_back(m_renderer, path);
      m_indices.try_emplace(id, index);

      return texture_index{index};
    }
  }

  /**
   * \brief Returns the texture associated with the specified index.
   *
   * \details This function performs a very fast index lookup for finding the associated
   * texture. This function is not bounds checked in optimized builds, but an assertion
   * will abort the execution of the program in debug builds if an invalid index is used.
   *
   * \pre `index` must be associated with an existing texture.
   *
   * \param index the index of the desired texture.
   *
   * \return the texture associated with the index.
   */
  [[nodiscard]] auto at(const texture_index index) const noexcept(on_msvc())
      -> const cen::texture&
  {
    assert(index < m_textures.size());  // texture_index is unsigned
    return m_textures[index];
  }

  /// \copydoc at()
  [[nodiscard]] auto operator[](const texture_index index) const noexcept(on_msvc())
      -> const cen::texture&
  {
    return at(index);
  }

  /**
   * \brief Indicates whether or not a texture index is associated with a texture.
   *
   * \param index the texture index that will be checked.
   *
   * \return `true` if the texture index is associated with a texture; `false` otherwise.
   */
  [[nodiscard]] auto contains(const texture_index index) const noexcept -> bool
  {
    return index < m_textures.size();
  }

  /**
   * \brief Returns the texture index associated with the specified ID.
   *
   * \param id the ID associated with the texture.
   *
   * \return the index of the specified texture.
   *
   * \throws std::out_of_range if the supplied ID isn't associated with an index.
   */
  [[nodiscard]] auto to_index(const texture_id id) const -> texture_index
  {
    return m_indices.at(id);
  }

  /// \} End of texture handling

  /// \name Font cache handling
  /// \{

  /**
   * \brief Adds a font cache to the graphics context.
   *
   * \tparam Args the types of the font cache constructor arguments.
   *
   * \note Any previous font cache associated with the supplied ID is overwritten.
   *
   * \param id the unique ID that will be associated with the font cache.
   * \param args the arguments that will be forwarded to an appropriate font cache
   * constructor.
   */
  template <typename... Args>
  void emplace_cache(const font_id id, Args&&... args)
  {
    m_caches.insert_or_assign(id, cen::font_cache{std::forward<Args>(args)...});
  }

  /**
   * \brief Returns the font cache associated with the specified ID.
   *
   * \param id the ID associated with the desired font cache.
   *
   * \return the found font cache.
   *
   * \throws std::out_of_range if there is no font cache associated with the ID.
   */
  [[nodiscard]] auto get_cache(const font_id id) -> cen::font_cache&
  {
    return m_caches.at(id);
  }

  /// \copydoc get_cache()
  [[nodiscard]] auto get_cache(const font_id id) const -> const cen::font_cache&
  {
    return m_caches.at(id);
  }

  [[nodiscard]] auto get_font(const font_id id) -> cen::font&
  {
    return get_cache(id).get_font();
  }

  [[nodiscard]] auto get_font(const font_id id) const -> const cen::font&
  {
    return get_cache(id).get_font();
  }

  /**
   * \brief Indicates whether or not the graphics context has a font cache associated with
   * the specified ID.
   *
   * \param id the ID that will be checked.
   *
   * \return `true` if there is a font cache associated with the ID; `false` otherwise.
   */
  [[nodiscard]] auto contains_cache(const font_id id) const -> bool
  {
    return m_caches.contains(id);
  }

  /// \} End of font cache handling

  /**
   * \brief Returns the renderer associated with the graphics context.
   *
   * \return the associated renderer.
   */
  [[nodiscard]] auto renderer() noexcept -> cen::renderer&
  {
    return m_renderer;
  }

  /// \copydoc renderer()
  [[nodiscard]] auto renderer() const noexcept -> const cen::renderer&
  {
    return m_renderer;
  }

  /**
   * \brief Returns the pixel format used by the associated window.
   *
   * \return the associated pixel format.
   */
  [[nodiscard]] auto format() const noexcept -> cen::pixel_format
  {
    return m_format;
  }

 private:
  cen::renderer m_renderer;
  cen::pixel_format m_format;
  std::vector<cen::texture> m_textures;
  std::unordered_map<texture_id, texture_index> m_indices;
  std::unordered_map<size_type, cen::font_cache> m_caches;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GRAPHICS_HPP

// #include "../events/button_pressed_event.hpp"
#ifndef RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP
#define RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP

// #include "../../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../null_entity.hpp"
#ifndef RUNE_ECS_NULL_ENTITY_HPP
#define RUNE_ECS_NULL_ENTITY_HPP

#include <concepts>  // constructible_from
#include <entt.hpp>  // entity, null

namespace rune {

/// \addtogroup ecs
/// \{

// clang-format off

/**
 * \brief Returns a null entity identifier for a component with an `entity` member type.
 *
 * \tparam T the component with a public `entity` member type (based on `entity_type`).
 *
 * \return a null entity identifier.
 *
 * \see `entity_type`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
[[nodiscard]] constexpr auto null()
    noexcept(noexcept(typename T::entity{entt::entity{entt::null}}))
{
  return typename T::entity{entt::entity{entt::null}};
}

// clang-format on

/**
 * \brief Assigns a null entity identifier to an strong type entity value.
 *
 * \tparam T the strong entity type.
 *
 * \param entity the entity that will be nullified.
 *
 * \see `entity_type`
 * \see `null()`
 *
 * \since 0.1.0
 */
template <std::constructible_from<entt::entity> T>
void nullify(T& entity) noexcept(noexcept(T{entt::entity{entt::null}}))
{
  entity = T{entt::entity{entt::null}};
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_NULL_ENTITY_HPP

// #include "../ui/ui_button.hpp"
#ifndef RUNE_ECS_UI_UI_BUTTON_HPP
#define RUNE_ECS_UI_UI_BUTTON_HPP

#include <centurion.hpp>  // farea, fpoint

// #include "../../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "../entity_type.hpp"
#ifndef RUNE_ECS_ENTITY_TYPE_HPP
#define RUNE_ECS_ENTITY_TYPE_HPP

#include <entt.hpp>   // entity
#include <nenya.hpp>  // strong_type

namespace rune {

/**
 * \typedef entity_type
 *
 * \brief Alias for creating strong types with `entt::entity` as the underlying type.
 *
 * \ingroup ecs
 *
 * \tparam T the unique tag type for the strong type alias.
 *
 * \see `null()`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
using entity_type = nenya::strong_type<entt::entity, T>;

}  // namespace rune

#endif  // RUNE_ECS_ENTITY_TYPE_HPP


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_button_tag;
}  // namespace tags

/**
 * \struct ui_button
 *
 * \brief A component that represents a UI button, i.e. a control that can be pressed.
 *
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 * \see `serialize(auto&, ui_button&)`
 *
 * \since 0.1.0
 */
struct ui_button final
{
  using entity = entity_type<tags::ui_button_tag>;

  uint32 id{};                             ///< User-defined identifier.
  mutable maybe<cen::fpoint> text_offset;  ///< Lazily initialized offset for the label.
  mutable maybe<cen::farea> size;          ///< Lazily initialized button size.
  bool is_enabled{true};   ///< Is the button enabled, i.e. can it be pressed?
  bool is_visible{true};   ///< Is the button visible?
  bool is_hovered{false};  ///< Is the button currently hovered?
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_button& b)
{
  archive(b.id, b.text_offset, b.size, b.is_enabled, b.is_visible, b.is_hovered);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BUTTON_HPP


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct button_pressed_event
 *
 * \brief An event that is emitted whenever a button is pressed.
 *
 * \since 0.1.0
 */
struct button_pressed_event final
{
  ui_button::entity button_entity{null<ui_button>()};  ///< The pressed button entity.
  uint32 id{};                                         ///< The button ID.
};

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_EVENTS_BUTTON_PRESSED_EVENT_HPP

// #include "../null_entity.hpp"
#ifndef RUNE_ECS_NULL_ENTITY_HPP
#define RUNE_ECS_NULL_ENTITY_HPP

#include <concepts>  // constructible_from
#include <entt.hpp>  // entity, null

namespace rune {

/// \addtogroup ecs
/// \{

// clang-format off

/**
 * \brief Returns a null entity identifier for a component with an `entity` member type.
 *
 * \tparam T the component with a public `entity` member type (based on `entity_type`).
 *
 * \return a null entity identifier.
 *
 * \see `entity_type`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
[[nodiscard]] constexpr auto null()
    noexcept(noexcept(typename T::entity{entt::entity{entt::null}}))
{
  return typename T::entity{entt::entity{entt::null}};
}

// clang-format on

/**
 * \brief Assigns a null entity identifier to an strong type entity value.
 *
 * \tparam T the strong entity type.
 *
 * \param entity the entity that will be nullified.
 *
 * \see `entity_type`
 * \see `null()`
 *
 * \since 0.1.0
 */
template <std::constructible_from<entt::entity> T>
void nullify(T& entity) noexcept(noexcept(T{entt::entity{entt::null}}))
{
  entity = T{entt::entity{entt::null}};
}

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_NULL_ENTITY_HPP

// #include "label_system.hpp"
#ifndef RUNE_ECS_UI_LABEL_SYSTEM_HPP
#define RUNE_ECS_UI_LABEL_SYSTEM_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // color, fpoint, texture
#include <entt.hpp>       // registry
#include <string>         // string
#include <utility>        // move

// #include "../../aliases/font_id.hpp"

// #include "../../core/graphics.hpp"

// #include "../null_entity.hpp"

// #include "ui_button.hpp"
#ifndef RUNE_ECS_UI_UI_BUTTON_HPP
#define RUNE_ECS_UI_UI_BUTTON_HPP

#include <centurion.hpp>  // farea, fpoint

// #include "../../aliases/integers.hpp"

// #include "../../aliases/maybe.hpp"

// #include "../entity_type.hpp"
#ifndef RUNE_ECS_ENTITY_TYPE_HPP
#define RUNE_ECS_ENTITY_TYPE_HPP

#include <entt.hpp>   // entity
#include <nenya.hpp>  // strong_type

namespace rune {

/**
 * \typedef entity_type
 *
 * \brief Alias for creating strong types with `entt::entity` as the underlying type.
 *
 * \ingroup ecs
 *
 * \tparam T the unique tag type for the strong type alias.
 *
 * \see `null()`
 * \see `nullify()`
 *
 * \since 0.1.0
 */
template <typename T>
using entity_type = nenya::strong_type<entt::entity, T>;

}  // namespace rune

#endif  // RUNE_ECS_ENTITY_TYPE_HPP


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_button_tag;
}  // namespace tags

/**
 * \struct ui_button
 *
 * \brief A component that represents a UI button, i.e. a control that can be pressed.
 *
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 * \see `serialize(auto&, ui_button&)`
 *
 * \since 0.1.0
 */
struct ui_button final
{
  using entity = entity_type<tags::ui_button_tag>;

  uint32 id{};                             ///< User-defined identifier.
  mutable maybe<cen::fpoint> text_offset;  ///< Lazily initialized offset for the label.
  mutable maybe<cen::farea> size;          ///< Lazily initialized button size.
  bool is_enabled{true};   ///< Is the button enabled, i.e. can it be pressed?
  bool is_visible{true};   ///< Is the button visible?
  bool is_hovered{false};  ///< Is the button currently hovered?
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_button& b)
{
  archive(b.id, b.text_offset, b.size, b.is_enabled, b.is_visible, b.is_hovered);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BUTTON_HPP

// #include "ui_foreground.hpp"
#ifndef RUNE_ECS_UI_UI_FOREGROUND_HPP
#define RUNE_ECS_UI_UI_FOREGROUND_HPP

#include <centurion.hpp>  // color

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_foreground_tag;
}  // namespace tags

/**
 * \struct ui_foreground
 *
 * \brief A component that represents a foreground color.
 *
 * \see `serialize(auto&, ui_foreground&)`
 *
 * \since 0.1.0
 */
struct ui_foreground final
{
  using entity = entity_type<tags::ui_foreground_tag>;

  cen::color color;  ///< The foreground color.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_foreground& fg)
{
  archive(fg.color);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_FOREGROUND_HPP

// #include "ui_grid.hpp"
#ifndef RUNE_ECS_UI_UI_GRID_HPP
#define RUNE_ECS_UI_UI_GRID_HPP

#include <centurion.hpp>  // fpoint

// #include "ui_position.hpp"
#ifndef RUNE_ECS_UI_UI_POSITION_HPP
#define RUNE_ECS_UI_UI_POSITION_HPP

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_position_tag;
}  // namespace tags

struct ui_position final
{
  using entity = entity_type<tags::ui_position_tag>;

  float row{};
  float col{};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_position& position)
{
  archive(position.row, position.col);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_POSITION_HPP


namespace rune::ui {

/// \addtogroup ecs
/// \{

#ifndef RUNE_MENU_ROW_SIZE
#define RUNE_MENU_ROW_SIZE 10.0f
#endif  // RUNE_MENU_ROW_SIZE

#ifndef RUNE_MENU_COLUMN_SIZE
#define RUNE_MENU_COLUMN_SIZE 10.0f
#endif  // RUNE_MENU_COLUMN_SIZE

inline constexpr float menu_row_size = RUNE_MENU_ROW_SIZE;
inline constexpr float menu_column_size = RUNE_MENU_COLUMN_SIZE;

/// \name Grid functions
/// \{

[[nodiscard]] constexpr auto row_to_y(const float row) noexcept -> float
{
  return row * menu_row_size;
}

[[nodiscard]] constexpr auto column_to_x(const float column) noexcept -> float
{
  return column * menu_column_size;
}

[[nodiscard]] constexpr auto from_grid(const float row, const float column) noexcept
    -> cen::fpoint
{
  return {column_to_x(column), row_to_y(row)};
}

[[nodiscard]] constexpr auto from_grid(const ui_position position) noexcept -> cen::fpoint
{
  return {column_to_x(position.col), row_to_y(position.row)};
}

/// \} End of grid functions

/// \} End of group ecs

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_UI_GRID_HPP

// #include "ui_label.hpp"
#ifndef RUNE_ECS_UI_UI_LABEL_HPP
#define RUNE_ECS_UI_UI_LABEL_HPP

#include <centurion.hpp>  // texture
#include <string>         // string

// #include "../../aliases/font_id.hpp"

// #include "../../aliases/maybe.hpp"

// #include "../entity_type.hpp"

// #include "ui_lazy_texture.hpp"
#ifndef RUNE_ECS_UI_UI_LAZY_TEXTURE_HPP
#define RUNE_ECS_UI_UI_LAZY_TEXTURE_HPP

#include <centurion.hpp>  // surface, texture

// #include "../../aliases/maybe.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_lazy_texture_tag;
}  // namespace tags

/**
 * \struct ui_lazy_texture
 *
 * \brief A component that represents a lazily initialized texture.
 *
 * \see `ui::make_lazy_texture()`
 *
 * \since 0.1.0
 */
struct ui_lazy_texture final
{
  using entity = entity_type<tags::ui_lazy_texture_tag>;

  cen::surface source;                  ///< The source image data.
  mutable maybe<cen::texture> texture;  ///< Lazily initialized texture.
};

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LAZY_TEXTURE_HPP


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_label_tag;
struct ui_label_shadow_tag;
}  // namespace tags

/**
 * \struct ui_label
 *
 * \brief A component that represents a UI label.
 *
 * \see `ui::make_label()`
 * \see `serialize(auto&, ui_label&)`
 *
 * \since 0.1.0
 */
struct ui_label final
{
  using entity = entity_type<tags::ui_label_tag>;

  std::string text;                     ///< The label text.
  font_id font{};                       ///< The associated font ID.
  mutable maybe<cen::texture> texture;  ///< Lazily initialized label texture.
};

/**
 * \struct ui_label_shadow
 *
 * \brief A component that represents a UI label shadow.
 *
 * \see `serialize(auto&, ui_label_shadow&)`
 *
 * \since 0.1.0
 */
struct ui_label_shadow final
{
  using entity = entity_type<tags::ui_label_shadow_tag>;

  mutable maybe<cen::texture> texture;  ///< Lazily initialized shadow texture.
  int offset{1};                        ///< The shadow offset.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_label& label)
{
  archive(label.text, label.font);
}

void serialize(auto& archive, ui_label_shadow& shadow)
{
  archive(shadow.offset);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LABEL_HPP

// #include "ui_menu.hpp"
#ifndef RUNE_ECS_UI_UI_MENU_HPP
#define RUNE_ECS_UI_UI_MENU_HPP

// #include "../../aliases/integers.hpp"

// #include "../entity_type.hpp"

// #include "../null_entity.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_menu_tag;
}  // namespace tags

/**
 * \struct ui_menu
 *
 * \brief A component that represents a UI menu.
 *
 * \see `ui::make_menu()`
 * \see `serialize(auto&, ui_menu&)`
 *
 * \since 0.1.0
 */
struct ui_menu final
{
  using entity = entity_type<tags::ui_menu_tag>;

  uint32 id{};         ///< User-defined identifier.
  bool is_blocking{};  ///< Does the menu block game logic updates?
};

struct active_menu final
{
  ui_menu::entity menu_entity{null<ui_menu>()};
};

struct in_menu final
{
  ui_menu::entity menu_entity{null<ui_menu>()};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_menu& menu)
{
  archive(menu.id, menu.is_blocking);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_MENU_HPP

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_label_cfg
 *
 * \brief Configuration used when creating label entities.
 *
 * \see `ui::add_label()`
 * \see `ui::make_label()`
 *
 * \since 0.1.0
 */
struct ui_label_cfg final
{
  ui_position position;                  ///< The position of the label.
  std::string text;                      ///< The label text.
  font_id font{};                        ///< The ID of the associated font.
  cen::color color{cen::colors::white};  ///< The label color.
  bool shadow{};                         ///< Does the label have a shadow?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Adds label components to an existing entity.
 *
 * \details The supplied entity will have the following components added to it.
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_label_cfg::shadow` is `true`)
 * - `ui_position`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry in which the supplied entity belongs to.
 * \param menu the host menu entity.
 * \param entity the entity to which label components will be added.
 * \param cfg the label configuration that will be used.
 *
 * \see `make_label()`
 *
 * \since 0.1.0
 */
inline void add_label(entt::registry& registry,
                      const ui_menu::entity menu,
                      const entt::entity entity,
                      ui_label_cfg cfg)
{
  registry.emplace<in_menu>(entity, menu);

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.text);
  label.font = cfg.font;

  registry.emplace<ui_position>(entity, cfg.position);
  registry.emplace<ui_foreground>(entity, cfg.color);

  if (cfg.shadow)
  {
    registry.emplace<ui_label_shadow>(entity);
  }
}

/**
 * \brief Creates a new label entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_label_cfg::shadow` is `true`)
 * - `ui_position`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry to which a label entity will be added.
 * \param menu the host menu entity.
 * \param cfg the label configuration that will be used.
 *
 * \return the created label entity.
 *
 * \see `add_label()`
 *
 * \since 0.1.0
 */
inline auto make_label(entt::registry& registry,
                       const ui_menu::entity menu,
                       ui_label_cfg cfg) -> ui_label::entity
{
  const auto entity = ui_label::entity{registry.create()};

  add_label(registry, menu, entity, std::move(cfg));

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

[[nodiscard]] inline auto render_text(graphics& gfx,
                                      const ui_label& label,
                                      const cen::color& color) -> cen::texture
{
  auto& renderer = gfx.renderer();
  renderer.set_color(color);

  const auto& font = gfx.get_font(label.font);
  return renderer.render_blended_utf8(label.text, font);
}

inline void render_label(graphics& gfx,
                         const ui_label& label,
                         const cen::fpoint& position,
                         const cen::color& fg)
{
  auto& renderer = gfx.renderer();

  if (!label.texture)
  {
    label.texture = render_text(gfx, label, fg);
  }

  assert(label.texture);
  renderer.render(*label.texture, position);
}

inline void render_shadow(graphics& gfx,
                          const ui_label& label,
                          const ui_label_shadow& shadow,
                          const cen::fpoint& position)
{
  if (!shadow.texture)
  {
    shadow.texture = render_text(gfx, label, cen::colors::black);
  }

  assert(shadow.texture);
  const cen::fpoint offset{static_cast<float>(shadow.offset),
                           static_cast<float>(shadow.offset)};
  gfx.renderer().render(*shadow.texture, position + offset);
}

inline void render_labels(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  const auto filter = entt::exclude<ui_button>;
  for (auto&& [entity, label, position, fg, inMenu] :
       registry.view<ui_label, ui_position, ui_foreground, in_menu>(filter).each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      if (const auto* shadow = registry.try_get<ui_label_shadow>(entity))
      {
        render_shadow(gfx, label, *shadow, from_grid(position));
      }

      render_label(gfx, label, from_grid(position), fg.color);
    }
  }
}

inline void render_button_labels(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  for (auto&& [entity, button, label, position, fg, inMenu] :
       registry.view<ui_button, ui_label, ui_position, ui_foreground, in_menu>().each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      const auto textPos = from_grid(position) + button.text_offset.value();

      if (const auto* shadow = registry.try_get<ui_label_shadow>(entity))
      {
        render_shadow(gfx, label, *shadow, textPos);
      }

      render_label(gfx, label, textPos, fg.color);
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace ui

}  // namespace rune

#endif  // RUNE_ECS_UI_LABEL_SYSTEM_HPP

// #include "ui_button.hpp"

// #include "ui_checkbox.hpp"
#ifndef RUNE_ECS_UI_CHECKBOX_HPP
#define RUNE_ECS_UI_CHECKBOX_HPP

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_checkbox_tag;
}  // namespace tags

/**
 * \struct ui_checkbox
 *
 * \brief A component that represents a UI button, i.e. a control that can be pressed.
 *
 * \see `serialize(auto&, ui_checkbox&)`
 *
 * \since 0.1.0
 */
struct ui_checkbox final
{
  using entity = entity_type<tags::ui_checkbox_tag>;

  bool is_checked{};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_checkbox& cb)
{
  archive(cb.is_checked);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_CHECKBOX_HPP

// #include "ui_foreground.hpp"

// #include "ui_grid.hpp"

// #include "ui_label.hpp"

// #include "ui_menu.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_button_cfg
 *
 * \brief Configuration used when creating button entities.
 *
 * \see `ui_button`
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 *
 * \since 0.1.0
 */
struct ui_button_cfg final
{
  ui_position position;               ///< The position of the button.
  std::string text;                   ///< The button label text.
  uint32 id{};                        ///< User-defined button identifier.
  font_id font{};                     ///< The font used by the label.
  cen::color fg{cen::colors::white};  ///< The label color.
  bool shadow{};                      ///< Should the label feature a shadow?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Adds button components to an existing entity.
 *
 * \details The supplied entity will have the following components added to it.
 * - `ui_button`
 * - `ui_position`
 * - `ui_foreground`
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_button_cfg::shadow` is `true`)
 * - `in_menu`
 *
 * \param registry the registry in which the supplied entity belongs to.
 * \param menu the host menu entity.
 * \param entity the entity to which button components will be added.
 * \param cfg the button configuration that will be used.
 *
 * \since 0.1.0
 */
inline void add_button(entt::registry& registry,
                       ui_menu::entity menu,
                       entt::entity entity,
                       ui_button_cfg cfg)
{
  auto& button = registry.emplace<ui_button>(entity);
  button.id = cfg.id;

  add_label(registry,
            menu,
            entity,
            {.position = cfg.position,
             .text = std::move(cfg.text),
             .font = cfg.font,
             .color = cfg.fg,
             .shadow = cfg.shadow});
}

/**
 * \brief Creates a new button entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_button`
 * - `ui_position`
 * - `ui_foreground`
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_button_cfg::shadow` is `true`)
 * - `in_menu`
 *
 * \param registry the registry to which a button entity will be added.
 * \param menu the host menu entity.
 * \param cfg the button configuration that will be used.
 *
 * \return the created button entity.
 *
 * \see `ui_button_cfg`
 * \see `add_button()`
 *
 * \since 0.1.0
 */
inline auto make_button(entt::registry& registry, ui_menu::entity menu, ui_button_cfg cfg)
    -> ui_button::entity
{
  const auto entity = ui_button::entity{registry.create()};

  add_button(registry, menu, entity, std::move(cfg));

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

[[nodiscard]] inline auto query_button(entt::registry& registry,
                                       entt::dispatcher& dispatcher,
                                       ui_button::entity entity,
                                       const cen::mouse& mouse) -> bool
{
  auto& button = registry.get<ui_button>(entity);
  if (button.is_enabled && button.is_hovered)
  {
    // TODO enable_cursor

    if (mouse.was_left_button_released())
    {
      dispatcher.trigger<button_pressed_event>(entity, button.id);
      button.is_hovered = false;

      if (auto* checkbox = registry.try_get<ui_checkbox>(entity))
      {
        checkbox->is_checked = !checkbox->is_checked;
      }

      // TODO reset cursor

      return true;
    }
  }

  return false;
}

[[nodiscard]] inline auto update_button_hover(entt::registry& registry,
                                              const cen::mouse& mouse)
    -> maybe<ui_button::entity>
{
  const auto menuEntity = registry.ctx<const active_menu>().menu_entity;
  const auto mousePos = cen::cast<cen::fpoint>(mouse.position());

  for (auto&& [entity, button, position, inMenu] :
       registry.view<ui_button, const ui_position, const in_menu>().each())
  {
    if (inMenu.menu_entity == menuEntity && button.is_visible && button.size)
    {
      const auto bounds = cen::frect{from_grid(position), *button.size};
      button.is_hovered = bounds.contains(mousePos);
      if (button.is_hovered)
      {
        return ui_button::entity{entity};
      }
    }
  }

  return nothing;
}

inline void update_button_bounds(const entt::registry& registry, graphics& gfx)
{
  auto& renderer = gfx.renderer();
  for (auto&& [entity, button, label] : registry.view<ui_button, ui_label>().each())
  {
    if (!button.size)
    {
      const auto& font = gfx.get_font(label.font);
      auto size = cen::cast<cen::farea>(font.string_size(label.text).value());

      const auto widthPadding = size.width * 0.5f;
      const auto heightPadding = size.height * 0.5f;

      size.width += widthPadding;
      size.height += heightPadding;

      button.size = size;
      button.text_offset = cen::fpoint{widthPadding / 2.0f, heightPadding / 2.0f};
    }
  }
}

inline void render_buttons(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  const auto view = registry.view<ui_button, ui_position, in_menu>();
  for (auto&& [entity, button, position, inMenu] : view.each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      assert(button.size);
      const auto rect = cen::frect{from_grid(position), *button.size};

      renderer.set_color(cen::colors::white);
      renderer.draw_rect(rect);

      if (button.is_hovered)
      {
        renderer.set_color(cen::colors::lime);
        renderer.draw_rect(rect);
      }
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_BUTTON_SYSTEM_HPP

// #include "ecs/ui/key_bind_system.hpp"
#ifndef RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
#define RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

#include <centurion.hpp>  // scan_code, key_mod
#include <entt.hpp>       // registry, dispatcher

// #include "../../aliases/integers.hpp"

// #include "../../core/input.hpp"
#ifndef RUNE_CORE_INPUT_HPP
#define RUNE_CORE_INPUT_HPP

#include <centurion.hpp>  // keyboard, mouse

namespace rune {

/// \addtogroup core
/// \{

struct input final
{
  cen::keyboard keyboard;
  cen::mouse mouse;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_INPUT_HPP

// #include "../events/key_bind_triggered_event.hpp"
#ifndef RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP
#define RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP

// #include "../../aliases/integers.hpp"

// #include "../null_entity.hpp"

// #include "../ui/ui_key_bind.hpp"
#ifndef RUNE_ECS_UI_UI_KEY_BIND_HPP
#define RUNE_ECS_UI_UI_KEY_BIND_HPP

#include <centurion.hpp>  // scan_code

// #include "../../aliases/integers.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_keybind_tag;
}  // namespace tags

/**
 * \struct ui_key_bind
 *
 * \brief A component that represents a key bind, that emits an event when triggered.
 *
 * \see `ui::make_key_bind()`
 * \see `serialize(auto&, ui_key_bind&)`
 *
 * \since 0.1.0
 */
struct ui_key_bind final
{
  using entity = entity_type<tags::ui_keybind_tag>;

  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The associated key modifiers.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_key_bind& bind)
{
  archive(bind.id, bind.key, bind.modifiers);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_KEY_BIND_HPP


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct key_bind_triggered_event
 *
 * \brief An event that is emitted whenever a key bind is triggered.
 *
 * \since 0.1.0
 */
struct key_bind_triggered_event final
{
  ui_key_bind::entity entity{null<ui_key_bind>()};  ///< The key bind entity.
  uint32 id{};                                      ///< The key bind ID.
};

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_EVENTS_KEY_BIND_TRIGGERED_EVENT_HPP

// #include "ui_key_bind.hpp"
#ifndef RUNE_ECS_UI_UI_KEY_BIND_HPP
#define RUNE_ECS_UI_UI_KEY_BIND_HPP

#include <centurion.hpp>  // scan_code

// #include "../../aliases/integers.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_keybind_tag;
}  // namespace tags

/**
 * \struct ui_key_bind
 *
 * \brief A component that represents a key bind, that emits an event when triggered.
 *
 * \see `ui::make_key_bind()`
 * \see `serialize(auto&, ui_key_bind&)`
 *
 * \since 0.1.0
 */
struct ui_key_bind final
{
  using entity = entity_type<tags::ui_keybind_tag>;

  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The associated key modifiers.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_key_bind& bind)
{
  archive(bind.id, bind.key, bind.modifiers);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_KEY_BIND_HPP


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_key_bind_cfg
 *
 * \brief Configuration used when creating key bind entities.
 *
 * \see `ui_key_bind`
 * \see `ui::make_key_bind()`
 *
 * \since 0.1.0
 */
struct ui_key_bind_cfg final
{
  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The required key modifiers.
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new key bind entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_key_bind`
 *
 * \param registry the registry to which a key bind entity will be added.
 * \param cfg the key bind configuration that will be used.
 *
 * \return the created key bind entity.
 *
 * \since 0.1.0
 */
inline auto make_key_bind(entt::registry& registry, const ui_key_bind_cfg cfg)
    -> ui_key_bind::entity
{
  const auto entity = ui_key_bind::entity{registry.create()};

  auto& bind = registry.emplace<ui_key_bind>(entity);
  bind.id = cfg.id;
  bind.key = cfg.key;
  bind.modifiers = cfg.modifiers;

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

inline void update_key_binds(entt::registry& registry,
                             entt::dispatcher& dispatcher,
                             const input& input)
{
  const auto state = cen::get_modifiers();

  // We don't care about these modifiers (they're never used in key binds)
  const auto subset = state & ~(cen::key_mod::num | cen::key_mod::caps);
  cen::set_modifiers(subset);

  for (auto&& [entity, bind] : registry.view<const ui_key_bind>().each())
  {
    if (input.keyboard.just_released(bind.key) &&
        cen::keyboard::is_only_active(bind.modifiers))
    {
      dispatcher.trigger<key_bind_triggered_event>(ui_key_bind::entity{entity}, bind.id);
      return;
    }
  }

  cen::set_modifiers(state);
}

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

// #include "ecs/ui/label_system.hpp"
#ifndef RUNE_ECS_UI_LABEL_SYSTEM_HPP
#define RUNE_ECS_UI_LABEL_SYSTEM_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // color, fpoint, texture
#include <entt.hpp>       // registry
#include <string>         // string
#include <utility>        // move

// #include "../../aliases/font_id.hpp"

// #include "../../core/graphics.hpp"

// #include "../null_entity.hpp"

// #include "ui_button.hpp"

// #include "ui_foreground.hpp"

// #include "ui_grid.hpp"

// #include "ui_label.hpp"

// #include "ui_menu.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_label_cfg
 *
 * \brief Configuration used when creating label entities.
 *
 * \see `ui::add_label()`
 * \see `ui::make_label()`
 *
 * \since 0.1.0
 */
struct ui_label_cfg final
{
  ui_position position;                  ///< The position of the label.
  std::string text;                      ///< The label text.
  font_id font{};                        ///< The ID of the associated font.
  cen::color color{cen::colors::white};  ///< The label color.
  bool shadow{};                         ///< Does the label have a shadow?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Adds label components to an existing entity.
 *
 * \details The supplied entity will have the following components added to it.
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_label_cfg::shadow` is `true`)
 * - `ui_position`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry in which the supplied entity belongs to.
 * \param menu the host menu entity.
 * \param entity the entity to which label components will be added.
 * \param cfg the label configuration that will be used.
 *
 * \see `make_label()`
 *
 * \since 0.1.0
 */
inline void add_label(entt::registry& registry,
                      const ui_menu::entity menu,
                      const entt::entity entity,
                      ui_label_cfg cfg)
{
  registry.emplace<in_menu>(entity, menu);

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.text);
  label.font = cfg.font;

  registry.emplace<ui_position>(entity, cfg.position);
  registry.emplace<ui_foreground>(entity, cfg.color);

  if (cfg.shadow)
  {
    registry.emplace<ui_label_shadow>(entity);
  }
}

/**
 * \brief Creates a new label entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_label_cfg::shadow` is `true`)
 * - `ui_position`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry to which a label entity will be added.
 * \param menu the host menu entity.
 * \param cfg the label configuration that will be used.
 *
 * \return the created label entity.
 *
 * \see `add_label()`
 *
 * \since 0.1.0
 */
inline auto make_label(entt::registry& registry,
                       const ui_menu::entity menu,
                       ui_label_cfg cfg) -> ui_label::entity
{
  const auto entity = ui_label::entity{registry.create()};

  add_label(registry, menu, entity, std::move(cfg));

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

[[nodiscard]] inline auto render_text(graphics& gfx,
                                      const ui_label& label,
                                      const cen::color& color) -> cen::texture
{
  auto& renderer = gfx.renderer();
  renderer.set_color(color);

  const auto& font = gfx.get_font(label.font);
  return renderer.render_blended_utf8(label.text, font);
}

inline void render_label(graphics& gfx,
                         const ui_label& label,
                         const cen::fpoint& position,
                         const cen::color& fg)
{
  auto& renderer = gfx.renderer();

  if (!label.texture)
  {
    label.texture = render_text(gfx, label, fg);
  }

  assert(label.texture);
  renderer.render(*label.texture, position);
}

inline void render_shadow(graphics& gfx,
                          const ui_label& label,
                          const ui_label_shadow& shadow,
                          const cen::fpoint& position)
{
  if (!shadow.texture)
  {
    shadow.texture = render_text(gfx, label, cen::colors::black);
  }

  assert(shadow.texture);
  const cen::fpoint offset{static_cast<float>(shadow.offset),
                           static_cast<float>(shadow.offset)};
  gfx.renderer().render(*shadow.texture, position + offset);
}

inline void render_labels(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  const auto filter = entt::exclude<ui_button>;
  for (auto&& [entity, label, position, fg, inMenu] :
       registry.view<ui_label, ui_position, ui_foreground, in_menu>(filter).each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      if (const auto* shadow = registry.try_get<ui_label_shadow>(entity))
      {
        render_shadow(gfx, label, *shadow, from_grid(position));
      }

      render_label(gfx, label, from_grid(position), fg.color);
    }
  }
}

inline void render_button_labels(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  for (auto&& [entity, button, label, position, fg, inMenu] :
       registry.view<ui_button, ui_label, ui_position, ui_foreground, in_menu>().each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      const auto textPos = from_grid(position) + button.text_offset.value();

      if (const auto* shadow = registry.try_get<ui_label_shadow>(entity))
      {
        render_shadow(gfx, label, *shadow, textPos);
      }

      render_label(gfx, label, textPos, fg.color);
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace ui

}  // namespace rune

#endif  // RUNE_ECS_UI_LABEL_SYSTEM_HPP

// #include "ecs/ui/lazy_texture_system.hpp"
#ifndef RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP
#define RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP

#include <centurion.hpp>  // texture, surface
#include <entt.hpp>       // registry

// #include "../../aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune

// #include "../../core/graphics.hpp"

// #include "ui_lazy_texture.hpp"


namespace rune::ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new lazy texture entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_lazy_texture`
 *
 * \param registry the registry to which a lazy texture entity will be added.
 * \param image the file path of the source image.
 *
 * \return the created lazy texture entity.
 *
 * \since 0.1.0
 */
inline auto make_lazy_texture(entt::registry& registry, const str image)
    -> ui_lazy_texture::entity
{
  const auto entity = ui_lazy_texture::entity{registry.create()};

  registry.emplace<ui_lazy_texture>(entity, cen::surface{image});

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

inline void update_lazy_textures(const entt::registry& registry, graphics& gfx)
{
  for (auto&& [entity, lazy] : registry.view<ui_lazy_texture>().each())
  {
    if (!lazy.texture)
    {
      lazy.texture = cen::texture{gfx.renderer(), lazy.source};
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP

// #include "ecs/ui/line_system.hpp"
#ifndef RUNE_ECS_UI_LINE_SYSTEM_HPP
#define RUNE_ECS_UI_LINE_SYSTEM_HPP

#include <centurion.hpp>  // color
#include <entt.hpp>       // registry

// #include "../../core/graphics.hpp"

// #include "ui_foreground.hpp"

// #include "ui_grid.hpp"

// #include "ui_line.hpp"
#ifndef RUNE_ECS_UI_UI_LINE_HPP
#define RUNE_ECS_UI_UI_LINE_HPP

// #include "../entity_type.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_line_tag;
}  // namespace tags

/**
 * \struct ui_line
 *
 * \brief A component that represents a UI line.
 *
 * \see `ui::make_line()`
 * \see `serialize(auto&, ui_line&)`
 *
 * \since 0.1.0
 */
struct ui_line final
{
  using entity = entity_type<tags::ui_line_tag>;

  ui_position start;  ///< The start point.
  ui_position end;    ///< The end point.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_line& line)
{
  archive(line.start, line.end);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LINE_HPP

// #include "ui_menu.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_line_cfg
 *
 * \brief Configuration used when creating line entities.
 *
 * \see `ui_line`
 * \see `ui::make_line()`
 *
 * \since 0.1.0
 */
struct ui_line_cfg final
{
  ui_position start;                     ///< The line start position.
  ui_position end;                       ///< The line end position.
  cen::color color{cen::colors::white};  ///< The color of the line.
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new line entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_line`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry to which a line entity will be added.
 * \param menu the host menu entity.
 * \param cfg the line configuration that will be used.
 *
 * \return the created line entity.
 *
 * \see `ui_line_cfg`
 *
 * \since 0.1.0
 */
inline auto make_line(entt::registry& registry,
                      const ui_menu::entity menu,
                      ui_line_cfg cfg) -> ui_line::entity
{
  const auto entity = ui_line::entity{registry.create()};

  registry.emplace<ui_line>(entity, cfg.start, cfg.end);
  registry.emplace<ui_foreground>(entity, cfg.color);
  registry.emplace<in_menu>(entity, menu);

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

inline void render_lines(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;

  auto& renderer = gfx.renderer();
  for (auto&& [entity, line, fg, inMenu] :
       registry.view<ui_line, ui_foreground, in_menu>().each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      renderer.set_color(fg.color);
      renderer.draw_line(from_grid(line.start), from_grid(line.end));
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_LINE_SYSTEM_HPP

// #include "ecs/ui/menu_system.hpp"
#ifndef RUNE_ECS_UI_MENU_SYSTEM_HPP
#define RUNE_ECS_UI_MENU_SYSTEM_HPP

#include <entt.hpp>  // registry
#include <string>    // string
#include <utility>   // move

// #include "../../aliases/font_id.hpp"

// #include "../../aliases/integers.hpp"

// #include "ui_label.hpp"

// #include "ui_menu.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_menu_cfg
 *
 * \brief Configuration used when creating menu entities.
 *
 * \see `ui_menu`
 * \see `ui::make_menu()`
 *
 * \since 0.1.0
 */
struct ui_menu_cfg final
{
  uint32 id{};             ///< User-defined identifier.
  std::string title;       ///< The menu title.
  font_id font{};          ///< The ID of the title font.
  bool is_blocking{true};  ///< Does the menu block game logic updates?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new menu entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_menu`
 * - `ui_label`
 *
 * \param registry the registry to which a menu entity will be added.
 * \param cfg the menu configuration that will be used.
 *
 * \return the created menu entity.
 *
 * \see `ui_menu_cfg`
 *
 * \since 0.1.0
 */
inline auto make_menu(entt::registry& registry, ui_menu_cfg cfg) -> ui_menu::entity
{
  const auto entity = ui_menu::entity{registry.create()};

  auto& menu = registry.emplace<ui_menu>(entity);
  menu.id = cfg.id;
  menu.is_blocking = cfg.is_blocking;

  auto& label = registry.emplace<ui_label>(entity);
  label.text = std::move(cfg.title);
  label.font = cfg.font;

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

}  // namespace ui

}  // namespace rune

#endif  // RUNE_ECS_UI_MENU_SYSTEM_HPP

// #include "ecs/ui/ui_background.hpp"
#ifndef RUNE_ECS_UI_UI_BACKGROUND_HPP
#define RUNE_ECS_UI_UI_BACKGROUND_HPP

#include <centurion.hpp>  // color

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_background_tag;
}  // namespace tags

/**
 * \struct ui_background
 *
 * \brief A component that represents a background color.
 *
 * \see `serialize(auto&, ui_background&)`
 *
 * \since 0.1.0
 */
struct ui_background final
{
  using entity = entity_type<tags::ui_background_tag>;

  cen::color color;  ///< The background color.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_background& bg)
{
  archive(bg.color);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BACKGROUND_HPP

// #include "ecs/ui/ui_button.hpp"
#ifndef RUNE_ECS_UI_UI_BUTTON_HPP
#define RUNE_ECS_UI_UI_BUTTON_HPP

#include <centurion.hpp>  // farea, fpoint

// #include "../../aliases/integers.hpp"

// #include "../../aliases/maybe.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_button_tag;
}  // namespace tags

/**
 * \struct ui_button
 *
 * \brief A component that represents a UI button, i.e. a control that can be pressed.
 *
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 * \see `serialize(auto&, ui_button&)`
 *
 * \since 0.1.0
 */
struct ui_button final
{
  using entity = entity_type<tags::ui_button_tag>;

  uint32 id{};                             ///< User-defined identifier.
  mutable maybe<cen::fpoint> text_offset;  ///< Lazily initialized offset for the label.
  mutable maybe<cen::farea> size;          ///< Lazily initialized button size.
  bool is_enabled{true};   ///< Is the button enabled, i.e. can it be pressed?
  bool is_visible{true};   ///< Is the button visible?
  bool is_hovered{false};  ///< Is the button currently hovered?
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_button& b)
{
  archive(b.id, b.text_offset, b.size, b.is_enabled, b.is_visible, b.is_hovered);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_BUTTON_HPP

// #include "ecs/ui/ui_checkbox.hpp"
#ifndef RUNE_ECS_UI_CHECKBOX_HPP
#define RUNE_ECS_UI_CHECKBOX_HPP

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_checkbox_tag;
}  // namespace tags

/**
 * \struct ui_checkbox
 *
 * \brief A component that represents a UI button, i.e. a control that can be pressed.
 *
 * \see `serialize(auto&, ui_checkbox&)`
 *
 * \since 0.1.0
 */
struct ui_checkbox final
{
  using entity = entity_type<tags::ui_checkbox_tag>;

  bool is_checked{};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_checkbox& cb)
{
  archive(cb.is_checked);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_CHECKBOX_HPP

// #include "ecs/ui/ui_foreground.hpp"
#ifndef RUNE_ECS_UI_UI_FOREGROUND_HPP
#define RUNE_ECS_UI_UI_FOREGROUND_HPP

#include <centurion.hpp>  // color

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_foreground_tag;
}  // namespace tags

/**
 * \struct ui_foreground
 *
 * \brief A component that represents a foreground color.
 *
 * \see `serialize(auto&, ui_foreground&)`
 *
 * \since 0.1.0
 */
struct ui_foreground final
{
  using entity = entity_type<tags::ui_foreground_tag>;

  cen::color color;  ///< The foreground color.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_foreground& fg)
{
  archive(fg.color);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_FOREGROUND_HPP

// #include "ecs/ui/ui_grid.hpp"
#ifndef RUNE_ECS_UI_UI_GRID_HPP
#define RUNE_ECS_UI_UI_GRID_HPP

#include <centurion.hpp>  // fpoint

// #include "ui_position.hpp"


namespace rune::ui {

/// \addtogroup ecs
/// \{

#ifndef RUNE_MENU_ROW_SIZE
#define RUNE_MENU_ROW_SIZE 10.0f
#endif  // RUNE_MENU_ROW_SIZE

#ifndef RUNE_MENU_COLUMN_SIZE
#define RUNE_MENU_COLUMN_SIZE 10.0f
#endif  // RUNE_MENU_COLUMN_SIZE

inline constexpr float menu_row_size = RUNE_MENU_ROW_SIZE;
inline constexpr float menu_column_size = RUNE_MENU_COLUMN_SIZE;

/// \name Grid functions
/// \{

[[nodiscard]] constexpr auto row_to_y(const float row) noexcept -> float
{
  return row * menu_row_size;
}

[[nodiscard]] constexpr auto column_to_x(const float column) noexcept -> float
{
  return column * menu_column_size;
}

[[nodiscard]] constexpr auto from_grid(const float row, const float column) noexcept
    -> cen::fpoint
{
  return {column_to_x(column), row_to_y(row)};
}

[[nodiscard]] constexpr auto from_grid(const ui_position position) noexcept -> cen::fpoint
{
  return {column_to_x(position.col), row_to_y(position.row)};
}

/// \} End of grid functions

/// \} End of group ecs

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_UI_GRID_HPP

// #include "ecs/ui/ui_key_bind.hpp"
#ifndef RUNE_ECS_UI_UI_KEY_BIND_HPP
#define RUNE_ECS_UI_UI_KEY_BIND_HPP

#include <centurion.hpp>  // scan_code

// #include "../../aliases/integers.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_keybind_tag;
}  // namespace tags

/**
 * \struct ui_key_bind
 *
 * \brief A component that represents a key bind, that emits an event when triggered.
 *
 * \see `ui::make_key_bind()`
 * \see `serialize(auto&, ui_key_bind&)`
 *
 * \since 0.1.0
 */
struct ui_key_bind final
{
  using entity = entity_type<tags::ui_keybind_tag>;

  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The associated key modifiers.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_key_bind& bind)
{
  archive(bind.id, bind.key, bind.modifiers);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_KEY_BIND_HPP

// #include "ecs/ui/ui_label.hpp"
#ifndef RUNE_ECS_UI_UI_LABEL_HPP
#define RUNE_ECS_UI_UI_LABEL_HPP

#include <centurion.hpp>  // texture
#include <string>         // string

// #include "../../aliases/font_id.hpp"

// #include "../../aliases/maybe.hpp"

// #include "../entity_type.hpp"

// #include "ui_lazy_texture.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_label_tag;
struct ui_label_shadow_tag;
}  // namespace tags

/**
 * \struct ui_label
 *
 * \brief A component that represents a UI label.
 *
 * \see `ui::make_label()`
 * \see `serialize(auto&, ui_label&)`
 *
 * \since 0.1.0
 */
struct ui_label final
{
  using entity = entity_type<tags::ui_label_tag>;

  std::string text;                     ///< The label text.
  font_id font{};                       ///< The associated font ID.
  mutable maybe<cen::texture> texture;  ///< Lazily initialized label texture.
};

/**
 * \struct ui_label_shadow
 *
 * \brief A component that represents a UI label shadow.
 *
 * \see `serialize(auto&, ui_label_shadow&)`
 *
 * \since 0.1.0
 */
struct ui_label_shadow final
{
  using entity = entity_type<tags::ui_label_shadow_tag>;

  mutable maybe<cen::texture> texture;  ///< Lazily initialized shadow texture.
  int offset{1};                        ///< The shadow offset.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_label& label)
{
  archive(label.text, label.font);
}

void serialize(auto& archive, ui_label_shadow& shadow)
{
  archive(shadow.offset);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LABEL_HPP

// #include "ecs/ui/ui_lazy_texture.hpp"
#ifndef RUNE_ECS_UI_UI_LAZY_TEXTURE_HPP
#define RUNE_ECS_UI_UI_LAZY_TEXTURE_HPP

#include <centurion.hpp>  // surface, texture

// #include "../../aliases/maybe.hpp"

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_lazy_texture_tag;
}  // namespace tags

/**
 * \struct ui_lazy_texture
 *
 * \brief A component that represents a lazily initialized texture.
 *
 * \see `ui::make_lazy_texture()`
 *
 * \since 0.1.0
 */
struct ui_lazy_texture final
{
  using entity = entity_type<tags::ui_lazy_texture_tag>;

  cen::surface source;                  ///< The source image data.
  mutable maybe<cen::texture> texture;  ///< Lazily initialized texture.
};

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LAZY_TEXTURE_HPP

// #include "ecs/ui/ui_line.hpp"
#ifndef RUNE_ECS_UI_UI_LINE_HPP
#define RUNE_ECS_UI_UI_LINE_HPP

// #include "../entity_type.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_line_tag;
}  // namespace tags

/**
 * \struct ui_line
 *
 * \brief A component that represents a UI line.
 *
 * \see `ui::make_line()`
 * \see `serialize(auto&, ui_line&)`
 *
 * \since 0.1.0
 */
struct ui_line final
{
  using entity = entity_type<tags::ui_line_tag>;

  ui_position start;  ///< The start point.
  ui_position end;    ///< The end point.
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_line& line)
{
  archive(line.start, line.end);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_LINE_HPP

// #include "ecs/ui/ui_menu.hpp"
#ifndef RUNE_ECS_UI_UI_MENU_HPP
#define RUNE_ECS_UI_UI_MENU_HPP

// #include "../../aliases/integers.hpp"

// #include "../entity_type.hpp"

// #include "../null_entity.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_menu_tag;
}  // namespace tags

/**
 * \struct ui_menu
 *
 * \brief A component that represents a UI menu.
 *
 * \see `ui::make_menu()`
 * \see `serialize(auto&, ui_menu&)`
 *
 * \since 0.1.0
 */
struct ui_menu final
{
  using entity = entity_type<tags::ui_menu_tag>;

  uint32 id{};         ///< User-defined identifier.
  bool is_blocking{};  ///< Does the menu block game logic updates?
};

struct active_menu final
{
  ui_menu::entity menu_entity{null<ui_menu>()};
};

struct in_menu final
{
  ui_menu::entity menu_entity{null<ui_menu>()};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_menu& menu)
{
  archive(menu.id, menu.is_blocking);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_MENU_HPP

// #include "ecs/ui/ui_position.hpp"
#ifndef RUNE_ECS_UI_UI_POSITION_HPP
#define RUNE_ECS_UI_UI_POSITION_HPP

// #include "../entity_type.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

namespace tags {
struct ui_position_tag;
}  // namespace tags

struct ui_position final
{
  using entity = entity_type<tags::ui_position_tag>;

  float row{};
  float col{};
};

/// \name Serialization
/// \{

void serialize(auto& archive, ui_position& position)
{
  archive(position.row, position.col);
}

/// \} End of serialization

/// \} End of group ecs

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_POSITION_HPP

// #include "ecs/ui/ui_system.hpp"
#ifndef RUNE_ECS_UI_UI_SYSTEM_HPP
#define RUNE_ECS_UI_UI_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

// #include "../../core/graphics.hpp"

// #include "../../core/input.hpp"

// #include "button_system.hpp"
#ifndef RUNE_ECS_UI_BUTTON_SYSTEM_HPP
#define RUNE_ECS_UI_BUTTON_SYSTEM_HPP

#include <cassert>        // assert
#include <centurion.hpp>  // mouse, color
#include <entt.hpp>       // registry, dispatcher
#include <string>         // string
#include <utility>        // move

// #include "../../aliases/font_id.hpp"

// #include "../../aliases/integers.hpp"

// #include "../../aliases/maybe.hpp"

// #include "../../core/graphics.hpp"

// #include "../events/button_pressed_event.hpp"

// #include "../null_entity.hpp"

// #include "label_system.hpp"

// #include "ui_button.hpp"

// #include "ui_checkbox.hpp"

// #include "ui_foreground.hpp"

// #include "ui_grid.hpp"

// #include "ui_label.hpp"

// #include "ui_menu.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_button_cfg
 *
 * \brief Configuration used when creating button entities.
 *
 * \see `ui_button`
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 *
 * \since 0.1.0
 */
struct ui_button_cfg final
{
  ui_position position;               ///< The position of the button.
  std::string text;                   ///< The button label text.
  uint32 id{};                        ///< User-defined button identifier.
  font_id font{};                     ///< The font used by the label.
  cen::color fg{cen::colors::white};  ///< The label color.
  bool shadow{};                      ///< Should the label feature a shadow?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Adds button components to an existing entity.
 *
 * \details The supplied entity will have the following components added to it.
 * - `ui_button`
 * - `ui_position`
 * - `ui_foreground`
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_button_cfg::shadow` is `true`)
 * - `in_menu`
 *
 * \param registry the registry in which the supplied entity belongs to.
 * \param menu the host menu entity.
 * \param entity the entity to which button components will be added.
 * \param cfg the button configuration that will be used.
 *
 * \since 0.1.0
 */
inline void add_button(entt::registry& registry,
                       ui_menu::entity menu,
                       entt::entity entity,
                       ui_button_cfg cfg)
{
  auto& button = registry.emplace<ui_button>(entity);
  button.id = cfg.id;

  add_label(registry,
            menu,
            entity,
            {.position = cfg.position,
             .text = std::move(cfg.text),
             .font = cfg.font,
             .color = cfg.fg,
             .shadow = cfg.shadow});
}

/**
 * \brief Creates a new button entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_button`
 * - `ui_position`
 * - `ui_foreground`
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_button_cfg::shadow` is `true`)
 * - `in_menu`
 *
 * \param registry the registry to which a button entity will be added.
 * \param menu the host menu entity.
 * \param cfg the button configuration that will be used.
 *
 * \return the created button entity.
 *
 * \see `ui_button_cfg`
 * \see `add_button()`
 *
 * \since 0.1.0
 */
inline auto make_button(entt::registry& registry, ui_menu::entity menu, ui_button_cfg cfg)
    -> ui_button::entity
{
  const auto entity = ui_button::entity{registry.create()};

  add_button(registry, menu, entity, std::move(cfg));

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

[[nodiscard]] inline auto query_button(entt::registry& registry,
                                       entt::dispatcher& dispatcher,
                                       ui_button::entity entity,
                                       const cen::mouse& mouse) -> bool
{
  auto& button = registry.get<ui_button>(entity);
  if (button.is_enabled && button.is_hovered)
  {
    // TODO enable_cursor

    if (mouse.was_left_button_released())
    {
      dispatcher.trigger<button_pressed_event>(entity, button.id);
      button.is_hovered = false;

      if (auto* checkbox = registry.try_get<ui_checkbox>(entity))
      {
        checkbox->is_checked = !checkbox->is_checked;
      }

      // TODO reset cursor

      return true;
    }
  }

  return false;
}

[[nodiscard]] inline auto update_button_hover(entt::registry& registry,
                                              const cen::mouse& mouse)
    -> maybe<ui_button::entity>
{
  const auto menuEntity = registry.ctx<const active_menu>().menu_entity;
  const auto mousePos = cen::cast<cen::fpoint>(mouse.position());

  for (auto&& [entity, button, position, inMenu] :
       registry.view<ui_button, const ui_position, const in_menu>().each())
  {
    if (inMenu.menu_entity == menuEntity && button.is_visible && button.size)
    {
      const auto bounds = cen::frect{from_grid(position), *button.size};
      button.is_hovered = bounds.contains(mousePos);
      if (button.is_hovered)
      {
        return ui_button::entity{entity};
      }
    }
  }

  return nothing;
}

inline void update_button_bounds(const entt::registry& registry, graphics& gfx)
{
  auto& renderer = gfx.renderer();
  for (auto&& [entity, button, label] : registry.view<ui_button, ui_label>().each())
  {
    if (!button.size)
    {
      const auto& font = gfx.get_font(label.font);
      auto size = cen::cast<cen::farea>(font.string_size(label.text).value());

      const auto widthPadding = size.width * 0.5f;
      const auto heightPadding = size.height * 0.5f;

      size.width += widthPadding;
      size.height += heightPadding;

      button.size = size;
      button.text_offset = cen::fpoint{widthPadding / 2.0f, heightPadding / 2.0f};
    }
  }
}

inline void render_buttons(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;
  auto& renderer = gfx.renderer();

  const auto view = registry.view<ui_button, ui_position, in_menu>();
  for (auto&& [entity, button, position, inMenu] : view.each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      assert(button.size);
      const auto rect = cen::frect{from_grid(position), *button.size};

      renderer.set_color(cen::colors::white);
      renderer.draw_rect(rect);

      if (button.is_hovered)
      {
        renderer.set_color(cen::colors::lime);
        renderer.draw_rect(rect);
      }
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_BUTTON_SYSTEM_HPP

// #include "key_bind_system.hpp"
#ifndef RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
#define RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

#include <centurion.hpp>  // scan_code, key_mod
#include <entt.hpp>       // registry, dispatcher

// #include "../../aliases/integers.hpp"

// #include "../../core/input.hpp"

// #include "../events/key_bind_triggered_event.hpp"

// #include "ui_key_bind.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_key_bind_cfg
 *
 * \brief Configuration used when creating key bind entities.
 *
 * \see `ui_key_bind`
 * \see `ui::make_key_bind()`
 *
 * \since 0.1.0
 */
struct ui_key_bind_cfg final
{
  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The required key modifiers.
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new key bind entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_key_bind`
 *
 * \param registry the registry to which a key bind entity will be added.
 * \param cfg the key bind configuration that will be used.
 *
 * \return the created key bind entity.
 *
 * \since 0.1.0
 */
inline auto make_key_bind(entt::registry& registry, const ui_key_bind_cfg cfg)
    -> ui_key_bind::entity
{
  const auto entity = ui_key_bind::entity{registry.create()};

  auto& bind = registry.emplace<ui_key_bind>(entity);
  bind.id = cfg.id;
  bind.key = cfg.key;
  bind.modifiers = cfg.modifiers;

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

inline void update_key_binds(entt::registry& registry,
                             entt::dispatcher& dispatcher,
                             const input& input)
{
  const auto state = cen::get_modifiers();

  // We don't care about these modifiers (they're never used in key binds)
  const auto subset = state & ~(cen::key_mod::num | cen::key_mod::caps);
  cen::set_modifiers(subset);

  for (auto&& [entity, bind] : registry.view<const ui_key_bind>().each())
  {
    if (input.keyboard.just_released(bind.key) &&
        cen::keyboard::is_only_active(bind.modifiers))
    {
      dispatcher.trigger<key_bind_triggered_event>(ui_key_bind::entity{entity}, bind.id);
      return;
    }
  }

  cen::set_modifiers(state);
}

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

// #include "label_system.hpp"

// #include "lazy_texture_system.hpp"
#ifndef RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP
#define RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP

#include <centurion.hpp>  // texture, surface
#include <entt.hpp>       // registry

// #include "../../aliases/str.hpp"

// #include "../../core/graphics.hpp"

// #include "ui_lazy_texture.hpp"


namespace rune::ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new lazy texture entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_lazy_texture`
 *
 * \param registry the registry to which a lazy texture entity will be added.
 * \param image the file path of the source image.
 *
 * \return the created lazy texture entity.
 *
 * \since 0.1.0
 */
inline auto make_lazy_texture(entt::registry& registry, const str image)
    -> ui_lazy_texture::entity
{
  const auto entity = ui_lazy_texture::entity{registry.create()};

  registry.emplace<ui_lazy_texture>(entity, cen::surface{image});

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

inline void update_lazy_textures(const entt::registry& registry, graphics& gfx)
{
  for (auto&& [entity, lazy] : registry.view<ui_lazy_texture>().each())
  {
    if (!lazy.texture)
    {
      lazy.texture = cen::texture{gfx.renderer(), lazy.source};
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP

// #include "line_system.hpp"
#ifndef RUNE_ECS_UI_LINE_SYSTEM_HPP
#define RUNE_ECS_UI_LINE_SYSTEM_HPP

#include <centurion.hpp>  // color
#include <entt.hpp>       // registry

// #include "../../core/graphics.hpp"

// #include "ui_foreground.hpp"

// #include "ui_grid.hpp"

// #include "ui_line.hpp"

// #include "ui_menu.hpp"

// #include "ui_position.hpp"


namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_line_cfg
 *
 * \brief Configuration used when creating line entities.
 *
 * \see `ui_line`
 * \see `ui::make_line()`
 *
 * \since 0.1.0
 */
struct ui_line_cfg final
{
  ui_position start;                     ///< The line start position.
  ui_position end;                       ///< The line end position.
  cen::color color{cen::colors::white};  ///< The color of the line.
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new line entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_line`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry to which a line entity will be added.
 * \param menu the host menu entity.
 * \param cfg the line configuration that will be used.
 *
 * \return the created line entity.
 *
 * \see `ui_line_cfg`
 *
 * \since 0.1.0
 */
inline auto make_line(entt::registry& registry,
                      const ui_menu::entity menu,
                      ui_line_cfg cfg) -> ui_line::entity
{
  const auto entity = ui_line::entity{registry.create()};

  registry.emplace<ui_line>(entity, cfg.start, cfg.end);
  registry.emplace<ui_foreground>(entity, cfg.color);
  registry.emplace<in_menu>(entity, menu);

  return entity;
}

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

inline void render_lines(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<active_menu>().menu_entity;

  auto& renderer = gfx.renderer();
  for (auto&& [entity, line, fg, inMenu] :
       registry.view<ui_line, ui_foreground, in_menu>().each())
  {
    if (menuEntity == inMenu.menu_entity)
    {
      renderer.set_color(fg.color);
      renderer.draw_line(from_grid(line.start), from_grid(line.end));
    }
  }
}

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_LINE_SYSTEM_HPP

// #include "ui_key_bind.hpp"

// #include "ui_menu.hpp"


namespace rune::ui {

/// \addtogroup ecs
/// \{

/**
 * \brief Updates the state of the UI.
 *
 * \details This is the only UI-function you need to call in your `handle_input()`
 * function in order to use the UI framework.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param dispatcher the event dispatcher that will be used.
 * \param input the current input state.
 *
 * \since 0.1.0
 */
inline void update(entt::registry& registry,
                   entt::dispatcher& dispatcher,
                   const input& input)
{
  if (const auto button = detail::update_button_hover(registry, input.mouse))
  {
    if (detail::query_button(registry, dispatcher, *button, input.mouse))
    {
      // TODO

      return;
    }
  }

  detail::update_key_binds(registry, dispatcher, input);
}

/**
 * \brief Renders the currently active UI components.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param gfx the graphics context that will be used for rendering.
 *
 * \see `debug()`
 *
 * \since 0.1.0
 */
inline void render(const entt::registry& registry, graphics& gfx)
{
  detail::update_button_bounds(registry, gfx);
  detail::update_lazy_textures(registry, gfx);

  detail::render_lines(registry, gfx);
  detail::render_buttons(registry, gfx);
  detail::render_labels(registry, gfx);
  detail::render_button_labels(registry, gfx);
}

/**
 * \brief Renders debug information for the currently active UI components.
 *
 * \details This function is intended to be used to aid debugging UI aspects such as
 * layouts or alignments.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param gfx the graphics context that will be used for rendering.
 *
 * \see `render()`
 *
 * \since 0.1.0
 */
inline void debug(const entt::registry& registry, graphics& gfx)
{
  const auto menuEntity = registry.ctx<const active_menu>().menu_entity;
  const auto& menu = registry.get<ui_menu>(menuEntity);

  if (menu.is_blocking)
  {
    auto& renderer = gfx.renderer();
    renderer.set_color(cen::colors::light_gray.with_alpha(50));

    const auto [logicalWidth, logicalHeight] = renderer.logical_size();

    // TODO
  }
}

/// \} End of group ecs

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_UI_SYSTEM_HPP

// #include "io/ini.hpp"
#ifndef RUNE_IO_INI_HPP
#define RUNE_IO_INI_HPP

#include <algorithm>    // find_if, all_of
#include <cassert>      // assert
#include <filesystem>   // path
#include <fstream>      // ifstream, ofstream
#include <functional>   // less
#include <istream>      // istream
#include <locale>       // locale, isspace, isdigit
#include <map>          // map
#include <ostream>      // ostream
#include <string>       // basic_string, getline
#include <string_view>  // basic_string_view
#include <utility>      // move
#include <vector>       // vector

// #include "../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP

// #include "../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "../core/rune_error.hpp"
#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

// #include "../aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune


namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const str what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> str override
  {
    return m_what;
  }

 private:
  str m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP

// #include "ini_section.hpp"
#ifndef RUNE_IO_INI_SECTION_HPP
#define RUNE_IO_INI_SECTION_HPP

#include <functional>   // less
#include <map>          // map
#include <ostream>      // ostream
#include <string>       // basic_string
#include <string_view>  // basic_string_view

// #include "../aliases/integers.hpp"

// #include "../core/rune_error.hpp"

// #include "ini_value.hpp"
#ifndef RUNE_IO_INI_VALUE_HPP
#define RUNE_IO_INI_VALUE_HPP

#include <concepts>     // convertible_to, integral, floating_point, same_as
#include <nenya.hpp>    // strong_type
#include <ostream>      // ostream
#include <string>       // basic_string, to_string
#include <string_view>  // basic_string_view
#include <utility>      // move
#include <variant>      // variant, get, get_if, holds_alternative

// #include "../aliases/integers.hpp"


namespace rune {

/// \addtogroup io
/// \{

/// \name Ini
/// \{

// clang-format off

template <typename T, typename Char>
concept is_ini_value = std::integral<T> ||
                       std::floating_point<T> ||
                       std::constructible_from<std::basic_string<Char>, T>;

// clang-format on

template <typename Char>
class basic_ini_value final
{
 public:
  using char_type = Char;
  using string_type = std::basic_string<char_type>;
  using string_view_type = std::basic_string_view<char_type>;
  using value_type = std::variant<string_type, bool, int64, uint64, double>;

  basic_ini_value() = default;

  basic_ini_value(const basic_ini_value&) = default;
  basic_ini_value(basic_ini_value&&) noexcept = default;

  basic_ini_value& operator=(const basic_ini_value&) = default;
  basic_ini_value& operator=(basic_ini_value&&) noexcept = default;

  template <typename T>
  /*implicit*/ basic_ini_value(T value) requires is_ini_value<T, char_type>  // NOLINT
  {
    assign(std::move(value));
  }

  template <typename T>
  basic_ini_value& operator=(T value) requires is_ini_value<T, char_type>
  {
    assign(std::move(value));
    return *this;
  }

  // clang-format off

  template <typename T> requires is_ini_value<T, char_type>
  [[nodiscard]] auto get() const -> T
  {
    static_assert(std::convertible_to<T, string_type> ||
                  std::signed_integral<T> ||
                  std::unsigned_integral<T> ||
                  std::floating_point<T> ||
                  std::same_as<T, bool>,
                  "Invalid template type parameter to basic_ini_value::get!");
    // clang-format on

    if constexpr (std::same_as<T, bool>)
    {
      return std::get<bool>(m_value);
    }
    else if constexpr (std::signed_integral<T>)
    {
      return static_cast<T>(std::get<int64>(m_value));
    }
    else if constexpr (std::unsigned_integral<T>)
    {
      return static_cast<T>(std::get<uint64>(m_value));
    }
    else if constexpr (std::floating_point<T>)
    {
      return static_cast<T>(std::get<double>(m_value));
    }
    else /*if constexpr (std::convertible_to<T, string_type>)*/
    {
      return std::get<string_type>(m_value);
    }
  }

  void get_to(string_type& value) const
  {
    value = std::get<string_type>(m_value);
  }

  void get_to(bool& value) const
  {
    value = std::get<bool>(m_value);
  }

  void get_to(int8& value) const
  {
    value = static_cast<int8>(std::get<int64>(m_value));
  }

  void get_to(int16& value) const
  {
    value = static_cast<int16>(std::get<int64>(m_value));
  }

  void get_to(int32& value) const
  {
    value = static_cast<int32>(std::get<int64>(m_value));
  }

  void get_to(int64& value) const
  {
    value = std::get<int64>(m_value);
  }

  void get_to(uint8& value) const
  {
    value = static_cast<uint8>(std::get<uint64>(m_value));
  }

  void get_to(uint16& value) const
  {
    value = static_cast<uint16>(std::get<uint64>(m_value));
  }

  void get_to(uint32& value) const
  {
    value = static_cast<uint32>(std::get<uint64>(m_value));
  }

  void get_to(uint64& value) const
  {
    value = std::get<uint64>(m_value);
  }

  void get_to(float& value) const
  {
    value = static_cast<float>(std::get<double>(m_value));
  }

  void get_to(double& value) const
  {
    value = std::get<double>(m_value);
  }

  // clang-format off

  template <typename T, typename Tag, nenya::conversion Conv> requires is_ini_value<T, char_type>
  void get_to(nenya::strong_type<T, Tag, Conv>& value) const
  {
    using strong_type = nenya::strong_type<T, Tag, Conv>;

    if constexpr (std::same_as<T, bool>)
    {
      value = strong_type{static_cast<T>(std::get<bool>(m_value))};
    }
    else if constexpr (std::signed_integral<T>)
    {
      value = strong_type{static_cast<T>(std::get<int64>(m_value))};
    }
    else if constexpr (std::unsigned_integral<T>)
    {
      value = strong_type{static_cast<T>(std::get<uint64>(m_value))};
    }
    else if constexpr (std::floating_point<T>)
    {
      value = strong_type{static_cast<T>(std::get<double>(m_value))};
    }
    else /*if constexpr (std::convertible_to<T, string_type>)*/
    {
      value = strong_type{static_cast<T>(std::get<string_type>(m_value))};
    }
  }

  // clang-format on

  [[nodiscard]] auto get() const -> const value_type&
  {
    return m_value;
  }

  [[nodiscard]] auto try_get_string() const noexcept -> const string_type*
  {
    return std::get_if<string_type>(&m_value);
  }

  [[nodiscard]] auto try_get_int() const noexcept -> const int64*
  {
    return std::get_if<int64>(&m_value);
  }

  [[nodiscard]] auto try_get_uint() const noexcept -> const uint64*
  {
    return std::get_if<uint64>(&m_value);
  }

  [[nodiscard]] auto try_get_float() const noexcept -> const double*
  {
    return std::get_if<double>(&m_value);
  }

  [[nodiscard]] auto try_get_bool() const noexcept -> const bool*
  {
    return std::get_if<bool>(&m_value);
  }

  [[nodiscard]] auto is_string() const noexcept -> bool
  {
    return std::holds_alternative<string_type>(m_value);
  }

  [[nodiscard]] auto is_int() const noexcept -> bool
  {
    return std::holds_alternative<int64>(m_value);
  }

  [[nodiscard]] auto is_uint() const noexcept -> bool
  {
    return std::holds_alternative<uint64>(m_value);
  }

  [[nodiscard]] auto is_float() const noexcept -> bool
  {
    return std::holds_alternative<double>(m_value);
  }

  [[nodiscard]] auto is_bool() const noexcept -> bool
  {
    return std::holds_alternative<bool>(m_value);
  }

  [[nodiscard]] bool operator==(const basic_ini_value&) const = default;

 private:
  value_type m_value;

  template <typename T>
  void assign(T value) requires is_ini_value<T, char_type>
  {
    if constexpr (std::same_as<T, bool>)
    {
      m_value.template emplace<bool>(std::move(value));
    }
    else if constexpr (std::signed_integral<T>)
    {
      m_value.template emplace<int64>(std::move(value));
    }
    else if constexpr (std::unsigned_integral<T>)
    {
      m_value.template emplace<uint64>(std::move(value));
    }
    else if constexpr (std::floating_point<T>)
    {
      m_value.template emplace<double>(std::move(value));
    }
    else /*if constexpr (std::convertible_to<T, string_type>)*/
    {
      m_value.template emplace<string_type>(std::move(value));
    }
  }
};

using ini_value = basic_ini_value<char>;

template <typename Char>
auto operator<<(std::ostream& stream, const basic_ini_value<Char>& value) -> std::ostream&
{
  if (const auto* str = value.try_get_string())
  {
    stream << *str;
  }
  else if (const auto* i = value.try_get_int())
  {
    stream << std::to_string(*i);
  }
  else if (const auto* u = value.try_get_uint())
  {
    stream << std::to_string(*u) << 'u';
  }
  else if (const auto* f = value.try_get_float())
  {
    stream << std::to_string(*f);
  }
  else if (const auto* b = value.try_get_bool())
  {
    stream << ((*b) ? "true" : "false");
  }

  return stream;
}

/// \} End of ini

/// \} End of group io

}  // namespace rune

#endif  // RUNE_IO_INI_VALUE_HPP


namespace rune {

/// \addtogroup io
/// \{

/// \name Ini
/// \{

template <typename Char>
struct ini_format final
{
  using value_type = Char;

  value_type section_start = '[';
  value_type section_end = ']';
  value_type assign = '=';
  value_type comment = ';';
};

template <typename Char>
class basic_ini_section final
{
 public:
  using char_type = Char;
  using value_type = basic_ini_value<char_type>;
  using string_type = std::basic_string<char_type>;
  using string_view_type = std::basic_string_view<char_type>;
  using format_type = ini_format<char_type>;
  using size_type = usize;

  void dump(std::ostream& stream, const format_type& format) const
  {
    for (const auto& [key, value] : m_entries)
    {
      stream << key << format.assign << value << '\n';
    }

    stream << '\n';
  }

  template <typename T>
  auto operator[](const T& element) -> value_type&
  {
    // TODO get_or_emplace with string_view_type parameter
    return m_entries[element];
  }

  // TODO erase

  [[nodiscard]] auto at(const string_view_type element) -> value_type&
  {
    if (const auto it = m_entries.find(element); it != m_entries.end())
    {
      return it->second;
    }
    else
    {
      throw rune_error{"basic_ini_section::at(): element does not exist!"};
    }
  }

  [[nodiscard]] auto at(const string_view_type element) const -> const value_type&
  {
    if (const auto it = m_entries.find(element); it != m_entries.end())
    {
      return it->second;
    }
    else
    {
      throw rune_error{"basic_ini_section::at(): element does not exist!"};
    }
  }

  [[nodiscard]] auto contains(const string_view_type element) const -> bool
  {
    return m_entries.find(element) != m_entries.end();
  }

  [[nodiscard]] auto size() const noexcept -> size_type
  {
    return m_entries.size();
  }

  [[nodiscard]] auto empty() const noexcept -> bool
  {
    return m_entries.empty();
  }

 private:
  std::map<string_type, value_type, std::less<>> m_entries;
};

/// \} End of ini

/// \} End of group IO

}  // namespace rune

#endif  // RUNE_IO_INI_SECTION_HPP

// #include "ini_value.hpp"


namespace rune {

/// \addtogroup io
/// \{

/// \name Ini
/// \{

template <typename Char>
class basic_ini final
{
 public:
  using char_type = Char;
  using string_type = std::basic_string<char_type>;
  using string_view_type = std::basic_string_view<char_type>;
  using section_type = basic_ini_section<char_type>;
  using format_type = ini_format<char_type>;
  using size_type = usize;
  using iterator = typename std::map<string_type, section_type>::iterator;
  using const_iterator = typename std::map<string_type, section_type>::const_iterator;

  /**
   * \brief Creates an empty Ini file.
   *
   * \param format optional custom format.
   */
  explicit basic_ini(const format_type format = format_type{}) : m_format{format}
  {}

  /**
   * \brief Parses an `.ini` file based on an input stream.
   *
   * \param stream the input stream that will be read.
   */
  void read(std::istream& stream)
  {
    string_type line;
    string_type section;

    line.reserve(32);
    section.reserve(32);

    while (std::getline(stream, line))
    {
      trim_left(line);
      trim_right(line);
      parse_line(line, section);
    }
  }

  /**
   * \brief Writes the contents of the instance to a stream.
   *
   * \param stream the output stream that will be used.
   */
  void write(std::ostream& stream) const
  {
    for (const auto& [name, values] : m_sections)
    {
      stream << m_format.section_start << name << m_format.section_end << '\n';
      values.dump(stream, m_format);
    }
  }

  /**
   * \brief Adds or replaces a section.
   *
   * \param section the name of the section that will be added or replaced.
   *
   * \return the new section.
   */
  auto emplace_or_replace(string_type section) -> section_type&
  {
    const auto [it, inserted] =
        m_sections.insert_or_assign(std::move(section), section_type{});
    return it->second;
  }

  /**
   * \brief Returns the section with the specified name if there is one, adding a new
   * section if it doesn't exist.
   *
   * \param section the name of the desired section.
   *
   * \return the existing section associated with the specified name or a new section if
   * no such section existed.
   */
  auto get_or_emplace(const string_view_type section) -> section_type&
  {
    if (const auto it = m_sections.find(section); it != m_sections.end())
    {
      return it->second;
    }
    else
    {
      auto [iterator, inserted] = m_sections.try_emplace(string_type{section});
      assert(inserted);

      return iterator->second;
    }
  }

  /// \copydoc get_or_emplace()
  auto operator[](const string_view_type section) -> section_type&
  {
    return get_or_emplace(section);
  }

  void erase(const string_view_type section)
  {
    if (const auto it = m_sections.find(section); it != m_sections.end())
    {
      m_sections.erase(it);
    }
  }

  /**
   * \brief Returns the existing section associated with the specified name.
   *
   * \param section the name of the desired section.
   *
   * \return the section with the specified name.
   *
   * \throws rune_error if there is no section with the specified name.
   */
  [[nodiscard]] auto at(const string_view_type section) -> section_type&
  {
    if (const auto it = m_sections.find(section); it != m_sections.end())
    {
      return it->second;
    }
    else
    {
      throw rune_error{"basic_ini::at(): section does not exist!"};
    }
  }

  /// \copydoc at()
  [[nodiscard]] auto at(const string_view_type section) const -> const section_type&
  {
    if (const auto it = m_sections.find(section); it != m_sections.end())
    {
      return it->second;
    }
    else
    {
      throw rune_error{"basic_ini::at(): section does not exist!"};
    }
  }

  /**
   * \brief Indicates whether or not the specified section exists.
   *
   * \param section the name of the section to look for.
   *
   * \return `true` if the specified section exists; `false` otherwise.
   */
  [[nodiscard]] auto contains(const string_view_type section) const -> bool
  {
    return m_sections.find(section) != m_sections.end();
  }

  /**
   * \brief Returns the number of sections stored in the `.ini` file.
   *
   * \return the number of sections.
   */
  [[nodiscard]] auto size() const noexcept -> size_type
  {
    return m_sections.size();
  }

  /**
   * \brief Indicates whether or not there are no sections.
   *
   * \return `true` if there are no sections; `false` otherwise.
   */
  [[nodiscard]] auto empty() const noexcept -> bool
  {
    return m_sections.empty();
  }

  /**
   * \brief Indicates whether or not the parsed contents were valid.
   *
   * \return `true` if there are no parse errors associated with the instance; `false`
   * otherwise.
   */
  [[nodiscard]] explicit operator bool() const noexcept
  {
    return m_errors.empty();
  }

  [[nodiscard]] auto errors() const -> const std::vector<string_type>&
  {
    return m_errors;
  }

  [[nodiscard]] auto begin() noexcept -> iterator
  {
    return m_sections.begin();
  }

  [[nodiscard]] auto begin() const noexcept -> const_iterator
  {
    return m_sections.begin();
  }

  [[nodiscard]] auto end() noexcept -> iterator
  {
    return m_sections.end();
  }

  [[nodiscard]] auto end() const noexcept -> const_iterator
  {
    return m_sections.end();
  }

 private:
  std::map<string_type, section_type, std::less<>> m_sections;
  std::vector<string_type> m_errors;
  format_type m_format;

  template <typename T>
  [[nodiscard]] static auto find_first_non_space(const T begin, const T end)
  {
    return std::find_if(begin, end, [](const char_type ch) {
      return !std::isspace(ch, std::locale::classic());
    });
  }

  // Remove leading whitespace
  void trim_left(string_type& line)
  {
    line.erase(line.begin(), find_first_non_space(line.begin(), line.end()));
  }

  // Remove any trailing whitespace
  void trim_right(string_type& line)
  {
    const auto it = find_first_non_space(line.rbegin(), line.rend());
    line.erase(it.base(), line.end());
  }

  [[nodiscard]] static auto is_unsigned(const string_type& str)
  {
    return !str.starts_with('-') && str.ends_with('u') &&
           std::all_of(str.begin(), str.end() - 1, [](const char_type ch) {
             return std::isdigit(ch, std::locale::classic());
           });
  }

  [[nodiscard]] static auto is_signed(const string_type& str)
  {
    if (str.starts_with('-'))
    {
      // Ignore leading minus
      return std::all_of(str.begin() + 1, str.end(), [](const char_type ch) {
        return std::isdigit(ch, std::locale::classic());
      });
    }
    else
    {
      return std::ranges::all_of(str, [](const char_type ch) {
        return std::isdigit(ch, std::locale::classic());
      });
    }
  }

  auto parse_variable(const string_type& line, const string_type& sectionName) -> bool
  {
    const auto assignment = std::ranges::find_if(line, [this](const char_type character) {
      return character == m_format.assign;
    });

    string_type variable{line.begin(), assignment};
    string_type value{assignment + 1, line.end()};

    trim_right(variable);
    trim_left(variable);

    auto& section = m_sections[sectionName];
    if (!section.contains(variable))
    {
      if (value == "true")
      {
        section[std::move(variable)] = true;
      }
      else if (value == "false")
      {
        section[std::move(variable)] = false;
      }
      else if (is_unsigned(value))
      {
        section[std::move(variable)] = std::stoul(value);
      }
      else if (is_signed(value))
      {
        section[std::move(variable)] = std::stoll(value);
      }
      else
      {
        section[std::move(variable)] = std::move(value);
      }

      return true;
    }
    else
    {
      m_errors.push_back(line);
      return false;
    }
  }

  [[nodiscard]] auto parse_section_name(const string_type& line) -> maybe<string_type>
  {
    if (line.back() == m_format.section_end)
    {
      return line.substr(1, line.length() - 2);
    }
    else
    {
      m_errors.push_back(line);
      return nothing;
    }
  }

  void parse_line(const string_type& line, string_type& section)
  {
    if (line.empty())
    {
      return;
    }

    const auto& character = line.front();

    if (character == m_format.comment)
    {
      return;
    }

    if (character == m_format.section_start)
    {
      if (const auto name = parse_section_name(line))
      {
        section = *name;
      }
    }
    else if (parse_variable(line, section))
    {}
    else
    {
      m_errors.push_back(line);
    }
  }
};

/// Alias for the most likely `basic_ini` type.
using ini_file = basic_ini<char>;

/**
 * \brief Writes a `basic_ini` instance to an output stream.
 *
 * \tparam Char the character type used.
 *
 * \param stream the output stream that will be used.
 * \param ini the `basic_ini` instance that will be written to the stream.
 *
 * \return the used stream.
 *
 * \see `basic_ini::write()`
 */
template <typename Char>
auto operator<<(std::ostream& stream, const basic_ini<Char>& ini) -> std::ostream&
{
  ini.write(stream);
  return stream;
}

/**
 * \brief Parses an `.ini` file from an input stream.
 *
 * \tparam Char the character type used.
 *
 * \param stream the input stream.
 * \param[out] ini the `basic_ini` instance that will be written to.
 *
 * \return the read input stream.
 *
 * \see `basic_ini::read()`
 * \see `read_ini()`
 */
template <typename Char>
auto operator>>(std::istream& stream, basic_ini<Char>& ini) -> std::istream&
{
  ini.read(stream);
  return stream;
}

/**
 * \brief Parses an `.ini` file and returns its contents.
 *
 * \pre `path` must feature the `.ini` extension.
 *
 * \tparam Char the character type used.
 *
 * \param path the file path of the `.ini` file.
 *
 * \return the parsed contents of the `.ini` file.
 */
template <typename Char = char>
[[nodiscard]] auto read_ini(const std::filesystem::path& path) -> basic_ini<Char>
{
  assert(path.extension() == ".ini");
  std::ifstream stream{path};

  ini_file file;
  stream >> file;

  return file;
}

/**
 * \brief Saves an Ini file to the specified file path.
 *
 * \pre `path` must feature the `.ini` extension.
 *
 * \tparam Char the character type used.
 *
 * \param ini the Ini file that will be saved.
 * \param path the file path of the ini file.
 */
template <typename Char>
void write_ini(const basic_ini<Char>& ini, const std::filesystem::path& path)
{
  assert(path.extension() == ".ini");
  std::ofstream stream{path};
  stream << ini;
}

/// \} End of ini

/// \} End of group io

}  // namespace rune

#endif  // RUNE_IO_INI_HPP

// #include "io/ini_value.hpp"
#ifndef RUNE_IO_INI_VALUE_HPP
#define RUNE_IO_INI_VALUE_HPP

#include <concepts>     // convertible_to, integral, floating_point, same_as
#include <nenya.hpp>    // strong_type
#include <ostream>      // ostream
#include <string>       // basic_string, to_string
#include <string_view>  // basic_string_view
#include <utility>      // move
#include <variant>      // variant, get, get_if, holds_alternative

// #include "../aliases/integers.hpp"


namespace rune {

/// \addtogroup io
/// \{

/// \name Ini
/// \{

// clang-format off

template <typename T, typename Char>
concept is_ini_value = std::integral<T> ||
                       std::floating_point<T> ||
                       std::constructible_from<std::basic_string<Char>, T>;

// clang-format on

template <typename Char>
class basic_ini_value final
{
 public:
  using char_type = Char;
  using string_type = std::basic_string<char_type>;
  using string_view_type = std::basic_string_view<char_type>;
  using value_type = std::variant<string_type, bool, int64, uint64, double>;

  basic_ini_value() = default;

  basic_ini_value(const basic_ini_value&) = default;
  basic_ini_value(basic_ini_value&&) noexcept = default;

  basic_ini_value& operator=(const basic_ini_value&) = default;
  basic_ini_value& operator=(basic_ini_value&&) noexcept = default;

  template <typename T>
  /*implicit*/ basic_ini_value(T value) requires is_ini_value<T, char_type>  // NOLINT
  {
    assign(std::move(value));
  }

  template <typename T>
  basic_ini_value& operator=(T value) requires is_ini_value<T, char_type>
  {
    assign(std::move(value));
    return *this;
  }

  // clang-format off

  template <typename T> requires is_ini_value<T, char_type>
  [[nodiscard]] auto get() const -> T
  {
    static_assert(std::convertible_to<T, string_type> ||
                  std::signed_integral<T> ||
                  std::unsigned_integral<T> ||
                  std::floating_point<T> ||
                  std::same_as<T, bool>,
                  "Invalid template type parameter to basic_ini_value::get!");
    // clang-format on

    if constexpr (std::same_as<T, bool>)
    {
      return std::get<bool>(m_value);
    }
    else if constexpr (std::signed_integral<T>)
    {
      return static_cast<T>(std::get<int64>(m_value));
    }
    else if constexpr (std::unsigned_integral<T>)
    {
      return static_cast<T>(std::get<uint64>(m_value));
    }
    else if constexpr (std::floating_point<T>)
    {
      return static_cast<T>(std::get<double>(m_value));
    }
    else /*if constexpr (std::convertible_to<T, string_type>)*/
    {
      return std::get<string_type>(m_value);
    }
  }

  void get_to(string_type& value) const
  {
    value = std::get<string_type>(m_value);
  }

  void get_to(bool& value) const
  {
    value = std::get<bool>(m_value);
  }

  void get_to(int8& value) const
  {
    value = static_cast<int8>(std::get<int64>(m_value));
  }

  void get_to(int16& value) const
  {
    value = static_cast<int16>(std::get<int64>(m_value));
  }

  void get_to(int32& value) const
  {
    value = static_cast<int32>(std::get<int64>(m_value));
  }

  void get_to(int64& value) const
  {
    value = std::get<int64>(m_value);
  }

  void get_to(uint8& value) const
  {
    value = static_cast<uint8>(std::get<uint64>(m_value));
  }

  void get_to(uint16& value) const
  {
    value = static_cast<uint16>(std::get<uint64>(m_value));
  }

  void get_to(uint32& value) const
  {
    value = static_cast<uint32>(std::get<uint64>(m_value));
  }

  void get_to(uint64& value) const
  {
    value = std::get<uint64>(m_value);
  }

  void get_to(float& value) const
  {
    value = static_cast<float>(std::get<double>(m_value));
  }

  void get_to(double& value) const
  {
    value = std::get<double>(m_value);
  }

  // clang-format off

  template <typename T, typename Tag, nenya::conversion Conv> requires is_ini_value<T, char_type>
  void get_to(nenya::strong_type<T, Tag, Conv>& value) const
  {
    using strong_type = nenya::strong_type<T, Tag, Conv>;

    if constexpr (std::same_as<T, bool>)
    {
      value = strong_type{static_cast<T>(std::get<bool>(m_value))};
    }
    else if constexpr (std::signed_integral<T>)
    {
      value = strong_type{static_cast<T>(std::get<int64>(m_value))};
    }
    else if constexpr (std::unsigned_integral<T>)
    {
      value = strong_type{static_cast<T>(std::get<uint64>(m_value))};
    }
    else if constexpr (std::floating_point<T>)
    {
      value = strong_type{static_cast<T>(std::get<double>(m_value))};
    }
    else /*if constexpr (std::convertible_to<T, string_type>)*/
    {
      value = strong_type{static_cast<T>(std::get<string_type>(m_value))};
    }
  }

  // clang-format on

  [[nodiscard]] auto get() const -> const value_type&
  {
    return m_value;
  }

  [[nodiscard]] auto try_get_string() const noexcept -> const string_type*
  {
    return std::get_if<string_type>(&m_value);
  }

  [[nodiscard]] auto try_get_int() const noexcept -> const int64*
  {
    return std::get_if<int64>(&m_value);
  }

  [[nodiscard]] auto try_get_uint() const noexcept -> const uint64*
  {
    return std::get_if<uint64>(&m_value);
  }

  [[nodiscard]] auto try_get_float() const noexcept -> const double*
  {
    return std::get_if<double>(&m_value);
  }

  [[nodiscard]] auto try_get_bool() const noexcept -> const bool*
  {
    return std::get_if<bool>(&m_value);
  }

  [[nodiscard]] auto is_string() const noexcept -> bool
  {
    return std::holds_alternative<string_type>(m_value);
  }

  [[nodiscard]] auto is_int() const noexcept -> bool
  {
    return std::holds_alternative<int64>(m_value);
  }

  [[nodiscard]] auto is_uint() const noexcept -> bool
  {
    return std::holds_alternative<uint64>(m_value);
  }

  [[nodiscard]] auto is_float() const noexcept -> bool
  {
    return std::holds_alternative<double>(m_value);
  }

  [[nodiscard]] auto is_bool() const noexcept -> bool
  {
    return std::holds_alternative<bool>(m_value);
  }

  [[nodiscard]] bool operator==(const basic_ini_value&) const = default;

 private:
  value_type m_value;

  template <typename T>
  void assign(T value) requires is_ini_value<T, char_type>
  {
    if constexpr (std::same_as<T, bool>)
    {
      m_value.template emplace<bool>(std::move(value));
    }
    else if constexpr (std::signed_integral<T>)
    {
      m_value.template emplace<int64>(std::move(value));
    }
    else if constexpr (std::unsigned_integral<T>)
    {
      m_value.template emplace<uint64>(std::move(value));
    }
    else if constexpr (std::floating_point<T>)
    {
      m_value.template emplace<double>(std::move(value));
    }
    else /*if constexpr (std::convertible_to<T, string_type>)*/
    {
      m_value.template emplace<string_type>(std::move(value));
    }
  }
};

using ini_value = basic_ini_value<char>;

template <typename Char>
auto operator<<(std::ostream& stream, const basic_ini_value<Char>& value) -> std::ostream&
{
  if (const auto* str = value.try_get_string())
  {
    stream << *str;
  }
  else if (const auto* i = value.try_get_int())
  {
    stream << std::to_string(*i);
  }
  else if (const auto* u = value.try_get_uint())
  {
    stream << std::to_string(*u) << 'u';
  }
  else if (const auto* f = value.try_get_float())
  {
    stream << std::to_string(*f);
  }
  else if (const auto* b = value.try_get_bool())
  {
    stream << ((*b) ? "true" : "false");
  }

  return stream;
}

/// \} End of ini

/// \} End of group io

}  // namespace rune

#endif  // RUNE_IO_INI_VALUE_HPP

// #include "io/json_utils.hpp"
#ifndef RUNE_IO_JSON_UTILS_HPP
#define RUNE_IO_JSON_UTILS_HPP

#include <cassert>      // assert
#include <concepts>     // same_as
#include <filesystem>   // path
#include <fstream>      // ifstream
#include <string_view>  // string_view
#include <variant>      // variant
#include <vector>       // vector

// #include "../aliases/json_type.hpp"
#ifndef RUNE_ALIASES_JSON_TYPE_HPP
#define RUNE_ALIASES_JSON_TYPE_HPP

#include <json.hpp>  // json

namespace rune {

using json_type = nlohmann::json;

}  // namespace rune

#endif  // RUNE_ALIASES_JSON_TYPE_HPP

// #include "../aliases/maybe.hpp"

// #include "../core/rune_error.hpp"

// #include "rune_api.hpp"


namespace rune {

/// \addtogroup io
/// \{

/// \name JSON
/// \{

// clang-format off

template <typename T>
concept json_serializable_type = requires (json_type json)
{
  { json.get<T>() };
};

// clang-format on

/**
 * \brief Parses the JSON file at the specified path, and returns the contents.
 *
 * \pre `file` must refer to a JSON file.
 *
 * \param file the file path of the JSON file.
 *
 * \return the parsed JSON data.
 */
[[nodiscard]] inline auto read_json(const std::filesystem::path& file) -> json_type
{
  assert(file.extension() == ".json");
  std::ifstream stream{file};

  json_type json;
  stream >> json;

  return json;
}

/// \} End of JSON

/// \} End of group io

namespace io {

/// \addtogroup io
/// \{

/// \name JSON
/// \{

/**
 * \brief Fills a vector with values from a JSON array.
 *
 * \pre `array` must represent a JSON array.
 *
 * \param array the JSON array that provides the source data.
 * \param[out] container the vector that will be filled.
 *
 * \see `try_get_to()`
 *
 * \since 0.1.0
 */
template <json_serializable_type T>
void get_to(const json_type& array, std::vector<T>& container)
{
  assert(array.is_array());

  container.reserve(array.size());
  for (const auto& [key, value] : array.items())
  {
    container.push_back(value.template get<T>());
  }
}

/**
 * \brief Fills a vector with values from a JSON array in a JSON object.
 *
 * \pre The JSON element associated with the specified key must be an array.
 *
 * \param json the JSON object that contains an array associated with the specified key.
 * \param key the key of the child JSON array element.
 * \param[out] container the vector that will be filled.
 *
 * \see `try_get_to()`
 *
 * \throws rune_error if there is no key with the specified name.
 *
 * \since 0.1.0
 */
template <json_serializable_type T>
void get_to(const json_type& json, const std::string_view key, std::vector<T>& container)
{
  const auto it = json.find(key);
  if (it == json.end())
  {
    throw rune_error{"io::get_to(): key does not exist"};
  }

  assert(it->is_array());
  container.reserve(it->size());
  for (const auto& [key, value] : it->items())
  {
    container.push_back(value.template get<T>());
  }
}

/**
 * \brief Attempts to serialize and assign a value.
 *
 * \details This function has no effect if there is no element associated with the
 * specified key.
 *
 * \tparam T the type of the serializable value.
 *
 * \param json the source JSON object.
 * \param key the key associated with the desired JSON value.
 * \param[out] value the value that will be assigned.
 *
 * \see `get_to()`
 */
template <json_serializable_type T>
void try_get_to(const json_type& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

/// \copydoc try_get_to()
template <json_serializable_type T>
void try_get_to(const json_type& json, const std::string_view key, maybe<T>& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

/**
 * \brief Fills a vector with values from a JSON array, if it exists.
 *
 * \note This function has no effect if there is no element associated with the specified
 * key.
 *
 * \pre The JSON element associated with the specified key must be an array.
 *
 * \param json the JSON object that contains an array associated with the specified key.
 * \param key the key of the JSON array element.
 * \param[out] container the vector that will be filled.
 *
 * \see `get_to()`
 *
 * \since 0.1.0
 */
template <json_serializable_type T>
void try_get_to(const json_type& json,
                const std::string_view key,
                std::vector<T>& container)
{
  if (const auto it = json.find(key); it != json.end())
  {
    assert(it->is_array());
    container.reserve(it->size());
    for (const auto& [key, value] : it->items())
    {
      container.push_back(value.template get<T>());
    }
  }
}

/**
 * \brief Assigns a wrapper from a serializable value.
 *
 * \tparam T the type of the wrapper.
 *
 * \param json the source JSON object.
 * \param key the key associated with the desired JSON value.
 * \param[out] value the value that will be assigned.
 *
 * \throws rune_error if there is no key with the specified name.
 *
 * \see `try_emplace_to()`
 *
 * \since 0.1.0
 */
template <typename T>
  requires json_serializable_type<typename T::value_type>
void emplace_to(const json_type& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = T{it->get<typename T::value_type>()};
  }
  else
  {
    throw rune_error{"io::emplace_to(): key does not exist"};
  }
}

/// \copydoc emplace_to()
template <typename T>
  requires json_serializable_type<typename T::value_type>
void emplace_to(const json_type& json, const std::string_view key, maybe<T>& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = T{it->get<typename T::value_type>()};
  }
  else
  {
    throw rune_error{"io::emplace_to(): key does not exist"};
  }
}

/**
 * \brief Attempts to assign a wrapper from a serializable value.
 *
 * \details This function has no effect if there is no element associated with the
 * specified key.
 *
 * \tparam T the type of the wrapper.
 *
 * \param json the source JSON object.
 * \param key the key associated with the desired JSON value.
 * \param[out] value the value that will be assigned.
 *
 * \see `emplace_to()`
 *
 * \since 0.1.0
 */
template <json_serializable_type T, typename... Types>
void try_emplace_to(const json_type& json,
                    const std::string_view key,
                    std::variant<Types...>& value)
{
  static_assert((std::same_as<T, Types> || ...),
                "Cannot emplace value of type that is not used by the variant!");

  if (const auto it = json.find(key); it != json.end())
  {
    value.template emplace<T>(it->get<T>());
  }
}

/// \} End of JSON

/// \} End of group io

}  // namespace io

}  // namespace rune

#endif  // RUNE_IO_JSON_UTILS_HPP

// #include "math/almost_equal.hpp"
#ifndef RUNE_MATH_ALMOST_EQUAL_HPP
#define RUNE_MATH_ALMOST_EQUAL_HPP

#include <cmath>     // abs
#include <concepts>  // floating_point

namespace rune {

/// \addtogroup math
/// \{

// clang-format off

/// The default epsilon value used for floating point comparisons.
inline constexpr float default_epsilon = 0.00001f;

/**
 * \brief Indicates whether or not two floating-point values are almost equal.
 *
 * \details The two values are considered equal if the absolute value of their difference
 * is in the range [0, `epsilon`).
 *
 * \param a the first value.
 * \param b the second value.
 * \param epsilon the epsilon value.
 *
 * \return `true` if the values are almost equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] auto almost_equal(const T a,
                                const T b,
                                const T epsilon = default_epsilon) noexcept(noexcept(std::abs(a)))
    -> bool
{
  return std::abs(a - b) < epsilon;
}

// clang-format on

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_ALMOST_EQUAL_HPP

// #include "math/index_to_matrix.hpp"
#ifndef RUNE_MATH_INDEX_TO_MATRIX_HPP
#define RUNE_MATH_INDEX_TO_MATRIX_HPP

#include <concepts>  // integral

namespace rune {

/// \addtogroup math
/// \{

template <std::integral T>
struct matrix_position final
{
  T row{};
  T column{};
};

template <std::integral T = int>
[[nodiscard]] constexpr auto index_to_matrix(const T index, const T nColumns) noexcept
    -> matrix_position<T>
{
  return {.row = index / nColumns, .column = index % nColumns};
}

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_INDEX_TO_MATRIX_HPP

// #include "math/max.hpp"
#ifndef RUNE_MATH_MAX_HPP
#define RUNE_MATH_MAX_HPP

#include <concepts>

namespace rune {

/**
 * \brief Returns the largest of two values.
 *
 * \note This function exists because `std::max()` isn't marked as `noexcept`.
 *
 * \note This function uses `operator<`, and not `operator>`.
 *
 * \ingroup math
 *
 * \tparam T the type of the values.
 *
 * \param a the first value.
 * \param b the second value.
 *
 * \return the largest of the two values.
 */
template <typename T>
[[nodiscard]] constexpr auto max(const T& a, const T& b) noexcept(noexcept(a < b)) -> T
{
  return (a < b) ? b : a;
}

}  // namespace rune

#endif  // RUNE_MATH_MAX_HPP

// #include "math/min.hpp"
#ifndef RUNE_MATH_MIN_HPP
#define RUNE_MATH_MIN_HPP

namespace rune {

/**
 * \brief Returns the smallest of two values.
 *
 * \note This function exists because `std::min()` isn't marked as `noexcept`.
 *
 * \ingroup math
 *
 * \tparam T the type of the values.
 *
 * \param a the first value.
 * \param b the second value.
 *
 * \return the smallest of the two values.
 */
template <typename T>
[[nodiscard]] constexpr auto min(const T& a, const T& b) noexcept(noexcept(a < b)) -> T
{
  return (a < b) ? a : b;
}

}  // namespace rune

#endif  // RUNE_MATH_MIN_HPP

// #include "math/random_utils.hpp"
#ifndef RUNE_MATH_RANDOM_UTILS_HPP
#define RUNE_MATH_RANDOM_UTILS_HPP

#include <algorithm>   // generate
#include <array>       // array
#include <concepts>    // floating_point, integral
#include <functional>  // ref
#include <random>      // mt19937, random_device, uniform_int_distribution, ...

namespace rune {

/// \addtogroup math
/// \{

/// \name Random number generation
/// \{

/// \brief The random engine type used by the RNG functions.
using random_engine = std::mt19937;

/**
 * \brief Creates and returns a seeded random engine.
 *
 * \return a seeded random engine.
 */
[[nodiscard]] inline auto make_random_engine() -> random_engine
{
  using result_type = std::random_device::result_type;

  constexpr auto n = random_engine::state_size;

  std::random_device device;
  std::array<result_type, (n - 1) / sizeof(result_type) + 1> data{};

  std::ranges::generate(data, std::ref(device));
  std::seed_seq seeds(data.begin(), data.end());

  return random_engine(seeds);
}

/**
 * \brief Returns a random value in the specified range [min, max].
 *
 * \tparam T the type of the value to be obtained.
 *
 * \param min the minimum possible value.
 * \param max the maximum possible value.
 *
 * \return a random value in the specified range.
 */
template <typename T>
  requires std::integral<T> || std::floating_point<T>
[[nodiscard]] auto next_random(const T min, const T max) -> T
{
  static auto engine = make_random_engine();

  if constexpr (std::floating_point<T>)
  {
    return std::uniform_real_distribution<T>{min, max}(engine);
  }
  else
  {
    return std::uniform_int_distribution<T>{min, max}(engine);
  }
}

/**
 * \brief Returns a random `bool` value.
 *
 * \return a random `bool` value.
 *
 * \see `next_random()`
 */
[[nodiscard]] inline auto next_bool() -> bool
{
  return next_random(0.0, 1.0) > 0.5;
}

/**
 * \brief Returns a random `float` in the interval [0, 1].
 *
 * \return a random `float` value.
 *
 * \see `next_random()`
 */
[[nodiscard]] inline auto next_float() -> float
{
  return next_random(0.0f, 1.0f);
}

/**
 * \brief Returns a random `double` in the interval [0, 1].
 *
 * \return a random `double` value.
 *
 * \see `next_random()`
 */
[[nodiscard]] inline auto next_double() -> double
{
  return next_random(0.0, 1.0);
}

/// \} End of random number generation

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_RANDOM_UTILS_HPP

// #include "math/vector2.hpp"
#ifndef RUNE_MATH_VECTOR2_HPP
#define RUNE_MATH_VECTOR2_HPP

#include <cmath>     // lerp, sqrt
#include <concepts>  // floating_point
#include <ostream>   // ostream
#include <string>    // string, to_string

// #include "almost_equal.hpp"
#ifndef RUNE_MATH_ALMOST_EQUAL_HPP
#define RUNE_MATH_ALMOST_EQUAL_HPP

#include <cmath>     // abs
#include <concepts>  // floating_point

namespace rune {

/// \addtogroup math
/// \{

// clang-format off

/// The default epsilon value used for floating point comparisons.
inline constexpr float default_epsilon = 0.00001f;

/**
 * \brief Indicates whether or not two floating-point values are almost equal.
 *
 * \details The two values are considered equal if the absolute value of their difference
 * is in the range [0, `epsilon`).
 *
 * \param a the first value.
 * \param b the second value.
 * \param epsilon the epsilon value.
 *
 * \return `true` if the values are almost equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] auto almost_equal(const T a,
                                const T b,
                                const T epsilon = default_epsilon) noexcept(noexcept(std::abs(a)))
    -> bool
{
  return std::abs(a - b) < epsilon;
}

// clang-format on

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_ALMOST_EQUAL_HPP


namespace rune {

/// \addtogroup math
/// \{

/**
 * \class basic_vector2
 *
 * \brief A two-dimensional vector with floating point coordinates.
 *
 * \tparam T the representation type, must a floating-point type.
 *
 * \see `float2`
 * \see `double2`
 * \see `almost_equal(const basic_vector2<T>&, const basic_vector2<T>&, T)`
 * \see `distance(const basic_vector2<T>&, const basic_vector2<T>&)`
 * \see `angle(const basic_vector2<T>&, const basic_vector2<T>&)`
 * \see `cross(const basic_vector2<T>&, const basic_vector2<T>&)`
 * \see `dot(const basic_vector2<T>&, const basic_vector2<T>&)`
 */
template <std::floating_point T>
class basic_vector2 final
{
 public:
  using value_type = T;               ///< The type of the coordinates.
  using vector_type = basic_vector2;  ///< The type of the vector itself.

  value_type x{};  ///< The x-coordinate.
  value_type y{};  ///< The y-coordinate.

  /// \name Construction
  /// \{

  /**
   * \brief Creates a zero vector.
   */
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

  /**
   * \brief Turns the vector into a zero vector.
   */
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

  /**
   * \brief Sets the magnitude of the vector.
   *
   * \note If the supplied magnitude is negative, the vector becomes the zero vector.
   *
   * \param length the new magnitude of the vector.
   */
  void set_magnitude(const T length)
  {
    if (length > 0) [[likely]]
    {
      const auto previous = magnitude();
      if (previous != 0 && previous != length)
      {
        scale(length / previous);
      }
    }
    else
    {
      reset();
    }
  }

  /// \} End of mutators

  /// \name Queries
  /// \{

  /// Returns the magnitude, i.e. length, of the vector.

  /**
   * \brief Returns the magnitude (length) of the vector.
   *
   * \return the magnitude of the vector.
   */
  [[nodiscard]] auto magnitude() const -> value_type
  {
    return std::sqrt((x * x) + (y * y));
  }

  /**
   * \brief Returns the squared magnitude of this vector.
   *
   * \details This function can be useful when comparing vectors. It avoids a relatively
   * expensive square root computation.
   *
   * \return the squared magnitude of this vector.
   */
  [[nodiscard]] constexpr auto magnitude2() const noexcept -> value_type
  {
    return (x * x) + (y * y);
  }

  /**
   * \brief Indicates whether or not the vector is a unit vector.
   *
   * \details A unit vector is a vector with length `1`.
   *
   * \return `true` if the vector is a unit vector; `false` otherwise.
   */
  [[nodiscard]] auto is_unit() const -> bool
  {
    return almost_equal(magnitude(), value_type{1});
  }

  /**
   * \brief Indicates whether or not the vector is a zero vector.
   *
   * \details A vector is a zero vector if both of its coordinates are zero.
   *
   * \return `true` if the vector is a zero vector; `false` otherwise.
   */
  [[nodiscard]] auto is_zero() const -> bool
  {
    return almost_equal(x, value_type{0}) && almost_equal(y, value_type{0});
  }

  /// \} End of queries

  /// \name Serialization
  /// \{

  /**
   * \brief Serializes the vector.
   *
   * \param archive the serialization archive that will be used.
   */
  void serialize(auto& archive)
  {
    archive(x, y);
  }

  /// \} End of serialization

  /// \name Comparisons
  /// \{

  /**
   * \brief Indicates whether or not two vectors are *exactly* equal.
   *
   * \return `true` if the vectors are exactly equal; `false` otherwise.
   *
   * \see `almost_equal(const basic_vector2<T>&, const basic_vector2<T>&, T)`
   */
  [[nodiscard]] constexpr bool operator==(const vector_type&) const noexcept = default;

  /// \} End of comparisons
};

/// A two-dimensional vector using `float` precision.
using float2 = basic_vector2<float>;

/// A two-dimensional vector using `double` precision.
using double2 = basic_vector2<double>;

/// \name Vector operators
/// \{

template <std::floating_point T>
constexpr void operator+=(basic_vector2<T>& a, const basic_vector2<T>& b) noexcept
{
  a.x += b.x;
  a.y += b.y;
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator+(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x + rhs.x, lhs.y + rhs.y};
}

template <std::floating_point T>
constexpr void operator-=(basic_vector2<T>& a, const basic_vector2<T>& b) noexcept
{
  a.x -= b.x;
  a.y -= b.y;
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator-(const basic_vector2<T>& lhs,
                                       const basic_vector2<T>& rhs) noexcept
    -> basic_vector2<T>
{
  return basic_vector2{lhs.x - rhs.x, lhs.y - rhs.y};
}

/**
 * \brief Returns the dot product of two vectors.
 *
 * \note The dot product is commutative, which means that the order of
 * the operands doesn't matter.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the dot product of the two vectors.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto operator*(const basic_vector2<T>& a,
                                       const basic_vector2<T>& b) noexcept -> T
{
  return (a.x * b.x) + (a.y * b.y);
}

template <std::floating_point T, typename U>
constexpr void operator*=(basic_vector2<T>& vector, const U factor) noexcept
{
  vector.scale(factor);
}

template <std::floating_point T, typename U>
[[nodiscard]] constexpr auto operator*(const basic_vector2<T>& vector,
                                       const U factor) noexcept -> basic_vector2<T>
{
  return basic_vector2{vector.x * factor, vector.y * factor};
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator*(const T factor,
                                       const basic_vector2<T>& vector) noexcept
    -> basic_vector2<T>
{
  return vector * factor;
}

/// \} End of vector operators

/// \name Vector functions
/// \{

/**
 * \brief Indicates whether or not two vectors are *almost* equal.
 *
 * \param a the first vector.
 * \param b the second vector.
 * \param epsilon the epsilon value that will be used.
 *
 * \return `true` if the vectors are almost equal; `false` otherwise.
 */
template <std::floating_point T>
[[nodiscard]] auto almost_equal(const basic_vector2<T>& a,
                                const basic_vector2<T>& b,
                                const T epsilon = default_epsilon) -> bool
{
  return almost_equal(a.x, b.x, epsilon) && almost_equal(a.y, b.y, epsilon);
}

/**
 * \brief Returns the distance between two vectors.
 *
 * \details The vectors are treated as points in the plane by this function.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the distance between the two points.
 */
template <std::floating_point T>
[[nodiscard]] auto distance(const basic_vector2<T>& a, const basic_vector2<T>& b) -> T
{
  const auto dx = b.x - a.x;
  const auto dy = b.y - a.y;
  return std::sqrt(dx * dx + dy * dy);
}

/**
 * \brief Returns the cross product between two vectors.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the cross product of the vectors.
 */
template <std::floating_point T>
[[nodiscard]] constexpr auto cross(const basic_vector2<T>& a,
                                   const basic_vector2<T>& b) noexcept -> T
{
  return a.x * b.y - a.y * b.x;
}

/// \copydoc operator*(const basic_vector2<T>&, const basic_vector2<T>&)
template <std::floating_point T>
[[nodiscard]] constexpr auto dot(const basic_vector2<T>& a,
                                 const basic_vector2<T>& b) noexcept -> T
{
  return a * b;
}

/**
 * \brief Returns the angle between two vectors.
 *
 * \note This function returns zero if any of the supplied vectors are zero vectors.
 *
 * \param a the first vector.
 * \param b the second vector.
 *
 * \return the angle between the two vectors.
 */
template <std::floating_point T>
[[nodiscard]] auto angle(const basic_vector2<T>& a, const basic_vector2<T>& b) -> T
{
  if (a.is_zero() || b.is_zero() || a == b)
  {
    return 0;
  }

  const auto mag1 = a.magnitude();
  const auto mag2 = b.magnitude();

  const auto cos = (a * b) / mag1 / mag2;
  const auto sin = cross(a, b) / mag1 / mag2;

  if (const auto angle = std::acos(cos); sin < 0)
  {
    return -angle;
  }
  else
  {
    return angle;
  }
}

/// \} End of vector functions

template <std::floating_point T>
[[nodiscard]] auto to_string(const basic_vector2<T> vec) -> std::string
{
  return "vector2{x: " + std::to_string(vec.x) + ", y: " + std::to_string(vec.y) + "}";
}

template <std::floating_point T>
auto operator<<(std::ostream& stream, const basic_vector2<T> vec) -> std::ostream&
{
  return stream << to_string(vec);
}

/// \} End of group math

}  // namespace rune

#endif  // RUNE_MATH_VECTOR2_HPP

// #include "tmx/parse_tileset.hpp"
#ifndef RUNE_TMX_PARSE_TILESET_HPP
#define RUNE_TMX_PARSE_TILESET_HPP

#include <filesystem>  // path
#include <string>      // string

// #include "../aliases/json_type.hpp"
#ifndef RUNE_ALIASES_JSON_TYPE_HPP
#define RUNE_ALIASES_JSON_TYPE_HPP

#include <json.hpp>  // json

namespace rune {

using json_type = nlohmann::json;

}  // namespace rune

#endif  // RUNE_ALIASES_JSON_TYPE_HPP

// #include "../io/json_utils.hpp"
#ifndef RUNE_IO_JSON_UTILS_HPP
#define RUNE_IO_JSON_UTILS_HPP

#include <cassert>      // assert
#include <concepts>     // same_as
#include <filesystem>   // path
#include <fstream>      // ifstream
#include <string_view>  // string_view
#include <variant>      // variant
#include <vector>       // vector

// #include "../aliases/json_type.hpp"
#ifndef RUNE_ALIASES_JSON_TYPE_HPP
#define RUNE_ALIASES_JSON_TYPE_HPP

#include <json.hpp>  // json

namespace rune {

using json_type = nlohmann::json;

}  // namespace rune

#endif  // RUNE_ALIASES_JSON_TYPE_HPP

// #include "../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "../core/rune_error.hpp"
#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

// #include "../aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune


namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const str what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> str override
  {
    return m_what;
  }

 private:
  str m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP

// #include "rune_api.hpp"


namespace rune {

/// \addtogroup io
/// \{

/// \name JSON
/// \{

// clang-format off

template <typename T>
concept json_serializable_type = requires (json_type json)
{
  { json.get<T>() };
};

// clang-format on

/**
 * \brief Parses the JSON file at the specified path, and returns the contents.
 *
 * \pre `file` must refer to a JSON file.
 *
 * \param file the file path of the JSON file.
 *
 * \return the parsed JSON data.
 */
[[nodiscard]] inline auto read_json(const std::filesystem::path& file) -> json_type
{
  assert(file.extension() == ".json");
  std::ifstream stream{file};

  json_type json;
  stream >> json;

  return json;
}

/// \} End of JSON

/// \} End of group io

namespace io {

/// \addtogroup io
/// \{

/// \name JSON
/// \{

/**
 * \brief Fills a vector with values from a JSON array.
 *
 * \pre `array` must represent a JSON array.
 *
 * \param array the JSON array that provides the source data.
 * \param[out] container the vector that will be filled.
 *
 * \see `try_get_to()`
 *
 * \since 0.1.0
 */
template <json_serializable_type T>
void get_to(const json_type& array, std::vector<T>& container)
{
  assert(array.is_array());

  container.reserve(array.size());
  for (const auto& [key, value] : array.items())
  {
    container.push_back(value.template get<T>());
  }
}

/**
 * \brief Fills a vector with values from a JSON array in a JSON object.
 *
 * \pre The JSON element associated with the specified key must be an array.
 *
 * \param json the JSON object that contains an array associated with the specified key.
 * \param key the key of the child JSON array element.
 * \param[out] container the vector that will be filled.
 *
 * \see `try_get_to()`
 *
 * \throws rune_error if there is no key with the specified name.
 *
 * \since 0.1.0
 */
template <json_serializable_type T>
void get_to(const json_type& json, const std::string_view key, std::vector<T>& container)
{
  const auto it = json.find(key);
  if (it == json.end())
  {
    throw rune_error{"io::get_to(): key does not exist"};
  }

  assert(it->is_array());
  container.reserve(it->size());
  for (const auto& [key, value] : it->items())
  {
    container.push_back(value.template get<T>());
  }
}

/**
 * \brief Attempts to serialize and assign a value.
 *
 * \details This function has no effect if there is no element associated with the
 * specified key.
 *
 * \tparam T the type of the serializable value.
 *
 * \param json the source JSON object.
 * \param key the key associated with the desired JSON value.
 * \param[out] value the value that will be assigned.
 *
 * \see `get_to()`
 */
template <json_serializable_type T>
void try_get_to(const json_type& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

/// \copydoc try_get_to()
template <json_serializable_type T>
void try_get_to(const json_type& json, const std::string_view key, maybe<T>& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = it->get<T>();
  }
}

/**
 * \brief Fills a vector with values from a JSON array, if it exists.
 *
 * \note This function has no effect if there is no element associated with the specified
 * key.
 *
 * \pre The JSON element associated with the specified key must be an array.
 *
 * \param json the JSON object that contains an array associated with the specified key.
 * \param key the key of the JSON array element.
 * \param[out] container the vector that will be filled.
 *
 * \see `get_to()`
 *
 * \since 0.1.0
 */
template <json_serializable_type T>
void try_get_to(const json_type& json,
                const std::string_view key,
                std::vector<T>& container)
{
  if (const auto it = json.find(key); it != json.end())
  {
    assert(it->is_array());
    container.reserve(it->size());
    for (const auto& [key, value] : it->items())
    {
      container.push_back(value.template get<T>());
    }
  }
}

/**
 * \brief Assigns a wrapper from a serializable value.
 *
 * \tparam T the type of the wrapper.
 *
 * \param json the source JSON object.
 * \param key the key associated with the desired JSON value.
 * \param[out] value the value that will be assigned.
 *
 * \throws rune_error if there is no key with the specified name.
 *
 * \see `try_emplace_to()`
 *
 * \since 0.1.0
 */
template <typename T>
  requires json_serializable_type<typename T::value_type>
void emplace_to(const json_type& json, const std::string_view key, T& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = T{it->get<typename T::value_type>()};
  }
  else
  {
    throw rune_error{"io::emplace_to(): key does not exist"};
  }
}

/// \copydoc emplace_to()
template <typename T>
  requires json_serializable_type<typename T::value_type>
void emplace_to(const json_type& json, const std::string_view key, maybe<T>& value)
{
  if (const auto it = json.find(key); it != json.end())
  {
    value = T{it->get<typename T::value_type>()};
  }
  else
  {
    throw rune_error{"io::emplace_to(): key does not exist"};
  }
}

/**
 * \brief Attempts to assign a wrapper from a serializable value.
 *
 * \details This function has no effect if there is no element associated with the
 * specified key.
 *
 * \tparam T the type of the wrapper.
 *
 * \param json the source JSON object.
 * \param key the key associated with the desired JSON value.
 * \param[out] value the value that will be assigned.
 *
 * \see `emplace_to()`
 *
 * \since 0.1.0
 */
template <json_serializable_type T, typename... Types>
void try_emplace_to(const json_type& json,
                    const std::string_view key,
                    std::variant<Types...>& value)
{
  static_assert((std::same_as<T, Types> || ...),
                "Cannot emplace value of type that is not used by the variant!");

  if (const auto it = json.find(key); it != json.end())
  {
    value.template emplace<T>(it->get<T>());
  }
}

/// \} End of JSON

/// \} End of group io

}  // namespace io

}  // namespace rune

#endif  // RUNE_IO_JSON_UTILS_HPP

// #include "tmx_global_id.hpp"
#ifndef RUNE_TMX_GLOBAL_ID_HPP
#define RUNE_TMX_GLOBAL_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "../aliases/integers.hpp"
#ifndef RUNE_ALIASES_INTEGERS_HPP
#define RUNE_ALIASES_INTEGERS_HPP

#include <centurion.hpp>  // ...
#include <cstddef>        // size_t

namespace rune {

/// \addtogroup core
/// \{

using usize = std::size_t;

using longlong = long long;

using ushort = unsigned short;

/// Unsigned integer.
using uint = unsigned;

/// Unsigned long integer.
using ulong = unsigned long;

/// Used as the argument type to integral literal operators.
using ulonglong = unsigned long long;

/// 8-bit signed integer.
using int8 = cen::i8;

/// 16-bit signed integer.
using int16 = cen::i16;

/// 32-bit signed integer.
using int32 = cen::i32;

/// 64-bit signed integer.
using int64 = cen::i64;

/// 8-bit unsigned integer.
using uint8 = cen::u8;

/// 16-bit unsigned integer.
using uint16 = cen::u16;

/// 32-bit unsigned integer.
using uint32 = cen::u32;

/// 64-bit unsigned integer.
using uint64 = cen::u64;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_INTEGERS_HPP


namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_global_id_tag;
}
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_global_id = nenya::strong_type<uint, tags::tmx_global_id_tag>;

/// \} End of group tmx

namespace tmx_literals {

/// \addtogroup tmx
/// \{

/// \name Literal operators
/// \{

[[nodiscard]] constexpr auto operator""_global(const ulonglong value) noexcept
    -> tmx_global_id
{
  return tmx_global_id{static_cast<tmx_global_id::value_type>(value)};
}

/// \} End of literal operators
/// \} End of group tmx

}  // namespace tmx_literals
}  // namespace rune

#endif  // RUNE_TMX_GLOBAL_ID_HPP

// #include "tmx_tileset.hpp"
#ifndef RUNE_TMX_TILESET_HPP
#define RUNE_TMX_TILESET_HPP

#include <string>  // string
#include <vector>  // vector

// #include "../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP

// #include "rune_api.hpp"

// #include "tmx_color.hpp"
#ifndef RUNE_TMX_COLOR_HPP
#define RUNE_TMX_COLOR_HPP

#include <cassert>      // assert
#include <string>       // string
#include <string_view>  // string_view

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../core/from_string.hpp"
#ifndef RUNE_CORE_FROM_STRING_HPP
#define RUNE_CORE_FROM_STRING_HPP

#include <charconv>      // from_chars
#include <string_view>   // string_view
#include <system_error>  // errc

// #include "../aliases/maybe.hpp"
#ifndef RUNE_ALIASES_MAYBE_HPP
#define RUNE_ALIASES_MAYBE_HPP

#include <optional>  // optional

namespace rune {

template <typename T>
using maybe = std::optional<T>;

inline constexpr std::nullopt_t nothing = std::nullopt;

}  // namespace rune

#endif  // RUNE_ALIASES_MAYBE_HPP


namespace rune {

/// \addtogroup core
/// \{

template <typename T>
[[nodiscard]] auto from_string(const std::string_view str, const int base = 10)
    -> maybe<T>
{
  T value{};

  const auto [ptr, error] =
      std::from_chars(str.data(), str.data() + str.size(), value, base);
  if (error != std::errc::invalid_argument && error != std::errc::result_out_of_range)
  {
    return value;
  }
  else
  {
    return nothing;
  }
}

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_FROM_STRING_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_color final
{
  uint8 red{};
  uint8 green{};
  uint8 blue{};
  uint8 alpha{0xFF};

  [[nodiscard]] constexpr bool operator==(const tmx_color&) const noexcept = default;
};

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

inline constexpr tmx_color black{0, 0, 0, 0xFF};

[[nodiscard]] inline auto from_hex(const std::string_view str) -> uint8
{
  assert(str.size() == 2);
  return from_string<uint8>(str, 16).value();
}

[[nodiscard]] inline auto make_color(const std::string_view str) -> tmx_color
{
  assert(str.size() == 7 || str.size() == 9);
  assert(str.at(0) == '#');

  const auto noHash = str.substr(1);
  const auto length = noHash.size();

  tmx_color result;

  if (length == 8)
  {
    // ARGB
    result.alpha = from_hex(noHash.substr(0, 2));
    result.red = from_hex(noHash.substr(2, 2));
    result.green = from_hex(noHash.substr(4, 2));
    result.blue = from_hex(noHash.substr(6, 2));
  }
  else
  {
    // RGB
    result.red = from_hex(noHash.substr(0, 2));
    result.green = from_hex(noHash.substr(2, 2));
    result.blue = from_hex(noHash.substr(4, 2));
  }

  return result;
}

/// \} End of group tmx

}  // namespace tmx

inline void from_json(const json_type& json, tmx_color& color)
{
  color = tmx::make_color(json.get<std::string>());
}

}  // namespace rune

#endif  // RUNE_TMX_COLOR_TEST

// #include "tmx_global_id.hpp"

// #include "tmx_grid.hpp"
#ifndef RUNE_TMX_GRID_HPP
#define RUNE_TMX_GRID_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

// #include "../aliases/json_type.hpp"

// #include "rune_api.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_grid_orientation
{
  orthogonal,
  isometric
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_grid_orientation,
                             {{tmx_grid_orientation::orthogonal, "orthogonal"},
                              {tmx_grid_orientation::isometric, "isometric"}})

struct tmx_grid final
{
  int cell_width{};
  int cell_height{};
  tmx_grid_orientation orientation{tmx_grid_orientation::orthogonal};
};

inline void from_json(const json_type& json, tmx_grid& grid)
{
  json.at("width").get_to(grid.cell_width);
  json.at("height").get_to(grid.cell_height);
  json.at("orientation").get_to(grid.orientation);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_GRID_HPP

// #include "tmx_property.hpp"
#ifndef RUNE_TMX_PROPERTY_HPP
#define RUNE_TMX_PROPERTY_HPP

#include <algorithm>    // any_of, find_if
#include <cassert>      // assert
#include <concepts>     // same_as
#include <nenya.hpp>    // strong_type
#include <string>       // string
#include <string_view>  // string_view
#include <variant>      // variant, get, get_if, holds_alternative
#include <vector>       // vector

// #include "../aliases/json_type.hpp"

// #include "../core/rune_error.hpp"
#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

// #include "../aliases/str.hpp"


namespace rune {

/**
 * \typedef str
 *
 * \brief An alias for a C-style null-terminated string.
 *
 * \ingroup core
 */
using str = const char*;

}  // namespace rune


namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const str what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> str override
  {
    return m_what;
  }

 private:
  str m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP

// #include "rune_api.hpp"

// #include "tmx_color.hpp"

// #include "tmx_property_type.hpp"
#ifndef RUNE_TMX_PROPERTY_TYPE_HPP
#define RUNE_TMX_PROPERTY_TYPE_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_property_type
{
  string,    ///< For string values, such as `"foo"`.
  integer,   ///< For integer values, e.g. `27`.
  floating,  ///< For floating-point values, e.g. `182.4`.
  boolean,   ///< For the boolean values `true`/`false`.
  color,     ///< For ARGB/RGB colors, i.e. `"#AARRGGBB"` and `"#RRGGBB"`.
  file,      ///< For file paths, e.g. `"some/path/abc.png"`.
  object     ///< For referencing other objects, really just an integer ID.
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_property_type,
                             {{tmx_property_type::string, "string"},
                              {tmx_property_type::integer, "int"},
                              {tmx_property_type::floating, "float"},
                              {tmx_property_type::boolean, "bool"},
                              {tmx_property_type::color, "color"},
                              {tmx_property_type::object, "object"},
                              {tmx_property_type::file, "file"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_PROPERTY_TYPE_HPP


namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_file_tag;
struct tmx_object_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_file = nenya::strong_type<std::string, tags::tmx_file_tag>;
using tmx_object_id = nenya::strong_type<int, tags::tmx_object_id_tag>;

/**
 * \brief Represents a property, with an associated name and value.
 */
struct tmx_property final
{
  using data_type =
      std::variant<std::string, tmx_file, tmx_object_id, tmx_color, int, float, bool>;

  std::string name;
  tmx_property_type type{tmx_property_type::string};
  data_type value;
};

using tmx_properties = std::vector<tmx_property>;

inline void from_json(const json_type& json, tmx_property& property)
{
  json.at("name").get_to(property.name);
  json.at("type").get_to(property.type);

  switch (property.type)
  {
    default:
      assert(false && "from_json() for tmx_property has missing branch!");

    case tmx_property_type::string:
      property.value.emplace<std::string>(json.at("value").get<std::string>());
      break;

    case tmx_property_type::integer:
      property.value.emplace<int>(json.at("value").get<int>());
      break;

    case tmx_property_type::floating:
      property.value.emplace<float>(json.at("value").get<float>());
      break;

    case tmx_property_type::boolean:
      property.value.emplace<bool>(json.at("value").get<bool>());
      break;

    case tmx_property_type::color:
      property.value.emplace<tmx_color>(json.at("value").get<tmx_color>());
      break;

    case tmx_property_type::file:
      property.value.emplace<tmx_file>(json.at("value").get<std::string>());
      break;

    case tmx_property_type::object:
      property.value.emplace<tmx_object_id>(json.at("value").get<int>());
      break;
  }
}

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

// clang-format off

template <typename T>
concept property_value_type = std::same_as<T, int> ||
                              std::same_as<T, float> ||
                              std::same_as<T, bool> ||
                              std::same_as<T, std::string> ||
                              std::same_as<T, tmx_color> ||
                              std::same_as<T, tmx_file> ||
                              std::same_as<T, tmx_object_id>;

// clang-format on

/// \name Property functions
/// \{

[[nodiscard]] inline auto try_get(const tmx_properties& properties,
                                  const std::string_view name)
    -> tmx_properties::const_iterator
{
  return std::ranges::find_if(properties, [name](const tmx_property& property) noexcept {
    return property.name == name;
  });
}

template <property_value_type T>
[[nodiscard]] auto get_if(const tmx_properties& properties,
                          const std::string_view name) noexcept -> const T*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<T>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto get_if_string(const tmx_property& property) noexcept
    -> const std::string*
{
  return std::get_if<std::string>(&property.value);
}

[[nodiscard]] inline auto get_if_string(const tmx_properties& properties,
                                        const std::string_view name) -> const std::string*
{
  return get_if<std::string>(properties, name);
}

[[nodiscard]] inline auto get_if_int(const tmx_property& property) noexcept -> const int*
{
  return std::get_if<int>(&property.value);
}

[[nodiscard]] inline auto get_if_int(const tmx_properties& properties,
                                     const std::string_view name) -> const int*
{
  return get_if<int>(properties, name);
}

[[nodiscard]] inline auto get_if_float(const tmx_property& property) noexcept -> const
    float*
{
  return std::get_if<float>(&property.value);
}

[[nodiscard]] inline auto get_if_float(const tmx_properties& properties,
                                       const std::string_view name) -> const float*
{
  return get_if<float>(properties, name);
}

[[nodiscard]] inline auto get_if_bool(const tmx_property& property) noexcept -> const
    bool*
{
  return std::get_if<bool>(&property.value);
}

[[nodiscard]] inline auto get_if_bool(const tmx_properties& properties,
                                      const std::string_view name) -> const bool*
{
  return get_if<bool>(properties, name);
}

[[nodiscard]] inline auto get_if_color(const tmx_property& property) noexcept
    -> const tmx_color*
{
  return std::get_if<tmx_color>(&property.value);
}

[[nodiscard]] inline auto get_if_color(const tmx_properties& properties,
                                       const std::string_view name) -> const tmx_color*
{
  return get_if<tmx_color>(properties, name);
}

[[nodiscard]] inline auto get_if_file(const tmx_property& property) noexcept
    -> const tmx_file*
{
  return std::get_if<tmx_file>(&property.value);
}

[[nodiscard]] inline auto get_if_file(const tmx_properties& properties,
                                      const std::string_view name) -> const tmx_file*
{
  return get_if<tmx_file>(properties, name);
}

[[nodiscard]] inline auto get_if_object(const tmx_property& property) noexcept
    -> const tmx_object_id*
{
  return std::get_if<tmx_object_id>(&property.value);
}

[[nodiscard]] inline auto get_if_object(const tmx_properties& properties,
                                        const std::string_view name)
    -> const tmx_object_id*
{
  return get_if<tmx_object_id>(properties, name);
}

template <property_value_type T>
[[nodiscard]] auto is(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<T>(property.value);
}

template <property_value_type T>
[[nodiscard]] auto is(const tmx_properties& properties, const std::string_view name)
    -> bool
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return is<T>(*it);
  }
  else
  {
    return false;
  }
}

[[nodiscard]] inline auto is_string(const tmx_property& property) noexcept -> bool
{
  return is<std::string>(property);
}

[[nodiscard]] inline auto is_string(const tmx_properties& properties,
                                    const std::string_view name) -> bool
{
  return is<std::string>(properties, name);
}

[[nodiscard]] inline auto is_int(const tmx_property& property) noexcept -> bool
{
  return is<int>(property);
}

[[nodiscard]] inline auto is_int(const tmx_properties& properties,
                                 const std::string_view name) -> bool
{
  return is<int>(properties, name);
}

[[nodiscard]] inline auto is_float(const tmx_property& property) noexcept -> bool
{
  return is<float>(property);
}

[[nodiscard]] inline auto is_float(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return is<float>(properties, name);
}

[[nodiscard]] inline auto is_bool(const tmx_property& property) noexcept -> bool
{
  return is<bool>(property);
}

[[nodiscard]] inline auto is_bool(const tmx_properties& properties,
                                  const std::string_view name) -> bool
{
  return is<bool>(properties, name);
}

[[nodiscard]] inline auto is_color(const tmx_property& property) noexcept -> bool
{
  return is<tmx_color>(property);
}

[[nodiscard]] inline auto is_color(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return is<tmx_color>(properties, name);
}

[[nodiscard]] inline auto is_file(const tmx_property& property) noexcept -> bool
{
  return is<tmx_file>(property);
}

[[nodiscard]] inline auto is_file(const tmx_properties& properties,
                                  const std::string_view name) -> bool
{
  return is<tmx_file>(properties, name);
}

[[nodiscard]] inline auto is_object(const tmx_property& property) noexcept -> bool
{
  return is<tmx_object_id>(property);
}

[[nodiscard]] inline auto is_object(const tmx_properties& properties,
                                    const std::string_view name) -> bool
{
  return is<tmx_object_id>(properties, name);
}

template <property_value_type T>
[[nodiscard]] auto get(const tmx_property& property) -> const T&
{
  return std::get<T>(property.value);
}

template <property_value_type T>
[[nodiscard]] auto get(const tmx_properties& properties, const std::string_view name)
    -> const T&
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return get<T>(*it);
  }
  else
  {
    throw rune_error{"Could not find property with the specified name!"};
  }
}

[[nodiscard]] inline auto get_string(const tmx_property& property) -> const std::string&
{
  return get<std::string>(property);
}

[[nodiscard]] inline auto get_string(const tmx_properties& properties,
                                     const std::string_view name) -> const std::string&
{
  return get<std::string>(properties, name);
}

[[nodiscard]] inline auto get_int(const tmx_property& property) -> int
{
  return get<int>(property);
}

[[nodiscard]] inline auto get_int(const tmx_properties& properties,
                                  const std::string_view name) -> int
{
  return get<int>(properties, name);
}

[[nodiscard]] inline auto get_float(const tmx_property& property) -> float
{
  return get<float>(property);
}

[[nodiscard]] inline auto get_float(const tmx_properties& properties,
                                    const std::string_view name) -> float
{
  return get<float>(properties, name);
}

[[nodiscard]] inline auto get_bool(const tmx_property& property) -> bool
{
  return get<bool>(property);
}

[[nodiscard]] inline auto get_bool(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return get<bool>(properties, name);
}

[[nodiscard]] inline auto get_color(const tmx_property& property) -> const tmx_color&
{
  return get<tmx_color>(property);
}

[[nodiscard]] inline auto get_color(const tmx_properties& properties,
                                    const std::string_view name) -> const tmx_color&
{
  return get<tmx_color>(properties, name);
}

[[nodiscard]] inline auto get_file(const tmx_property& property) -> const tmx_file&
{
  return get<tmx_file>(property);
}

[[nodiscard]] inline auto get_file(const tmx_properties& properties,
                                   const std::string_view name) -> const tmx_file&
{
  return get<tmx_file>(properties, name);
}

[[nodiscard]] inline auto get_object(const tmx_property& property) -> tmx_object_id
{
  return get<tmx_object_id>(property);
}

[[nodiscard]] inline auto get_object(const tmx_properties& properties,
                                     const std::string_view name) -> tmx_object_id
{
  return get<tmx_object_id>(properties, name);
}

/**
 * \brief Indicates whether or not a property with the specified name exists in a vector
 * of properties.
 *
 * \param properties the vector of properties that will be searched.
 * \param name the name of the property to look for.
 *
 * \return `true` if the properties contains a property with the specified name; `false`
 * otherwise.
 */
[[nodiscard]] inline auto contains(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return std::ranges::any_of(properties, [name](const tmx_property& property) noexcept {
    return property.name == name;
  });
}

/**
 * \brief Attempts to find and return a property with the specified name.
 *
 * \param properties the properties that will be searched.
 * \param name the name of the desired property.
 *
 * \return the property with the specified name.
 *
 * \throws rune_error if there is no property with the specified name.
 */
[[nodiscard]] inline auto at(const tmx_properties& properties,
                             const std::string_view name) -> const tmx_property&
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return *it;
  }
  else
  {
    throw rune_error{"Could not find property with specified name!"};
  }
}

/// \} End of property functions

/// \} End of group tmx

}  // namespace tmx

}  // namespace rune

#endif  // RUNE_TMX_PROPERTY_HPP

// #include "tmx_terrain.hpp"
#ifndef RUNE_TMX_TERRAIN_HPP
#define RUNE_TMX_TERRAIN_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_local_id.hpp"
#ifndef RUNE_TMX_LOCAL_ID_HPP
#define RUNE_TMX_LOCAL_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "../aliases/integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_local_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_local_id = nenya::strong_type<int, tags::tmx_local_id_tag>;

/// \} End of group tmx

namespace tmx_literals {

/// \addtogroup tmx
/// \{

/// \name Literal operators
/// \{

[[nodiscard]] constexpr auto operator""_local(const ulonglong value) noexcept
    -> tmx_local_id
{
  return tmx_local_id{static_cast<tmx_local_id::value_type>(value)};
}

/// \} End of literal operators

/// \} End of group tmx

}  // namespace tmx_literals
}  // namespace rune

#endif  // RUNE_TMX_LOCAL_ID_HPP

// #include "tmx_property.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_terrain final
{
  tmx_local_id tile{};
  std::string name;
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_terrain& terrain)
{
  terrain.tile = tmx_local_id{json.at("tile").get<tmx_local_id::value_type>()};
  json.at("name").get_to(terrain.name);
  io::try_get_to(json, "properties", terrain.properties);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TERRAIN_HPP

// #include "tmx_tile.hpp"
#ifndef RUNE_TMX_TILE_HPP
#define RUNE_TMX_TILE_HPP

#include <array>   // array
#include <string>  // string

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../core/from_string.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_animation.hpp"
#ifndef RUNE_TMX_ANIMATION_HPP
#define RUNE_TMX_ANIMATION_HPP

#include <chrono>  // milliseconds
#include <vector>  // vector

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "rune_api.hpp"

// #include "tmx_local_id.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_frame final
{
  tmx_local_id tile{};
  std::chrono::milliseconds duration{};
};

struct tmx_animation final
{
  std::vector<tmx_frame> frames;
};

inline void from_json(const json_type& json, tmx_frame& frame)
{
  using ms_t = std::chrono::milliseconds;

  io::emplace_to(json, "tileid", frame.tile);
  frame.duration = ms_t{json.at("duration").get<ms_t::rep>()};
}

inline void from_json(const json_type& json, tmx_animation& animation)
{
  io::get_to(json, animation.frames);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_ANIMATION_HPP

// #include "tmx_layer.hpp"
#ifndef RUNE_TMX_LAYER_HPP
#define RUNE_TMX_LAYER_HPP

#include <cassert>   // assert
#include <concepts>  // same_as
#include <memory>    // unique_ptr, make_unique
#include <string>    // string
#include <variant>   // variant, monostate
#include <vector>    // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "rune_api.hpp"

// #include "tmx_color.hpp"

// #include "tmx_image_layer.hpp"
#ifndef RUNE_TMX_IMAGE_LAYER_HPP
#define RUNE_TMX_IMAGE_LAYER_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_color.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_image_layer final
{
  std::string image;
  maybe<tmx_color> transparent;
};

inline void from_json(const json_type& json, tmx_image_layer& layer)
{
  json.at("image").get_to(layer.image);
  io::try_get_to(json, "transparentcolor", layer.transparent);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_IMAGE_LAYER_HPP

// #include "tmx_layer_type.hpp"
#ifndef RUNE_TMX_LAYER_TYPE_HPP
#define RUNE_TMX_LAYER_TYPE_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_layer_type
{
  tile_layer,
  object_layer,
  image_layer,
  group
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_layer_type,
                             {{tmx_layer_type::tile_layer, "tilelayer"},
                              {tmx_layer_type::image_layer, "imagelayer"},
                              {tmx_layer_type::object_layer, "objectgroup"},
                              {tmx_layer_type::group, "group"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_LAYER_TYPE_HPP

// #include "tmx_object.hpp"
#ifndef RUNE_TMX_OBJECT_HPP
#define RUNE_TMX_OBJECT_HPP

#include <memory>   // unique_ptr, make_unique
#include <string>   // string
#include <variant>  // variant, monostate
#include <vector>   // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "rune_api.hpp"

// #include "tmx_global_id.hpp"

// #include "tmx_point.hpp"
#ifndef RUNE_TMX_POINT_HPP
#define RUNE_TMX_POINT_HPP

// #include "../aliases/json_type.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_point final
{
  float x{};  ///< The x-coordinate of the point.
  float y{};  ///< The y-coordinate of the point.
};

inline void from_json(const json_type& json, tmx_point& point)
{
  json.at("x").get_to(point.x);
  json.at("y").get_to(point.y);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_POINT_HPP

// #include "tmx_property.hpp"

// #include "tmx_text.hpp"
#ifndef RUNE_TMX_TEXT_HPP
#define RUNE_TMX_TEXT_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_color.hpp"

// #include "tmx_halign.hpp"
#ifndef RUNE_TMX_HALIGN_HPP
#define RUNE_TMX_HALIGN_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_halign
{
  center,
  right,
  left,
  justify
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_halign,
                             {{tmx_halign::center, "center"},
                              {tmx_halign::right, "right"},
                              {tmx_halign::left, "left"},
                              {tmx_halign::justify, "justify"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_HALIGN_HPP

// #include "tmx_valign.hpp"
#ifndef RUNE_TMX_VALIGN_HPP
#define RUNE_TMX_VALIGN_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_valign
{
  center,
  top,
  bottom
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_valign,
                             {{tmx_valign::center, "center"},
                              {tmx_valign::top, "top"},
                              {tmx_valign::bottom, "bottom"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_VALIGN_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_text final
{
  std::string text;
  std::string family{"sans-serif"};
  tmx_color color;
  tmx_halign horizontal_alignment{tmx_halign::left};
  tmx_valign vertical_alignment{tmx_valign::top};
  int pixel_size{16};
  bool bold{};
  bool italic{};
  bool kerning{true};
  bool strikeout{};
  bool underline{};
  bool wrap{};
};

inline void from_json(const json_type& json, tmx_text& text)
{
  json.at("text").get_to(text.text);

  io::try_get_to(json, "fontfamily", text.family);
  io::try_get_to(json, "halign", text.horizontal_alignment);
  io::try_get_to(json, "valign", text.vertical_alignment);
  io::try_get_to(json, "pixelsize", text.pixel_size);
  io::try_get_to(json, "bold", text.bold);
  io::try_get_to(json, "italic", text.italic);
  io::try_get_to(json, "kerning", text.kerning);
  io::try_get_to(json, "strikeout", text.strikeout);
  io::try_get_to(json, "underline", text.underline);
  io::try_get_to(json, "wrap", text.wrap);

  if (const auto it = json.find("color"); it != json.end())
  {
    text.color = tmx::make_color(it->get<std::string>());
  }
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TEXT_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_object;

struct tmx_polygon final
{
  std::vector<tmx_point> points;
};

struct tmx_polyline final
{
  std::vector<tmx_point> points;
};

struct tmx_template_object final
{
  std::string template_file;
  std::unique_ptr<tmx_object> object;
  maybe<std::string> tileset_source;
  maybe<tmx_global_id> tileset_first_id;
};

struct tmx_object final
{
  using data_type = std::variant<std::monostate,
                                 tmx_polygon,
                                 tmx_polyline,
                                 tmx_text,
                                 tmx_template_object,
                                 tmx_global_id>;

  int id{};
  float x{};
  float y{};
  float width{};
  float height{};
  float rotation{};
  std::string name;
  std::string type;
  tmx_properties properties;
  data_type data;
  bool is_ellipse{};
  bool is_point{};
  bool visible{true};
};

inline void from_json(const json_type& json, tmx_polygon& polygon)
{
  io::get_to(json, polygon.points);
}

inline void from_json(const json_type& json, tmx_polyline& line)
{
  io::get_to(json, line.points);
}

void from_json(const json_type& json, tmx_object& object);

inline void from_json(const json_type& json, tmx_template_object& object)
{
  json.at("template").get_to(object.template_file);
  object.object = std::make_unique<tmx_object>(json.at("object").get<tmx_object>());

  if (const auto it = json.find("tileset"); it != json.end())
  {
    io::emplace_to(json, "firstgid", object.tileset_first_id);
    object.tileset_source = json.at("source").get<std::string>();
  }
}

inline void from_json(const json_type& json, tmx_object& object)
{
  json.at("id").get_to(object.id);
  json.at("x").get_to(object.x);
  json.at("y").get_to(object.y);
  json.at("width").get_to(object.width);
  json.at("height").get_to(object.height);
  json.at("rotation").get_to(object.rotation);
  json.at("name").get_to(object.name);
  json.at("type").get_to(object.type);
  json.at("visible").get_to(object.visible);

  io::try_get_to(json, "ellipse", object.is_ellipse);
  io::try_get_to(json, "point", object.is_point);

  io::try_get_to(json, "properties", object.properties);

  if (const auto it = json.find("gid"); it != json.end())
  {
    object.data.emplace<tmx_global_id>(it->get<tmx_global_id::value_type>());
  }

  io::try_emplace_to<tmx_text>(json, "text", object.data);
  io::try_emplace_to<tmx_polygon>(json, "polygon", object.data);
  io::try_emplace_to<tmx_polyline>(json, "polyline", object.data);
  io::try_emplace_to<tmx_template_object>(json, "template", object.data);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_HPP

// #include "tmx_object_layer.hpp"
#ifndef RUNE_TMX_OBJECT_LAYER_HPP
#define RUNE_TMX_OBJECT_LAYER_HPP

#include <cassert>   // assert
#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM
#include <vector>    // vector

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_object.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_object_layer_draw_order
{
  top_down,
  index
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_object_layer_draw_order,
                             {{tmx_object_layer_draw_order::top_down, "topdown"},
                              {tmx_object_layer_draw_order::index, "index"}})

struct tmx_object_layer final  // Note, referred to as "object group" by tiled
{
  tmx_object_layer_draw_order draw_order{tmx_object_layer_draw_order::top_down};
  std::vector<tmx_object> objects;
};

inline void from_json(const json_type& json, tmx_object_layer& layer)
{
  io::get_to(json, "objects", layer.objects);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_LAYER_HPP

// #include "tmx_property.hpp"

// #include "tmx_tile_layer.hpp"
#ifndef RUNE_TMX_TILE_LAYER_HPP
#define RUNE_TMX_TILE_LAYER_HPP

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_data.hpp"
#ifndef RUNE_TMX_DATA_HPP
#define RUNE_TMX_DATA_HPP

#include <cassert>  // assert
#include <string>   // string
#include <variant>  // variant
#include <vector>   // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "tmx_global_id.hpp"


namespace rune {

struct tmx_data final
{
  using gid_data = std::vector<tmx_global_id>;
  using base64_data = std::string;
  using data_type = std::variant<gid_data, base64_data>;

  data_type tile_data;
};

inline void from_json(const json_type& json, tmx_data& data)
{
  assert(json.is_array() || json.is_string());

  if (json.is_array())
  {
    auto& gidData = data.tile_data.emplace<tmx_data::gid_data>();
    for (const auto& [key, value] : json.items())
    {
      gidData.emplace_back(value.get<uint>());
    }
  }
  else if (json.is_string())
  {
    data.tile_data.emplace<tmx_data::base64_data>(json.get<tmx_data::base64_data>());
  }
}

}  // namespace rune

#endif  // RUNE_TMX_DATA_HPP

// #include "tmx_tile_layer_compression.hpp"
#ifndef RUNE_TMX_TILE_LAYER_COMPRESSION_HPP
#define RUNE_TMX_TILE_LAYER_COMPRESSION_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_tile_layer_compression
{
  none,
  gzip,
  zlib
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_tile_layer_compression,
                             {{tmx_tile_layer_compression::none, ""},
                              {tmx_tile_layer_compression::gzip, "gzip"},
                              {tmx_tile_layer_compression::zlib, "zlib"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_COMPRESSION_HPP

// #include "tmx_tile_layer_encoding.hpp"
#ifndef RUNE_TMX_TILE_LAYER_ENCODING_HPP
#define RUNE_TMX_TILE_LAYER_ENCODING_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_tile_layer_encoding
{
  csv,
  base64
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_tile_layer_encoding,
                             {{tmx_tile_layer_encoding::csv, "csv"},
                              {tmx_tile_layer_encoding::base64, "base64"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_ENCODING_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_layer final
{
  tmx_tile_layer_compression compression{tmx_tile_layer_compression::none};
  tmx_tile_layer_encoding encoding{tmx_tile_layer_encoding::csv};
  maybe<tmx_data> data;
  // TODO std::vector<chunk> m_chunks;
};

inline void from_json(const json_type& json, tmx_tile_layer& layer)
{
  io::try_get_to(json, "compression", layer.compression);
  io::try_get_to(json, "encoding", layer.encoding);
  io::try_get_to(json, "data", layer.data);

  // TODO
  //  if (json.contains("chunks")) {
  //    m_chunks = detail::fill<std::vector<chunk>>(json, "chunks");
  //  }
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_layer;

struct tmx_group final
{
  std::vector<std::unique_ptr<tmx_layer>> layers;
};

struct tmx_layer final
{
  using data_type = std::variant<std::monostate,
                                 tmx_tile_layer,
                                 tmx_image_layer,
                                 tmx_object_layer,
                                 tmx_group>;

  tmx_layer_type type{tmx_layer_type::tile_layer};
  int id{};
  int width{};
  int height{};
  int start_x{};
  int start_y{};
  float parallax_x{1};
  float parallax_y{1};
  float offset_x{};
  float offset_y{};
  float opacity{1};

  maybe<tmx_color> tint;
  tmx_properties properties;

  data_type data;

  std::string name;
  bool visible{true};
};

using tmx_layers = std::vector<tmx_layer>;

void from_json(const json_type& json, tmx_layer& layer);

inline void from_json(const json_type& json, tmx_group& group)
{
  const auto& layers = json.at("layers");
  group.layers.reserve(layers.size());
  for (const auto& [key, value] : layers.items())
  {
    group.layers.push_back(std::make_unique<tmx_layer>(value.get<tmx_layer>()));
  }
}

inline void from_json(const json_type& json, tmx_layer& layer)
{
  json.at("type").get_to(layer.type);

  io::try_get_to(json, "name", layer.name);
  io::try_get_to(json, "opacity", layer.opacity);
  io::try_get_to(json, "visible", layer.visible);
  io::try_get_to(json, "id", layer.id);
  io::try_get_to(json, "width", layer.width);
  io::try_get_to(json, "height", layer.height);
  io::try_get_to(json, "startx", layer.start_x);
  io::try_get_to(json, "starty", layer.start_y);
  io::try_get_to(json, "parallaxx", layer.parallax_x);
  io::try_get_to(json, "parallaxy", layer.parallax_y);
  io::try_get_to(json, "offsetx", layer.offset_x);
  io::try_get_to(json, "offsety", layer.offset_y);
  io::try_get_to(json, "tintcolor", layer.tint);

  io::try_get_to(json, "properties", layer.properties);

  switch (layer.type)
  {
    default:
      assert(false && "from_json() for tmx_layer is missing branch!");

    case tmx_layer_type::tile_layer:
      layer.data = json.get<tmx_tile_layer>();
      break;

    case tmx_layer_type::object_layer:
      layer.data = json.get<tmx_object_layer>();
      break;

    case tmx_layer_type::image_layer:
      layer.data = json.get<tmx_image_layer>();
      break;

    case tmx_layer_type::group:
      layer.data = json.get<tmx_group>();
      break;
  }
}

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

// clang-format off

template <typename T>
concept layer_value_type = std::same_as<T, tmx_tile_layer> ||
                           std::same_as<T, tmx_object_layer> ||
                           std::same_as<T, tmx_image_layer> ||
                           std::same_as<T, tmx_group>;

// clang-format on

/// \name Layer functions
/// \{

template <layer_value_type T>
[[nodiscard]] auto get(const tmx_layer& layer) -> const T&
{
  return std::get<T>(layer.data);
}

[[nodiscard]] inline auto get_tile_layer(const tmx_layer& layer) -> const tmx_tile_layer&
{
  return get<tmx_tile_layer>(layer);
}

[[nodiscard]] inline auto get_image_layer(const tmx_layer& layer)
    -> const tmx_image_layer&
{
  return get<tmx_image_layer>(layer);
}

[[nodiscard]] inline auto get_object_layer(const tmx_layer& layer)
    -> const tmx_object_layer&
{
  return get<tmx_object_layer>(layer);
}

[[nodiscard]] inline auto get_group(const tmx_layer& layer) -> const tmx_group&
{
  return get<tmx_group>(layer);
}

template <layer_value_type T>
[[nodiscard]] auto try_get(const tmx_layer& layer) noexcept -> const T*
{
  return std::get_if<T>(&layer.data);
}

[[nodiscard]] inline auto try_get_tile_layer(const tmx_layer& layer) noexcept
    -> const tmx_tile_layer*
{
  return try_get<tmx_tile_layer>(layer);
}

[[nodiscard]] inline auto try_get_object_layer(const tmx_layer& layer) noexcept
    -> const tmx_object_layer*
{
  return try_get<tmx_object_layer>(layer);
}

[[nodiscard]] inline auto try_get_image_layer(const tmx_layer& layer) noexcept
    -> const tmx_image_layer*
{
  return try_get<tmx_image_layer>(layer);
}

[[nodiscard]] inline auto try_get_group(const tmx_layer& layer) noexcept
    -> const tmx_group*
{
  return try_get<tmx_group>(layer);
}

template <layer_value_type T>
[[nodiscard]] auto is(const tmx_layer& layer) noexcept -> bool
{
  return std::holds_alternative<T>(layer.data);
}

[[nodiscard]] inline auto is_tile_layer(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_tile_layer>(layer);
}

[[nodiscard]] inline auto is_object_layer(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_object_layer>(layer);
}

[[nodiscard]] inline auto is_image_layer(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_image_layer>(layer);
}

[[nodiscard]] inline auto is_group(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_group>(layer);
}

/// \} End of layer functions

/// \} End of group tmx

}  // namespace tmx
}  // namespace rune

#endif  // RUNE_TMX_LAYER_HPP

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile final
{
  tmx_local_id id{};
  maybe<tmx_animation> animation;
  maybe<std::array<int, 4>> terrain;
  maybe<std::string> type;
  maybe<std::string> image;
  maybe<int> image_width;
  maybe<int> image_height;
  maybe<float> probability;
  maybe<tmx_layer> object_layer;
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_tile& tile)
{
  io::emplace_to(json, "id", tile.id);

  io::try_get_to(json, "animation", tile.animation);
  io::try_get_to(json, "type", tile.type);
  io::try_get_to(json, "image", tile.image);
  io::try_get_to(json, "imagewidth", tile.image_width);
  io::try_get_to(json, "imageheight", tile.image_height);
  io::try_get_to(json, "probability", tile.probability);
  io::try_get_to(json, "objectgroup", tile.object_layer);
  io::try_get_to(json, "properties", tile.properties);

  if (const auto it = json.find("terrain"); it != json.end())
  {
    auto& terrain = tile.terrain.emplace();
    for (const auto& [key, value] : it->items())
    {
      const auto index = from_string<usize>(key).value();
      terrain.at(index) = value.get<int>();
    }
  }
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_HPP

// #include "tmx_tile_offset.hpp"
#ifndef RUNE_TMX_TILE_OFFSET_HPP
#define RUNE_TMX_TILE_OFFSET_HPP

// #include "../aliases/json_type.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_offset final
{
  int x{};
  int y{};
};

inline void from_json(const json_type& json, tmx_tile_offset& offset)
{
  json.at("x").get_to(offset.x);
  json.at("y").get_to(offset.y);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_OFFSET_HPP

// #include "tmx_wang_set.hpp"
#ifndef RUNE_TMX_WANG_SET_HPP
#define RUNE_TMX_WANG_SET_HPP

#include <string>  // string
#include <vector>  // vector

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"

// #include "tmx_wang_color.hpp"
#ifndef RUNE_TMX_WANG_COLOR_HPP
#define RUNE_TMX_WANG_COLOR_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_color.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_color final
{
  tmx_local_id tile{};
  tmx_color color;
  std::string name;
  float probability{};
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_wang_color& color)
{
  json.at("name").get_to(color.name);
  json.at("color").get_to(color.color);
  json.at("probability").get_to(color.probability);
  io::emplace_to(json, "tile", color.tile);

  io::try_get_to(json, "properties", color.properties);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_COLOR_HPP

// #include "tmx_wang_tile.hpp"
#ifndef RUNE_TMX_WANG_TILE_HPP
#define RUNE_TMX_WANG_TILE_HPP

#include <array>  // array

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_local_id.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_tile final
{
  tmx_local_id tile{};
  std::array<uint8, 8> indices{};
};

inline void from_json(const json_type& json, tmx_wang_tile& tile)
{
  io::emplace_to(json, "tileid", tile.tile);
  json.at("wangid").get_to(tile.indices);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_TILE_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_set final
{
  tmx_local_id tile{};
  std::string name;
  std::vector<tmx_wang_tile> wang_tiles;
  std::vector<tmx_wang_color> colors;
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_wang_set& set)
{
  io::emplace_to(json, "tile", set.tile);
  json.at("name").get_to(set.name);

  // TODO check if colors or wangtiles are required
  io::try_get_to(json, "colors", set.colors);
  io::try_get_to(json, "wangtiles", set.wang_tiles);
  io::try_get_to(json, "properties", set.properties);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_SET_HPP


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tileset final
{
  tmx_global_id first_id{1};
  int tile_width{};
  int tile_height{};
  int tile_count{};
  int column_count{};
  int image_width{};
  int image_height{};
  int margin{};
  int spacing{};

  std::string name;
  std::string image;
  std::string external_source;
  std::string tiled_version;
  std::string json_version;

  maybe<tmx_color> background;
  maybe<tmx_color> transparent;
  maybe<tmx_tile_offset> tile_offset;
  maybe<tmx_grid> grid;

  std::vector<tmx_tile> tiles;
  std::vector<tmx_terrain> terrains;
  std::vector<tmx_wang_set> wang_sets;
  tmx_properties properties;
};

using tmx_tilesets = std::vector<tmx_tileset>;

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILESET_HPP


namespace rune::tmx {

/// \cond FALSE

namespace detail {

inline void parse_tileset_common(const json_type& json, tmx_tileset& tileset)
{
  json.at("tilewidth").get_to(tileset.tile_width);
  json.at("tileheight").get_to(tileset.tile_height);
  json.at("tilecount").get_to(tileset.tile_count);
  json.at("columns").get_to(tileset.column_count);
  json.at("imagewidth").get_to(tileset.image_width);
  json.at("imageheight").get_to(tileset.image_height);
  json.at("margin").get_to(tileset.margin);
  json.at("spacing").get_to(tileset.spacing);
  json.at("image").get_to(tileset.image);
  json.at("name").get_to(tileset.name);

  io::try_get_to(json, "tiledversion", tileset.tiled_version);
  io::try_get_to(json, "version", tileset.json_version);
  io::try_get_to(json, "backgroundcolor", tileset.background);
  io::try_get_to(json, "transparentcolor", tileset.transparent);
  io::try_get_to(json, "tileoffset", tileset.tile_offset);
  io::try_get_to(json, "grid", tileset.grid);

  io::try_get_to(json, "tiles", tileset.tiles);
  io::try_get_to(json, "terrains", tileset.terrains);
  io::try_get_to(json, "wangsets", tileset.wang_sets);
  io::try_get_to(json, "properties", tileset.properties);
}

}  // namespace detail

/// \endcond

/// \addtogroup tmx
/// \{

[[nodiscard]] inline auto parse_tileset(const std::filesystem::path& directory,
                                        const json_type& json) -> tmx_tileset
{
  tmx_tileset tileset;

  tileset.first_id = tmx_global_id{json.at("firstgid").get<tmx_global_id::value_type>()};
  if (const auto it = json.find("source"); it != json.end())
  {
    // External
    tileset.external_source = it->get<std::string>();

    const auto source = directory / tileset.external_source;
    const auto external = read_json(source);

    detail::parse_tileset_common(external, tileset);
  }
  else
  {
    // Embedded
    detail::parse_tileset_common(json, tileset);
  }

  return tileset;
}

/// \} End of group tmx

}  // namespace rune::tmx

#endif  // RUNE_TMX_PARSE_TILESET_HPP

// #include "tmx/parse_tmx.hpp"
#ifndef RUNE_TMX_PARSE_TMX_HPP
#define RUNE_TMX_PARSE_TMX_HPP

#include <cassert>     // assert
#include <filesystem>  // path
#include <string>      // string

// #include "../aliases/integers.hpp"

// #include "../io/json_utils.hpp"

// #include "parse_tileset.hpp"
#ifndef RUNE_TMX_PARSE_TILESET_HPP
#define RUNE_TMX_PARSE_TILESET_HPP

#include <filesystem>  // path
#include <string>      // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_global_id.hpp"

// #include "tmx_tileset.hpp"


namespace rune::tmx {

/// \cond FALSE

namespace detail {

inline void parse_tileset_common(const json_type& json, tmx_tileset& tileset)
{
  json.at("tilewidth").get_to(tileset.tile_width);
  json.at("tileheight").get_to(tileset.tile_height);
  json.at("tilecount").get_to(tileset.tile_count);
  json.at("columns").get_to(tileset.column_count);
  json.at("imagewidth").get_to(tileset.image_width);
  json.at("imageheight").get_to(tileset.image_height);
  json.at("margin").get_to(tileset.margin);
  json.at("spacing").get_to(tileset.spacing);
  json.at("image").get_to(tileset.image);
  json.at("name").get_to(tileset.name);

  io::try_get_to(json, "tiledversion", tileset.tiled_version);
  io::try_get_to(json, "version", tileset.json_version);
  io::try_get_to(json, "backgroundcolor", tileset.background);
  io::try_get_to(json, "transparentcolor", tileset.transparent);
  io::try_get_to(json, "tileoffset", tileset.tile_offset);
  io::try_get_to(json, "grid", tileset.grid);

  io::try_get_to(json, "tiles", tileset.tiles);
  io::try_get_to(json, "terrains", tileset.terrains);
  io::try_get_to(json, "wangsets", tileset.wang_sets);
  io::try_get_to(json, "properties", tileset.properties);
}

}  // namespace detail

/// \endcond

/// \addtogroup tmx
/// \{

[[nodiscard]] inline auto parse_tileset(const std::filesystem::path& directory,
                                        const json_type& json) -> tmx_tileset
{
  tmx_tileset tileset;

  tileset.first_id = tmx_global_id{json.at("firstgid").get<tmx_global_id::value_type>()};
  if (const auto it = json.find("source"); it != json.end())
  {
    // External
    tileset.external_source = it->get<std::string>();

    const auto source = directory / tileset.external_source;
    const auto external = read_json(source);

    detail::parse_tileset_common(external, tileset);
  }
  else
  {
    // Embedded
    detail::parse_tileset_common(json, tileset);
  }

  return tileset;
}

/// \} End of group tmx

}  // namespace rune::tmx

#endif  // RUNE_TMX_PARSE_TILESET_HPP

// #include "tmx_global_id.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_map.hpp"
#ifndef RUNE_TMX_MAP_HPP
#define RUNE_TMX_MAP_HPP

#include <string>  // string

// #include "../aliases/maybe.hpp"

// #include "tmx_color.hpp"

// #include "tmx_layer.hpp"

// #include "tmx_map_orientation.hpp"
#ifndef RUNE_TMX_MAP_ORIENTATION_HPP
#define RUNE_TMX_MAP_ORIENTATION_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_map_orientation
{
  orthogonal,
  isometric,
  staggered,
  hexagonal
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_map_orientation,
                             {{tmx_map_orientation::orthogonal, "orthogonal"},
                              {tmx_map_orientation::isometric, "isometric"},
                              {tmx_map_orientation::staggered, "staggered"},
                              {tmx_map_orientation::hexagonal, "hexagonal"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_ORIENTATION_HPP

// #include "tmx_map_render_order.hpp"
#ifndef RUNE_TMX_MAP_RENDER_ORDER_HPP
#define RUNE_TMX_MAP_RENDER_ORDER_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_map_render_order
{
  right_down,
  right_up,
  left_down,
  left_up
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_map_render_order,
                             {{tmx_map_render_order::right_down, "right-down"},
                              {tmx_map_render_order::right_up, "right-up"},
                              {tmx_map_render_order::left_down, "left-down"},
                              {tmx_map_render_order::left_up, "left-up"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_RENDER_ORDER_HPP

// #include "tmx_property.hpp"

// #include "tmx_stagger_axis.hpp"
#ifndef RUNE_TMX_STAGGER_AXIS_HPP
#define RUNE_TMX_STAGGER_AXIS_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_stagger_axis
{
  x,
  y
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_stagger_axis,
                             {{tmx_stagger_axis::x, "x"}, {tmx_stagger_axis::y, "y"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_STAGGER_AXIS_HPP

// #include "tmx_stagger_index.hpp"
#ifndef RUNE_TMX_STAGGER_INDEX_HPP
#define RUNE_TMX_STAGGER_INDEX_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_stagger_index
{
  odd,
  even
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_stagger_index,
                             {{tmx_stagger_index::odd, "odd"},
                              {tmx_stagger_index::even, "even"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_STAGGER_INDEX_HPP

// #include "tmx_tileset.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_map final
{
  int width{};   ///< Number of columns.
  int height{};  ///< Number of rows.

  int next_layer_id{1};
  int next_object_id{1};

  int tile_height{};
  int tile_width{};

  int compression_level{-1};
  int hex_side_length{};

  tmx_map_orientation orientation{tmx_map_orientation::orthogonal};
  tmx_map_render_order render_order{tmx_map_render_order::right_down};

  maybe<tmx_color> background;
  maybe<tmx_stagger_axis> stagger_axis;
  maybe<tmx_stagger_index> stagger_index;

  tmx_layers layers;
  tmx_tilesets tilesets;
  tmx_properties properties;

  std::string tiled_version;
  std::string json_version;
  bool infinite{};
};

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_HPP


namespace rune {

/// \addtogroup tmx
/// \{

/**
 * \brief Parses a Tiled JSON map file, and returns the contents.
 *
 * \details This function will not validate the specified JSON file. An invalid map file
 * will likely result in an exception being thrown due to parsing errors. However, there
 * are debug assertions that try to make it easier to detect errors and their cause,
 * compared to the generic exceptions from the JSON parser.
 *
 * \note The Tiled XML format is not supported.
 *
 * \todo Support all versions of the JSON format.
 *
 * \param path the file path to the Tiled JSON map file.
 *
 * \return the parsed Tiled map.
 */
[[nodiscard]] inline auto parse_tmx(const std::filesystem::path& path) -> tmx_map
{
  const auto json = read_json(path);
  assert(json.contains("type") && "Map file requires \"type\" element!");
  assert(json.at("type").get<std::string>() == "map");

  tmx_map map;

  json.at("width").get_to(map.width);
  json.at("height").get_to(map.height);
  json.at("nextlayerid").get_to(map.next_layer_id);
  json.at("nextobjectid").get_to(map.next_object_id);
  json.at("tilewidth").get_to(map.tile_width);
  json.at("tileheight").get_to(map.tile_height);
  json.at("infinite").get_to(map.infinite);
  json.at("orientation").get_to(map.orientation);
  json.at("renderorder").get_to(map.render_order);
  json.at("tiledversion").get_to(map.tiled_version);
  json.at("version").get_to(map.json_version);

  io::try_get_to(json, "backgroundcolor", map.background);
  io::try_get_to(json, "compressionlevel", map.compression_level);
  io::try_get_to(json, "hexsidelength", map.hex_side_length);
  io::try_get_to(json, "staggeraxis", map.stagger_axis);
  io::try_get_to(json, "staggerindex", map.stagger_index);

  io::try_get_to(json, "layers", map.layers);
  io::try_get_to(json, "properties", map.properties);

  if (const auto it = json.find("tilesets"); it != json.end())
  {
    const auto directory = path.parent_path();

    map.tilesets.reserve(it->size());
    for (const auto& [key, value] : it->items())
    {
      map.tilesets.push_back(tmx::parse_tileset(directory, value));
    }
  }

  return map;
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_PARSE_TMX_HPP

// #include "tmx/tmx_animation.hpp"
#ifndef RUNE_TMX_ANIMATION_HPP
#define RUNE_TMX_ANIMATION_HPP

#include <chrono>  // milliseconds
#include <vector>  // vector

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "rune_api.hpp"

// #include "tmx_local_id.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_frame final
{
  tmx_local_id tile{};
  std::chrono::milliseconds duration{};
};

struct tmx_animation final
{
  std::vector<tmx_frame> frames;
};

inline void from_json(const json_type& json, tmx_frame& frame)
{
  using ms_t = std::chrono::milliseconds;

  io::emplace_to(json, "tileid", frame.tile);
  frame.duration = ms_t{json.at("duration").get<ms_t::rep>()};
}

inline void from_json(const json_type& json, tmx_animation& animation)
{
  io::get_to(json, animation.frames);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_ANIMATION_HPP

// #include "tmx/tmx_color.hpp"
#ifndef RUNE_TMX_COLOR_HPP
#define RUNE_TMX_COLOR_HPP

#include <cassert>      // assert
#include <string>       // string
#include <string_view>  // string_view

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../core/from_string.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_color final
{
  uint8 red{};
  uint8 green{};
  uint8 blue{};
  uint8 alpha{0xFF};

  [[nodiscard]] constexpr bool operator==(const tmx_color&) const noexcept = default;
};

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

inline constexpr tmx_color black{0, 0, 0, 0xFF};

[[nodiscard]] inline auto from_hex(const std::string_view str) -> uint8
{
  assert(str.size() == 2);
  return from_string<uint8>(str, 16).value();
}

[[nodiscard]] inline auto make_color(const std::string_view str) -> tmx_color
{
  assert(str.size() == 7 || str.size() == 9);
  assert(str.at(0) == '#');

  const auto noHash = str.substr(1);
  const auto length = noHash.size();

  tmx_color result;

  if (length == 8)
  {
    // ARGB
    result.alpha = from_hex(noHash.substr(0, 2));
    result.red = from_hex(noHash.substr(2, 2));
    result.green = from_hex(noHash.substr(4, 2));
    result.blue = from_hex(noHash.substr(6, 2));
  }
  else
  {
    // RGB
    result.red = from_hex(noHash.substr(0, 2));
    result.green = from_hex(noHash.substr(2, 2));
    result.blue = from_hex(noHash.substr(4, 2));
  }

  return result;
}

/// \} End of group tmx

}  // namespace tmx

inline void from_json(const json_type& json, tmx_color& color)
{
  color = tmx::make_color(json.get<std::string>());
}

}  // namespace rune

#endif  // RUNE_TMX_COLOR_TEST

// #include "tmx/tmx_data.hpp"
#ifndef RUNE_TMX_DATA_HPP
#define RUNE_TMX_DATA_HPP

#include <cassert>  // assert
#include <string>   // string
#include <variant>  // variant
#include <vector>   // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "tmx_global_id.hpp"


namespace rune {

struct tmx_data final
{
  using gid_data = std::vector<tmx_global_id>;
  using base64_data = std::string;
  using data_type = std::variant<gid_data, base64_data>;

  data_type tile_data;
};

inline void from_json(const json_type& json, tmx_data& data)
{
  assert(json.is_array() || json.is_string());

  if (json.is_array())
  {
    auto& gidData = data.tile_data.emplace<tmx_data::gid_data>();
    for (const auto& [key, value] : json.items())
    {
      gidData.emplace_back(value.get<uint>());
    }
  }
  else if (json.is_string())
  {
    data.tile_data.emplace<tmx_data::base64_data>(json.get<tmx_data::base64_data>());
  }
}

}  // namespace rune

#endif  // RUNE_TMX_DATA_HPP

// #include "tmx/tmx_global_id.hpp"
#ifndef RUNE_TMX_GLOBAL_ID_HPP
#define RUNE_TMX_GLOBAL_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "../aliases/integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_global_id_tag;
}
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_global_id = nenya::strong_type<uint, tags::tmx_global_id_tag>;

/// \} End of group tmx

namespace tmx_literals {

/// \addtogroup tmx
/// \{

/// \name Literal operators
/// \{

[[nodiscard]] constexpr auto operator""_global(const ulonglong value) noexcept
    -> tmx_global_id
{
  return tmx_global_id{static_cast<tmx_global_id::value_type>(value)};
}

/// \} End of literal operators
/// \} End of group tmx

}  // namespace tmx_literals
}  // namespace rune

#endif  // RUNE_TMX_GLOBAL_ID_HPP

// #include "tmx/tmx_grid.hpp"
#ifndef RUNE_TMX_GRID_HPP
#define RUNE_TMX_GRID_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

// #include "../aliases/json_type.hpp"

// #include "rune_api.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_grid_orientation
{
  orthogonal,
  isometric
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_grid_orientation,
                             {{tmx_grid_orientation::orthogonal, "orthogonal"},
                              {tmx_grid_orientation::isometric, "isometric"}})

struct tmx_grid final
{
  int cell_width{};
  int cell_height{};
  tmx_grid_orientation orientation{tmx_grid_orientation::orthogonal};
};

inline void from_json(const json_type& json, tmx_grid& grid)
{
  json.at("width").get_to(grid.cell_width);
  json.at("height").get_to(grid.cell_height);
  json.at("orientation").get_to(grid.orientation);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_GRID_HPP

// #include "tmx/tmx_halign.hpp"
#ifndef RUNE_TMX_HALIGN_HPP
#define RUNE_TMX_HALIGN_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_halign
{
  center,
  right,
  left,
  justify
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_halign,
                             {{tmx_halign::center, "center"},
                              {tmx_halign::right, "right"},
                              {tmx_halign::left, "left"},
                              {tmx_halign::justify, "justify"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_HALIGN_HPP

// #include "tmx/tmx_image_layer.hpp"
#ifndef RUNE_TMX_IMAGE_LAYER_HPP
#define RUNE_TMX_IMAGE_LAYER_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_color.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_image_layer final
{
  std::string image;
  maybe<tmx_color> transparent;
};

inline void from_json(const json_type& json, tmx_image_layer& layer)
{
  json.at("image").get_to(layer.image);
  io::try_get_to(json, "transparentcolor", layer.transparent);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_IMAGE_LAYER_HPP

// #include "tmx/tmx_layer.hpp"
#ifndef RUNE_TMX_LAYER_HPP
#define RUNE_TMX_LAYER_HPP

#include <cassert>   // assert
#include <concepts>  // same_as
#include <memory>    // unique_ptr, make_unique
#include <string>    // string
#include <variant>   // variant, monostate
#include <vector>    // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "rune_api.hpp"

// #include "tmx_color.hpp"

// #include "tmx_image_layer.hpp"

// #include "tmx_layer_type.hpp"

// #include "tmx_object.hpp"

// #include "tmx_object_layer.hpp"

// #include "tmx_property.hpp"

// #include "tmx_tile_layer.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_layer;

struct tmx_group final
{
  std::vector<std::unique_ptr<tmx_layer>> layers;
};

struct tmx_layer final
{
  using data_type = std::variant<std::monostate,
                                 tmx_tile_layer,
                                 tmx_image_layer,
                                 tmx_object_layer,
                                 tmx_group>;

  tmx_layer_type type{tmx_layer_type::tile_layer};
  int id{};
  int width{};
  int height{};
  int start_x{};
  int start_y{};
  float parallax_x{1};
  float parallax_y{1};
  float offset_x{};
  float offset_y{};
  float opacity{1};

  maybe<tmx_color> tint;
  tmx_properties properties;

  data_type data;

  std::string name;
  bool visible{true};
};

using tmx_layers = std::vector<tmx_layer>;

void from_json(const json_type& json, tmx_layer& layer);

inline void from_json(const json_type& json, tmx_group& group)
{
  const auto& layers = json.at("layers");
  group.layers.reserve(layers.size());
  for (const auto& [key, value] : layers.items())
  {
    group.layers.push_back(std::make_unique<tmx_layer>(value.get<tmx_layer>()));
  }
}

inline void from_json(const json_type& json, tmx_layer& layer)
{
  json.at("type").get_to(layer.type);

  io::try_get_to(json, "name", layer.name);
  io::try_get_to(json, "opacity", layer.opacity);
  io::try_get_to(json, "visible", layer.visible);
  io::try_get_to(json, "id", layer.id);
  io::try_get_to(json, "width", layer.width);
  io::try_get_to(json, "height", layer.height);
  io::try_get_to(json, "startx", layer.start_x);
  io::try_get_to(json, "starty", layer.start_y);
  io::try_get_to(json, "parallaxx", layer.parallax_x);
  io::try_get_to(json, "parallaxy", layer.parallax_y);
  io::try_get_to(json, "offsetx", layer.offset_x);
  io::try_get_to(json, "offsety", layer.offset_y);
  io::try_get_to(json, "tintcolor", layer.tint);

  io::try_get_to(json, "properties", layer.properties);

  switch (layer.type)
  {
    default:
      assert(false && "from_json() for tmx_layer is missing branch!");

    case tmx_layer_type::tile_layer:
      layer.data = json.get<tmx_tile_layer>();
      break;

    case tmx_layer_type::object_layer:
      layer.data = json.get<tmx_object_layer>();
      break;

    case tmx_layer_type::image_layer:
      layer.data = json.get<tmx_image_layer>();
      break;

    case tmx_layer_type::group:
      layer.data = json.get<tmx_group>();
      break;
  }
}

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

// clang-format off

template <typename T>
concept layer_value_type = std::same_as<T, tmx_tile_layer> ||
                           std::same_as<T, tmx_object_layer> ||
                           std::same_as<T, tmx_image_layer> ||
                           std::same_as<T, tmx_group>;

// clang-format on

/// \name Layer functions
/// \{

template <layer_value_type T>
[[nodiscard]] auto get(const tmx_layer& layer) -> const T&
{
  return std::get<T>(layer.data);
}

[[nodiscard]] inline auto get_tile_layer(const tmx_layer& layer) -> const tmx_tile_layer&
{
  return get<tmx_tile_layer>(layer);
}

[[nodiscard]] inline auto get_image_layer(const tmx_layer& layer)
    -> const tmx_image_layer&
{
  return get<tmx_image_layer>(layer);
}

[[nodiscard]] inline auto get_object_layer(const tmx_layer& layer)
    -> const tmx_object_layer&
{
  return get<tmx_object_layer>(layer);
}

[[nodiscard]] inline auto get_group(const tmx_layer& layer) -> const tmx_group&
{
  return get<tmx_group>(layer);
}

template <layer_value_type T>
[[nodiscard]] auto try_get(const tmx_layer& layer) noexcept -> const T*
{
  return std::get_if<T>(&layer.data);
}

[[nodiscard]] inline auto try_get_tile_layer(const tmx_layer& layer) noexcept
    -> const tmx_tile_layer*
{
  return try_get<tmx_tile_layer>(layer);
}

[[nodiscard]] inline auto try_get_object_layer(const tmx_layer& layer) noexcept
    -> const tmx_object_layer*
{
  return try_get<tmx_object_layer>(layer);
}

[[nodiscard]] inline auto try_get_image_layer(const tmx_layer& layer) noexcept
    -> const tmx_image_layer*
{
  return try_get<tmx_image_layer>(layer);
}

[[nodiscard]] inline auto try_get_group(const tmx_layer& layer) noexcept
    -> const tmx_group*
{
  return try_get<tmx_group>(layer);
}

template <layer_value_type T>
[[nodiscard]] auto is(const tmx_layer& layer) noexcept -> bool
{
  return std::holds_alternative<T>(layer.data);
}

[[nodiscard]] inline auto is_tile_layer(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_tile_layer>(layer);
}

[[nodiscard]] inline auto is_object_layer(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_object_layer>(layer);
}

[[nodiscard]] inline auto is_image_layer(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_image_layer>(layer);
}

[[nodiscard]] inline auto is_group(const tmx_layer& layer) noexcept -> bool
{
  return is<tmx_group>(layer);
}

/// \} End of layer functions

/// \} End of group tmx

}  // namespace tmx
}  // namespace rune

#endif  // RUNE_TMX_LAYER_HPP

// #include "tmx/tmx_layer_type.hpp"
#ifndef RUNE_TMX_LAYER_TYPE_HPP
#define RUNE_TMX_LAYER_TYPE_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_layer_type
{
  tile_layer,
  object_layer,
  image_layer,
  group
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_layer_type,
                             {{tmx_layer_type::tile_layer, "tilelayer"},
                              {tmx_layer_type::image_layer, "imagelayer"},
                              {tmx_layer_type::object_layer, "objectgroup"},
                              {tmx_layer_type::group, "group"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_LAYER_TYPE_HPP

// #include "tmx/tmx_local_id.hpp"
#ifndef RUNE_TMX_LOCAL_ID_HPP
#define RUNE_TMX_LOCAL_ID_HPP

#include <nenya.hpp>  // strong_type

// #include "../aliases/integers.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_local_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_local_id = nenya::strong_type<int, tags::tmx_local_id_tag>;

/// \} End of group tmx

namespace tmx_literals {

/// \addtogroup tmx
/// \{

/// \name Literal operators
/// \{

[[nodiscard]] constexpr auto operator""_local(const ulonglong value) noexcept
    -> tmx_local_id
{
  return tmx_local_id{static_cast<tmx_local_id::value_type>(value)};
}

/// \} End of literal operators

/// \} End of group tmx

}  // namespace tmx_literals
}  // namespace rune

#endif  // RUNE_TMX_LOCAL_ID_HPP

// #include "tmx/tmx_map.hpp"
#ifndef RUNE_TMX_MAP_HPP
#define RUNE_TMX_MAP_HPP

#include <string>  // string

// #include "../aliases/maybe.hpp"

// #include "tmx_color.hpp"

// #include "tmx_layer.hpp"

// #include "tmx_map_orientation.hpp"

// #include "tmx_map_render_order.hpp"

// #include "tmx_property.hpp"

// #include "tmx_stagger_axis.hpp"

// #include "tmx_stagger_index.hpp"

// #include "tmx_tileset.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_map final
{
  int width{};   ///< Number of columns.
  int height{};  ///< Number of rows.

  int next_layer_id{1};
  int next_object_id{1};

  int tile_height{};
  int tile_width{};

  int compression_level{-1};
  int hex_side_length{};

  tmx_map_orientation orientation{tmx_map_orientation::orthogonal};
  tmx_map_render_order render_order{tmx_map_render_order::right_down};

  maybe<tmx_color> background;
  maybe<tmx_stagger_axis> stagger_axis;
  maybe<tmx_stagger_index> stagger_index;

  tmx_layers layers;
  tmx_tilesets tilesets;
  tmx_properties properties;

  std::string tiled_version;
  std::string json_version;
  bool infinite{};
};

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_HPP

// #include "tmx/tmx_map_orientation.hpp"
#ifndef RUNE_TMX_MAP_ORIENTATION_HPP
#define RUNE_TMX_MAP_ORIENTATION_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_map_orientation
{
  orthogonal,
  isometric,
  staggered,
  hexagonal
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_map_orientation,
                             {{tmx_map_orientation::orthogonal, "orthogonal"},
                              {tmx_map_orientation::isometric, "isometric"},
                              {tmx_map_orientation::staggered, "staggered"},
                              {tmx_map_orientation::hexagonal, "hexagonal"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_ORIENTATION_HPP

// #include "tmx/tmx_map_render_order.hpp"
#ifndef RUNE_TMX_MAP_RENDER_ORDER_HPP
#define RUNE_TMX_MAP_RENDER_ORDER_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_map_render_order
{
  right_down,
  right_up,
  left_down,
  left_up
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_map_render_order,
                             {{tmx_map_render_order::right_down, "right-down"},
                              {tmx_map_render_order::right_up, "right-up"},
                              {tmx_map_render_order::left_down, "left-down"},
                              {tmx_map_render_order::left_up, "left-up"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_MAP_RENDER_ORDER_HPP

// #include "tmx/tmx_object.hpp"
#ifndef RUNE_TMX_OBJECT_HPP
#define RUNE_TMX_OBJECT_HPP

#include <memory>   // unique_ptr, make_unique
#include <string>   // string
#include <variant>  // variant, monostate
#include <vector>   // vector

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "rune_api.hpp"

// #include "tmx_global_id.hpp"

// #include "tmx_point.hpp"

// #include "tmx_property.hpp"

// #include "tmx_text.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_object;

struct tmx_polygon final
{
  std::vector<tmx_point> points;
};

struct tmx_polyline final
{
  std::vector<tmx_point> points;
};

struct tmx_template_object final
{
  std::string template_file;
  std::unique_ptr<tmx_object> object;
  maybe<std::string> tileset_source;
  maybe<tmx_global_id> tileset_first_id;
};

struct tmx_object final
{
  using data_type = std::variant<std::monostate,
                                 tmx_polygon,
                                 tmx_polyline,
                                 tmx_text,
                                 tmx_template_object,
                                 tmx_global_id>;

  int id{};
  float x{};
  float y{};
  float width{};
  float height{};
  float rotation{};
  std::string name;
  std::string type;
  tmx_properties properties;
  data_type data;
  bool is_ellipse{};
  bool is_point{};
  bool visible{true};
};

inline void from_json(const json_type& json, tmx_polygon& polygon)
{
  io::get_to(json, polygon.points);
}

inline void from_json(const json_type& json, tmx_polyline& line)
{
  io::get_to(json, line.points);
}

void from_json(const json_type& json, tmx_object& object);

inline void from_json(const json_type& json, tmx_template_object& object)
{
  json.at("template").get_to(object.template_file);
  object.object = std::make_unique<tmx_object>(json.at("object").get<tmx_object>());

  if (const auto it = json.find("tileset"); it != json.end())
  {
    io::emplace_to(json, "firstgid", object.tileset_first_id);
    object.tileset_source = json.at("source").get<std::string>();
  }
}

inline void from_json(const json_type& json, tmx_object& object)
{
  json.at("id").get_to(object.id);
  json.at("x").get_to(object.x);
  json.at("y").get_to(object.y);
  json.at("width").get_to(object.width);
  json.at("height").get_to(object.height);
  json.at("rotation").get_to(object.rotation);
  json.at("name").get_to(object.name);
  json.at("type").get_to(object.type);
  json.at("visible").get_to(object.visible);

  io::try_get_to(json, "ellipse", object.is_ellipse);
  io::try_get_to(json, "point", object.is_point);

  io::try_get_to(json, "properties", object.properties);

  if (const auto it = json.find("gid"); it != json.end())
  {
    object.data.emplace<tmx_global_id>(it->get<tmx_global_id::value_type>());
  }

  io::try_emplace_to<tmx_text>(json, "text", object.data);
  io::try_emplace_to<tmx_polygon>(json, "polygon", object.data);
  io::try_emplace_to<tmx_polyline>(json, "polyline", object.data);
  io::try_emplace_to<tmx_template_object>(json, "template", object.data);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_HPP

// #include "tmx/tmx_object_layer.hpp"
#ifndef RUNE_TMX_OBJECT_LAYER_HPP
#define RUNE_TMX_OBJECT_LAYER_HPP

#include <cassert>   // assert
#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM
#include <vector>    // vector

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_object.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_object_layer_draw_order
{
  top_down,
  index
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_object_layer_draw_order,
                             {{tmx_object_layer_draw_order::top_down, "topdown"},
                              {tmx_object_layer_draw_order::index, "index"}})

struct tmx_object_layer final  // Note, referred to as "object group" by tiled
{
  tmx_object_layer_draw_order draw_order{tmx_object_layer_draw_order::top_down};
  std::vector<tmx_object> objects;
};

inline void from_json(const json_type& json, tmx_object_layer& layer)
{
  io::get_to(json, "objects", layer.objects);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_OBJECT_LAYER_HPP

// #include "tmx/tmx_point.hpp"
#ifndef RUNE_TMX_POINT_HPP
#define RUNE_TMX_POINT_HPP

// #include "../aliases/json_type.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_point final
{
  float x{};  ///< The x-coordinate of the point.
  float y{};  ///< The y-coordinate of the point.
};

inline void from_json(const json_type& json, tmx_point& point)
{
  json.at("x").get_to(point.x);
  json.at("y").get_to(point.y);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_POINT_HPP

// #include "tmx/tmx_property.hpp"
#ifndef RUNE_TMX_PROPERTY_HPP
#define RUNE_TMX_PROPERTY_HPP

#include <algorithm>    // any_of, find_if
#include <cassert>      // assert
#include <concepts>     // same_as
#include <nenya.hpp>    // strong_type
#include <string>       // string
#include <string_view>  // string_view
#include <variant>      // variant, get, get_if, holds_alternative
#include <vector>       // vector

// #include "../aliases/json_type.hpp"

// #include "../core/rune_error.hpp"

// #include "rune_api.hpp"

// #include "tmx_color.hpp"

// #include "tmx_property_type.hpp"


namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_file_tag;
struct tmx_object_id_tag;
}  // namespace tags
/// \endcond

/// \addtogroup tmx
/// \{

using tmx_file = nenya::strong_type<std::string, tags::tmx_file_tag>;
using tmx_object_id = nenya::strong_type<int, tags::tmx_object_id_tag>;

/**
 * \brief Represents a property, with an associated name and value.
 */
struct tmx_property final
{
  using data_type =
      std::variant<std::string, tmx_file, tmx_object_id, tmx_color, int, float, bool>;

  std::string name;
  tmx_property_type type{tmx_property_type::string};
  data_type value;
};

using tmx_properties = std::vector<tmx_property>;

inline void from_json(const json_type& json, tmx_property& property)
{
  json.at("name").get_to(property.name);
  json.at("type").get_to(property.type);

  switch (property.type)
  {
    default:
      assert(false && "from_json() for tmx_property has missing branch!");

    case tmx_property_type::string:
      property.value.emplace<std::string>(json.at("value").get<std::string>());
      break;

    case tmx_property_type::integer:
      property.value.emplace<int>(json.at("value").get<int>());
      break;

    case tmx_property_type::floating:
      property.value.emplace<float>(json.at("value").get<float>());
      break;

    case tmx_property_type::boolean:
      property.value.emplace<bool>(json.at("value").get<bool>());
      break;

    case tmx_property_type::color:
      property.value.emplace<tmx_color>(json.at("value").get<tmx_color>());
      break;

    case tmx_property_type::file:
      property.value.emplace<tmx_file>(json.at("value").get<std::string>());
      break;

    case tmx_property_type::object:
      property.value.emplace<tmx_object_id>(json.at("value").get<int>());
      break;
  }
}

/// \} End of group tmx

namespace tmx {

/// \addtogroup tmx
/// \{

// clang-format off

template <typename T>
concept property_value_type = std::same_as<T, int> ||
                              std::same_as<T, float> ||
                              std::same_as<T, bool> ||
                              std::same_as<T, std::string> ||
                              std::same_as<T, tmx_color> ||
                              std::same_as<T, tmx_file> ||
                              std::same_as<T, tmx_object_id>;

// clang-format on

/// \name Property functions
/// \{

[[nodiscard]] inline auto try_get(const tmx_properties& properties,
                                  const std::string_view name)
    -> tmx_properties::const_iterator
{
  return std::ranges::find_if(properties, [name](const tmx_property& property) noexcept {
    return property.name == name;
  });
}

template <property_value_type T>
[[nodiscard]] auto get_if(const tmx_properties& properties,
                          const std::string_view name) noexcept -> const T*
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return std::get_if<T>(&it->value);
  }
  else
  {
    return nullptr;
  }
}

[[nodiscard]] inline auto get_if_string(const tmx_property& property) noexcept
    -> const std::string*
{
  return std::get_if<std::string>(&property.value);
}

[[nodiscard]] inline auto get_if_string(const tmx_properties& properties,
                                        const std::string_view name) -> const std::string*
{
  return get_if<std::string>(properties, name);
}

[[nodiscard]] inline auto get_if_int(const tmx_property& property) noexcept -> const int*
{
  return std::get_if<int>(&property.value);
}

[[nodiscard]] inline auto get_if_int(const tmx_properties& properties,
                                     const std::string_view name) -> const int*
{
  return get_if<int>(properties, name);
}

[[nodiscard]] inline auto get_if_float(const tmx_property& property) noexcept -> const
    float*
{
  return std::get_if<float>(&property.value);
}

[[nodiscard]] inline auto get_if_float(const tmx_properties& properties,
                                       const std::string_view name) -> const float*
{
  return get_if<float>(properties, name);
}

[[nodiscard]] inline auto get_if_bool(const tmx_property& property) noexcept -> const
    bool*
{
  return std::get_if<bool>(&property.value);
}

[[nodiscard]] inline auto get_if_bool(const tmx_properties& properties,
                                      const std::string_view name) -> const bool*
{
  return get_if<bool>(properties, name);
}

[[nodiscard]] inline auto get_if_color(const tmx_property& property) noexcept
    -> const tmx_color*
{
  return std::get_if<tmx_color>(&property.value);
}

[[nodiscard]] inline auto get_if_color(const tmx_properties& properties,
                                       const std::string_view name) -> const tmx_color*
{
  return get_if<tmx_color>(properties, name);
}

[[nodiscard]] inline auto get_if_file(const tmx_property& property) noexcept
    -> const tmx_file*
{
  return std::get_if<tmx_file>(&property.value);
}

[[nodiscard]] inline auto get_if_file(const tmx_properties& properties,
                                      const std::string_view name) -> const tmx_file*
{
  return get_if<tmx_file>(properties, name);
}

[[nodiscard]] inline auto get_if_object(const tmx_property& property) noexcept
    -> const tmx_object_id*
{
  return std::get_if<tmx_object_id>(&property.value);
}

[[nodiscard]] inline auto get_if_object(const tmx_properties& properties,
                                        const std::string_view name)
    -> const tmx_object_id*
{
  return get_if<tmx_object_id>(properties, name);
}

template <property_value_type T>
[[nodiscard]] auto is(const tmx_property& property) noexcept -> bool
{
  return std::holds_alternative<T>(property.value);
}

template <property_value_type T>
[[nodiscard]] auto is(const tmx_properties& properties, const std::string_view name)
    -> bool
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return is<T>(*it);
  }
  else
  {
    return false;
  }
}

[[nodiscard]] inline auto is_string(const tmx_property& property) noexcept -> bool
{
  return is<std::string>(property);
}

[[nodiscard]] inline auto is_string(const tmx_properties& properties,
                                    const std::string_view name) -> bool
{
  return is<std::string>(properties, name);
}

[[nodiscard]] inline auto is_int(const tmx_property& property) noexcept -> bool
{
  return is<int>(property);
}

[[nodiscard]] inline auto is_int(const tmx_properties& properties,
                                 const std::string_view name) -> bool
{
  return is<int>(properties, name);
}

[[nodiscard]] inline auto is_float(const tmx_property& property) noexcept -> bool
{
  return is<float>(property);
}

[[nodiscard]] inline auto is_float(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return is<float>(properties, name);
}

[[nodiscard]] inline auto is_bool(const tmx_property& property) noexcept -> bool
{
  return is<bool>(property);
}

[[nodiscard]] inline auto is_bool(const tmx_properties& properties,
                                  const std::string_view name) -> bool
{
  return is<bool>(properties, name);
}

[[nodiscard]] inline auto is_color(const tmx_property& property) noexcept -> bool
{
  return is<tmx_color>(property);
}

[[nodiscard]] inline auto is_color(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return is<tmx_color>(properties, name);
}

[[nodiscard]] inline auto is_file(const tmx_property& property) noexcept -> bool
{
  return is<tmx_file>(property);
}

[[nodiscard]] inline auto is_file(const tmx_properties& properties,
                                  const std::string_view name) -> bool
{
  return is<tmx_file>(properties, name);
}

[[nodiscard]] inline auto is_object(const tmx_property& property) noexcept -> bool
{
  return is<tmx_object_id>(property);
}

[[nodiscard]] inline auto is_object(const tmx_properties& properties,
                                    const std::string_view name) -> bool
{
  return is<tmx_object_id>(properties, name);
}

template <property_value_type T>
[[nodiscard]] auto get(const tmx_property& property) -> const T&
{
  return std::get<T>(property.value);
}

template <property_value_type T>
[[nodiscard]] auto get(const tmx_properties& properties, const std::string_view name)
    -> const T&
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return get<T>(*it);
  }
  else
  {
    throw rune_error{"Could not find property with the specified name!"};
  }
}

[[nodiscard]] inline auto get_string(const tmx_property& property) -> const std::string&
{
  return get<std::string>(property);
}

[[nodiscard]] inline auto get_string(const tmx_properties& properties,
                                     const std::string_view name) -> const std::string&
{
  return get<std::string>(properties, name);
}

[[nodiscard]] inline auto get_int(const tmx_property& property) -> int
{
  return get<int>(property);
}

[[nodiscard]] inline auto get_int(const tmx_properties& properties,
                                  const std::string_view name) -> int
{
  return get<int>(properties, name);
}

[[nodiscard]] inline auto get_float(const tmx_property& property) -> float
{
  return get<float>(property);
}

[[nodiscard]] inline auto get_float(const tmx_properties& properties,
                                    const std::string_view name) -> float
{
  return get<float>(properties, name);
}

[[nodiscard]] inline auto get_bool(const tmx_property& property) -> bool
{
  return get<bool>(property);
}

[[nodiscard]] inline auto get_bool(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return get<bool>(properties, name);
}

[[nodiscard]] inline auto get_color(const tmx_property& property) -> const tmx_color&
{
  return get<tmx_color>(property);
}

[[nodiscard]] inline auto get_color(const tmx_properties& properties,
                                    const std::string_view name) -> const tmx_color&
{
  return get<tmx_color>(properties, name);
}

[[nodiscard]] inline auto get_file(const tmx_property& property) -> const tmx_file&
{
  return get<tmx_file>(property);
}

[[nodiscard]] inline auto get_file(const tmx_properties& properties,
                                   const std::string_view name) -> const tmx_file&
{
  return get<tmx_file>(properties, name);
}

[[nodiscard]] inline auto get_object(const tmx_property& property) -> tmx_object_id
{
  return get<tmx_object_id>(property);
}

[[nodiscard]] inline auto get_object(const tmx_properties& properties,
                                     const std::string_view name) -> tmx_object_id
{
  return get<tmx_object_id>(properties, name);
}

/**
 * \brief Indicates whether or not a property with the specified name exists in a vector
 * of properties.
 *
 * \param properties the vector of properties that will be searched.
 * \param name the name of the property to look for.
 *
 * \return `true` if the properties contains a property with the specified name; `false`
 * otherwise.
 */
[[nodiscard]] inline auto contains(const tmx_properties& properties,
                                   const std::string_view name) -> bool
{
  return std::ranges::any_of(properties, [name](const tmx_property& property) noexcept {
    return property.name == name;
  });
}

/**
 * \brief Attempts to find and return a property with the specified name.
 *
 * \param properties the properties that will be searched.
 * \param name the name of the desired property.
 *
 * \return the property with the specified name.
 *
 * \throws rune_error if there is no property with the specified name.
 */
[[nodiscard]] inline auto at(const tmx_properties& properties,
                             const std::string_view name) -> const tmx_property&
{
  if (const auto it = try_get(properties, name); it != properties.end())
  {
    return *it;
  }
  else
  {
    throw rune_error{"Could not find property with specified name!"};
  }
}

/// \} End of property functions

/// \} End of group tmx

}  // namespace tmx

}  // namespace rune

#endif  // RUNE_TMX_PROPERTY_HPP

// #include "tmx/tmx_stagger_axis.hpp"
#ifndef RUNE_TMX_STAGGER_AXIS_HPP
#define RUNE_TMX_STAGGER_AXIS_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_stagger_axis
{
  x,
  y
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_stagger_axis,
                             {{tmx_stagger_axis::x, "x"}, {tmx_stagger_axis::y, "y"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_STAGGER_AXIS_HPP

// #include "tmx/tmx_stagger_index.hpp"
#ifndef RUNE_TMX_STAGGER_INDEX_HPP
#define RUNE_TMX_STAGGER_INDEX_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_stagger_index
{
  odd,
  even
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_stagger_index,
                             {{tmx_stagger_index::odd, "odd"},
                              {tmx_stagger_index::even, "even"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_STAGGER_INDEX_HPP

// #include "tmx/tmx_terrain.hpp"
#ifndef RUNE_TMX_TERRAIN_HPP
#define RUNE_TMX_TERRAIN_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_terrain final
{
  tmx_local_id tile{};
  std::string name;
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_terrain& terrain)
{
  terrain.tile = tmx_local_id{json.at("tile").get<tmx_local_id::value_type>()};
  json.at("name").get_to(terrain.name);
  io::try_get_to(json, "properties", terrain.properties);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TERRAIN_HPP

// #include "tmx/tmx_text.hpp"
#ifndef RUNE_TMX_TEXT_HPP
#define RUNE_TMX_TEXT_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_color.hpp"

// #include "tmx_halign.hpp"

// #include "tmx_valign.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_text final
{
  std::string text;
  std::string family{"sans-serif"};
  tmx_color color;
  tmx_halign horizontal_alignment{tmx_halign::left};
  tmx_valign vertical_alignment{tmx_valign::top};
  int pixel_size{16};
  bool bold{};
  bool italic{};
  bool kerning{true};
  bool strikeout{};
  bool underline{};
  bool wrap{};
};

inline void from_json(const json_type& json, tmx_text& text)
{
  json.at("text").get_to(text.text);

  io::try_get_to(json, "fontfamily", text.family);
  io::try_get_to(json, "halign", text.horizontal_alignment);
  io::try_get_to(json, "valign", text.vertical_alignment);
  io::try_get_to(json, "pixelsize", text.pixel_size);
  io::try_get_to(json, "bold", text.bold);
  io::try_get_to(json, "italic", text.italic);
  io::try_get_to(json, "kerning", text.kerning);
  io::try_get_to(json, "strikeout", text.strikeout);
  io::try_get_to(json, "underline", text.underline);
  io::try_get_to(json, "wrap", text.wrap);

  if (const auto it = json.find("color"); it != json.end())
  {
    text.color = tmx::make_color(it->get<std::string>());
  }
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TEXT_HPP

// #include "tmx/tmx_tile.hpp"
#ifndef RUNE_TMX_TILE_HPP
#define RUNE_TMX_TILE_HPP

#include <array>   // array
#include <string>  // string

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../core/from_string.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_animation.hpp"

// #include "tmx_layer.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile final
{
  tmx_local_id id{};
  maybe<tmx_animation> animation;
  maybe<std::array<int, 4>> terrain;
  maybe<std::string> type;
  maybe<std::string> image;
  maybe<int> image_width;
  maybe<int> image_height;
  maybe<float> probability;
  maybe<tmx_layer> object_layer;
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_tile& tile)
{
  io::emplace_to(json, "id", tile.id);

  io::try_get_to(json, "animation", tile.animation);
  io::try_get_to(json, "type", tile.type);
  io::try_get_to(json, "image", tile.image);
  io::try_get_to(json, "imagewidth", tile.image_width);
  io::try_get_to(json, "imageheight", tile.image_height);
  io::try_get_to(json, "probability", tile.probability);
  io::try_get_to(json, "objectgroup", tile.object_layer);
  io::try_get_to(json, "properties", tile.properties);

  if (const auto it = json.find("terrain"); it != json.end())
  {
    auto& terrain = tile.terrain.emplace();
    for (const auto& [key, value] : it->items())
    {
      const auto index = from_string<usize>(key).value();
      terrain.at(index) = value.get<int>();
    }
  }
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_HPP

// #include "tmx/tmx_tile_layer.hpp"
#ifndef RUNE_TMX_TILE_LAYER_HPP
#define RUNE_TMX_TILE_LAYER_HPP

// #include "../aliases/json_type.hpp"

// #include "../aliases/maybe.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_data.hpp"

// #include "tmx_tile_layer_compression.hpp"

// #include "tmx_tile_layer_encoding.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_layer final
{
  tmx_tile_layer_compression compression{tmx_tile_layer_compression::none};
  tmx_tile_layer_encoding encoding{tmx_tile_layer_encoding::csv};
  maybe<tmx_data> data;
  // TODO std::vector<chunk> m_chunks;
};

inline void from_json(const json_type& json, tmx_tile_layer& layer)
{
  io::try_get_to(json, "compression", layer.compression);
  io::try_get_to(json, "encoding", layer.encoding);
  io::try_get_to(json, "data", layer.data);

  // TODO
  //  if (json.contains("chunks")) {
  //    m_chunks = detail::fill<std::vector<chunk>>(json, "chunks");
  //  }
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_HPP

// #include "tmx/tmx_tile_layer_compression.hpp"
#ifndef RUNE_TMX_TILE_LAYER_COMPRESSION_HPP
#define RUNE_TMX_TILE_LAYER_COMPRESSION_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_tile_layer_compression
{
  none,
  gzip,
  zlib
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_tile_layer_compression,
                             {{tmx_tile_layer_compression::none, ""},
                              {tmx_tile_layer_compression::gzip, "gzip"},
                              {tmx_tile_layer_compression::zlib, "zlib"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_COMPRESSION_HPP

// #include "tmx/tmx_tile_layer_encoding.hpp"
#ifndef RUNE_TMX_TILE_LAYER_ENCODING_HPP
#define RUNE_TMX_TILE_LAYER_ENCODING_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_tile_layer_encoding
{
  csv,
  base64
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_tile_layer_encoding,
                             {{tmx_tile_layer_encoding::csv, "csv"},
                              {tmx_tile_layer_encoding::base64, "base64"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_LAYER_ENCODING_HPP

// #include "tmx/tmx_tile_offset.hpp"
#ifndef RUNE_TMX_TILE_OFFSET_HPP
#define RUNE_TMX_TILE_OFFSET_HPP

// #include "../aliases/json_type.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tile_offset final
{
  int x{};
  int y{};
};

inline void from_json(const json_type& json, tmx_tile_offset& offset)
{
  json.at("x").get_to(offset.x);
  json.at("y").get_to(offset.y);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILE_OFFSET_HPP

// #include "tmx/tmx_tileset.hpp"
#ifndef RUNE_TMX_TILESET_HPP
#define RUNE_TMX_TILESET_HPP

#include <string>  // string
#include <vector>  // vector

// #include "../aliases/maybe.hpp"

// #include "rune_api.hpp"

// #include "tmx_color.hpp"

// #include "tmx_global_id.hpp"

// #include "tmx_grid.hpp"

// #include "tmx_property.hpp"

// #include "tmx_terrain.hpp"

// #include "tmx_tile.hpp"

// #include "tmx_tile_offset.hpp"

// #include "tmx_wang_set.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_tileset final
{
  tmx_global_id first_id{1};
  int tile_width{};
  int tile_height{};
  int tile_count{};
  int column_count{};
  int image_width{};
  int image_height{};
  int margin{};
  int spacing{};

  std::string name;
  std::string image;
  std::string external_source;
  std::string tiled_version;
  std::string json_version;

  maybe<tmx_color> background;
  maybe<tmx_color> transparent;
  maybe<tmx_tile_offset> tile_offset;
  maybe<tmx_grid> grid;

  std::vector<tmx_tile> tiles;
  std::vector<tmx_terrain> terrains;
  std::vector<tmx_wang_set> wang_sets;
  tmx_properties properties;
};

using tmx_tilesets = std::vector<tmx_tileset>;

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TILESET_HPP

// #include "tmx/tmx_valign.hpp"
#ifndef RUNE_TMX_VALIGN_HPP
#define RUNE_TMX_VALIGN_HPP

#include <json.hpp>  // NLOHMANN_JSON_SERIALIZE_ENUM

namespace rune {

/// \addtogroup tmx
/// \{

enum class tmx_valign
{
  center,
  top,
  bottom
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_valign,
                             {{tmx_valign::center, "center"},
                              {tmx_valign::top, "top"},
                              {tmx_valign::bottom, "bottom"}})

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_VALIGN_HPP

// #include "tmx/tmx_wang_color.hpp"
#ifndef RUNE_TMX_WANG_COLOR_HPP
#define RUNE_TMX_WANG_COLOR_HPP

#include <string>  // string

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_color.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_color final
{
  tmx_local_id tile{};
  tmx_color color;
  std::string name;
  float probability{};
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_wang_color& color)
{
  json.at("name").get_to(color.name);
  json.at("color").get_to(color.color);
  json.at("probability").get_to(color.probability);
  io::emplace_to(json, "tile", color.tile);

  io::try_get_to(json, "properties", color.properties);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_COLOR_HPP

// #include "tmx/tmx_wang_set.hpp"
#ifndef RUNE_TMX_WANG_SET_HPP
#define RUNE_TMX_WANG_SET_HPP

#include <string>  // string
#include <vector>  // vector

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_local_id.hpp"

// #include "tmx_property.hpp"

// #include "tmx_wang_color.hpp"

// #include "tmx_wang_tile.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_set final
{
  tmx_local_id tile{};
  std::string name;
  std::vector<tmx_wang_tile> wang_tiles;
  std::vector<tmx_wang_color> colors;
  tmx_properties properties;
};

inline void from_json(const json_type& json, tmx_wang_set& set)
{
  io::emplace_to(json, "tile", set.tile);
  json.at("name").get_to(set.name);

  // TODO check if colors or wangtiles are required
  io::try_get_to(json, "colors", set.colors);
  io::try_get_to(json, "wangtiles", set.wang_tiles);
  io::try_get_to(json, "properties", set.properties);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_SET_HPP

// #include "tmx/tmx_wang_tile.hpp"
#ifndef RUNE_TMX_WANG_TILE_HPP
#define RUNE_TMX_WANG_TILE_HPP

#include <array>  // array

// #include "../aliases/integers.hpp"

// #include "../aliases/json_type.hpp"

// #include "../io/json_utils.hpp"

// #include "tmx_local_id.hpp"


namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_wang_tile final
{
  tmx_local_id tile{};
  std::array<uint8, 8> indices{};
};

inline void from_json(const json_type& json, tmx_wang_tile& tile)
{
  io::emplace_to(json, "tileid", tile.tile);
  json.at("wangid").get_to(tile.indices);
}

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_WANG_TILE_HPP


#endif  // RUNE_EVERYTHING_HPP
