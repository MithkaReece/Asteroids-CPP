#include "SceneManager.hpp"
extern entt::dispatcher globalDispatcher;

SceneManager &SceneManager::getInstance()
{
  static SceneManager instance;
  return instance;
}

Scene dummyScene(""); // Create a dummy scene instance

Scene &SceneManager::getScene(const std::string &id)
{
  for (const auto &scene : SceneManager::getInstance().scenes)
  {
    if (scene->ID == id)
    {
      return *scene;
    }
  }
  std::cout << "Could not find scene " + id + "\n";
  return dummyScene; // Scene not found
}

SceneManager::SceneManager()
{
  globalDispatcher.sink<EventDeath>().connect<&SceneManager::gotoLevel>(*this);
  globalDispatcher.sink<EventStartGame>().connect<&SceneManager::gotoLevel>(*this);
  globalDispatcher.sink<EventPause>().connect<&SceneManager::pause>(*this);
  globalDispatcher.sink<EventUnpause>().connect<&SceneManager::unpause>(*this);
  globalDispatcher.sink<EventMainMenu>().connect<&SceneManager::gotoMainMenu>(*this);
  //   Add initialise scenes
  persistentScene = SceneGame();

  // addScene(SceneMainMenu);
  gotoMainMenu();
  //  gotoLevel();
}

// template <typename SceneType>
void SceneManager::addScene(std::function<std::unique_ptr<Scene>()> sceneBuilder)
{
  scenes.push_back(std::move(sceneBuilder()));
}

void SceneManager::sortScenesByPrecedence()
{
  /*std::sort(scenes.begin(), scenes.end(), [](auto &a, auto &b)
            { return a->precedence() < b->precedence(); });*/
}

void SceneManager::clearScenes()
{
}
#include <iostream>
void SceneManager::gotoMainMenu()
{
  std::cout << "====MAIN MENU====\n";
  scenes.clear();
  addScene(SceneMainMenu);
  std::cout << "====SCENES DELETED====\n";

  // auto view = registryRef.get().view<ComponentScene>();
  // for (auto [entity, sceneInfo] : view.each())
  //{
  // sceneInfo.inGame = false;
  //}
}

void SceneManager::gotoLevel()
{
  // ClearScenes
  scenes.clear();
  addScene(SceneGameplay);
  addScene(SceneHUD);

  // auto view = registryRef.get().view<ComponentScene>();
  // for (auto [entity, sceneInfo] : view.each())
  // sceneInfo.inGame = true;
}

void SceneManager::pause()
{
  for (const auto &scene : scenes)
  {
    if (scene->ID == "Gameplay")
    {
      scene->pause();
      break;
    }
  }

  addScene(ScenePauseMenu);
}
void SceneManager::unpause()
{
  for (const auto &scene : scenes)
  {
    if (scene->ID == "Gameplay")
    {
      scene->unpause();
      break;
    }
  }
  removeScene("PauseMenu");
}

void SceneManager::removeScene(std::string id)
{
  scenes.erase(std::remove_if(scenes.begin(), scenes.end(),
                              [id](const std::unique_ptr<Scene> &scene)
                              {
                                return scene->ID == id;
                              }),
               scenes.end());
}
