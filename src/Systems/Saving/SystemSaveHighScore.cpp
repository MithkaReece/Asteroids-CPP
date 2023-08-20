#include "SystemSaveHighScore.hpp"

void SystemSaveHighScore::SaveHighScore()
{
  for (auto [highScoreEntity, highScore] : GlobalObjects::getRegistry().view<ComponentHighScore>().each())
  {
    int savedHighScore = ResourceManager::getInstance().getHighScore();
    if (savedHighScore < highScore.value)
      ResourceManager::getInstance().setHighScore(highScore.value);
  }
}