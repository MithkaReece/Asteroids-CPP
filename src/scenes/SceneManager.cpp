

#include "scenes/SceneManager.hpp"
//

namespace Scene
{
  Manager::Manager(System::Manager &systemManager, entt::registry &registry, sf::RenderWindow &window)
      : systemManagerRef(systemManager), registryRef(registry), windowRef(window)
  {
    // Add initialise scenes
    addScene<Level>();
  }

  template <typename SceneType>
  void Manager::addScene()
  {
    scenes.emplace_back(std::make_unique<SceneType>(systemManagerRef.get(), registryRef.get(), windowRef.get()));
    // sortScenesByPrecedence();
  }

  template <typename SceneType>
  void Manager::removeScene()
  {
    // Find the scene with the specified type and remove it
    /*auto it = std::find_if(scenes.begin(), scenes.end(), [](const auto &scene)
                           { return dynamic_cast<SceneType *>(scene.get()) != nullptr; });
    if (it == scenes.end())
      return;
    it.erase();       // Remove entities of scene
    scenes.erase(it); // Remove scene from active scenes*/
  }

  void Manager::sortScenesByPrecedence()
  {
    /*std::sort(scenes.begin(), scenes.end(), [](auto &a, auto &b)
              { return a->precedence() < b->precedence(); });*/
  }
}