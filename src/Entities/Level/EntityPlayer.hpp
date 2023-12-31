#pragma once
#ifndef HEADER_ENTITY_PLAYER
#define HEADER_ENTITY_PLAYER
#include <entt/entt.hpp>

#include <SFML/Graphics.hpp>

#include "ComponentPlayer.hpp"
#include "ComponentAcceleration.hpp"
#include "ComponentTransform.hpp"
#include "ComponentVelocity.hpp"
#include "ComponentWrapperBoundary.hpp"
#include "ComponentRender.hpp"
#include "ComponentCollider.hpp"
#include "ComponentPlayerInput.hpp"
#include "ComponentWeapon.hpp"

#include "Scene.hpp"
#include "GlobalObjects.hpp"

/**
 * @brief Create a triangle shape.
 *
 * @return The created triangle shape.
 */
sf::ConvexShape entityTriangle();

/**
 * @brief Create a player entity with the specified components.
 *
 * @param registry The entity registry.
 * @param window The render window.
 */
void EntityPlayer(Scene &scene);
#endif