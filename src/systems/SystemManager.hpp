#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <vector>

#include <SFML/System/Time.hpp>
#include "systems/ISystem.hpp"

namespace System
{
  class Manager
  {
  private:
    std::vector<std::unique_ptr<ISystem>> systems;
    std::unique_ptr<ISystem> render;

  public:
    Manager(std::unique_ptr<ISystem> renderSystem);

    void updateSystems(sf::Time dt);

    void updateRenderSystem(sf::Time dt);

    void addSystem(std::unique_ptr<ISystem> system);

    void removeSystem(int ID);
  };
}