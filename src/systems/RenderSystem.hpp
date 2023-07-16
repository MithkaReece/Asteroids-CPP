#pragma once

#include <entt/entt.hpp>
#include "../components/TransformComponent.hpp"
#include "../components/RenderComponent.hpp"

#include <iostream>
class RenderSystem
{
public:
    void update(entt::registry &registry, float dt, sf::RenderWindow &window)
    {
        auto view = registry.view<RenderComponent, TransformComponent>();

        for (auto entity : view)
        {
            RenderComponent &renderComponent = view.get<RenderComponent>(entity);
            TransformComponent &transformComponent = view.get<TransformComponent>(entity);

            // Render the entity using the render and transform components

            // Access the drawable and transform information to perform rendering
            sf::Drawable *drawable = renderComponent.drawable.get();
            assert(drawable != nullptr && "Drawable is null!");

            window.draw(*drawable); // Draw the drawable object to the window

            // sf::Vector2f position = transformComponent.position;
            // sf::Vector2f scale = transformComponent.scale;
            // float rotation = transformComponent.rotation;

            // Set the position, scale, and rotation of the drawable
            // drawable->setPosition(position);
            // drawable->setScale(scale);
            // drawable->setRotation(rotation);

            // Render the drawable object
            // window.draw(*drawable);
        }
    }
};