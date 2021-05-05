#pragma once

#include <nenya.hpp>  // strong_type

namespace rune {

namespace tags {
struct tmx_local_id_tag;
}  // namespace tags

using tmx_local_id = nenya::strong_type<int, tags::tmx_local_id_tag>;

}  // namespace rune
