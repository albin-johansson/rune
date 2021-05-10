#include "math/max.hpp"

#include <gtest/gtest.h>

static_assert(noexcept(rune::max(1, 2)));

TEST(Max, Max)
{
  ASSERT_EQ(1, rune::max(1, 1));
  ASSERT_EQ(2, rune::max(1, 2));
  ASSERT_EQ(1.3f, rune::max(1.2f, 1.3f));
  ASSERT_EQ(1.3f, rune::max(1.3f, 1.2f));
}
