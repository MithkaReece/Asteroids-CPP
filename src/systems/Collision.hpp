#pragma once

#include "systems/System.hpp"

#include "components/Transform.hpp"
#include "components/Collider.hpp"
#include "components/Velocity.hpp"
#include "components/Player.hpp"
#include "components/Asteroid.hpp"
#include "components/BulletTag.hpp"

#include "entities/Asteroid.hpp"

#include "Constants.h"

// Temp
#include <iostream>

namespace System
{
  class Collision : public System
  {
  private:
    sf::RenderWindow &window;

    void handleAsteroidCollision(entt::registry &registry,
                                 entt::entity entity1, Component::Transform transform1, Component::Velocity velocity1, int level1,
                                 entt::entity entity2, Component::Transform transform2, Component::Velocity velocity2, int level2)
    {
      float mass1 = std::sqrt(transform1.scale.x * transform1.scale.x + transform1.scale.y * transform1.scale.y);
      float mass2 = std::sqrt(transform2.scale.x * transform2.scale.x + transform2.scale.y * transform2.scale.y);

      // Calculate the collision normal
      sf::Vector2f collisionNormal = transform2.position - transform1.position;
      collisionNormal /= std::sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);
      sf::Vector2 perpNormal(-collisionNormal.y, collisionNormal.x);

      // Calculate the relative velocity
      sf::Vector2f relativeVelocity = velocity2.velocity - velocity1.velocity;

      // Calculate the impulse magnitude
      float impulseMagnitude = (2.0f * mass2 * (relativeVelocity.x * collisionNormal.x + relativeVelocity.y * collisionNormal.y)) / (mass1 + mass2);

      // Calculate the new velocities
      sf::Vector2f newVelocity1 = velocity1.velocity + (impulseMagnitude * collisionNormal) / mass1;
      sf::Vector2f newVelocity2 = velocity2.velocity - (impulseMagnitude * collisionNormal) / mass2;

      if (!(registry.valid(entity1) && registry.valid(entity2)))
        return;

      registry.destroy(entity1);
      registry.destroy(entity2);

      // Asteroid 1 -> splits into 2 asteroids 3,4
      sf::Vector2f position3 = transform1.position + (level1 - 1) * (level1 - 1) * 15.0f * perpNormal;
      sf::Vector2f velocity3 = rotateVector(newVelocity1, ASTEROID_SPLIT_ANGLE);
      sf::Vector2f position4 = transform1.position - (level1 - 1) * (level1 - 1) * 15.0f * perpNormal;
      sf::Vector2f velocity4 = rotateVector(newVelocity1, -ASTEROID_SPLIT_ANGLE);
      splitAsteroid(registry, entity1, level1, position3, velocity3, position4, velocity4);

      // Asteroid 2 -> splits into 2 asteroids 5,6
      sf::Vector2f position5 = transform2.position + (level2 - 1) * (level2 - 1) * 15.0f * perpNormal;
      sf::Vector2f velocity5 = rotateVector(newVelocity2, -ASTEROID_SPLIT_ANGLE);
      sf::Vector2f position6 = transform2.position - (level2 - 1) * (level2 - 1) * 15.0f * perpNormal;
      sf::Vector2f velocity6 = rotateVector(newVelocity2, ASTEROID_SPLIT_ANGLE);
      splitAsteroid(registry, entity2, level2, position5, velocity5, position6, velocity6);
    }

    sf::Vector2f rotateVector(sf::Vector2f vector, float angle)
    {
      float cosAngle = std::cos(DEG_TO_RAD * angle);
      float sinAngle = std::sin(DEG_TO_RAD * angle);
      sf::Vector2f rotatedVector(cosAngle * vector.x - sinAngle * vector.y,
                                 sinAngle * vector.x + cosAngle * vector.y);
      return rotatedVector;
    }

    void splitAsteroid(entt::registry &registry,
                       entt::entity entity, int level,
                       sf::Vector2f position1, sf::Vector2f velocity1,
                       sf::Vector2f position2, sf::Vector2f velocity2)
    {
      if (level < 2 || level > 3)
        return;

      Entity::createAsteroid(registry, window, level - 1, position1, velocity1);
      Entity::createAsteroid(registry, window, level - 1, position2, velocity2);
    }

