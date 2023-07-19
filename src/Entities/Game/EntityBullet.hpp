#pragma once
#ifndef HEADER_ENTITY_BULLET
#define HEADER_ENTITY_BULLET
#include <entt/entt.hpp>
#include "ComponentBulletTag.hpp"
#include "ComponentTransform.hpp"
#include "ComponentVelocity.hpp"
#include "ComponentRender.hpp"
#include "ComponentCollider.hpp"

#include "Scene.hpp"
#include <SFML/Graphics.hpp>

/**
 * @brief Create a bullet shape.
 *
 * @return The created bullet shape.
 */
sf::ConvexShape entityBulletShape();

/**
 * @brief Create a bullet entity with the specified position, velocity and rotation.
 *
 * @param registry The entity registry.
 * @param position The position of the bullet.
 * @param velocity The velocity of the bullet.
 * @param rotation The rotation of the bullet.
 */
void entityBullet(Scene &scene, sf::Vector2f position,
                  sf::Vector2f velocity, float rotation);
#endif