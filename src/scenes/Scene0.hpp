#pragma once

#include <entt/entt.hpp>
#include "Scene.hpp"

#include "../entities/PlayerEntity.hpp"
#include "../entities/AsteroidEntity.hpp"

class Scene0 : public Scene
{
    void init(entt::registry &registry)
    {
        createPlayer(registry);
    }
};