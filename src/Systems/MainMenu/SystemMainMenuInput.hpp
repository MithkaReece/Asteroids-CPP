#pragma once
#ifndef HEADER_SCENE_MANAGER
#define HEADER_SCENE_MANAGER

#include "System.hpp"

#include <SFML/Window/Keyboard.hpp>

class SystemMainMenuInput : public System
{
public:
  SystemMainMenuInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  void update(sf::Time dt);
};

#endif