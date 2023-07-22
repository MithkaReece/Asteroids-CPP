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

  for (auto [entity, background] : registry.view<ComponentBackground>().each())
  {
    sf::Texture &backgroundTexture = ResourceManager::getInstance().getTexture(background.textureID);
    sf::Sprite backgroundSprite(backgroundTexture);
    window.draw(backgroundSprite);
  }

  for (auto [entity, render, transform] : registry.view<ComponentRender, ComponentTransform>().each())
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
  for (auto [entity, score, lives] : registry.view<ComponentScoreText, ComponentLivesText>().each())
  {
    window.draw(*score.text);
    window.draw(*lives.text);
  }

  // Main Menu
  for (auto [entity, menuItem] : registry.view<ComponentMenuItem>().each())
  {
    window.draw(*menuItem.shape);
    window.draw(*menuItem.text);
  }
}
