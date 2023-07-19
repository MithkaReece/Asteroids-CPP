#pragma once

#include <SFML/System/Time.hpp>
#include <functional>
#include "scenes/Scene.hpp"

namespace System
{
  /**
   * @brief The base System class for game systems.
   */
  class System
  {
  protected:
    std::reference_wrapper<entt::registry> registryRef;
    std::reference_wrapper<sf::RenderWindow> windowRef;
    std::reference_wrapper<Scene::Scene> sceneRef;
    static int nextID;

  public:
    int ID;

    System(entt::registry &registry, sf::RenderWindow &window, Scene::Scene &scene);

    /**
     * @brief Virtual destructor for proper inheritance.
     */
    // virtual ~System() {}
    virtual void update(sf::Time dt);
  };
}