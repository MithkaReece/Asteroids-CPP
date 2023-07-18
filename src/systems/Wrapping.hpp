#pragma once

#include <entt/entt.hpp>
#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"

namespace System
{
  /**
   * @brief The Wrapping class handles the wrapping behavior of entities.
   */
  class Wrapping : public System
  {
  private:
    sf::RenderWindow &window;

  public:
    /**
     * @brief Constructs a Wrapping object with the specified window.
     *
     * @param window The SFML render window.
     */
    Wrapping(sf::RenderWindow &window) : window(window) {}

    /**
     * @brief Update function for handling the wrapping behavior of entities.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Transform, Component::Velocity, Component::WrapperBoundary>();

      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;

        Component::Transform &transform = view.get<Component::Transform>(entity);
        Component::WrapperBoundary &boundary = view.get<Component::WrapperBoundary>(entity);
        const float boundarySize = boundary.boundarySize;

        // Wrap position horizontally
        if (transform.position.x < -boundarySize)
          transform.position.x = window.getSize().x + boundarySize;
        else if (transform.position.x > window.getSize().x + boundarySize)
          transform.position.x = -boundarySize;

        // Wrap position vertically
        if (transform.position.y < -boundarySize)
          transform.position.y = window.getSize().y + boundarySize;
        else if (transform.position.y > window.getSize().y + boundarySize)
          transform.position.y = -boundarySize;
      }
    }
  };
}