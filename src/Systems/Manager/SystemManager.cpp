#include "SystemManager.hpp"
#include <iostream>
#include <string>

SystemManager::SystemManager(std::unique_ptr<ISystem> renderSystem)
    : render(std::move(renderSystem)) {}

void SystemManager::updateSystems(sf::Time dt)
{
  // Remove systems with stored IDs after iteration
  emptyRemoveQueue();

  // Add new systems
  for (auto &system : newSystems)
  {
    systems.push_back(std::move(system));
  }
  newSystems.clear();

  for (const std::unique_ptr<ISystem> &system : systems)
  {
    if (system && system != nullptr)
      system->update(dt);
  }
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
    // std::cout << "Delete queue +" << std::to_string(systemID) + "\n";
    systemsToRemove.insert(systemID);
  }
}

// Function to remove a system by ID
void SystemManager::emptyRemoveQueue()
{
  for (auto it = systems.begin(); it != systems.end();)
  {
    int systemID = (*it)->ID;

    if (systemsToRemove.find(systemID) != systemsToRemove.end())
    {
      std::cout << "System " << std::to_string(systemID) << " Deleted\n";
      it = systems.erase(it);
    }
    else
    {
      ++it;
    }
  }
  systemsToRemove.clear();
}