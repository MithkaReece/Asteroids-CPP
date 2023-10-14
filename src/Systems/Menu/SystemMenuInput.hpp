#pragma once
#ifndef HEADER_SYSTEM_MENU_INPUT
#define HEADER_SYSTEM_MENU_INPUT

#include <SFML/Graphics.hpp>
#include "System.hpp"

#include "ComponentMenuItem.hpp"
#include "Input.hpp"

class SystemMenuInput : public System
{
public:
  SystemMenuInput();

  void update(sf::Time dt);

private:
  bool previousMouseLeft = false;
};

#endif