#include "io/tmx/tmx_color.hpp"

#include <gtest/gtest.h>

TEST(TmxColor, Defaults)
{
  const rune::tmx_color color;
  ASSERT_EQ(0, color.red);
  ASSERT_EQ(0, color.green);
  ASSERT_EQ(0, color.blue);
  ASSERT_EQ(0xFF, color.alpha);
  ASSERT_EQ(rune::tmx::black, color);
}

TEST(TmxColor, RGB)
{
  const auto color = rune::tmx::make_color("#A1B2C3");
  ASSERT_EQ(0xA1, color.red);
  ASSERT_EQ(0xB2, color.green);
  ASSERT_EQ(0xC3, color.blue);
  ASSERT_EQ(0xFF, color.alpha);
}

TEST(TmxColor, ARGB)
{
  const auto color = rune::tmx::make_color("#A1B2C3D4");
  ASSERT_EQ(0xA1, color.alpha);
  ASSERT_EQ(0xB2, color.red);
  ASSERT_EQ(0xC3, color.green);
  ASSERT_EQ(0xD4, color.blue);
}

TEST(TmxColor, Parse)
{
  const nlohmann::json json = "#C142BE8A";
  const auto color = json.get<rune::tmx_color>();

  ASSERT_EQ(0xC1, color.alpha);
  ASSERT_EQ(0x42, color.red);
  ASSERT_EQ(0xBE, color.green);
  ASSERT_EQ(0x8A, color.blue);
}
