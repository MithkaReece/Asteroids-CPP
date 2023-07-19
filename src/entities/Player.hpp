#pragma once
#include <entt/entt.hpp>

#include "components/Player.hpp"
#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/WrapperBoundary.hpp"
#include "components/Render.hpp"
#include "components/Collider.hpp"
#include "components/PlayerInput.hpp"
#include "components/Weapon.hpp"

#include "scenes/Scene.hpp"

namespace Entity
{
  /**
   * @brief Create a triangle shape.
   *
   * @return The created triangle shape.
   */
  sf::ConvexShape
  createTriangle();

  /**
   * @brief Create a player entity with the specified components.
   *
   * @param registry The entity registry.
   * @param window The render window.
   */
  void createPlayer(Scene::Scene &scene, sf::RenderWindow &window);
}