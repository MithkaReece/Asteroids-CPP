#pragma once
#ifndef HEADER_COMPONENT_TRANSFORM
#define HEADER_COMPONENT_TRANSFORM
#include <SFML/Graphics.hpp>

/**
 * @brief Component representing the transformation of an entity in 2D space.
 *
 * The Transform stores the position, scale and rotation of an entity.
 * It is used to determine the visual representation and spatial properties of an entity.
 */
struct ComponentTransform
{
  sf::Vector2f position;
  sf::Vector2f scale;
  float rotation;
};
#endif