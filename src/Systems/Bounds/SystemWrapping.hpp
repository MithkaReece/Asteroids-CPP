#pragma once
#ifndef HEADER_SYSTEM_WRAPPING
#define HEADER_SYSTEM_WRAPPING
#include <entt/entt.hpp>
#include "System.hpp"
#include "ComponentTransform.hpp"
#include "ComponentVelocity.hpp"
#include "ComponentWrapperBoundary.hpp"

/**
 * @brief The Wrapping class handles the wrapping behavior of entities.
 */
class SystemWrapping : public System
{

public:
  SystemWrapping(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  /**
   * @brief Update function for handling the wrapping behavior of entities.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif