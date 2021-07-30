#ifndef RUNE_API_HPP
#define RUNE_API_HPP

#ifdef _WIN32
#ifdef RUNE_EXPORT
#define RUNE_API __declspec(dllexport)
#else
#define RUNE_API __declspec(dllimport)
#endif  // RUNE_EXPORT
#endif  // _WIN32

#define RUNE_FUNCTION [[nodiscard]] RUNE_API

#endif  // RUNE_API_HPP
