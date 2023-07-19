#include "entities/ScoreUI.hpp"

namespace Entity
{
  void createScoreUI(Scene::Scene &scene)
  {
    auto entity = scene.create();

    sf::Vector2f position(0.01f, 0.01f);
    sf::Vector2f scale(1.0f, 1.0f);
    scene.emplace<Component::Transform>(entity, position, scale, 0.0f);
    sf::Font font;
    font.loadFromFile("/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/resources/Roboto-Medium.ttf");
    scene.emplace<Component::TextUI>(entity, "0", font, sf::Color::White);
    scene.emplace<Component::ScoreTag>(entity);
  }
}