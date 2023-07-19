#include "systems/System.hpp"

namespace System
{
  System::System(std::reference_wrapper<Scene::IManager> sceneManager, Scene::IScene &scene)
      : sceneManagerRef(sceneManager), sceneRef(scene) {}

  // TODO: not sure why I need this, but its stop complaining about
  // TODO: some other thing not implementing this virtual update
  void System::update(sf::Time dt) {}
}
