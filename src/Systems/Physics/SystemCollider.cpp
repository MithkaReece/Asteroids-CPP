#include "SystemCollider.hpp"

SystemCollider::SystemCollider() {}

void SystemCollider::update(sf::Time dt)
{
  entt::registry &registry = GlobalObjects::getRegistry();
  auto view = registry.view<ComponentCollider, ComponentTransform>();

  for (auto [entity, collider, transform] : view.each())
  {
    sf::ConvexShape &shape = collider.shape;
    shape.setPosition(transform.position);
    shape.setScale(transform.scale);
    shape.setRotation(transform.rotation);
  }
}
