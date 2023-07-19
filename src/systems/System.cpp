#include "systems/System.hpp"

namespace System
{
  System::System(entt::registry &registry, sf::RenderWindow &window, Scene::Scene &scene)
      : registryRef(registry), windowRef(window), sceneRef(scene), ID(nextID++) {}

  int System::nextID = 0;

  // TODO: not sure why I need this, but its stop complaining about
  // TODO: some other thing not implementing this virtual update
  void System::update(sf::Time dt) {}
}
