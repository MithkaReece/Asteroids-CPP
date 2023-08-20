#pragma once
#ifndef HEADER_SYSTEM_USER_INPUT
#define HEADER_SYSTEM_USER_INPUT
#include "System.hpp"
#include "ComponentInput.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "Constants.h"

/**
 * @brief The UserInput class handles updating player input based on keyboard events.
 */
class SystemUserInput : public System
{
public:
  SystemUserInput();
  /**
   * @brief Update function for updating player input.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif