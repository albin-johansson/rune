#ifndef RUNE_TMX_LOCAL_ID_HPP
#define RUNE_TMX_LOCAL_ID_HPP

#include <nenya.hpp>  // strong_type

#include "../aliases/integers.hpp"

namespace rune {

/// \cond FALSE
namespace tags {
struct tmx_local_id_tag;
}  // namespace tags
/// \endcond

using tmx_local_id = nenya::strong_type<int, tags::tmx_local_id_tag>;

namespace tmx_literals {

[[nodiscard]] constexpr auto operator""_local(const ulonglong value) noexcept
    -> tmx_local_id
{
  return tmx_local_id{static_cast<tmx_local_id::value_type>(value)};
}

}  // namespace tmx_literals
}  // namespace rune

#endif  // RUNE_TMX_LOCAL_ID_HPP
