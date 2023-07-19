#include "SystemCollider.hpp"

SystemCollider::SystemCollider(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemCollider::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentCollider, ComponentTransform>();

  for (auto entity : view)
  {
    if (!registry.valid(entity))
      continue;

    ComponentCollider &collider = view.get<ComponentCollider>(entity);
    ComponentTransform &transform = view.get<ComponentTransform>(entity);

    sf::ConvexShape &shape = collider.shape;
    shape.setPosition(transform.position);
    shape.setScale(transform.scale);
    shape.setRotation(transform.rotation);
  }
}
