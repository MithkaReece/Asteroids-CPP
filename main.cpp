#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "src/components/PlayerComponent.hpp"
#include "src/components/PositionComponent.hpp"
#include "src/components/VelocityComponent.hpp"

#include "src/systems/SystemManager.cpp"
#include "src/systems/UserInputSystem.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

void createPlayer(entt::registry &registry)
{
    auto entity = registry.create();

    registry.emplace<PlayerComponent>(entity);
    registry.emplace<PositionComponent>(entity, sf::Vector2f(30.0f, 30.0f));
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

    createPlayer(registry);
    // Create an entity with position and velocity components
    auto entity = registry.create();
    registry.emplace<PositionComponent>(entity, sf::Vector2f(100.f, 100.f));
    registry.emplace<VelocityComponent>(entity, sf::Vector2f(50.f, 0.f));

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

        // TODO Drawing entities automated
        //  Draw entities based on their position component
        auto view = registry.view<PositionComponent>();
        for (auto entity : view)
        {
            const auto &position = view.get<PositionComponent>(entity);

            sf::CircleShape circle(10.f);
            circle.setPosition(position.position);
            circle.setFillColor(sf::Color::Red);

            window.draw(circle);
        }

        // Display the window
        window.display();
    }

    return 0;
}