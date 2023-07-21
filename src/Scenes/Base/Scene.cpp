#include "Scene.hpp"
#include "System.hpp"

#include <iostream>

Scene::Scene(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : systemManagerRef(systemManager), registryRef(registry), windowRef(window)
{
  font.loadFromFile("/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Roboto-Medium.ttf");
}

Scene::~Scene()
{
  for (const auto &entity : createdEntities)
  {
    if (registryRef.get().valid(entity))
      registryRef.get().destroy(entity);
  }

  createdEntities.clear();

  SystemManager &systemManager = systemManagerRef.get();
  systemManager.removeSystems(systemIDs);
}

entt::entity Scene::create()
{
  entt::entity entity = registryRef.get().create();
  createdEntities.insert(entity);
  return entity;
}
