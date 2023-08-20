#pragma once
#ifndef HEADER_SYSTEM_COLLIDER
#define HEADER_SYSTEM_COLLIDER
#include <entt/entt.hpp>
#include "System.hpp"
#include "ComponentTransform.hpp"
#include "ComponentCollider.hpp"

/**
 * @brief Class for updating colliders based on transform components.
 */
class SystemCollider : public System
{
public:
  SystemCollider();
  /**
   * @brief Updates the colliders based on transform components.
   *
   * @param registry The entity registry.
   * @param dt The elapsed time since the last update.
   */
  void update(sf::Time dt);
};
#endif