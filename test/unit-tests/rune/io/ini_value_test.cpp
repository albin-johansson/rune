#include "io/ini_value.hpp"

#include <gtest/gtest.h>

#include <iostream>  // cout

TEST(IniValue, Defaults)
{
  const rune::ini_value value;
  ASSERT_TRUE(value.is_string());
}

TEST(IniValue, DirectInitialization)
{
  const rune::ini_value str{"foo"};
  ASSERT_TRUE(str.is_string());
  ASSERT_EQ("foo", str);
}

TEST(IniValue, StringValue)
{
  const rune::ini_value value = "foo";
  ASSERT_TRUE(value.is_string());
  ASSERT_EQ("foo", value);
}

TEST(IniValue, SignedNegativeIntegerValue)
{
  const rune::ini_value value = -123;
  ASSERT_TRUE(value.is_int());
  ASSERT_FALSE(value.is_uint());
  ASSERT_EQ(-123, value);
}

TEST(IniValue, SignedPositiveIntegerValue)
{
  const rune::ini_value value = 123'456;
  ASSERT_TRUE(value.is_int());
  ASSERT_FALSE(value.is_uint());
  ASSERT_EQ(123'456, value);
}

TEST(IniValue, UnsignedIntegerValue)
{
  const rune::ini_value value = 1'563'329u;
  ASSERT_TRUE(value.is_uint());
  ASSERT_FALSE(value.is_int());
  ASSERT_EQ(1'563'329u, value);
}

TEST(IniValue, BooleanValue)
{
  const rune::ini_value a{true};
  const rune::ini_value b{false};

  ASSERT_TRUE(a.is_bool());
  ASSERT_TRUE(b.is_bool());

  ASSERT_EQ(true, a);
  ASSERT_EQ(false, b);
}

TEST(IniValue, GetToBool)
{
  const rune::ini_value value{true};

  int i{};
  ASSERT_THROW(value.get_to(i), std::bad_variant_access);

  bool b{};
  value.get_to(b);

  ASSERT_TRUE(b);
}

TEST(IniValue, GetToInt8)
{
  const rune::ini_value value = 105;

  bool b{};
  ASSERT_THROW(value.get_to(b), std::bad_variant_access);

  rune::int8 i{};
  value.get_to(i);

  ASSERT_EQ(105, i);
}

TEST(IniValue, GetToInt16)
{
  const rune::ini_value value = 1'234;

  std::string s;
  ASSERT_THROW(value.get_to(s), std::bad_variant_access);

  rune::int16 i{};
  value.get_to(i);

  ASSERT_EQ(1'234, i);
}

TEST(IniValue, GetToInt32)
{
  const rune::ini_value value = -5'721;

  rune::uint8 u{};
  ASSERT_THROW(value.get_to(u), std::bad_variant_access);

  rune::int32 i{};
  value.get_to(i);

  ASSERT_EQ(-5'721, i);
}

TEST(IniValue, GetToInt64)
{
  const rune::ini_value value = 284'482;

  float f{};
  ASSERT_THROW(value.get_to(f), std::bad_variant_access);

  rune::int64 i{};
  value.get_to(i);

  ASSERT_EQ(284'482, i);
}

TEST(IniValue, GetToUint8)
{
  const rune::ini_value value = 12u;

  double d{};
  ASSERT_THROW(value.get_to(d), std::bad_variant_access);

  rune::uint8 u{};
  value.get_to(u);

  ASSERT_EQ(12u, u);
}

TEST(IniValue, GetToUint16)
{
  const rune::ini_value value = 468u;

  bool b{};
  ASSERT_THROW(value.get_to(b), std::bad_variant_access);

  rune::uint16 u{};
  value.get_to(u);

  ASSERT_EQ(468u, u);
}

TEST(IniValue, GetToUint32)
{
  const rune::ini_value value = 1'395u;

  rune::int32 i{};
  ASSERT_THROW(value.get_to(i), std::bad_variant_access);

  rune::uint32 u{};
  value.get_to(u);

  ASSERT_EQ(1'395u, u);
}

TEST(IniValue, GetToUint64)
{
  const rune::ini_value value = 92'564u;

  std::string s;
  ASSERT_THROW(value.get_to(s), std::bad_variant_access);

  rune::uint64 u{};
  value.get_to(u);

  ASSERT_EQ(92'564u, u);
}

TEST(IniValue, GetToFloat)
{
  const rune::ini_value value = 54.3f;

  int i{};
  ASSERT_THROW(value.get_to(i), std::bad_variant_access);

  float f{};
  value.get_to(f);

  ASSERT_EQ(54.3f, f);
}

TEST(IniValue, GetToDouble)
{
  const rune::ini_value value = 164.8;

  int i{};
  ASSERT_THROW(value.get_to(i), std::bad_variant_access);

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

TEST(IniValue, TryGet)
{
  rune::ini_value value;

  value = "foo";
  ASSERT_TRUE(value.try_get_string());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_FALSE(value.try_get_bool());

  value = 123;
  ASSERT_FALSE(value.try_get_string());
  ASSERT_TRUE(value.try_get_int());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_FALSE(value.try_get_bool());

  value = 42u;
  ASSERT_FALSE(value.try_get_string());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_TRUE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_FALSE(value.try_get_bool());

  value = 12.3;
  ASSERT_FALSE(value.try_get_string());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_TRUE(value.try_get_float());
  ASSERT_FALSE(value.try_get_bool());

  value = true;
  ASSERT_FALSE(value.try_get_string());
  ASSERT_FALSE(value.try_get_int());
  ASSERT_FALSE(value.try_get_uint());
  ASSERT_FALSE(value.try_get_float());
  ASSERT_TRUE(value.try_get_bool());
}

TEST(IniValue, TypeIndicators)
{
  rune::ini_value value = "foo";
  ASSERT_TRUE(value.is_string());
  ASSERT_FALSE(value.is_int());
  ASSERT_FALSE(value.is_uint());
  ASSERT_FALSE(value.is_float());
  ASSERT_FALSE(value.is_bool());

  value = 27;
  ASSERT_FALSE(value.is_string());
  ASSERT_TRUE(value.is_int());
  ASSERT_FALSE(value.is_uint());
  ASSERT_FALSE(value.is_float());
  ASSERT_FALSE(value.is_bool());

  value = 452u;
  ASSERT_FALSE(value.is_string());
  ASSERT_FALSE(value.is_int());
  ASSERT_TRUE(value.is_uint());
  ASSERT_FALSE(value.is_float());
  ASSERT_FALSE(value.is_bool());

  value = 542.8f;
  ASSERT_FALSE(value.is_string());
  ASSERT_FALSE(value.is_int());
  ASSERT_FALSE(value.is_uint());
  ASSERT_TRUE(value.is_float());
  ASSERT_FALSE(value.is_bool());

  value = false;
  ASSERT_FALSE(value.is_string());
  ASSERT_FALSE(value.is_int());
  ASSERT_FALSE(value.is_uint());
  ASSERT_FALSE(value.is_float());
  ASSERT_TRUE(value.is_bool());
}

TEST(IniValue, Comparison)
{
  ASSERT_EQ(rune::ini_value{}, rune::ini_value{});

  ASSERT_EQ(rune::ini_value{42}, rune::ini_value{42});
  ASSERT_NE(rune::ini_value{42}, rune::ini_value{42u});
  ASSERT_NE(rune::ini_value{42}, rune::ini_value{123});

  ASSERT_NE(rune::ini_value{123u}, rune::ini_value{"foo"});
  ASSERT_EQ(rune::ini_value{12.3}, rune::ini_value{12.3});

  ASSERT_EQ(rune::ini_value{true}, rune::ini_value{true});
  ASSERT_EQ(rune::ini_value{false}, rune::ini_value{false});
  ASSERT_NE(rune::ini_value{true}, rune::ini_value{false});
}

TEST(IniValue, StreamOperator)
{
  std::cout << "rune::ini_value{42}: " << rune::ini_value{42} << '\n';
  std::cout << "rune::ini_value{123u}: " << rune::ini_value{123u} << '\n';
  std::cout << "rune::ini_value{27.5}: " << rune::ini_value{27.5} << '\n';
  std::cout << "rune::ini_value{\"foo\"}: " << rune::ini_value{"foo"} << '\n';
  std::cout << "rune::ini_value{true}: " << rune::ini_value{true} << '\n';
}