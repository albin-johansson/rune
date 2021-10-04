# Rune

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Language](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![version](https://img.shields.io/github/v/release/albin-johansson/rune)](https://github.com/albin-johansson/rune/releases)
[![doxygen](https://img.shields.io/badge/doxygen-stable-blue)](https://albin-johansson.github.io/rune/)
[![CI: Windows](https://github.com/albin-johansson/rune/actions/workflows/windows.yml/badge.svg?branch=dev)](https://github.com/albin-johansson/rune/actions/workflows/windows.yml)
[![CI: Ubuntu](https://github.com/albin-johansson/rune/actions/workflows/ubuntu.yml/badge.svg?branch=dev)](https://github.com/albin-johansson/rune/actions/workflows/ubuntu.yml)

A modern C++ game framework for 2D games, written in C++20.

## Background

This framework was originally developed from the custom engine built for the
[Wanderer](https://github.com/albin-johansson/wanderer) indie game, developed by me.

## Features

The following is a (non-exhaustive) list of the features of Rune.

* Header-only
* Simple framework with very little performance overhead
* Semi-fixed delta time game loop implementation
* Efficient 2D vector implementation
* Performant utilities and data structures
    * `static_vector`: a contiguous container with an API of a dynamic array, with static storage
    * `vector_map`: an associative container that stores its key/value-pairs contiguously
    * `stack_resource`:
    * `from_string()`
* AABB collision detection framework
* Random number generation utilities

## Example

```C++
#include <entt.hpp>
#include <centurion.hpp>
#include <rune.hpp>

struct FooEvent final 
{
  int foo{};
  int bar{};
};

class AwesomeGame final
{
 public:
  AwesomeGame()
  {
    mEngine.on_start<&AwesomeGame::on_start>(this); // Called once before the game loop starts running
    mEngine.on_exit<&AwesomeGame::on_exit>(this);   // Called once just before shutdown
    
    /* Register the various systems, you can register several systems to these different categories. 
       Call order: input systems -> logic systems -> render systems */
    mEngine.add_input_system<&AwesomeGame::update_input>(this);
    mEngine.add_logic_system<&AwesomeGame::update_logic>(this);
    mEngine.add_render_system<&AwesomeGame::render>(this);
    
    auto& registry = mEngine.registry();
    registry.set<cen::renderer>(mEngine.window());
    
    auto& dispatcher = mEngine.dispatcher();
    dispatcher.sink<FooEvent>().connect<&AwesomeGame::on_foo>(this);
  }
  
  void run()
  {
    mEngine.run();
  }
  
 private:
  rune::engine mEngine;
  
  void on_start() 
  {
    /* Prepare the game just before the main loop starts running */
  }
  
  void on_exit() 
  {
    /* Prepare for imminent shutdown of the game, e.g. by creating an exit save */
  }
  
  /* Input systems can omit the dispatcher parameter */
  void update_input(entt::registry& registry, entt::dispatcher& dispatcher)
  {
    const auto& keyboard = mEngine.keyboard();
    const auto& mouse = mEngine.mouse();
    
    /* Handle input state, input systems are always called before logic systems. */
  }
  
  /* Logic systems can omit the dispatcher and delta time parameters */
  void update_logic(entt::registry& registry, entt::dispatcher& dispatcher, float dt)
  {
    /* Update game logic */
  }
  
  void render(entt::registry& registry)
  {
    auto& renderer = registry.ctx<cen::renderer>();
    renderer.clear_with(cen::colors::black);
    
    /* Miscellaneous rendering code... */
    
    renderer.present();
  }
  
  void on_foo(const FooEvent& event)
  {
    /* Handle the event... */
  }
};

int main(int, char**)
{
  cen::library centurion;
  
  AwesomeGame game;
  game.run();
  
  return 0;
}
```

## Dependencies

The following table shows the dependencies of the Rune library. Note, SDL_ttf is the only mandatory
SDL extension library for use of Rune, see the Centurion documentation for more details regarding
extension libraries.

| Dependency          | Source                                                                                   | Version |
| ------------------- | ---------------------------------------------------------------------------------------- | ------- |
| Centurion           | [www.github.com/albin-johansson/centurion](https://github.com/albin-johansson/centurion) | 6.2.0   |
| Nenya               | [www.github.com/albin-johansson/nenya](https://github.com/albin-johansson/nenya)         | 0.1.0   |
| EnTT                | [www.github.com/skypjack/entt](https://github.com/skypjack/entt)                         | 3.8.1   |
| JSON for Modern C++ | [www.github.com/nlohmann/json](https://github.com/nlohmann/json)                         | 3.9.1   |

## Documentation

Detailed documentation and examples for the latest stable release can be
found [here](https://albin-johansson.github.io/centurion/).
