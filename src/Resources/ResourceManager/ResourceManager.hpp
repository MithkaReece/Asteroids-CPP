#pragma once
#ifndef HEADER_RESOURCE_MANAGER
#define HEADER_RESOURCE_MANAGER

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class ResourceManager
{
private:
  std::unordered_map<std::string, sf::Texture> textures;
  std::unordered_map<std::string, sf::Font> fonts;

public:
  static ResourceManager &getInstance()
  {
    static ResourceManager instance;
    return instance;
  }

private:
  ResourceManager();

  bool loadTexture(const std::string &id, const std::string &filepath);

  bool loadFont(const std::string &id, const std::string &filepath);

public:
  sf::Texture &getTexture(const std::string &id);

  sf::Font &getFont(const std::string &id);
};

#endif