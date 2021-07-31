#include "io/csv.hpp"

#include <gtest/gtest.h>

TEST(ParseCSV, EmptyString)
{
  const auto tokens = rune::parse_csv("");
  ASSERT_TRUE(tokens.empty());
}

TEST(ParseCSV, ValidCSV)
{
  const auto tokens = rune::parse_csv("1:2,5,foo,bar");
  ASSERT_EQ(4, tokens.size());
  ASSERT_EQ("1:2", tokens.at(0));
  ASSERT_EQ("5", tokens.at(1));
  ASSERT_EQ("foo", tokens.at(2));
  ASSERT_EQ("bar", tokens.at(3));
}
