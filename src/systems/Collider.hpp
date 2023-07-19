#pragma once

#include <entt/entt.hpp>
#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Collider.hpp"

namespace System
{
  /**
   * @brief Class for updating colliders based on transform components.
   */
  class Collider : public System
  {
  public:
    Collider(entt::registry &registry, sf::RenderWindow &window, Scene::Scene &scene)
        : System::System(registry, window,scene) {}
    /**
     * @brief Updates the colliders based on transform components.
     *
     * @param registry The entity registry.
     * @param dt The elapsed time since the last update.
     */
    void update(sf::Time dt)
    {
      entt::registry &registry = registryRef.get();
      auto view = registry.view<Component::Collider, Component::Transform>();

      for (auto entity : view)
      {
        if (!registry.valid(entity))
        {
          continue;
        }
        Component::Collider &collider = view.get<Component::Collider>(entity);
        Component::Transform &transform = view.get<Component::Transform>(entity);

        sf::ConvexShape &shape = collider.shape;
        shape.setPosition(transform.position);
        shape.setScale(transform.scale);
        shape.setRotation(transform.rotation);
      }
    }
  };
}