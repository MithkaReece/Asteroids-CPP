#include "EntityPlayer.hpp"

sf::ConvexShape entityTriangle()
{
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, sf::Vector2f(1.0f, .0f));    // Middle Right vertex
  triangle.setPoint(1, sf::Vector2f(-1.0f, 1.0f));  // Top Left vertex
  triangle.setPoint(2, sf::Vector2f(-1.0f, -1.0f)); // Bottom Left vertex
  triangle.setFillColor(sf::Color::Red);
  return triangle;
}

void EntityPlayer(Scene &scene, sf::RenderWindow &window)
{

  // Create entity
  auto entity = scene.create();

  scene.emplace<ComponentScore>(entity, 0);
  scene.emplace<ComponentLives>(entity, 3);

  // Add PlayerComponent
  const float acceleration = 100.0f;

  scene.emplace<ComponentPlayer>(entity, acceleration);

  // Add TransformComponent
  sf::Vector2f position(window.getSize().x / 2, window.getSize().y / 2);
  sf::Vector2f scale(10.0f, 10.0f);
  const float rotation = 0.0f;
  scene.emplace<ComponentTransform>(entity, position, scale, rotation);

  // Add VelocityComponent
  sf::Vector2f velocity(0.0f, 0.0f);
  scene.emplace<ComponentVelocity>(entity, velocity);

  // Add WrapperBoundaryComponent
  const float boundarySize = 2.0f;
  scene.emplace<ComponentWrapperBoundary>(entity, boundarySize);

  // Add Weapon to shoot
  scene.emplace<ComponentWeapon>(entity, sf::seconds(0.2f));

  // Add PlayerInputComponent
  scene.emplace<ComponentPlayerInput>(entity);

  // Add RenderComponent
  sf::ConvexShape shape = entityTriangle();
  std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
  scene.emplace<ComponentRender>(entity, std::move(drawable));

  // Add ColliderComponent
  scene.emplace<ComponentCollider>(entity, shape);
}
