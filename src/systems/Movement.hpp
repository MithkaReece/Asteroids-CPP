#pragma once

#include "systems/System.hpp"
#include <SFML/Graphics.hpp>

#include "components/Transform.hpp"
#include "components/Velocity.hpp"
namespace System
{
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
}