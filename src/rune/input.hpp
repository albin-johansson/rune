#pragma once

#include <centurion.hpp>  // keyboard, mouse

namespace rune {

struct input final
{
  cen::keyboard keyboard;
  cen::mouse mouse;
};

}  // namespace rune
