#pragma once
#ifndef HEADER_SCENE
#define HEADER_SCENE
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <entt/entt.hpp>

#include "SystemManager.hpp"

#include <iostream>
#include <string>

#include "GlobalObjects.hpp"

/**
 * @brief Base class for scenes in an ECS (entt) and SFML project.
 * Scenes represent different states or levels in the game.
 */
class Scene
{
private:
  std::unordered_set<entt::entity> createdEntities;
  std::vector<int> systemIDs;

public:
  std::string ID;

  int precendence = 0;

  Scene(std::string id);
  virtual ~Scene();
  /**
   * @brief Updates all the systems in the scene.
   *
   * @param registry The entt::registry containing the game entities.
   * @param dt The time delta for the update.
   */
  void updateSystems(sf::Time dt);

  entt::entity create();

  // Templated method to add a component to an entity in the scene
  template <typename ComponentType, typename... Args>
  void emplace(entt::entity entity, Args &&...args)
  {
    GlobalObjects::getRegistry().emplace<ComponentType>(entity, std::forward<Args>(args)...);
  }

  /**
   * @brief Add systems to system manager. Save system ID to scene.
   */
  template <typename SystemType, typename... Args>
  void addSystem(Args &&...args)
  {
    std::unique_ptr<SystemType> system = std::make_unique<SystemType>(std::forward<Args>(args)...);
    systemIDs.push_back(system->ID);
    SystemManager::getInstance().addSystem(std::move(system));
  }

  void pause();

  void unpause();
};
#endif