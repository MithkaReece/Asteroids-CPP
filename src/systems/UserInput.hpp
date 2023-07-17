#pragma once

#include "systems/System.hpp"
#include "components/PlayerInput.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "Constants.h"

#include <iostream>
namespace System
{
  class UserInput : public System
  {
  public:
    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::PlayerInput>();
      for (auto entity : view)
      {
        if (!registry.valid(entity))
        {
          continue;
        }

        Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);

        input.leftRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        input.rightRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        input.thrustPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        input.shootPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
      }
    }
  };
}