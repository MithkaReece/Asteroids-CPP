#pragma once
#ifndef HEADER_SYSTEM_SPAWNER
#define HEADER_SYSTEM_SPAWNER

#include <entt/entt.hpp>
#include "System.hpp"
#include "EntityAsteroid.hpp"

class SystemSpawner : public System
{
  sf::Time timer;

public:
  SystemSpawner();

  void update(sf::Time dt);
};

#endif