#pragma once

namespace Component
{
  /**
   * @brief Asteroid component representing an asteroid entity.
   *
   * The Asteroid component is used to represent an asteroid entity in the game.
   * It stores the level of the asteroid representing the size category.
   * When it reaches 1 it no longer splits on collision.
   */
  struct Asteroid
  {
    int level;
  };
}