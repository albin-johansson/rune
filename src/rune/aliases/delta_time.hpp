#ifndef RUNE_ALIASES_DELTA_TIME_HPP
#define RUNE_ALIASES_DELTA_TIME_HPP

#include <nenya.hpp>  // strong_type

namespace rune {

/// \cond FALSE
namespace tags {
struct delta_time_tag;
}  // namespace tags
/// \endcond

/// \addtogroup core
/// \{

/**
 * \def RUNE_DELTA_TIME_UNDERLYING_TYPE
 *
 * \brief The underlying type of the `delta_time` strong type.
 *
 * \note The underlying should be a floating-point type, i.e. `float`, `double` or
 * possibly `long double`.
 */
#ifndef RUNE_DELTA_TIME_UNDERLYING_TYPE
#define RUNE_DELTA_TIME_UNDERLYING_TYPE float
#endif  // RUNE_DELTA_TIME_UNDERLYING_TYPE

/**
 * \brief The type used for delta time values, e.g. in the `tick()` function of game class
 * implementations.
 *
 * \see `RUNE_DELTA_TIME_UNDERLYING_TYPE`
 */
using delta_time =
    nenya::strong_type<RUNE_DELTA_TIME_UNDERLYING_TYPE, tags::delta_time_tag>;

/// \} End of group core

}  // namespace rune

#endif  // RUNE_ALIASES_DELTA_TIME_HPP
