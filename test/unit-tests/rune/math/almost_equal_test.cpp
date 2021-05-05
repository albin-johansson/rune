#include "almost_equal.hpp"

#include <gtest/gtest.h>

TEST(AlmostEqual, Identity)
{
  ASSERT_TRUE(rune::almost_equal(1.0, 1.0));
  ASSERT_TRUE(rune::almost_equal(1.0f, 1.0f));
}

TEST(AlmostEqual, NotEqual)
{
  ASSERT_FALSE(rune::almost_equal(1.0, -1.0));
  ASSERT_FALSE(rune::almost_equal(1.0, 2.0));

  ASSERT_FALSE(rune::almost_equal(1.0, 1.1));
  ASSERT_FALSE(rune::almost_equal(1.0, 1.01));
  ASSERT_FALSE(rune::almost_equal(1.0, 1.001));
  ASSERT_FALSE(rune::almost_equal(1.0, 1.0001));
}

TEST(AlmostEqual, AlmostEqual)
{
  ASSERT_TRUE(rune::almost_equal(1.0, 1.000009));
  ASSERT_TRUE(rune::almost_equal(1.0f, 1.000009f));
}