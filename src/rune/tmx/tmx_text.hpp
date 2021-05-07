#ifndef RUNE_TMX_TEXT_HPP
#define RUNE_TMX_TEXT_HPP

#include <json.hpp>  // json
#include <string>    // string

#include "tmx_color.hpp"

namespace rune {

enum class tmx_halign
{
  center,
  right,
  left,
  justify
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_halign,
                             {{tmx_halign::center, "center"},
                              {tmx_halign::right, "right"},
                              {tmx_halign::left, "left"},
                              {tmx_halign::justify, "justify"}})

enum class tmx_valign
{
  center,
  top,
  bottom
};

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_valign,
                             {{tmx_valign::center, "center"},
                              {tmx_valign::top, "top"},
                              {tmx_valign::bottom, "bottom"}})

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

}  // namespace rune

#endif  // RUNE_TMX_TEXT_HPP
