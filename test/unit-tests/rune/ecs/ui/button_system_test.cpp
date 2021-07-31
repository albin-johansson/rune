#include "ecs/ui/button_system.hpp"

#include <gtest/gtest.h>

#include "ecs/ui/menu_system.hpp"
#include "ecs/ui/ui_foreground.hpp"
#include "ecs/ui/ui_label.hpp"

TEST(ButtonSystem, UiButtonCfg)
{
  const rune::ui_button_cfg cfg;
  ASSERT_EQ(0, cfg.position.row);
  ASSERT_EQ(0, cfg.position.col);
  ASSERT_EQ(0, cfg.id);
  ASSERT_EQ(0, cfg.font);
  ASSERT_EQ(cen::colors::white, cfg.fg);
  ASSERT_TRUE(cfg.text.empty());
  ASSERT_FALSE(cfg.shadow);
}

TEST(ButtonSystem, MakeButton)
{
  entt::registry registry;

  const auto menu = rune::ui::make_menu(registry, {});
  const auto entity = rune::ui::make_button(registry,
                                            menu,
                                            {.position = {2, 4},
                                             .text = "bar",
                                             .id = 42,
                                             .font = 7,
                                             .fg = cen::colors::teal,
                                             .shadow = true});

  ASSERT_TRUE(registry.all_of<rune::ui_button>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_position>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_label>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_label_shadow>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_foreground>(entity));
  ASSERT_TRUE(registry.all_of<rune::in_menu>(entity));

  const auto& button = registry.get<rune::ui_button>(entity);
  ASSERT_EQ(42, button.id);
  ASSERT_TRUE(button.is_visible);
  ASSERT_TRUE(button.is_enabled);
  ASSERT_FALSE(button.is_hovered);
  ASSERT_FALSE(button.text_offset.has_value());
  ASSERT_FALSE(button.size.has_value());

  const auto& position = registry.get<rune::ui_position>(entity);
  ASSERT_EQ(2.0f, position.row);
  ASSERT_EQ(4.0f, position.col);

  const auto& label = registry.get<rune::ui_label>(entity);
  ASSERT_EQ("bar", label.text);
  ASSERT_EQ(7, label.font);
  ASSERT_FALSE(label.texture.has_value());

  const auto& fg = registry.get<rune::ui_foreground>(entity);
  ASSERT_EQ(cen::colors::teal, fg.color);

  const auto& inMenu = registry.get<rune::in_menu>(entity);
  ASSERT_EQ(menu, inMenu.menu_entity);
}
