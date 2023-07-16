#pragma once
#include <entt/entt.hpp>
#include <random>
sf::ConvexShape createAsteroid(unsigned int noPoints, float radius, float noiseMagnitude)
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

    asteroid.setFillColor(sf::Color::White);
    asteroid.setOutlineColor(sf::Color::Black);
    asteroid.setOutlineThickness(1.0f);

    return asteroid;
}