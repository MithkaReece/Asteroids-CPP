#pragma once
#ifndef HEADER_SCENE_LEVEL
#define HEADER_SCENE_LEVEL
#include <entt/entt.hpp>
#include "Scene.hpp"

#include "SystemMovement.hpp"
#include "SystemCollision.hpp"
#include "SystemWrapping.hpp"
#include "SystemUserInput.hpp"
#include "SystemAsteroidSpawner.hpp"
#include "SystemCollider.hpp"
#include "SystemPlayerThrust.hpp"
#include "SystemPlayerRotate.hpp"
#include "SystemWeapon.hpp"
#include "SystemOutOfBound.hpp"

#include "EntityPlayer.hpp"
#include "EntityScoreUI.hpp"

/**
 * @brief Implementation of Scene0 class, representing the first scene of the game.
 */
class SceneLevel : public Scene
{
public:
  SceneLevel(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);
  int precedence() override { return 0; }
};
#endif