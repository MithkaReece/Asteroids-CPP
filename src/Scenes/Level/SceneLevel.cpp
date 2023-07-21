#include "SceneLevel.hpp"

SceneLevel::SceneLevel(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : Scene(systemManager, registry, window)
{
  // Define entities
  EntityPlayer(*this, windowRef.get());
  // EntitycreateScoreUI(*this);

  // Define systems
  // Spawners
  addSystem<SystemAsteroidSpawner>(sf::milliseconds(2000));
  //  Input
  addSystem<SystemUserInput>();
  //  Input responses
  addSystem<SystemPlayerThrust>();
  addSystem<SystemPlayerRotate>();
  addSystem<SystemWeapon>();

  // Applying velocity
  addSystem<SystemMovement>();
  //  Collider positioning
  addSystem<SystemCollider>();
  //  Keep objects within boundary or deleted
  addSystem<SystemWrapping>();
  addSystem<SystemOutOfBound>();

  // Detects collisions
  addSystem<SystemCollision>();
}
