#include "SystemLives.hpp"

SystemLives::SystemLives(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemLives::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  auto playerView = registry.view<ComponentLives>();

  for (auto [player, lives] : playerView.each())
  {
    auto uiView = registry.view<ComponentLivesText>();
    for (auto [ui, livesText] : uiView.each())
      livesText.text->setString("Lives: " + std::to_string(lives.value));
  }
}