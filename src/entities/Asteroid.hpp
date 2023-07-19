#pragma once
#include <entt/entt.hpp>
#include <random>
#include "components/Asteroid.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"
#include "components/Render.hpp"
#include "components/Collider.hpp"
#include <SFML/Graphics.hpp>

#include "scenes/Scene.hpp"
#include "Constants.h"

namespace Entity
{
  /**
   * @brief Create an asteroid shape with given number of points and noise magnitude.
   *
   * @param noPoints The number of points to create for the asteroid shape.
   * @param noiseMagnitude Magnitude of noise applied to points dist from center.
   * @return The created sf::ConvexShape representing the asteroid.
   */
  sf::ConvexShape createAsteroidShape(unsigned int noPoints, float noiseMagnitude);

  /**
   * @brief Get the minimum scale value based on the asteroid level.
   *
   * @param level The level of the asteroid.
   * @return The minimum scale value.
   */
  float levelMinScale(int level);

  /**
   * @brief Get the maximum scale value based on the asteroid level.
   *
   * @param level The level of the asteroid.
   * @return The maximum scale value.
   */
  float levelMaxScale(int level);

  /**
   * @brief Create an asteroid entity with the specified level, position, and velocity.
   *
   * @param registry The entity registry.
   * @param window The SFML render window.
   * @param level The level of the asteroid used to set the range the scale can randomly be
   * @param position The position of the asteroid.
   * @param velocity The velocity of the asteroid.
   */
  void createAsteroid(Scene::Scene &scene, sf::RenderWindow &window, int level,
                      sf::Vector2f position, sf::Vector2f velocity);

  /**
   *
   * @brief Create an asteroid entity with a random level (1-3),
   * random position outside the window but within the boundary
   * and random velocity.
   *
   * @param registry The entity registry.
   * @param window The SFML render window.
   */
  void createAsteroid(Scene::Scene &scene, sf::RenderWindow &window);
}