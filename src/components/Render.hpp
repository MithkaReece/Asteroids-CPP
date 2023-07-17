#pragma once

#include <SFML/Graphics.hpp>

namespace Component
{
    struct Render
    {
        std::unique_ptr<sf::Drawable> drawable; // Pointer to the SFML drawable object (sf::Sprite or sf::Shape)
    };
}