#pragma
#ifndef HEADER_COMPONENT_BACKGROUND
#define HEADER_COMPONENT_BACKGROUND
#include <string>
/**
 * @brief Background component representing the texture of the current background.
 * 
 * Stores the texture ID that is used to retrieve the texture from the 
 * resource loader to display the background.
 * 
*/
struct ComponentBackground
{
  std::string textureID;
};
#endif