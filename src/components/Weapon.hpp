#pragma once
#include <SFML/System/Time.hpp>

namespace Component
{
    struct Weapon
    {
        sf::Time cooldownDuration;
        sf::Time remainingCooldown;
    };
}