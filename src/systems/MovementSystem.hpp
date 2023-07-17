#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "System.hpp"

class MovementSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<Component::Transform, Component::Velocity>();

        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }
            Component::Velocity &velocity = view.get<Component::Velocity>(entity);
            Component::Transform &transform = view.get<Component::Transform>(entity);
            transform.position += velocity.velocity * dt.asSeconds();
        }
    }
};