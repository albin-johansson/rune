#include "rune-aabb/aabb.hpp"

#include <gtest/gtest.h>

TEST(Aabb, MakeAabb)
{
  const auto lower = rune::float2{12.3f, 34.8f};
  const auto upper = rune::float2{83.4f, 94.1f};
  const auto aabb = rune::make_aabb(lower, upper);

  ASSERT_EQ(lower, aabb.min);
  ASSERT_EQ(upper, aabb.max);
  ASSERT_EQ(rune::compute_area(aabb), aabb.area);
}

TEST(Aabb, Size)
{
  const auto lower = rune::float2{84, 74};
  const auto upper = rune::float2{323, 755};
  const auto aabb = rune::make_aabb(lower, upper);

  ASSERT_EQ(upper - lower, aabb.size());
}

TEST(Aabb, Merge)
{
  const auto a = rune::make_aabb(rune::float2{12.3f, 45.6f}, rune::float2{78.9f, 82.1f});
  const auto b = rune::make_aabb(rune::float2{34.3f, 22.9f}, rune::float2{84.3f, 63.4f});

  const auto c = rune::merge(a, b);
  ASSERT_EQ(12.3f, c.min.x);
  ASSERT_EQ(22.9f, c.min.y);
  ASSERT_EQ(84.3f, c.max.x);
  ASSERT_EQ(82.1f, c.max.y);
}