#pragma once

#include "System.hpp"

#include "../components/PlayerInputComponent.hpp"
#include "../components/TransformComponent.hpp"

class PlayerRotateSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<PlayerInputComponent, TransformComponent>();

        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }

            PlayerInputComponent &input = view.get<PlayerInputComponent>(entity);
            TransformComponent &transform = view.get<TransformComponent>(entity);

            if (input.leftRotatePressed)
            {
                transform.rotation -= 0.1f;
                input.leftRotatePressed = false;
            }

            if (input.rightRotatePressed)
            {
                transform.rotation += 0.1f;
                input.rightRotatePressed = false;
            }
        }
    }
};