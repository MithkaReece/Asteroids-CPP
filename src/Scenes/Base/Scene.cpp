#include "Scene.hpp"
#include "System.hpp"

#include <iostream>

Scene::Scene(std::string id)
    : ID(id) {}

Scene::~Scene()
{
  for (const auto &entity : createdEntities)
  {
    if (GlobalObjects::getRegistry().valid(entity))
      GlobalObjects::getRegistry().destroy(entity);
  }

  createdEntities.clear();
  SystemManager::getInstance().removeSystems(systemIDs);
}

entt::entity Scene::create()
{
  entt::entity entity = GlobalObjects::getRegistry().create();
  createdEntities.insert(entity);
  return entity;
}

void Scene::pause()
{
  SystemManager::getInstance().pauseSystems(systemIDs);
}

void Scene::unpause()
{
  SystemManager::getInstance().unpauseSystems(systemIDs);
}
