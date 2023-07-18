#pragma once

#include <entt/entt.hpp>

/**
 * @brief Base class for scenes in an ECS (entt) and SFML project.
 * Scenes represent different states or levels in the game.
 */
class Scene
{
public:
  virtual ~Scene() {}
  /**
   * @brief Initialize the scene by adding entities and components to the registry.
   *
   * @param registry The entity registry.
   * @param window The SFML render window.
   */
  virtual void init(entt::registry &registry, sf::RenderWindow &window) = 0;
};