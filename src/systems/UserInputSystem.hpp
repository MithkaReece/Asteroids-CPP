#pragma once

#include "System.hpp"
#include "../components/PlayerInputComponent.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "../Constants.h"

#include <iostream>

class UserInputSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<PlayerInputComponent>();
        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }

            PlayerInputComponent &input = view.get<PlayerInputComponent>(entity);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                input.leftRotatePressed = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                input.rightRotatePressed = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                input.thrustPressed = true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                input.shootPressed = true;
        }
    }
};