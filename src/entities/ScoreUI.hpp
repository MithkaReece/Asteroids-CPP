#pragma once
#include <entt/entt.hpp>

#include "components/Transform.hpp"
#include "components/TextUI.hpp"
#include "components/ScoreTag.hpp"

#include "scenes/Scene.hpp"

#include <SFML/Graphics.hpp>

namespace Entity
{
  /**
   * @brief Create a score UI entity with the specified components.
   *
   * @param registry The entity registry.
   */
  void createScoreUI(Scene::Scene &scene);
}