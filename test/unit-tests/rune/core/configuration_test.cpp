#include "core/configuration.hpp"

#include <gtest/gtest.h>

TEST(Configuration, ParseConfiguration)
{
  {
    const auto cfg = rune::parse_configuration("resources/rune_default.ini");
    ASSERT_EQ(120.0, cfg.engine_max_tick_rate);
    ASSERT_EQ(5, cfg.engine_max_frames_per_tick);

    ASSERT_EQ("Rune", cfg.window_title);
    ASSERT_EQ(800, cfg.window_size.width);
    ASSERT_EQ(600, cfg.window_size.height);

    ASSERT_EQ(cen::renderer::default_flags(), cfg.renderer_flags);
    ASSERT_EQ(0, cfg.logical_size.width);
    ASSERT_EQ(0, cfg.logical_size.height);

    ASSERT_EQ(64u, cfg.aabb_default_capacity);

    ASSERT_EQ(10.0, cfg.ui_row_size);
    ASSERT_EQ(10.0, cfg.ui_column_size);
  }

  {
    const auto cfg = rune::parse_configuration("resources/rune_custom.ini");
    ASSERT_EQ(240.0, cfg.engine_max_tick_rate);
    ASSERT_EQ(7, cfg.engine_max_frames_per_tick);

    ASSERT_EQ("Custom", cfg.window_title);
    ASSERT_EQ(1200, cfg.window_size.width);
    ASSERT_EQ(800, cfg.window_size.height);

    ASSERT_EQ(cen::renderer::accelerated | cen::renderer::vsync |
                  cen::renderer::target_textures,
              cfg.renderer_flags);
    ASSERT_EQ(800, cfg.logical_size.width);
    ASSERT_EQ(600, cfg.logical_size.height);

    ASSERT_EQ(48u, cfg.aabb_default_capacity);

    ASSERT_EQ(15.0, cfg.ui_row_size);
    ASSERT_EQ(30.0, cfg.ui_column_size);
  }
}
