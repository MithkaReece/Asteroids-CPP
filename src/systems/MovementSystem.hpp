#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "System.cpp"

class MovementSystem : public System
{
public:
    void update(entt::registry &registry, float dt)
    {
        auto view = registry.view<TransformComponent, VelocityComponent>();

        for (auto entity : view)
        {
            auto &transform = view.get<TransformComponent>(entity);
            const auto &velocity = view.get<VelocityComponent>(entity);

            transform.position += velocity.velocity * dt;
        }
    }
};