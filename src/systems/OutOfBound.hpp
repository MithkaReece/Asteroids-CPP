#pragma once

#include "systems/System.hpp"

#include "components/Transform.hpp"
#include "components/PlayerInput.hpp"
#include "components/Weapon.hpp"

#include "entities/Bullet.hpp"

#include "Constants.h"
namespace System
{
class OutOfBoundSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
    }
};
}