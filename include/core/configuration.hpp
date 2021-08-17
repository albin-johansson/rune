#ifndef RUNE_CORE_CONFIGURATION_HPP
#define RUNE_CORE_CONFIGURATION_HPP

#include <centurion.hpp>  // window, renderer, iarea
#include <concepts>       // convertible_to
#include <filesystem>     // path
#include <string>         // string

#include "../aliases/integers.hpp"
#include "../io/csv.hpp"
#include "../io/ini.hpp"

namespace rune {

/// \addtogroup core
/// \{

/**
 * \struct configuration
 *
 * \brief Provides configuration options for different engine aspects.
 *
 * \see `engine`
 *
 * \since 0.1.0
 */
struct configuration final
{
  uint32 renderer_flags;
  cen::iarea window_size;

  double engine_max_tick_rate;
  int engine_max_frames_per_tick;

  usize aabb_default_capacity;

  float ui_row_size;
  float ui_column_size;
};

/// \name Configuration
/// \{

[[nodiscard]] inline auto get_default_cfg() -> configuration
{
  return {.renderer_flags = cen::renderer::default_flags(),
          .window_size = cen::window::default_size(),
          .engine_max_tick_rate = 120.0,
          .engine_max_frames_per_tick = 5,
          .aabb_default_capacity = 64u,
          .ui_row_size = 10.0f,
          .ui_column_size = 10.0f};
}

[[nodiscard]] inline auto get_cfg() -> configuration&
{
  static auto cfg = get_default_cfg();
  return cfg;
}

[[nodiscard]] inline auto get_engine_max_tick_rate() -> double
{
  return get_cfg().engine_max_tick_rate;
}

[[nodiscard]] inline auto get_engine_max_frames_per_tick() -> int
{
  return get_cfg().engine_max_frames_per_tick;
}

[[nodiscard]] inline auto get_aabb_default_capacity() -> usize
{
  return get_cfg().aabb_default_capacity;
}

[[nodiscard]] inline auto get_ui_row_size() -> float
{
  return get_cfg().ui_row_size;
}

[[nodiscard]] inline auto get_ui_column_size() -> float
{
  return get_cfg().ui_column_size;
}

[[nodiscard]] inline auto parse_configuration(const std::filesystem::path& path)
    -> configuration
{
  auto cfg = get_default_cfg();

  const auto ini = read_ini(path);
  if (!ini)
  {
    return cfg;
  }

  if (ini->contains("Engine"))
  {
    const auto engine = ini->at("Engine");

    if (engine.contains("MaxTickRate"))
    {
      engine.at("MaxTickRate").get_to(cfg.engine_max_tick_rate);
    }

    if (engine.contains("MaxFramesPerTick"))
    {
      engine.at("MaxFramesPerTick").get_to(cfg.engine_max_frames_per_tick);
    }
  }

  if (ini->contains("Graphics"))
  {
    const auto& graphics = ini->at("Graphics");

    if (graphics.contains("RendererFlags"))
    {
      if (const auto flags = graphics.at("RendererFlags").as<std::string>();
          flags == "default")
      {
        cfg.renderer_flags = cen::renderer::default_flags();
      }
      else
      {
        cfg.renderer_flags = 0;
        for (const auto& token : parse_csv(flags))
        {
          if (token == "accelerated")
          {
            cfg.renderer_flags |= cen::renderer::accelerated;
          }
          else if (token == "vsync")
          {
            cfg.renderer_flags |= cen::renderer::vsync;
          }
          else if (token == "target_textures")
          {
            cfg.renderer_flags |= cen::renderer::target_textures;
          }
          else if (token == "software")
          {
            cfg.renderer_flags |= cen::renderer::software;
          }
        }
      }
    }

    if (graphics.contains("WindowWidth"))
    {
      graphics.at("WindowWidth").get_to(cfg.window_size.width);
    }

    if (graphics.contains("WindowHeight"))
    {
      graphics.at("WindowHeight").get_to(cfg.window_size.height);
    }
  }

  if (ini->contains("AABB"))
  {
    const auto& aabb = ini->at("AABB");

    if (aabb.contains("TreeDefaultCapacity"))
    {
      aabb.at("TreeDefaultCapacity").get_to(cfg.aabb_default_capacity);
    }
  }

  if (ini->contains("UI"))
  {
    const auto& ui = ini->at("UI");

    if (ui.contains("MenuRowSize"))
    {
      ui.at("MenuRowSize").get_to(cfg.ui_row_size);
    }

    if (ui.contains("MenuColumnSize"))
    {
      ui.at("MenuColumnSize").get_to(cfg.ui_column_size);
    }
  }

  return cfg;
}

inline void load_configuration(const std::filesystem::path& path)
{
  get_cfg() = parse_configuration(path);
}

/// \} End of configuration

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_CONFIGURATION_HPP
