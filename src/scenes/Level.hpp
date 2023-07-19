#pragma once

#include <entt/entt.hpp>
#include "scenes/Scene.hpp"

#include "systems/Movement.hpp"
#include "systems/Collision.hpp"
#include "systems/Wrapping.hpp"
#include "systems/UserInput.hpp"
#include "systems/AsteroidSpawner.hpp"
#include "systems/Collider.hpp"
#include "systems/PlayerThrust.hpp"
#include "systems/PlayerRotate.hpp"
#include "systems/Weapon.hpp"
#include "systems/OutOfBound.hpp"

#include "entities/Player.hpp"
#include "entities/ScoreUI.hpp"

namespace Scene
{
  /**
   * @brief Implementation of Scene0 class, representing the first scene of the game.
   */
  class Level : public Scene
  {
  public:
    Level(System::Manager &systemManager, entt::registry &registry, sf::RenderWindow &window)
        : Scene(systemManager, registry, window)
    {
      // Define entities
      Entity::createPlayer(*this, windowRef.get());
      // Entity::createScoreUI(*this);

      // Define systems
      // Spawners
      addSystem<System::AsteroidSpawner>(sf::milliseconds(2000));
      //  Input
      addSystem<System::UserInput>();
      //  Input responses
      addSystem<System::PlayerThrust>();
      addSystem<System::PlayerRotate>();
      addSystem<System::Weapon>();

      // Applying velocity
      addSystem<System::Movement>();
      //  Collider positioning
      addSystem<System::Collider>();
      //  Keep objects within boundary or deleted
      addSystem<System::Wrapping>();
      addSystem<System::OutOfBound>();

      // Detects collisions
      addSystem<System::Collision>();
    }

    int precedence() override { return 0; }
  };
}