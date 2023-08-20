#include "SystemHUD.hpp"

SystemHUD::SystemHUD() {}

void SystemHUD::update(sf::Time dt)
{
  entt::registry &registry = GlobalObjects::getRegistry();
  for (auto [textEntity, text] : registry.view<ComponentText>().each())
  {
    if (text.ID == "Score")
    {
      for (auto [valueEntity, score] : registry.view<ComponentScore>().each())
        text.text->setString("Score: " + std::to_string(score.value));
    }
    else if (text.ID == "Lives")
    {
      for (auto [valueEntity, lives] : registry.view<ComponentLives>().each())
        text.text->setString("Lives: " + std::to_string(lives.value));
    }
    else if (text.ID == "HighScore")
    {
      for (auto [valueEntity, highScore] : registry.view<ComponentHighScore>().each())
        text.text->setString("High Score: " + std::to_string(highScore.value));
    }
    sf::FloatRect textBounds = text.text->getGlobalBounds();
    text.text->setOrigin(textBounds.width / 2.f, 0.f);
  }
}