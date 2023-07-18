#pragma once

#include "systems/System.hpp"
#include "components/PlayerInput.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "Constants.h"

#include <iostream>
namespace System
{
  /**
   * @brief The UserInput class handles updating player input based on keyboard events.
   */
  class UserInput : public System
  {
  public:
    /**
     * @brief Update function for updating player input.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::PlayerInput>();
      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;

        Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);

        // Update input based on keyboard events
        input.leftRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        input.rightRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        input.thrustPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        input.shootPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
      }
    }
  };
}