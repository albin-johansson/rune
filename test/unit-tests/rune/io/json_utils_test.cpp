#include "io/json_utils.hpp"

#include <gtest/gtest.h>

#include <nenya.hpp>

TEST(JsonUtils, ReadJson)
{
  const auto json = rune::read_json("resources/test.json");
  ASSERT_TRUE(json.contains("string"));
  ASSERT_TRUE(json.contains("integer"));
  ASSERT_TRUE(json.contains("float"));
  ASSERT_TRUE(json.contains("boolean"));
  ASSERT_TRUE(json.contains("object"));
  ASSERT_TRUE(json.contains("array"));
}

TEST(JsonUtils, GetToVector)
{
  const auto json = R"([ 1, 2, 3 ])"_json;

  std::vector<int> vector;
  ASSERT_NO_THROW(rune::io::get_to(json, vector));

  ASSERT_EQ(3, vector.size());
  ASSERT_EQ(3, vector.capacity());

  ASSERT_EQ(1, vector.at(0));
  ASSERT_EQ(2, vector.at(1));
  ASSERT_EQ(3, vector.at(2));
}

TEST(JsonUtils, GetElementToVector)
{
  const rune::json_type json = {{"foo", "bar"}, {"array", {12, 24, 36}}};

  std::vector<int> vector;
  ASSERT_THROW(rune::io::get_to(json, "abc", vector), rune::rune_error);
  ASSERT_NO_THROW(rune::io::get_to(json, "array", vector));

  ASSERT_EQ(3, vector.size());
  ASSERT_EQ(3, vector.capacity());

  ASSERT_EQ(12, vector.at(0));
  ASSERT_EQ(24, vector.at(1));
  ASSERT_EQ(36, vector.at(2));
}

TEST(JsonUtils, TryGetTo)
{
  const rune::json_type json = {{"string", "foo"},
                                {"int", 123},
                                {"float", 5.2},
                                {"bool", true}};

  std::string str;
  ASSERT_NO_THROW(rune::io::try_get_to(json, "foobar", str));
  ASSERT_TRUE(str.empty());

  ASSERT_NO_THROW(rune::io::try_get_to(json, "string", str));
  ASSERT_EQ("foo", str);

  int i{};
  ASSERT_ANY_THROW(rune::io::try_get_to(json, "string", i));
  ASSERT_EQ(0, i);
}

TEST(JsonUtils, TryGetToOptional)
{
  const rune::json_type json = {{"foo", 123}};

  std::optional<int> foo;
  ASSERT_NO_THROW(rune::io::try_get_to(json, "bar", foo));
  ASSERT_FALSE(foo.has_value());

  rune::io::try_get_to(json, "foo", foo);
  ASSERT_EQ(123, foo);
}

TEST(JsonUtils, TryGetToVector)
{
  const rune::json_type json = {{"foo", {"a", "b", "c"}}};

  std::vector<std::string> vector;
  ASSERT_NO_THROW(rune::io::try_get_to(json, "bar", vector));
  ASSERT_TRUE(vector.empty());

  rune::io::try_get_to(json, "foo", vector);

  ASSERT_EQ(3, vector.size());
  ASSERT_EQ(3, vector.capacity());

  ASSERT_EQ("a", vector.at(0));
  ASSERT_EQ("b", vector.at(1));
  ASSERT_EQ("c", vector.at(2));
}

TEST(JsonUtils, EmplaceTo)
{
  using foo_type = nenya::strong_type<float, struct foo_tag>;
  const rune::json_type json = {{"foo", 12.3}};

  foo_type foo;
  ASSERT_THROW(rune::io::emplace_to(json, "bar", foo), rune::rune_error);

  rune::io::emplace_to(json, "foo", foo);
  ASSERT_FLOAT_EQ(12.3f, foo);
}

TEST(JsonUtils, EmplaceToOptional)
{
  const rune::json_type json = {{"abc", 42}};

  std::optional<int> abc;
  ASSERT_THROW(rune::io::emplace_to(json, "foo", abc), rune::rune_error);
  ASSERT_FALSE(abc.has_value());

  rune::io::emplace_to(json, "abc", abc);
  ASSERT_EQ(42, abc);
}

TEST(JsonUtils, TryEmplaceTo)
{
  const rune::json_type json = {{"foo", 12.3}, {"bar", 27}};
  std::variant<int, float, bool> var;

  ASSERT_NO_THROW(rune::io::try_emplace_to<float>(json, "abc", var));
  ASSERT_NO_THROW(rune::io::try_emplace_to<int>(json, "abc", var));

  rune::io::try_emplace_to<float>(json, "foo", var);
  ASSERT_FLOAT_EQ(12.3f, std::get<float>(var));

  rune::io::try_emplace_to<int>(json, "bar", var);
  ASSERT_EQ(27, std::get<int>(var));
}
