#include "EntityBullet.hpp"

sf::ConvexShape entityBulletShape()
{
  const float ratio = 5.0f;
  sf::ConvexShape bullet;
  bullet.setPointCount(4);
  bullet.setPoint(0, sf::Vector2f(-ratio, -1.0f));
  bullet.setPoint(1, sf::Vector2f(-ratio, 1.0f));
  bullet.setPoint(2, sf::Vector2f(ratio, 1.0f));
  bullet.setPoint(3, sf::Vector2f(ratio, -1.0f));
  bullet.setFillColor(sf::Color::White);
  return bullet;
}

void entityBullet(Scene &scene, sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
  // Add components
  auto entity = scene.create();

  scene.emplace<ComponentBulletTag>(entity);
  scene.emplace<ComponentTransform>(entity, position, sf::Vector2f(1.0f, 1.0f), rotation);
  scene.emplace<ComponentVelocity>(entity, velocity);

  // Create shape
  sf::ConvexShape shape = entityBulletShape();
  std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));

  // Add components
  scene.emplace<ComponentRender>(entity, std::move(drawable));
  scene.emplace<ComponentCollider>(entity, shape);
}
