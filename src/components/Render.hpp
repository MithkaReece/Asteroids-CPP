#pragma once

#include <SFML/Graphics.hpp>

namespace Component
{
  /**
   * @brief Render component for visual representation of entities.
   *
   * The Render component is responsible for storing a pointer to the SFML
   * drawable object that represents the visual appearance of an entity,
   * such as an sf::Sprite or sf::Shape.
   */
  struct Render
  {
    std::unique_ptr<sf::Drawable> drawable;
  };
}