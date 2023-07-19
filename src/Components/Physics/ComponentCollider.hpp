#pragma once
#ifndef HEADER_COMPONENT_COLLIDER
#define HEADER_COMPONENT_COLLIDER
#include <SFML/Graphics.hpp>

/**
 * @brief Collider component for collision detection.
 *
 * This component defines the shape of an entity used for collision detection.
 * The shape is defined as a `sf::ConvexShape` object.
 */
struct ComponentCollider
{
  sf::ConvexShape shape;
};
#endif