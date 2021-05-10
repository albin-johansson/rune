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
  using vector_type = basic_vector2<T>;

  vector_type min;
  vector_type max;
  double area{};

  [[nodiscard]] constexpr auto contains(const vector_type& other) const noexcept -> bool
  {
    return (other.min.x >= min.x) && (other.min.y >= min.y) && (other.max.x <= max.x) &&
           (other.max.y <= max.y);
  }

  [[nodiscard]] constexpr auto size() const noexcept -> vector_type
  {
    return max - min;
  }
};

template <std::floating_point T>
[[nodiscard]] constexpr auto compute_area(const basic_aabb<T>& aabb) noexcept -> double
{
  auto sum = 0.0;

  for (auto a = 0; a < 2; ++a)
  {
    auto product = 1.0;

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

  return 2.0 * sum;
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

/// \} End of group containers

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_HPP
