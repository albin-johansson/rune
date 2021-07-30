#include "io/json_utils.hpp"

#include <cassert>  // assert
#include <fstream>  // ifstream

namespace rune {

auto read_json(const std::filesystem::path& file) -> json_type
{
  assert(file.extension() == ".json");
  std::ifstream stream{file};

  json_type json;
  stream >> json;

  return json;
}

}  // namespace rune
