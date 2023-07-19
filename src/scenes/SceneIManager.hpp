#pragma once
#include <entt/entt.hpp>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Scene
{
  class IManager
  {
  public:
    std::reference_wrapper<entt::registry> registryRef; // Reference to the entity registry
    std::reference_wrapper<sf::RenderWindow> windowRef; // Reference to the SFML render window

    IManager(entt::registry &registry, sf::RenderWindow &window)
        : registryRef(registry), windowRef(window) {}
  };
}