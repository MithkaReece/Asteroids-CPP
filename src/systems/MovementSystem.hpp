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

            VelocityComponent &velocityComponent = view.get<VelocityComponent>(entity);
            TransformComponent &transformComponent = view.get<TransformComponent>(entity);
            transformComponent.position += velocityComponent.velocity * dt;
        }
    }
};