#include "EntityLevelUI.hpp"
void EntityLevelUI(Scene &scene, sf::Vector2f position, std::string ID)
{
  sf::RenderWindow &window = GlobalObjects::getWindow();
  auto entity = scene.create();

  std::unique_ptr<sf::Text> scoreText = std::make_unique<sf::Text>();
  scoreText->setFont(ResourceManager::getInstance().getFont("Default"));
  scoreText->setCharacterSize(35);

  scoreText->setPosition(window.getSize().x * position.x, window.getSize().y * position.y);
  scoreText->setFillColor(sf::Color::White);
  scoreText->setOutlineThickness(2.f); // Set the thickness in pixels
  scoreText->setOutlineColor(sf::Color::Black);

  scene.emplace<ComponentText>(entity, std::move(ID), std::move(scoreText));
}
