# rune

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Language](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![CI: Windows](https://github.com/albin-johansson/rune/actions/workflows/windows.yml/badge.svg?branch=dev)](https://github.com/albin-johansson/rune/actions/workflows/windows.yml)
[![CI: Ubuntu](https://github.com/albin-johansson/rune/actions/workflows/ubuntu.yml/badge.svg?branch=dev)](https://github.com/albin-johansson/rune/actions/workflows/ubuntu.yml)

A modern C++ game framework for 2D games, written in C++20.

## Background

This framework was originally developed from the custom engine built for the
[Wanderer](https://github.com/albin-johansson/wanderer) indie game, developed by me. This framework
is also closely tied to the [Centurion](https://github.com/albin-johansson/centurion) library.

## Features

* Distributed as a single header file.
* Simple framework with little to no performance overhead, e.g. no virtual function calls.
* Configurable at compile time.
* Efficient 2D vector implementation.
* AABB collision detection.
* [Tiled](https://github.com/mapeditor/tiled) JSON map parsing.
* `.ini` parsing support.
* Performant utilities, e.g. `static_vector`, `vector_map`, `stack_resource`, `to_string()`, etc.
* Relevant components have serialization support, based on the Cereal library.

## Example

```C++
#define RUNE_MAX_TICK_RATE 60.0  // This is not required, the default is 120.0
#include <rune.hpp>
#include <centurion.hpp>

/* Game classes must be either default-constructible or provide 
   a constructor that accepts a reference to a graphics context. */
class Game
{
 public:
  explicit Game(rune::graphics& gfx);
  
  // [Optional] Called just after the game class has been constructed. 
  void init(rune::graphics& gfx);
  
  // [Optional] Called just before the game starts running
  void on_start();

  // [Optional] Called just before the game quits
  void on_exit();

  // [Mandatory] Handles user input
  void handle_input(const rune::input& input);

  // [Mandatory] Updates the game logic by one step
  void tick(rune::delta_time dt);

  // [Mandatory] Renders the game
  void render(rune::graphics& gfx);

  // [Mandatory] Return true to quit the game
  [[nodiscard]] auto should_quit() const -> bool;
};

int main(int, char**) 
{
  cen::library centurion;
  rune::engine<Game> engine;
  return engine.run();
}
```

## Dependencies

* [Centurion](https://github.com/albin-johansson/centurion)
* [EnTT](https://github.com/skypjack/entt)
* [JSON](https://github.com/nlohmann/json)
