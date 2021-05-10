#include "math/min.hpp"

#include <gtest/gtest.h>

static_assert(noexcept(rune::min(1, 2)));

TEST(Min, Min)
{
  ASSERT_EQ(1, rune::min(1, 1));
  ASSERT_EQ(1, rune::min(1, 2));
  ASSERT_EQ(1.2f, rune::min(1.2f, 1.3f));
  ASSERT_EQ(1.2f, rune::min(1.3f, 1.2f));
}
