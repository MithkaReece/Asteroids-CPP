#pragma once

#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Render.hpp"
#include "components/TextUI.hpp"
#include "components/ScoreTag.hpp"

#include <iostream>
namespace System
{
  class Render : public System
  {
  private:
    sf::RenderWindow &window;

  public:
    Render(sf::RenderWindow &window) : window(window) {}

    void update(entt::registry &registry, sf::Time dt)
    {
      auto view = registry.view<Component::Render, Component::Transform>();

      for (auto entity : view)
      {
        if (!registry.valid(entity))
          continue;

        Component::Render &render = view.get<Component::Render>(entity);
        Component::Transform &transform = view.get<Component::Transform>(entity);

        // Render the entity using the render and transform components
        sf::Drawable *drawable = render.drawable.get();
        assert(drawable != nullptr && "Drawable is null!");

        sf::Transform sfTransform;
        sfTransform.translate(transform.position);
        sfTransform.scale(transform.scale);
        sfTransform.rotate(transform.rotation);
        window.draw(*drawable, sfTransform); // Draw the drawable object to the window
      }

      auto viewUI = registry.view<Component::Transform, Component::TextUI, Component::ScoreTag>();

      for (auto entity : viewUI)
      {
        if (!registry.valid(entity))
          continue;

        Component::Transform &transform = viewUI.get<Component::Transform>(entity);
        Component::TextUI &textUI = viewUI.get<Component::TextUI>(entity);
        // Render the UI element
        sf::Text scoreText;
        sf::Font font;
        font.loadFromFile("/Users/reece/Documents/GitHub.nosync/Asteroids-CPP/src/resources/Roboto-Medium.ttf");
        scoreText.setFont(font);
        scoreText.setString(textUI.text);
        scoreText.setCharacterSize(25);
        scoreText.setPosition(window.getSize().x * transform.position.x, window.getSize().y * transform.position.y);
        scoreText.setFillColor(textUI.color);
        window.draw(scoreText);
      }
    }
  };
}