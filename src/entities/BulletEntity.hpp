#pragma once
#include <entt/entt.hpp>
#include "../components/BulletTag.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/RenderComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include <SFML/Graphics.hpp>

sf::ConvexShape createBulletShape()
{
    const float ratio = 10.0f;
    sf::ConvexShape bullet;
    bullet.setPointCount(4);
    bullet.setPoint(0, sf::Vector2f(-ratio, -1.0f));
    bullet.setPoint(1, sf::Vector2f(-ratio, 1.0f));
    bullet.setPoint(2, sf::Vector2f(ratio, 1.0f));
    bullet.setPoint(3, sf::Vector2f(ratio, -1.0f));
    bullet.setFillColor(sf::Color::White);
    return bullet;
}

void createBullet(entt::registry &registry, sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
    // Add components
    auto entity = registry.create();

    registry.emplace<BulletTag>(entity);
    registry.emplace<TransformComponent>(entity, position, sf::Vector2f(1.0f, 1.0f), rotation);
    registry.emplace<VelocityComponent>(entity, velocity);

    // Create shape
    sf::ConvexShape shape = createBulletShape();
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));

    // Add components
    registry.emplace<RenderComponent>(entity, std::move(drawable));
    registry.emplace<ColliderComponent>(entity, shape);
}