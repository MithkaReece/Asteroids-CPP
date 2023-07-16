#pragma once
#include <entt/entt.hpp>
#include <random>
sf::ConvexShape createAsteroidShape(unsigned int noPoints, float radius, float noiseMagnitude)
{
    sf::ConvexShape asteroid;
    asteroid.setPointCount(noPoints);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> noiseDist(-noiseMagnitude, noiseMagnitude);
    std::uniform_real_distribution<float> angleDist(0.0f, 360.0f);

    for (unsigned int i = 0; i < noPoints; ++i)
    {
        float angle = (i * 360.0f) / noPoints;
        float noiseOffset = noiseDist(gen);

        float x = radius * std::cos(angle * 3.14159f / 180.0f) + noiseOffset;
        float y = radius * std::sin(angle * 3.14159f / 180.0f) + noiseOffset;

        asteroid.setPoint(i, sf::Vector2f(x, y));
    }

    asteroid.setFillColor(sf::Color::Black);
    asteroid.setOutlineColor(sf::Color::White);
    asteroid.setOutlineThickness(0.1f);

    return asteroid;
}

void createAsteroid(entt::registry &registry, sf::RenderWindow &window)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    auto entity = registry.create();
    // Add components
    const float boundary = 10.0f;
    std::uniform_real_distribution<float> positionDistribution(boundary, window.getSize().x - boundary);
    std::uniform_real_distribution<float> scaleDistribution(5.0f, 50.0f);
    const float scale = scaleDistribution(gen);
    registry.emplace<TransformComponent>(
        entity,
        sf::Vector2f(positionDistribution(gen), positionDistribution(gen)),
        sf::Vector2f(scale, scale),
        0.0f);
    const float maxStartingVelocity = 25.0f;

    std::uniform_real_distribution<float> directionDistribution(-maxStartingVelocity, maxStartingVelocity);
    registry.emplace<VelocityComponent>(entity, sf::Vector2(directionDistribution(gen), directionDistribution(gen)));

    // Add visuals
    sf::ConvexShape shape = createAsteroidShape(15, 1.0f, 0.3f);
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
    registry.emplace<RenderComponent>(entity, std::move(drawable));
}