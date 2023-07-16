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

// Random number between -max < -min or min < max
float randomRange(float min, float max, std::mt19937 gen)
{
    std::uniform_real_distribution<float> distribution(-max + min, max - min);
    //-max+min < max-min
    // If neg then -min
    // If positive then +min
    float x = distribution(gen);
    return x + std::signbit(x) * min;
}

void createAsteroid(entt::registry &registry, sf::RenderWindow &window)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create entity
    auto entity = registry.create();

    const float maxScale = 50.0f;
    std::uniform_real_distribution<float> scaleDistribution(5.0f, maxScale);
    const float scale = scaleDistribution(gen);
    sf::Vector2f scaleVector(scale, scale);

    const float scaleVariation = 0.3f;

    const float boundary = maxScale * 2;

    // Add TransformComponent
    // Generate a random position outside the window but inside the boundary

    // Random x inside window
    std::uniform_real_distribution<float> xDistribution(-window.getSize().x, window.getSize().x);
    float x = xDistribution(gen);
    // Width to the edge of the box
    const float innerWidth = window.getSize().x + (maxScale + scaleVariation) * 2;
    // Further x - closest x
    const float outerWidth = window.getSize().x + boundary - innerWidth;
    // Shift all inner x outside x (now between innerWidth and window.getSize().x + boundary)
    x = x * outerWidth + std::signbit(x) * innerWidth;
    // Map to screen
    x += window.getSize().x / 2;

    // Random y inside window
    std::uniform_real_distribution<float> yDistribution(-window.getSize().y, window.getSize().y);
    float y = yDistribution(gen);
    // Height to the edge of the box
    const float innerHeight = window.getSize().y + (maxScale + scaleVariation) * 2;
    // Further y - closest y
    const float outerHeight = window.getSize().y + boundary - innerHeight;
    // Shift all inner y outside y (now between innerHeight and window.getSize().y + boundary)
    y = y * outerHeight + std::signbit(y) * innerHeight;
    // Map to screen
    y += window.getSize().y / 2;

    sf::Vector2f position(x, y);
    registry.emplace<TransformComponent>(entity, position, scaleVector, 0.0f);

    // Add VelocityComponent
    const float maxStartingVelocity = 50.0f;
    const float minStartingVelocity = 10.0f;
    std::uniform_real_distribution<float> directionDistribution(-maxStartingVelocity, maxStartingVelocity);
    sf::Vector2f velocity(directionDistribution(gen), directionDistribution(gen));
    registry.emplace<VelocityComponent>(entity, velocity);

    // Add WrapperBoundaryComponent
    registry.emplace<WrapperBoundaryComponent>(entity, boundary);

    // Add RenderComponent
    sf::ConvexShape shape = createAsteroidShape(15, 1.0f, scaleVariation);
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
    registry.emplace<RenderComponent>(entity, std::move(drawable));

    // Add ColliderComponent
    registry.emplace<ColliderComponent>(entity, shape);

    // Add AsteroidComponent
    registry.emplace<AsteroidComponent>(entity, 3);
}