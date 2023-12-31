#pragma once
#ifndef HEADER_ENTITY_GAME
#define HEADER_ENTITY_GAME

#include <entt/entt.hpp>
#include "Scene.hpp"
#include "ComponentHighScore.hpp"
#include "ComponentScore.hpp"
#include "ComponentLives.hpp"
#include "ComponentScene.hpp"
#include "ComponentBackground.hpp"

#include "ResourceManager.hpp"
#include "GlobalObjects.hpp"

void EntityGame(Scene &scene);

#endif