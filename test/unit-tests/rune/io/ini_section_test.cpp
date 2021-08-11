#include "io/ini_section.hpp"

#include <gtest/gtest.h>

#include <algorithm>  // for_each
#include <iostream>   // cout

TEST(IniSection, Defaults)
{
  const rune::ini_section section;
  ASSERT_EQ(0, section.size());
  ASSERT_TRUE(section.empty());
}

TEST(IniSection, Dump)
{
  rune::ini_section section;

  section["foo"] = "bar";
  section["doo"] = 42;
  section["boo"] = 12.3;
  section["zoo"] = true;
  section["noo"] = 27u;

  std::cout << "Section with standard format: \n";
  section.dump(std::cout, rune::ini_section::format_type{});

  const rune::ini_section::format_type format{.section_start = '{',
                                              .section_end = '}',
                                              .assign = ':',
                                              .comment = '~'};

  std::cout << "Section with custom format: \n";
  section.dump(std::cout, format);
}

TEST(IniSection, Erase)
{
  rune::ini_section section;
  ASSERT_FALSE(section.erase("foo"));

  section["foo"] = "abc";
  section["bar"] = 42;
  ASSERT_EQ(2, section.size());
  ASSERT_TRUE(section.contains("foo"));
  ASSERT_TRUE(section.contains("bar"));

  ASSERT_TRUE(section.erase("foo"));
  ASSERT_FALSE(section.erase("foo"));
  ASSERT_EQ(1, section.size());
  ASSERT_FALSE(section.contains("foo"));

  ASSERT_FALSE(section.erase("BAR"));
  ASSERT_TRUE(section.erase("bar"));
  ASSERT_TRUE(section.empty());

  const std::string str = "bar";
  ASSERT_FALSE(section.erase(str));
}

TEST(IniSection, GetOrEmplace)
{
  rune::ini_section section;

  auto& a = section.get_or_emplace("foo");
  ASSERT_EQ(1, section.size());
  ASSERT_TRUE(section.contains("foo"));

  auto& b = section.get_or_emplace("foo");
  ASSERT_EQ(1, section.size());
  ASSERT_EQ(&a, &b);

  section.get_or_emplace("bar") = 42u;
  ASSERT_EQ(2, section.size());
  ASSERT_EQ(42u, section.at("bar"));
}

TEST(IniSection, SubscriptOperator)
{
  rune::ini_section section;

  auto& a = section["foo"];
  ASSERT_EQ(1, section.size());
  ASSERT_TRUE(section.contains("foo"));

  auto& b = section["foo"];
  ASSERT_EQ(1, section.size());
  ASSERT_EQ(&a, &b);

  section["bar"] = "hello";
  ASSERT_EQ(2, section.size());
  ASSERT_EQ("hello", section.at("bar"));
}

TEST(IniSection, At)
{
  rune::ini_section section;
  ASSERT_THROW(section.at("foo"), rune::rune_error);

  section["foo"] = "bar";
  ASSERT_EQ("bar", section.at("foo"));
}

TEST(IniSection, Contains)
{
  rune::ini_section section;
  ASSERT_FALSE(section.contains("foo"));

  section["foo"] = 123;
  ASSERT_TRUE(section.contains("foo"));

  section.erase("foo");
  ASSERT_FALSE(section.contains("foo"));
}

TEST(IniSection, Iteration)
{
  rune::ini_section section;

  section["0"] = 0;
  section["1"] = 1;
  section["2"] = 2;

  int index = 0;
  for (const auto& [name, value] : section)
  {
    ASSERT_EQ(index, section.at(std::to_string(index)));
    ++index;
  }

  std::ranges::for_each(section, [](std::pair<const std::string, rune::ini_value>& elem) {
    auto& value = elem.second;
    value = value.as<int>() + 1;
  });

  index = 0;
  for (const auto& [name, value] : section)
  {
    ASSERT_EQ(index + 1, section.at(std::to_string(index)));
    ++index;
  }
}