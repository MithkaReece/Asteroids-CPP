#pragma once

#include "systems/System.hpp"

#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"

#include "Constants.h"

namespace System
{
  class OutOfBound : public System
  {
  private:
    sf::RenderWindow &window;

  public:
    OutOfBound(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Transform, Component::Velocity>(entt::exclude<Component::WrapperBoundary>);

      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;

        Component::Transform &transform = view.get<Component::Transform>(entity);

        // Delete outside boundary
        if (transform.position.x < -BOUNDARY || transform.position.x > window.getSize().x + BOUNDARY || transform.position.y < -BOUNDARY || transform.position.y > window.getSize().y + BOUNDARY)
          registry.destroy(entity);
      }
    }
  };
}