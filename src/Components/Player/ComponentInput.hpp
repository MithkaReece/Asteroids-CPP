#pragma once
#ifndef HEADER_COMPONENT_INPUT
#define HEADER_COMPONENT_INPUT

/**
 * @brief Player input component for storing user-inputs.
 *
 * This component represents the input state for controlling the player.
 * It contains boolean flags for various input actions.
 */
struct ComponentPlayerInput
{
  bool thrustPressed = false;
  bool leftRotatePressed = false;
  bool rightRotatePressed = false;
  bool shootPressed = false;
};
#endif