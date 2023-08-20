#include "SystemAsteroidSpawner.hpp"

SystemAsteroidSpawner::SystemAsteroidSpawner(sf::Time interval)
    : interval(interval) {}

void SystemAsteroidSpawner::update(sf::Time dt)
{
  timer += dt;
  if (timer >= interval)
  {
    entityAsteroid("Gameplay");
    timer = sf::Time::Zero;
  }
}
