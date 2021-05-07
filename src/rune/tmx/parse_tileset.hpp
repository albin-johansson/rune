#pragma once

#include <filesystem>  // path
#include <fstream>     // ifstream
#include <json.hpp>    // json
#include <string>      // string

#include "../io/json_utils.hpp"
#include "tmx_global_id.hpp"
#include "tmx_tileset.hpp"

namespace rune::tmx {
namespace detail {

void parse_tileset(const nlohmann::json& json, tmx_tileset& tileset)
{
  json.at("tilewidth").get_to(tileset.tile_width);
  json.at("tileheight").get_to(tileset.tile_height);
  json.at("tilecount").get_to(tileset.tile_count);
  json.at("columns").get_to(tileset.column_count);
  json.at("imagewidth").get_to(tileset.image_width);
  json.at("imageheight").get_to(tileset.image_height);
  json.at("margin").get_to(tileset.margin);
  json.at("spacing").get_to(tileset.spacing);
  json.at("image").get_to(tileset.image);
  json.at("name").get_to(tileset.name);

  get_if_exists(json, "tiledversion", tileset.tiled_version);
  get_if_exists(json, "version", tileset.json_version);
  get_if_exists(json, "backgroundcolor", tileset.background);
  get_if_exists(json, "transparentcolor", tileset.transparent);
  // TODO get_if_exists(json, "grid", tileset.grid);
  // TODO get_if_exists(json, "tileoffset", tileset.tile_offset);

  fill_if_exists(json, "tiles", tileset.tiles);
  fill_if_exists(json, "terrains", tileset.terrains);
  fill_if_exists(json, "wangsets", tileset.wang_sets);
  fill_if_exists(json, "properties", tileset.properties);
}

}  // namespace detail

[[nodiscard]] inline auto parse_tileset(const std::filesystem::path& path) -> tmx_tileset
{
  const auto read = [](const std::filesystem::path& file) {
    std::ifstream stream{file};

    nlohmann::json data;
    stream >> data;

    return data;
  };

  const auto json = read(path);
  tmx_tileset tileset;

  tileset.first_id = tmx_global_id{json.at("firstgid").get<tmx_global_id::value_type>()};
  if (const auto it = json.find("source"); it != json.end())
  {
    // External
    tileset.external_source = it->get<std::string>();

    const auto source = path.parent_path() / tileset.external_source;
    const auto external = read(source);

    detail::parse_tileset(external, tileset);
  }
  else
  {
    // Embedded
    detail::parse_tileset(json, tileset);
  }

  return tileset;
}

}  // namespace rune::tmx
