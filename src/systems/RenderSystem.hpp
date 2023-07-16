#pragma once

#include <entt/entt.hpp>
#include "../components/TransformComponent.hpp"
#include "../components/RenderComponent.hpp"

#include <iostream>
class RenderSystem
{
private:
    sf::RenderWindow &window;

public:
    RenderSystem(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, float dt)
    {
        auto view = registry.view<RenderComponent, TransformComponent>();

        for (auto entity : view)
        {
            RenderComponent &renderComponent = view.get<RenderComponent>(entity);
            TransformComponent &transformComponent = view.get<TransformComponent>(entity);

            // Render the entity using the render and transform components
            sf::Drawable *drawable = renderComponent.drawable.get();
            assert(drawable != nullptr && "Drawable is null!");

            sf::Transform transform;
            transform.translate(transformComponent.position);
            transform.scale(transformComponent.scale);
            transform.rotate(transformComponent.rotation);

            window.draw(*drawable, transform); // Draw the drawable object to the window
        }
    }
};