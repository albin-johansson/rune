/// \defgroup core Core
/// \brief Core components of the library.

/// \defgroup tmx TMX
/// \brief Responsible for parsing Tiled JSON map files.
/// \details The main API for working with TMX maps is the `parse_tmx()` function, which
/// takes a file path to a JSON file and returns a `tmx_map` instance that corresponds to
/// the map. Most of the structs with `tmx_` prefixes are not meant to be instantiated
/// directly in client code, instead most data should be used to read information about a
/// save file, that is subsequently converted to the representations used in your game.
/// \code{cpp}
/// void foo()
/// {
///   const auto map = rune::parse_tmx("resources/map.json");
///   // Process the map contents...
/// }
/// \endcode
///
/// \details There are plenty of helper functions for extracting information from the
/// parsed map data, that are located in the `rune::tmx` namespace. Particularly when
/// working with properties and layers.
/// \code{cpp}
/// void foo()
/// {
///   const auto map = rune::parse_tmx("resources/map.json");
///   for (const auto& layer : map.layers)
///   {
///     if (const auto* tileLayer = rune::tmx::try_get_tile_layer(layer))
///     {
///       // The current layer is a tile layer!
///     }
///
///     if (rune::tmx::contains(layer.properties, "bar"))
///     {
///       // The layer has a property named "bar"
///     }
///
///     if (const auto* property = rune::tmx::try_get(layer.properties, "hello"))
///     {
///       // Try to find a property named "hello"
///     }
///
///     // Read value of property "abc" as an integer, throwing an error if it isn't one
///     const int abc = rune::tmx::get_int(layer.properties, "abc");
///   }
/// }
/// \endcode

/// \defgroup math Math
/// \brief Contains numeric and mathematical components.

/// \defgroup io IO
/// \brief Filesystem utilities related to JSON, Ini, etc.
