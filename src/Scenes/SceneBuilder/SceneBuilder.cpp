#include "SceneBuilder.hpp"
#include <iostream>
std::unique_ptr<Scene> SceneGame()
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("Game");
  EntityGame(*scene);
  scene->addSystem<SystemMenuInput>();
  scene->addSystem<SystemMouseHover>();

  return scene;
}
#include <iostream>
std::unique_ptr<Scene> SceneMainMenu()
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("MainMenu");
  // Start Game Button
  EntityMenuItem(*scene, "Start Game", sf::Vector2f(0.5f, 0.3f), sf::Vector2f(0.05f, 0.05f), [](entt::dispatcher &dispatcher) { // OnClick
    std::cout << "Test\n";
    dispatcher.trigger<EventStartGame>();
    auto view = GlobalObjects::getRegistry().view<ComponentScene, ComponentBackground>();
    for (auto [entity, sceneInfo, background] : view.each())
    {
      sceneInfo.inGame = true;
      background.textureID = "background2";
    }
  });
  // Exit Button
  EntityMenuItem(*scene, "Exit", sf::Vector2f(0.5f, 0.6f), sf::Vector2f(0.05f, 0.05f), [](entt::dispatcher &dispatcher)
                 { GlobalObjects::getWindow().close(); });

  return scene;
}

std::unique_ptr<Scene> SceneGameplay()
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("Gameplay");
  // Define entities
  EntityPlayer(*scene);

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

std::unique_ptr<Scene> SceneHUD()
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("HUD");
  EntityLevelUI(*scene, sf::Vector2f(0.08f, 0.01f), "Score");
  EntityLevelUI(*scene, sf::Vector2f(0.92f, 0.01f), "Lives");
  EntityLevelUI(*scene, sf::Vector2f(0.5f, 0.01f), "HighScore");

  scene->addSystem<SystemHUD>();

  scene->addSystem<SystemPauseMenuToggle>();
  return scene;
}
#include <iostream>
std::unique_ptr<Scene> ScenePauseMenu()
{
  std::unique_ptr<Scene> scene = std::make_unique<Scene>("PauseMenu");
  // Resume Button
  EntityMenuItem(*scene, "Resume", sf::Vector2f(0.5f, 0.3f), sf::Vector2f(0.05f, 0.05f), [](entt::dispatcher &dispatcher) { // Onclick
    dispatcher.trigger<EventUnpause>();
    auto view = GlobalObjects::getRegistry().view<ComponentScene>();
    for (auto [entity, sceneInfo] : view.each())
    {
      sceneInfo.pauseMenu = false;
    }
  });
  // Main Menu Button
  EntityMenuItem(*scene, "Main Menu", sf::Vector2f(0.5f, 0.6f), sf::Vector2f(0.05f, 0.05f), [](entt::dispatcher &dispatcher) { // Onclick
    dispatcher.trigger<EventMainMenu>();
    auto view = GlobalObjects::getRegistry().view<ComponentScore>();
    for (auto [entity, score] : view.each())
    {
      score.value = 0;
    }

    /*auto view = GlobalObjects::getRegistry().view<ComponentScene>();
    for (auto [entity, sceneInfo] : view.each())
    {
      sceneInfo.inGame = false;
    } */
  });
  // Add system for menu input
  return scene;
}