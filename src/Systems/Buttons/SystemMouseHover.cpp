#include "SystemMouseHover.hpp"

SystemMouseHover::SystemMouseHover() {}

void SystemMouseHover::update(sf::Time dt)
{
  const sf::Vector2f mouse_pos = Input::GetMousePosFloat();

  auto view = GlobalObjects::getRegistry().view<ComponentMenuItem>();

  for (auto [entity, menuItem] : view.each())
  {
    menuItem.hover = menuItem.shape->getGlobalBounds().contains(mouse_pos);
    if (menuItem.hover)
      menuItem.shape->setFillColor(sf::Color(100, 100, 100, 200));
    else
      menuItem.shape->setFillColor(sf::Color(50, 50, 50, 200));
  }
}