#include "SystemMenuInput.hpp"

#include <iostream>
extern entt::dispatcher globalDispatcher;

SystemMenuInput::SystemMenuInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemMenuInput::update(sf::Time dt)
{
  // Clicked left mouse button (one click)
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseDown)
  {

    sf::RenderWindow &window = windowRef.get();

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    auto view = registryRef.get().view<ComponentMenuItem>();
    for (auto [entity, menuItem] : view.each())
    {
      if (menuItem.shape == nullptr)
        return;
      if (menuItem.shape->getGlobalBounds().contains(mousePositionFloat))
        menuItem.onClick(registryRef.get(), window, globalDispatcher);
    }
  }

  // Track mouse down and release
  mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}