#include "System.hpp"
#include <iostream>
#include <string>
System::System(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : registryRef(registry), windowRef(window), sceneRef(scene) {}
