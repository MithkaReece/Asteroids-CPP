#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/ColliderComponent.hpp"

class ColliderSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<Component::Collider, Component::Transform>();

        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }
            Component::Collider &collider = view.get<Component::Collider>(entity);
            Component::Transform &transform = view.get<Component::Transform>(entity);

            sf::ConvexShape &shape = collider.shape;
            shape.setPosition(transform.position);
            shape.setScale(transform.scale);
            shape.setRotation(transform.rotation);
        }
    }
};