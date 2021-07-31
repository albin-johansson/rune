#ifndef RUNE_IO_CSV_HPP
#define RUNE_IO_CSV_HPP

#include <string>  // string
#include <vector>  // vector

#include "rune_api.hpp"

namespace rune {

/// \addtogroup io
/// \{

/**
 * \brief Parses a string of comma-separated values (CSV).
 *
 * \param csv the string that holds the comma separated values.
 *
 * \return the parsed tokens.
 *
 * \since 0.1.0
 */
RUNE_FUNCTION auto parse_csv(const std::string& csv) -> std::vector<std::string>;

/// \} End of group io

}  // namespace rune

#endif  // RUNE_IO_CSV_HPP
