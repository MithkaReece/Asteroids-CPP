

#include "scenes/SceneManager.hpp"
//

namespace Scene
{
  Manager::Manager(System::Manager &systemManager, entt::registry &registry, sf::RenderWindow &window)
      : systemManagerRef(systemManager), registryRef(registry), windowRef(window), render(std::make_unique<System::Render>(registry, window))
  {
    // Add initialise scenes
    addScene<Level>();
  }

  template <typename SceneType>
  void Manager::addScene()
  {
    scenes.emplace_back(std::make_unique<SceneType>(registryRef.get(), windowRef.get()));
    scenes.back()->init();
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

  void Manager::updateSystems(sf::Time dt)
  {
    for (auto &scene : scenes)
      scene->updateSystems(dt);
  }

  void Manager::updateRenderSystem(sf::Time dt) { render->update(dt); }

  void Manager::sortScenesByPrecedence()
  {
    /*std::sort(scenes.begin(), scenes.end(), [](auto &a, auto &b)
              { return a->precedence() < b->precedence(); });*/
  }
}