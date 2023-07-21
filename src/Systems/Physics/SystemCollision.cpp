#include "SystemCollision.hpp"

SystemCollision::SystemCollision(entt::registry &registry, sf::RenderWindow &window, Scene &scene)
    : System(registry, window, scene) {}

void SystemCollision::update(sf::Time dt)
{
  entt::registry &registry = registryRef.get();
  Scene &scene = sceneRef.get();
  auto asteroidView = registry.view<ComponentTransform, ComponentCollider, ComponentAsteroid, ComponentVelocity>();
  auto playerView = registry.view<ComponentTransform, ComponentCollider, ComponentPlayer, ComponentVelocity>();
  auto bulletView = registry.view<ComponentBulletTag>();

  auto view = registry.view<ComponentTransform, ComponentCollider, ComponentVelocity>();
  for (auto entity1 : view)
  {
    if (!registry.valid(entity1))
      continue;

    ComponentTransform &transform1 = view.get<ComponentTransform>(entity1);
    ComponentCollider &collider1 = view.get<ComponentCollider>(entity1);
    ComponentVelocity &velocity1 = view.get<ComponentVelocity>(entity1);

    for (auto entity2 : registry.view<ComponentTransform, ComponentCollider, ComponentVelocity>())
    {
      if (!registry.valid(entity2))
        continue;

      ComponentTransform &transform2 = view.get<ComponentTransform>(entity2);
      ComponentCollider &collider2 = view.get<ComponentCollider>(entity2);
      ComponentVelocity &velocity2 = view.get<ComponentVelocity>(entity2);

      if (entity1 == entity2 || !collider1.shape.getGlobalBounds().intersects(collider2.shape.getGlobalBounds()))
        continue;

      const bool isAsteroid1 = asteroidView.contains(entity1), isPlayer1 = playerView.contains(entity1), isBullet1 = bulletView.contains(entity1);
      const bool isAsteroid2 = asteroidView.contains(entity2), isPlayer2 = playerView.contains(entity2), isBullet2 = bulletView.contains(entity2);

      if (isAsteroid1 && isAsteroid2)
      {
        const int level1 = asteroidView.get<ComponentAsteroid>(entity1).level;
        const int level2 = asteroidView.get<ComponentAsteroid>(entity2).level;
        handleAsteroidCollision(entity1, transform1, velocity1, level1,
                                entity2, transform2, velocity2, level2);
      }

      else if (isAsteroid1 && isPlayer2 || isPlayer1 && isAsteroid2)
        handlePlayerCollision();

      else if (isAsteroid1 && isBullet2)
      {
        const int level1 = asteroidView.get<ComponentAsteroid>(entity1).level;
        handleBulletCollision(entity2, transform2,
                              entity1, transform1, velocity1, level1);
      }

      else if (isBullet1 && isAsteroid2)
      {
        const int level2 = asteroidView.get<ComponentAsteroid>(entity2).level;
        handleBulletCollision(entity1, transform1,
                              entity2, transform2, velocity2, level2);
      }
    }
  }
}

void SystemCollision::handleAsteroidCollision(entt::entity entity1, ComponentTransform transform1, ComponentVelocity velocity1, int level1,
                                              entt::entity entity2, ComponentTransform transform2, ComponentVelocity velocity2, int level2)
{
  float mass1 = std::sqrt(transform1.scale.x * transform1.scale.x + transform1.scale.y * transform1.scale.y);
  float mass2 = std::sqrt(transform2.scale.x * transform2.scale.x + transform2.scale.y * transform2.scale.y);

  // Calculate the collision normal
  sf::Vector2f collisionNormal = transform2.position - transform1.position;
  collisionNormal /= std::sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);
  sf::Vector2 perpNormal(-collisionNormal.y, collisionNormal.x);

  // Calculate the relative velocity
  sf::Vector2f relativeVelocity = velocity2.velocity - velocity1.velocity;

  // Calculate the impulse magnitude
  float impulseMagnitude = (2.0f * mass2 * (relativeVelocity.x * collisionNormal.x + relativeVelocity.y * collisionNormal.y)) / (mass1 + mass2);

  // Calculate the new velocities
  sf::Vector2f newVelocity1 = velocity1.velocity + (impulseMagnitude * collisionNormal) / mass1;
  sf::Vector2f newVelocity2 = velocity2.velocity - (impulseMagnitude * collisionNormal) / mass2;

  entt::registry &registry = registryRef.get();

  if (!(registry.valid(entity1) && registry.valid(entity2)))
    return;

  registry.destroy(entity1);
  registry.destroy(entity2);

  // Asteroid 1 -> splits into 2 asteroids 3,4
  sf::Vector2f position3 = transform1.position + (level1 - 1) * (level1 - 1) * 15.0f * perpNormal;
  sf::Vector2f velocity3 = rotateVector(newVelocity1, ASTEROID_SPLIT_ANGLE);
  sf::Vector2f position4 = transform1.position - (level1 - 1) * (level1 - 1) * 15.0f * perpNormal;
  sf::Vector2f velocity4 = rotateVector(newVelocity1, -ASTEROID_SPLIT_ANGLE);
  splitAsteroid(entity1, level1, position3, velocity3, position4, velocity4);

  // Asteroid 2 -> splits into 2 asteroids 5,6
  sf::Vector2f position5 = transform2.position + (level2 - 1) * (level2 - 1) * 15.0f * perpNormal;
  sf::Vector2f velocity5 = rotateVector(newVelocity2, -ASTEROID_SPLIT_ANGLE);
  sf::Vector2f position6 = transform2.position - (level2 - 1) * (level2 - 1) * 15.0f * perpNormal;
  sf::Vector2f velocity6 = rotateVector(newVelocity2, ASTEROID_SPLIT_ANGLE);
  splitAsteroid(entity2, level2, position5, velocity5, position6, velocity6);
}

