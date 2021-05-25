#include "io/ini.hpp"

#include <gtest/gtest.h>

#include <iostream>  // cout

TEST(Ini, Defaults)
{
  const rune::ini_file file;
  ASSERT_EQ(0, file.size());
  ASSERT_TRUE(file.empty());
  ASSERT_TRUE(file);
}

TEST(Ini, GetOrEmplace)
{
  rune::ini_file file;
  ASSERT_EQ(0, file.size());
  ASSERT_TRUE(file.empty());

  {
    auto& foo = file.get_or_emplace("foo");
    ASSERT_TRUE(file.contains("foo"));
    ASSERT_EQ(1, file.size());

    foo["abc"] = "123";
  }

  {
    auto& foo = file.get_or_emplace("foo");
    ASSERT_EQ(1, foo.size());
    ASSERT_TRUE(foo.contains("abc"));

    ASSERT_TRUE(file.contains("foo"));
    ASSERT_EQ(1, file.size());
  }

  file.get_or_emplace("bar");
  ASSERT_TRUE(file.contains("bar"));
  ASSERT_EQ(2, file.size());
}

TEST(Ini, EmplaceOrReplace)
{
  rune::ini_file file;

  {
    auto& foo = file.emplace_or_replace("foo");
    foo["abc"] = "123";
    ASSERT_TRUE(foo.contains("abc"));
  }

  {
    // Ensure that the section was replaced
    auto& foo = file.emplace_or_replace("foo");
    ASSERT_FALSE(foo.contains("abc"));
  }

  ASSERT_TRUE(file);
  ASSERT_EQ(1, file.size());
  ASSERT_TRUE(file.contains("foo"));
}

TEST(Ini, Erase)
{
  rune::ini_file file;
  ASSERT_NO_THROW(file.erase("foo"));

  file.emplace_or_replace("foo");
  ASSERT_EQ(1, file.size());
  ASSERT_FALSE(file.empty());
  ASSERT_TRUE(file.contains("foo"));

  file.erase("foo");
  ASSERT_EQ(0, file.size());
  ASSERT_TRUE(file.empty());
  ASSERT_FALSE(file.contains("foo"));
}

TEST(Ini, At)
{
  rune::ini_file file;
  ASSERT_ANY_THROW(file.at("foo"));

  file["foo"];
  file["bar"];

  ASSERT_NO_THROW(file.at("foo"));
  ASSERT_NO_THROW(file.at("bar"));
}

TEST(Ini, Subscript)
{
  rune::ini_file file;

  file["foo"];
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_EQ(1, file.size());

  file["foo"]["bar"];
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_EQ(1, file.size());
}

TEST(Ini, FromFile)
{
  auto file = rune::read_ini("resources/test.ini");
  file.write(std::cout);

  ASSERT_EQ(2, file.size());
  ASSERT_FALSE(file.empty());

  {
    const auto& foo = file.at("foo");
    ASSERT_EQ(4, foo.size());

    ASSERT_TRUE(foo.contains("abc"));
    ASSERT_EQ(rune::ini_value{"world"}, foo.at("abc"));

    ASSERT_TRUE(foo.contains("bar"));
    ASSERT_EQ(rune::ini_value{"hello"}, foo.at("bar"));

    ASSERT_TRUE(foo.contains("health"));
    ASSERT_EQ(rune::ini_value{87u}, foo.at("health"));

    ASSERT_TRUE(foo.contains("offset"));
    ASSERT_EQ(rune::ini_value{-42}, foo.at("offset"));
  }

  {
    const auto& bar = file.at("bar");
    ASSERT_EQ(3, bar.size());

    ASSERT_TRUE(bar.contains("isCool"));
    ASSERT_EQ(rune::ini_value{true}, bar.at("isCool"));

    ASSERT_TRUE(bar.contains("isFancy"));
    ASSERT_EQ(rune::ini_value{false}, bar.at("isFancy"));

    ASSERT_TRUE(bar.contains("123"));
    ASSERT_EQ(rune::ini_value{321}, bar.at("123"));
  }
}

TEST(Ini, Usage)
{
  rune::ini_file file;

  file["foo"]["abc"] = "hello";
  file["foo"]["def"] = "world";
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_FALSE(file.contains("bar"));

  {
    const auto& foo = file.at("foo");
    ASSERT_EQ(2, foo.size());
    ASSERT_EQ(rune::ini_value{"hello"}, foo.at("abc"));
    ASSERT_EQ(rune::ini_value{"world"}, foo.at("def"));
  }

  file["bar"]["ghi"] = "lorem";
  ASSERT_EQ(2, file.size());
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_TRUE(file.contains("bar"));

  file.erase("foo");
  ASSERT_EQ(1, file.size());
  ASSERT_FALSE(file.contains("foo"));
  ASSERT_TRUE(file.contains("bar"));
}
