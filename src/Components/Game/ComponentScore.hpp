#pragma once
#ifndef HEADER_COMPONENT_SCORE
#define HEADER_COMPONENT_SCORE
/**
 * @brief Score component representing the player's current score.
 *
 * Resets when player runs out of lives.
 *
 */
struct ComponentScore
{
  int value = 0;
};
#endif