sf::Vector2f SystemCollision::rotateVector(sf::Vector2f vector, float angle)
{
  float cosAngle = std::cos(DEG_TO_RAD * angle);
  float sinAngle = std::sin(DEG_TO_RAD * angle);
  sf::Vector2f rotatedVector(cosAngle * vector.x - sinAngle * vector.y,
                             sinAngle * vector.x + cosAngle * vector.y);
  return rotatedVector;
}

void SystemCollision::splitAsteroid(entt::entity entity, int level,
                                    sf::Vector2f position1, sf::Vector2f velocity1,
                                    sf::Vector2f position2, sf::Vector2f velocity2)
{
  if (level < 2 || level > 3)
    return;
  Scene &scene = sceneRef.get();

  entityAsteroid(scene, windowRef.get(), level - 1, position1, velocity1);
  entityAsteroid(scene, windowRef.get(), level - 1, position2, velocity2);
}

void SystemCollision::handleBulletCollision(entt::entity bullet, ComponentTransform bulletTransform,
                                            entt::entity asteroid, ComponentTransform transform, ComponentVelocity velocity, int level)
{
  entt::registry &registry = registryRef.get();
  registry.destroy(bullet);

  // Find collision normal
  sf::Vector2f collisionNormal = bulletTransform.position - transform.position;
  collisionNormal /= std::sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);
  sf::Vector2 perpNormal(-collisionNormal.y, collisionNormal.x);

  sf::Vector2f &originalVelocity = velocity.velocity;

  if (!registry.valid(asteroid))
    return;
  registry.destroy(asteroid);

  sf::Vector2f position1 = transform.position + (level - 1) * (level - 1) * 15.0f * perpNormal;
  sf::Vector2f velocity1 = rotateVector(originalVelocity, ASTEROID_SPLIT_ANGLE);
  sf::Vector2f position2 = transform.position - (level - 1) * (level - 1) * 15.0f * perpNormal;
  sf::Vector2f velocity2 = rotateVector(originalVelocity, -ASTEROID_SPLIT_ANGLE);

  splitAsteroid(asteroid, level, position1, velocity1, position2, velocity2);

  // TODO: Add Event score
  //  TODO: addScore() edits something in a different scene
  //  TODO: addScore therefore should be an event
  //  addScore(registry, 1);
}

void SystemCollision::addScore(entt::registry &registry, int scoreIncrease)
{
  auto view = registry.view<ComponentTransform, ComponentTextUI, ComponentScoreTag>();

  for (auto entity : view)
  {
    if (!registry.valid(entity))
      continue;
    // Increment score value
    ComponentTextUI &textUI = view.get<ComponentTextUI>(entity);
    int score = std::stoi(textUI.text);
    score += scoreIncrease;
    textUI.text = std::to_string(score);
  }
}

void SystemCollision::handlePlayerCollision()
{
  // TODO: In system updates, also give the sceneManager
  // TODO: Conversely just give the scene manager as it also holds registry and window
  // SceneManager &sceneManager = SceneManager::getInstance();
  //  TODO: Reset level scene
  //  sceneManager.switchToScene(0);
}