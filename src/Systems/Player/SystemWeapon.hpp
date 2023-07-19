#pragma once
#ifndef HEADER_SYSTEM_WEAPON
#define HEADER_SYSTEM_WEAPON
#include "System.hpp"

#include "ComponentTransform.hpp"
#include "ComponentInput.hpp"
#include "ComponentWeapon.hpp"

#include "EntityBullet.hpp"

#include "Constants.h"

// Temp
#include <iostream>

/**
 * @brief The Weapon class manages the player's weapon system.
 */
class SystemWeapon : public System
{
public:
  SystemWeapon(entt::registry &registry, sf::RenderWindow &window, Scene &scene);
  /**
   * @brief Update function for managing the player's weapon system.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif