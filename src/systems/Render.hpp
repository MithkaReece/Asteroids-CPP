#pragma once

#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Render.hpp"

#include <iostream>
namespace System
{
class RenderSystem : public System
{
private:
    sf::RenderWindow &window;

public:
    RenderSystem(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<Component::Render, Component::Transform>();

        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }
            Component::Render &render = view.get<Component::Render>(entity);
            Component::Transform &transform = view.get<Component::Transform>(entity);

            // Render the entity using the render and transform components
            sf::Drawable *drawable = render.drawable.get();
            assert(drawable != nullptr && "Drawable is null!");

            sf::Transform sfTransform;
            sfTransform.translate(transform.position);
            sfTransform.scale(transform.scale);
            sfTransform.rotate(transform.rotation);

            window.draw(*drawable, sfTransform); // Draw the drawable object to the window
        }
    }
};
}