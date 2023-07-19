#include "SystemMovement.hpp"

SystemMovement::SystemMovement(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemMovement::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentTransform, ComponentVelocity>();

  for (auto entity : view)
  {
    if (!registry.valid(entity))
      continue;

    // Get the velocity and transform components of the entity
    ComponentVelocity &velocity = view.get<ComponentVelocity>(entity);
    ComponentTransform &transform = view.get<ComponentTransform>(entity);

    // Update the position based on the velocity
    transform.position += velocity.velocity * dt.asSeconds();
  }
}