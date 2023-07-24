#include "EntityGame.hpp"

void EntityGame(Scene &scene, sf::RenderWindow &window)
{
  auto entity = scene.create();
  scene.emplace<ComponentHighScore>(entity, 0);
  scene.emplace<ComponentScore>(entity, 0);
  scene.emplace<ComponentLives>(entity, 3);
  scene.emplace<ComponentScene>(entity);
  scene.emplace<ComponentBackground>(entity, "background3");
  
}