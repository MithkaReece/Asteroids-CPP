#include "SystemRender.hpp"

#include <iostream>

SystemRender::SystemRender(entt::registry &registry, sf::RenderWindow &window)
    : registryRef(registry), windowRef(window)
{
}

void SystemRender::update(sf::Time dt)
{
  sf::RenderWindow &window = windowRef.get();
  entt::registry &registry = registryRef.get();

  auto view = registry.view<ComponentRender, ComponentTransform>();

  for (auto [entity, render, transform] : view.each())
  {
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
  auto viewUI = registry.view<ComponentScoreText, ComponentLivesText>(); // TODO add lives
  for (auto [entity, score, lives] : viewUI.each())
  {
    window.draw(*score.text);
    window.draw(*lives.text);
  }

  // Main Menu
  auto viewMenu = registry.view<ComponentMenuItem>();
  for (auto [entity, menuItem] : viewMenu.each())
  {
    sf::FloatRect textBounds = menuItem.text->getGlobalBounds();
    sf::RectangleShape backgroundRect(sf::Vector2f(textBounds.width + window.getSize().x * menuItem.boundaryRatio.x, textBounds.height + window.getSize().y * menuItem.boundaryRatio.y));

    backgroundRect.setPosition(textBounds.left - window.getSize().x * menuItem.boundaryRatio.x / 2.0f,
                               textBounds.top - window.getSize().y * menuItem.boundaryRatio.y / 2.0f);

    backgroundRect.setFillColor(sf::Color(50, 50, 50));

    window.draw(backgroundRect);
    window.draw(*menuItem.text);
  }
}
