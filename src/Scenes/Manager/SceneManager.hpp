#pragma once
#ifndef HEADER_SCENE_MANAGER
#define HEADER_SCENE_MANAGER
#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <functional>

#include "Scene.hpp"
#include "SceneBuilder.hpp"

#include "EventDeath.hpp"
#include "EventStartGame.hpp"
#include "EventMainMenu.hpp"
#include "EventPause.hpp"
#include "EventUnpause.hpp"
/**
 * @brief Class for managing scenes and switching between them.
 */
class SceneManager
{
private:
  std::vector<std::unique_ptr<Scene>> scenes; // Vector of unique pointers to all scenes
  std::unique_ptr<Scene> persistentScene;

public:
  /**
   * @brief Constructs a SceneManager object and switches to a given scene.
   */
  static SceneManager &getInstance();

  static Scene &getScene(const std::string &id);

  void addScene(std::function<std::unique_ptr<Scene>()> sceneBuilder);

  entt::registry &getRegistry();

  sf::RenderWindow &getWindow();

private:
  SceneManager();

  SceneManager(const SceneManager &) = delete;
  SceneManager &operator=(const SceneManager &) = delete;

  // Sort scenes based on precedence
  void sortScenesByPrecedence();

  void clearScenes();

  void gotoMainMenu();

  void gotoLevel();

  void pause();
  void unpause();

  void removeScene(std::string type);
};
#endif