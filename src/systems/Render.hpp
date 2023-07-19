#pragma once

#include <entt/entt.hpp>
#include <functional>
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
    std::reference_wrapper<sf::RenderWindow> windowRef;
    std::reference_wrapper<entt::registry> registryRef;

  public:
    Render(entt::registry &registry, sf::RenderWindow &window);
    /**
     * @brief Updates the system by rendering entities and UI elements.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(sf::Time dt);
  };
}