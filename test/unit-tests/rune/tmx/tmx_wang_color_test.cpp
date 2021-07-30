#include "tmx/tmx_wang_color.hpp"

#include <gtest/gtest.h>

#include "tmx/parse_tmx.hpp"

using namespace rune::tmx_literals;

TEST(TmxWangColor, Defaults)
{
  const rune::tmx_wang_color color;
  ASSERT_EQ(0_local, color.tile);
  ASSERT_EQ(rune::tmx::black, color.color);
  ASSERT_EQ(0, color.probability);
  ASSERT_TRUE(color.name.empty());
}

TEST(TmxWangColor, Parse)
{
  const auto json = R"(
    {
      "color": "#D31313",
      "tile": 18,
      "name": "Anduril",
      "probability": 0.8,
      "properties": []
    }
  )"_json;

  const auto color = json.get<rune::tmx_wang_color>();
  ASSERT_EQ("Anduril", color.name);
  ASSERT_EQ(18_local, color.tile);
  ASSERT_FLOAT_EQ(0.8f, color.probability);
  ASSERT_TRUE(color.properties.empty());

  const rune::tmx_color expected{0xD3, 0x13, 0x13};
  ASSERT_EQ(expected, color.color);
}
