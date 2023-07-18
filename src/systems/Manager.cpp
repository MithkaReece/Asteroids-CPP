#pragma once

#include "systems/System.hpp"

#include "systems/Movement.hpp"
#include "systems/Collision.hpp"
#include "systems/Render.hpp"
#include "systems/Wrapping.hpp"
#include "systems/UserInput.hpp"
#include "systems/AsteroidSpawner.hpp"
#include "systems/Collider.hpp"
#include "systems/PlayerThrust.hpp"
#include "systems/PlayerRotate.hpp"
#include "systems/Weapon.hpp"
#include "systems/OutOfBound.hpp"
namespace System
{
  /**
   * @brief The Manager class defines and updates all systems in the game.
   */
  class Manager
  {
  private:
    std::vector<std::unique_ptr<System>> systems;
    std::unique_ptr<Render> render;

    /**
     * @brief Constructs the Manager object and defines all the systems.
     *
     * @param window The SFML RenderWindow to be used by the systems.
     */
  public:
    // Adds all the systems
    Manager(sf::RenderWindow &window) : render(std::make_unique<Render>(window))
    {
      // Spawners
      systems.push_back(std::make_unique<AsteroidSpawner>(window, sf::milliseconds(2000)));

      // Input
      systems.push_back(std::make_unique<UserInput>());
      // Input responses
      systems.push_back(std::make_unique<PlayerThrust>());
      systems.push_back(std::make_unique<PlayerRotate>());
      systems.push_back(std::make_unique<Weapon>());

      // Applying velocity
      systems.push_back(std::make_unique<Movement>());
      // Collider positioning
      systems.push_back(std::make_unique<Collider>());
      // Keep objects within boundary or deleted
      systems.push_back(std::make_unique<Wrapping>(window));
      systems.push_back(std::make_unique<OutOfBound>(window));

      // Detects collisions
      systems.push_back(std::make_unique<Collision>(window));
    }

    /**
     * @brief Updates all the systems in the Manager.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void updateSystems(entt::registry &registry, sf::Time dt)
    {
      for (auto &system : systems)
        system->update(registry, dt);
    }

    /**
     * @brief Updates the render system in the Manager.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void updateRenderSystem(entt::registry &registry, sf::Time dt)
    {
      render->update(registry, dt);
    }
  };
}