#ifndef RUNE_ECS_UI_BUTTON_SYSTEM_HPP
#define RUNE_ECS_UI_BUTTON_SYSTEM_HPP

#include <centurion.hpp>  // mouse, color
#include <entt.hpp>       // registry, dispatcher
#include <string>         // string

#include "aliases/font_id.hpp"
#include "aliases/integers.hpp"
#include "aliases/maybe.hpp"
#include "core/graphics.hpp"
#include "ecs/events/button_pressed_event.hpp"
#include "rune_api.hpp"
#include "ui_button.hpp"
#include "ui_menu.hpp"
#include "ui_position.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_button_cfg
 *
 * \brief Configuration used when creating button entities.
 *
 * \see `ui_button`
 * \see `ui::add_button()`
 * \see `ui::make_button()`
 *
 * \since 0.1.0
 */
struct ui_button_cfg final
{
  ui_position position;               ///< The position of the button.
  std::string text;                   ///< The button label text.
  uint32 id{};                        ///< User-defined button identifier.
  font_id font{};                     ///< The font used by the label.
  cen::color fg{cen::colors::white};  ///< The label color.
  bool shadow{};                      ///< Should the label feature a shadow?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Adds button components to an existing entity.
 *
 * \details The supplied entity will have the following components added to it.
 * - `ui_button`
 * - `ui_position`
 * - `ui_foreground`
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_button_cfg::shadow` is `true`)
 * - `in_menu`
 *
 * \param registry the registry in which the supplied entity belongs to.
 * \param menu the host menu entity.
 * \param entity the entity to which button components will be added.
 * \param cfg the button configuration that will be used.
 *
 * \since 0.1.0
 */
RUNE_API void add_button(entt::registry& registry,
                         ui_menu::entity menu,
                         entt::entity entity,
                         ui_button_cfg cfg);

/**
 * \brief Creates a new button entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_button`
 * - `ui_position`
 * - `ui_foreground`
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_button_cfg::shadow` is `true`)
 * - `in_menu`
 *
 * \param registry the registry to which a button entity will be added.
 * \param menu the host menu entity.
 * \param cfg the button configuration that will be used.
 *
 * \return the created button entity.
 *
 * \see `ui_button_cfg`
 * \see `add_button()`
 *
 * \since 0.1.0
 */
RUNE_FUNCTION auto make_button(entt::registry& registry,
                               ui_menu::entity menu,
                               ui_button_cfg cfg) -> ui_button::entity;

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

RUNE_FUNCTION auto query_button(entt::registry& registry,
                                entt::dispatcher& dispatcher,
                                ui_button::entity entity,
                                const cen::mouse& mouse) -> bool;

RUNE_FUNCTION auto update_button_hover(entt::registry& registry, const cen::mouse& mouse)
    -> maybe<ui_button::entity>;

RUNE_API void update_button_bounds(const entt::registry& registry, graphics& gfx);

RUNE_API void render_buttons(const entt::registry& registry, graphics& gfx);

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_BUTTON_SYSTEM_HPP
