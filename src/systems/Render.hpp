#pragma once

#include <entt/entt.hpp>
#include <functional>
#include "scenes/SceneIManager.hpp"
#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Render.hpp"
#include "components/TextUI.hpp"
#include "components/ScoreTag.hpp"

namespace System
{
  /**
   * @brief The Render class handles rendering entities and UI elements.
   */
  class Render
  {
  private:
    std::reference_wrapper<Scene::IManager> sceneManagerRef;

  public:
    Render(std::reference_wrapper<Scene::IManager> sceneManager);
    /**
     * @brief Updates the system by rendering entities and UI elements.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(sf::Time dt);
  };
}