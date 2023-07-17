#pragma once
#include <entt/entt.hpp>

#include "components/Transform.hpp"
#include "components/TextUI.hpp"
#include "components/ScoreTag.hpp"

#include <SFML/Graphics.hpp>

namespace Entity
{
  void createScoreUI(entt::registry &registry)
  {
    auto entity = registry.create();

    sf::Vector2f position(0.01f, 0.01f);
    sf::Vector2f scale(1.0f, 1.0f);
    registry.emplace<Component::Transform>(entity, position, scale, 0.0f);
    registry.emplace<Component::TextUI>(entity, "0", sf::Color::White);
    registry.emplace<Component::ScoreTag>(entity);
  }
}