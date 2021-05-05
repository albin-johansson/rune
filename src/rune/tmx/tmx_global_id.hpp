#pragma once

#include <nenya.hpp>  // strong_type

#include "../aliases/integers.hpp"

namespace rune {

namespace tags {
struct tmx_global_id_tag;
}

using tmx_global_id = nenya::strong_type<uint, tags::tmx_global_id_tag>;

}  // namespace rune
