#include "SystemManager.hpp"

SystemManager::SystemManager(std::unique_ptr<ISystem> renderSystem)
    : render(std::move(renderSystem)) {}

void SystemManager::updateSystems(sf::Time dt)
{
  // Remove the systems from the list (outside of the iteration loop)
  for (auto it = indicesToRemove.rbegin(); it != indicesToRemove.rend(); ++it)
  {
    systems.erase(systems.begin() + *it);
  }
  indicesToRemove.clear();

  for (const std::unique_ptr<ISystem> &system : systems)
  {
    if (system != nullptr)
      system->update(dt);
  }
}

void SystemManager::updateRenderSystem(sf::Time dt)
{
  render->update(dt);
}

void SystemManager::addSystem(std::unique_ptr<ISystem> system)
{
  systems.push_back(std::move(system));
}

void SystemManager::removeSystems(const std::vector<int> &systemIDs)
{
  // Mark the systems for removal by adding their indices to the list
  for (size_t i = 0; i < systems.size(); ++i)
  {
    const auto &system = systems[i];
    if (system && std::find(systemIDs.begin(), systemIDs.end(), system->ID) != systemIDs.end())
    {
      indicesToRemove.push_back(i);
    }
  }
}
