#include "Input.hpp"

namespace Input
{

  const sf::Vector2f GetMousePosFloat()
  {
    const sf::RenderWindow &window = GlobalObjects::getWindow();
    const sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return sf::Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
  }
}