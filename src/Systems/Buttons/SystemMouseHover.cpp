#include "SystemMouseHover.hpp"

SystemMouseHover::SystemMouseHover() {}

void SystemMouseHover::update(sf::Time dt)
{
  sf::Vector2i mousePosition = sf::Mouse::getPosition(GlobalObjects::getWindow());
  sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

  auto view = GlobalObjects::getRegistry().view<ComponentMenuItem>();
  for (auto [entity, menuItem] : view.each())
  {
    menuItem.hover = menuItem.shape->getGlobalBounds().contains(mousePositionFloat);
    if (menuItem.hover)
      menuItem.shape->setFillColor(sf::Color(100, 100, 100, 200));
    else
      menuItem.shape->setFillColor(sf::Color(50, 50, 50, 200));
  }
}