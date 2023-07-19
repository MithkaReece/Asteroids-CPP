#include "systems/SystemManager.hpp"

namespace System
{
  Manager::Manager(std::unique_ptr<ISystem> renderSystem)
      : render(std::move(renderSystem)) {}

  void Manager::updateSystems(sf::Time dt)
  {
    for (const std::unique_ptr<ISystem> &system : systems)
      system->update(dt);
  }

  void Manager::updateRenderSystem(sf::Time dt)
  {
    render->update(dt);
  }

  void Manager::addSystem(std::unique_ptr<ISystem> system)
  {
    systems.push_back(std::move(system));
  }

  void Manager::removeSystem(int ID)
  {
    systems.erase(std::remove_if(
                      systems.begin(), systems.end(),
                      [ID](const std::unique_ptr<ISystem> &system)
                      {
                        return system->ID == ID;
                      }),
                  systems.end());
  }
}