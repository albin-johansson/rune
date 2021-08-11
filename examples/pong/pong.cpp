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

inline constexpr int logical_width = 800;
inline constexpr int logical_height = 600;
inline constexpr float half_height = logical_height / 2.0f;

inline constexpr float paddle_speed = 250;
inline constexpr float ball_speed = 300;

inline constexpr float paddle_width = 30;
inline constexpr float paddle_height = 100;
inline constexpr float2 paddle_size = {paddle_width, paddle_height};

inline constexpr float ball_radius = 30;

inline constexpr float paddle_y = (logical_height - paddle_height) / 2.0f;

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
 public:
  explicit pong_game(rune::graphics& graphics)
      : m_left{make_paddle(m_registry, float2{10, paddle_y})}
      , m_right{make_paddle(m_registry,
                            float2{logical_width - paddle_width - 10, paddle_y})}
      , m_ball{make_ball(m_registry)}
  {
    graphics.get_renderer().set_logical_size({logical_width, logical_height});

    m_tree.disable_thickness_factor();
    //    m_tree.insert(left_paddle_id, m_left.position, m_left.position + paddle_size);
    //    m_tree.insert(right_paddle_id, m_right.position, m_right.position +
    //    paddle_size); m_tree.insert(ball_id,
    //                  m_ball.position,
    //                  m_ball.position + float2{ball_radius, ball_radius});
  }

  void handle_input(const rune::input& input) override
  {
    if (input.keyboard.just_released(cen::keycodes::escape))
    {
      m_quit = true;
      return;
    }

    const auto leftUp = input.keyboard.is_pressed(cen::scancodes::w);
    const auto leftDown = input.keyboard.is_pressed(cen::scancodes::s);
    const auto rightUp = input.keyboard.is_pressed(cen::scancodes::up);
    const auto rightDown = input.keyboard.is_pressed(cen::scancodes::down);

    if (leftUp && leftDown || !leftUp && !leftDown)
    {
      //      m_left.velocity.reset();
    }
    else if (leftUp)
    {
      //      m_left.velocity.y = -paddle_speed;
    }
    else /*if (leftDown)*/
    {
      //      m_left.velocity.y = paddle_speed;
    }

    if (rightUp && rightDown || !rightUp && !rightDown)
    {
      //      m_right.velocity.reset();
    }
    else if (rightUp)
    {
      //      m_right.velocity.y = -paddle_speed;
    }
    else /*if (rightDown)*/
    {
      //      m_right.velocity.y = paddle_speed;
    }
  }

  void tick(const rune::delta_time dt) override
  {
    for (auto&& [entity, movable] : m_registry.view<comp::movable>().each())
    {
      movable.position += movable.velocity * dt;
      m_tree.set_position(entity, movable.position);
    }

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
};

using engine_base = rune::engine<pong_game>;

class pong_engine final : public engine_base
{
 public:
  pong_engine() : engine_base{}
  {
    get_window().set_size({400, 300});
  }
};

}  // namespace

RUNE_IMPLEMENT_MAIN_WITH_ENGINE(pong_engine)
