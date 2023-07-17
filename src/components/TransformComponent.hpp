#pragma once

#include <SFML/Graphics.hpp>

namespace Component
{
    struct Transform
    {
        sf::Vector2f position;
        sf::Vector2f scale;
        float rotation;
    };
}