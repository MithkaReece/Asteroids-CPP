#pragma once

#include <entt/entt.hpp>
#include "scenes/Scene.hpp"

#include "entities/Player.hpp"
#include "entities/ScoreUI.hpp"

class Scene0 : public Scene
{
  void init(entt::registry &registry, sf::RenderWindow &window)
  {
    Entity::createPlayer(registry, window);
    Entity::createScoreUI(registry);
  }
};