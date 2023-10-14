#include <gtest/gtest.h>
#include "SystemMovement.hpp"

TEST(SystemMovement, UpdatesPositionCorrectly)
{
  SystemMovement system;

  // Create a test entity with components
  entt::registry &registry = GlobalObjects::getRegistry();
  registry.clear();
  entt::entity entity = registry.create();
  registry.emplace<ComponentTransform>(entity, sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f), 0.0f);
  registry.emplace<ComponentVelocity>(entity, sf::Vector2f(1.f, 2.f)); // Velocity (1, 2)
  sf::Time dt = sf::seconds(0.5f);                                     // Time delta

  // Call the system's update function
  system.update(dt);

  // Validate that position has been updated as expected
  const ComponentTransform &transform = registry.get<ComponentTransform>(entity);
  ASSERT_EQ(transform.position, sf::Vector2f(0.5f, 1.0f)); // Expected position after 0.5 seconds
}

TEST(SystemMovement, UpdatesPositionWithZeroVelocity)
{
  SystemMovement system;

  // Create a test entity with components
  entt::registry &registry = GlobalObjects::getRegistry();
  registry.clear();
  entt::entity entity = registry.create();
  registry.emplace<ComponentTransform>(entity, sf::Vector2f(2.0f, 3.0f), sf::Vector2f(1.f, 1.f), 0.0f);
  registry.emplace<ComponentVelocity>(entity, sf::Vector2f(0.0f, 0.0f)); // Zero velocity
  sf::Time dt = sf::seconds(1.0f);                                       // Time delta

  // Call the system's update function
  system.update(dt);

  // Validate that position remains unchanged with zero velocity
  const ComponentTransform &transform = registry.get<ComponentTransform>(entity);
  ASSERT_EQ(transform.position, sf::Vector2f(2.0f, 3.0f)); // Position should not change
}