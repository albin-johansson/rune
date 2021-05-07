#ifndef RUNE_TMX_GLOBAL_ID_HPP
#define RUNE_TMX_GLOBAL_ID_HPP

#include <nenya.hpp>  // strong_type

#include "../aliases/integers.hpp"

namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_global_id_tag;
}
/// \endcond

using tmx_global_id = nenya::strong_type<uint, tags::tmx_global_id_tag>;

namespace tmx_literals {

[[nodiscard]] constexpr auto operator""_global(const ulonglong value) noexcept
    -> tmx_global_id
{
  return tmx_global_id{static_cast<tmx_global_id::value_type>(value)};
}

}  // namespace tmx_literals
}  // namespace rune

#endif  // RUNE_TMX_GLOBAL_ID_HPP
