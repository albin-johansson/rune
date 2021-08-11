/**
 * \defgroup core Core
 *
 * \brief Contains core components, used throughout the library.
 */

/**
 * \defgroup io IO
 *
 * \brief Filesystem utilities related to JSON, Ini, etc.
 */

/// \addtogroup io
/// \{

/**
 * \defgroup tmx TMX
 *
 * \brief Responsible for parsing Tiled JSON map files.
 *
 * \details The main API for working with TMX maps is the `parse_tmx()` function, which
 * takes a file path to a JSON file and returns a `tmx_map` instance that corresponds to
 * the map. Most of the structs with `tmx_` prefixes are not meant to be instantiated
 * directly in client code, instead most data should be used to read information about a
 * save file, that is subsequently converted to the representations used in your game.
 *
 * \code{cpp}
 * void foo()
 * {
 *   const auto map = rune::parse_tmx("resources/map.json");
 *   // Process the map contents...
 * }
 * \endcode
 *
 * \details There are plenty of helper functions for extracting information from the
 * parsed map data, that are located in the `rune::tmx` namespace. Particularly when
 * working with properties and layers.
 *
 * \code{cpp}
 * const auto map = rune::parse_tmx("resources/map.json");
 * for (const auto& layer : map.layers)
 * {
 *   if (const auto* tileLayer = rune::tmx::try_get_tile_layer(layer))
 *   {
 *     // The current layer is a tile layer!
 *   }
 *
 *   if (rune::tmx::contains(layer.properties, "bar"))
 *   {
 *     // The layer has a property named "bar"
 *   }
 *
 *   if (const auto* property = rune::tmx::try_get(layer.properties, "hello"))
 *   {
 *     // Try to find a property named "hello"
 *   }
 *
 *   // Read value of property "abc" as an integer, throwing an error if it isn't one
 *   const int abc = rune::tmx::get_int(layer.properties, "abc");
 * }
 * \endcode
 */

/// \} End of group io

/**
 * \defgroup math Math
 *
 * \brief Contains numeric and mathematical components.
 */

/**
 * \defgroup containers Containers
 *
 * \brief Contains performant generic data structures and utilities.
 *
 * \note The AABB framework was based on the [AABBCC](https://github.com/lohedges/aabbcc)
 * library, written by Lester Hedges, which uses the Zlib license.
 */

/**
 * \defgroup ecs ECS
 *
 * \brief Contains ECS utilities and a UI framework.
 *
 * \par Entity utilities
 * A few ECS utilities are provided for working with entities and strong types. The
 * `entity_type` alias template can be used to easily create a strong type with underlying
 * type `entt::entity`. This is used by all UI framework components to provide a public
 * member type `entity` that is meant to be used to represent entities associated with
 * themselves. Subsequently, use the `null()` and `nullify()` functions to create a null
 * entity identifier from strong entity types.
 *
 * \par UI framework
 * The ECS UI framework provides components and systems for handling menus, buttons,
 * checkboxes, labels, etc. The most important functions in the UI framework are
 * `rune::ui::update()` and `rune::ui::render()`, which (unsurprisingly) update and render
 * all of the UI systems, respectively. Functions related to the UI framework reside in
 * the `rune::ui` namespace.
 *
 * It's recommended to use the provided factory functions for creating UI entities, in
 * order to ensure that the entities feature the correct set of components. All UI
 * component names feature a `ui_` prefix.
 *
 * Events are used to enable users to observe changes to the UI. For example,
 * `button_pressed_event` is emitted whenever a button is pressed, etc.
 *
 * \code{cpp}
 * void handle_input(const rune::input& input) override
 * {
 *   // Updates the UI systems, call this early in your input handling function
 *   rune::ui::update(m_registry, m_dispatcher, input);
 *
 *   // ...
 * }
 *
 * void render(graphics_type& gfx) const override
 * {
 *    // ...
 *
 *    // Renders all active UI components, such as menus, buttons, labels, etc.
 *    rune::ui::render(m_registry, gfx);
 * }
 * \endcode
 */
