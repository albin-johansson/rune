#pragma once

#include <json.hpp>  // json
#include <string>    // string

#include "../json_utils.hpp"
#include "tmx_color.hpp"

namespace rune {

enum class tmx_halign
{
  center,
  right,
  left,
  justify
};

enum class tmx_valign
{
  center,
  top,
  bottom
};

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

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_halign,
                             {{tmx_halign::center, "center"},
                              {tmx_halign::right, "right"},
                              {tmx_halign::left, "left"},
                              {tmx_halign::justify, "justify"}})

NLOHMANN_JSON_SERIALIZE_ENUM(tmx_valign,
                             {{tmx_valign::center, "center"},
                              {tmx_valign::top, "top"},
                              {tmx_valign::bottom, "bottom"}})

inline void from_json(const nlohmann::json& json, tmx_text& text)
{
  json.at("text").get_to(text.text);

  get_if_exists(json, "fontfamily", text.family);
  get_if_exists(json, "halign", text.horizontal_alignment);
  get_if_exists(json, "valign", text.vertical_alignment);
  get_if_exists(json, "pixelsize", text.pixel_size);
  get_if_exists(json, "bold", text.bold);
  get_if_exists(json, "italic", text.italic);
  get_if_exists(json, "kerning", text.kerning);
  get_if_exists(json, "strikeout", text.strikeout);
  get_if_exists(json, "underline", text.underline);
  get_if_exists(json, "wrap", text.wrap);

  if (const auto it = json.find("color"); it != json.end())
  {
    text.color = tmx::make_color(it->get<std::string>());
  }
}

}  // namespace rune