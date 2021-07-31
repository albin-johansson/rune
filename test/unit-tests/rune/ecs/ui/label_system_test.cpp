#include "ecs/ui/label_system.hpp"

#include <gtest/gtest.h>

#include "ecs/ui/menu_system.hpp"
#include "ecs/ui/ui_foreground.hpp"

TEST(LabelSystem, UiLabelCfg)
{
  const rune::ui_label_cfg cfg;
  ASSERT_TRUE(cfg.text.empty());
  ASSERT_FALSE(cfg.shadow);
  ASSERT_EQ(0, cfg.position.row);
  ASSERT_EQ(0, cfg.position.col);
  ASSERT_EQ(0, cfg.font);
  ASSERT_EQ(cen::colors::white, cfg.color);
}

TEST(LabelSystem, MakeLabel)
{
  entt::registry registry;

  const auto menu = rune::ui::make_menu(registry, {});

  const auto entity = rune::ui::make_label(registry,
                                           menu,
                                           {.position = {12, 7},
                                            .text = "foobar",
                                            .font = 123,
                                            .color = cen::colors::crimson,
                                            .shadow = true});

  ASSERT_TRUE(registry.all_of<rune::ui_label>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_position>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_foreground>(entity));
  ASSERT_TRUE(registry.all_of<rune::ui_label_shadow>(entity));
  ASSERT_TRUE(registry.all_of<rune::in_menu>(entity));

  const auto& label = registry.get<rune::ui_label>(entity);
  ASSERT_EQ("foobar", label.text);
  ASSERT_EQ(123, label.font);
  ASSERT_FALSE(label.texture.has_value());

  const auto& position = registry.get<rune::ui_position>(entity);
  ASSERT_EQ(12.0f, position.row);
  ASSERT_EQ(7.0f, position.col);

  const auto& fg = registry.get<rune::ui_foreground>(entity);
  ASSERT_EQ(cen::colors::crimson, fg.color);

  const auto& shadow = registry.get<rune::ui_label_shadow>(entity);
  ASSERT_EQ(1, shadow.offset);
  ASSERT_FALSE(shadow.texture.has_value());

  const auto& inMenu = registry.get<rune::in_menu>(entity);
  ASSERT_EQ(menu, inMenu.menu_entity);
}
