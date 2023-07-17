#pragma once
#include <entt/entt.hpp>
#include <random>
#include "components/Asteroid.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"
#include "components/Render.hpp"
#include "components/Collider.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace Entity
{
  sf::ConvexShape createAsteroidShape(unsigned int noPoints, float noiseMagnitude)
  {
    const float radius = 1.0f; // Normalised circled, then its scaled up

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

  float levelMinScale(int level)
  {
    switch (level)
    {
    case 1:
      return 5.0f;
    case 2:
      return 20.0f;
    case 3:
      return 50.0f;
    }
    return 0.0f;
  }

  float levelMaxScale(int level)
  {
    switch (level)
    {
    case 1:
      return 10.0f;
    case 2:
      return 25.0f;
    case 3:
      return MAX_SCALE;
    }
    return 0.0f;
  }

  void createAsteroid(entt::registry &registry, sf::RenderWindow &window, int level, sf::Vector2f position, sf::Vector2f velocity)
  {
    assert(level == 1 || level == 2 || level == 3);
    // Calculate random scale from level
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> scaleDistribution(levelMinScale(level), levelMaxScale(level));
    const float scale = scaleDistribution(gen);
    sf::Vector2f scaleVector(scale, scale);

    // Add components
    auto entity = registry.create();
    registry.emplace<Component::Asteroid>(entity, level);
    registry.emplace<Component::Transform>(entity, position, scaleVector, 0.0f);
    registry.emplace<Component::Velocity>(entity, velocity);
    registry.emplace<Component::WrapperBoundary>(entity, BOUNDARY);

    // Create shape
    const int points = 15;
    sf::ConvexShape shape = createAsteroidShape(points, SCALE_VARIATION);
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));

    // Add components
    registry.emplace<Component::Render>(entity, std::move(drawable));
    registry.emplace<Component::Collider>(entity, shape);
  }

  void createAsteroid(entt::registry &registry, sf::RenderWindow &window)
  {
    std::random_device rd;
    std::mt19937 gen(rd());

    // std::uniform_int_distribution<int> levelDistribution(1, 3);
    // int level = levelDistribution(gen);
    int level = 3;

    // Generate a random position outside the window but inside the boundary

    // Random x inside window
    std::uniform_real_distribution<float> xDistribution(-window.getSize().x, window.getSize().x);
    float x = xDistribution(gen);
    // Width to the edge of the box
    const float innerWidth = window.getSize().x + (MAX_SCALE + SCALE_VARIATION) * 2;
    // Further x - closest x
    const float outerWidth = window.getSize().x + BOUNDARY - innerWidth;
    // Shift all inner x outside x (now between innerWidth and window.getSize().x + boundary)
    x = x * outerWidth + std::signbit(x) * innerWidth;
    // Map to screen
    x += window.getSize().x / 2;

    // Random y inside window
    std::uniform_real_distribution<float> yDistribution(-window.getSize().y, window.getSize().y);
    float y = yDistribution(gen);
    // Height to the edge of the box
    const float innerHeight = window.getSize().y + (MAX_SCALE + SCALE_VARIATION) * 2;
    // Further y - closest y
    const float outerHeight = window.getSize().y + BOUNDARY - innerHeight;
    // Shift all inner y outside y (now between innerHeight and window.getSize().y + boundary)
    y = y * outerHeight + std::signbit(y) * innerHeight;
    // Map to screen
    y += window.getSize().y / 2;

    sf::Vector2f position(x, y);

    // Random VelocityComponent
    const float maxStartingVelocity = 50.0f;
    const float minStartingVelocity = 10.0f;
    std::uniform_real_distribution<float> directionDistribution(-maxStartingVelocity, maxStartingVelocity);
    sf::Vector2f velocity(directionDistribution(gen), directionDistribution(gen));

    createAsteroid(registry, window, level, position, velocity);
  }
}