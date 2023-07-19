#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>

#include <entt/entt.hpp>

#include "systems/SystemManager.hpp"
#include "scenes/SceneManager.hpp"

// Temp
#include <iostream>

int main(int argc, char *argv[])
{
  sf::RenderWindow window(sf::VideoMode(1000, 600), "");

  entt::registry registry;
  System::Manager systemManager;
  Scene::Manager sceneManager(systemManager, registry, window);

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
    sceneManager.updateSystems(dt);
    // Render
    window.clear(sf::Color::Black);
    sceneManager.updateRenderSystem(dt);

    // Display the window
    window.display();
  }

  return 0;
}