#include "tmx/tmx_text.hpp"

#include <gtest/gtest.h>

TEST(TmxText, Defaults)
{
  const rune::tmx_text text;

  ASSERT_TRUE(text.text.empty());
  ASSERT_EQ("sans-serif", text.family);

  ASSERT_EQ(16, text.pixel_size);
  ASSERT_EQ(rune::tmx::black, text.color);

  ASSERT_EQ(rune::tmx_halign::left, text.horizontal_alignment);
  ASSERT_EQ(rune::tmx_valign::top, text.vertical_alignment);

  ASSERT_TRUE(text.kerning);
  ASSERT_FALSE(text.bold);
  ASSERT_FALSE(text.italic);
  ASSERT_FALSE(text.strikeout);
  ASSERT_FALSE(text.underline);
  ASSERT_FALSE(text.wrap);
}

TEST(TmxTest, Parse)
{
  const auto json = R"(
    {
      "text": "foobar",
      "fontfamily": "Ironfoot",
      "color": "#1234ABCD",
      "halign": "center",
      "valign": "bottom",
      "pixelsize": 24,
      "bold": true,
      "italic": true,
      "kerning": false,
      "strikeout": false,
      "underline": false,
      "wrap": true
    }
  )"_json;

  const auto text = json.get<rune::tmx_text>();
  ASSERT_EQ("foobar", text.text);
  ASSERT_EQ("Ironfoot", text.family);
  ASSERT_EQ(0x12, text.color.alpha);
  ASSERT_EQ(0x34, text.color.red);
  ASSERT_EQ(0xAB, text.color.green);
  ASSERT_EQ(0xCD, text.color.blue);
  ASSERT_EQ(rune::tmx_halign::center, text.horizontal_alignment);
  ASSERT_EQ(rune::tmx_valign::bottom, text.vertical_alignment);
  ASSERT_TRUE(text.bold);
  ASSERT_TRUE(text.italic);
  ASSERT_FALSE(text.kerning);
  ASSERT_FALSE(text.strikeout);
  ASSERT_FALSE(text.underline);
  ASSERT_TRUE(text.wrap);
}
