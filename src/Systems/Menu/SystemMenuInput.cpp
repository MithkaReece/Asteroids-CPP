#include "SystemMenuInput.hpp"

#include <iostream>
extern entt::dispatcher globalDispatcher;

SystemMenuInput::SystemMenuInput() {}

void SystemMenuInput::update(sf::Time dt)
{
  // Clicked left mouse button (one click)
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !previousMouseLeft)
  {
    const sf::Vector2f mouse_pos = Input::GetMousePosFloat();

    auto view = GlobalObjects::getRegistry().view<ComponentMenuItem>();
    for (auto [entity, menuItem] : view.each())
    {
      if (menuItem.shape == nullptr)
        return;
      if (menuItem.shape->getGlobalBounds().contains(mouse_pos))
        menuItem.onClick(globalDispatcher);
    }
  }

  // Track mouse down and release
  previousMouseLeft = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
