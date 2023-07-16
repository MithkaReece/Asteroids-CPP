#pragma once

#include <SFML/Graphics.hpp>

struct RenderComponent
{
    std::unique_ptr<sf::Drawable> drawable; // Pointer to the SFML drawable object (sf::Sprite or sf::Shape)
};