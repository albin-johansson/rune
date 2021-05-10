#ifndef RUNE_CONTAINERS_AABB_NODE_HPP
#define RUNE_CONTAINERS_AABB_NODE_HPP

#include <concepts>  // floating_point
#include <cstddef>   // size_t
#include <optional>  // optional

#include "aabb.hpp"

namespace rune {

template <typename Key, std::floating_point Precision>
class aabb_node final
{
 public:
  using key_type = Key;
  using precision_type = Precision;
  using vector_type = basic_vector2<precision_type>;
  using aabb_type = basic_aabb<precision_type>;
  using index_type = std::size_t;

  std::optional<key_type> id;        ///< The user-provided ID associated with the AABB.
  aabb_type box;                     ///< The associated AABB.
  std::optional<index_type> parent;  ///< Index of parent node.
  std::optional<index_type> left;    ///< Index of left child.
  std::optional<index_type> right;   ///< Index of right child.
  std::optional<index_type> next;    ///< Index of next adjacent node.
  int height{-1};                    ///< Amount of levels below the node. TODO check doc
};

/// \name Serialization
/// \{

template <typename Key, std::floating_point Precision>
void serialize(auto& archive, aabb_node<Key, Precision>& node)
{
  archive(node.id, node.box, node.parent, node.left, node.right, node.next, node.height);
}

/// \} End of serialization

template <typename Key, std::floating_point Precision>
[[nodiscard]] constexpr auto is_leaf(const aabb_node<Key, Precision>& node) noexcept
    -> bool
{
  return !node.left;
}

}  // namespace rune

#endif  // RUNE_CONTAINERS_AABB_NODE_HPP
