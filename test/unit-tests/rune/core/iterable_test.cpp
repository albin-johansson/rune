#include "core/iterable.hpp"

#include <map>     // map
#include <string>  // string
#include <vector>  // vector

static_assert(rune::iterable<std::vector<int>, int>);
static_assert(!rune::iterable<std::vector<int>, std::string>);

static_assert(rune::iterable<std::map<int, float>, std::pair<int, float>>);