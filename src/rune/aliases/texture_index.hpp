#ifndef RUNE_ALIASES_TEXTURE_INDEX_HPP
#define RUNE_ALIASES_TEXTURE_INDEX_HPP

#include <cstddef>    // size_t
#include <nenya.hpp>  // strong_type

namespace rune {

/// \cond FALSE
namespace tags {
struct texture_index_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \typedef texture_index
 *
 * \brief Strong type for texture indices, used by the `graphics` class.
 */
using texture_index = nenya::strong_type<std::size_t, tags::texture_index_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_TEXTURE_INDEX_HPP
