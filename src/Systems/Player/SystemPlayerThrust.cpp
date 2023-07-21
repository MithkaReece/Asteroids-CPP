#include "SystemPlayerThrust.hpp"

SystemPlayerThrust::SystemPlayerThrust(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemPlayerThrust::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto view = registry.view<ComponentPlayer, ComponentPlayerInput, ComponentTransform, ComponentVelocity>();
  for (auto [entity, player, input, transform, velocity] : view.each())
  { // Apply thrust to the entity if the thrust button is pressed
    if (!input.thrustPressed)
      continue;

    // Calculate the forward vector based on the entity's rotation
    sf::Vector2f forwardVector = sf::Vector2f(
        std::cos(transform.rotation * DEG_TO_RAD),
        std::sin(transform.rotation * DEG_TO_RAD));

    // Accelerate the entity forward by adding the forward vector scaled by acceleration and time delta
    velocity.velocity += forwardVector * player.acceleration * dt.asSeconds();

    // Reset the thrust button state
    input.thrustPressed = false;
  }
}