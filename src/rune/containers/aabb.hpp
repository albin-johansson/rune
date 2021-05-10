#ifndef RUNE_CONTAINERS_AABB_HPP
#define RUNE_CONTAINERS_AABB_HPP

#include <cassert>   // assert
#include <concepts>  // floating_point

#include "../math/max.hpp"
#include "../math/min.hpp"
#include "../math/vector2.hpp"

namespace rune {

/// \addtogroup containers
/// \{

template <std::floating_point T>
struct basic_aabb final
{
  using precision_type = T;
  using vector_type = basic_vector2<precision_type>;

  vector_type min;
  vector_type max;
  precision_type area{};

  [[nodiscard]] constexpr auto contains(const basic_aabb& other) const noexcept -> bool
  {
    return (other.min.x >= min.x) && (other.min.y >= min.y) && (other.max.x <= max.x) &&
           (other.max.y <= max.y);
  }

  [[nodiscard]] constexpr auto size() const noexcept -> vector_type
  {
    return max - min;
  }
};

/// \name Serialization
/// \{

template <std::floating_point T>
void serialize(auto& archive, basic_aabb<T>& aabb)
{
  archive(aabb.min, aabb.max, aabb.area);
}

/// \} End of serialization

/// \name AABB operators
/// \{

template <std::floating_point T>
[[nodiscard]] constexpr auto operator==(const basic_aabb<T>& a,
                                        const basic_aabb<T>& b) noexcept -> bool
{
  return a.min == b.min && a.max == b.max;
}

template <std::floating_point T>
[[nodiscard]] constexpr auto operator!=(const basic_aabb<T>& a,
                                        const basic_aabb<T>& b) noexcept -> bool
{
  return !(a == b);
}

/// \} End of AABB operators

/// \name AABB functions
/// \{

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

template <std::floating_point T>
void fatten(basic_aabb<T>& aabb, const T factor) noexcept
{
  const auto size = aabb.size();

  const auto dx = factor * size.x;
  const auto dy = factor * size.y;

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
