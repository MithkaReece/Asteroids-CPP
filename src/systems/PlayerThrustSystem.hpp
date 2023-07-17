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
        auto view = registry.view<PlayerComponent, PlayerInputComponent, TransformComponent, VelocityComponent>();
        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }

            PlayerComponent &player = view.get<PlayerComponent>(entity);
            PlayerInputComponent &input = view.get<PlayerInputComponent>(entity);
            TransformComponent &transform = view.get<TransformComponent>(entity);
            VelocityComponent &velocity = view.get<VelocityComponent>(entity);

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