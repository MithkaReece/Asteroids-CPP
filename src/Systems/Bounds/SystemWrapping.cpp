#include "SystemWrapping.hpp"

SystemWrapping::SystemWrapping(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemWrapping::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  sf::RenderWindow &window = windowRef.get();
  auto view = registry.view<ComponentTransform, ComponentWrapperBoundary>();

  for (auto [entity, transform, boundary] : view.each())
  {
    const float boundarySize = boundary.boundarySize;

    // Wrap position horizontally
    if (transform.position.x < -boundarySize)
      transform.position.x = window.getSize().x + boundarySize;
    else if (transform.position.x > window.getSize().x + boundarySize)
      transform.position.x = -boundarySize;

    // Wrap position vertically
    if (transform.position.y < -boundarySize)
      transform.position.y = window.getSize().y + boundarySize;
    else if (transform.position.y > window.getSize().y + boundarySize)
      transform.position.y = -boundarySize;
  }
}