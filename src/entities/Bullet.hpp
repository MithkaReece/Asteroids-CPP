#pragma once
#include <entt/entt.hpp>
#include "components/BulletTag.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/Render.hpp"
#include "components/Collider.hpp"
#include <SFML/Graphics.hpp>
namespace Entity
{
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

    registry.emplace<Component::BulletTag>(entity);
    registry.emplace<Component::Transform>(entity, position, sf::Vector2f(1.0f, 1.0f), rotation);
    registry.emplace<Component::Velocity>(entity, velocity);

    // Create shape
    sf::ConvexShape shape = createBulletShape();
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));

    // Add components
    registry.emplace<Component::Render>(entity, std::move(drawable));
    registry.emplace<Component::Collider>(entity, shape);
}
}