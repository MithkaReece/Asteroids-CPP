#pragma once
#ifndef HEADER_COMPONENT_TEXT
#define HEADER_COMPONENT_TEXT
#include <SFML/Graphics.hpp>
#include <memory>

struct ComponentText
{
  std::string ID;
  std::unique_ptr<sf::Text> text;
};
#endif