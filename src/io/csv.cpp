#include "io/csv.hpp"

#include <sstream>  // istringstream
#include <string>   // getline
#include <utility>  // move

namespace rune {

auto parse_csv(const std::string& csv) -> std::vector<std::string>
{
  std::vector<std::string> tokens;

  std::istringstream stream{csv};
  std::string token;

  while (std::getline(stream, token, ','))
  {
    tokens.push_back(std::move(token));
    token.clear();
  }

  return tokens;
}

}  // namespace rune
