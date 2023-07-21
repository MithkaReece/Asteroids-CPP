#include "SystemWeapon.hpp"

SystemWeapon::SystemWeapon(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemWeapon::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  Scene &scene = sceneRef.get();
  auto view = registry.view<ComponentTransform, ComponentPlayerInput, ComponentWeapon, ComponentVelocity>();
  for (auto [entity, transform, input, weapon, velocity] : view.each())
  {
    if (input.shootPressed && weapon.remainingCooldown <= sf::Time::Zero)
    {
      // Calculate the forward vector based on the player's rotation
      sf::Vector2f forwardVector = sf::Vector2f(
          std::cos(transform.rotation * DEG_TO_RAD),
          std::sin(transform.rotation * DEG_TO_RAD));

      // Calculate forward velocity
      const float magnitude = 500.0f;
      sf::Vector2f bulletVelocity = forwardVector * magnitude + velocity.velocity;

      // Offset the position from the player
      sf::Vector2f position = transform.position;
      position += forwardVector * transform.scale.x;

      //  Create a bullet entity with the calculated position, velocity, and rotation
      entityBullet(scene, position, bulletVelocity, transform.rotation);

      // Reset the remaining cooldown to the specified cooldown duration
      weapon.remainingCooldown = weapon.cooldownDuration;
      input.shootPressed = false;
    }

    // Update the cooldown timer
    if (weapon.remainingCooldown > sf::Time::Zero)
      weapon.remainingCooldown -= dt;
  }
}