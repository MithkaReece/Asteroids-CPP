#pragma once
#ifndef HEADER_SYSTEM_MANAGER
#define HEADER_SYSTEM_MANAGER
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <vector>

#include <SFML/System/Time.hpp>
#include "ISystem.hpp"

class SystemManager
{
private:
  std::vector<std::unique_ptr<ISystem>> systems;
  std::unique_ptr<ISystem> render;

public:
  SystemManager(std::unique_ptr<ISystem> renderSystem);

  void updateSystems(sf::Time dt);

  void updateRenderSystem(sf::Time dt);

  void addSystem(std::unique_ptr<ISystem> system);

  void removeSystem(int ID);
};
#endif