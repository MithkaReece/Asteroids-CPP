#pragma once

#include "System.cpp"

#include "MovementSystem.hpp"
#include "CollisionSystem.hpp"

class SystemManager
{
public:
    // Adds all the systems
    SystemManager()
    {
        systems.push_back(std::make_unique<MovementSystem>());
        systems.push_back(std::make_unique<CollisionSystem>());
    }

    void updateSystems(entt::registry &registry, float dt)
    {
        for (auto &system : systems)
        {
            system->update(registry, dt);
        }
    }

private:
    std::vector<std::unique_ptr<System>> systems;
};