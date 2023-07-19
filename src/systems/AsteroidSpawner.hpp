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
    sf::Time interval; // Interval between asteroid spawns
    sf::Time timer;    // Timer to track the elapsed time

  public:
    AsteroidSpawner(entt::registry &registry, sf::RenderWindow &window, Scene::Scene &scene, sf::Time interval)
        : System::System(registry, window,scene), interval(interval) {}

    /**
     * @brief Updates the asteroid spawner.
     *
     * @param registry The entity registry.
     * @param dt The elapsed time since the last update.
     */
    void update(sf::Time dt)
    {
      entt::registry &registry = registryRef.get();
      timer += dt;
      if (timer >= interval)
      {
        Scene::Scene &scene = sceneRef.get();
        // Entity::createAsteroid(scene, sceneManagerRef.get().windowRef.get());
        timer = sf::Time::Zero;
      }
    }
  };
}