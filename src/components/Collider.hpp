#pragma once

#include <SFML/Graphics.hpp>
namespace Component
{
    /**
     * @brief Collider component for collision detection.
     * 
     * This component defines the shape of an entity used for collision detection.
     * The shape is defined as a `sf::ConvexShape` object.
     */
    struct Collider
    {
        sf::ConvexShape shape; 
    };
}