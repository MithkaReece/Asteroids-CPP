#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <entt/entt.hpp>

#include "src/systems/SystemManager.cpp"

#include "src/scenes/SceneManager.cpp"

// Temp
#include <iostream>

// Function to create an asteroid

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "");

    entt::registry registry;
    SystemManager systemManager(window);
    SceneManager sceneManager(registry, 0);

    sf::Clock clock;

    // Frame loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        { // Close window (on close button)
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the movement system
        float dt = clock.restart().asSeconds();

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