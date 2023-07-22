#pragma once
#ifndef HEADER_SYSTEM_PAUSE_MENU_TOGGLE
#define HEADER_SYSTEM_PAUSE_MENU_TOGGLE

#include <SFML/Graphics.hpp>
#include "System.hpp"

#include "EventPause.hpp"
#include "EventUnpause.hpp"

class SystemPauseMenuToggle : public System
{
public:
  SystemPauseMenuToggle(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  void update(sf::Time dt);
};

#endif