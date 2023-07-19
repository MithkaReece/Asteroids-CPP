#pragma once
#ifndef HEADER_COMPONENT_WEAPON
#define HEADER_COMPONENT_WEAPON
#include <SFML/System/Time.hpp>

/**
 * @brief Weapon component represents the player's weapon information
 *
 * This stores the length of the cooldown before shooting the weapon again.
 * Also stores the current time left until the cooldown is over.
 */
struct ComponentWeapon
{
  sf::Time cooldownDuration;
  sf::Time remainingCooldown;
};
#endif