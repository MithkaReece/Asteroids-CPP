#pragma once
#ifndef HEADER_COMPONENT_PLAYER
#define HEADER_COMPONENT_PLAYER
/**
 * @brief Player component representing a player entity.
 *
 * The Player component is used to represent a player entity in the game.
 * It stores the acceleration value when the player thrusts.
 */
struct ComponentPlayer
{
  float acceleration;
};
#endif