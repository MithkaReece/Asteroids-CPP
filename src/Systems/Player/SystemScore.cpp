#include "SystemScore.hpp"

#include <iostream>

SystemScore::SystemScore() {}

void SystemScore::update(sf::Time dt)
{
  entt::registry &registry = GlobalObjects::getRegistry();
  auto playerView = registry.view<ComponentScore>();

  for (auto [player, score] : playerView.each())
  {
    auto uiView = registry.view<ComponentScoreText>();
    for (auto [ui, scoreText] : uiView.each())
      scoreText.text->setString("Score: " + std::to_string(score.value));
  }
}