#ifndef RUNE_CORE_RUNE_ERROR_HPP
#define RUNE_CORE_RUNE_ERROR_HPP

#include <exception>  // exception

#include "../aliases/czstring.hpp"

namespace rune {

/// \addtogroup core
/// \{

class rune_error final : public std::exception
{
 public:
  explicit rune_error(const czstring what) noexcept : m_what{what}
  {}

  [[nodiscard]] auto what() const noexcept -> czstring override
  {
    return m_what;
  }

 private:
  czstring m_what{"n/a"};
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_RUNE_ERROR_HPP
