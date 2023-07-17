#pragma once

#include <entt/entt.hpp>
#include "Scene0.hpp"

class SceneManager
{
private:
  std::reference_wrapper<entt::registry> registry;
  std::reference_wrapper<sf::RenderWindow> window;
  std::vector<std::unique_ptr<Scene>> scenes;
  int currentSceneIndex;

public:
  SceneManager(entt::registry &registry, sf::RenderWindow &window, int startingSceneIndex)
      : registry(registry), window(window)
  {
    // Add scenes that exist
    scenes.emplace_back(std::make_unique<Scene0>());

    switchToScene(startingSceneIndex);
  }

  // Switch to a scene by index
  void switchToScene(int sceneIndex)
  {
    // Valid scene index
    assert(sceneIndex >= 0 && sceneIndex < scenes.size());
    // Clear and init scene
    registry.get().clear();
    currentSceneIndex = sceneIndex;
    scenes[currentSceneIndex]->init(registry.get(), window.get());
  }
};