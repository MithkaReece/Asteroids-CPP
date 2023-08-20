#include "SystemMovement.hpp"

SystemMovement::SystemMovement() {}

void SystemMovement::update(sf::Time dt)
{
  entt::registry &registry = GlobalObjects::getRegistry();
  auto view = registry.view<ComponentTransform, ComponentVelocity>();
  for (auto [entity, transform, velocity] : view.each())
    transform.position += velocity.velocity * dt.asSeconds();
}