#include "tmx/tmx_property.hpp"

#include <gtest/gtest.h>

TEST(TmxProperty, Defaults)
{
  const rune::tmx_property property;
  ASSERT_TRUE(property.name.empty());

  ASSERT_TRUE(rune::tmx::is_string(property));
  ASSERT_FALSE(rune::tmx::is_integer(property));
  ASSERT_FALSE(rune::tmx::is_float(property));
  ASSERT_FALSE(rune::tmx::is_boolean(property));
  ASSERT_FALSE(rune::tmx::is_color(property));
  ASSERT_FALSE(rune::tmx::is_file(property));
  ASSERT_FALSE(rune::tmx::is_object(property));

  ASSERT_EQ(rune::tmx_property_type::string, property.type);
  ASSERT_TRUE(rune::tmx::try_as_string(property));
}

TEST(TmxProperty, Parse)
{
  const nlohmann::json json = {{"name", "Frodo"}, {"type", "int"}, {"value", 123}};
  const auto property = json.get<rune::tmx_property>();

  ASSERT_EQ("Frodo", property.name);
  ASSERT_EQ(rune::tmx_property_type::integer, property.type);

  ASSERT_TRUE(rune::tmx::is_integer(property));
  ASSERT_FALSE(rune::tmx::is_string(property));
  ASSERT_FALSE(rune::tmx::is_float(property));
  ASSERT_FALSE(rune::tmx::is_boolean(property));
  ASSERT_FALSE(rune::tmx::is_color(property));
  ASSERT_FALSE(rune::tmx::is_file(property));
  ASSERT_FALSE(rune::tmx::is_object(property));

  ASSERT_EQ(123, rune::tmx::as_integer(property));
  ASSERT_TRUE(rune::tmx::try_as_integer(property));
}
