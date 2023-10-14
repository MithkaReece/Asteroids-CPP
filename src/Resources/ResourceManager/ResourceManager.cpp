#include "ResourceManager.hpp"

#include <iostream>

ResourceManager::ResourceManager()
{

  loadFont("Default", "/Users/reece/Documents/GitHub.nosync/C++/Asteroids-CPP/src/Resources/Fonts/Roboto-Medium.ttf");

  loadTexture("background1", "/Users/reece/Documents/GitHub.nosync/C++/Asteroids-CPP/src/Resources/Backgrounds/1.png");
  loadTexture("background2", "/Users/reece/Documents/GitHub.nosync/C++/Asteroids-CPP/src/Resources/Backgrounds/2.png");
  loadTexture("background3", "/Users/reece/Documents/GitHub.nosync/C++/Asteroids-CPP/src/Resources/Backgrounds/3.png");

  loadHighScore();
}
#include <iostream>
void ResourceManager::loadHighScore()
{
  int retrievedHighScore = 0;
  // if (std::filesystem::exists(highScorePath))
  // {
  //   std::ifstream file(highScorePath, std::ios::binary);
  //   if (file.is_open())
  //   {
  //     file.read(reinterpret_cast<char *>(&retrievedHighScore), sizeof(int));
  //     file.close();
  //   }
  //   else
  //   {
  //     // Handle error if file cannot be opened (optional)
  //     std::cerr << "Error: Could not open file '" << highScorePath << "' for reading.\n";
  //   }
  // }
  // else
  // {
  //   // The file doesn't exist, so create it with the default high score
  //   // std::ofstream file(highScorePath, std::ios::binary);
  //   // if (file.is_open())
  //   // {
  //   //   // std::cout << "Create file\n";
  //   //   file.write(reinterpret_cast<const char *>(&retrievedHighScore), sizeof(int));
  //   //   file.close();
  //   // }
  //   // else
  //   // {
  //   //   // Handle error if file cannot be created (optional)
  //   //   // std::cerr << "Error: Could not create file '" << highScorePath << "' for writing.\n";
  //   // }
  // }
  // std::cout << "Highscore loaded:" << retrievedHighScore << "\n";
  highScore = retrievedHighScore;
}

int ResourceManager::getHighScore()
{
  // std::cout << "High Score give is " << std::to_string(highScore) << "\n";
  return highScore;
}

void ResourceManager::setHighScore(int newHighScore)
{
  highScore = newHighScore;
  // Save to file
  std::ofstream file(highScorePath, std::ios::binary);
  if (file.is_open())
  {
    file.write(reinterpret_cast<const char *>(&highScore), sizeof(int));
    file.close();
  }
  else
  {
    // Handle error if file cannot be opened
    // ...
  }
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