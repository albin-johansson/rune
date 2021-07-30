#ifndef RUNE_TMX_PARSE_TMX_HPP
#define RUNE_TMX_PARSE_TMX_HPP

#include <filesystem>  // path

#include "rune_api.hpp"
#include "tmx_map.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

/**
 * \brief Parses a Tiled JSON map file, and returns the contents.
 *
 * \details This function will not validate the specified JSON file. An invalid map file
 * will likely result in an exception being thrown due to parsing errors. However, there
 * are debug assertions that try to make it easier to detect errors and their cause,
 * compared to the generic exceptions from the JSON parser.
 *
 * \note The Tiled XML format is not supported.
 *
 * \todo Support all versions of the JSON format.
 *
 * \param path the file path to the Tiled JSON map file.
 *
 * \return the parsed Tiled map.
 */
RUNE_FUNCTION auto parse_tmx(const std::filesystem::path& path) -> tmx_map;

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_PARSE_TMX_HPP
