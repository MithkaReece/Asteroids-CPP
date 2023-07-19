#pragma once
#ifndef HEADER_SCENE_MANAGER
#define HEADER_SCENE_MANAGER
#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <functional>

#include "SystemRender.hpp"
#include "SystemManager.hpp"

#include "Scene.hpp"
#include "SceneGame.hpp"
#include "SceneGameUI.hpp"

/**
 * @brief Class for managing scenes and switching between them.
 */
class SceneManager
{
private:
  std::vector<std::unique_ptr<Scene>> scenes; // Vector of unique pointers to all scenes
  std::reference_wrapper<SystemManager> systemManagerRef;

public:
  std::reference_wrapper<entt::registry> registryRef; // Reference to the entity registry
  std::reference_wrapper<sf::RenderWindow> windowRef; // Reference to the SFML render window
  /**
   * @brief Constructs a SceneManager object and switches to a given scene.
   *
   * @param registry The entity registry.
   * @param window The SFML render window.
   * @param startingSceneIndex The index of the starting scene.
   */
  SceneManager(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

  template <typename SceneType>
  void addScene();

  template <typename SceneType>
  void removeScene();

  entt::registry &getRegistry();

  sf::RenderWindow &getWindow();

private:
  // Sort scenes based on precedence
  void sortScenesByPrecedence();
};
#endif