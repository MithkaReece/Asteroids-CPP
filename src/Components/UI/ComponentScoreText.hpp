#pragma once
#ifndef HEADER_COMPONENT_SCORE_TEXT
#define HEADER_COMPONENT_SCORE_TEXT
#include <SFML/Graphics.hpp>

struct ComponentScoreText
{
  std::unique_ptr<sf::Text> text;
};
#endif