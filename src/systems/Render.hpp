#pragma once

#include "systems/System.hpp"
#include "components/Transform.hpp"
#include "components/Render.hpp"
#include "components/TextUI.hpp"
#include "components/ScoreTag.hpp"

#include <iostream>
namespace System
{
  /**
   * @brief The Render class handles rendering entities and UI elements.
   */
  class Render : public System
  {
  private:
    sf::RenderWindow &window;

  public:
    /**
     * @brief Constructs a Render object with the specified SFML window.
     *
     * @param window The SFML RenderWindow to render to.
     */
    Render(sf::RenderWindow &window) : window(window) {}

    /**
     * @brief Updates the system by rendering entities and UI elements.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
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

      // Render UI elements
      auto viewUI = registry.view<Component::Transform, Component::TextUI, Component::ScoreTag>();

      for (auto entity : viewUI)
      {
        if (!registry.valid(entity))
          continue;

        Component::Transform &transform = viewUI.get<Component::Transform>(entity);
        Component::TextUI &textUI = viewUI.get<Component::TextUI>(entity);
        // Render the UI element
        sf::Text scoreText;
        scoreText.setFont(textUI.font);
        scoreText.setString(textUI.text);
        scoreText.setCharacterSize(25);
        scoreText.setPosition(window.getSize().x * transform.position.x, window.getSize().y * transform.position.y);
        scoreText.setFillColor(textUI.color);
        window.draw(scoreText);
      }
    }
  };
}