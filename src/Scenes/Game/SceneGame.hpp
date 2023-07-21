#pragma once
#ifndef HEADER_SCENE_GAME
#define HEADER_SCENE_GAME

#include <entt/entt.hpp>
#include "Scene.hpp"
#include "EntityGame.hpp"

class SceneGame : public Scene
{
public:
  SceneGame(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);
  int precedence() override { return -1; }
};

#endif