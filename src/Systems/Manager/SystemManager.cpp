#include "SystemManager.hpp"

SystemManager::SystemManager(std::unique_ptr<ISystem> renderSystem)
    : render(std::move(renderSystem)) {}

void SystemManager::updateSystems(sf::Time dt)
{
  for (const std::unique_ptr<ISystem> &system : systems)
  {
    if (system && system != nullptr)
      system->update(dt);
  }

  // Remove systems with stored IDs after iteration
  for (const auto &systemID : systemsToRemove)
  {
    RemoveSystemByID(systemID);
  }
  systemsToRemove.clear();

  // Add new systems
  for (auto &system : newSystems)
  {
    systems.push_back(std::move(system));
  }
  newSystems.clear();
}

void SystemManager::updateRenderSystem(sf::Time dt)
{
  render->update(dt);
}

void SystemManager::addSystem(std::unique_ptr<ISystem> system)
{
  newSystems.push_back(std::move(system));
}

void SystemManager::removeSystems(const std::vector<int> &systemIDs)
{
  for (const int &systemID : systemIDs)
  {
    systemsToRemove.insert(systemID);
  }
}

// Function to remove a system by ID
void SystemManager::RemoveSystemByID(int systemID)
{
  // Use an appropriate method to find and remove the system with the given ID
  // For example, if you have an unordered map for fast access based on IDs:
  auto iter = std::find_if(systems.begin(), systems.end(), [systemID](const auto &system)
                           { return system->ID == systemID; });

  if (iter != systems.end())
  {
    systems.erase(iter);
  }
}