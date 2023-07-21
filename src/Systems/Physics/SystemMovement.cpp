#include "SystemMovement.hpp"

SystemMovement::SystemMovement(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemMovement::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentTransform, ComponentVelocity>();
  for (auto [entity, transform, velocity] : view.each())
    transform.position += velocity.velocity * dt.asSeconds();
}