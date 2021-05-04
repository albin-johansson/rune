#include "to_string.hpp"

#include <gtest/gtest.h>

#include <cstdint>   // int32_t, int64_t, uint32_t, uint64_t
#include <iostream>  // cout
#include <limits>    // numeric_limits

TEST(ToString, Integers)
{
  ASSERT_TRUE(rune::to_string(std::numeric_limits<std::int32_t>::max()));
  ASSERT_TRUE(rune::to_string(std::numeric_limits<std::int64_t>::max()));
  ASSERT_TRUE(rune::to_string(std::numeric_limits<std::uint32_t>::max()));
  ASSERT_TRUE(rune::to_string(std::numeric_limits<std::uint64_t>::max()));

  std::cout << "rune::to_string(123) == \"" << rune::to_string(123).value() << "\"\n";
}

TEST(ToString, Floats)
{
  ASSERT_TRUE(rune::to_string(std::numeric_limits<float>::max()));
  ASSERT_TRUE(rune::to_string(std::numeric_limits<double>::max()));

  std::cout << "rune::to_string(12.3f) == \"" << rune::to_string(12.3f).value() << "\"\n";
}
