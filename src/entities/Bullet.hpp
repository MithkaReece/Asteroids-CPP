#pragma once
#include <entt/entt.hpp>
#include "components/BulletTag.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/Render.hpp"
#include "components/Collider.hpp"

#include "scenes/Scene.hpp"
#include <SFML/Graphics.hpp>

namespace Entity
{
  /**
   * @brief Create a bullet shape.
   *
   * @return The created bullet shape.
   */
  sf::ConvexShape createBulletShape();

  /**
   * @brief Create a bullet entity with the specified position, velocity and rotation.
   *
   * @param registry The entity registry.
   * @param position The position of the bullet.
   * @param velocity The velocity of the bullet.
   * @param rotation The rotation of the bullet.
   */
  void createBullet(Scene::Scene &scene, sf::Vector2f position,
                    sf::Vector2f velocity, float rotation);
}