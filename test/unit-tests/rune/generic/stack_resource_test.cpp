#include "generic/stack_resource.hpp"

#include <gtest/gtest.h>

TEST(StackResource, BasicUsage)
{
  rune::stack_resource<128> resource;
  std::pmr::vector<int> vector{resource.get()};

  vector.push_back(12);
  vector.push_back(24);
  vector.push_back(36);
  ASSERT_EQ(3, vector.size());
}
