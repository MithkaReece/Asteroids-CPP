#include "SystemManager.hpp"

SystemManager::SystemManager(std::unique_ptr<ISystem> renderSystem)
    : render(std::move(renderSystem)) {}

void SystemManager::updateSystems(sf::Time dt)
{
  for (const std::unique_ptr<ISystem> &system : systems)
    system->update(dt);
}

void SystemManager::updateRenderSystem(sf::Time dt)
{
  render->update(dt);
}

void SystemManager::addSystem(std::unique_ptr<ISystem> system)
{
  systems.push_back(std::move(system));
}

void SystemManager::removeSystem(int ID)
{
  systems.erase(std::remove_if(
                    systems.begin(), systems.end(),
                    [ID](const std::unique_ptr<ISystem> &system)
                    {
                      return system->ID == ID;
                    }),
                systems.end());
}
