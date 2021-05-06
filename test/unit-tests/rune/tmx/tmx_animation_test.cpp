#include "tmx/tmx_animation.hpp"

#include <gtest/gtest.h>

#include "tmx/tmx_parsers.hpp"

TEST(TmxFrame, Defaults)
{
  const rune::tmx_frame frame;
  ASSERT_EQ(rune::tmx_local_id{0}, frame.tile);
  ASSERT_EQ(0, frame.duration);
}

TEST(TmxAnimation, Parse)
{
  const auto json = R"(
    [
      {
        "tileid": 42,
        "duration": 123
      },
      {
        "tileid": 27,
        "duration": 447
      }
    ]
  )"_json;

  const auto animation = json.get<rune::tmx_animation>();
  ASSERT_EQ(2, animation.frames.size());

  const auto& first = animation.frames.at(0);
  ASSERT_EQ(rune::tmx_local_id{42}, first.tile);
  ASSERT_EQ(123, first.duration);

  const auto& second = animation.frames.at(1);
  ASSERT_EQ(rune::tmx_local_id{27}, second.tile);
  ASSERT_EQ(447, second.duration);
}
