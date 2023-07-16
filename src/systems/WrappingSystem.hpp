#pragma once

#include <entt/entt.hpp>
#include "../components/TransformComponent.hpp"

class WrappingSystem
{
public:
    void update(entt::registry &registry, float dt, sf::RenderWindow &window)
    {
        auto view = registry.view<TransformComponent>();

        for (auto entity : view)
        {
            TransformComponent &transformComponent = view.get<TransformComponent>(entity);

            // Wrap position horizontally
            if (transformComponent.position.x < 0)
            {
                transformComponent.position.x = window.getSize().x;
            }
            else if (transformComponent.position.x > window.getSize().x)
            {
                transformComponent.position.x = 0;
            }

            // Wrap position vertically
            if (transformComponent.position.y < 0)
            {
                transformComponent.position.y = window.getSize().y;
            }
            else if (transformComponent.position.y > window.getSize().y)
            {
                transformComponent.position.y = 0;
            }
        }
    }
};