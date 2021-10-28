#include "rune-math/index_to_matrix.hpp"

#include <gtest/gtest.h>

TEST(IndexToMatrix, IndexToMatrix)
{
  const auto nColumns = 4;

  ASSERT_EQ(0, rune::index_to_matrix(0, nColumns).row);
  ASSERT_EQ(0, rune::index_to_matrix(0, nColumns).column);

  ASSERT_EQ(0, rune::index_to_matrix(1, nColumns).row);
  ASSERT_EQ(1, rune::index_to_matrix(1, nColumns).column);

  ASSERT_EQ(0, rune::index_to_matrix(2, nColumns).row);
  ASSERT_EQ(2, rune::index_to_matrix(2, nColumns).column);

  ASSERT_EQ(0, rune::index_to_matrix(3, nColumns).row);
  ASSERT_EQ(3, rune::index_to_matrix(3, nColumns).column);

  ASSERT_EQ(1, rune::index_to_matrix(4, nColumns).row);
  ASSERT_EQ(0, rune::index_to_matrix(4, nColumns).column);

  ASSERT_EQ(1, rune::index_to_matrix(5, nColumns).row);
  ASSERT_EQ(1, rune::index_to_matrix(5, nColumns).column);

  ASSERT_EQ(1, rune::index_to_matrix(6, nColumns).row);
  ASSERT_EQ(2, rune::index_to_matrix(6, nColumns).column);
}
