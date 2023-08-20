#include "SystemUserInput.hpp"

SystemUserInput::SystemUserInput() {}

void SystemUserInput::update(sf::Time dt)
{
  auto view = GlobalObjects::getRegistry().view<ComponentPlayerInput>();
  for (auto [entity, input] : view.each())
  {
    // Update input based on keyboard events
    input.leftRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    input.rightRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    input.thrustPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    input.shootPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
  }
}