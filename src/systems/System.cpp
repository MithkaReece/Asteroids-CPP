#pragma once

#include <entt/entt.hpp>
class System
{
public:
    virtual ~System() {}
    virtual void update(entt::registry &registry, float dt) = 0;
};