#include "SystemPlayerThrust.hpp"

SystemPlayerThrust::SystemPlayerThrust() {}

void SystemPlayerThrust::update(sf::Time dt)
{
  entt::registry &registry = GlobalObjects::getRegistry();
  auto view = registry.view<ComponentPlayer, ComponentAcceleration, ComponentPlayerInput, ComponentTransform, ComponentVelocity>();
  for (auto [entity, acceleration, input, transform, velocity] : view.each())
  { // Apply thrust to the entity if the thrust button is pressed
    if (!input.thrustPressed)
      continue;

    // Calculate the forward vector based on the entity's rotation
    sf::Vector2f forwardVector = sf::Vector2f(
        std::cos(transform.rotation * DEG_TO_RAD),
        std::sin(transform.rotation * DEG_TO_RAD));

    // Accelerate the entity forward by adding the forward vector scaled by acceleration and time delta
    velocity.velocity += forwardVector * acceleration.value * dt.asSeconds();

    // Reset the thrust button state
    input.thrustPressed = false;
  }
}