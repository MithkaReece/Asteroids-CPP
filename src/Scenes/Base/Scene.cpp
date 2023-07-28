#include "Scene.hpp"
#include "System.hpp"

#include <iostream>

Scene::Scene(std::string type, SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : type(type), systemManagerRef(systemManager), registryRef(registry), windowRef(window) {}

Scene::~Scene()
{
  for (const auto &entity : createdEntities)
  {
    if (registryRef.get().valid(entity))
      registryRef.get().destroy(entity);
  }

  createdEntities.clear();
  systemManagerRef.get().removeSystems(systemIDs);
}

entt::entity Scene::create()
{
  entt::entity entity = registryRef.get().create();
  createdEntities.insert(entity);
  return entity;
}

void Scene::pause()
{
  systemManagerRef.get().pauseSystems(systemIDs);
}

void Scene::unpause()
{
  systemManagerRef.get().unpauseSystems(systemIDs);
}
