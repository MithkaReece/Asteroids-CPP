#include "EntityGame.hpp"

void EntityGame(Scene &scene)
{
  auto entity = scene.create();
  scene.emplace<ComponentHighScore>(entity, ResourceManager::getInstance().getHighScore());
  scene.emplace<ComponentScore>(entity, 0);
  scene.emplace<ComponentLives>(entity, 3);
  scene.emplace<ComponentScene>(entity);
  scene.emplace<ComponentBackground>(entity, "background3");
}