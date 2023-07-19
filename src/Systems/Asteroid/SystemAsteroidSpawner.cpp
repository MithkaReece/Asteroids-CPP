#include "SystemAsteroidSpawner.hpp"

SystemAsteroidSpawner::SystemAsteroidSpawner(entt::registry &registry, sf::RenderWindow &window, Scene &scene, sf::Time interval)
    : System(registry, window, scene), interval(interval) {}

void SystemAsteroidSpawner::update(sf::Time dt)
{
  timer += dt;
  if (timer >= interval)
  {
    entityAsteroid(sceneRef.get(), windowRef.get());
    timer = sf::Time::Zero;
  }
}
