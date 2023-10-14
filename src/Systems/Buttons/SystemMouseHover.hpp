#pragma once
#ifndef HEADER_SYSTEM_MOUSE_HOVER
#define HEADER_SYSTEM_MOUSE_HOVER

#include "System.hpp"

#include "ComponentMenuItem.hpp"
#include "Input.hpp"

class SystemMouseHover : public System
{
public:
  SystemMouseHover();
  void update(sf::Time dt);
};

#endif