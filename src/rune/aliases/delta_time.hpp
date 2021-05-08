#ifndef RUNE_ALIASES_DELTA_TIME_HPP
#define RUNE_ALIASES_DELTA_TIME_HPP

namespace rune {

#ifndef RUNE_DELTA_TIME_TYPE
#define RUNE_DELTA_TIME_TYPE float
#endif  // RUNE_DELTA_TIME_TYPE

/**
 * \brief The type used for delta time values, e.g. in the `tick()` function of game class
 * implementations.
 *
 * \details By default, this alias is equivalent to `float`.
 *
 * \ingroup core
 *
 * \see `RUNE_DELTA_TIME_TYPE`
 */
using delta_time = RUNE_DELTA_TIME_TYPE;

}  // namespace rune

#endif  // RUNE_ALIASES_DELTA_TIME_HPP
