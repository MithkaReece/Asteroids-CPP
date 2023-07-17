#pragma once

#include "System.hpp"

#include "../components/PlayerInputComponent.hpp"
#include "../components/TransformComponent.hpp"

class PlayerRotateSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<Component::PlayerInput, Component::Transform>();

        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }

            Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);
            Component::Transform &transform = view.get<Component::Transform>(entity);

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