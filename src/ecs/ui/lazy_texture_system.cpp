#include "ecs/ui/lazy_texture_system.hpp"

#include <centurion.hpp>  // texture, surface

namespace rune::ui {

auto make_lazy_texture(entt::registry& registry, const str image)
    -> ui_lazy_texture::entity
{
  const auto entity = ui_lazy_texture::entity{registry.create()};

  registry.emplace<ui_lazy_texture>(entity, cen::surface{image});

  return entity;
}

namespace detail {

void update_lazy_textures(const entt::registry& registry, graphics& gfx)
{
  for (auto&& [entity, lazy] : registry.view<ui_lazy_texture>().each())
  {
    if (!lazy.texture)
    {
      lazy.texture = cen::texture{gfx.renderer(), lazy.source};
    }
  }
}

}  // namespace detail
}  // namespace rune::ui
