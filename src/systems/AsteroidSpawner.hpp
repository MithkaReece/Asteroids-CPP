#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "../entities/AsteroidEntity.hpp"

#include <iostream>
class AsteroidSpawner : public System
{
private:
    sf::RenderWindow &window;
    std::chrono::seconds interval;
    float timer;

public:
    AsteroidSpawner(sf::RenderWindow &window, std::chrono::seconds interval)
        : window(window), interval(interval) {}

    void update(entt::registry &registry, float dt)
    {
        timer += dt;
        std::cout << timer << "||" << interval.count() << "\n";
        if (timer >= interval.count())
        {
            std::cout << "SPAWN\n";
            createAsteroid(registry, window);
            timer = 0;
        }
    }
};