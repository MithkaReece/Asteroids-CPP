#pragma once

#include <entt/entt.hpp>
#include "systems/System.hpp"
#include "entities/Asteroid.hpp"

#include <iostream>

/**
 * @brief Class for spawning asteroids at a fixed interval.
 */
namespace System
{
  class AsteroidSpawner : public System
  {
  private:
    sf::RenderWindow &window; // Reference to the SFML render window
    sf::Time interval;        // Interval between asteroid spawns
    sf::Time timer;           // Timer to track the elapsed time

  public:
    /**
     * @brief Constructs an AsteroidSpawner object.
     *
     * @param window The SFML render window.
     * @param interval The interval between asteroid spawns.
     */
    AsteroidSpawner(sf::RenderWindow &window, sf::Time interval)
        : window(window), interval(interval) {}

    /**
     * @brief Updates the asteroid spawner.
     *
     * @param registry The entity registry.
     * @param dt The elapsed time since the last update.
     */
    void update(entt::registry &registry, sf::Time dt)
    {
      timer += dt;
      if (timer >= interval)
      {
        Entity::createAsteroid(registry, window);
        timer = sf::Time::Zero;
      }
    }
  };
}