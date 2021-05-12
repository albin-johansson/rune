#include "containers/vector_map.hpp"

#include <gtest/gtest.h>

#include <concepts>  // same_as
#include <string>    // string

namespace {

using map_type = rune::vector_map<int, std::string>;

static_assert(std::same_as<map_type::key_type, int>);
static_assert(std::same_as<map_type::mapped_type, std::string>);
static_assert(std::same_as<map_type::value_type, std::pair<int, std::string>>);

// Used to verify that the map can handle keys that are comparable to the actual key
class custom_string final
{
 public:
  explicit custom_string(const char* str) : m_string{str}
  {}

  [[nodiscard]] bool operator==(const std::string& str) const
  {
    return m_string == str;
  }

  [[nodiscard]] bool operator!=(const std::string& str) const
  {
    return m_string != str;
  }

 private:
  std::string m_string;
};

static_assert(rune::transparent_to<std::string, custom_string>);

}  // namespace

TEST(VectorMap, DefaultConstruction)
{
  const map_type map;

  ASSERT_TRUE(map.empty());
  ASSERT_EQ(0, map.size());
  ASSERT_EQ(0, map.capacity());
}

TEST(VectorMap, CapacityConstructor)
{
  map_type map{4};

  ASSERT_TRUE(map.empty());
  ASSERT_EQ(0, map.size());
  ASSERT_EQ(4, map.capacity());
}

TEST(VectorMap, Clear)
{
  map_type map;
  ASSERT_EQ(0, map.size());

  map.emplace(1, "a");
  map.emplace(2, "b");
  ASSERT_EQ(2, map.size());

  map.clear();
  ASSERT_EQ(0, map.size());
  ASSERT_TRUE(map.empty());

  ASSERT_NO_THROW(map.clear());
}

TEST(VectorMap, Reserve)
{
  map_type map;
  ASSERT_EQ(0, map.capacity());

  map.reserve(5);
  ASSERT_EQ(5, map.capacity());

  // Reserving with capacity less than actual capacity should have no effect
  map.reserve(4);
  ASSERT_EQ(5, map.capacity());

  map.reserve(10);
  ASSERT_EQ(10, map.capacity());
}

TEST(VectorMap, EmplaceVariadic)
{
  map_type map;
  ASSERT_EQ(0, map.size());

  map.emplace(10, "A");
  ASSERT_EQ(1, map.size());

  map.emplace(20, "B");
  ASSERT_EQ(2, map.size());

  const auto& [key, value] = map.emplace(30, "C");
  ASSERT_EQ(3, map.size());

  ASSERT_EQ(30, key);
  ASSERT_EQ("C", value);
}

TEST(VectorMap, EmplaceValue)
{
  map_type map;
  ASSERT_EQ(0, map.size());

  const std::string a{"A"};
  const std::string b{"B"};
  const std::string c{"C"};

  map.emplace(10, a);
  ASSERT_EQ(1, map.size());

  map.emplace(20, b);
  ASSERT_EQ(2, map.size());

  const auto& [key, value] = map.emplace(30, c);
  ASSERT_EQ(3, map.size());

  ASSERT_EQ(30, key);
  ASSERT_EQ("C", value);
}

TEST(VectorMap, EmplaceOrReplaceVariadic)
{
  map_type map;
  ASSERT_EQ(0, map.size());

  map.emplace_or_replace(10, "A");
  ASSERT_EQ(1, map.size());

  ASSERT_NO_THROW(map.emplace_or_replace(10, "B"));
  ASSERT_EQ(1, map.size());
  ASSERT_EQ("B", map.at(10));

  map.emplace_or_replace(20, "C");
  ASSERT_EQ(2, map.size());

  const auto& [key, value] = map.emplace(30, "D");
  ASSERT_EQ(3, map.size());

  ASSERT_EQ(30, key);
  ASSERT_EQ("D", value);
}

TEST(VectorMap, EmplaceOrReplaceValue)
{
  map_type map;
  ASSERT_EQ(0, map.size());

  const std::string a{"A"};
  const std::string b{"B"};
  const std::string c{"C"};

  map.emplace_or_replace(10, a);
  ASSERT_EQ(1, map.size());

  ASSERT_NO_THROW(map.emplace_or_replace(10, b));
  ASSERT_EQ(1, map.size());
  ASSERT_EQ("B", map.at(10));

  const auto& [key, value] = map.emplace_or_replace(20, c);
  ASSERT_EQ(2, map.size());

  ASSERT_EQ(20, key);
  ASSERT_EQ("C", value);
}

