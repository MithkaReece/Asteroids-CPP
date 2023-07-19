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
    AsteroidSpawner(std::reference_wrapper<Scene::IManager> sceneManager, Scene::IScene &scene, sf::Time interval)
        : System::System(sceneManager, scene), interval(interval) {}

    /**
     * @brief Updates the asteroid spawner.
     *
     * @param registry The entity registry.
     * @param dt The elapsed time since the last update.
     */
    void update(sf::Time dt)
    {
      entt::registry &registry = sceneManagerRef.get().registryRef.get();
      timer += dt;
      if (timer >= interval)
      {
        Scene::IScene &scene = sceneRef.get();
        // Entity::createAsteroid(scene, sceneManagerRef.get().windowRef.get());
        timer = sf::Time::Zero;
      }
    }
  };
}