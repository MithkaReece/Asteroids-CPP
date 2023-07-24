#pragma once
#ifndef HEADER_SYSTEM_SAVE_HIGH_SCORE
#define HEADER_SYSTEM_SAVE_HIGH_SCORE
#include <entt/entt.hpp>
#include "ComponentHighScore.hpp"
#include "ResourceManager.hpp"

class SystemSaveHighScore
{
public:
  static void SaveHighScore(entt::registry &registry);
};

#endif