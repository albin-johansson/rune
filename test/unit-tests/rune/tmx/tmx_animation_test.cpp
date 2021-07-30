#include "tmx/tmx_animation.hpp"

#include <gtest/gtest.h>

#include "tmx/parse_tmx.hpp"

using namespace rune::tmx_literals;
using namespace std::chrono_literals;

TEST(TmxFrame, Defaults)
{
  const rune::tmx_frame frame;
  ASSERT_EQ(0_local, frame.tile);
  ASSERT_EQ(std::chrono::milliseconds::zero(), frame.duration);
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
  ASSERT_EQ(42_local, first.tile);
  ASSERT_EQ(123ms, first.duration);

  const auto& second = animation.frames.at(1);
  ASSERT_EQ(27_local, second.tile);
  ASSERT_EQ(447ms, second.duration);
}
