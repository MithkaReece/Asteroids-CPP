#pragma once

#include "System.hpp"

#include "../components/PlayerComponent.hpp"
#include "../components/PlayerInputComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"

class PlayerThrustSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<Component::Player, Component::PlayerInput, Component::Transform, Component::Velocity>();
        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }

            Component::Player &player = view.get<Component::Player>(entity);
            Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);
            Component::Transform &transform = view.get<Component::Transform>(entity);
            Component::Velocity &velocity = view.get<Component::Velocity>(entity);

            if (input.thrustPressed)
            { // Accelerate player forward
                sf::Vector2f forwardVector = sf::Vector2f(
                    std::cos(transform.rotation * DEG_TO_RAD),
                    std::sin(transform.rotation * DEG_TO_RAD));
                velocity.velocity += forwardVector * player.acceleration * dt.asSeconds();
                input.thrustPressed = false;
            }
        }
    }
};