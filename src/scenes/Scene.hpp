#pragma once

#include <entt/entt.hpp>

class Scene
{
public:
    virtual ~Scene() {}
    virtual void init(entt::registry &registry) = 0;
};