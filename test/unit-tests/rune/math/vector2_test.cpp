#include "vector2.hpp"

#include <gtest/gtest.h>

#include <cereal/cereal.hpp>
#include <iostream>     // cout
#include <type_traits>  // is_same_v

#include "serialization_utils.hpp"

static_assert(std::is_same_v<rune::float2::value_type, float>);
static_assert(std::is_same_v<rune::double2::value_type, double>);

TEST(Vector2, Defaults)
{
  const rune::float2 vector;
  ASSERT_FLOAT_EQ(0, vector.x);
  ASSERT_FLOAT_EQ(0, vector.y);
  ASSERT_TRUE(vector.is_zero());
}

TEST(Vector2, ValueConstructor)
{
  const auto x = 12.3f;
  const auto y = 65.3f;

  const rune::float2 vector{x, y};
  ASSERT_FLOAT_EQ(x, vector.x);
  ASSERT_FLOAT_EQ(y, vector.y);
}

TEST(Vector2, Reset)
{
  rune::float2 vector{123, 456};
  vector.reset();

  ASSERT_FLOAT_EQ(0, vector.x);
  ASSERT_FLOAT_EQ(0, vector.y);
  ASSERT_TRUE(vector.is_zero());
}

TEST(Vector2, Negate)
{
  rune::float2 vector{12, 34};

  vector.negate();
  ASSERT_FLOAT_EQ(-12, vector.x);
  ASSERT_FLOAT_EQ(-34, vector.y);

  vector.negate();
  ASSERT_FLOAT_EQ(12, vector.x);
  ASSERT_FLOAT_EQ(34, vector.y);
}

TEST(Vector2, Normalize)
{
  {  // Normalize a zero vector
    rune::float2 vector;
    vector.normalize();

    ASSERT_FLOAT_EQ(0, vector.x);
    ASSERT_FLOAT_EQ(0, vector.y);
    ASSERT_TRUE(vector.is_zero());
    ASSERT_FALSE(vector.is_unit());
  }

  {  // Normalize a non-zero vector
    rune::float2 vector{123, 456};
    ASSERT_FALSE(vector.is_unit());

    vector.normalize();
    ASSERT_TRUE(vector.is_unit());
  }
}

TEST(Vector2, Scale)
{
  rune::float2 vector{12, 34};

  vector.scale(10);
  ASSERT_FLOAT_EQ(120, vector.x);
  ASSERT_FLOAT_EQ(340, vector.y);

  vector.scale(0.5f);
  ASSERT_FLOAT_EQ(60, vector.x);
  ASSERT_FLOAT_EQ(170, vector.y);

  vector.scale(-1);
  ASSERT_FLOAT_EQ(-60, vector.x);
  ASSERT_FLOAT_EQ(-170, vector.y);
}

TEST(Vector2, Lerp)
{
  rune::float2 a{0, 0};
  const rune::float2 b{1, 1};

  a.lerp(b, 0.5f);
  ASSERT_EQ(0.5f, a.x);
  ASSERT_EQ(0.5f, a.y);
  ASSERT_EQ(1, b.x);
  ASSERT_EQ(1, b.y);
}

TEST(Vector2, LookAt)
{
  {  // Simple case
    const rune::float2 point{1, 0};
    rune::float2 vector;

    vector.look_at(point, 1);
    ASSERT_FLOAT_EQ(1, vector.magnitude());
    ASSERT_FLOAT_EQ(1, vector.x);
    ASSERT_FLOAT_EQ(0, vector.y);
  }

  {  // Slightly more involved
    const rune::float2 point{1, 1};
    rune::float2 vector{-1, -1};

    vector.look_at(point, 1);
    ASSERT_FLOAT_EQ(1.0f, vector.magnitude());
    ASSERT_FLOAT_EQ(1.0f / std::sqrt(2.0f), vector.x);
    ASSERT_FLOAT_EQ(1.0f / std::sqrt(2.0f), vector.y);
  }

  {  // Maintain magnitude
    const rune::float2 point{152, -23};
    rune::float2 vector{43, 84};

    const auto magnitude = vector.magnitude();
    vector.look_at(point);

    ASSERT_FLOAT_EQ(magnitude, vector.magnitude());
    ASSERT_GT(vector.x, 0);
    ASSERT_LT(vector.y, 0);
  }
}

