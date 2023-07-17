#pragma once

#include <entt/entt.hpp>
#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Collider.hpp"
namespace System
{
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
}