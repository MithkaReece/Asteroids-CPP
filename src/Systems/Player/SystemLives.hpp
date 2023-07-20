#pragma once
#ifndef HEADER_SYSTEM_LIVES
#define HEADER_SYSTEM_LIVES

#include "System.hpp"
#include "ComponentLives.hpp"
#include "ComponentLivesText.hpp"
#include <string>

class SystemLives : public System
{
public:
  SystemLives(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  void update(sf::Time dt);
};

#endif