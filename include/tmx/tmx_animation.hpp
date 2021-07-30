#ifndef RUNE_TMX_ANIMATION_HPP
#define RUNE_TMX_ANIMATION_HPP

#include <chrono>  // milliseconds
#include <vector>  // vector

#include "../aliases/json_type.hpp"
#include "rune_api.hpp"
#include "tmx_local_id.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_frame final
{
  tmx_local_id tile{};
  std::chrono::milliseconds duration{};
};

struct tmx_animation final
{
  std::vector<tmx_frame> frames;
};

RUNE_API void from_json(const json_type& json, tmx_frame& frame);
RUNE_API void from_json(const json_type& json, tmx_animation& animation);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_ANIMATION_HPP
