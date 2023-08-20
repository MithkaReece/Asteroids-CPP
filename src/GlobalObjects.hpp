// GlobalObjects.h
#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

class GlobalObjects
{
public:
  static GlobalObjects &getInstance()
  {
    static GlobalObjects instance;
    return instance;
  }

  inline static GlobalObjects &get()
  {
    return getInstance();
  }

  inline static sf::RenderWindow &getWindow()
  {
    return get().window;
  }

  inline static entt::registry &getRegistry()
  {
    return get().registry;
  }

private:
  GlobalObjects() : window(sf::VideoMode(4 * 300, 4 * 200), ""), registry() {}

  GlobalObjects(const GlobalObjects &) = delete;
  GlobalObjects &operator=(const GlobalObjects &) = delete;

  sf::RenderWindow window;
  entt::registry registry;
};