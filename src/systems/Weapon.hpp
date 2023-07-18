#pragma once

#include "systems/System.hpp"

#include "components/Transform.hpp"
#include "components/PlayerInput.hpp"
#include "components/Weapon.hpp"

#include "entities/Bullet.hpp"

#include "Constants.h"

// Temp
#include <iostream>

namespace System
{
  /**
   * @brief The Weapon class manages the player's weapon system.
   */
  class Weapon : public System
  {
  public:
    /**
     * @brief Update function for managing the player's weapon system.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Transform, Component::PlayerInput, Component::Weapon, Component::Velocity>();
      for (auto entity : view)
      {
        if (!registry.valid(entity))
        {
          continue;
        }
        Component::Transform &transform = view.get<Component::Transform>(entity);
        Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);
        Component::Weapon &weapon = view.get<Component::Weapon>(entity);
        Component::Velocity &velocity = view.get<Component::Velocity>(entity);

        if (input.shootPressed && weapon.remainingCooldown <= sf::Time::Zero)
        {
          // Calculate the forward vector based on the player's rotation
          sf::Vector2f forwardVector = sf::Vector2f(
              std::cos(transform.rotation * DEG_TO_RAD),
              std::sin(transform.rotation * DEG_TO_RAD));

          // Calculate forward velocity
          const float magnitude = 500.0f;
          sf::Vector2f bulletVelocity = forwardVector * magnitude + velocity.velocity;

          // Offset the position from the player
          sf::Vector2f position = transform.position;
          position += forwardVector * transform.scale.x;

          // Create a bullet entity with the calculated position, velocity, and rotation
          Entity::createBullet(registry, position, bulletVelocity, transform.rotation);

          // Reset the remaining cooldown to the specified cooldown duration
          weapon.remainingCooldown = weapon.cooldownDuration;
          input.shootPressed = false;
        }

        // Update the cooldown timer
        if (weapon.remainingCooldown > sf::Time::Zero)
          weapon.remainingCooldown -= dt;
      }
    }
  };
}