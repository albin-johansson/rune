#pragma once

#include <nenya.hpp>

namespace rune {
namespace tags {
struct local_id;
}

using tmx_local_id = nenya::strong_type<int, tags::local_id>;

}  // namespace rune
