#include "SystemPlayerRotate.hpp"

SystemPlayerRotate::SystemPlayerRotate(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemPlayerRotate::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentPlayerInput, ComponentTransform>();

  for (auto [entity, input, transform] : view.each())
  {
    // Rotate the entity based on player input
    if (input.leftRotatePressed)
    {
      transform.rotation -= 200.0f * dt.asSeconds();
      input.leftRotatePressed = false;
    }

    if (input.rightRotatePressed)
    {
      transform.rotation += 200.0f * dt.asSeconds();
      input.rightRotatePressed = false;
    }
  }
}