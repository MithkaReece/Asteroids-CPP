#pragma once

#include <SFML/Graphics.hpp>

namespace Component
{
  /**
   * @brief Velocity component representing the entity's movement velocity.
   *
   * The Velocity component is used to store the velocity of an entity, which
   * determines its movement speed and direction for every frame.
   */
  struct Velocity
  {
    sf::Vector2f velocity;
  };
}