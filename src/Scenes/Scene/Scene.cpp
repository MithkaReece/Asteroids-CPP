#include "Scene.hpp"
#include "System.hpp"

#include <iostream>

int Scene::precedence() { return 0; }

Scene::Scene(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : systemManagerRef(systemManager), registryRef(registry), windowRef(window) {}

Scene::~Scene()
{
  for (const auto &entity : createdEntities)
  {
    if (registryRef.get().valid(entity))
      registryRef.get().destroy(entity);
  }

  createdEntities.clear();
}

// TODO move else where
void Scene::updateSystems(sf::Time dt)
{
  // for (auto &system : systems)
  // system->update(dt);
}

entt::entity Scene::create()
{
  entt::entity entity = registryRef.get().create();
  createdEntities.insert(entity);
  return entity;
}
