#include "tmx/tmx_property.hpp"

#include <gtest/gtest.h>

#include <vector>  // vector

#include "io/json_utils.hpp"
#include "tmx/tmx_parsers.hpp"

TEST(TmxProperty, TmxPropertyTypeEnum)
{
  const auto json = R"(
    [ "string", "int", "float", "bool", "color", "file", "object" ]
  )"_json;

  std::vector<rune::tmx_property_type> values;
  rune::fill(json, values);

  ASSERT_EQ(7, values.size());
  ASSERT_EQ(rune::tmx_property_type::string, values.at(0));
  ASSERT_EQ(rune::tmx_property_type::integer, values.at(1));
  ASSERT_EQ(rune::tmx_property_type::floating, values.at(2));
  ASSERT_EQ(rune::tmx_property_type::boolean, values.at(3));
  ASSERT_EQ(rune::tmx_property_type::color, values.at(4));
  ASSERT_EQ(rune::tmx_property_type::file, values.at(5));
  ASSERT_EQ(rune::tmx_property_type::object, values.at(6));
}

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
  const auto json = R"({ "name": "Frodo", "type": "int", "value": 123 })"_json;
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

inline const auto properties_json_array = R"(
    [
      {
        "name": "A",
        "type": "int",
        "value": 123
      },
      {
        "name": "B",
        "type": "float",
        "value": 42.3
      },
      {
        "name": "C",
        "type": "string",
        "value": "hello world!"
      }
    ]
  )"_json;

TEST(TmxProperty, Contains)
{
  std::vector<rune::tmx_property> properties;
  rune::fill(properties_json_array, properties);

  ASSERT_EQ(3, properties.size());
  ASSERT_EQ(3, properties.capacity());

  ASSERT_TRUE(rune::tmx::contains(properties, "A"));
  ASSERT_TRUE(rune::tmx::contains(properties, "B"));
  ASSERT_TRUE(rune::tmx::contains(properties, "C"));

  ASSERT_FALSE(rune::tmx::contains(properties, ""));
  ASSERT_FALSE(rune::tmx::contains(properties, "a"));
  ASSERT_FALSE(rune::tmx::contains(properties, "int"));
  ASSERT_FALSE(rune::tmx::contains(properties, "hello world!"));
  ASSERT_FALSE(rune::tmx::contains(properties, "foobar"));
}

TEST(TmxProperty, Find)
{
  std::vector<rune::tmx_property> properties;
  rune::fill(properties_json_array, properties);

  const auto& a = rune::tmx::find(properties, "A");
  ASSERT_TRUE(rune::tmx::is_integer(a));
  ASSERT_EQ(123, rune::tmx::as_integer(a));

  const auto& b = rune::tmx::find(properties, "B");
  ASSERT_TRUE(rune::tmx::is_float(b));
  ASSERT_EQ(42.3f, rune::tmx::as_float(b));

  ASSERT_THROW(rune::tmx::find(properties, "foo"), rune::rune_error);
}