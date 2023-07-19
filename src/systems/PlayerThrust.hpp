#pragma once

#include "systems/System.hpp"

#include "components/Player.hpp"
#include "components/PlayerInput.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
namespace System
{
  /**
   * @brief The PlayerThrust class handles applying thrust to player-controlled entities.
   */
  class PlayerThrust : public System
  {
  public:
    PlayerThrust(std::reference_wrapper<Scene::IManager> sceneManager, Scene::IScene &scene)
        : System::System(sceneManager, scene) {}
    /**
     * @brief Updates the system by applying thrust to player-controlled entities.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(sf::Time dt)
    {
      entt::registry &registry = sceneManagerRef.get().registryRef.get();
      auto view = registry.view<Component::Player, Component::PlayerInput, Component::Transform, Component::Velocity>();
      for (auto entity : view)
      {
        if (!registry.valid(entity))
        {
          continue;
        }

        // Get the player, player input, transform, and velocity components of the entity
        Component::Player &player = view.get<Component::Player>(entity);
        Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);
        Component::Transform &transform = view.get<Component::Transform>(entity);
        Component::Velocity &velocity = view.get<Component::Velocity>(entity);

        // Apply thrust to the entity if the thrust button is pressed
        if (input.thrustPressed)
        {
          // Calculate the forward vector based on the entity's rotation
          sf::Vector2f forwardVector = sf::Vector2f(
              std::cos(transform.rotation * DEG_TO_RAD),
              std::sin(transform.rotation * DEG_TO_RAD));

          // Accelerate the entity forward by adding the forward vector scaled by acceleration and time delta
          velocity.velocity += forwardVector * player.acceleration * dt.asSeconds();

          // Reset the thrust button state
          input.thrustPressed = false;
        }
      }
    }
  };
}