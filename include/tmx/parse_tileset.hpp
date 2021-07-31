#ifndef RUNE_TMX_PARSE_TILESET_HPP
#define RUNE_TMX_PARSE_TILESET_HPP

#include "../aliases/json_type.hpp"
#include "rune_api.hpp"
#include "tmx_tileset.hpp"

namespace rune::tmx {

/// \addtogroup tmx
/// \{

RUNE_FUNCTION auto parse_tileset(const std::filesystem::path& directory,
                                 const json_type& json) -> tmx_tileset;

/// \} End of group tmx

}  // namespace rune::tmx

#endif  // RUNE_TMX_PARSE_TILESET_HPP
