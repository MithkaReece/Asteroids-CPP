#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/WrapperBoundaryComponent.hpp"

class WrappingSystem : public System
{
private:
    sf::RenderWindow &window;

public:
    WrappingSystem(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<TransformComponent, WrapperBoundaryComponent>();

        for (auto entity : view)
        {
            if(!registry.valid(entity)){
                continue;
            }

            TransformComponent &transformComponent = view.get<TransformComponent>(entity);
            WrapperBoundaryComponent &wrapperBoundaryComponent = view.get<WrapperBoundaryComponent>(entity);
            const float boundary = wrapperBoundaryComponent.boundarySize;

            // Wrap position horizontally
            if (transformComponent.position.x < -boundary)
            {
                transformComponent.position.x = window.getSize().x + boundary;
            }
            else if (transformComponent.position.x > window.getSize().x + boundary)
            {
                transformComponent.position.x = -boundary;
            }

            // Wrap position vertically
            if (transformComponent.position.y < -boundary)
            {
                transformComponent.position.y = window.getSize().y + boundary;
            }
            else if (transformComponent.position.y > window.getSize().y + boundary)
            {
                transformComponent.position.y = -boundary;
            }
        }
    }
};