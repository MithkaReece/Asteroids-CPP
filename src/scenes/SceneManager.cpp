

#include "scenes/SceneManager.hpp"
//

namespace Scene
{
  Manager::Manager(entt::registry &registry, sf::RenderWindow &window)
      : IManager(registry, window), render(std::make_unique<System::Render>(*this))
  {
    // Add initialise scenes
    addScene<Level>();
  }

  template <typename SceneType>
  void Manager::addScene()
  {
    scenes.emplace_back(std::make_unique<SceneType>(*this));
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

  entt::registry &Manager::getRegistry() { return registryRef.get(); }

  sf::RenderWindow &Manager::getWindow() { return windowRef.get(); }

  void Manager::sortScenesByPrecedence()
  {
    /*std::sort(scenes.begin(), scenes.end(), [](auto &a, auto &b)
              { return a->precedence() < b->precedence(); });*/
  }
}

/**
 * @brief Class for managing scenes and switching between them.

class SceneManager
{
private:
  // std::vector<std::unique_ptr<Scene>> scenes; // Vector of unique pointers to all scenes
  // std::unique_ptr<Render> render;

  // static Manager *instance;

public:
  /*std::reference_wrapper<entt::registry> registryRef; // Reference to the entity registry
  std::reference_wrapper<sf::RenderWindow> windowRef; // Reference to the SFML render window
  static Manager &getInstance()
  {
    assert(instance != nullptr && "SceneManager instance not created!");
    return *instance;
  }*/

/**
 * @brief Constructs a SceneManager object and switches to a given scene.
 *
 * @param registry The entity registry.
 * @param window The SFML render window.
 * @param startingSceneIndex The index of the starting scene.

SceneManager(entt::registry &registry, sf::RenderWindow &window)
// : registryRef(registry), windowRef(window), render(std::make_unique<Render>(*this))
{
  // Add initialise scenes
  // addScene<Level>();
  // instance = this;
}

    template <typename SceneType>
    void addScene()
    {
      scenes.emplace_back(std::make_unique<SceneType>(registry, window));
      scenes.back()->init(*this);
      sortScenesByPrecedence();
    }

    template <typename SceneType>
    void removeScene()
    {
      // Find the scene with the specified type and remove it
      auto it = std::find_if(scenes.begin(), scenes.end(), [](const auto &scene)
                             { return dynamic_cast<SceneType *>(scene.get()) != nullptr; });
      if (it == scenes.end())
        return;
      it.erase();       // Remove entities of scene
      scenes.erase(it); // Remove scene from active scenes
    }

    void updateSystems(sf::Time dt)
    {
      for (auto &scene : scenes)
        scene->updateSystems(dt);
    }

    void updateRenderSystem(sf::Time dt) { render->update(dt); }

    entt::registry &getRegistry() { return registry.get(); }

    sf::RenderWindow &getWindow() { return window.get(); }

  private:
    void sortScenesByPrecedence()
    {
      std::sort(scenes.begin(), scenes.end(), [](auto &a, auto &b)
                { return a->precedence() < b->precedence(); });
    }
};

// Have to define this or it breaks
// Manager *Manager::instance = nullptr;
*/