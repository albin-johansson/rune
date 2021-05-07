#ifndef RUNE_CORE_GRAPHICS_HPP
#define RUNE_CORE_GRAPHICS_HPP

#include <centurion.hpp>  // window, renderer, texture, font_cache, pixel_format
#include <cstddef>        // size_t
#include <string>         // string
#include <unordered_map>  // unordered_map
#include <utility>        // forward
#include <vector>         // vector

namespace rune {

/// \addtogroup core
/// \{

#ifndef RUNE_GRAPHICS_RENDERER_FLAGS
#define RUNE_GRAPHICS_RENDERER_FLAGS cen::renderer::default_flags()
#endif  // RUNE_GRAPHICS_RENDERER_FLAGS

class graphics
{
 public:
  using size_type = std::size_t;
  using texture_index = size_type;
  using texture_id = size_type;
  using font_id = size_type;

  template <typename T>
  explicit graphics(const cen::basic_window<T>& window)
      : m_renderer{window, RUNE_GRAPHICS_RENDERER_FLAGS}
      , m_format{window.get_pixel_format()}
  {}

  virtual ~graphics() noexcept = default;

  /// \name Texture loading
  /// \{

  auto load(const texture_id id, const std::string& path) -> texture_index
  {
    if (const auto it = m_indices.find(id); it != m_indices.end())
    {
      return it->second;
    }
    else
    {
      const auto index = m_textures.size();

      m_textures.emplace_back(m_renderer, path);
      m_indices.try_emplace(id, index);

      return index;
    }
  }

  /// \} End of texture loading

  void set_blend_mode(const cen::blend_mode mode)
  {
    m_renderer.set_blend_mode(mode);
  }

  template <typename... Args>
  void emplace_font(const size_type id, Args&&... args)
  {
    m_renderer.emplace_font(id, std::forward<Args>(args)...);
  }

  template <typename... Args>
  void emplace_cache(const font_id id, Args&&... args)
  {
    m_caches.try_emplace(id, std::forward<Args>(args)...);
  }

  [[nodiscard]] auto renderer() noexcept -> cen::renderer&
  {
    return m_renderer;
  }

  [[nodiscard]] auto renderer() const noexcept -> const cen::renderer&
  {
    return m_renderer;
  }

  [[nodiscard]] auto format() const noexcept -> cen::pixel_format
  {
    return m_format;
  }

 private:
  cen::renderer m_renderer;
  cen::pixel_format m_format;
  std::vector<cen::texture> m_textures;
  std::unordered_map<texture_id, texture_index> m_indices;
  std::unordered_map<size_type, cen::font_cache> m_caches;
};

/// \} End of group core

}  // namespace rune

#endif  // RUNE_CORE_GRAPHICS_HPP
