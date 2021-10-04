#include <iterator>  // back_inserter
#include <vector>    // vector

#include "../../src/rune.hpp"

using rune::float2;
using aabb_tree = rune::aabb_tree<entt::entity>;

namespace {
namespace comp {

struct movable final
{
  float2 position;
  float2 velocity;
};

struct paddle final
{};

struct left_paddle
{};

struct right_paddle
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

class pong_game final
{
  constexpr static auto key_left_up = cen::scancodes::w;
  constexpr static auto key_left_down = cen::scancodes::s;
  constexpr static auto key_right_up = cen::scancodes::up;
  constexpr static auto key_right_down = cen::scancodes::down;

 public:
  pong_game()
  {
    mEngine.add_input_system<&pong_game::handle_input>(this);

    mEngine.add_logic_system<&pong_game::update_movables>();
    mEngine.add_logic_system<&pong_game::update_ball>();

    mEngine.add_render_system<&pong_game::pre_render>();
    mEngine.add_render_system<&pong_game::render_paddles>();
    mEngine.add_render_system<&pong_game::render_ball>();
    mEngine.add_render_system<&pong_game::post_render>();

    auto& registry = mEngine.registry();
    registry.set<cen::renderer>(mEngine.window(), cen::renderer::accelerated);

    const auto left = make_paddle(registry, initial_left_paddle_pos);
    const auto right = make_paddle(registry, initial_right_paddle_pos);
    const auto ball = make_ball(registry);

    registry.emplace<comp::left_paddle>(left);
    registry.emplace<comp::right_paddle>(right);

    auto& tree = registry.set<aabb_tree>();
    tree.disable_thickness_factor();
    tree.insert(left, initial_left_paddle_pos, initial_left_paddle_pos + paddle_size);
    tree.insert(right, initial_right_paddle_pos, initial_right_paddle_pos + paddle_size);
    tree.insert(ball, initial_ball_pos, initial_ball_pos + ball_size);
  }

  void run()
  {
    mEngine.run();
  }

 private:
  rune::engine mEngine;

  // Movable system
  static void update_movables(entt::registry& registry,
                              entt::dispatcher& /*dispatcher*/,
                              const float dt)
  {
    auto& tree = registry.ctx<aabb_tree>();
    for (auto&& [entity, movable] : registry.view<comp::movable>().each())
    {
      movable.position += movable.velocity * dt;
      tree.set_position(entity, movable.position);
    }
  }

  // Ball system
  static void update_ball(entt::registry& registry)
  {
    auto& tree = registry.ctx<aabb_tree>();
    for (auto&& [ballEntity, movable, ball] :
         registry.view<comp::movable, comp::ball>().each())
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
        tree.query(ballEntity, std::back_inserter(candidates));
        for (const auto candidate : candidates)
        {
          if (registry.any_of<comp::left_paddle, comp::right_paddle>(candidate))
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

  void handle_input(entt::registry& registry, entt::dispatcher& dispatcher)
  {
    const auto& keyboard = mEngine.keyboard();

    if (keyboard.just_released(cen::keycodes::escape))
    {
      mEngine.stop();
      return;
    }

    auto updateMovable = [&](const entt::entity entity, const bool up, const bool down) {
      auto& movable = registry.get<comp::movable>(entity);

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

    updateMovable(registry.view<comp::movable, comp::left_paddle>().front(),
                  keyboard.is_pressed(key_left_up),
                  keyboard.is_pressed(key_left_down));

    updateMovable(registry.view<comp::movable, comp::right_paddle>().front(),
                  keyboard.is_pressed(key_right_up),
                  keyboard.is_pressed(key_right_down));
  }

  static void pre_render(entt::registry& registry)
  {
    auto& renderer = registry.ctx<cen::renderer>();
    renderer.clear_with(cen::colors::teal);
  }

  static void render_paddles(entt::registry& registry)
  {
    auto& renderer = registry.ctx<cen::renderer>();
    renderer.set_color(cen::colors::white);

    for (auto&& [entity, movable] : registry.view<comp::movable, comp::paddle>().each())
    {
      const auto& pos = movable.position;
      renderer.fill_rect(cen::rect(pos.x, pos.y, paddle_width, paddle_height));
    }
  }

  static void render_ball(entt::registry& registry)
  {
    auto& renderer = registry.ctx<cen::renderer>();
    renderer.set_color(cen::colors::white);

    for (auto&& [entity, movable, ball] :
         registry.view<comp::movable, comp::ball>().each())
    {
      const auto& pos = movable.position;
      renderer.fill_circle({pos.x + ball_radius / 2.0f, pos.y + ball_radius / 2.0f},
                           ball_radius);
    }
  }

  static void post_render(entt::registry& registry)
  {
    auto& renderer = registry.ctx<cen::renderer>();
    renderer.present();
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

  pong_game game;
  game.run();

  return 0;
}
