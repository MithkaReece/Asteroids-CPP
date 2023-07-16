#pragma once

#include "System.cpp"
#include "../components/PlayerComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include <entt/entt.hpp>

#include <SFML/Window/Keyboard.hpp>

#include "../Constants.h"

class UserInputSystem
{
public:
    void update(entt::registry &registry, float dt, sf::Keyboard::Key key)
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
            if (key == sf::Keyboard::Key::A)
            {
                transformComponent.rotation -= 10.0f;
            }
            if (key == sf::Keyboard::Key::D)
            {
                transformComponent.rotation -= 10.0f;
            }
            if (key == sf::Keyboard::Key::W)
            {
                // Accelerate player forward
                sf::Vector2f forwardVector = sf::Vector2f(
                    std::cos(transformComponent.rotation * DEG_TO_RAD),
                    std::sin(transformComponent.rotation * DEG_TO_RAD));
                sf::Vector2f acceleration = forwardVector * playerComponent.acceleration;
                velocityComponent.velocity += acceleration;
            }
            if (key == sf::Keyboard::Key::S)
            {
                // velocityComponent.velocity.y = 100.0f;
            }
        }
    }
};