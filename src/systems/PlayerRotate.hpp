#pragma once

#include "systems/System.hpp"

#include "components/PlayerInput.hpp"
#include "components/Transform.hpp"

namespace System
{
  /**
   * @brief The PlayerRotate class handles the rotation of player-controlled entities.
   */
  class PlayerRotate : public System
  {
  public:
    PlayerRotate(std::reference_wrapper<Scene::IManager> sceneManager, Scene::IScene &scene)
        : System::System(sceneManager, scene) {}
    /**
     * @brief Updates the system by handling rotation of player-controlled entities.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(sf::Time dt)
    {
      entt::registry &registry = sceneManagerRef.get().registryRef.get();
      auto view = registry.view<Component::PlayerInput, Component::Transform>();

      for (auto entity : view)
      {
        if (!registry.valid(entity))
        {
          continue;
        }

        // Get the player input and transform components of the entity
        Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);
        Component::Transform &transform = view.get<Component::Transform>(entity);

        // Rotate the entity based on player input
        if (input.leftRotatePressed)
        {
          transform.rotation -= 200.0f * dt.asSeconds();
          input.leftRotatePressed = false;
        }

        if (input.rightRotatePressed)
        {
          transform.rotation += 200.0f * dt.asSeconds();
          input.rightRotatePressed = false;
        }
      }
    }
  };
}