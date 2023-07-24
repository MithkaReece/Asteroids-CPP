#include "System.hpp"
#include <iostream>
#include <string>
System::System(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : registryRef(registry), windowRef(window), sceneRef(scene) {}

// TODO: not sure why I need this, but its stop complaining about
// TODO: some other thing not implementing this virtual update
void System::update(sf::Time dt) {}
