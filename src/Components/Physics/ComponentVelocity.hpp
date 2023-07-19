#pragma once
#ifndef HEADER_COMPONENT_VELOCITY
#define HEADER_COMPONENT_VELOCITY
#include <SFML/Graphics.hpp>

/**
 * @brief Velocity component representing the entity's movement velocity.
 *
 * The Velocity component is used to store the velocity of an entity, which
 * determines its movement speed and direction for every frame.
 */
struct ComponentVelocity
{
  sf::Vector2f velocity;
};
#endif