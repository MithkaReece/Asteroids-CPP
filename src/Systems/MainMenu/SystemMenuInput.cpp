#include "SystemMenuInput.hpp"

#include <iostream>
extern entt::dispatcher globalDispatcher;

SystemMenuInput::SystemMenuInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemMenuInput::update(sf::Time dt)
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
        globalDispatcher.trigger<EventStartGame>();
      }
      else if (menuItem.id == MenuItemID::Exit)
      {
        window.close();
      }
    }
  }
}