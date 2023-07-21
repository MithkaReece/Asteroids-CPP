#pragma once
#ifndef HEADER_SYSTEM_MOUSE_HOVER
#define HEADER_SYSTEM_MOUSE_HOVER

#include "System.hpp"

#include "ComponentMenuItem.hpp"

class SystemMouseHover : public System
{
public:
  SystemMouseHover(entt::registry &registry, sf::RenderWindow &window, Scene &scene);
  void update(sf::Time dt);
};

#endif