#include "SystemRender.hpp"

#include <iostream>

SystemRender::SystemRender() {}

void SystemRender::update(sf::Time dt)
{
  sf::RenderWindow &window = GlobalObjects::getWindow();
  entt::registry &registry = GlobalObjects::getRegistry();

  for (auto [entity, background] : registry.view<ComponentBackground>().each())
  {
    sf::Texture &backgroundTexture = ResourceManager::getInstance().getTexture(background.textureID);
    sf::Sprite backgroundSprite(backgroundTexture);

    // Get the size of the window and the texture
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Calculate the scale factors for both X and Y directions
    float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y);

    // Determine the scale that will preserve the aspect ratio
    float scale = std::max(scaleX, scaleY);

    // Calculate the position to center the image
    float posX = (windowSize.x - textureSize.x * scale) / 2.f;
    float posY = (windowSize.y - textureSize.y * scale) / 2.f;

    // Set the scale and position of the sprite
    backgroundSprite.setScale(scale, scale);
    backgroundSprite.setPosition(posX, posY);

    // window.draw(backgroundSprite);
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

  // Main Menu
  for (auto [entity, menuItem] : registry.view<ComponentMenuItem>().each())
  {
    window.draw(*menuItem.shape);
    window.draw(*menuItem.text);
  }

  // Render UI elements
  for (auto [entity, text] : registry.view<ComponentText>().each())
  {
    window.draw(*text.text);
  }
}
