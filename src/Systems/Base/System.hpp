#pragma once
#ifndef HEADER_SYSTEM
#define HEADER_SYSTEM
#include <entt/entt.hpp>
#include <SFML/System/Time.hpp>
#include <functional>
#include "GlobalObjects.hpp"

/**
 * @brief The base System class for game systems.
 */
class System
{
protected:
  static int nextID;

public:
  System();
  int ID;
  int Paused = false;

  /**
   * @brief Virtual destructor for proper inheritance.
   */
  // virtual ~System() {}
  virtual void update(sf::Time dt) {}
};
#endif