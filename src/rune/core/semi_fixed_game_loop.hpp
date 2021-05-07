#pragma once

#include <algorithm>      // min
#include <centurion.hpp>  // ...
#include <concepts>       // floating_point

#include "../aliases/delta_time.hpp"

namespace rune {

/// \addtogroup core
/// \{

#ifndef RUNE_MAX_TICK_RATE
#define RUNE_MAX_TICK_RATE 120.0
#endif  // RUNE_MAX_TICK_RATE

#ifndef RUNE_ENGINE_MAX_FRAMES_PER_TICK
#define RUNE_ENGINE_MAX_FRAMES_PER_TICK 5
#endif  // RUNE_ENGINE_MAX_FRAMES_PER_TICK

inline constexpr double max_tick_rate = RUNE_MAX_TICK_RATE;
inline constexpr int engine_max_frames_per_tick = RUNE_ENGINE_MAX_FRAMES_PER_TICK;

[[nodiscard]] inline auto tick_rate() -> double
{
  return std::min(static_cast<double>(max_tick_rate),
                  static_cast<double>(cen::screen::refresh_rate().value()));
}

template <game_type Game, std::derived_from<graphics> Graphics>
class engine;

template <game_type Game, std::derived_from<graphics> Graphics>
class semi_fixed_game_loop
{
 public:
  using engine_type = engine<Game, Graphics>;
  using seconds_type = cen::seconds<double>;

  explicit semi_fixed_game_loop(engine_type* engine)
      : m_engine{engine}
      , m_rate{tick_rate()}
      , m_delta{1.0 / m_rate}
      , m_current{cen::counter::now_in_seconds<double>()}
  {}

  void fetch_current_time() noexcept
  {
    m_current = cen::counter::now_in_seconds<double>();
  }

  void tick()
  {
    const auto newTime = cen::counter::now_in_seconds<double>();
    auto frameTime = newTime - m_current;

    m_current = newTime;
    auto nSteps = 0;

    while (frameTime > seconds_type::zero())
    {
      if (nSteps > engine_max_frames_per_tick)
      {
        break;  // avoids spiral-of-death by limiting maximum amount of steps
      }

      m_running = m_engine->update_input();
      if (!m_running)
      {
        break;
      }

      const auto dt = std::min(frameTime, m_delta);
      m_engine->update_logic(static_cast<delta_time>(dt.count()));

      frameTime -= dt;

      ++nSteps;
    }
  }

  [[nodiscard]] auto is_running() const noexcept -> bool
  {
    return m_running;
  }

 private:
  engine_type* m_engine{};
  double m_rate;
  seconds_type m_delta;
  seconds_type m_current;
  bool m_running{true};
};

/// \} End of group core

}  // namespace rune
