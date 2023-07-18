#pragma once

#include <SFML/Graphics.hpp>

namespace Component
{
    /**
     * @brief Component representing the transformation of an entity in 2D space.
     *
     * The Transform stores the position, scale and rotation of an entity.
     * It is used to determine the visual representation and spatial properties of an entity.
     */
    struct Transform
    {
        sf::Vector2f position;
        sf::Vector2f scale;
        float rotation;
    };
}