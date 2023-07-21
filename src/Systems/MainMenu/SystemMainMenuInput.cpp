#include "SystemMainMenuInput.hpp"

SystemMainMenuInput::SystemMainMenuInput(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemMainMenuInput::update(sf::Time dt)
{
  if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    return;

  sf::Vector2i mousePosition = sf::Mouse::getPosition(windowRef.get());
}