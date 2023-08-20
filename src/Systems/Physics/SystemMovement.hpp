#pragma once
#ifndef HEADER_SYSTEM_MOVEMENT
#define HEADER_SYSTEM_MOVEMENT
#include "System.hpp"
#include <SFML/Graphics.hpp>

#include "ComponentTransform.hpp"
#include "ComponentVelocity.hpp"

/**
 * @brief The Movement class updates the position of entities based on their velocity.
 */
class SystemMovement : public System
{
public:
  SystemMovement();
  /**
   * @brief Updates the position of entities based on their velocity.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif
