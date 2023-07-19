#include "SystemOutOfBound.hpp"

SystemOutOfBound::SystemOutOfBound(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemOutOfBound::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  sf::RenderWindow &window = windowRef.get();
  auto view = registry.view<ComponentTransform, ComponentVelocity>(entt::exclude<ComponentWrapperBoundary>);

  for (auto entity : view)
  {
    if (!registry.valid(entity))
      continue;

    // Get the transform component of the entity
    ComponentTransform &transform = view.get<ComponentTransform>(entity);

    // Delete outside boundary
    if (transform.position.x < -BOUNDARY || transform.position.x > window.getSize().x + BOUNDARY || transform.position.y < -BOUNDARY || transform.position.y > window.getSize().y + BOUNDARY)
      registry.destroy(entity);
  }
}