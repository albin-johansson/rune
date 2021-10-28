#include "rune-core/from_string.hpp"

#include <gtest/gtest.h>

#include <cstdint>  // uint8_t

TEST(FromString, Integer)
{
  ASSERT_FALSE(rune::from_string<int>("foo"));

  ASSERT_EQ(42, rune::from_string<int>("42"));
  ASSERT_EQ(-123, rune::from_string<int>("-123"));
  ASSERT_EQ(234, rune::from_string<std::uint8_t>("234"));
}

TEST(FromString, Float)
{
  ASSERT_FALSE(rune::from_string<float>("bar"));

  ASSERT_EQ(12.3, rune::from_string<double>("12.3"));
  ASSERT_EQ(932.0f, rune::from_string<float>("932"));
  ASSERT_EQ(-83.4f, rune::from_string<float>("-83.4"));
}