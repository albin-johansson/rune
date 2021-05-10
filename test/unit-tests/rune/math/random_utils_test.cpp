#include "math/random_utils.hpp"

#include <gtest/gtest.h>

#include <algorithm>  // count
#include <iomanip>    // boolalpha
#include <iostream>   // cout
#include <vector>     // vector

TEST(RandomUtils, NextRandom)
{
  const auto i = rune::next_random(0, 100);
  ASSERT_GE(i, 0);
  ASSERT_LE(i, 100);

  std::cout << "Random integer in [0, 100]: " << rune::next_random(0, 100) << '\n';
}

TEST(RandomUtils, NextBool)
{
  std::vector<bool> values;
  values.reserve(1'000);

  for (auto i = 0; i < 1'000; ++i)
  {
    values.push_back(rune::next_bool());
  }

  const auto t = std::ranges::count(values, true);
  std::cout << "1'000 runs -> #true: " << t << ", #false: " << (1'000 - t) << '\n';
}

TEST(RandomUtils, NextFloat)
{
  const auto f = rune::next_float();
  ASSERT_GE(f, 0.0f);
  ASSERT_LE(f, 1.0f);

  std::cout << "Random float in [0, 1]: " << rune::next_float() << '\n';
}

TEST(RandomUtils, NextDouble)
{
  const auto d = rune::next_double();
  ASSERT_GE(d, 0.0);
  ASSERT_LE(d, 1.0);

  std::cout << "Random double in [0, 1]: " << rune::next_double() << '\n';
}