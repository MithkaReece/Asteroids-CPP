#pragma once
#ifndef HEADER_COMPONENT_MENU_ITEM
#define HEADER_COMPONENT_MENU_ITEM
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

using OnClickFunc = void (*)(entt::dispatcher &);

struct ComponentMenuItem
{
  std::unique_ptr<sf::Text> text;
  std::unique_ptr<sf::RectangleShape> shape;
  OnClickFunc onClick; // Function pointer
  bool hover = false;
};

#endif