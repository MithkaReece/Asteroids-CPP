#pragma once
#ifndef HEADER_COMPONENT_RENDER
#define HEADER_COMPONENT_RENDER
#include <SFML/Graphics.hpp>

/**
 * @brief Render component for visual representation of entities.
 *
 * The Render component is responsible for storing a pointer to the SFML
 * drawable object that represents the visual appearance of an entity,
 * such as an sf::Sprite or sf::Shape.
 */
struct ComponentRender
{
  std::unique_ptr<sf::Drawable> drawable;
};
#endif