#ifndef RUNE_ECS_UI_UI_SYSTEM_HPP
#define RUNE_ECS_UI_UI_SYSTEM_HPP

#include <entt.hpp>  // registry, dispatcher

#include "core/graphics.hpp"
#include "core/input.hpp"
#include "rune_api.hpp"

namespace rune::ui {

/// \addtogroup ecs
/// \{

/**
 * \brief Updates the state of the UI.
 *
 * \details This is the only UI-function you need to call in your `handle_input()`
 * function in order to use the UI framework.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param dispatcher the event dispatcher that will be used.
 * \param input the current input state.
 *
 * \since 0.1.0
 */
RUNE_API void update(entt::registry& registry,
                     entt::dispatcher& dispatcher,
                     const input& input);

/**
 * \brief Renders the currently active UI components.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param gfx the graphics context that will be used for rendering.
 *
 * \see `debug()`
 *
 * \since 0.1.0
 */
RUNE_API void render(const entt::registry& registry, graphics& gfx);

/**
 * \brief Renders debug information for the currently active UI components.
 *
 * \details This function is intended to be used to aid debugging UI aspects such as
 * layouts or alignments.
 *
 * \param registry the registry that contains all of the UI entities.
 * \param gfx the graphics context that will be used for rendering.
 *
 * \see `render()`
 *
 * \since 0.1.0
 */
RUNE_API void debug(const entt::registry& registry, graphics& gfx);

/// \} End of group ecs

}  // namespace rune::ui

#endif  // RUNE_ECS_UI_UI_SYSTEM_HPP
