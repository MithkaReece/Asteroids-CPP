#pragma once
#ifndef HEADER_SYSTEM_RENDER
#define HEADER_SYSTEM_RENDER
#include <entt/entt.hpp>
#include <functional>
#include "ISystem.hpp"
#include "ComponentTransform.hpp"
#include "ComponentRender.hpp"
#include "TextUI.hpp"
#include "ScoreTag.hpp"
#include "ComponentScoreText.hpp"
#include "ComponentLivesText.hpp"

/**
 * @brief The Render class handles rendering entities and UI elements.
 */
class SystemRender : public ISystem
{
private:
  std::reference_wrapper<sf::RenderWindow> windowRef;
  std::reference_wrapper<entt::registry> registryRef;

public:
  SystemRender(entt::registry &registry, sf::RenderWindow &window);
  /**
   * @brief Updates the system by rendering entities and UI elements.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void update(sf::Time dt);
};
#endif