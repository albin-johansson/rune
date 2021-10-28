#include "rune-core/formatted_string.hpp"

#include <gtest/gtest.h>

TEST(FormattedString, NoArgs)
{
  const rune::formatted_string<64> str{"foo"};
  ASSERT_EQ(3u, str.size());
  ASSERT_STREQ("foo", str.data());
  ASSERT_EQ("foo", str.view());
}

TEST(FormattedString, WithArgs)
{
  const rune::formatted_string<64> foo{"{}", "mooo"};
  const rune::formatted_string<64> bar{"{} {} {}", 1, 4.2, true};

  ASSERT_EQ(4u, foo.size());
  ASSERT_STREQ("mooo", foo.data());
  ASSERT_EQ("mooo", foo.view());

  ASSERT_EQ(10u, bar.size());
  ASSERT_STREQ("1 4.2 true", bar.data());
  ASSERT_EQ("1 4.2 true", bar.view());
}

TEST(FormattedString, Overflow)
{
  const rune::formatted_string<6> str{"{}", "1234567890"};
  static_assert(str.capacity() == 6u);

  ASSERT_EQ(str.capacity(), str.size());
  ASSERT_STREQ("123456", str.data());
  ASSERT_EQ("123456", str.view());
}