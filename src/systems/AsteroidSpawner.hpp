#pragma once

#include <entt/entt.hpp>
#include "systems/System.hpp"
#include "entities/Asteroid.hpp"

#include <iostream>

namespace System
{
    class AsteroidSpawnerSystem : public System
    {
    private:
        sf::RenderWindow &window;
        sf::Time interval;
        sf::Time timer;

    public:
        AsteroidSpawnerSystem(sf::RenderWindow &window, sf::Time interval)
            : window(window), interval(interval) {}

        void update(entt::registry &registry, sf::Time dt)
        {
            timer += dt;
            if (timer >= interval)
            {
                Entity::createAsteroid(registry, window);
                timer = sf::Time::Zero;
            }
        }
    };
}