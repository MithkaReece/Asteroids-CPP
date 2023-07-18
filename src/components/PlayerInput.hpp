#pragma once

namespace Component
{
  /**
   * @brief Player input component for storing user-inputs.
   *
   * This component represents the input state for controlling the player.
   * It contains boolean flags for various input actions.
   */
  struct PlayerInput
  {
    bool thrustPressed = false;
    bool leftRotatePressed = false;
    bool rightRotatePressed = false;
    bool shootPressed = false;
  };
}