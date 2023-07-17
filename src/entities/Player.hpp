#pragma once
#include <entt/entt.hpp>

#include "components/Player.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"
#include "components/Render.hpp"
#include "components/Collider.hpp"
#include "components/PlayerInput.hpp"
namespace Entity
{
sf::ConvexShape createTriangle()
{
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(1.0f, .0f));    // Middle Right vertex
    triangle.setPoint(1, sf::Vector2f(-1.0f, 1.0f));  // Top Left vertex
    triangle.setPoint(2, sf::Vector2f(-1.0f, -1.0f)); // Bottom Left vertex
    triangle.setFillColor(sf::Color::Red);
    return triangle;
}

void createPlayer(entt::registry &registry)
{
    // Create entity
    auto entity = registry.create();

    // Add PlayerComponent
    const float acceleration = 100.0f;
    registry.emplace<Component::Player>(entity, acceleration);

    // Add TransformComponent
    sf::Vector2f position(30.0f, 30.0f);
    sf::Vector2f scale(10.0f, 10.0f);
    const float rotation = 0.0f;
    registry.emplace<Component::Transform>(entity, position, scale, rotation);

    // Add VelocityComponent
    sf::Vector2f velocity(0.0f, 0.0f);
    registry.emplace<Component::Velocity>(entity, velocity);

    // Add WrapperBoundaryComponent
    const float boundarySize = 2.0f;
    registry.emplace<Component::WrapperBoundary>(entity, boundarySize);

    // Add PlayerInputComponent
    registry.emplace<Component::PlayerInput>(entity);

    // Add RenderComponent
    sf::ConvexShape shape = createTriangle();
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
    registry.emplace<Component::Render>(entity, std::move(drawable));

    // Add ColliderComponent
    registry.emplace<Component::Collider>(entity, shape);
}
}