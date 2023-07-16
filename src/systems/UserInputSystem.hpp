#pragma once

#include "System.hpp"
#include "../components/PlayerComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include <entt/entt.hpp>

#include <SFML/Window/Keyboard.hpp>

#include "../Constants.h"

#include <iostream>

class UserInputSystem : public System
{
public:
    void update(entt::registry &registry, float dt)
    {
        // Retrieve entities with PlayerComponent and VelocityComponent
        auto view = registry.view<PlayerComponent, TransformComponent, VelocityComponent>();

        // Process user input for the player entity
        for (auto entity : view)
        {
            PlayerComponent &playerComponent = view.get<PlayerComponent>(entity);
            TransformComponent &transformComponent = view.get<TransformComponent>(entity);
            VelocityComponent &velocityComponent = view.get<VelocityComponent>(entity);
            // Update velocity based on user input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                transformComponent.rotation -= 0.1f;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                transformComponent.rotation += 0.1f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                // Accelerate player forward
                sf::Vector2f forwardVector = sf::Vector2f(
                    std::cos(transformComponent.rotation * DEG_TO_RAD),
                    std::sin(transformComponent.rotation * DEG_TO_RAD));
                velocityComponent.velocity += forwardVector * playerComponent.acceleration * dt;
            }
        }
    }
};