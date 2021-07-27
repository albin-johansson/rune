# rune

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

* Distributed as a single header file
* Simple framework with little to no performance overhead, e.g. no virtual function calls
* Game loop implementation
* Compile-time configuration
* Efficient 2D vector implementation
* AABB collision detection
* [Tiled](https://github.com/mapeditor/tiled) JSON map parsing
* `.ini` support.
* Performant utilities and data structures, e.g. `static_vector`, `vector_map`, `stack_resource`, `from_string()`, etc
* Random number generation utilities
* Serialization support, based on the Cereal API

## Dependencies

The following table shows the dependencies of the Rune library. Note, SDL_ttf is the only mandatory SDL extension library for use of Rune, see the Centurion documentation for more details regarding extension libraries.

| Dependency          | Source                                                                                   | Version |
| ------------------- | ---------------------------------------------------------------------------------------- | ------- |
| Centurion           | [www.github.com/albin-johansson/centurion](https://github.com/albin-johansson/centurion) | 6.2.0   |
| Nenya               | [www.github.com/albin-johansson/nenya](https://github.com/albin-johansson/nenya)         | 0.1.0   |
| EnTT                | [www.github.com/skypjack/entt](https://github.com/skypjack/entt)                         | 3.8.0   |
| JSON for Modern C++ | [www.github.com/nlohmann/json](https://github.com/nlohmann/json)                         | 3.9.1   |

## Documentation

Detailed documentation and examples for the latest stable release can be found [here](https://albin-johansson.github.io/centurion/).
