#include "SystemScore.hpp"

#include <iostream>

SystemScore::SystemScore(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemScore::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto playerView = registry.view<ComponentScore>();

  for (auto player : playerView)
  {
    ComponentScore &score = playerView.get<ComponentScore>(player);

    auto uiView = registry.view<ComponentScoreText>();
    for (auto ui : uiView)
    {
      ComponentScoreText &scoreText = uiView.get<ComponentScoreText>(ui);
      scoreText.text->setString("Score: " + std::to_string(score.value));
    }
  }
}