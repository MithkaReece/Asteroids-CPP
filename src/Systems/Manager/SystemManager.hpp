#pragma once
#ifndef HEADER_SYSTEM_MANAGER
#define HEADER_SYSTEM_MANAGER
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <vector>

#include <SFML/System/Time.hpp>
#include "System.hpp"
#include "SystemRender.hpp"

#include "ComponentScene.hpp"

class SystemManager
{
private:
  std::vector<std::unique_ptr<System>> systems;
  std::vector<std::unique_ptr<System>> newSystems; // To be added
  std::set<int> systemsToRemove;                   // To be removed
  std::vector<size_t> indicesToRemove;

  std::unique_ptr<System> render;

public:
  static SystemManager &getInstance();

  void updateSystems(sf::Time dt);

  void updateRenderSystem(sf::Time dt);

  void addSystem(std::unique_ptr<System> system);

  void removeSystems(const std::vector<int> &systemIDs);

  void emptyRemoveQueue();

  void pauseSystems(const std::vector<int> &idsToPause);

  void unpauseSystems(const std::vector<int> &idsToPause);

private:
  SystemManager();

  SystemManager(const SystemManager &) = delete;
  SystemManager &operator=(const SystemManager &) = delete;
};
#endif