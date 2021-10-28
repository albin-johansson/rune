#include "rune-core/compiler.hpp"

#include <gtest/gtest.h>

TEST(Compiler, OnMSVC)
{
#ifdef _MSC_VER
  ASSERT_TRUE(rune::on_msvc());
#else
  ASSERT_FALSE(rune::on_msvc());
#endif  // _MSC_VER
}

TEST(Compiler, OnGCC)
{
#ifdef __GNUC__
  ASSERT_TRUE(rune::on_gcc());
#else
  ASSERT_FALSE(rune::on_gcc());
#endif  // __GNUC__
}

TEST(Compiler, OnClang)
{
#ifdef __clang__
  ASSERT_TRUE(rune::on_clang());
#else
  ASSERT_FALSE(rune::on_clang());
#endif  // __clang__
}
