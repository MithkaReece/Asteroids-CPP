#pragma once
#ifndef HEADER_SYSTEM_PLAYER_THRUST
#define HEADER_SYSTEM_PLAYER_THRUST
#include "System.hpp"

#include "ComponentPlayer.hpp"
#include "ComponentInput.hpp"
#include "ComponentTransform.hpp"
#include "ComponentVelocity.hpp"

#include "Constants.h"

/**
 * @brief The PlayerThrust class handles applying thrust to player-controlled entities.
 */
class SystemPlayerThrust : public System
{
public:
  SystemPlayerThrust(entt::registry &registry, sf::RenderWindow &window, Scene &scene);
  /**
   * @brief Updates the system by applying thrust to player-controlled entities.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif