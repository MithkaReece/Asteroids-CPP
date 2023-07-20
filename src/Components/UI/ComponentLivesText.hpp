#pragma once
#ifndef HEADER_COMPONENT_LIVES_TEXT
#define HEADER_COMPONENT_LIVES_TEXT
#include <SFML/Graphics.hpp>
#include <memory>

struct ComponentLivesText
{
  std::unique_ptr<sf::Text> text;
};
#endif