#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>

#include <entt/entt.hpp>

#include "SystemSaveHighScore.hpp"
#include "ResourceManager.hpp"

#include "SystemRender.hpp"

#include "SystemManager.hpp"
#include "SceneManager.hpp"

#include "GlobalObjects.hpp"

// Temp
#include <iostream>

entt::dispatcher globalDispatcher;

int main(int argc, char *argv[])
{
  sf::RenderWindow &window = GlobalObjects::getWindow();
  entt::registry &registry = GlobalObjects::getRegistry();

  ResourceManager::getInstance(); // Create resource manager

  SystemManager &systemManager = SystemManager::getInstance();

  SceneManager &sceneManager = SceneManager::getInstance();

  sf::Clock clock;
  sf::Time dt;

  // Frame loop
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    { // Close window (on close button)
      if (event.type == sf::Event::Closed)
      {
        SystemSaveHighScore::SaveHighScore();
        window.close();
      }
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