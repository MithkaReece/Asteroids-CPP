#pragma
#ifndef HEADER_COMPONENT_LIVES
#define HEADER_COMPONENT_LIVES
/**
 * @brief Lives component representing the player's number of lives
 * 
 * Resets when lives hit 0 and resets score.
*/
struct ComponentLives
{
  int value = 3;
};
#endif