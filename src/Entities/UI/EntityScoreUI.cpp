#include "EntityScoreUI.hpp"

void entityScoreUI(Scene &scene)
{
  auto entity = scene.create();

  sf::Vector2f position(0.01f, 0.01f);
  sf::Vector2f scale(1.0f, 1.0f);
  scene.emplace<ComponentTransform>(entity, position, scale, 0.0f);
  sf::Font font;
  font.loadFromFile("/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Roboto-Medium.ttf");
  scene.emplace<ComponentTextUI>(entity, "0", font, sf::Color::White);
  scene.emplace<ComponentScoreTag>(entity);
}
