

#include "SceneManager.hpp"
extern entt::dispatcher globalDispatcher;

SceneManager::SceneManager(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : systemManagerRef(systemManager), registryRef(registry), windowRef(window)
{
  globalDispatcher.sink<EventDeath>().connect<&SceneManager::gotoLevel>(*this);
  // Add initialise scenes
  persistentScene = std::make_unique<SceneGame>(systemManager, registry, window);

  gotoLevel();
}

template <typename SceneType>
void SceneManager::addScene()
{
  scenes.emplace_back(std::make_unique<SceneType>(systemManagerRef.get(), registryRef.get(), windowRef.get()));
  // sortScenesByPrecedence();
}

template <typename SceneType>
void SceneManager::removeScene()
{
  // Find the scene with the specified type and remove it
  /*auto it = std::find_if(scenes.begin(), scenes.end(), [](const auto &scene)
                         { return dynamic_cast<SceneType *>(scene.get()) != nullptr; });
  if (it == scenes.end())
    return;
  it.erase();       // Remove entities of scene
  scenes.erase(it); // Remove scene from active scenes*/
}

void SceneManager::sortScenesByPrecedence()
{
  /*std::sort(scenes.begin(), scenes.end(), [](auto &a, auto &b)
            { return a->precedence() < b->precedence(); });*/
}

void SceneManager::clearScenes()
{
}

void SceneManager::gotoMainMenu()
{
  scenes.clear();
  // Clear scenes
  // Add Scenes
}

void SceneManager::gotoLevel()
{
  // ClearScenes
  scenes.clear();
  addScene<SceneLevel>();
  addScene<SceneLevelUI>();
}

/** Main Menu   Level
 *  Game Scene  Game Scene
 *  Menu Scene  Level Scene
 *              Level UI Scene
 *
 *
 *
 *
 *
 */