TEST(Vector2, Magnitude)
{
  const rune::float2 zero;
  const rune::float2 x{-1, 0};
  const rune::float2 y{0, 1};
  const rune::float2 xy{1, 1};

  ASSERT_FLOAT_EQ(0, zero.magnitude());
  ASSERT_FLOAT_EQ(1, x.magnitude());
  ASSERT_FLOAT_EQ(1, y.magnitude());
  ASSERT_FLOAT_EQ(std::sqrt(2.0f), xy.magnitude());
}

TEST(Vector2, Magnitude2)
{
  const rune::float2 zero;
  const rune::float2 x{2, 0};
  const rune::float2 y{0, -3};
  const rune::float2 xy{1, 1};

  ASSERT_FLOAT_EQ(0, zero.magnitude2());
  ASSERT_FLOAT_EQ(4, x.magnitude2());
  ASSERT_FLOAT_EQ(9, y.magnitude2());
  ASSERT_FLOAT_EQ(2, xy.magnitude2());
}

TEST(Vector2, IsUnit)
{
  const rune::float2 zero;
  const rune::float2 x{1, 0};
  const rune::float2 y{0, 1};
  const rune::float2 vector{123, 456};

  ASSERT_FALSE(zero.is_unit());
  ASSERT_TRUE(x.is_unit());
  ASSERT_TRUE(y.is_unit());
  ASSERT_FALSE(vector.is_unit());
}

TEST(Vector2, IsZero)
{
  const rune::float2 zero;
  ASSERT_TRUE(zero.is_zero());

  rune::float2 vector{10, 20};
  ASSERT_FALSE(vector.is_zero());

  vector.reset();
  ASSERT_TRUE(vector.is_zero());
}

TEST(Vector2, Serialize)
{
  {
    rune::float2 vector{123, 456};
    serialize_write("float2.bin", vector);
  }

  {
    const auto vector = serialize_read<rune::float2>("float2.bin");
    ASSERT_FLOAT_EQ(123, vector.x);
    ASSERT_FLOAT_EQ(456, vector.y);
  }
}

TEST(Vector2, EqualityOperators)
{
  const rune::float2 a{10, 20};
  const rune::float2 b{a};
  const rune::float2 c{42, 27};

  ASSERT_EQ(a, a);
  ASSERT_TRUE(a == a);

  ASSERT_EQ(a, b);
  ASSERT_EQ(b, a);
  ASSERT_TRUE(a == b);
  ASSERT_TRUE(b == a);
  ASSERT_FALSE(a != b);

  ASSERT_NE(a, c);
  ASSERT_TRUE(a != c);
  ASSERT_FALSE(a == c);
}

TEST(Vector2, AlmostEqual)
{
  const rune::float2 a{123, 456};
  const rune::float2 b{34, 394};
  const rune::float2 c{34 + (rune::default_epsilon / 2.0f),
                       394 + (rune::default_epsilon / 2.0f)};

  ASSERT_TRUE(rune::almost_equal(a, a));

  ASSERT_FALSE(rune::almost_equal(a, b));
  ASSERT_FALSE(rune::almost_equal(b, a));

  ASSERT_TRUE(rune::almost_equal(b, c));
  ASSERT_TRUE(rune::almost_equal(c, b));
}

TEST(Vector2, AdditionAssignmentOperator)
{
  rune::float2 a{15, 24};
  const rune::float2 b{45, -4};

  a += b;

  ASSERT_FLOAT_EQ(60, a.x);
  ASSERT_FLOAT_EQ(20, a.y);
  ASSERT_FLOAT_EQ(45, b.x);
  ASSERT_FLOAT_EQ(-4, b.y);
}

TEST(Vector2, SubtractionAssignmentOperator)
{
  rune::float2 a{123, 94};
  const rune::float2 b{-73, 33};

  a -= b;

  ASSERT_FLOAT_EQ(196, a.x);
  ASSERT_FLOAT_EQ(61, a.y);
  ASSERT_FLOAT_EQ(-73, b.x);
  ASSERT_FLOAT_EQ(33, b.y);
}

TEST(Vector2, MultiplicationAssignmentOperator)
{
  rune::float2 vector{12, 74};

  vector *= 2.5f;

  ASSERT_FLOAT_EQ(30, vector.x);
  ASSERT_FLOAT_EQ(185, vector.y);
}

TEST(Vector2, ToString)
{
  const rune::float2 vector{123, 456};
  std::cout << vector << '\n';
}
