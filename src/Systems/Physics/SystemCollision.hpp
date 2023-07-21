#pragma once
#ifndef HEADER_SYSTEM_COLLISION
#define HEADER_SYSTEM_COLLISION
#include "System.hpp"

#include "ComponentTransform.hpp"
#include "ComponentCollider.hpp"
#include "ComponentVelocity.hpp"
#include "ComponentPlayer.hpp"
#include "ComponentAsteroid.hpp"
#include "ComponentBulletTag.hpp"
#include "ComponentScore.hpp"
#include "ComponentLives.hpp"

#include "EntityAsteroid.hpp"

#include "EventDeath.hpp"

#include "Constants.h"
#include <string>



/**
 * @brief Class for handling collisions between entities.
 */
class SystemCollision : public System
{

public:
  SystemCollision(entt::registry &registry, sf::RenderWindow &window, Scene &scene);

  /**
   * @brief Updates the collision system.
   *
   * @param registry The entity registry.
   * @param dt The delta time.
   */
  void update(sf::Time dt);

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
  void handleAsteroidCollision(entt::entity entity1, ComponentTransform transform1, ComponentVelocity velocity1, int level1,
                               entt::entity entity2, ComponentTransform transform2, ComponentVelocity velocity2, int level2);
  /**
   * @brief Rotates a vector by a given angle.
   *
   * @param vector The vector to rotate.
   * @param angle The angle of rotation.
   * @return sf::Vector2f The rotated vector.
   */
  sf::Vector2f rotateVector(sf::Vector2f vector, float angle);

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
  void splitAsteroid(entt::entity entity, int level,
                     sf::Vector2f position1, sf::Vector2f velocity1,
                     sf::Vector2f position2, sf::Vector2f velocity2);

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
  void handleBulletCollision(entt::entity bullet, ComponentTransform bulletTransform,
                             entt::entity asteroid, ComponentTransform transform, ComponentVelocity velocity, int level);

  /**
   * @brief Increases the score by a specified amount.
   *
   * @param registry The entity registry.
   * @param scoreIncrease The amount to increase the score by.
   */
  void addScore(int scoreIncrease);

  void handlePlayerCollision();

  void resetScore();
};
#endif