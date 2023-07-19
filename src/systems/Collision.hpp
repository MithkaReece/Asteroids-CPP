#pragma once

#include "systems/System.hpp"

#include "components/Transform.hpp"
#include "components/Collider.hpp"
#include "components/Velocity.hpp"
#include "components/Player.hpp"
#include "components/Asteroid.hpp"
#include "components/BulletTag.hpp"
#include "components/TextUI.hpp"
#include "components/ScoreTag.hpp"

#include "entities/Asteroid.hpp"

#include "scenes/SceneManager.hpp"

// TODO This is require but is circlular dependency
//   #include "scenes/Manager.cpp"

#include "Constants.h"
#include <string>

// Temp
#include <iostream>

namespace System
{
  /**
   * @brief Class for handling collisions between entities.
   */
  class Collision : public System
  {

  public:
    Collision(std::reference_wrapper<Scene::IManager> sceneManager, Scene::IScene &scene)
        : System::System(sceneManager, scene) {}

    /**
     * @brief Updates the collision system.
     *
     * @param registry The entity registry.
     * @param dt The delta time.
     */
    void update(sf::Time dt)
    {
      entt::registry &registry = sceneManagerRef.get().registryRef.get();
      auto asteroidView = registry.view<Component::Transform, Component::Collider, Component::Asteroid, Component::Velocity>();
      auto playerView = registry.view<Component::Transform, Component::Collider, Component::Player, Component::Velocity>();
      auto bulletView = registry.view<Component::BulletTag>();

      registry.view<Component::Transform, Component::Collider, Component::Velocity>()
          .each([this, &registry, asteroidView, playerView, bulletView](entt::entity entity1, Component::Transform &transform1, Component::Collider &collider1, Component::Velocity &velocity1)
                { registry.view<Component::Transform, Component::Collider, Component::Velocity>()
                      .each([this, &registry, asteroidView, playerView, bulletView, entity1, &transform1, &collider1, &velocity1](entt::entity entity2, Component::Transform &transform2, Component::Collider &collider2, Component::Velocity &velocity2)
                            {
                              if (entity1 == entity2 || !collider1.shape.getGlobalBounds().intersects(collider2.shape.getGlobalBounds()))
                                return;
                              
                              const bool isAsteroid1 = asteroidView.contains(entity1), isPlayer1 = playerView.contains(entity1), isBullet1 = bulletView.contains(entity1);
                              const bool isAsteroid2 = asteroidView.contains(entity2), isPlayer2 = playerView.contains(entity2), isBullet2 = bulletView.contains(entity2);

                              if(isAsteroid1 && isAsteroid2)
                                handleAsteroidCollision(registry, entity1, transform1, velocity1, asteroidView.get<Component::Asteroid>(entity1).level,
                                      entity2, transform2, velocity2, asteroidView.get<Component::Asteroid>(entity2).level);
                              else if(isAsteroid1 && isPlayer2 || isPlayer1 && isAsteroid2)
                                handlePlayerCollision();
                              else if (isAsteroid1 && isBullet2)
                                handleBulletCollision(registry,
                                                      entity2, transform2,
                                                      entity1, transform1, velocity1, asteroidView.get<Component::Asteroid>(entity1).level);
                              else if (isBullet1 && isAsteroid2)
                                handleBulletCollision(registry,
                                                      entity1, transform1,
                                                      entity2, transform2, velocity2, asteroidView.get<Component::Asteroid>(entity2).level); }); });
    }

  private:
    /**
     * @brief Handles collision between two asteroids.
     *
     * @param registry The entity registry.
     * @param entity1 The first asteroid entity.
     * @param transform1 The transform component of the first asteroid.
     * @param velocity1 The velocity component of the first asteroid.
     * @param level1 The level of the first asteroid.
     * @param entity2 The second asteroid entity.
     * @param transform2 The transform component of the second asteroid.
     * @param velocity2 The velocity component of the second asteroid.
     * @param level2 The level of the second asteroid.
     */
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
    /**
     * @brief Rotates a vector by a given angle.
     *
     * @param vector The vector to rotate.
     * @param angle The angle of rotation.
     * @return sf::Vector2f The rotated vector.
     */
    sf::Vector2f rotateVector(sf::Vector2f vector, float angle)
    {
      float cosAngle = std::cos(DEG_TO_RAD * angle);
      float sinAngle = std::sin(DEG_TO_RAD * angle);
      sf::Vector2f rotatedVector(cosAngle * vector.x - sinAngle * vector.y,
                                 sinAngle * vector.x + cosAngle * vector.y);
      return rotatedVector;
    }

    /**
     * @brief Splits an asteroid into two smaller asteroids.
     * Spawning 2 smaller asteroids if original above level 1
     *
     * @param registry The entity registry.
     * @param entity The asteroid entity to split.
     * @param level The level of the asteroid.
     * @param position1 The position of the first split asteroid.
     * @param velocity1 The velocity of the first split asteroid.
     * @param position2 The position of the second split asteroid.
     * @param velocity2 The velocity of the second split asteroid.
     */
    void splitAsteroid(entt::registry &registry,
                       entt::entity entity, int level,
                       sf::Vector2f position1, sf::Vector2f velocity1,
                       sf::Vector2f position2, sf::Vector2f velocity2)
    {
      if (level < 2 || level > 3)
        return;

      // TODO registry -> scene
      // Entity::createAsteroid(registry, sceneManagerRef.get().windowRef.get(), level - 1, position1, velocity1);
      // Entity::createAsteroid(registry, sceneManagerRef.get().windowRef.get(), level - 1, position2, velocity2);
    }

    /**
     * @brief Handles collision between a bullet and an asteroid.
     *  Splits asteroid, deletes bullet and adds a score.
     *
     * @param registry The entity registry.
     * @param bullet The bullet entity.
     * @param bulletTransform The transform component of the bullet.
     * @param asteroid The asteroid entity.
     * @param transform The transform component of the asteroid.
     * @param velocity The velocity component of the asteroid.
     * @param level The level of the asteroid.
     */
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

      addScore(registry, 1);
    }

    /**
     * @brief Increases the score by a specified amount.
     *
     * @param registry The entity registry.
     * @param scoreIncrease The amount to increase the score by.
     */
    void addScore(entt::registry &registry, int scoreIncrease)
    {
      auto view = registry.view<Component::Transform, Component::TextUI, Component::ScoreTag>();

      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;
        // Increment score value
        Component::TextUI &textUI = view.get<Component::TextUI>(entity);
        int score = std::stoi(textUI.text);
        score += scoreIncrease;
        textUI.text = std::to_string(score);
      }
    }

    void handlePlayerCollision()
    {
      // TODO: In system updates, also give the sceneManager
      // TODO: Conversely just give the scene manager as it also holds registry and window
      // Scene::Manager &sceneManager = Scene::Manager::getInstance();
      //  TODO: Reset level scene
      //  sceneManager.switchToScene(0);
    }
  };
}