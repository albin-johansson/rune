#include "io/ini.hpp"

#include <gtest/gtest.h>

#include <iostream>  // cout

TEST(Ini, Defaults)
{
  const rune::ini_file file;
  ASSERT_EQ(0, file.size());
  ASSERT_TRUE(file.empty());
  ASSERT_TRUE(file);
}

TEST(Ini, EmplaceOrReplace)
{
  rune::ini_file file;

  {
    auto& foo = file.emplace_or_replace("foo");
    foo["abc"] = 42;

    ASSERT_TRUE(file.contains("foo"));
    ASSERT_EQ(1, file.size());
  }

  {
    auto& foo = file.emplace_or_replace("foo");
    ASSERT_EQ(1, file.size());

    // Ensure that the section was replaced
    ASSERT_FALSE(foo.contains("abc"));
  }
}

TEST(Ini, GetOrEmplace)
{
  rune::ini_file file;

  {
    auto& foo = file.get_or_emplace("foo");
    ASSERT_TRUE(file.contains("foo"));
    ASSERT_EQ(1, file.size());

    foo["abc"] = "123";
  }

  {
    auto& foo = file.get_or_emplace("foo");
    ASSERT_TRUE(foo.contains("abc"));

    ASSERT_TRUE(file.contains("foo"));
    ASSERT_EQ(1, file.size());
  }

  file.get_or_emplace("bar");
  ASSERT_TRUE(file.contains("bar"));
  ASSERT_EQ(2, file.size());
}

TEST(Ini, SubscriptOperator)
{
  rune::ini_file file;

  file["foo"]["abc"] = 42;
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_EQ(1, file.size());

  file["foo"]["def"] = 123;
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_EQ(1, file.size());
  ASSERT_EQ(2, file["foo"].size());

  file["bar"];
  ASSERT_EQ(2, file.size());
}

TEST(Ini, Erase)
{
  rune::ini_file file;
  ASSERT_FALSE(file.erase("foo"));

  file["foo"];
  ASSERT_TRUE(file.contains("foo"));
  ASSERT_EQ(1, file.size());

  ASSERT_TRUE(file.erase("foo"));
  ASSERT_FALSE(file.contains("foo"));
  ASSERT_EQ(0, file.size());
  ASSERT_TRUE(file.empty());

  ASSERT_FALSE(file.erase("foo"));
}

TEST(Ini, At)
{
  rune::ini_file file;
  ASSERT_THROW(file.at("foo"), rune::rune_error);

  file["foo"];
  file["bar"];

  ASSERT_NO_THROW(file.at("foo"));
  ASSERT_NO_THROW(file.at("bar"));
}

TEST(Ini, Contains)
{
  rune::ini_file file;
  ASSERT_FALSE(file.contains("abc"));

  file["foo"];
  ASSERT_TRUE(file.contains("foo"));

  file.erase("foo");
  ASSERT_FALSE(file.contains("foo"));
}

TEST(Ini, ReadIni)
{
  const auto file = rune::read_ini("resources/test.ini").value();

  std::cout << "resources/test.ini:\n";
  file.dump(std::cout);

  ASSERT_EQ(2, file.size());
  ASSERT_FALSE(file.empty());

  const auto& foo = file.at("foo");
  ASSERT_EQ(5, foo.size());

  ASSERT_TRUE(foo.contains("str_1"));
  ASSERT_TRUE(foo.at("str_1").is_string());
  ASSERT_EQ("hello12.3", foo.at("str_1"));

  ASSERT_TRUE(foo.contains("str_2"));
  ASSERT_TRUE(foo.at("str_2").is_string());
  ASSERT_EQ("12a", foo.at("str_2"));

  ASSERT_TRUE(foo.contains("unsigned"));
  ASSERT_TRUE(foo.at("unsigned").is_uint());
  ASSERT_EQ(87u, foo.at("unsigned"));

  ASSERT_TRUE(foo.contains("positive"));
  ASSERT_TRUE(foo.at("positive").is_int());
  ASSERT_EQ(123, foo.at("positive"));

  ASSERT_TRUE(foo.contains("negative"));
  ASSERT_TRUE(foo.at("negative").is_int());
  ASSERT_EQ(-42, foo.at("negative"));

  const auto& bar = file.at("bar");
  ASSERT_EQ(3, bar.size());

  ASSERT_TRUE(bar.contains("real"));
  ASSERT_TRUE(bar.at("real").is_float());
  ASSERT_EQ(32.1, bar.at("real"));

  ASSERT_TRUE(bar.contains("bool_t"));
  ASSERT_TRUE(bar.at("bool_t").is_bool());
  ASSERT_EQ(true, bar.at("bool_t"));

  ASSERT_TRUE(bar.contains("bool_f"));
  ASSERT_TRUE(bar.at("bool_f").is_bool());
  ASSERT_EQ(false, bar.at("bool_f"));
}

TEST(Ini, WriteRead)
{
  {
    rune::ini_file ini;
    ini["foo"]["positive"] = 9'394;
    ini["foo"]["negative"] = -834;
    ini["foo"]["unsigned"] = 734u;
    ini["foo"]["str"] = "foobar";

    ini["bar"]["real_1"] = 1.0;
    ini["bar"]["real_2"] = 87.3;
    ini["bar"]["real_3"] = 0.0;
    ini["bar"]["bool_f"] = false;
    ini["bar"]["bool_t"] = true;

    rune::write_ini(ini, "usage.ini");
  }

  {
    const auto ini = rune::read_ini("usage.ini").value();

    ASSERT_TRUE(ini.at("foo").at("positive").is_int());
    ASSERT_EQ(9'394, ini.at("foo").at("positive").as<int>());

    ASSERT_TRUE(ini.at("foo").at("negative").is_int());
    ASSERT_EQ(-834, ini.at("foo").at("negative").as<int>());

    ASSERT_TRUE(ini.at("foo").at("unsigned").is_uint());
    ASSERT_EQ(734u, ini.at("foo").at("unsigned").as<unsigned>());

    ASSERT_TRUE(ini.at("foo").at("str").is_string());
    ASSERT_EQ("foobar", ini.at("foo").at("str").as<std::string>());

    ASSERT_TRUE(ini.at("bar").at("real_1").is_float());
    ASSERT_EQ(1.0f, ini.at("bar").at("real_1").as<float>());

    ASSERT_TRUE(ini.at("bar").at("real_2").is_float());
    ASSERT_EQ(87.3f, ini.at("bar").at("real_2").as<float>());

    ASSERT_TRUE(ini.at("bar").at("real_3").is_float());
    ASSERT_EQ(0.0f, ini.at("bar").at("real_3").as<float>());

    ASSERT_TRUE(ini.at("bar").at("bool_f").is_bool());
    ASSERT_EQ(false, ini.at("bar").at("bool_f").as<bool>());

    ASSERT_TRUE(ini.at("bar").at("bool_t").is_bool());
    ASSERT_EQ(true, ini.at("bar").at("bool_t").as<bool>());
  }
}
