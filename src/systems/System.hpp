#pragma once

#include <SFML/System/Time.hpp>
#include <functional>
#include "scenes/SceneIManager.hpp"
#include "scenes/IScene.hpp"
#include "systems/ISystem.hpp"

namespace System
{
  /**
   * @brief The base System class for game systems.
   */
  class System : ISystem
  {
  protected:
    std::reference_wrapper<Scene::IManager> sceneManagerRef;
    std::reference_wrapper<Scene::IScene> sceneRef;

  public:
    System(std::reference_wrapper<Scene::IManager> sceneManager, Scene::IScene &scene);

    /**
     * @brief Virtual destructor for proper inheritance.
     */
    // virtual ~System() {}
    virtual void update(sf::Time dt);
  };
}