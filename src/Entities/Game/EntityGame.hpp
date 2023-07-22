#pragma once
#ifndef HEADER_ENTITY_GAME
#define HEADER_ENTITY_GAME

#include <entt/entt.hpp>
#include "Scene.hpp"
#include "ComponentScore.hpp"
#include "ComponentLives.hpp"
#include "ComponentScene.hpp"

void EntityGame(Scene &scene, sf::RenderWindow &window);

#endif