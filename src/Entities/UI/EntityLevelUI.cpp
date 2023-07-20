#include "EntityLevelUI.hpp"

void entityLevelUI(Scene &scene, sf::RenderWindow &window)
{
  auto entity = scene.create();
  std::unique_ptr<sf::Text> scoreText = std::make_unique<sf::Text>();
  scoreText->setFont(scene.font);
  scoreText->setCharacterSize(25);
  scoreText->setPosition(window.getSize().x * 0.01f, 10.0f);
  scoreText->setFillColor(sf::Color::White);
  scene.emplace<ComponentScoreText>(entity, std::move(scoreText));

  std::unique_ptr<sf::Text> livesText = std::make_unique<sf::Text>();
  livesText->setFont(scene.font);
  livesText->setCharacterSize(25);
  livesText->setPosition(window.getSize().x * 0.9f, 10.0f);
  livesText->setFillColor(sf::Color::White);
  scene.emplace<ComponentLivesText>(entity, std::move(livesText));
}
