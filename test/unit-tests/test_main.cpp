#include <gtest/gtest.h>

#include <centurion.hpp>

int main(int argc, char** argv)
{
  // Don't initialize audio because linux (-.-)
  cen::config cfg;
  cfg.initMixer = false;
  cfg.coreFlags = SDL_INIT_EVERYTHING & ~SDL_INIT_AUDIO;

  cen::library centurion{cfg};

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}