#include "SystemWrapping.hpp"

SystemWrapping::SystemWrapping(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemWrapping::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  sf::RenderWindow &window = windowRef.get();
  auto view = registry.view<ComponentTransform, ComponentVelocity, ComponentWrapperBoundary>();

  for (auto entity : view)
  {
    if (!registry.valid(entity))
      continue;

    ComponentTransform &transform = view.get<ComponentTransform>(entity);
    ComponentWrapperBoundary &boundary = view.get<ComponentWrapperBoundary>(entity);
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