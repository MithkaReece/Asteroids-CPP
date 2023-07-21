#pragma once
#ifndef HEADER_SCENE_BUILDER
#define HEADER_SCENE_BUILDER

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
#include "SystemScore.hpp"
#include "SystemLives.hpp"
#include "SystemMenuInput.hpp"
#include "SystemMouseHover.hpp"

#include "EntityGame.hpp"
#include "EntityPlayer.hpp"
#include "EntityScoreUI.hpp"
#include "EntityLevelUI.hpp"
#include "EntityMainMenu.hpp"

#include "EnumMenuItemID.hpp"

std::unique_ptr<Scene> SceneGame(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

std::unique_ptr<Scene> SceneMainMenu(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

std::unique_ptr<Scene> SceneGameplay(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

std::unique_ptr<Scene> SceneHUD(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

std::unique_ptr<Scene> ScenePauseMenu(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);
#endif