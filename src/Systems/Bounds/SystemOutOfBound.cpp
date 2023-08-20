#include "SystemOutOfBound.hpp"

SystemOutOfBound::SystemOutOfBound() {}

void SystemOutOfBound::update(sf::Time dt)
{
  entt::registry &registry = GlobalObjects::getRegistry();
  sf::RenderWindow &window = GlobalObjects::getWindow();
  auto view = registry.view<ComponentTransform>(entt::exclude<ComponentWrapperBoundary>);

  for (auto [entity, transform] : view.each())
  {
    // Delete outside boundary
    if (transform.position.x < -BOUNDARY || transform.position.x > window.getSize().x + BOUNDARY || transform.position.y < -BOUNDARY || transform.position.y > window.getSize().y + BOUNDARY)
      registry.destroy(entity);
  }
}