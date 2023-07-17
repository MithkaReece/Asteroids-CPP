#pragma once

#include "System.hpp"

#include "../components/TransformComponent.hpp"
#include "../components/PlayerInputComponent.hpp"
#include "../components/WeaponComponent.hpp"

#include "../entities/BulletEntity.hpp"

#include "../Constants.h"

class OutOfBoundSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
    }
};