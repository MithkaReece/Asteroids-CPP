#pragma once
#ifndef HEADER_COMPONENT_TEXT_UI
#define HEADER_COMPONENT_TEXT_UI
#include <string>
#include <SFML/Graphics.hpp>

/**
 * @brief TextUI component for displaying text on the user interface.
 *
 * The TextUI component represents text to be displayed on the user interface.
 * It stores the text content as a string, the font to be used and the color of the text.
 */
struct ComponentTextUI
{
  std::string text;
  sf::Font font;
  sf::Color color;
};
#endif