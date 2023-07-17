#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <entt/entt.hpp>

#include "systems/Manager.cpp"

#include "scenes/SceneManager.cpp"

// Temp
#include <iostream>

// Function to create an asteroid

int main(int argc, char *argv[])
{
  sf::RenderWindow window(sf::VideoMode(1000, 600), "");

  entt::registry registry;
  System::Manager systemManager(window);
  SceneManager sceneManager(registry, window, 0);

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
    systemManager.updateSystems(registry, dt);
    // Render
    window.clear(sf::Color::Black);
    systemManager.updateRenderSystem(registry, dt);

    // Display the window
    window.display();
  }

  return 0;
}