#pragma once
#ifndef HEADER_RESOURCE_MANAGER
#define HEADER_RESOURCE_MANAGER

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <filesystem>

class ResourceManager
{
private:
  std::unordered_map<std::string, sf::Texture> textures;
  std::unordered_map<std::string, sf::Font> fonts;
  std::string highScorePath = "/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/Resources/Highscore/Highscore";
  int highScore;

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

  void loadHighScore();

public:
  sf::Texture &getTexture(const std::string &id);

  sf::Font &getFont(const std::string &id);

  int getHighScore();
  void setHighScore(int newHighScore);
};

#endif