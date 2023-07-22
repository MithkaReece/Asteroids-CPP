#include "SystemPauseMenuToggle.hpp"

extern entt::dispatcher globalDispatcher;

#include <iostream>

SystemPauseMenuToggle::SystemPauseMenuToggle(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene)
{
}

void SystemPauseMenuToggle::update(sf::Time dt)
{
  auto view = registryRef.get().view<ComponentScene>();
  for (auto [entity, sceneInfo] : view.each())
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !sceneInfo.pausePressed && sceneInfo.inGame)
    {
      if (sceneInfo.pauseMenu)
      {
        std::cout << "Unpause\n";
        sceneInfo.pauseMenu = false;
        globalDispatcher.trigger<EventUnpause>();
      }
      else
      {
        std::cout << "Pause\n";
        sceneInfo.pauseMenu = true;
        globalDispatcher.trigger<EventPause>();
      }
    }
    sceneInfo.pausePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
  }
}