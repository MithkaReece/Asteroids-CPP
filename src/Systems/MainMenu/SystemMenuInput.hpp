#pragma once
#ifndef HEADER_SYSTEM_MAIN_MENU_INPUT
#define HEADER_SYSTEM_MAIN_MENU_INPUT

#include <SFML/Graphics.hpp>
#include "System.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "ComponentMenuItem.hpp"
#include "ComponentBackground.hpp"

#include "EventStartGame.hpp"
#include "EventMainMenu.hpp"

#include "EnumMenuItemID.hpp"

class SystemMenuInput : public System
{
public:
  SystemMenuInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  void update(sf::Time dt);

private:
  void handleButtonStartGame();
  void handleButtonMainMenu();
};

#endif