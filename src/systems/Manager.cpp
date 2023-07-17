#pragma once

#include "systems/System.hpp"

#include "systems/Movement.hpp"
#include "systems/Collision.hpp"
#include "systems/Render.hpp"
#include "systems/Wrapping.hpp"
#include "systems/UserInput.hpp"
#include "systems/AsteroidSpawner.hpp"
#include "systems/Collider.hpp"
#include "systems/PlayerThrust.hpp"
#include "systems/PlayerRotate.hpp"
#include "systems/Weapon.hpp"
#include "systems/OutOfBound.hpp"
namespace System
{
    class Manager
    {
    private:
        std::vector<std::unique_ptr<System>> systems;
        std::unique_ptr<RenderSystem> renderSystem;

    public:
        // Adds all the systems
        Manager(sf::RenderWindow &window) : renderSystem(std::make_unique<RenderSystem>(window))
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
}