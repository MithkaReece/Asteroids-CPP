#pragma once
#ifndef HEADER_SYSTEM_PLAYER_ROTATE
#define HEADER_SYSTEM_PLAYER_ROTATE
#include "System.hpp"

#include "ComponentInput.hpp"
#include "ComponentTransform.hpp"

/**
 * @brief The PlayerRotate class handles the rotation of player-controlled entities.
 */
class SystemPlayerRotate : public System
{
public:
  SystemPlayerRotate(entt::registry &registry, sf::RenderWindow &window, Scene &scene);
  /**
   * @brief Updates the system by handling rotation of player-controlled entities.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif