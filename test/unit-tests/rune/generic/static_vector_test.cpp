#include "generic/static_vector.hpp"

#include <gtest/gtest.h>

#include <concepts>  // same_as
#include <string>    // string

TEST(StaticVector, Defaults)
{
  const rune::static_vector<int, 3> vector;

  ASSERT_EQ(3, vector.capacity());
  ASSERT_EQ(0, vector.size());

  ASSERT_ANY_THROW(vector.at(0));
}

TEST(StaticVector, FromInitializerList)
{
  rune::static_vector vector = {10, 20, 30};
  static_assert(std::same_as<decltype(vector), rune::static_vector<int, 3>>);

  ASSERT_EQ(3, vector.size());
  ASSERT_EQ(3, vector.capacity());

  ASSERT_EQ(10, vector.at(0));
  ASSERT_EQ(20, vector.at(1));
  ASSERT_EQ(30, vector.at(2));

  ASSERT_THROW(vector.at(3), rune::rune_error);
}

TEST(StaticVector, Clear)
{
  rune::static_vector<std::string, 3> vector;

  ASSERT_NO_THROW(vector.clear());
  ASSERT_EQ(0, vector.size());
  ASSERT_EQ(3, vector.capacity());

  {
    auto& foo = vector.emplace_back("foo");
    ASSERT_EQ("foo", foo);
  }

  ASSERT_EQ(1, vector.size());
  ASSERT_EQ(3, vector.capacity());

  vector.emplace_back("bar");
  ASSERT_EQ(2, vector.size());
  ASSERT_EQ(3, vector.capacity());
  ASSERT_NO_THROW(vector.at(0));
  ASSERT_NO_THROW(vector.at(1));

  vector.clear();
  ASSERT_EQ(0, vector.size());
  ASSERT_EQ(3, vector.capacity());
  ASSERT_THROW(vector.at(0), rune::rune_error);
  ASSERT_THROW(vector.at(1), rune::rune_error);
}

TEST(StaticVector, RValuePushBack)
{
  rune::static_vector<int, 3> vector;
  ASSERT_EQ(0, vector.size());

  vector.push_back(42);
  ASSERT_EQ(1, vector.size());
  ASSERT_EQ(42, vector.at(0));

  vector.push_back(123);
  ASSERT_EQ(2, vector.size());
  ASSERT_EQ(42, vector.at(0));
  ASSERT_EQ(123, vector.at(1));

  vector.push_back(27);
  ASSERT_EQ(3, vector.size());
  ASSERT_EQ(42, vector.at(0));
  ASSERT_EQ(123, vector.at(1));
  ASSERT_EQ(27, vector.at(2));

  ASSERT_THROW(vector.push_back(10), rune::rune_error);
}

TEST(StaticVector, LValuePushBack)
{
  rune::static_vector<int, 3> vector;
  ASSERT_EQ(0, vector.size());

  const auto a = 42;
  const auto b = 123;
  const auto c = 27;

  vector.push_back(a);
  ASSERT_EQ(1, vector.size());
  ASSERT_EQ(a, vector.at(0));

  vector.push_back(b);
  ASSERT_EQ(2, vector.size());
  ASSERT_EQ(a, vector.at(0));
  ASSERT_EQ(b, vector.at(1));

  vector.push_back(c);
  ASSERT_EQ(3, vector.size());
  ASSERT_EQ(a, vector.at(0));
  ASSERT_EQ(b, vector.at(1));
  ASSERT_EQ(c, vector.at(2));

  ASSERT_THROW(vector.push_back(10), rune::rune_error);
}

TEST(StaticVector, EmplaceBack)
{
  rune::static_vector<std::string, 3> vector;
  ASSERT_EQ(0, vector.size());
  ASSERT_TRUE(vector.empty());

  auto& foo = vector.emplace_back("foo");
  ASSERT_FALSE(vector.empty());
  ASSERT_EQ(1, vector.size());
  ASSERT_EQ("foo", foo);

  auto& bar = vector.emplace_back("bar");
  ASSERT_EQ(2, vector.size());
  ASSERT_EQ("bar", bar);

  auto& hello = vector.emplace_back("hello");
  ASSERT_EQ(3, vector.size());
  ASSERT_EQ("hello", hello);

  ASSERT_THROW(vector.emplace_back("world"), rune::rune_error);
}

TEST(StaticVector, PopBack)
{
  rune::static_vector<int, 3> vector;
  ASSERT_EQ(0, vector.size());
  ASSERT_TRUE(vector.empty());

  vector.push_back(42);
  ASSERT_EQ(1, vector.size());
  ASSERT_FALSE(vector.empty());

  vector.pop_back();
  ASSERT_EQ(0, vector.size());
  ASSERT_TRUE(vector.empty());
}

TEST(StaticVector, At)
{
  rune::static_vector<int, 2> vector;
  ASSERT_THROW(vector.at(0), rune::rune_error);

  vector.push_back(123);
  ASSERT_NO_THROW(vector.at(0));
}

TEST(StaticVector, SubscriptOperator)
{
  rune::static_vector vector = {24, 48, 64};
  ASSERT_EQ(24, vector[0]);
  ASSERT_EQ(48, vector[1]);
  ASSERT_EQ(64, vector[2]);
}

TEST(StaticVector, RangeFor)
{
  rune::static_vector vector = {1, 2, 3};
  auto count = 0;

  for (const auto value : vector)
  {
    ++count;
  }

  ASSERT_EQ(3, count);
}

TEST(StaticVector, Empty)
{
  const rune::static_vector<int, 2> empty;
  ASSERT_TRUE(empty.empty());

  const rune::static_vector vector = {1, 2, 3};
  ASSERT_FALSE(vector.empty());
}
