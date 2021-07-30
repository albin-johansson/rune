#include "tmx/tmx_grid.hpp"

#include <gtest/gtest.h>

TEST(TmxGrid, Defaults)
{
  const rune::tmx_grid grid;
  ASSERT_EQ(0, grid.cell_width);
  ASSERT_EQ(0, grid.cell_height);
  ASSERT_EQ(rune::tmx_grid_orientation::orthogonal, grid.orientation);
}

TEST(TmxGrid, Parse)
{
  const auto json = R"(
    {
      "width": 42,
      "height": 27,
      "orientation": "isometric"
    }
  )"_json;

  const auto grid = json.get<rune::tmx_grid>();
  ASSERT_EQ(42, grid.cell_width);
  ASSERT_EQ(27, grid.cell_height);
  ASSERT_EQ(rune::tmx_grid_orientation::isometric, grid.orientation);
}
