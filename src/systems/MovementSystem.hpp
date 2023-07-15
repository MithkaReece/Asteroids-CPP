#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../components/PositionComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "System.cpp"

class MovementSystem : public System
{
public:
    void update(entt::registry &registry, float dt)
    {
        auto view = registry.view<PositionComponent, VelocityComponent>();

        for (auto entity : view)
        {
            auto &position = view.get<PositionComponent>(entity);
            const auto &velocity = view.get<VelocityComponent>(entity);

            position.position += velocity.velocity * dt;
        }
    }
};