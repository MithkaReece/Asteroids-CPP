#pragma once
#ifndef HEADER_SYSTEM_UPDATE_UI
#define HEADER_SYSTEM_UPDATE_UI

#include "System.hpp"
#include "ComponentLives.hpp"
#include "ComponentScore.hpp"
#include "ComponentHighScore.hpp"
#include "ComponentText.hpp"
#include <string>

class SystemHUD : public System
{
public:
  SystemHUD(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  void update(sf::Time dt);
};

#endif