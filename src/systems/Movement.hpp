#pragma once

#include "systems/System.hpp"
#include <SFML/Graphics.hpp>

#include "components/Transform.hpp"
#include "components/Velocity.hpp"
namespace System
{
  /**
   * @brief The Movement class updates the position of entities based on their velocity.
   */
  class Movement : public System
  {
  public:
    /**
     * @brief Updates the position of entities based on their velocity.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Transform, Component::Velocity>();

      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;

        // Get the velocity and transform components of the entity
        Component::Velocity &velocity = view.get<Component::Velocity>(entity);
        Component::Transform &transform = view.get<Component::Transform>(entity);

        // Update the position based on the velocity
        transform.position += velocity.velocity * dt.asSeconds();
      }
    }
  };
}