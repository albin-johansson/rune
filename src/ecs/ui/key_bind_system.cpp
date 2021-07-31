#include "ecs/ui/key_bind_system.hpp"

#include "ecs/events/key_bind_triggered_event.hpp"

namespace rune::ui {

auto make_key_bind(entt::registry& registry, const ui_key_bind_cfg cfg)
    -> ui_key_bind::entity
{
  const auto entity = ui_key_bind::entity{registry.create()};

  auto& bind = registry.emplace<ui_key_bind>(entity);
  bind.id = cfg.id;
  bind.key = cfg.key;
  bind.modifiers = cfg.modifiers;

  return entity;
}

namespace detail {

void update_key_binds(entt::registry& registry,
                      entt::dispatcher& dispatcher,
                      const input& input)

{
  const auto state = cen::get_modifiers();

  // We don't care about these modifiers (they're never used in key binds)
  const auto subset = state & ~(cen::key_mod::num | cen::key_mod::caps);
  cen::set_modifiers(subset);

  for (auto&& [entity, bind] : registry.view<const ui_key_bind>().each())
  {
    if (input.keyboard.just_released(bind.key) &&
        cen::keyboard::is_only_active(bind.modifiers))
    {
      dispatcher.trigger<key_bind_triggered_event>(ui_key_bind::entity{entity}, bind.id);
      return;
    }
  }

  cen::set_modifiers(state);
}

}  // namespace detail
}  // namespace rune::ui
