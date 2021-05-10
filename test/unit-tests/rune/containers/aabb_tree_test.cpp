#include "containers/aabb_tree.hpp"

#include <gtest/gtest.h>

#include <algorithm>  // count
#include <iostream>   // cout
#include <iterator>   // back_inserter
#include <vector>     // vector

using aabb_tree = rune::aabb_tree<int>;

TEST(AabbTree, Defaults)
{
  const aabb_tree tree;
  ASSERT_EQ(0, tree.size());
  ASSERT_EQ(0, tree.height());
  ASSERT_EQ(0, tree.node_count());
  ASSERT_EQ(0, tree.surface_area_ratio());
  ASSERT_EQ(0, tree.maximum_balance());
  ASSERT_EQ(0.05f, tree.thickness_factor());
  ASSERT_TRUE(tree.empty());
}

TEST(AabbTree, Insert)
{
  aabb_tree tree;

  tree.insert(42, {12, 34}, {56, 78});
  ASSERT_EQ(1, tree.size());
  ASSERT_EQ(1, tree.node_count());
  ASSERT_EQ(0, tree.height());
  ASSERT_FALSE(tree.empty());

  tree.insert(27, {10, 10}, {50, 50});
  ASSERT_EQ(2, tree.size());
  ASSERT_EQ(3, tree.node_count());
  ASSERT_EQ(1, tree.height());
  ASSERT_FALSE(tree.empty());

  tree.insert(123, {48, 93}, {132, 189});
  ASSERT_EQ(3, tree.size());
  ASSERT_EQ(5, tree.node_count());
  ASSERT_EQ(2, tree.height());
  ASSERT_FALSE(tree.empty());

  //  std::cout << tree << '\n';
}

TEST(AabbTree, Erase)
{
  aabb_tree tree;

  tree.insert(42, {12, 34}, {56, 78});
  tree.insert(27, {10, 10}, {50, 50});
  tree.insert(123, {48, 93}, {132, 189});
  ASSERT_EQ(3, tree.size());

  tree.erase(27);
  ASSERT_EQ(2, tree.size());

  ASSERT_NO_THROW(tree.erase(27));
  ASSERT_EQ(2, tree.size());

  tree.erase(123);
  ASSERT_EQ(1, tree.size());

  tree.erase(42);
  ASSERT_EQ(0, tree.size());
  ASSERT_TRUE(tree.empty());
}

TEST(AabbTree, Clear)
{
  aabb_tree tree;
  ASSERT_NO_THROW(tree.clear());

  tree.insert(42, {12, 34}, {56, 78});
  tree.insert(27, {10, 10}, {50, 50});
  tree.insert(123, {48, 93}, {132, 189});

  ASSERT_EQ(3, tree.size());
  ASSERT_FALSE(tree.empty());

  tree.clear();
  ASSERT_EQ(0, tree.size());
  ASSERT_EQ(0, tree.node_count());
  ASSERT_EQ(0, tree.height());
  ASSERT_TRUE(tree.empty());
}

TEST(AabbTree, Rebuild)
{
  aabb_tree tree;
  ASSERT_NO_THROW(tree.rebuild());

  tree.insert(42, {12, 34}, {56, 78});
  tree.insert(27, {10, 10}, {50, 50});
  tree.insert(123, {48, 93}, {132, 189});

  tree.set_position(42, {342, 934});
  tree.set_position(123, {112, 35});

  ASSERT_NO_THROW(tree.rebuild());
  ASSERT_EQ(3, tree.size());
}

TEST(AabbTree, UpdateWithAabb)
{
  aabb_tree tree;
  tree.disable_thickness_factor();

  tree.insert(42, {12, 34}, {56, 78});
  tree.insert(27, {10, 10}, {50, 50});
  tree.insert(123, {48, 93}, {132, 189});

  const auto aabb = rune::make_aabb(rune::float2{10, 11}, rune::float2{20, 21});
  ASSERT_FALSE(tree.update(0, aabb));
  ASSERT_TRUE(tree.update(42, aabb));

  ASSERT_EQ(aabb.min, tree.at(42).min);
  ASSERT_EQ(aabb.max, tree.at(42).max);
}

TEST(AabbTree, UpdateLowerUpper)
{
  aabb_tree tree;
  tree.disable_thickness_factor();

  tree.insert(42, {12, 34}, {56, 78});
  tree.insert(27, {10, 10}, {50, 50});
  tree.insert(123, {48, 93}, {132, 189});

  ASSERT_FALSE(tree.update(0, {0, 0}, {10, 10}));
  ASSERT_TRUE(tree.update(42, {10, 11}, {20, 21}));

  const auto& aabb = tree.at(42);
  ASSERT_EQ(rune::float2(10, 11), aabb.min);
  ASSERT_EQ(rune::float2(20, 21), aabb.max);
}

TEST(AabbTree, SetPosition)
{
  aabb_tree tree;
  tree.disable_thickness_factor();

  tree.insert(42, rune::float2{12, 34}, rune::float2{56, 78});
  tree.insert(27, rune::float2{10, 10}, rune::float2{50, 50});

  const auto lower = rune::float2{432, 123};
  const auto upper = rune::float2{921, 434};
  const auto size = upper - lower;
  tree.insert(123, lower, upper);

  ASSERT_FALSE(tree.set_position(0, rune::float2{43, 87}));
  ASSERT_TRUE(tree.set_position(123, rune::float2{43, 87}));

  const auto& aabb = tree.at(123);
  ASSERT_EQ(rune::float2(43, 87), aabb.min);
  ASSERT_EQ(size, aabb.size());
}

TEST(AabbTree, At)
{
  aabb_tree tree;
  tree.disable_thickness_factor();

  ASSERT_THROW(tree.at(0), std::out_of_range);

  const auto lower = rune::float2{32, 88};
  const auto upper = rune::float2{652, 213};
  tree.insert(42, lower, upper);

  const auto& aabb = tree.at(42);
  ASSERT_EQ(lower, aabb.min);
  ASSERT_EQ(upper, aabb.max);
}

TEST(AabbTree, Find)
{
  aabb_tree tree;
  tree.disable_thickness_factor();

  ASSERT_NO_THROW(tree.find(0));
  ASSERT_FALSE(tree.find(0));

  const auto lower = rune::float2{32, 88};
  const auto upper = rune::float2{652, 213};
  tree.insert(42, lower, upper);

  const auto* aabb = tree.find(42);
  ASSERT_TRUE(aabb);
  ASSERT_EQ(lower, aabb->min);
  ASSERT_EQ(upper, aabb->max);
}

TEST(AabbTree, Query)
{
  aabb_tree tree;
  tree.disable_thickness_factor();

  tree.insert(1, {10, 10}, {110, 110});
  tree.insert(2, {90, 10}, {160, 60});
  tree.insert(3, {10, 90}, {35, 115});

  // Way off
  tree.insert(4, {1000, 1000}, {1100, 1100});

  std::vector<int> candidates;
  tree.query(1, std::back_inserter(candidates));

  ASSERT_EQ(2, candidates.size());

  ASSERT_EQ(0, std::ranges::count(candidates, 1));  // Never collide with self
  ASSERT_EQ(1, std::ranges::count(candidates, 2));
  ASSERT_EQ(1, std::ranges::count(candidates, 3));
  ASSERT_EQ(0, std::ranges::count(candidates, 4));

  tree.query(1, [](const int id) {
    ASSERT_TRUE(id == 2 || id == 3);
  });

  // Test ability to short-circuit queries
  auto count = 0;
  tree.query(1, [&](const int id) {
    ++count;
    return true;
  });

  ASSERT_EQ(1, count);
}
