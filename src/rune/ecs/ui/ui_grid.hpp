#ifndef RUNE_ECS_UI_UI_GRID_HPP
#define RUNE_ECS_UI_UI_GRID_HPP

#include <centurion.hpp>  // fpoint

namespace rune {

#ifndef RUNE_MENU_ROW_SIZE
#define RUNE_MENU_ROW_SIZE 10.0f
#endif  // RUNE_MENU_ROW_SIZE

#ifndef RUNE_MENU_COLUMN_SIZE
#define RUNE_MENU_COLUMN_SIZE 10.0f
#endif  // RUNE_MENU_COLUMN_SIZE

inline constexpr float menu_row_size = RUNE_MENU_ROW_SIZE;
inline constexpr float menu_column_size = RUNE_MENU_COLUMN_SIZE;

[[nodiscard]] constexpr auto row_to_y(const float row) noexcept -> float
{
  return row * menu_row_size;
}

[[nodiscard]] constexpr auto column_to_x(const float column) noexcept -> float
{
  return column * menu_column_size;
}

[[nodiscard]] constexpr auto from_grid(const float row, const float column) noexcept
    -> cen::fpoint
{
  return {column_to_x(column), row_to_y(row)};
}

}  // namespace rune

#endif  // RUNE_ECS_UI_UI_GRID_HPP
