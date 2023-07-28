#include "SceneBuilder.hpp"

std::unique_ptr<Scene> SceneGame(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("Game", systemManager, registry, window);
  EntityGame(*scene, window);

  scene->addSystem<SystemMenuInput>();
  scene->addSystem<SystemMouseHover>();

  return scene;
}
#include <iostream>
std::unique_ptr<Scene> SceneMainMenu(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("MainMenu", systemManager, registry, window);

  EntityMenuItem(*scene, window, "Start Game", sf::Vector2f(0.5f, 0.3f), sf::Vector2f(0.05f, 0.05f), [](entt::registry &registry, sf::RenderWindow &window, entt::dispatcher &dispatcher)
                 {
                    std::cout<<"Test\n";
                    dispatcher.trigger<EventStartGame>();
                    auto view = registry.view<ComponentScene, ComponentBackground>();
                    for (auto [entity, sceneInfo, background] : view.each())
                    {
                      sceneInfo.inGame = true;
                      background.textureID = "background2";
                    } });
  EntityMenuItem(*scene, window, "Exit", sf::Vector2f(0.5f, 0.6f), sf::Vector2f(0.05f, 0.05f), [](entt::registry &registry, sf::RenderWindow &window, entt::dispatcher &dispatcher)
                 { window.close(); });

  return scene;
}

std::unique_ptr<Scene> SceneGameplay(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("Gameplay", systemManager, registry, window);
  // Define entities
  EntityPlayer(*scene, window);

  // Define systems
  // Spawners

  scene->addSystem<SystemAsteroidSpawner>(sf::milliseconds(1000));
  //   Input
  scene->addSystem<SystemUserInput>();
  //   Input responses
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
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("HUD", systemManager, registry, window);
  EntityLevelUI(*scene, window, sf::Vector2f(0.08f, 0.01f), "Score");
  EntityLevelUI(*scene, window, sf::Vector2f(0.92f, 0.01f), "Lives");
  EntityLevelUI(*scene, window, sf::Vector2f(0.5f, 0.01f), "HighScore");

  scene->addSystem<SystemHUD>();

  scene->addSystem<SystemPauseMenuToggle>();
  return scene;
}
#include <iostream>
std::unique_ptr<Scene> ScenePauseMenu(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("PauseMenu", systemManager, registry, window);
  // Create pause menu entity
  EntityMenuItem(*scene, window, "Resume", sf::Vector2f(0.5f, 0.3f), sf::Vector2f(0.05f, 0.05f), [](entt::registry &registry, sf::RenderWindow &window, entt::dispatcher &dispatcher)
                 {
                   dispatcher.trigger<EventUnpause>();
                   auto view = registry.view<ComponentScene>();
                   for (auto [entity, sceneInfo] : view.each())
                   {
                     sceneInfo.pauseMenu = false;
                   } });
  EntityMenuItem(*scene, window, "Main Menu", sf::Vector2f(0.5f, 0.6f), sf::Vector2f(0.05f, 0.05f), [](entt::registry &registry, sf::RenderWindow &window, entt::dispatcher &dispatcher)
                 {
                    dispatcher.trigger<EventMainMenu>();
                    /*auto view = registry.view<ComponentScene>();
                    for (auto [entity, sceneInfo] : view.each())
                    {
                      sceneInfo.inGame = false;
                    } */ });
  // Add system for menu input
  return scene;
}