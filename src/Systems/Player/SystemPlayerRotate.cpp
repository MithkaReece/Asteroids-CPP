#include "SystemPlayerRotate.hpp"

SystemPlayerRotate::SystemPlayerRotate(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemPlayerRotate::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentPlayerInput, ComponentTransform>();

  for (auto entity : view)
  {
    if (!registry.valid(entity))
    {
      continue;
    }

    // Get the player input and transform components of the entity
    ComponentPlayerInput &input = view.get<ComponentPlayerInput>(entity);
    ComponentTransform &transform = view.get<ComponentTransform>(entity);

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