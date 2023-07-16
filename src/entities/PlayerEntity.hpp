#pragma once
#include <entt/entt.hpp>

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
    auto entity = registry.create();
    // Add components
    registry.emplace<PlayerComponent>(entity, 50.0f);
    registry.emplace<TransformComponent>(
        entity,
        sf::Vector2f(30.0f, 30.0f),
        sf::Vector2f(10.0, 10.0f),
        0.0f);
    registry.emplace<VelocityComponent>(entity, sf::Vector2f(0.f, 0.f));
    // Add visuals
    sf::ConvexShape shape = createTriangle();
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
    registry.emplace<RenderComponent>(entity, std::move(drawable));
}
