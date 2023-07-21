#include "SystemOutOfBound.hpp"

SystemOutOfBound::SystemOutOfBound(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemOutOfBound::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  sf::RenderWindow &window = windowRef.get();
  auto view = registry.view<ComponentTransform>(entt::exclude<ComponentWrapperBoundary>);

  for (auto [entity, transform] : view.each())
  {
    // Delete outside boundary
    if (transform.position.x < -BOUNDARY || transform.position.x > window.getSize().x + BOUNDARY || transform.position.y < -BOUNDARY || transform.position.y > window.getSize().y + BOUNDARY)
      registry.destroy(entity);
  }
}