#include "tmx/tmx_text.hpp"

#include "io/json_utils.hpp"

namespace rune {

void from_json(const json_type& json, tmx_text& text)
{
  json.at("text").get_to(text.text);

  io::try_get_to(json, "fontfamily", text.family);
  io::try_get_to(json, "halign", text.horizontal_alignment);
  io::try_get_to(json, "valign", text.vertical_alignment);
  io::try_get_to(json, "pixelsize", text.pixel_size);
  io::try_get_to(json, "bold", text.bold);
  io::try_get_to(json, "italic", text.italic);
  io::try_get_to(json, "kerning", text.kerning);
  io::try_get_to(json, "strikeout", text.strikeout);
  io::try_get_to(json, "underline", text.underline);
  io::try_get_to(json, "wrap", text.wrap);

  if (const auto it = json.find("color"); it != json.end())
  {
    text.color = tmx::make_color(it->get<std::string>());
  }
}

}  // namespace rune
