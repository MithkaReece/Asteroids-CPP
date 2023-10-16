#include "EntityPlayer.hpp"

constexpr const float PLAYER_ACCELERATION = 100.f;
constexpr const float PLAYER_SCALE = 10.f;
constexpr const float PLAYER_ROTATION = 0.f;
constexpr const float MAX_DIST_FROM_BOUNDARY = 2.f;
constexpr const float FIRE_RATE_DELAY = 0.2f;

void EntityPlayer(Scene &scene)
{
  sf::RenderWindow &window = GlobalObjects::getWindow();
  auto entity = scene.create();
  scene.emplace<ComponentPlayer>(entity);
  scene.emplace<ComponentAcceleration>(entity, PLAYER_ACCELERATION);
  scene.emplace<ComponentTransform>(entity, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(PLAYER_SCALE, PLAYER_SCALE), PLAYER_ROTATION);
  scene.emplace<ComponentVelocity>(entity, sf::Vector2f(0.f, 0.f));
  scene.emplace<ComponentWrapperBoundary>(entity, MAX_DIST_FROM_BOUNDARY);
  scene.emplace<ComponentWeapon>(entity, sf::seconds(FIRE_RATE_DELAY));
  scene.emplace<ComponentPlayerInput>(entity);

  // Add RenderComponent
  sf::ConvexShape shape = entityTriangle();
  std::unique_ptr<sf::Drawable> drawable = std::make_unique<sf::ConvexShape>(std::move(shape));
  scene.emplace<ComponentRender>(entity, std::move(drawable));
  scene.emplace<ComponentCollider>(entity, shape);
}

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