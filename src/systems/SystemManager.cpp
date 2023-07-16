#pragma once

#include "System.hpp"

#include "MovementSystem.hpp"
#include "CollisionSystem.hpp"
#include "RenderSystem.hpp"
#include "WrappingSystem.hpp"
#include "UserInputSystem.hpp"

class SystemManager
{
private:
    std::vector<std::unique_ptr<System>> systems;
    std::unique_ptr<RenderSystem> renderSystem;

public:
    // Adds all the systems
    SystemManager(sf::RenderWindow &window) : renderSystem(std::make_unique<RenderSystem>(window))
    {
        systems.push_back(std::make_unique<MovementSystem>());
        systems.push_back(std::make_unique<CollisionSystem>());
        systems.push_back(std::make_unique<UserInputSystem>());
        systems.push_back(std::make_unique<WrappingSystem>(window));
    }

    void updateSystems(entt::registry &registry, float dt)
    {
        for (auto &system : systems)
        {
            system->update(registry, dt);
        }
    }

    void updateRenderSystem(entt::registry &registry, float dt)
    {
        renderSystem->update(registry, dt);
    }
};