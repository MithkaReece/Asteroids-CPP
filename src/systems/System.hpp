#pragma once

#include <SFML/System/Time.hpp>
#include <entt/entt.hpp>
namespace System
{
  /**
   * @brief The base System class for game systems.
   */
  class System
  {
  public:
    /**
     * @brief Virtual destructor for proper inheritance.
     */
    virtual ~System() {}

    /**
     * @brief Update function for the system.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    virtual void update(entt::registry &registry, sf::Time dt) = 0;
  };
}