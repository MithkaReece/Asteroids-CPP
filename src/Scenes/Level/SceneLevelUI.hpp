#pragma once
#ifndef HEADER_SCENE_LEVEL_UI
#define HEADER_SCENE_LEVEL_UI
#include "Scene.hpp"
#include "EntityLevelUI.hpp"
#include "SystemScore.hpp"
#include "SystemLives.hpp"

class SceneLevelUI : public Scene
{
public:
  SceneLevelUI(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window);

  int precedence() override { return 0; }
};
#endif