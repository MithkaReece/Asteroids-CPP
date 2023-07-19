#pragma once
#ifndef HEADER_SYSTEM_OUT_OF_BOUND
#define HEADER_SYSTEM_OUT_OF_BOUND
#include "System.hpp"

#include "ComponentTransform.hpp"
#include "ComponentVelocity.hpp"
#include "ComponentWrapperBoundary.hpp"

#include "Constants.h"

/**
 * @brief The OutOfBound class removes entities that are outside the game boundary.
 */
class SystemOutOfBound : public System
{

public:
  SystemOutOfBound(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  /**
   * @brief Updates the system by removing entities that are outside the game boundary.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif