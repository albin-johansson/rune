#ifndef RUNE_ECS_UI_LABEL_SYSTEM_HPP
#define RUNE_ECS_UI_LABEL_SYSTEM_HPP

#include <centurion.hpp>  // color, fpoint, texture
#include <entt.hpp>       // registry
#include <string>         // string

#include "aliases/font_id.hpp"
#include "core/graphics.hpp"
#include "ecs/null_entity.hpp"
#include "rune_api.hpp"
#include "ui_label.hpp"
#include "ui_menu.hpp"
#include "ui_position.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_label_cfg
 *
 * \brief Configuration used when creating label entities.
 *
 * \see `ui::add_label()`
 * \see `ui::make_label()`
 *
 * \since 0.1.0
 */
struct ui_label_cfg final
{
  ui_position position;                  ///< The position of the label.
  std::string text;                      ///< The label text.
  font_id font{};                        ///< The ID of the associated font.
  cen::color color{cen::colors::white};  ///< The label color.
  bool shadow{};                         ///< Does the label have a shadow?
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Adds label components to an existing entity.
 *
 * \details The supplied entity will have the following components added to it.
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_label_cfg::shadow` is `true`)
 * - `ui_position`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry in which the supplied entity belongs to.
 * \param menu the host menu entity.
 * \param entity the entity to which label components will be added.
 * \param cfg the label configuration that will be used.
 *
 * \see `make_label()`
 *
 * \since 0.1.0
 */
RUNE_API void add_label(entt::registry& registry,
                        ui_menu::entity menu,
                        entt::entity entity,
                        ui_label_cfg cfg);

/**
 * \brief Creates a new label entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_label`
 * - `ui_label_shadow` (if `ui_label_cfg::shadow` is `true`)
 * - `ui_position`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry to which a label entity will be added.
 * \param menu the host menu entity.
 * \param cfg the label configuration that will be used.
 *
 * \return the created label entity.
 *
 * \see `add_label()`
 *
 * \since 0.1.0
 */
RUNE_FUNCTION auto make_label(entt::registry& registry,
                              ui_menu::entity menu,
                              ui_label_cfg cfg) -> ui_label::entity;

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

RUNE_FUNCTION auto render_text(graphics& gfx,
                               const ui_label& label,
                               const cen::color& color) -> cen::texture;

RUNE_API void render_label(graphics& gfx,
                           const ui_label& label,
                           const cen::fpoint& position,
                           const cen::color& fg);

RUNE_API void render_shadow(graphics& gfx,
                            const ui_label& label,
                            const ui_label_shadow& shadow,
                            const cen::fpoint& position);

RUNE_API void render_labels(const entt::registry& registry, graphics& gfx);

RUNE_API void render_button_labels(const entt::registry& registry, graphics& gfx);

}  // namespace detail

/// \endcond

}  // namespace ui

}  // namespace rune

#endif  // RUNE_ECS_UI_LABEL_SYSTEM_HPP
