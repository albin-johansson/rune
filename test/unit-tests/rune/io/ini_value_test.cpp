#include "io/ini_value.hpp"

#include <gtest/gtest.h>

TEST(IniValue, Defaults)
{
  const rune::ini_value value;
  ASSERT_TRUE(value.is_string());
}

TEST(IniValue, StringValue)
{
  const rune::ini_value value = "foo";
  ASSERT_TRUE(value.is_string());

  std::string str;
  ASSERT_NO_THROW(value.get_to(str));
  ASSERT_EQ("foo", str);
}

TEST(IniValue, SignedNegativeIntegerValue)
{
  const rune::ini_value value = -123;
  ASSERT_TRUE(value.is_int());

  int i{};
  ASSERT_NO_THROW(value.get_to(i));
  ASSERT_EQ(-123, i);
}

TEST(IniValue, SignedPositiveIntegerValue)
{
  const rune::ini_value value = 123'456;
  ASSERT_TRUE(value.is_int());

  int i{};
  ASSERT_NO_THROW(value.get_to(i));
  ASSERT_EQ(123'456, i);
}

TEST(IniValue, UnsignedIntegerValue)
{
  const rune::ini_value value = 1'500'000u;
  ASSERT_TRUE(value.is_uint());

  rune::uint u{};
  ASSERT_NO_THROW(value.get_to(u));
  ASSERT_EQ(1'500'000u, u);
}

TEST(IniValue, BooleanValue)
{
  const rune::ini_value trueValue = true;
  const rune::ini_value falseValue = false;

  ASSERT_TRUE(trueValue.is_bool());
  ASSERT_TRUE(falseValue.is_bool());

  bool t{};
  bool f{};
  ASSERT_NO_THROW(trueValue.get_to(t));
  ASSERT_NO_THROW(falseValue.get_to(f));

  ASSERT_TRUE(t);
  ASSERT_FALSE(f);
}

TEST(IniValue, GetToBool)
{
  const rune::ini_value value{true};

  bool b{};
  value.get_to(b);

  ASSERT_TRUE(b);
}

TEST(IniValue, GetToInt8)
{
  const rune::ini_value value = 105;

  rune::int8 i{};
  value.get_to(i);

  ASSERT_EQ(105, i);
}

TEST(IniValue, GetToInt16)
{
  const rune::ini_value value = 1'234;

  rune::int16 i{};
  value.get_to(i);

  ASSERT_EQ(1'234, i);
}

TEST(IniValue, GetToInt32)
{
  const rune::ini_value value = -5'721;

  rune::int32 i{};
  value.get_to(i);

  ASSERT_EQ(-5'721, i);
}

TEST(IniValue, GetToInt64)
{
  const rune::ini_value value = 284'482;

  rune::int64 i{};
  value.get_to(i);

  ASSERT_EQ(284'482, i);
}

TEST(IniValue, GetToUint8)
{
  const rune::ini_value value = 12u;

  rune::uint8 u{};
  value.get_to(u);

  ASSERT_EQ(12u, u);
}

TEST(IniValue, GetToUint16)
{
  const rune::ini_value value = 468u;

  rune::uint16 u{};
  value.get_to(u);

  ASSERT_EQ(468u, u);
}

TEST(IniValue, GetToUint32)
{
  const rune::ini_value value = 1'395u;

  rune::uint32 u{};
  value.get_to(u);

  ASSERT_EQ(1'395u, u);
}

TEST(IniValue, GetToUint64)
{
  const rune::ini_value value = 92'564u;

  rune::uint64 u{};
  value.get_to(u);

  ASSERT_EQ(92'564u, u);
}

TEST(IniValue, GetToFloat)
{
  const rune::ini_value value = 54.3f;

  float f{};
  value.get_to(f);

  ASSERT_EQ(54.3f, f);
}

TEST(IniValue, GetToDouble)
{
  const rune::ini_value value = 164.8;

  double d{};
  value.get_to(d);

  ASSERT_EQ(164.8, d);
}

TEST(IniValue, GetToSignedIntStrongType)
{
  using strong_int = nenya::strong_type<int, struct strong_int_tag>;

  const rune::ini_value value = 123;

  strong_int i;
  value.get_to(i);

  ASSERT_EQ(strong_int{123}, i);
}

TEST(IniValue, GetToUnsignedIntStrongType)
{
  using strong_uint = nenya::strong_type<unsigned, struct strong_uint_tag>;

  const rune::ini_value value = 8'234u;

  strong_uint u;
  value.get_to(u);

  ASSERT_EQ(strong_uint{8'234}, u);
}

TEST(IniValue, GetToFloatStrongType)
{
  using strong_float = nenya::strong_type<float, struct strong_float_tag>;

  const rune::ini_value value = 93.5;

  strong_float f;
  value.get_to(f);

  ASSERT_EQ(strong_float{93.5f}, f);
}

TEST(IniValue, GetToBoolStrongType)
{
  using strong_bool = nenya::strong_type<bool, struct strong_bool_tag>;

  const rune::ini_value value = true;

  strong_bool b;
  value.get_to(b);

  ASSERT_EQ(strong_bool{true}, b);
}

TEST(IniValue, GetToStringStrongType)
{
  using strong_string = nenya::strong_type<std::string, struct strong_string_tag>;

  const rune::ini_value value = "foobar";

  strong_string s;
  value.get_to(s);

  ASSERT_EQ(strong_string{"foobar"}, s);
}

TEST(IniValue, TryGetString)
{
  rune::ini_value value = 123;
  ASSERT_FALSE(value.try_get_string());

  value = "foo";
  ASSERT_TRUE(value.try_get_string());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_FALSE(value.try_get_bool());

  ASSERT_EQ("foo", *value.try_get_string());
}

TEST(IniValue, TryGetInt)
{
  rune::ini_value value = true;
  ASSERT_FALSE(value.try_get_int());

  value = 123;
  ASSERT_TRUE(value.try_get_int());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_FALSE(value.try_get_string());
  ASSERT_FALSE(value.try_get_bool());

  ASSERT_EQ(123, *value.try_get_int());
}

TEST(IniValue, TryGetUint)
{
  rune::ini_value value = "abc";
  ASSERT_FALSE(value.try_get_uint());

  value = 1'337u;
  ASSERT_TRUE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_FALSE(value.try_get_string());
  ASSERT_FALSE(value.try_get_bool());

  ASSERT_EQ(1'337u, *value.try_get_uint());
}

TEST(IniValue, TryGetFloat)
{
  rune::ini_value value = 42;
  ASSERT_FALSE(value.try_get_float());

  value = 12.3;
  ASSERT_TRUE(value.try_get_float());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_FALSE(value.try_get_string());
  ASSERT_FALSE(value.try_get_bool());

  ASSERT_EQ(12.3, *value.try_get_float());
}
