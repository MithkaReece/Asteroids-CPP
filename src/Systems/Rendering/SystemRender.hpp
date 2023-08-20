#pragma once
#ifndef HEADER_SYSTEM_RENDER
#define HEADER_SYSTEM_RENDER
#include <entt/entt.hpp>
#include <functional>
#include "System.hpp"
#include "ComponentTransform.hpp"
#include "ComponentRender.hpp"
#include "ComponentText.hpp"
#include "ComponentMenuItem.hpp"
#include "ComponentBackground.hpp"
#include "ResourceManager.hpp"

#include "GlobalObjects.hpp"

/**
 * @brief The Render class handles rendering entities and UI elements.
 */
class SystemRender : public System
{
public:
  SystemRender();
  /**
   * @brief Updates the system by rendering entities and UI elements.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif