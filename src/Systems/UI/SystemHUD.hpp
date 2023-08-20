#pragma once
#ifndef HEADER_SYSTEM_UPDATE_UI
#define HEADER_SYSTEM_UPDATE_UI

#include "System.hpp"
#include "ComponentLives.hpp"
#include "ComponentScore.hpp"
#include "ComponentHighScore.hpp"
#include "ComponentText.hpp"
#include <string>

#include "GlobalObjects.hpp"

class SystemHUD : public System
{
public:
  SystemHUD();

  void update(sf::Time dt);
};

#endif