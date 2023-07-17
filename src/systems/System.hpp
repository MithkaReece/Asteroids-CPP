#pragma once

#include <SFML/System/Time.hpp>
#include <entt/entt.hpp>
namespace System
{
class System
{
public:
    virtual ~System() {}
    virtual void update(entt::registry &registry, sf::Time dt) = 0;
};
}