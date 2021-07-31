#ifndef RUNE_ECS_UI_LINE_SYSTEM_HPP
#define RUNE_ECS_UI_LINE_SYSTEM_HPP

#include <centurion.hpp>  // color
#include <entt.hpp>       // registry

#include "core/graphics.hpp"
#include "ecs/ui/ui_line.hpp"
#include "ecs/ui/ui_menu.hpp"
#include "ecs/ui/ui_position.hpp"
#include "rune_api.hpp"

namespace rune {

/// \addtogroup ecs
/// \{

/**
 * \struct ui_line_cfg
 *
 * \brief Configuration used when creating line entities.
 *
 * \see `ui_line`
 * \see `ui::make_line()`
 *
 * \since 0.1.0
 */
struct ui_line_cfg final
{
  ui_position start;                     ///< The line start position.
  ui_position end;                       ///< The line end position.
  cen::color color{cen::colors::white};  ///< The color of the line.
};

/// \} End of group ecs

namespace ui {

/// \addtogroup ecs
/// \{

/// \name Factory functions
/// \{

/**
 * \brief Creates a new line entity and returns it.
 *
 * \details The created entity will feature the following components.
 * - `ui_line`
 * - `ui_foreground`
 * - `in_menu`
 *
 * \param registry the registry to which a line entity will be added.
 * \param menu the host menu entity.
 * \param cfg the line configuration that will be used.
 *
 * \return the created line entity.
 *
 * \see `ui_line_cfg`
 *
 * \since 0.1.0
 */
RUNE_FUNCTION auto make_line(entt::registry& registry,
                             ui_menu::entity menu,
                             ui_line_cfg cfg) -> ui_line::entity;

/// \} End of factory functions

/// \} End of group ecs

/// \cond FALSE

namespace detail {

RUNE_API void render_lines(const entt::registry& registry, graphics& gfx);

}  // namespace detail

/// \endcond

}  // namespace ui
}  // namespace rune

#endif  // RUNE_ECS_UI_LINE_SYSTEM_HPP
