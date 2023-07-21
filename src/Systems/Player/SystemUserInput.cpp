#include "SystemUserInput.hpp"

SystemUserInput::SystemUserInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemUserInput::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentPlayerInput>();
  for (auto [entity, input] : view.each())
  {
    // Update input based on keyboard events
    input.leftRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    input.rightRotatePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    input.thrustPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    input.shootPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
  }
}