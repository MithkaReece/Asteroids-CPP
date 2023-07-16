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
        if (timer >= interval.count())
        {
            createAsteroid(registry, window);
            timer = 0;
        }
    }
};