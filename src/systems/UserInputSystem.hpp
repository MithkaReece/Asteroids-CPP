#pragma once

#include "System.cpp"
#include "../components/PlayerComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include <entt/entt.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <iostream>

class UserInputSystem
{
public:
    void update(entt::registry &registry, float dt, sf::Keyboard::Key key)
    {
        // Retrieve entities with PlayerComponent and VelocityComponent
        auto view = registry.view<PlayerComponent, VelocityComponent>();

        // Process user input for the player entity
        for (auto entity : view)
        {
            VelocityComponent &velocityComponent = view.get<VelocityComponent>(entity);
            // Update velocity based on user input
            if (key == sf::Keyboard::Key::A)
            {
                velocityComponent.velocity.x = -100.0f;
                std::cout << "A\n";
            }
            if (key == sf::Keyboard::Key::D)
            {
                velocityComponent.velocity.x = 100.0f;
                std::cout << "D\n";
            }
            if (key == sf::Keyboard::Key::W)
            {
                velocityComponent.velocity.y = -100.0f;
                std::cout << "W\n";
            }
            if (key == sf::Keyboard::Key::S)
            {
                velocityComponent.velocity.y = 100.0f;
                std::cout << "S\n";
            }
        }
    }
};