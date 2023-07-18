#pragma once

#include "systems/System.hpp"

#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"

#include "Constants.h"

namespace System
{
  /**
   * @brief The OutOfBound class removes entities that are outside the game boundary.
   */
  class OutOfBound : public System
  {
  private:
    sf::RenderWindow &window;

  public:
    /**
     * @brief Constructs an OutOfBound object with a reference to the game window.
     *
     * @param window The sf::RenderWindow object representing the game window.
     */
    OutOfBound(sf::RenderWindow &window) : window(window) {}

    /**
     * @brief Updates the system by removing entities that are outside the game boundary.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Transform, Component::Velocity>(entt::exclude<Component::WrapperBoundary>);

      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;

        // Get the transform component of the entity
        Component::Transform &transform = view.get<Component::Transform>(entity);

        // Delete outside boundary
        if (transform.position.x < -BOUNDARY || transform.position.x > window.getSize().x + BOUNDARY || transform.position.y < -BOUNDARY || transform.position.y > window.getSize().y + BOUNDARY)
          registry.destroy(entity);
      }
    }
  };
}