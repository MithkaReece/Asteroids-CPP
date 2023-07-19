#include "EntityLevelUI.hpp"

void entityLevelUI(Scene &scene, sf::RenderWindow &window)
{
  auto entity = scene.create();

  scene.emplace<ComponentScoreText>(entity);

  scene.emplace<ComponentLivesText>(entity);
}
