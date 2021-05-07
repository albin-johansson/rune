#pragma once

#include <centurion.hpp>  // keyboard, mouse

namespace rune {

/// \addtogroup core
/// \{

struct input final
{
  cen::keyboard keyboard;
  cen::mouse mouse;
};

/// \} End of group core

}  // namespace rune
