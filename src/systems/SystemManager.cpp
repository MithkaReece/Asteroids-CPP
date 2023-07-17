#pragma once

#include "System.hpp"

#include "MovementSystem.hpp"
#include "CollisionSystem.hpp"
#include "RenderSystem.hpp"
#include "WrappingSystem.hpp"
#include "UserInputSystem.hpp"
#include "AsteroidSpawnerSystem.hpp"
#include "ColliderSystem.hpp"
#include "PlayerThrustSystem.hpp"
#include "PlayerRotateSystem.hpp"
#include "WeaponSystem.hpp"
#include "OutOfBoundSystem.hpp"

class SystemManager
{
private:
    std::vector<std::unique_ptr<System>> systems;
    std::unique_ptr<RenderSystem> renderSystem;

public:
    // Adds all the systems
    SystemManager(sf::RenderWindow &window) : renderSystem(std::make_unique<RenderSystem>(window))
    {
        // Spawners
        systems.push_back(std::make_unique<AsteroidSpawnerSystem>(window, sf::milliseconds(2000)));

        // Input
        systems.push_back(std::make_unique<UserInputSystem>());
        // Input responses
        systems.push_back(std::make_unique<PlayerThrustSystem>());
        systems.push_back(std::make_unique<PlayerRotateSystem>());
        systems.push_back(std::make_unique<WeaponSystem>());

        // Applying velocity
        systems.push_back(std::make_unique<MovementSystem>());
        // Collider positioning
        systems.push_back(std::make_unique<ColliderSystem>());
        // Keep objects within boundary or deleted
        systems.push_back(std::make_unique<WrappingSystem>(window));
        systems.push_back(std::make_unique<OutOfBoundSystem>());

        // Detects collisions
        systems.push_back(std::make_unique<CollisionSystem>(window));
    }

    void updateSystems(entt::registry &registry, sf::Time dt)
    {
        for (auto &system : systems)
            system->update(registry, dt);
    }

    void updateRenderSystem(entt::registry &registry, sf::Time dt)
    {
        renderSystem->update(registry, dt);
    }
};