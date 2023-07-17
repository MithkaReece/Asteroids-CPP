#pragma once

#include <entt/entt.hpp>
#include "System.hpp"
#include "CollisionSystem.hpp"
#include "../components/TransformComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/PlayerComponent.hpp"
#include "../components/AsteroidComponent.hpp"

#include "../entities/AsteroidEntity.hpp"

#include "../Constants.h"

// Temp
#include <iostream>

class CollisionSystem : public System
{
private:
    sf::RenderWindow &window;

    void handleAsteroidCollision(entt::registry &registry,
                                 entt::entity entity1, TransformComponent transform1, VelocityComponent velocity1, int level1,
                                 entt::entity entity2, TransformComponent transform2, VelocityComponent velocity2, int level2)
    {
        float mass1 = std::sqrt(transform1.scale.x * transform1.scale.x + transform1.scale.y * transform1.scale.y);
        float mass2 = std::sqrt(transform2.scale.x * transform2.scale.x + transform2.scale.y * transform2.scale.y);

        // Calculate the collision normal
        sf::Vector2f collisionNormal = transform2.position - transform1.position;
        collisionNormal /= std::sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);
        sf::Vector2 perpNormal(-collisionNormal.y, collisionNormal.x);

        // Calculate the relative velocity
        sf::Vector2f relativeVelocity = velocity2.velocity - velocity1.velocity;

        // Calculate the impulse magnitude
        float impulseMagnitude = (2.0f * mass2 * (relativeVelocity.x * collisionNormal.x + relativeVelocity.y * collisionNormal.y)) / (mass1 + mass2);

        // Calculate the new velocities
        sf::Vector2f newVelocity1 = velocity1.velocity + (impulseMagnitude * collisionNormal) / mass1;
        sf::Vector2f newVelocity2 = velocity2.velocity - (impulseMagnitude * collisionNormal) / mass2;

        const float splitAngle = 30.0f;

        // Asteroid 1 -> splits into 2 asteroids 3,4
        sf::Vector2f velocity3 = rotateVector(newVelocity1, splitAngle);
        sf::Vector2f velocity4 = rotateVector(newVelocity1, -splitAngle);

        // Asteroid 2 -> splits into 2 asteroids 5,6
        sf::Vector2f velocity5 = rotateVector(newVelocity2, -splitAngle);
        sf::Vector2f velocity6 = rotateVector(newVelocity2, splitAngle);

        // Destroy old asteroids
        if (!(registry.valid(entity1) && registry.valid(entity2)))
            return;
        registry.destroy(entity1);
        registry.destroy(entity2);

        // Create asteroids halves
        if (level1 > 1)
        {
            createAsteroid(registry, window, level1 - 1, transform1.position + (level1 - 1) * (level1 - 1) * 15.0f * perpNormal, velocity3);
            createAsteroid(registry, window, level1 - 1, transform1.position - (level1 - 1) * (level1 - 1) * 15.0f * perpNormal, velocity4);
        }

        if (level2 > 1)
        {
            createAsteroid(registry, window, level2 - 1, transform2.position + (level2 - 1) * (level2 - 1) * 15.0f * perpNormal, velocity5);
            createAsteroid(registry, window, level2 - 1, transform2.position - (level2 - 1) * (level2 - 1) * 15.0f * perpNormal, velocity6);
        }
    }

    sf::Vector2f rotateVector(sf::Vector2f vector, float angle)
    {
        float cosAngle = std::cos(DEG_TO_RAD * angle);
        float sinAngle = std::sin(DEG_TO_RAD * angle);
        sf::Vector2f rotatedVector(cosAngle * vector.x - sinAngle * vector.y,
                                   sinAngle * vector.x + cosAngle * vector.y);
        return rotatedVector;
    }

public:
    CollisionSystem(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<TransformComponent, ColliderComponent, VelocityComponent>();
        auto asteroidView = registry.view<TransformComponent, ColliderComponent, AsteroidComponent, VelocityComponent>();
        auto playerView = registry.view<TransformComponent, ColliderComponent, PlayerComponent, VelocityComponent>();

        for (auto entity1 : view)
        {
            if (!registry.valid(entity1))
                continue;
            const ColliderComponent &collider1 = view.get<ColliderComponent>(entity1);
            const TransformComponent &transform1 = view.get<TransformComponent>(entity1);
            const VelocityComponent &velocity1 = view.get<VelocityComponent>(entity1);

            for (auto entity2 : view)
            {
                if (!registry.valid(entity2))
                    continue;
                if (entity1 == entity2)
                    continue;

                const ColliderComponent &collider2 = view.get<ColliderComponent>(entity2);
                const TransformComponent &transform2 = view.get<TransformComponent>(entity2);
                const VelocityComponent &velocity2 = view.get<VelocityComponent>(entity2);

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
                        handleAsteroidCollision(registry, entity1, transform1, velocity1, asteroidView.get<AsteroidComponent>(entity1).level,
                                                entity2, transform2, velocity2, asteroidView.get<AsteroidComponent>(entity2).level);
                        //  handleAsteroidCollision(registry, entity1, entity2);
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
                        std::cout << "Unexpected collision (unknown entities)\n";
                    }
                }
            }
        }
    }
};