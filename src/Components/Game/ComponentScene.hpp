#pragma
#ifndef HEADER_COMPONENT_SCENE
#define HEADER_COMPONENT_SCENE
/**
 * Scene component containing information about current scenes.
 * 
 * Holds booleans of whether we are in game or main menu, in pause menu or not
 * and whether the pause button has been pressed.
*/
struct ComponentScene
{
  bool inGame = false;
  bool pauseMenu = false;
  bool pausePressed = false;
};
#endif