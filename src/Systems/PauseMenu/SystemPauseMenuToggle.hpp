#pragma once
#ifndef HEADER_SYSTEM_PAUSE_MENU_TOGGLE
#define HEADER_SYSTEM_PAUSE_MENU_TOGGLE

#include <SFML/Graphics.hpp>
#include "System.hpp"

#include "EventPause.hpp"
#include "EventUnpause.hpp"

#include "ComponentScene.hpp"

class SystemPauseMenuToggle : public System
{
public:
  SystemPauseMenuToggle();

  void update(sf::Time dt);
};

#endif