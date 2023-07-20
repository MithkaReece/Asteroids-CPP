#pragma once
#ifndef HEADER_SCENE_GAME_UI
#define HEADER_SCENE_GAME_UI
#include "Scene.hpp"
#include "EntityLevelUI.hpp"
#include "SystemScore.hpp"
#include "SystemLives.hpp"

class SceneGameUI : public Scene
{
public:
  SceneGameUI(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

  int precedence() override { return 0; }
};
#endif