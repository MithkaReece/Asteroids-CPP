#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "CollisionSystem.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PlayerComponent.hpp"
#include "../components/AsteroidComponent.hpp"

// Temp
#include <iostream>

class CollisionSystem : public System
{
public:
    void update(entt::registry &registry, float dt)
    {
        auto view = registry.view<TransformComponent, ColliderComponent>();
        auto asteroidView = registry.view<TransformComponent, ColliderComponent, AsteroidComponent>();
        auto playerView = registry.view<TransformComponent, ColliderComponent, PlayerComponent>();

        for (auto entity1 : view)
        {
            const auto &collider1 = view.get<ColliderComponent>(entity1);

            for (auto entity2 : view)
            {
                if (entity1 == entity2)
                    continue;

                const auto &collider2 = view.get<ColliderComponent>(entity2);

                if (collider1.shape.getGlobalBounds().intersects(collider2.shape.getGlobalBounds()))
                {

                    // Determine entity types using tag components
                    const bool isAsteroid1 = asteroidView.contains(entity1);
                    const bool isPlayer1 = playerView.contains(entity1);
                    const bool isAsteroid2 = asteroidView.contains(entity2);
                    const bool isPlayer2 = playerView.contains(entity2);

                    if (isAsteroid1 && isAsteroid2)
                    {
                        // Asteroid-to-Asteroid collision
                        std::cout << "Asteroid\n";
                        // handleAsteroidCollision(registry, entity1, entity2);
                    }
                    else if (isAsteroid1 && isPlayer2)
                    {
                        // Asteroid-to-Player collision
                        std::cout << "Player\n";
                        // handleAsteroidPlayerCollision(registry, entity1, entity2);
                    }
                    else if (isPlayer1 && isAsteroid2)
                    {
                        // Player-to-Asteroid collision
                        std::cout << "Player\n";
                        // handlePlayerAsteroidCollision(registry, entity1, entity2);
                    }
                    else
                    {
                        std::cout << "WHAT?\n";
                    }
                }
            }
        }
    }
};