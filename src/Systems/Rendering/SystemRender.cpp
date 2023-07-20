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

  for (auto entity : view)
  {
    if (!registry.valid(entity))
      continue;

    ComponentRender &render = view.get<ComponentRender>(entity);
    ComponentTransform &transform = view.get<ComponentTransform>(entity);

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
  for (auto entity : viewUI)
  {
    if (!registry.valid(entity))
      continue;

    ComponentScoreText &score = viewUI.get<ComponentScoreText>(entity);

    window.draw(*score.text);

    ComponentLivesText &lives = viewUI.get<ComponentLivesText>(entity);

    window.draw(*lives.text);
  }
}
