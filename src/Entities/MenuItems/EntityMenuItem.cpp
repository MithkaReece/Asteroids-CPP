#include "EntityMenuItem.hpp"

void EntityMenuItem(Scene &scene, sf::RenderWindow &window, MenuItemID itemID,
                    std::string stringText, sf::Vector2f position, sf::Vector2f outerborderRatio)
{
  auto entity = scene.create();
  // Make button text
  std::unique_ptr<sf::Text> text = std::make_unique<sf::Text>();
  text->setFont(ResourceManager::getInstance().getFont("Default"));
  text->setCharacterSize(75);
  text->setPosition(window.getSize().x * position.x, window.getSize().y * position.y);
  text->setFillColor(sf::Color::White);
  text->setString(stringText);
  sf::FloatRect textBounds = text->getLocalBounds();
  text->setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);

  // Make button shape
  sf::FloatRect globalTextBounds = text->getGlobalBounds();
  std::unique_ptr<sf::RectangleShape> backgroundRect = std::make_unique<sf::RectangleShape>(
      sf::Vector2f(globalTextBounds.width + window.getSize().x * outerborderRatio.x,
                   globalTextBounds.height + window.getSize().y * outerborderRatio.y));

  backgroundRect->setPosition(globalTextBounds.left - window.getSize().x * outerborderRatio.x / 2.0f,
                              globalTextBounds.top - window.getSize().y * outerborderRatio.y / 2.0f);

  scene.emplace<ComponentMenuItem>(entity, itemID, std::move(text), std::move(backgroundRect));
}