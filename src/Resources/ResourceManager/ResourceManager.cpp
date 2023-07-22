#include "ResourceManager.hpp"

#include <iostream>

ResourceManager::ResourceManager()
{
  std::cout << "Test\n";
  loadFont("Default", "/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Fonts/Roboto-Medium.ttf");

  loadTexture("background1", "/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Backgrounds/1.png");
  loadTexture("background2", "/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Backgrounds/2.png");
  loadTexture("background3", "/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Backgrounds/3.png");
}

bool ResourceManager::loadTexture(const std::string &id, const std::string &filepath)
{
  if (textures.find(id) != textures.end())
    return false;

  sf::Texture texture;
  if (!texture.loadFromFile(filepath))
    return false;

  textures[id] = std::move(texture);
  return true;
}

sf::Texture &ResourceManager::getTexture(const std::string &id)
{
    auto it = textures.find(id);
    assert(it != textures.end() && "Texture not found in ResourceManager");
    return it->second;
}

bool ResourceManager::loadFont(const std::string &id, const std::string &filepath)
{
  if (fonts.find(id) != fonts.end())
    return false;

  sf::Font font;
  if (!font.loadFromFile(filepath))
  {
    return false;
  }
  fonts[id] = std::move(font);
  return true;
}

sf::Font &ResourceManager::getFont(const std::string &id)
{
  return fonts.at(id);
}