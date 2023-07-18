#pragma once

#include <entt/entt.hpp>
#include "Scene0.hpp"

/**
 * @brief Class for managing scenes and switching between them.
 */
class SceneManager
{
private:
  std::reference_wrapper<entt::registry> registry; // Reference to the entity registry
  std::reference_wrapper<sf::RenderWindow> window; // Reference to the SFML render window
  std::vector<std::unique_ptr<Scene>> scenes;      // Vector of unique pointers to scenes
  int currentSceneIndex;                           // Index of the current active scene

public:
  /**
   * @brief Constructs a SceneManager object and switches to a given scene.
   *
   * @param registry The entity registry.
   * @param window The SFML render window.
   * @param startingSceneIndex The index of the starting scene.
   */
  SceneManager(entt::registry &registry, sf::RenderWindow &window, int startingSceneIndex)
      : registry(registry), window(window)
  {
    // Add scenes that exist
    scenes.emplace_back(std::make_unique<Scene0>());
    switchToScene(startingSceneIndex);
  }

  /**
   * @brief Switches to a scene by index.
   *
   * @param sceneIndex The index of the scene to switch to.
   */
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