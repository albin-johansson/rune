#ifndef RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
#define RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP

#include <centurion.hpp>  // scan_code, key_mod
#include <entt.hpp>       // registry, dispatcher

#include "aliases/integers.hpp"
#include "core/input.hpp"
#include "rune_api.hpp"
#include "ui_key_bind.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_key_bind_cfg
 *
 * \brief Configuration used when creating key bind entities.
 *
 * \see `ui_key_bind`
 * \see `ui::make_key_bind()`
 *
 * \since 0.1.0
 */
struct ui_key_bind_cfg final
{
  uint32 id{};                                 ///< User-defined identifier.
  cen::scan_code key;                          ///< The associated key.
  cen::key_mod modifiers{cen::key_mod::none};  ///< The required key modifiers.
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new key bind entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_key_bind`
 *
 * \param registry the registry to which a key bind entity will be added.
 * \param cfg the key bind configuration that will be used.
 *
 * \return the created key bind entity.
 *
 * \since 0.1.0
 */
RUNE_FUNCTION auto make_key_bind(entt::registry& registry, const ui_key_bind_cfg cfg)
    -> ui_key_bind::entity;

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

RUNE_API void update_key_binds(entt::registry& registry,
                               entt::dispatcher& dispatcher,
                               const input& input);

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_KEY_BIND_SYSTEM_HPP
