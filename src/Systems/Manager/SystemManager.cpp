#include "SystemManager.hpp"
#include <iostream>
#include <string>

SystemManager &SystemManager::getInstance()
{
  static SystemManager instance;
  return instance;
}

SystemManager::SystemManager()
    : render(std::move(std::make_unique<SystemRender>())) {}

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

  for (const std::unique_ptr<System> &system : systems)
  {
    if (system && system != nullptr && !system->Paused)
      system->update(dt);
  }
}

void SystemManager::updateRenderSystem(sf::Time dt)
{
  render->update(dt);
}

void SystemManager::addSystem(std::unique_ptr<System> system)
{
  newSystems.push_back(std::move(system));
}

void SystemManager::removeSystems(const std::vector<int> &systemIDs)
{
  for (const int &systemID : systemIDs)
    systemsToRemove.insert(systemID);
}

// Function to remove a system by ID
void SystemManager::emptyRemoveQueue()
{
  if (systemsToRemove.size() <= 0)
    return;

  for (auto it = systems.begin(); it != systems.end();)
  {
    int systemID = (*it)->ID;

    if (systemsToRemove.find(systemID) != systemsToRemove.end())
    {
      it = systems.erase(it);
    }
    else
    {
      ++it;
    }
  }
  systemsToRemove.clear();
}

void SystemManager::pauseSystems(const std::vector<int> &idsToPause)
{
  // Find the systems with the given IDs and call pause() on each of them
  for (const auto &id : idsToPause)
  {
    auto it = std::find_if(systems.begin(), systems.end(), [id](const auto &system)
                           { return system->ID == id; });

    if (it != systems.end())
    {
      (*it)->Paused = true;
    }
  }
}

void SystemManager::unpauseSystems(const std::vector<int> &idsToPause)
{
  // Find the systems with the given IDs and call pause() on each of them
  for (const auto &id : idsToPause)
  {
    auto it = std::find_if(systems.begin(), systems.end(), [id](const auto &system)
                           { return system->ID == id; });

    if (it != systems.end())
    {
      (*it)->Paused = false;
    }
  }
}