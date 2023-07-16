#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/ColliderComponent.hpp"

class ColliderSystem : public System
{
public:
    void update(entt::registry &registry, float dt)
    {
        auto view = registry.view<ColliderComponent, TransformComponent>();

        for (auto entity : view)
        {
            ColliderComponent &colliderComponent = view.get<ColliderComponent>(entity);
            TransformComponent &transformComponent = view.get<TransformComponent>(entity);

            sf::ConvexShape &shape = colliderComponent.shape;
            shape.setPosition(transformComponent.position);
            shape.setScale(transformComponent.scale);
            shape.setRotation(transformComponent.rotation);
        }
    }
};