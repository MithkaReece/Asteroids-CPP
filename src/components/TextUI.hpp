#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Component
{
  struct TextUI
  {
    std::string text;
    sf::Color color;
  };
}