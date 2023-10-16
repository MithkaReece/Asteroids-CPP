#include <gtest/gtest.h>
#include "SystemPlayerThrust.hpp"

TEST(SystemPlayerThrust, UpdatesVelocityOnThrustPressed)
{
  SystemPlayerThrust system;

  // Create a test entity with components
  entt::registry &registry = GlobalObjects::getRegistry();
  registry.clear();
  entt::entity entity = registry.create();
  registry.emplace<ComponentPlayer>(entity);
  registry.emplace<ComponentAcceleration>(entity, 100.0f);                                            // Set acceleration
  registry.emplace<ComponentPlayerInput>(entity, true, false, false, false);                          // Thrust pressed
  registry.emplace<ComponentTransform>(entity, sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f), 0.0f); // Set rotation
  registry.emplace<ComponentVelocity>(entity, sf::Vector2f(0.0f, 0.0f));                              // Initial velocity
  sf::Time dt = sf::seconds(1.0f);                                                                    // 1 second time delta

  // Call the system's update function
  system.update(dt);

  // Validate that velocity has been updated as expected
  const ComponentVelocity &velocity = registry.get<ComponentVelocity>(entity);
  ASSERT_NE(velocity.velocity, sf::Vector2f(0.0f, 0.0f));
}

TEST(SystemPlayerThrust, DoesNotUpdateVelocityOnThrustNotPressed)
{
  SystemPlayerThrust system;

  // Create a test entity with components
  entt::registry &registry = GlobalObjects::getRegistry();
  registry.clear();
  entt::entity entity = registry.create();
  registry.emplace<ComponentPlayer>(entity);
  registry.emplace<ComponentAcceleration>(entity, 0.0f);                                              // Set acceleration
  registry.emplace<ComponentPlayerInput>(entity, false, false, false, false);                         // Thrust not pressed
  registry.emplace<ComponentTransform>(entity, sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f), 0.0f); // Set rotation
  registry.emplace<ComponentVelocity>(entity, sf::Vector2f(0.0f, 0.0f));                              // Initial velocity
  sf::Time dt = sf::seconds(1.0f);                                                                    // 1 second time delta

  // Call the system's update function
  system.update(dt);

  // Validate that velocity has not been updated
  const ComponentVelocity &velocity = registry.get<ComponentVelocity>(entity);
  ASSERT_EQ(velocity.velocity, sf::Vector2f(0.0f, 0.0f));
}