#pragma once
#ifndef HEADER_SYSTEM
#define HEADER_SYSTEM
#include <SFML/System/Time.hpp>
#include <functional>
#include "Scene.hpp"
#include "ISystem.hpp"

/**
 * @brief The base System class for game systems.
 */
class System : public ISystem
{
protected:
  std::reference_wrapper<entt::registry> registryRef;
  std::reference_wrapper<sf::RenderWindow> windowRef;
  std::reference_wrapper<Scene> sceneRef;

public:
  System(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  /**
   * @brief Virtual destructor for proper inheritance.
   */
  // virtual ~System() {}
  virtual void update(sf::Time dt) {}
};
#endif