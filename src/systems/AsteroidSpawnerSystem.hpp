#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "../entities/AsteroidEntity.hpp"

#include <iostream>
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
            createAsteroid(registry, window);
            timer = sf::Time::Zero;
        }
    }
};