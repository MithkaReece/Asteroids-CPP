#include "SystemSaveHighScore.hpp"

void SystemSaveHighScore::SaveHighScore(entt::registry &registry)
{
  for (auto [highScoreEntity, highScore] : registry.view<ComponentHighScore>().each())
  {
    int savedHighScore = ResourceManager::getInstance().getHighScore();
    if (savedHighScore < highScore.value)
      ResourceManager::getInstance().setHighScore(highScore.value);
  }
}