#include <iterator>  // back_inserter
#include <vector>    // vector

#include "../../include/everything.hpp"

using rune::float2;

namespace {
namespace comp {

struct movable final
{
  float2 position;
  float2 velocity;
};

struct paddle final
{};

struct ball final
{
  bool active{true};
};

}  // namespace comp

constexpr int logical_width = 800;
constexpr int logical_height = 600;
constexpr float half_height = logical_height / 2.0f;

constexpr float paddle_speed = 250;
constexpr float ball_speed = 300;

constexpr float paddle_width = 30;
constexpr float paddle_height = 100;
constexpr float2 paddle_size = {paddle_width, paddle_height};

constexpr float ball_radius = 30;
constexpr float2 ball_size = {2.0f * ball_radius, 2.0f * ball_radius};

constexpr float paddle_y = (logical_height - paddle_height) / 2.0f;

constexpr float2 initial_ball_pos = {logical_width / 2.0f, half_height};
constexpr float2 initial_left_paddle_pos = {10, paddle_y};
constexpr float2 initial_right_paddle_pos = {logical_width - paddle_width - 10, paddle_y};

auto make_paddle(entt::registry& registry, const float2 position) -> entt::entity
{
  const auto entity = registry.create();

  auto& movable = registry.emplace<comp::movable>(entity);
  movable.position = position;

  registry.emplace<comp::paddle>(entity);

  return entity;
}

auto make_ball(entt::registry& registry) -> entt::entity
{
  const auto entity = registry.create();

  auto& movable = registry.emplace<comp::movable>(entity);
  movable.position = float2{logical_width / 2.0f, half_height};
  movable.velocity.x = rune::next_bool() ? ball_speed : -ball_speed;
  movable.velocity.y = rune::next_bool() ? ball_speed : -ball_speed;

  registry.emplace<comp::ball>(entity);

  return entity;
}

class pong_game final : public rune::game_base
{
  constexpr static auto key_left_up = cen::scancodes::w;
  constexpr static auto key_left_down = cen::scancodes::s;
  constexpr static auto key_right_up = cen::scancodes::up;
  constexpr static auto key_right_down = cen::scancodes::down;

 public:
  pong_game()
      : m_left{make_paddle(m_registry, initial_left_paddle_pos)}
      , m_right{make_paddle(m_registry, initial_right_paddle_pos)}
      , m_ball{make_ball(m_registry)}
  {
    m_tree.disable_thickness_factor();
    m_tree.insert(m_left, initial_left_paddle_pos, initial_left_paddle_pos + paddle_size);
    m_tree.insert(m_right,
                  initial_right_paddle_pos,
                  initial_right_paddle_pos + paddle_size);
    m_tree.insert(m_ball, initial_ball_pos, initial_ball_pos + ball_size);
  }

  void handle_input(const rune::input& input) override
  {
    const auto& keyboard = input.keyboard;

    if (keyboard.just_released(cen::keycodes::escape))
    {
      m_quit = true;
      return;
    }

    auto updateMovable = [](comp::movable& movable, const bool up, const bool down) {
      if (up && down || !up && !down)
      {
        movable.velocity.reset();
      }
      else if (up)
      {
        movable.velocity.y = -paddle_speed;
      }
      else
      {
        movable.velocity.y = paddle_speed;
      }
    };

    updateMovable(m_registry.get<comp::movable>(m_left),
                  keyboard.is_pressed(key_left_up),
                  keyboard.is_pressed(key_left_down));

    updateMovable(m_registry.get<comp::movable>(m_right),
                  keyboard.is_pressed(key_right_up),
                  keyboard.is_pressed(key_right_down));
  }

  void tick(const float dt) override
  {
    for (auto&& [entity, movable] : m_registry.view<comp::movable>().each())
    {
      movable.position += movable.velocity * dt;
      m_tree.set_position(entity, movable.position);
    }

    update_ball();
  }

  void render(rune::graphics& graphics) const override
  {
    auto& renderer = graphics.get_renderer();
    renderer.clear_with(cen::colors::teal);

    renderer.set_color(cen::colors::white);
    for (auto&& [entity, movable] : m_registry.view<comp::movable, comp::paddle>().each())
    {
      const auto& pos = movable.position;
      renderer.fill_rect(cen::rect(pos.x, pos.y, paddle_width, paddle_height));
    }

    for (auto&& [entity, movable, ball] :
         m_registry.view<comp::movable, comp::ball>().each())
    {
      const auto& pos = movable.position;
      renderer.fill_circle({pos.x + ball_radius / 2.0f, pos.y + ball_radius / 2.0f},
                           ball_radius);
    }

    renderer.present();
  }

  [[nodiscard]] auto should_quit() const noexcept -> bool override
  {
    return m_quit;
  }

 private:
  entt::registry m_registry;
  rune::aabb_tree<entt::entity> m_tree;
  entt::entity m_left{entt::null};
  entt::entity m_right{entt::null};
  entt::entity m_ball{entt::null};
  bool m_quit{};

  void update_ball()
  {
    for (auto&& [entity, movable, ball] :
         m_registry.view<comp::movable, comp::ball>().each())
    {
      if (movable.position.y <= 0)
      {
        movable.position.y = 0;
        movable.velocity.y *= -1;
      }
      else if (movable.position.y + ball_radius >= logical_height)
      {
        movable.position.y = logical_height - ball_radius;
        movable.velocity.y *= -1;
      }

      if (ball.active)
      {
        std::vector<entt::entity> candidates;
        m_tree.query(m_ball, std::back_inserter(candidates));
        for (const auto candidate : candidates)
        {
          if (candidate == m_left || candidate == m_right)
          {
            movable.velocity.x *= -1.0f;
            ball.active = false;
            break;
          }
        }
      }
      else if (movable.position.x >= (logical_width / 2.0f) - 50 &&
               movable.position.x <= (logical_width / 2.0f) + 50)
      {
        ball.active = true;
      }
    }
  }
};

}  // namespace

int main(int, char**)
{
  cen::library centurion;
  cen::log::use_preset_output_function();

  if constexpr (cen::is_debug_build())
  {
    cen::log::set_priority(cen::log_priority::debug);
  }

  rune::load_configuration("pong.ini");
  rune::engine<pong_game> engine;

  return engine.run();
}
