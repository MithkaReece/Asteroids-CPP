#pragma once
#ifndef HEADER_COMPONENT_MENU_ITEM
#define HEADER_COMPONENT_MENU_ITEM
#include <SFML/Graphics.hpp>
#include "EnumMenuItemID.hpp"

struct ComponentMenuItem
{
  MenuItemID id;
  std::unique_ptr<sf::Text> text;
  std::unique_ptr<sf::RectangleShape> shape;
  bool hover = false;
};

#endif