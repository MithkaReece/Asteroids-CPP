#pragma once

namespace Component
{
  /**
   * @brief Player component representing a player entity.
   *
   * The Player component is used to represent a player entity in the game.
   * It stores the acceleration value when the player thrusts.
   */
  struct Player
  {
    float acceleration;
  };
}