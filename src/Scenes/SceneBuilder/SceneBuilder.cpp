#include "SceneBuilder.hpp"

std::unique_ptr<Scene> SceneGame(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>(systemManager, registry, window);
  EntityGame(*scene, window);
  return scene;
}

std::unique_ptr<Scene> SceneMainMenu(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>(systemManager, registry, window);

  EntityMenuItem(*scene, window, MenuItemID::StartGame, "Start Game", sf::Vector2f(0.5f, 0.2f), sf::Vector2f(0.05f, 0.05f));
  EntityMenuItem(*scene, window, MenuItemID::Exit, "Exit", sf::Vector2f(0.5f, 0.5f), sf::Vector2f(0.05f, 0.05f));

  scene->addSystem<SystemMenuInput>();
  scene->addSystem<SystemMouseHover>();

  return scene;
}

std::unique_ptr<Scene> SceneGameplay(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>(systemManager, registry, window);
  // Define entities
  EntityPlayer(*scene, window);
  // EntitycreateScoreUI(*this);

  // Define systems
  // Spawners
  scene->addSystem<SystemAsteroidSpawner>(sf::milliseconds(1000));
  //  Input
  scene->addSystem<SystemUserInput>();
  //  Input responses
  scene->addSystem<SystemPlayerThrust>();
  scene->addSystem<SystemPlayerRotate>();
  scene->addSystem<SystemWeapon>();

  // Applying velocity
  scene->addSystem<SystemMovement>();
  //  Collider positioning
  scene->addSystem<SystemCollider>();
  //  Keep objects within boundary or deleted
  scene->addSystem<SystemWrapping>();
  scene->addSystem<SystemOutOfBound>();

  // Detects collisions
  scene->addSystem<SystemCollision>();
  return scene;
}

std::unique_ptr<Scene> SceneHUD(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>(systemManager, registry, window);
  EntityLevelUI(*scene, window);

  scene->addSystem<SystemScore>();
  scene->addSystem<SystemLives>();
  return scene;
}

std::unique_ptr<Scene> ScenePauseMenu(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>(systemManager, registry, window);
  // Create pause menu entity

  // Add system for menu input

  return scene;
}