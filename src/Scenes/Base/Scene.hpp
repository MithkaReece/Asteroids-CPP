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

/**
 * @brief Base class for scenes in an ECS (entt) and SFML project.
 * Scenes represent different states or levels in the game.
 */
class Scene
{
private:
  std::unordered_set<entt::entity> createdEntities;
  std::reference_wrapper<SystemManager> systemManagerRef;
  std::vector<int> systemIDs;
  std::reference_wrapper<entt::registry> registryRef;
  std::reference_wrapper<sf::RenderWindow> windowRef;

public:
  std::string type;

  int precendence = 0;

  Scene(std::string type, SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);
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
    registryRef.get().emplace<ComponentType>(entity, std::forward<Args>(args)...);
  }

  /**
   * @brief Add systems to system manager. Save system ID to scene.
   */
  template <typename SystemType, typename... Args>
  void addSystem(Args &&...args)
  {
    std::unique_ptr<SystemType> system = std::make_unique<SystemType>(
        registryRef.get(), windowRef.get(), *this, std::forward<Args>(args)...);
    systemIDs.push_back(system->ID);
    std::cout << "System created:" << std::to_string(system->ID) << "\n";
    systemManagerRef.get().addSystem(std::move(system));
  }
};
#endif