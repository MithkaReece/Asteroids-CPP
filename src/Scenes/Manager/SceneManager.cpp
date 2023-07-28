

#include "SceneManager.hpp"
extern entt::dispatcher globalDispatcher;

SceneManager::SceneManager(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : systemManagerRef(systemManager), registryRef(registry), windowRef(window)
{
  globalDispatcher.sink<EventDeath>().connect<&SceneManager::gotoLevel>(*this);
  globalDispatcher.sink<EventStartGame>().connect<&SceneManager::gotoLevel>(*this);
  globalDispatcher.sink<EventPause>().connect<&SceneManager::pause>(*this);
  globalDispatcher.sink<EventUnpause>().connect<&SceneManager::unpause>(*this);
  globalDispatcher.sink<EventMainMenu>().connect<&SceneManager::gotoMainMenu>(*this);
  // Add initialise scenes
  persistentScene = SceneGame(systemManager, registry, window);

  // addScene(SceneMainMenu);
  gotoMainMenu();
  //  gotoLevel();
}

// template <typename SceneType>
void SceneManager::addScene(std::function<std::unique_ptr<Scene>(SystemManager &, entt::registry &, sf::RenderWindow &)> sceneBuilder)
{
  scenes.push_back(std::move(sceneBuilder(systemManagerRef.get(), registryRef.get(), windowRef.get())));
  // scenes.emplace_back(std::make_unique<SceneType>(systemManagerRef.get(), registryRef.get(), windowRef.get()));
  //  sortScenesByPrecedence();
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
    if (scene->type == "Gameplay")
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
    if (scene->type == "Gameplay")
    {
      scene->unpause();
      break;
    }
  }
  removeScene("PauseMenu");
}

void SceneManager::removeScene(std::string type)
{
  scenes.erase(std::remove_if(scenes.begin(), scenes.end(),
                              [type](const std::unique_ptr<Scene> &scene)
                              {
                                return scene->type == type;
                              }),
               scenes.end());
}
