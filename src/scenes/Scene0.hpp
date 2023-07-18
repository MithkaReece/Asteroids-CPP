#pragma once

#include <entt/entt.hpp>
#include "scenes/Scene.hpp"

#include "entities/Player.hpp"
#include "entities/ScoreUI.hpp"

/**
 * @brief Implementation of Scene0 class, representing the first scene of the game.
 */
class Scene0 : public Scene
{
  /**
   * @brief Initialize the Scene0 by creating entities and components.
   *
   * @param registry The entity registry.
   * @param window The SFML render window.
   */
  void init(entt::registry &registry, sf::RenderWindow &window)
  {
    Entity::createPlayer(registry, window);
    Entity::createScoreUI(registry);
  }
};