TEST(VectorMap, Erase)
{
  map_type map;

  ASSERT_NO_THROW(map.erase(123));
  ASSERT_EQ(0, map.size());

  map.emplace(42, "foo");
  map.emplace(123, "bar");
  ASSERT_EQ(2, map.size());

  map.erase(42);
  ASSERT_EQ(1, map.size());

  map.erase(42);
  ASSERT_EQ(1, map.size());

  map.erase(123);
  ASSERT_EQ(0, map.size());
  ASSERT_TRUE(map.empty());
}

TEST(VectorMap, MoveForward)
{
  map_type map;

  map.emplace(10, "A");
  map.emplace(20, "B");
  map.emplace(30, "C");

  ASSERT_EQ(0, map.index_of(10));
  ASSERT_EQ(1, map.index_of(20));
  ASSERT_EQ(2, map.index_of(30));

  map.move_forward(10);
  ASSERT_EQ(1, map.index_of(10));
  ASSERT_EQ(0, map.index_of(20));
  ASSERT_EQ(2, map.index_of(30));

  map.move_forward(10);
  ASSERT_EQ(2, map.index_of(10));
  ASSERT_EQ(0, map.index_of(20));
  ASSERT_EQ(1, map.index_of(30));
}

TEST(VectorMap, MoveBackward)
{
  map_type map;

  map.emplace(10, "A");
  map.emplace(20, "B");
  map.emplace(30, "C");

  ASSERT_EQ(0, map.index_of(10));
  ASSERT_EQ(1, map.index_of(20));
  ASSERT_EQ(2, map.index_of(30));

  map.move_backward(30);
  ASSERT_EQ(0, map.index_of(10));
  ASSERT_EQ(2, map.index_of(20));
  ASSERT_EQ(1, map.index_of(30));

  map.move_backward(30);
  ASSERT_EQ(1, map.index_of(10));
  ASSERT_EQ(2, map.index_of(20));
  ASSERT_EQ(0, map.index_of(30));
}

TEST(VectorMap, Find)
{
  rune::vector_map<std::string, std::string> map;
  map.emplace("foo", "bar");

  custom_string foo{"foo"};
  custom_string bar{"bar"};

  ASSERT_NE(map.end(), map.find("foo"));
  ASSERT_NE(map.end(), map.find(foo));

  ASSERT_EQ(map.end(), map.find("bar"));
  ASSERT_EQ(map.end(), map.find(bar));
}

TEST(VectorMap, AtIndex)
{
  map_type map;
  ASSERT_THROW(map.at_index(0), std::out_of_range);

  map.emplace(42, "foo");
  const auto& [key, value] = map.at_index(0);
  ASSERT_EQ(42, key);
  ASSERT_EQ("foo", value);
}

TEST(VectorMap, At)
{
  map_type map;
  ASSERT_THROW(map.at(42), rune::rune_error);

  map.emplace(42, "foo");
  ASSERT_EQ("foo", map.at(42));
}

TEST(VectorMap, Subscript)
{
  map_type map;
  ASSERT_THROW(map[42], rune::rune_error);

  map.emplace(42, "foo");
  ASSERT_EQ("foo", map[42]);
}

TEST(VectorMap, IndexOf)
{
  map_type map;
  ASSERT_FALSE(map.index_of(123));

  map.emplace(42, "foo");
  map.emplace(123, "bar");

  ASSERT_EQ(0, map.index_of(42));
  ASSERT_EQ(1, map.index_of(123));
}

TEST(VectorMap, Empty)
{
  map_type map;
  ASSERT_TRUE(map.empty());

  map.emplace(123, "foo");
  ASSERT_FALSE(map.empty());

  map.clear();
  ASSERT_TRUE(map.empty());
}

TEST(VectorMap, Iteration)
{
  map_type map;

  map.emplace(1, "A");
  map.emplace(2, "B");
  map.emplace(3, "C");

  auto count = 0;
  for (const auto& [key, value] : map)
  {
    ++count;
  }

  ASSERT_EQ(3, count);
}
