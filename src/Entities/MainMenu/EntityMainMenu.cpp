#include "EntityMainMenu.hpp"

void EntityMenuItem(Scene &scene, sf::RenderWindow &window, MenuItemID itemID, std::string stringText, sf::Vector2f position)
{
  auto entity = scene.create();

  std::unique_ptr<sf::Text> text = std::make_unique<sf::Text>();
  text->setFont(scene.font);
  text->setCharacterSize(50);

  text->setPosition(window.getSize().x * position.x, window.getSize().y * position.y);
  text->setFillColor(sf::Color::White);
  text->setString(stringText);

  sf::FloatRect textBounds = text->getLocalBounds();
  text->setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
  scene.emplace<ComponentMenuItem>(entity, itemID, std::move(text), sf::Vector2f(0.05, 0.05));
}