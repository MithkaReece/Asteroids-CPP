#pragma once
#include <SFML/System/Time.hpp>

namespace Component
{
  /**
   * @brief Weapon component represents the player's weapon information
   *
   * This stores the length of the cooldown before shooting the weapon again.
   * Also stores the current time left until the cooldown is over.
   */
  struct Weapon
  {
    sf::Time cooldownDuration;
    sf::Time remainingCooldown;
  };
}