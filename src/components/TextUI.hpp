#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Component
{
  /**
   * @brief TextUI component for displaying text on the user interface.
   *
   * The TextUI component represents text to be displayed on the user interface.
   * It stores the text content as a string, the font to be used and the color of the text.
   */
  struct TextUI
  {
    std::string text;
    sf::Font font;
    sf::Color color;
  };
}