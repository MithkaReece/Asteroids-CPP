#pragma once
#ifndef HEADER_SYSTEM_SAVE_HIGH_SCORE
#define HEADER_SYSTEM_SAVE_HIGH_SCORE
#include <entt/entt.hpp>
#include "ComponentHighScore.hpp"
#include "ResourceManager.hpp"

#include "GlobalObjects.hpp"

class SystemSaveHighScore
{
public:
  static void SaveHighScore();
};

#endif