    void handleBulletCollision(entt::registry &registry,
                               entt::entity bullet, Component::Transform bulletTransform,
                               entt::entity asteroid, Component::Transform transform, Component::Velocity velocity, int level)
    {
      registry.destroy(bullet);

      // Find collision normal
      sf::Vector2f collisionNormal = bulletTransform.position - transform.position;
      collisionNormal /= std::sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);
      sf::Vector2 perpNormal(-collisionNormal.y, collisionNormal.x);

      sf::Vector2f &originalVelocity = velocity.velocity;

      if (!registry.valid(asteroid))
        return;
      registry.destroy(asteroid);

      sf::Vector2f position1 = transform.position + (level - 1) * (level - 1) * 15.0f * perpNormal;
      sf::Vector2f velocity1 = rotateVector(originalVelocity, ASTEROID_SPLIT_ANGLE);
      sf::Vector2f position2 = transform.position - (level - 1) * (level - 1) * 15.0f * perpNormal;
      sf::Vector2f velocity2 = rotateVector(originalVelocity, -ASTEROID_SPLIT_ANGLE);

      splitAsteroid(registry, asteroid, level, position1, velocity1, position2, velocity2);
    }

  public:
    Collision(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Transform, Component::Collider, Component::Velocity>();
      auto asteroidView = registry.view<Component::Transform, Component::Collider, Component::Asteroid, Component::Velocity>();
      auto playerView = registry.view<Component::Transform, Component::Collider, Component::Player, Component::Velocity>();
      auto bulletView = registry.view<Component::BulletTag>();

      for (auto entity1 : view)
      {
        if (!registry.valid(entity1))
          continue;
        const Component::Collider &collider1 = view.get<Component::Collider>(entity1);
        const Component::Transform &transform1 = view.get<Component::Transform>(entity1);
        const Component::Velocity &velocity1 = view.get<Component::Velocity>(entity1);

        for (auto entity2 : view)
        {
          if (!registry.valid(entity2))
            continue;
          if (entity1 == entity2)
            continue;

          const Component::Collider &collider2 = view.get<Component::Collider>(entity2);
          const Component::Transform &transform2 = view.get<Component::Transform>(entity2);
          const Component::Velocity &velocity2 = view.get<Component::Velocity>(entity2);

          if (collider1.shape.getGlobalBounds().intersects(collider2.shape.getGlobalBounds()))
          {
            // Determine entity types using tag components
            const bool isAsteroid1 = asteroidView.contains(entity1);
            const bool isPlayer1 = playerView.contains(entity1);
            const bool isBullet1 = bulletView.contains(entity1);
            const bool isAsteroid2 = asteroidView.contains(entity2);
            const bool isPlayer2 = playerView.contains(entity2);
            const bool isBullet2 = bulletView.contains(entity2);

            if (isAsteroid1 && isAsteroid2)
            {
              handleAsteroidCollision(registry, entity1, transform1, velocity1, asteroidView.get<Component::Asteroid>(entity1).level,
                                      entity2, transform2, velocity2, asteroidView.get<Component::Asteroid>(entity2).level);
            }
            else if (isAsteroid1 && isPlayer2 || isPlayer1 && isAsteroid2)
            {
              // Asteroid-to-Player collision
              // std::cout << "Player\n";
              // handleAsteroidPlayerCollision(registry, entity1, entity2);
            }
            else if (isAsteroid1 && isBullet2)
            {
              handleBulletCollision(registry,
                                    entity2, transform2,
                                    entity1, transform1, velocity1, asteroidView.get<Component::Asteroid>(entity1).level);
            }
            else if (isBullet1 && isAsteroid2)
            {
              handleBulletCollision(registry,
                                    entity1, transform1,
                                    entity2, transform2, velocity2, asteroidView.get<Component::Asteroid>(entity2).level);
            }
            else
            {
              // std::cout << "Unexpected collision (unknown entities)\n";
            }
          }
        }
      }
    }
  };
}