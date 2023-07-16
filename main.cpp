#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "src/components/PlayerComponent.hpp"
#include "src/components/TransformComponent.hpp"
#include "src/components/RenderComponent.hpp"
#include "src/components/VelocityComponent.hpp"

#include "src/systems/SystemManager.cpp"
#include "src/systems/UserInputSystem.hpp"
#include "src/systems/RenderSystem.hpp"

// Temp
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

void createPlayer(entt::registry &registry)
{
    auto entity = registry.create();

    registry.emplace<PlayerComponent>(entity, 1.0f);
    registry.emplace<TransformComponent>(entity, sf::Vector2f(30.0f, 30.0f),
                                         sf::Vector2f(1.0, 1.0f),
                                         0.0f);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0f, 0.0f));
    triangle.setPoint(1, sf::Vector2f(100.0f, 0.0f));
    triangle.setPoint(2, sf::Vector2f(50.0f, 100.0f));
    triangle.setFillColor(sf::Color::Red);
    std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(triangle));
    registry.emplace<RenderComponent>(entity, std::move(drawable));

    registry.emplace<VelocityComponent>(entity, sf::Vector2f(0.f, 0.f));
}

int main(int argc, char *argv[])
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "");

    // Define entity registry
    entt::registry registry;

    // Define systems
    SystemManager systemManager;
    UserInputSystem userInputSystem;
    RenderSystem renderSystem;

    createPlayer(registry);

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

        systemManager.updateSystems(registry, dt);
        userInputSystem.update(registry, dt, event.key.code);

        // Clear the window
        window.clear(sf::Color::White);

        // Draw all drawables
        renderSystem.update(registry, dt, window);

        // Display the window
        window.display();
    }

    return 0;
}