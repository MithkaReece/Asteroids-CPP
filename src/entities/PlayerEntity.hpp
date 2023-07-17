#pragma once
#include <entt/entt.hpp>

#include "../components/PlayerComponent.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/WrapperBoundaryComponent.hpp"
#include "../components/RenderComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PlayerInputComponent.hpp"

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
    registry.emplace<PlayerComponent>(entity, acceleration);

    // Add TransformComponent
    sf::Vector2f position(30.0f, 30.0f);
    sf::Vector2f scale(10.0f, 10.0f);
    const float rotation = 0.0f;
    registry.emplace<TransformComponent>(entity, position, scale, rotation);

    // Add VelocityComponent
    sf::Vector2f velocity(0.0f, 0.0f);
    registry.emplace<VelocityComponent>(entity, velocity);

    // Add WrapperBoundaryComponent
    const float boundarySize = 2.0f;
    registry.emplace<WrapperBoundaryComponent>(entity, boundarySize);

    // Add PlayerInputComponent
    registry.emplace<PlayerInputComponent>(entity);

    // Add RenderComponent
    sf::ConvexShape shape = createTriangle();
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
    registry.emplace<RenderComponent>(entity, std::move(drawable));

    // Add ColliderComponent
    registry.emplace<ColliderComponent>(entity, shape);
}
