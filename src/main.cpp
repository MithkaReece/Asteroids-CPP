#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>

#include <entt/entt.hpp>

#include "SystemRender.hpp"
#include "SystemManager.hpp"
#include "SceneManager.hpp"

#include "EventManager.hpp"

// Temp
#include <iostream>

int main(int argc, char *argv[])
{

  EventManager &eventManager = EventManager::GetInstance();

  sf::RenderWindow window(sf::VideoMode(1000, 600), "");

  entt::registry registry;
  SystemManager systemManager(std::make_unique<SystemRender>(registry, window));
  SceneManager sceneManager(systemManager, registry, window);

  sf::Clock clock;
  sf::Time dt;

  // Frame loop
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    { // Close window (on close button)
      if (event.type == sf::Event::Closed)
        window.close();
      else if (event.type == sf::Event::Resized)
      {
      }
    }

    // Calculate delta time
    dt = clock.restart();
    // Update
    systemManager.updateSystems(dt);
    // Render
    window.clear(sf::Color::Black);
    systemManager.updateRenderSystem(dt);

    // Display the window
    window.display();
  }

  return 0;
}