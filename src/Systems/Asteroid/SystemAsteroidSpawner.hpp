#pragma once
#ifndef HEADER_SYSTEM_ASTEROID_SPAWNER
#define HEADER_SYSTEM_ASTEROID_SPAWNER
#include <entt/entt.hpp>
#include "System.hpp"
#include "EntityAsteroid.hpp"

/**
 * @brief Class for spawning asteroids at a fixed interval.
 */

class SystemAsteroidSpawner : public System
{
private:
  sf::Time interval; // Interval between asteroid spawns
  sf::Time timer;    // Timer to track the elapsed time

public:
  SystemAsteroidSpawner(entt::registry &registry, sf::RenderWindow &window, Scene &scene, sf::Time interval);

  /**
   * @brief Updates the asteroid spawner.
   *
   * @param registry The entity registry.
   * @param dt The elapsed time since the last update.
   */
  void update(sf::Time dt);
};
#endif