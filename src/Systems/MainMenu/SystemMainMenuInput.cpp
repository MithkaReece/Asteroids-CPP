#include "SystemMainMenuInput.hpp"

#include <iostream>

SystemMainMenuInput::SystemMainMenuInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemMainMenuInput::update(sf::Time dt)
{
  if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    return;
  sf::RenderWindow &window = windowRef.get();

  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

  auto view = registryRef.get().view<ComponentMenuItem>();
  for (auto [entity, menuItem] : view.each())
  {
    if (menuItem.shape->getGlobalBounds().contains(mousePositionFloat))
    {
      if (menuItem.id == MenuItemID::StartGame)
      {
        std::cout << "Start Game\n";
      }
      else
      {
        std::cout << "Inside\n";
      }
    }
  }
}