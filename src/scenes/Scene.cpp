#include "scenes/Scene.hpp"
#include "systems/System.hpp"

#include <iostream>

namespace Scene
{
  int Scene::precedence() { return 0; }

  Scene::Scene(IManager &sceneManager)
      : sceneManagerRef(sceneManager), registryRef(sceneManager.registryRef), windowRef(sceneManager.windowRef) {}

  Scene::~Scene()
  {
    for (const auto &entity : createdEntities)
    {
      if (registryRef.get().valid(entity))
        registryRef.get().destroy(entity);
    }

    createdEntities.clear();
  }

  void Scene::updateSystems(sf::Time dt)
  {
    for (auto &system : systems)
      system->update(dt);
  }

  entt::entity Scene::create()
  {
    entt::entity entity = registryRef.get().create();
    createdEntities.insert(entity);
    return entity;
  }

}