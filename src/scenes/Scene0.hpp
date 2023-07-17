#pragma once

#include <entt/entt.hpp>
#include "scenes/Scene.hpp"

#include "entities/Player.hpp"
#include "entities/Asteroid.hpp"

class Scene0 : public Scene
{
    void init(entt::registry &registry)
    {
        Entity::createPlayer(registry);
    }
};