#pragma once
#include <SFML/System/Time.hpp>

struct WeaponComponent
{
    sf::Time cooldownDuration;
    sf::Time remainingCooldown;
};