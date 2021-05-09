#ifndef RUNE_TMX_TEXT_HPP
#define RUNE_TMX_TEXT_HPP

#include <json.hpp>  // json
#include <string>    // string

#include "tmx_color.hpp"
#include "tmx_halign.hpp"
#include "tmx_valign.hpp"

namespace rune {

/// \addtogroup tmx
/// \{

struct tmx_text final
{
  std::string text;
  std::string family{"sans-serif"};
  tmx_color color;
  tmx_halign horizontal_alignment{tmx_halign::left};
  tmx_valign vertical_alignment{tmx_valign::top};
  int pixel_size{16};
  bool bold{};
  bool italic{};
  bool kerning{true};
  bool strikeout{};
  bool underline{};
  bool wrap{};
};

void from_json(const nlohmann::json& json, tmx_text& text);

/// \} End of group tmx

}  // namespace rune

#endif  // RUNE_TMX_TEXT_HPP
