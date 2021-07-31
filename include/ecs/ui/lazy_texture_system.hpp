#ifndef RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP
#define RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP

#include <entt.hpp>  // registry

#include "aliases/str.hpp"
#include "core/graphics.hpp"
#include "ecs/ui/ui_lazy_texture.hpp"
#include "rune_api.hpp"

namespace rune::ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new lazy texture entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_lazy_texture`
 *
 * \param registry the registry to which a lazy texture entity will be added.
 * \param image the file path of the source image.
 *
 * \return the created lazy texture entity.
 *
 * \since 0.1.0
 */
RUNE_FUNCTION auto make_lazy_texture(entt::registry& registry, str image)
    -> ui_lazy_texture::entity;

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

RUNE_API void update_lazy_textures(const entt::registry& registry, graphics& gfx);

}  // namespace detail

/// \endcond

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_LAZY_TEXTURE_SYSTEM_HPP
